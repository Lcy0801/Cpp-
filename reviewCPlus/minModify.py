def getNumber(m,n):
    for i in range(10):
        if i!=m and i!=n:
            return i


def minModify(s):
    n=0
    l=len(s)
    if(l==0 or l==1):
        return 0
    for i in range(1,l):
        current = s[i]
        last =s[i-1]
        if i<n-1:
            next = s[i+1]
        else:
            next = None
        if(current == last):
            new =getNumber(last,next)
            s=s[:i]+str(new)+s[i+1:]
            n+=1
    return n

if __name__=='__main__':
    print(minModify('111222333'))
        
