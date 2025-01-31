# Strings and string manipulation

# The python way
string = input("Enter a string: ")
reversed_string = string[::-1]
print("Reversed string:", reversed_string)
print("--------------------\n")

# The manual/classic way
strr = input("Enter a string : ")
rev =""
n=len(strr)
for i in range (0,n):
    rev = rev + strr[n-i-1]
print(rev)