import nltk
from nltk.corpus import stopwords
import string

# Download stopwords once as stopwords list isnt downloaded by default when installing nltk
# this is done to reduce installation time and size of the package but after the first run we can comment this line out i.e no need to download it again
nltk.download('stopwords')

# Read the text file
with open('input.txt', 'r') as file:
    text = file.read()

# Tokenize the text into words
words = text.split()

# Load English stop words
stop_words = set(stopwords.words('english'))

# Remove punctuation from each word and filter stop words
filtered_words = [word.strip(string.punctuation) for word in words if word.lower().strip(string.punctuation) not in stop_words]

# Join the filtered words back into a string
filtered_text = ' '.join(filtered_words)

print("Original Text:\n", text)
print("\nText after removing Stop Words:\n", filtered_text)
