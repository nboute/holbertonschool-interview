#!/usr/bin/python3
"""N queens problem solver."""
import sys


def solve_nqueens(n, chessboard, index: int = 0):
    """Solves the N queens problem.
    Args:
        n: The size of the chessboard.
    """
    if (index == n):
        return
    for col in range(n):
        if check_queen(chessboard, index, col):
            chessboard[index] = col
            if index == n - 1:
                print_nqueens(chessboard)
            solve_nqueens(n, chessboard, index + 1)
            chessboard[index] = None


def check_queen(chessboard, row: int, col: int):
    """Checks if a queen can be placed at a given position.
    Args:
        chessboard: The chessboard.
        row: The row to check.
        col: The column to check.
    """
    for i in range(len(chessboard)):
        if chessboard[i] is None:
            continue
        if chessboard[i] == col and i != row:
            return False
        if i != row and (chessboard[i] == col - (row - i) or
                         chessboard[i] == col + (row - i)):
            return False
    return True


def print_nqueens(chessboard):
    """Prints the chessboard.
    Args:
        chessboard: The chessboard."""
    queens = []
    for row in range(len(chessboard)):
        queens.append([row, chessboard[row]])
    print(queens)


def nqueens():
    if len(sys.argv) != 2:
        print('Usage: nqueens N')
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print('N must be a number')
        sys.exit(1)

    if n < 4:
        print('N must be at least 4')
        sys.exit(1)

    chessboard = [None for row in range(n)]
    solve_nqueens(n, chessboard)


if __name__ == '__main__':
    nqueens()
