#!/usr/bin/python3
"""
    Main file for testing
"""


def minOperations(n):
    """ minOperations """
    i = 2
    a_list = []

    if type(n) is not int and n < 2:
        return 0

    while n > 1:
        if n % i == 0:
            n /= i
            a_list.append(i)
        else:
            i += 1
    return (sum(a_list))
