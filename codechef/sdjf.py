t = input()
t = int (t)
while(t):
	t = t - 1
	n = input()
	n_len = len(n)
	index = n_len // 4

	if(n_len > 15):
		n_arr = [n[0:5],n[5:10],n[10:15],n[15:]]		
	elif(n_len > 10):
		n_arr = [int(n[0:5]),int(n[5:10]),int(n[10:])]			
	elif(n_len > 5):
		n_arr = [int(n[0:5]),int(n[5:])]		
	else:
		n_arr = int (n)

	sum_total = 0	
	for i in range (0,index):
		x = n_arr[i]
		print(x)
		sum = 0
		while (x):
			sum = sum + (x%10)
			x = x // 10
		sum_total = sum_total + sum	
	print (sum_total)
