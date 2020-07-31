def sumdigtis(a):
    sm = 0
    while(a):
        sm += a%10
        a /= 10
    return sm

for i in range(100):
    summedvalue = sumdigtis(i)
    a = i%9
    print("i = {0} sum of digits = {2} i%9 = {3}".format(i,sum)