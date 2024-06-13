s=input()
n =int(input())
slist = s.split(";")[:-1]
print(slist)
for i in range(n):
    key = input()
    value=None
    for item in slist:
        [k,v]=item.split("=")
        if(k==key):
            value=v
    print(value)
