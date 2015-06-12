import sys
import math
 
stdin = sys.stdin
 
Mid= lambda x : ((x[0] + x[1])>>1)
Lowbit = lambda x : (x&(-x))
 
used = {}
 
class Task:
	def __init__(self , _d , _m , _index):
		self.d = int(_d)
		self.m = int(_m)
		self.index = int(_index)
	def __lt__(self , other):
		if (self.d == other.d):
			return self.m > other.m
		else:
			return self.d < other.d
	def __repr__(self):
		return str((self.d , self.m))
class Node:
	def __init__(self):
		self.val = 0
		self.idx = 0
		self.add = 0
		self.cover = (0 , 0)
		self.lChild = None
		self.rChild = None
	def __lt__(self , other):
		if (self.idx not in used):
			return True
		if (other.idx not in used):
			return False
		return self.val < other.val
	def __repr__(self):
		return str(self.val)
	def build(self , cover):
		self.cover = cover
		self.idx = cover[0]
		if (cover[0] == cover[1]):
			return
		mid = Mid(cover)
		self.lChild = Node()
		self.rChild = Node()
		self.lChild.build( (cover[0] , mid) )
		self.rChild.build( (mid + 1 , cover[1]) )
	def addDown(self):
 
		self.lChild.addValue(self.add)
		self.rChild.addValue(self.add)
		self.add = 0
 
	def update(self , cover, add):
		if (cover[0] <= self.cover[0] and cover[1] >= self.cover[1]):
			self.val += add
			self.add += add
			return
		if (self.add):
			self.addDown()
		mid = Mid(self.cover)
		if (cover[0] <= mid):
			self.lChild.update(cover , add)
		if (cover[1] > mid):
			self.rChild.update(cover , add)
 
		ret = max( self.lChild , self.rChild )
		self.val = ret.val
		self.idx = ret.idx
 
	def query(self , cover):
		if (cover[0] == self.cover[0] and cover[1] == self.cover[1]):
			return self
		if (self.add):
			self.addDown()
		mid = Mid(self.cover)
		if (cover[1] <= mid):
			return self.lChild.query(cover)
		elif (cover[0] > mid):
			return self.rChild.query(cover)
		else:
			vl = self.lChild.query( (cover[0] , mid) )
			vr = self.rChild.query( (mid + 1 , cover[1]) )
			return max(vl , vr)
 
class BinIdxTree:
	def __init__(self , size):
		self.S = [0 for i in range(size+10)]
	def add(self , x , c):
 
		while (x <= n):
			self.S[x] += c
			x += Lowbit(x)
	def getsum(self , x):
		res = 0
		while (x > 0):
			res += self.S[x]
			x -= Lowbit(x)
		return res
 
 
line = stdin.readline()
n = int(line)
 
segTreeRoot = Node()
segTreeRoot.build((1 , n))
bTree = BinIdxTree(n)
 
taskList = []
rank = [0 for i in range(n+1)]
 
for i in range(n):
	line = stdin.readline()
	[d , m] = [int(x) for x in line.split()]
	t = Task(d , m , i)
	taskList.append(t)
 
taskList.sort()
 
for i in range(n):
	rank[ taskList[i].index ] = i
 
ans = 0
for i in range(n):
	p = rank[i] + 1
	bTree.add(p , taskList[p-1].m)
	used[p] = True
	segTreeRoot.update((p , p) ,  - taskList[p-1].d)
	segTreeRoot.update((p , n) , taskList[p-1].m)
	res = bTree.getsum(p) - taskList[p-1].d
	res = 0 if res < 0 else res
	if (p + 1 <= n):
		resNode = segTreeRoot.query((p + 1 , n))
		p = resNode.idx
		if (p in used):
			print p,bTree.getsum(p), taskList[p-1].d
			s =bTree.getsum(p) - taskList[p-1].d
			res = s if s > res else res
	ans = res if res > ans else ans
	print ans

