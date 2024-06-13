[n,a,b] = [int(item) for item in input().split(' ')]
cis  = [int(item) for item in input().split(' ')]
minci = min(cis)
maxci = max(cis)
right = (a//n+1)*b//minci+1
left = (a//n)*b//maxci

def f(mid):
    s = 0
    for ci in cis:
        s+= mid*ci//b
    return s

while left<right:
    
    res= f(left)
    if(res>=a):
        break
    mid = (left+right)//2
    res = f(mid)
    if(res>=a):
        right = mid
    elif(res<a):
        left = mid+1
print(res)