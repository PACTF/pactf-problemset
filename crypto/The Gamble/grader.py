def grade(arg, key):
    if "not the flag" in key:
        return True, "Les jeux sont fait. Reload the page."
    else:
        return False, "Try this secretive problem again?"
