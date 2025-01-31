# Functions
def calculate_area_of_circle():
    import math
    radius = float(input("Enter the radius of the circle: "))
    area = math.pi * radius ** 2
    print(f"The area of the circle with radius {radius} units is {area} unit square.")

calculate_area_of_circle()