def grade(key, flag):
    if flag.lower() == 'flag is guess you’re not a square! xpsogpps' or flag.lower() == 'guess you’re not a square! xpsogpps' or flag.lower() == 'xpsogpps':
        return True, "No square. No more."
    else:
        return False, "You are clearly a square."
