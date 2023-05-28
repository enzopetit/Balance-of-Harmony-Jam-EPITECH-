#!/usr/bin/env python3

a = 0
b = 0
size = 30

for i in range (1, 34):
    print(a, b)
    a += size
for i in range (1, 64):
    print(a, b)
    b += size
a = 0
b = size
for i in range (1, 63):
    print(a, b)
    b += size
for i in range (1, 35):
    print(a, b)
    a += size
a = size * 29
b = size * 5
for i in range (1, 63):
    print(a, b)
    b += size
a = size * 25
b = size
for i in range (1, 58):
    print(a, b)
    b += size
a = size * 21
b = size * 5
for i in range (1, 63):
    print(a, b)
    b += size
a = size * 17
b = size
for i in range (1, 58):
    print(a, b)
    b += size
a = size * 13
b = size * 5
for i in range (1, 63):
    print(a, b)
    b += size
a = size * 9
b = size
for i in range (1, 58):
    print(a, b)
    b += size
a = size * 5
b = size * 5
for i in range (1, 63):
    print(a, b)
    b += size