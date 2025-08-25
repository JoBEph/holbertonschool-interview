#!/usr/bin/python3

"""Minimum Operations"""


def minOperations(n):
    """ calculates the fewest number of operations """
    if n < 2:
        return 0
    ope_count = 0
    curr_factor = 2

    while n > 1:
        while n % curr_factor == 0:
            ope_count += curr_factor
            n = int(n / curr_factor)
        curr_factor += 1

    return ope_count
