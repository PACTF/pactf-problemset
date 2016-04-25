def grade(arg, key):
    if "57Yh+k6TTFiz63os1nWhAP/g5X9UBWzcj7pl91beLbE=" in key:
        return True, "Congratulations! It worked!"
    elif "lxgHG27ibhPKlbUq0XgQHLGUXV+tQGzoDNeqZXTz46k=" in key:
        return False, "Use DER, not PEM, before hashing."
    elif "lv8t74hplkz79CIsCsBzDiaTfJF1skxv0rLhkV5Gw2A=" in key:
        return False, "No, the hash looks something like this, but this is not it."
    else:
        return False, "No, it didn't work. Keep trying."
