#!/usr/bin/python3

"""function to determine if all boxes can be unlocked"""


def canUnlockAll(boxes):
    """Determine if all boxes can be unlocked"""
    for n in range(len(boxes)):
        if n == 0:
            continue
        if not boxes[n]:
            return False
        else:
            for key in boxes[n]:
                if key < len(boxes) and key != n:
                    boxes[key].append(n)
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
