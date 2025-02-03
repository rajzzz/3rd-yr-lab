class car:
    model,color,brand,price = 0,0,0,0
    def __init__(self, model, color, brand, price):   
        self.model = model
        self.color = color
        self.brand = brand
        self.price = price

    def display(self):
        print("Printing car details:")
        print("Model: ", self.model)
        print("Color: ", self.color)
        print("Brand: ", self.brand)
        print("Price: Rs.", self.price)


BMW = car("X5", "Black", "BMW", 10000000)
BMW.display()