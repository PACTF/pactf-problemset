def grade(team, key):
    stocks = set(key.lower().split('_'))
    if stocks == {'xom', 'cvx'}:
        return True, ""
    else:
        return False, ""
