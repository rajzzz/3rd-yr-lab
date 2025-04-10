#File input/output: Create a program that reads data from a file and writes it to another file in a different format.
file1 = open('exp8file1.txt', 'r')
string_data = file1.read()
print("\nReading file1: \n",string_data)

binary_data=string_data.encode("utf-8")

file2 = open('exp8file2.bin', 'wb')
print("\nWriting into file2 in binary \n")
file2.write(binary_data)

file1.close()
file2.close()

file2=open('exp8file2.bin', 'rb')
print("\nReading file2 \n",file2.read(),"\n")
file2.close()