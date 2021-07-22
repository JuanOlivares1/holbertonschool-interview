#!/usr/bin/python3
""" Module """
import sys


def n_queens(n):
    """ func n queens """
    print(board)


if __name__ == "__main__":
    if not len(sys.argv) == 2:
        print("Usage: nqueens N")
        sys.exit(1)

    if not (sys.argv[1]).isdigit():
        print("N must be a number")
        sys.exit(1)

    n = int(sys.argv[1])

    if not (n >= 4):
        print("N must be at least 4")
        sys.exit(1)

    board = [[0 for i in range(n)] for j in range(n)]
    n_queens(board)
