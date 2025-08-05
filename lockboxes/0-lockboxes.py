#!/usr/bin/python3

"""function to determine if all boxes can be unlocked"""


def canUnlockAll(boxes):
    """Determine if all boxes can be unlocked"""
    if not boxes:
        return True
    
    unlocked = [False] * len(boxes)
    unlocked[0] = True
    stack = [0]

    while stack:
        current = stack.pop()
        for key in boxes[current]:
            if key < len(boxes) and not unlocked[key]:
                unlocked[key] = True
                stack.append(key)

    return all(unlocked)
