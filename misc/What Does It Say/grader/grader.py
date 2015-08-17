    def grade(arg, key):
        if "Digicert" in key:
            return True, "Correct"
        else:
            return False, "Incorrect"