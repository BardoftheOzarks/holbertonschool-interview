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

    opcount = 0
    chars = n
    i = 2

    while i < (int(chars / 2) + 1):
        # find prime factors
        if chars % i == 0 and isprime(i):
            opcount += i  # opcount is equal to sum of prime factors
            chars //= i  # decrease loop limit factor for time complexity
            if isprime(chars):  # catch for final factor
                opcount += chars
        else:
            i += 1
    return opcount


def isprime(i):
    '''Determines in an int is prime'''
    for j in range(2, int(i / 2) + 1):
        if i % j == 0:
            return False
    return True
