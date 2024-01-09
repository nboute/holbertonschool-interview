#!/usr/bin/python3
""" Rain module"""


def rain(walls):
    """Rain function
    Args:
        walls: list of non-negative integers
        Returns: integer indicating total amount of rainwater retained
    """
    if walls is None or len(walls) == 0:
        return 0

    water = 0
    last_wall = 0
    width = 0
    for i in range(0, len(walls)):
        if (walls[i] != 0):
            if last_wall != 0:
                water += width * min(last_wall, walls[i])
            last_wall = walls[i]
            width = 0
        else:
            width += 1

    return water
