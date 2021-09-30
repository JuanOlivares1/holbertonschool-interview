#!/usr/bin/python3
""" 2d matrix rotation """


def rotate_2d_matrix(matrix):
    """ Rotates a 2D-matrix clockwise
    """
    matrix.reverse()
    m_copy = [row.copy() for row in matrix]
    for i, row in enumerate(m_copy):
        for j, col in enumerate(row):
            matrix[j][i] = m_copy[i][j]
