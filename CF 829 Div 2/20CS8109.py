def mp(p):
    ll = len(p) 
    m = [[-1]*ll for _ in range(ll)]
    s = [[-1]*ll for _ in range(ll)]
 
    mcmHelper(p, 1, ll - 1, m, s)
    return m, s
 
def mcmHelper(p, start, end, m, s):
    if m[start][end] >= 0:
        return m[start][end]
 
    if start == end:
        q = 0
    else:
        q = float('inf')
        for k in range(start, end):
            temp = mcmHelper(p, start, k, m, s)
            temp += mcmHelper(p, k + 1, end, m, s)
            temp += p[start-1]*p[k]*p[end]
            if q > temp:
                q = temp
                s[start][end] = k
 
    m[start][end] = q
    return q
 
 
def print_order(s, start, end):
    if start == end:
        print('A[{}]'.format(start), end='')
        return
 
    k = s[start][end]
 
    print('(', end='')
    print_order(s, start, k)
    print_order(s, k + 1, end)
    print(')', end='')
 
 
n = int(input('Enter no of matrices: ------------->'))
p = []
for i in range(n):
    temp = int(input('Enter number of rows in matrix {}: '.format(i + 1)))
    p.append(temp)
temp = int(input('Enter number of columns in matrix {}: '.format(n)))
p.append(temp)
 
m, s = mp(p)
#[5,10,8,15,20,4]
print('The min cost is :----------->', m[1][n])
print('Order is :-------> ', end='')
print_order(s, 1, n)