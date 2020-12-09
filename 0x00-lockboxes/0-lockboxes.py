#!/usr/bin/python3
""" Lockboxes """


def canUnlockAll(boxes):
    """ Tels if all boxes can be opened """
    stack = []
    nodeSeen = []
    node = 0

    while node not in nodeSeen and node is not None:
        nodeSeen.append(node)
        for key in boxes[node]:
            if key not in nodeSeen:
                stack.append(key)
        if stack:
            node = stack[-1]
            stack.pop()
        else:
            break
    if len(nodeSeen) == len(boxes):
        return True
    else:
        return False
