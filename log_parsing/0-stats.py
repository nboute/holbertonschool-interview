#!/usr/bin/python3

import fileinput

"""Log parsing"""


def print_logs(file_size: int, status_codes: dict):
    """Print logs"""
    print("File size: {}".format(file_size))
    for key, value in sorted(status_codes.items()):
        if (value > 0):
            print("{}: {}".format(key, value))


def parse_log():
    """Parse log from stdin"""
    file_size = 0
    status_codes = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0}
    current_line = 0

    try:
        for line in fileinput.input():
            data = line.split()
            print(data)
            current_line += 1
            if (len(data) > 8):
                file_size += int(data[8])
                status = int(data[7])
                if (status in status_codes):
                    status_codes[status] += 1

            if (current_line % 10 == 0):
                print_logs(file_size, status_codes)
    except KeyboardInterrupt:
        print_logs(file_size, status_codes)


if __name__ == "__main__":
    parse_log()
