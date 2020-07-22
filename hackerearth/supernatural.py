# def prod(i):
#     pr = 1
#     while(i!=0):
#         r = i%10
#         if(r == 1):
#             return 0
#         pr = pr * r
#         i = i//10
#     return pr
# def CountFrequency(my_list): 
      
#    # Creating an empty dictionary  
#    count = {} 
#    for i in my_list: 
#     count[i] = count.get(i, 0) + 1
#    return count

# a = []
# for i in range(1,222224):
#     pr = prod(i)
#     if pr != 0 and pr<=100:
#         print("i = {0} prod = {1}".format(i,pr))
#         a.append(pr)

# b = CountFrequency(a)
# print (b)

b = {2: 1, 3: 1, 4: 2, 5: 1, 6: 3, 7: 1, 8: 4, 9: 2, 10: 2, 12: 7, 14: 2, 16: 7, 18: 7, 15: 2, 21: 2, 24: 17, 27: 3, 20: 5, 28: 5, 32: 13, 36: 21, 25: 1, 30: 8, 35: 2, 40: 12, 45: 5, 42: 8, 48: 38, 54: 15, 49: 1, 56: 12, 63: 5, 64: 24, 72: 58, 81: 5, 50: 3, 60: 24, 70: 6, 80: 26, 90: 24, 84: 24, 96: 82, 98: 3, 75: 3, 100: 9}

for i in range(1,101):
    if i in b.keys():
        print("i = {0}  count = {1}".format(i,b[int(i)]))
    else :
        print("i = {0}  count = 0".format(i))
