#!/usr/bin/python3
'''Method to determine if all lockboxes can be opened'''


def canUnlockAll(boxes):
    '''Let's crack some code'''
    keyring = [0]
    count = 0
    while len(boxes) > count:
        for box in range(len(boxes)):
            if box in keyring:
                for key in boxes[box]:
                    if key not in keyring:
                        keyring.append(key)
        count += 1
        if len(boxes) == len(keyring):
            return True
    return False
