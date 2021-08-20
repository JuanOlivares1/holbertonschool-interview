#!/usr/bin/python3
""" Module - Rain
"""


def rain(walls):
    """ calculates water
    """
    water = 0

    if not walls:
        return water

    prev = walls[0]
    higher = [(0, walls[0])]
    f1 = 0
    t_water = 0
    for i in range(1, len(walls)):
        if walls[i] > prev:
            if walls[i] > higher[-1][1]:
                higher.append((i, walls[i]))
                i += 1
                f1 = 0
            if f1 != 0:
                t_water = pour_water(walls[higher[-1][0]:i + 1])
                if walls[i] == higher[-1][1]:
                    higher.append((i, walls[i]))
            water += t_water
            if i != len(walls) and walls[i] == higher[-1][1]:
                higher.append((i, walls[i]))

        if i != len(walls):
            if walls[i] < prev and f1 == 0:
                for j in range(i + 1, len(walls)):
                    if walls[j] > walls[i]:
                        t_water = pour_water(walls[i - 1:j + 1])
                        i = j
                        f1 = 1
                        if walls[i] == higher[-1][1]:
                            higher.append((i, walls[i]))
                            i += 1
                            f1 = 0
                        break
            prev = walls[i]

    return water


def pour_water(well):
    """ calculates water btw 2 walls
    """
    depth = min(well[0], well[-1])
    width = len(well) - 2
    uw_block = 0
    water = 0

    for i in (well):
        if i > 0 and i < depth:
            uw_block += i

    water += (depth * width) - uw_block
    return water
