def getPermutations(n):
    if(n==1):
        return [[1]]
    resN_1=getPermutations(n-1)
    resN=[]
    for item in resN_1:
        for i in range(n):
            # 防止浅拷贝的问题
            item_=item[:]
            item_.insert(i,n)
            resN.append(item_)
    return resN

if __name__=='__main__':
    print(getPermutations(5))
    