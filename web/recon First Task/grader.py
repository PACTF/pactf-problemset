def grade(arg, key):
	if "sutro" in key.lower() and "tower" in key.lower():
		return True, ""
	else:
		return False, "Keep trying!"