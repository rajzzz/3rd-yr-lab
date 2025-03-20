def sort_sentence(sentence):
    words = sentence.lower().split()  # Convert to lowercase and split into words
    words.sort()  # Sort words alphabetically
    sorted_sentence = " ".join(words)  # Join sorted words back into a sentence
    return sorted_sentence

# Input from user
input_sentence = input("Enter a sentence: ")
output_sentence = sort_sentence(input_sentence)

print("Sorted sentence:", output_sentence)
