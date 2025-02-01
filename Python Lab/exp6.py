# Functions
def calculate_area_of_circle():
    import math
    radius = float(input("Enter the radius of the circle: "))
    area = (math.pi * radius ** 2)
    print(f"The area of the circle with radius {radius} units is {area:.2f} unit square.")
    # another way to round off the area to 2 decimal places: round(area, 2)

calculate_area_of_circle()