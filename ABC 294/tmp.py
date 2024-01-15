n, m, k = map(int, input().split())

takahashi = []
for i in range(n):
    a, b = map(int, input().split())
    takahashi.append((a, b))

aoki = []
for i in range(m):
    c, d = map(int, input().split())
    aoki.append((c, d))

concentrations = []
for i in range(n):
    for j in range(m):
        concentration = (takahashi[i][0] + aoki[j][0]) / (takahashi[i][1] + aoki[j][1]) * 100
        concentrations.append(concentration)

concentrations.sort(reverse=True)
print('{:.10f}'.format(concentrations[k-1]/100))
