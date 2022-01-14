#!/usr/bin/python3
'''
Rotates a 2D matrix clockwise by 90 degrees
'''

def rotate_2d_matrix(matrix):
    '''Spin the wheel...or matrix'''
    size = len(matrix)
    count = 0

    '''flip diagonally'''
    for row in range(len(matrix)):
        for col in range(len(matrix)):
            if col > row:
                (matrix[row][col], matrix[col][row]) =\
                (matrix[col][row], matrix[row][col])
    '''flip horizontally'''
    for row in matrix:
        size = len(matrix) - 1
        count = 0
        while size > count:
            (row[count], row[size]) = (row[size], row[count])
            count += 1
            size -= 1
