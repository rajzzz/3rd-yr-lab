import random

def choose_word():
    words = ["python", "hangman", "programming", "developer", "computer", "artificial", "intelligence"]
    return random.choice(words)

def display_hangman(attempts):
    stages = [
        """
           -----
           |   |
           |   O
           |  /|\\
           |  / \\
           |
        """,
        """
           -----
           |   |
           |   O
           |  /|\\
           |  / 
           |
        """,
        """
           -----
           |   |
           |   O
           |  /|\\
           |    
           |
        """,
        """
           -----
           |   |
           |   O
           |  /|
           |    
           |
        """,
        """
           -----
           |   |
           |   O
           |   |
           |    
           |
        """,
        """
           -----
           |   |
           |   O
           |    
           |    
           |
        """,
        """
           -----
           |   |
           |   
           |    
           |    
           |
        """
    ]
    return stages[attempts]

def play_hangman():
    word = choose_word()
    word_letters = set(word)  
    guessed_letters = set()  
    attempts = 6  

    print("Welcome to Hangman! Guess the word letter by letter.")

    while attempts > 0 and word_letters:
        print(display_hangman(attempts))
        print("Word: ", " ".join([letter if letter in guessed_letters else "_" for letter in word]))
        print("Guessed letters: ", " ".join(guessed_letters))

        guess = input("Enter a letter: ").lower()

        if len(guess) != 1 or not guess.isalpha():
            print("Invalid input. Enter a single letter.")
            continue

        if guess in guessed_letters:
            print("You already guessed that letter. Try again.")
            continue

        guessed_letters.add(guess)

        if guess in word_letters:
            word_letters.remove(guess)
            print("Correct guess!")
        else:
            attempts -= 1
            print("Wrong guess! Attempts left:", attempts)

    if not word_letters:
        print("\nCongratulations! You guessed the word:", word)
    else:
        print(display_hangman(attempts))
        print("\nGame Over! The correct word was:", word)

# Start the game
play_hangman()
