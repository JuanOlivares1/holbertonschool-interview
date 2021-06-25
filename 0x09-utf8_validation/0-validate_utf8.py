#!/usr/bin/python3
""" """


def validUTF8(data):
    """
    Args:
        data (list): data set of characters
    """
    t_bytes = 0

    for i in data:
        byte = format(i, '#010b')[-8:]
        if t_bytes == 0:
            if byte[0] == '1':
                t_bytes = len(byte.split('0')[0])

            if t_bytes == 1 or t_bytes > 4:
                return False

            elif t_bytes == 0:
                continue
        else:
            if not byte.startswith('10'):
                return False
        t_bytes = t_bytes - 1

    if t_bytes != 0:
        return False
    return True
