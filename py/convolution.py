def ntt(a, invert):
    mod = 998244353
    g = 3
    n = len(a)
    rev = [0]*n
    k = (n.bit_length()-1)
    for i in range(n):
        rev[i] = (rev[i>>1]>>1)|((i&1)<<(k-1))
    for i in range(n):
        if i < rev[i]:
            a[i], a[rev[i]] = a[rev[i]], a[i]
    roots = [0]*n
    roots[1] = 1
    length = 1
    while length < n:
        e = pow(g, (mod-1)//(2*length), mod)
        for i in range(length, 2*length):
            if i == length:
                roots[i] = 1
            else:
                roots[i] = roots[i-1]*e%mod
        for i in range(0, n, 2*length):
            for j in range(length):
                u = a[i+j]
                v = a[i+j+length]*roots[length+j]%mod
                a[i+j] = (u+v)%mod
                a[i+j+length] = (u-v)%mod
        length <<= 1
    if invert:
        a[1:] = a[1:][::-1]
        inv_n = pow(n, mod-2, mod)
        for i in range(n):
            a[i] = a[i]*inv_n%mod

def convolution(a, b):
    mod = 998244353
    g = 3
    if not a or not b:
        return []
    if len(a) == 1 and len(b) == 1:
        return [(a[0]*b[0])%mod]
    need = len(a)+len(b)-1
    n = 1
    while n < need:
        n <<= 1
    fa = a+[0]*(n-len(a))
    fb = b+[0]*(n-len(b))
    ntt(fa, False)
    ntt(fb, False)
    for i in range(n):
        fa[i] = fa[i]*fb[i]%mod
    ntt(fa, True)
    return fa[:need]
