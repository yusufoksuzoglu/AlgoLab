def listt(u, v, listed):
    listed[u - 1].append(v)
    listed[v - 1].append(u)

N, M = map(int, input().split())
matrix = [[0] * N for _ in range(N)]
listed = [[] for _ in range(N)]
for i in range(M):
    u, v = map(int, input().split())
    matrix[u - 1][v - 1] = 1
    matrix[v - 1][u - 1] = 1
    listt(u, v, listed)
for i in range(N):
    listed[i].sort()
    for j in range(len(listed[i])):
        print(listed[i][j], end = " ")
    print()
for i in range(N):
    for j in range(N):
        print(matrix[i][j], end = " ")
    print()
