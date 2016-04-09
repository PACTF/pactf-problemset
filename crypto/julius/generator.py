import string

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

def encrypt(msg, n):
    if n % 26 == 0: n = 13
    output = ''
    for c in msg:
        if c in string.ascii_lowercase:
            output += chr((ord(c)-97+n)%26 + 97)
        elif c in string.ascii_uppercase:
            output += chr((ord(c)-65+n)%26 + 97)
        else: output += c
    return output

def generate(key):
    random.seed(key)
    n = random.randint(1, 25)
    msg = plaintext % randword(8)
    return encrypt(msg), "Et tu, Brute?"
