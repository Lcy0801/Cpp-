def maxK(s: str, k: int):
    flag = True
    index = -1
    n = len(s)
    i = 0
    while i < k:
        flag_ = True
        if flag:
            for j in range(index+1, n, 1):
                ch = s[j]
                if ch == '0':
                    s = s[0:j]+'1'+s[j+1:]
                    index = j
                    i += 1
                    flag_ = False
                    break
            if flag_:
                flag = False
                index = n-1
        else:
            for j in range(index-1, -1, -1):
                ch = s[j]
                if ch == '1':
                    s = s[0:j]+'0'+s[j+1:]
                    i += 1
                    index = j
                    break
            if flag_:
                flag = True
                index = 0
    return s


if __name__ == "__main__":
    s = input()
    k = int(input())
    print(maxK(s, k))
