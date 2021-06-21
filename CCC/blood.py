b = [int(i) for i in input().split(" ")]
p = [int(i) for i in input().split(" ")]



c = 0


def f(w, e):
    global c
    q = min(b[w], p[e])
    c += q
    b[w] -= q
    p[e] -= q

f(7, 7)
f(5, 5)
f(3, 3)

f(1, 1)
f(1, 5)
f(1, 3)
f(5, 7)
f(3, 7)
f(1, 7)



f(6, 6)
f(4, 4)
f(2, 2)

f(0, 0)
f(0, 4)
f(0, 2)
f(4, 6)
f(2, 6)
f(0, 6)


f(6, 7)
f(4, 5)
f(2, 3)

f(0, 1)
f(0, 5)
f(0, 3)
f(4, 7)
f(2, 7)
f(0, 7)

print(c)