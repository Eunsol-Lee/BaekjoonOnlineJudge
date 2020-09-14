from queue import Queue

T = int(input())
for _ in range(T):
    N, K = map(int, input().split())
    D = list(map(int, input().split()))
    inbound = [0] * 1001
    matrix = [[0] * 1001 for _ in range(1001)]
    value = [0] * 1001
    for _ in range(K):
        X, Y = map(int, input().split())
        matrix[X][Y] = 1
        inbound[Y] += 1
    W = int(input())

    q = Queue()

    for i in range(1, N + 1):
        if inbound[i] == 0:
            q.put(i)
            value[i] = D[i - 1]
    while not q.empty():
        c = q.get()
        for i in range(1, N + 1):
            if matrix[c][i]:
                value[i] = max(value[i], value[c] + D[i - 1])
                inbound[i] -= 1
                if inbound[i] == 0:
                    q.put(i)
    print(value[W])
