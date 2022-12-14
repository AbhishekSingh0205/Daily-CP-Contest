def matrix_product(p):
    length = len(p)
    m = [[-1]*length for _ in range(length)]
    s = [[-1]*length for _ in range(length)]
 
    matrix_product_helper(p, 1, length - 1, m, s)
    return m, s
 
def matrix_product_helper(p, start, end, m, s):
    if m[start][end] >= 0:
        return m[start][end]
 
    if start == end:
        q = 0
    else:
        q = 10000000
        for k in range(start, end):
            temp = matrix_product_helper(p, start, k, m, s)
            temp += matrix_product_helper(p, k + 1, end, m, s)
            temp += p[start-1]*p[k]*p[end]
            if q > temp:
                q = temp
                s[start][end] = k
 
    m[start][end] = q
    return q
 
 
def print_order(s, start, end):
    if start == end:
        print(start, end='')
        return
 
    k = s[start][end]
 
    print('(', end='')
    print_order(s, start, k)
    print_order(s, k + 1, end)
    print(')', end='')
 
 
n = int(input('Enter number of matrices: '))
p = []
for i in range(n):
    temp = int(input('Enter number of rows in matrix {}: '.format(i + 1)))
    p.append(temp)
temp = int(input('Enter number of columns in matrix {}: '.format(n)))
p.append(temp)
 
m, s = matrix_product(p)
#[5,10,8,15,20,4]
print('The minimum cost is', m[1][n])
print('Optimal order: ', end='')
print_order(s, 1, n)

# at {i} position suppose number {j} comes :
# probability of it is 1/M
# Basically cnt/(M)^k


