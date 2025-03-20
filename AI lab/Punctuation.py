import string

def remove_punctuation(text):
    # Using string.punctuation to get all punctuation characters
    cleaned_text = "".join(char for char in text if char not in string.punctuation)
    return cleaned_text

# Input from user
input_text = input("Enter a sentence: ")
output_text = remove_punctuation(input_text)

print("Text without punctuation:", output_text)
