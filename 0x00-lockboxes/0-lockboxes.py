#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    """ Tels if all boxes can be opened """
    stack = []
    nodeSeen = []
    node = 0

    if not boxes:
        return True

    while node not in nodeSeen and node is not None:
        nodeSeen.append(node)
        for key in boxes[node]:
            if key not in nodeSeen and key < len(boxes) and key not in stack:
                stack.append(key)
        if stack:
            node = stack[-1]
            stack.pop()
    if len(nodeSeen) == len(boxes):
        return True
    else:
        return False
