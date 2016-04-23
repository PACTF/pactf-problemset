    def grade(arg, key):
        if "Digicert" in key:
            return True, "Whatever program you used has failed to protect you from a revoked certificate, so be careful out there!"
        else:
            return False, "Try again."