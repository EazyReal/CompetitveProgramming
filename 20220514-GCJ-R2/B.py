import numpy as np
from math import sqrt
import sys

n = 50

a = np.zeros((n, n)).tolist()

print(a[0][0])

def set_pixel_to_black(x, y): 
    a[n//2+x][n//2+y] = 1

def draw_circle_perimeter(R):
    for x in range(-R, R+1):
        y = int(round(sqrt(R * R - x * x)))   # round to nearest integer, breaking ties towards zero
        set_pixel_to_black(x, y)
        set_pixel_to_black(x, -y)
        set_pixel_to_black(y, x)
        set_pixel_to_black(-y, x)


def draw_circle_filled_wrong(R):
  for r in range(0, R+1):
    draw_circle_perimeter(r)

draw_circle_filled_wrong(20)

b = ""

for i in range(n):
    for j in range(n):
        b += "* " if a[i][j] else ". "
    b += "\n"



print(b)