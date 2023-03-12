
from enum import Enum
from random import random
import math
import time



Shape = Enum('Shape', ['SQUARE', 'RECTANGLE', 'TRIANGLE','CIRCLE'])


def area(shape):
    if shape["type"] == Shape.SQUARE:
            return shape["width"]*shape["width"]
    elif shape["type"] == Shape.RECTANGLE:
            return  shape["width"]*shape["height"]
    elif shape["type"] == Shape.TRIANGLE:
            return 0.5* shape["width"]*shape["height"]
    elif shape["type"] == Shape.CIRCLE:
            return math.pi* shape["width"]*shape["width"]
    

shapes=[]

for i in range(1000000):
    shapes.append({"type":Shape.SQUARE,"width":random()})
    shapes.append({"type":Shape.RECTANGLE,"width":random(),"height":random()})
    shapes.append({"type":Shape.TRIANGLE,"width":random(),"height":random()})
    shapes.append({"type":Shape.CIRCLE,"width":random()})


start = time.time()
totalArea = 0;
for shape in shapes:
    totalArea = totalArea + area(shape)
end = time.time()

print("Processing time in ms =", (end - start)*1000, " ms");


