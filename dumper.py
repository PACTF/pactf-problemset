#!/usr/bin/env python3

"""Dump list of problems and some associated data into a CSV file

The CSV file format is as so: uuid, window codename, problem name, points.
"""

__author__ = 'Yatharth Agarwal <yatharth999@gmail.com>'

import os
from os.path import isfile, join
from termcolor import colored
import yaml
import yaml.parser
import csv
from uuid import uuid4
import shutil
import re
import textwrap

OUTFILE = 'dump.csv'
PK_FIELD = 'id'
PROBLEMS_DIR = '.'
DATA_BASENAME = 'problem.yaml'
UUID_BASENAME = '.uuid'
UUID_REGEX = r'[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}'
UUID_BACKUP_BASENAME = '.uuid.rejected'
IGNORES = [
    '.',
    'unpublished',
    # '_',
]
VERBOSE = False


def subdirs(directory):
    if VERBOSE:
        out = print
    else:
        out = lambda *args, **kwargs: None

    out("Walking directory '{}'".format(directory))
    for basename in os.listdir(directory):
        path = join(directory, basename)

        # Skip files
        if isfile(path):
            out("Ignoring '{}': Is file".format(basename))
            continue

        # Ignore private dirs
        if any(basename.startswith(ignore) for ignore in IGNORES):
            out("Ignoring '{}': Marked private with underscore or dot".format(basename))
            continue

        yield basename, path


def warn(text):
    print(colored(text, 'red'))


def main():
    print("Writing to '{}'".format(OUTFILE))

    with open(OUTFILE, 'w') as outfile:
        writer = csv.writer(outfile)

        for window_basename, window_path in subdirs(PROBLEMS_DIR):
            for prob_basename, prob_path in subdirs(window_path):

                problem_filename = join(prob_path, DATA_BASENAME)
                try:
                    with open(problem_filename) as problem_file:
                        data = yaml.load(problem_file)
                except IsADirectoryError as err:
                    warn("Skipping '{}': Is a directory".format(prob_basename))
                    warn(err)
                    warn("")
                except FileNotFoundError:
                    warn("Fixing '{}': Creating a problem file".format(prob_basename))
                    warn("")
                    with open(join(prob_path, DATA_BASENAME), 'w') as outfile:
                        outfile.write(textwrap.dedent('''\
                            name: {}
                            points: 10
                            description: N/A
                            hint: N/A
                            '''.format(
                            prob_basename,
                        )))
                except yaml.parser.ParserError as err:
                    warn("Skipping '{}': Parser error".format(prob_basename))
                    warn(err)
                    warn("")
                    continue

                uuid_path = join(prob_path, UUID_BASENAME)
                uuid = None
                if isfile(uuid_path):
                    with open(uuid_path) as uuid_file:
                        uuid = uuid_file.read().strip()
                        data[PK_FIELD] = uuid

                    if not re.match('{}$'.format(UUID_REGEX), uuid):
                        warn("UUID File did not match the expected format '{}'".format(UUID_REGEX))
                        warn("Backing up and deleting existing UUID file")
                        uuid = None
                        backup_uuid_path = join(prob_path, UUID_BACKUP_BASENAME)
                        shutil.move(uuid_path, backup_uuid_path)

                if uuid is None:
                    uuid = str(uuid4())
                    warn("Creating a UUID file for '{}'".format(prob_basename))
                    warn("")
                    with open(uuid_path, 'w') as uuid_file:
                        uuid_file.write(uuid)

                try:
                    row = [uuid, window_basename, data['name'], data['points']]
                except KeyError as err:
                    warn("Skipping '{}': Problem file missing key: {}".format(prob_basename, err))
                    warn("")
                    continue

                writer.writerow(row)

    print("Printing output file")
    print()
    with open(OUTFILE) as infile:
        print(infile.read())
    print("Exiting successfully")


if __name__ == '__main__':
    main()
