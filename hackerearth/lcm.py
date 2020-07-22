'''
# Sample code to perform I/O:

name = input()                  # Reading input from STDIN
print('Hi, %s.' % name)         # Writing output to STDOUT

# Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
'''

# Write your code here
import math
from collections import OrderedDict

def pw(x, y, p) : 
    res = 1     # Initialize result 
  
    # Update x if it is more 
    # than or equal to p 
    x = x % p  
      
    if (x == 0) : 
        return 0
  
    while (y > 0) : 
          
        # If y is odd, multiply 
        # x with result 
        if ((y & 1) == 1) : 
            res = (res * x) % p 
  
        # y must be even now 
        y = y >> 1      # y = y/2 
        x = (x * x) % p 
          
    return res 
# def LCMofArray(a):
#   lcm = a[0]
#   for i in range(1,len(a)):
#     lcm = lcm*a[i]//math.gcd(lcm, a[i])
#   return lcm

MAX = 10000003
  
# mod = 1000000007
  
prime = [0 for i in range(MAX)] 
  
max_map = dict() 
  
# function to return a^n 
def power(a, n, mod): 
      
    if n == 0: 
        return 1
    p = power(a, n // 2,mod) % mod 
    p = (p * p) % mod 
      
    if n & 1: 
        p = (p * a) % mod 
    return p 
  
# function to find the smallest prime 
# factors of numbers upto MAX 
def sieve(): 
    prime[0], prime[1] = 1, 1
    for i in range(2, MAX): 
        if prime[i] == 0: 
            for j in range(i * 2, MAX, i): 
                if prime[j] == 0: 
                    prime[j] = i 
            prime[i] = i 
  
# function to return the LCM modulo M 
def lcmModuloM(arr, n, mod): 
      
    for i in range(n): 
        num = arr[i] 
          
        temp = dict() 
          
        # temp stores mapping of prime factors  
        # to its power for the current element 
        while num > 1: 
               
            # factor is the smallest prime 
            # factor of num 
            factor = prime[num] 
              
            # Increase count of factor in temp 
            if factor in temp.keys(): 
                temp[factor] += 1
            else: 
                temp[factor] = 1
                  
            # Reduce num by its prime factor 
            num = num // factor 
              
        for i in temp: 
            # store the higest power of every prime 
            # found till now in a new map max_map 
            if i in max_map.keys(): 
                max_map[i] = max(max_map[i], temp[i]) 
            else: 
                max_map[i] = temp[i] 
              
    ans = 1
      
    for i in max_map: 
          
        # LCM is product of primes to their 
        # higest powers modulo M 
        ans = (ans * power(i, max_map[i],mod)) % mod 
    return ans 
  
# Driver code 
sieve() 

t = int(input())
for i in range(0,t):
    n,m,k = map(int, input().split())
    arr = list(map(int,input().split()))
    arr = list(set(arr))
    lm = lcmModuloM(arr,n,m)
    lm = power(lm,k,m)
    # lm = power(LCMofArray(arr),k,m)
    print(lm)

