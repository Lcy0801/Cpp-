import time

def execution_time_out(number):
    print("传入的数字是:{}".format(number))
    def execution_time(func):
        def decoration(a,b):
            start = time.time()
            func(a,b)
            end = time.time()
            t = end - start
            print("函数运行时间:{}s".format(t))
        return decoration
    return execution_time

@execution_time_out(1)
def add(a,b):
    time.sleep(1)
    print(a+b)
    
if __name__ == "__main__":
    add(1,1)