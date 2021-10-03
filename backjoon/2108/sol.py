import sys
from typing import Counter

N = int(sys.stdin.readline())
arr = []

for i in range(N) : 
    arr.append(int(sys.stdin.readline()))

arr.sort()
tmp = Counter(arr).most_common()

print(round(sum(arr) / N))
print(arr[N // 2])

if len(arr) > 1 : 
    if tmp[0][1] == tmp[1][1] : 
        print(tmp[1][0])
    else : 
        print(tmp[0][0])
else : 
    print(tmp[0][0])

print(arr[-1] - arr[0])