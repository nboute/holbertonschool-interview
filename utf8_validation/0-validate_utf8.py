#!/usr/bin/python3

""" 0-validate_utf8.py
This module contains the function validUTF8, which determines if a given data
set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """ validUTF8 - determines if a given data set represents a valid UTF-8
    encoding.
    Arguments:
    data: list of integers
    Returns:
    True if data is a valid UTF-8 encoding, False otherwise
    """
    if (type(data) is not list or any(not isinstance(i, int) for i in data)):
        return False
    if (any(i not in range(0, 255) for i in data)):
        return False
    try:
        byte_data = bytes([data])
        data.decode('utf-8')
    except UnicodeError:
        return False
    finally:
        return True
