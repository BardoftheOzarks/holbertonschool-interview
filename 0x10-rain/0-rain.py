#!/usr/bin/python3
'''
rain collection calculator
'''


def rain(walls):
    '''Caculates how much rain is collected'''
    total = 0
    index = 0

    if (len(walls) > 2):
        right = -1
        sub = 0
        while (index < len(walls)):
            if (walls[index] > 0):
                if (right < 0):
                    right = index
                else:
                    left = index
                    width = left - right - 1
                    if (walls[left] >= walls[right]):
                        total += (walls[right] * width) - sub
                        right = left
                        left = 0
                        sub = 0
                    elif (walls[left] * width < sub):
                        sub += walls[left]
                    else:
                        total += (walls[left] * width) - sub
                        sub += ((walls[left] * (width + 1)) - sub)

            index += 1

    return total
