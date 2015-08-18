    def grade(arg, key):
	    if "4fV8cM2QfE2TJcHMxdSrvSye+ic/bQHlw+4Bm9nwls0=" in key:
		return True, "Congratulations! It worked!"
	    elif "DBZRU8OYyg0bvI0x2F+LL+QcYRLIKWLPyz92dwuaPDs=" in key:
	        return False, "No, it didn't work. I need the hash of the private key, not the public key."
	    elif "lv8t74hplkz79CIsCsBzDiaTfJF1skxv0rLhkV5Gw2A=" in key:
	    	return False, "No, the hash looks something like this, but this is not it."
	    else:
	        return False, "No, it didn't work. Keep trying."
