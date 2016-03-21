#!/usr/bin/python

import math

tests = (
	("1 2 3 4 5", 3),
	("1 2 3 4 5 6", 3.5),
	("1 3 5 7 10", 5.2),
	# TODO
)

def grade(arg, key):
	if len(key) > 5:
		return False, "That's too long!"
#	if all(map(j_grader(key), tests)):
#		return True, "Weird, huh?"
#	else:
#		return False, "Nope!"
	if '+/%#' in key:
		return True, "Weird, huh?"
	else: return False, "Nope!"

# TODO
def j_grader(verb):
	def j_grade(test): pass
	return j_grade

def j_interpret(line):

