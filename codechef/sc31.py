#!/usr/bin/python
# -*- coding: utf-8 -*-
t = int(input())
while t:
    t = t - 1
    n = int(input())
    arr = [0] * n
    for i in range(n):
        temp = input()
        arr[i] = int(temp, 2)
    result = arr[0]
    for i in range(1, n):
        result = result ^ arr[i]

    result = bin(result)

    setBits = [ones for ones in result[2:] if ones == '1']

    print (len(setBits))
