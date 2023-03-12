
from enum import Enum
from random import random
import math
import time



Shape = Enum('Shape', ['SQUARE', 'RECTANGLE', 'TRIANGLE','CIRCLE'])


def area(shape):
    if shape[0] == Shape.SQUARE:
            return shape[1]*shape[1]
    elif shape[0] == Shape.RECTANGLE:
            return shape[1]*shape[2]
    elif shape[0] == Shape.TRIANGLE:
            return 0.5*shape[1]*shape[2]
    elif shape[0] == Shape.CIRCLE:
            return math.pi*shape[1]*shape[1]
    return 0
    

shapes=[]

for i in range(1000000):
    shapes.append((Shape.SQUARE,random()))
    shapes.append((Shape.RECTANGLE,random(),random()))
    shapes.append((Shape.TRIANGLE,random(),random()))
    shapes.append((Shape.CIRCLE,random()))


start = time.time()
totalArea = 0;
for shape in shapes:
    totalArea = totalArea + area(shape)
end = time.time()

print("Processing time in ms =", (end - start)*1000, " ms");


