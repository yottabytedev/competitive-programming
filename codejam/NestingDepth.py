t = int(input())
for case in range(1,t+1):
    S = input()
    S2 = ''
    bracket = 0
    for num in S:
        if(int(num) > bracket):
            for i in range(int(num) - bracket):
                S2 += '('
                bracket += 1
        if(int(num) < bracket):
            for i in range(bracket - int(num)):
                S2 += ')'
                bracket -= 1
        S2 += num
    for i in range(bracket):
        S2 += ')'
    
    print("Case #{0}: {1}".format(case,S2))