#!/usr/bin/python3
"""0-making_change.py
This module contains the function makeChange(coins, total).
"""

def makeChange(coins, total):
    """Make change for a given total using the fewest number of coins.
    Args:
        coins: a list of integers representing coin denominations
        total: an integer representing the total amount of change to make
    Returns:
        An integer representing the fewest number of coins to make the given
        total. If the total cannot be made with the given coins, return -1.
    """
    if total == 0:
        return 0
    if len(coins) == 0:
        return -1
    coins = sorted(coins, reverse=True)
    i = 0
    while coins[i] > total:
        i += 1
        if i == len(coins):
            return -1
    count = total // coins[i]
    total = total % coins[i]
    ret = makeChange(coins[i:], total)
    if ret == -1:
        return -1
    else:
        return count + ret
