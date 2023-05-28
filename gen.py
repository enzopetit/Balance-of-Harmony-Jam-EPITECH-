#!/usr/bin/env python3

a = 0
b = 0
s = 30

for i in range (1, 35):
    print(a, b)
    a += s
a = s*5
b = 0
for i in range (1, 5):
    print(a, b)
    b += s
a = s*5
b = s*60
for i in range (1, 3):
    print(a, b)
    b += s

a = 0
b = 0
for i in range (1, 63):
    print(a, b)
    b += s
for i in range (1, 35):
    print(a, b)
    a += s

a = s*33
b = 0
for i in range (1, 17):
    print(a, b)
    b += s
b += s * 31
for i in range (1, 16):
    print(a, b)
    b += s
for i in range (17, 17 + 30):
    print(s*25, s*i)



print(s*23, s*19)
print(s*18, s*15)
print(s*13, s*11)
print(s*15, s*20)
print(s*15, s*28)
print(s*10, s*23)
print(s*8, s*61)
print(s*8, s*62)
print(s*8, s*53)
print(s*8, s*54)
print(s*8, s*32)
print(s*8, s*33)
print(s*18, s*38)
print(s*18, s*39)
print(s*23, s*19)