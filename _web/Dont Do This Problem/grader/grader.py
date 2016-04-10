    def grade(arg, key):
        if "not the flag" in key:
            return True, "But you really should not have done this problem! Why!?"
        else:
            return False, "Incorrect. Try this secretive problem again?"