def grade(arg, key):
    if "digicert" in key.lower():
        return True, "Be careful out there! Looks like that revoked certificate got through whatever you used!"
    else:
        return False, "Try again."
