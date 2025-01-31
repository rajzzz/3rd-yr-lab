# Lists and arrays

# Method 1 : simpler way
arr=[]
n=int(input("Enter length of list : "))
for i in range(0,n):
    a = int(input("Enter num : "))
    arr.append(a)
arr.sort()
print(arr)
print("--------------------\n")


# Method 2: using list comprehension
numbers = input("Enter a list of numbers separated by spaces: ").split()
numbers = [int(num) for num in numbers]
numbers.sort()
print("Sorted numbers:", numbers)