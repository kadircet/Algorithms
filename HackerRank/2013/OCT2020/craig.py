words = {}

f = open('training.json')
f.readline()
inp = f.readlines()
for i in range(len(inp)):
	inp[i] = eval(inp[i].split('\n')[0])

for i in range(len(inp)):
	if inp[i]['section'] not in words:
		words[inp[i]['section']] = {}
	if inp[i]['category'] not in words[inp[i]['section']]:
		words[inp[i]['section']][inp[i]['category']] = {}
	for w in inp[i]['heading'].lower():
		if w not in words[inp[i]['section']][inp[i]['category']]:
			words[inp[i]['section']][inp[i]['category']][w] = 0
		words[inp[i]['section']][inp[i]['category']][w] += 1

n = input()
for i in range(n):
	inp = eval(raw_input())
	point = {}
	for cat in words[inp['section']]:
		point[cat] = 0
	for w in inp['heading'].lower():
		for cat in point:
			point[cat] += 1.*words[inp['section']][cat][w]/sum(words[inp['section']][cat].values()) \
			if w in words[inp['section']][cat] else 0
	
	m=0
	mcat=''
	for cat in point:
		if point[cat]>m:
			m=point[cat]
			mcat=cat
	if mcat:
		print mcat

