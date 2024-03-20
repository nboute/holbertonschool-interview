#!/usr/bin/python3
"""0-island_perimeter.py

This module implements the island_perimeter function that
calculates the perimeter of an island.
"""


def island_perimeter(grid):
    """island_perimeter function
    This function calculates the perimeter of an island.
    Args:
        grid (list of lists): A grid of integers.
    Returns:
        int: The perimeter of the island.
    """
    count = 0
    if grid is None:
        return 0
    if len(grid) == 0:
        return 0
    for row in grid:
        if len(row) == 0:
            return 0
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if grid[i][j] == 1:
                if i == 0 or grid[i - 1][j] == 0:
                    count += 1
                if i == len(grid) - 1 or grid[i + 1][j] == 0:
                    count += 1
                if j == 0 or grid[i][j - 1] == 0:
                    count += 1
                if j == len(grid[i]) - 1 or grid[i][j + 1] == 0:
                    count += 1
    return count
