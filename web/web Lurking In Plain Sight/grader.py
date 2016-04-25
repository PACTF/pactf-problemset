def grade(arg, key):
    if "i_found_a_header!" == key.strip().lower():
        return True, "You found it."
    else:
        return False, "Are you looking in the right place?"
