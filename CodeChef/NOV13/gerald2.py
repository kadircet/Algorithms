def res(V, d=0):
	if color[V]==2:
		return [-1, 0]
	if V not in C:
		if color[V] == 0:
			return [V,d]
		return [-1, 0]
	
	for i in C[V]:
		x = res(i, d+1)
		if x[0]!=-1:
			return x
	
	if color[V] == 0:
		return [V,d]
	return [-1,0]

def resP(V, d=0):
	if V==1:
		if color[V] == 0:
			return [V,d]
		return [-1,0]
	
	xd = res(P[V-2], d+1)
	xu = resP(P[V-2], d+1)
	if xu[0]==-1 and xd[0]!=-1:
		return xd
	elif xd[0]==-1 and xu[0]!=-1:
		return xu
	elif xd[0]!=-1 and xu[0]!=-1:
		return xu if xu[1]>=xd[1] else xd
	
	if color[V] == 0:
		return [V,d]
	return [-1,0]

T = input()

while T>0:
	T-=1
	
	N,M = [int(x) for x in raw_input().split(' ')]
	P = [int(x) for x in raw_input().split(' ')]
	
	C = {}
	color = {}
	color[1] = 0
	
	for i in range(len(P)):
		if P[i] not in C:
			C[P[i]] = []
		if i+2 not in color:
			color[i+2] = 0
		C[P[i]].append(i+2)
		
	for val in C:
		C[val] = C[val][::-1]
	
	while M>0:
		M-=1
		
		V = input()
		nc = 1-color[V]
		color[V] = 2
		
		r = res(V)
		md = r[1]
		a=1
		while V!=1:
			V = P[V-2]
			re = res(V,a)
			if re[1]>md:
				md = re[1]
				r = re
			a+=1
		#ru = resP(V)
		color[V] = nc
		print r
