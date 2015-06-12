def powm(a, b):
	if b==1:
		return a
	
	return powm((a*a)%1000000007,b/2) * (a if b%2==1 else 1)

t = input()
while t>0:
	t-=1
	line = [int(x) for x in raw_input().split(' ')]
	a = line[0]%1000000007
	b = line[1]%1000000006
	print powm(a, b)%1000000007
