def planeNum(n,m,k,N,M,K):
    res=0
    for i in range(n):
        for j in range(m):
            for h in range(k):
                s=N[i]*M[j]*K[h]
                if  s>=l and s<=r:
                    res+=1
    return res




if __name__ == "__main__":
    s=input()
    nmk= [int(item) for item in s.split()]
    n=nmk[0]
    m=nmk[1]
    k=nmk[2]

    ns=input()
    ms=input()
    ks=input()
    l=int(input())
    r=int(input())
    N= [int(item) for item in ns.split()]
    M= [int(item) for item in ms.split()]
    K= [int(item) for item in ks.split()]
    print(planeNum(n,m,k,N,M,K))