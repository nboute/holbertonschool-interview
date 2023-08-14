#!/usr/bin/python3
"""0-lockboxes.py
This module contains a method that takes a list of list of integers
as parameter, and tells if all boxes can be opened
"""


def canUnlockAll(boxes):
    """Checks if all boxes can be opened

        Args: boxes (List): List of Lists of integers

        Returns:
            (bool): Tells whether all items in the list can be opened
    """
    keysDict = {}

    for index, box in enumerate(boxes):
        if box:
            for item in box:
                if index != item:
                    keysDict[item] = True

    for index, box in enumerate(boxes):
        if index != 0 and keysDict.get(index) is not True:
            return False
    return True
