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