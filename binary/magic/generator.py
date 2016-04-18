desc = '''Wanna see a [magic trick]({{% ctfstatic 'magic{}' %}})?'''
hint = '''I wonder if you could get into memory and see the magic?'''

def generate(key):
    return desc.format(key % 3), hint
