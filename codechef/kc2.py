#!/usr/bin/python
# -*- coding: utf-8 -*-

# cook your dish here




def findNth(n):

    count = 0
    st = 0

    for curr in range(st,9223372036854775807):
        #print (curr)
        sum = 0
        x = curr
        while x:
            sum = sum + x % 10
            x = x // 10
        if sum % 10 == 0 and curr != 0:
            count = count + 1
        if count == n:
            return curr

    return -1


if __name__ == '__main__':
    t = input()
    t = int(t)
    while t:
        t = t - 1
        n = input()
        n = int(n)
        print (findNth(n))
print ('\n')


			