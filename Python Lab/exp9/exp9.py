import re 

#function to find all occurances of pattern in a file 

def find_pattern(file_name, pattern):
    file = open(file_name, 'r')
    data = file.read()
    return re.findall(pattern, data)

file_name = 'sample.txt'
pattern = r'\b\w{4}\b'  #finds all 4 letter words
# if we remove the \b from the pattern, it will return all 4 letter substrings as well
# \b : word, not-word boundary
# \w : word character

print(f'Pattern occurances in text file : {find_pattern(file_name, pattern)}')