#!/usr/bin/python3
'''
Shows the placement of N queens on a NxN board
'''
import sys


def isSafe(board, row, col):
    '''checks if a placement is safe'''
    # check row
    for i in range(col):
        if (board[row][i]):
            return False
    # check upper diagonal
    y = row
    x = col
    while x >= 0 and y >= 0:
        if (board[y][x]):
            return False
        y -= 1
        x -= 1
    # check lower diagonal
    y = row
    x = col
    while x >= 0 and y < N:
        if (board[y][x]):
            return False
        y += 1
        x -= 1
    return True


def placement(board, col):
    '''Places the next queen'''
    if col >= N:
        queens = []
        for x in range(N):
            for y in range(N):
                if board[x][y] == 1:
                    queen = [x, y]
                    queens.append(queen)
        result.append(queens)
        return True
    res = False
    for i in range(N):
        if (isSafe(board, i, col)):
            board[i][col] = 1
            res = placement(board, col + 1) or res
            board[i][col] = 0
    return res


def nqueens(N):
    '''Main function'''
    result.clear()
    board = [[0 for j in range(N)] for i in range(N)]
    placement(board, 0)
    result.sort()
    return result


if __name__ == '__main__':
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if not sys.argv[1].isdigit():
        print("N must be a number")
        exit(1)
    N = int(sys.argv[1])
    if N < 4:
        print("N must be at least 4")
        exit(1)
    result = []
    for solution in nqueens(N):
        print(solution)
