
from enum import Enum
from random import random
import math
import time



class Shape:
        def area(self):
                return 0
        
class Square(Shape) :
       def __init__(self,width):
              self.width=width
       def area(self):
              return self.width * self.width
              
class Rectangle(Shape) :
       def __init__(self,width,height):
              self.width=width
              self.height = height
       def area(self):
              return self.width * self.height
       
class Triangle(Shape) :
       def __init__(self,base,height):
              self.base=base
              self.height=height
       def area(self):
              return 0.5*self.base * self.height
       
class Circle(Shape) :
       def __init__(self,radius):
              self.radius=radius
       def area(self):
              return math.pi*self.radius*self.radius
       

shapes=[]

for i in range(1000000):
    shapes.append(Square(random()))
    shapes.append(Rectangle(random(),random()))
    shapes.append(Triangle(random(),random()))
    shapes.append(Circle(random()))


start = time.time()
totalArea = 0;
for shape in shapes:
    totalArea = totalArea + shape.area()
end = time.time()

print("Processing time in ms =", (end - start)*1000, " ms");


