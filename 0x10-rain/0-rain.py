#!/usr/bin/python3
""" Module - Rain
"""


def rain(walls):
    """ calculates water
    """
    water = 0

    if not walls:
        return water

    tmp = 0
    aux = -1
    for i in range(len(walls)):
        if walls[i] > 0:
            if aux == -1:
                aux = i
            j = i + 1
            try:
                while walls[j] == 0:
                    j += 1
                if walls[j] == walls[aux]:
                    water += pour_water(walls[aux:j + 1])
                    water -= tmp
                    aux = -1
                    continue
                water += pour_water(walls[i:j + 1])
                tmp = water
            except IndexError:
                break
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
    print("---> {}".format(water))
    return water
