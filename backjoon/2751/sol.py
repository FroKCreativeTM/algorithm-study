# import heapq 

# def merge_sort(arr) : 
#     if len(arr) <= 1 : 
#         return arr

#     mid = len(arr) // 2
#     left = merge_sort(arr[:mid])
#     right = merge_sort(arr[mid:])
#     i = 0
#     j = 0
#     k = 0

#     while len(left) > i and len(right) > j : 
#         if left[i] < right[j] : 
#             arr[k] = left[i]
#             i += 1
            
#         else : 
#             arr[k] = right[j]
#             j += 1
        
#         k += 1

#         # 왼쪽만 남은 경우
#     if len(left) == i : 
#         while len(right) > j : 
#             arr[k] = right[j]
#             j += 1
#             k += 1

#     # 오른쪽만 남은 경우
#     elif len(right) == j : 
#         while len(left) > i : 
#             arr[k] = left[i]
#             i += 1
#             k += 1
                
#     return arr

# N = int(input())
# arr = []
# for i in range(N) : 
#     arr.append(int(input()))

# arr = merge_sort(arr)

# for _ in arr: 
#     print(_)

# 위 코드는 O(NlogN) 문제다
# 하지만 속도 이슈로 인해 pypy3의 sorted를 쓰자
N = int(input())
arr = []

for i in range(N) : 
    arr.append(int(input()))

for _ in sorted(arr): 
    print(_)