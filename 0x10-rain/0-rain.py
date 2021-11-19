#!/usr/bin/python3
'''
rain collection calculator
'''


def rain(walls):
    '''Caculates how much rain is collected'''
    total = 0
    index = 0

    if (len(walls) > 3):
        right = 0
        sub = 0
        while (index < len(walls)):
            if (walls[index] > 0):
                if (right == 0):
                    right = walls[index]
                    r_index = index
                else:
                    left = walls[index]
                    width = index - r_index - 1
                    if (left >= right):
                        total += (right * width) - sub
                        right = left
                        left = 0
                        r_index = index
                        sub = 0
                    else:
                        total += (left * width) - sub
                        sub += ((left * width) - sub) + left

            index += 1

    return total
