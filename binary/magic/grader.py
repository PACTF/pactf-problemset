flags = ['pa{cHECk_uR_vAr5}', 'pactf{eax_more_like_easy}', 'flag{h1de_0n_Bu5h}']

def grade(team, flag):
    if flags[team % len(flags)] in flag:
        return True, "Bet you couldn't do THAT as a kid!"
    return False, "Nope!"
