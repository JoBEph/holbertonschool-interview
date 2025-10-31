#!/usr/bin/python3
"""
Prints all possible N-queens solutions as lists of [row, col] pairs.
"""

import sys


def is_safe(queens, row, col):
    """Return True if is safe."""
    for r, c in queens:
        if c == col or abs(c - col) == abs(r - row):
            return False
    return True


def solve(n, row, queens, solutions):
    """place queens row by row."""
    if row == n:
        solutions.append([[r, c] for r, c in queens])
        return

    for col in range(n):
        if is_safe(queens, row, col):
            queens.append([row, col])
            solve(n, row + 1, queens, solutions)
            queens.pop()


def main():
    """Solve and print solutions."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        n = int(sys.argv[1])
    except Exception:
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []
    solve(n, 0, [], solutions)
    for sol in solutions:
        print(sol)


if __name__ == "__main__":
    main()
