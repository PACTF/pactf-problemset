import random
plaintext = (
    "'Jedi' is just 'Monk' in ROT13, isn't it? "
    "Wait, no, that's 'Zbax'. Also, the flag is "
    "just_a_warmup{%s}"
)

def randword(length):
    return ''.join(random.choice(
        string.ascii_lowercase + string.ascii_uppercase)
        for i in range(length)
    )

def grade(key, flag):
    random.seed(key)
    n = random.randint(1, 25)
    msg = plaintext % randword(8)
    if msg[85:] in flag:
        return True, 'Nice job!'
    return False, 'Nope!'
