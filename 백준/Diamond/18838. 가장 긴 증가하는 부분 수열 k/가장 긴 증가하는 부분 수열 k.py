from bisect import bisect_left


def bisect_left_dsc(a, x, key=None):  # a는 내림차순 정렬된 배열이고, 반환값을 i라고 하면, a[:i]의 모든 e에 대하여 e > x
    lo = 0
    hi = len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if x < key(a[mid]):
            lo = mid + 1
        else:
            hi = mid
    return lo


def bisect_right_dsc(a, x, key=None):  # a[i:]의 모든 e에 대하여 e < x:
    lo = 0
    hi = len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if x > key(a[mid]):
            hi = mid
        else:
            lo = mid + 1
    return lo


def make():  # d배열 제작 (a배열 에서의 index = d[i][j]인 원소를 마지막 원소로 하는 부분 수열의 길이가 곧 i)
    for i in range(len(a)):
        pos = bisect_left(d, a[i], key=lambda x: a[x[-1]])
        if pos == len(d):
            d.append([i])
        else:
            d[pos].append(i)


def count():  # d배열을 토대로 tot 배열 제작 (편의상 tot[i]의 첫 원소를 0으로 넣어줌)
    for i in range(len(d)):
        tot.append([])
    for i in range(len(d[-1]) + 1):
        tot[-1].append(i)
    for i in range(len(d) - 2, -1, -1):
        tot[i].append(0)
        for j in range(len(d[i])):
            lo = bisect_left(d[i + 1], d[i][j])  # 이분탐색
            hi = bisect_left_dsc(d[i + 1], a[d[i][j]], key=lambda x: a[x])
            if lo >= hi or hi > len(d[i + 1]):
                tot[i].append(0)
            else:
                tot[i].append(tot[i + 1][hi] - tot[i + 1][lo])
        for j in range(1, len(d[i]) + 1):  # 누적합
            tot[i][j] += tot[i][j - 1]
    return tot[0][-1]


def find(k):  # 여기가 문제인 것 같은데..
    res = []
    for i in range(len(d)):
        mult.append([])
        for j in range(len(d[i]) + 1):
            mult[i].append(0)
    for i in range(1, len(d[0]) + 1):  # mult도 누적합으로 제작.
        mult[0][i] = i
    for i in range(len(tot)):
        if i != 0:
            for j in range(len(tot[i]) - 1, 0, -1):
                if d[i][j - 1] > res[-1] and a[d[i][j - 1]] > a[res[-1]] and tot[i][j] - tot[i][j - 1] > 0:
                    lo = bisect_left_dsc(d[i - 1], a[res[-1]], key=lambda x: a[x])  # lo까지가 res[-1]
                    hi = min(bisect_right_dsc(d[i - 1], a[res[-1]], key=lambda x: a[x]),
                             bisect_left(d[i - 1], d[i][j - 1]))  # hi - 1까지가 res[-1]임.
                    mult[i][j] = mult[i - 1][hi] - mult[i - 1][lo]
            for j in range(1, len(tot[i])):  # 누적합
                mult[i][j] += mult[i][j - 1]
        j = len(tot[i]) - 1
        while j > 0:
            if (len(res) == 0 or a[d[i][j - 1]] > a[res[-1]]) and tot[i][j] - tot[i][j - 1] > 0:
                cnt = (tot[i][j] - tot[i][j - 1]) * (mult[i][j] - mult[i][j - 1])
                while j > 1 and a[d[i][j - 1]] == a[d[i][j - 2]] and (len(res) == 0 or d[i][j - 2] > res[-1]):
                    j -= 1
                    cnt += (tot[i][j] - tot[i][j - 1]) * (mult[i][j] - mult[i][j - 1])
                if k > cnt:
                    k -= cnt
                else:
                    res.append(d[i][j - 1])
                    break
            j -= 1
    return list(map(lambda x: a[x], res))


n, k = map(int, input().split())
a = list(map(int, input().split()))

d = []
tot = []
mult = []
make()

if k > count():
    print(-1)
else:
    print(*find(k))
