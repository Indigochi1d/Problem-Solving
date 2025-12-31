from sys import stdin

input = stdin.readline


def cant_place(x):
    for i in range(x):
        if chess[x] == chess[i] or abs(chess[x] - chess[i]) == abs(x - i):
            return False
    return True


def n_queens(x):
    global cnt
    if x == n:
        cnt += 1
        return
    else:
        for i in range(n):
            chess[x] = i
            if cant_place(x):
                n_queens(x + 1)


n = int(input())
chess = [0] * n
cnt = 0
n_queens(0)
print(cnt)