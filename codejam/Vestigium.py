def printRepeating(arr, size): 
    s = set(arr)
    if (len(s) != size):
        return 1
    return 0
    
t = int(input())

for case in range(1,t+1):
    n = int(input())
    arr2d = [[int(j) for j in input().strip().split(" ")] for i in range(n)]
    arr2dT = [[arr2d[j][i] for j in range(n)] for i in range(n)]
    
    k = 0
    r = 0
    c = 0
    for i in range(0,n):
        k += arr2d[i][i]
        if(printRepeating(arr2d[i],n)):
            r += 1
        if(printRepeating(arr2dT[i],n)):
            c += 1
    
    print("Case #{0}: {1} {2} {3}".format(case,k,r,c))