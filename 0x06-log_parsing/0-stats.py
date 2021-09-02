#!/usr/bin/python3
"""Parses a log of status codes with Pirates of the Caribbean references"""
import sys


class parsley:
    '''Methods and values for log parsing and flavor'''

    def __init__(self):
        '''Let's git init'''
        self.totals = {'200': 0, '301': 0, '400': 0, '401': 0,
                       '403': 0, '404': 0, '405': 0, '500': 0}
        self.size = 0

    def parsnip(self):
        '''snips the log into firewood pieces'''
        count = 0
        for line in sys.stdin:
            if len(line) > 30:
                line = line.split()
                if line[-1].isnumeric():
                    self.size += int(line[-1])
                if line[-2].isnumeric():
                    self.totals[line[-2]] += 1
                count += 1
                if count % 10 == 0:
                    self.parler()

    def parler(self):
        '''relays the totals back to the capt...er...user'''
        print("File size: {}".format(self.size))
        for response in sorted(self.totals.keys()):
            if self.totals[response] > 0:
                print("{}: {}".format(response, self.totals[response]))

if __name__ == '__main__':
    log = parsley()
    try:
        log.parsnip()
        log.parler()
    except KeyboardInterrupt:
        log.parler()
