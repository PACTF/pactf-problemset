import re

def grade(key, flag):
    pat = re.compile(flag)
    if pat.findall('efw ???????!?????..???????? wefwe') and not pat.findall(' efwefw????????????????..?'):
        return True, "Joe says thanks!"
    else:
        return False, "Joe is still sad."