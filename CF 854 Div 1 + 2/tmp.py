from collections import Counter

t = int(input())
for _ in range(t):
    s = input().strip()
    freq = Counter(s)
    sorted_chars = sorted(freq.keys(), key=lambda x: -freq[x])
    n = len(s)
    t = [''] * n
    i = 0
    j = n - 1
    for c in sorted_chars:
        count = freq[c]
        if i < j:
            # Interleave the characters
            t[i] = c
            t[j] = c
            i += 1
            j -= 1
            count -= 1
        else:
            # Place the remaining characters in the middle
            t[n // 2] = c
            count -= 1
        while count > 0:
            # Fill the remaining positions
            if i < n // 2:
                t[i] = c
                i += 1
            else:
                t[j] = c
                j -= 1
            count -= 1
    print(''.join(t))
