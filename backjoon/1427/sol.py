N = int(input())

s = str(N)
arr = []

for c in s : 
    arr.append(int(c))
    
s2 = ""

for _ in sorted(arr) : 
    s2 += str(_)

s2 = s2[::-1]

print(s2)
