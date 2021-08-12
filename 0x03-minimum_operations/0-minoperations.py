#!/usr/bin/python3
"""
Calculates the minimum number of CopyAll and Paste operations to make n chars
"""


def minOperations(n):
    '''Finds the minimum number of operations'''
    if type(n) is not int or n < 2:
        return 0
    if isprime(n):
        return n
    factors = []
    opcount = 0
    chars = n
    check = 1
    i = 2

    while i < (int(chars / 2) + 1):
        # check for potential prime factors
        if chars % i == 0 and isprime(i):
            factors.append(i)
            chars //= i
            if isprime(chars):
                factors.append(chars)
        else:
            i += 1
    for factor in factors:
        opcount += factor  # add all prime factors together for min ops
        check *= factor
    if check != n:  # check for missing duplicate factor
        print("Duplicate factors missing")
    return opcount


def isprime(i):
    '''Determines in an int is prime'''
    for j in range(2, int(i / 2) + 1):
        if i % j == 0:
            return False
    return True
