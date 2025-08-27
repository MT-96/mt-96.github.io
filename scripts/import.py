import sys
from string import ascii_uppercase, ascii_lowercase
def rot_13(string):
    return "".join([encrypt_char(c) for c in string])
