#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 1
print("Min # of operations to reach {} char: {}, 1".format(n, minOperations(n)))
n = 2
print("Min # of operations to reach {} char: {}, 2".format(n, minOperations(n)))
n = 139
print("Min # of operations to reach {} char: {}, 139".format(n, minOperations(n)))
n = 4
print("Min # of operations to reach {} char: {}, 4".format(n, minOperations(n)))
n = 5
print("Min # of operations to reach {} char: {}, 5".format(n, minOperations(n)))
n = 6
print("Min # of operations to reach {} char: {}, 5".format(n, minOperations(n)))
n = 7
print("Min # of operations to reach {} char: {}, 7".format(n, minOperations(n)))
n = 8
print("Min # of operations to reach {} char: {}, 6".format(n, minOperations(n)))
n = 10
print("Min # of operations to reach {} char: {}, 7".format(n, minOperations(n)))
n = 12
print("Min # of operations to reach {} char: {}, 7".format(n, minOperations(n)))
n = 15
print("Min # of operations to reach {} char: {}, 8".format(n, minOperations(n)))
n = 21
print("Min # of operations to reach {} char: {}, 10".format(n, minOperations(n)))
n = 99
print("Min # of operations to reach {} char: {}, 17".format(n, minOperations(n)))
