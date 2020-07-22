'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
n = int(input())
b = {2: 1, 3: 1, 4: 2, 5: 1, 6: 3, 7: 1, 8: 4, 9: 2, 10: 2, 12: 7, 14: 2, 16: 7, 18: 7, 15: 2, 21: 2, 24: 17, 27: 3, 20: 5, 28: 5, 32: 13, 36: 21, 25: 1, 30: 8, 35: 2, 40: 12, 45: 5, 42: 8, 48: 38, 54: 15, 49: 1, 56: 12, 63: 5, 64: 23, 72: 58, 81: 5, 50: 3, 60: 24, 70: 6, 80: 26, 90: 24, 84: 24, 96: 76, 98: 3, 75: 3, 100: 9}
if n in b.keys():
    print(int(b[n]))
else:
    print('0')