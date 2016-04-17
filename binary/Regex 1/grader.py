import re

ACCEPTS = (
    'efw ???????!?????..???????? wefwe',
    'ghrm???!!???? !!!!!!!!.?!!!!!!!!!!!!!! wefwe',
)

REJECTS = (
    ' efwefw????????????????..????',
    ' efwefw???????;??????????????!',
)


def grade(key, flag):
    pat = re.compile(flag)
    if (all(not pat.findall(reject) for reject in REJECTS)
        and all(pat.findall(accept) for accept in ACCEPTS)):
        return True, "Now you have two problems (seriously, refresh the page)."
    else:
        return False, "Joe still doesn’t know…"
