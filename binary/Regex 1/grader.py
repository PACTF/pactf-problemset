import re

ACCEPTS = (
    'efw ???????!?????..???????? wefwe',
    'ghrm???!!???? !!!!!!!!.?!!!!!!!!!!!!!! wefwe',
)

REJECTS = (
    ' efwefw????????????????..????',
    ' efwefw???????;??????????????!',
)


def check(flag):
    pat = re.compile(flag)
    return (
        all(not pat.findall(reject) for reject in REJECTS)
        and all(pat.findall(accept) for accept in ACCEPTS)
    )


def grade(key, flag):
    try:
        success = check(flag)
    except Exception as err:
        print(err)
        return False, "Please try a different regex."

    if success:
        return True, "Now you have two problems. (Seriously, refresh the page.)"
    else:
        return False, "Joe still doesn’t know…"
