def grade(key, flag):
    if flag == 'entering_sudo_mode':
        return True, "Welcome to sudo world"
    else:
        return False, "Blocked!"
