def func(valuesStr:str):
    values = valuesStr.split(' ')
    values =[int(v) for v in values]
    oxd=dict()
    n=len(values)
    for i in range(1,n-1):
        if values[i]>= values[i-1] and values[i]> values[i+1]:
            oxd[i]=0
    oxdnos= oxd.keys()
    for i in range(1,n-1):
        if i in oxdnos:
            oxd[i]+=values[i]-1
        if values[i-1]>values[i] and values[i+1]<=values[i]:
            for j in range(i-1,1):
                if j in oxdnos:
                    oxd[j]+=values[i]-1
        elif values[i-1]<values[i] and values[i+1]>=values[i]:
            for j in range(i+1,n-1):
                if j in oxdnos:
                    oxd[j]+=values[i-1]
        else:
            for j in range(i+1,n-1):
                if j in oxdnos:
                    break
            for k in range(i-1,1):
                if k in oxdnos:
                    break
            if values[j]>values[k]:
                oxd[j]+=values[i]-1
            else:
                oxd[j]+=values[k-1]
    for v in oxdnos:
        print(oxd[v])
            

if __name__ == "__main__":
    func()
