# 迭代器是一个对象，需要实现__iter__和__next__两个函数
class MyIteration:
    def __init__(self) -> None:
        self.x =1
        self.y=1
        self.n=0
    def __iter__(self):
        return self
    def __next__(self):
        if self.n >=10:
            raise StopIteration
        res= self.x
        self.x,self.y = self.y,self.x+self.y
        self.n+=1
        return res

# 生成器是一个特殊的函数，能有多个返回值，每调用一次都会有一个返回值, 关键字yield

def flattenList(llist):
    for l in llist:
        for i in l:
            yield i
            
            

if __name__=="__main__":
    it = MyIteration()
    for i in it:
        print(i)
    # llsit = [[1,1,1],[2,2,2],[3,3,3],[4,4,4]]
    # items = flattenList(llsit)
    # for item in items:
    #     print(item)
    
        
        
        