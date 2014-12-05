def o(s):
    l=len(s)
    #s = set(s)
    #q = len(set(s))
    #return q==l
    return len(set([a+b+c
                    for a in s for b in s for c in s])
               )==l*(l+1)*(l+2)//6

M=int(input())
N=3**M
i=9
s=M*[i]
s=[1,2,5,12,24,46,83,130,236,400]
while i:
    if s[i]-N:
        s[i]=s[i]+1
        if o(s[:i+1]):
            print s
            if i<M-1:
                i=i+1
                s[i]=s[i-1]
            else:
                N=s[-1]
    else:
        i=i-1
print(N)

