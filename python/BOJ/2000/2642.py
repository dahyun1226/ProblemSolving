# 백준 온라인 저지 2642번: 전개도
# 전개도의 조건에 대해 생각해보자
# 코드는 henry11님의 코드

dx, dy = [1, 0, -1, 0], [0, 1, 0, -1]
n = 6

L = [list(map(int, input().split())) for x in range(n)]


def adj(y, x):
    ret = []
    for d in range(4):
        ny, nx = y + dy[d], x + dx[d]
        if 0 <= ny < n and 0 <= nx < n and L[ny][nx]:
            ret.append((ny, nx, d))
    return ret


def dfs(y, x, py, px, dist, dir):
    print(y, x, py, px, dist, dir)
    if dist == 2:
        print()
        return [L[y][x]]
    ret = []
    for ny, nx, d in adj(y, x):
        print(ny,nx,d)
        print(adj(y,x))
        if (ny, nx) != (py, px):
            print(ny, nx, py, px)
            ret += dfs(ny, nx, y, x, dist + (dir + d + 1) % 2, dir)
    return ret


def solve():
    across = [[] for x in range(n + 1)]
    for y in range(n):
        for x in range(n):
            k = L[y][x]
            if L[y][x]:
                for ny, nx, d in adj(y, x):
                    across[k] += dfs(ny, nx, y, x, 1, d)
                print("!")
    print(across)
    for i in range(1, n + 1):
        if len(across[i]) != 1:
            return 0
    print(across)
    return across[1][0]


print(solve())
