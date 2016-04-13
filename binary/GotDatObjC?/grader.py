def grade(team, flag):
    if '{lovn_dis_ObjC' in flag:
        return True, "Nice. It's gonna get harder, though!"
    return False, "Bit harder when it's not in you architecture. Isn't it?"