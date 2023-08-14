#!/usr/bin/python3

def canUnlockAll(boxes):
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
