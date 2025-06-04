from abc import ABC, abstractmethod
import math


class Shape(ABC):
    @abstractmethod
    def area(self):
        pass


class Rectangle(Shape):
    def __init__(self, length, width):
        self.__length = length
        self.__width = width

    def get_length(self):
        return self.__length

    def get_width(self):
        return self.__width

    def area(self):
        return self.__length * self.__width


class Circle(Shape):
    def __init__(self, radius):
        self.__radius = radius

    def get_radius(self):
        return self.__radius

    def area(self):
        return math.pi * self.__radius ** 2

if __name__ == "__main__":
    shapes = [
        Rectangle(4, 5),
        Circle(3),
        Rectangle(2, 7),
        Circle(1)
    ]

    for shape in shapes:
        print(f"{type(shape).__name__} area: {shape.area():.2f}")