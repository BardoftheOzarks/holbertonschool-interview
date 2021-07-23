#!/usr/bin/python3
'''Method to determine if all lockboxes can be opened'''


def canUnlockAll(boxes):
    '''Let's crack some code'''
    if boxes is None or len(boxes) < 1:
        return False
    keyring = [0]
    count = 0
    while len(boxes) > count:
        for key in keyring:
            for keys in boxes[key]:
                if keys not in keyring and keys < len(boxes):
                    keyring.append(keys)
        count += 1
        if len(boxes) == len(keyring):
            return True
    return False
