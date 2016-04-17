desc = '''You found an [interesting program]({% ctflexstatic adventure{} %}) on
the floor... wonder what it is?
'''

hint = '''What is a directory? A miserable little pile of hidden files!'''

def generate(key):
    return desc.format(key % 3), hint
