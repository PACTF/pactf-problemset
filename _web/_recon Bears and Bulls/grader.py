def grade(team, flag):
    names = flag.split('_')
    if len(names) != 2: return False, "Nope!"
    if "xom" in names and "cvx" in names:
        return True, "Nice!"
    return False, "Nope!"
