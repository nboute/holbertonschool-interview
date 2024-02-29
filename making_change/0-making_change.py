#!/usr/bin/python3
"""0-making_change.py
This module contains the function makeChange(coins, total).
"""


def makeChange(coins, total, count=0):
    """Make change for a given total using the fewest number of coins.
    Args:
        coins: a list of integers representing coin denominations
        total: an integer representing the total amount of change to make
    Returns:
        An integer representing the fewest number of coins to make the given

        total. If the total cannot be made with the given coins, return -1.
    """
    if total == 0:
        return count
    if total < 0 or len(coins) == 0:
        return -1
    coins = sorted(coins, reverse=True)

    remove_coin = makeChange(coins, total - coins[0], count + 1)

    pop_pile = makeChange(coins[1:], total, count)
    if remove_coin == -1 and pop_pile == -1:
        return -1
    if remove_coin == -1:
        return pop_pile
    if pop_pile == -1:
        return remove_coin
    return min(remove_coin, pop_pile)
