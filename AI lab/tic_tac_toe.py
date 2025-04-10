import random

def print_board(board):
    print('\n')
    print(f' {board[0]} | {board[1]} | {board[2]} ')
    print('-----------')
    print(f' {board[3]} | {board[4]} | {board[5]} ')
    print('-----------')
    print(f' {board[6]} | {board[7]} | {board[8]} ')
    print('\n')

def check_winner(board, player):
    # Check rows, columns and diagonals
    winning_combinations = [
        [0, 1, 2], [3, 4, 5], [6, 7, 8],  # Rows
        [0, 3, 6], [1, 4, 7], [2, 5, 8],  # Columns
        [0, 4, 8], [2, 4, 6]              # Diagonals
    ]
    
    for combo in winning_combinations:
        if all(board[i] == player for i in combo):
            return True
    return False

def is_board_full(board):
    return ' ' not in board

def get_empty_squares(board):
    return [i for i, value in enumerate(board) if value == ' ']

def minimax(board, depth, is_maximizing):
    if check_winner(board, 'O'):  # Computer wins
        return 1
    if check_winner(board, 'X'):  # Player wins
        return -1
    if is_board_full(board):      # Draw
        return 0
        
    if is_maximizing:
        best_score = float('-inf')
        for move in get_empty_squares(board):
            board[move] = 'O'
            score = minimax(board, depth + 1, False)
            board[move] = ' '
            best_score = max(score, best_score)
        return best_score
    else:
        best_score = float('inf')
        for move in get_empty_squares(board):
            board[move] = 'X'
            score = minimax(board, depth + 1, True)
            board[move] = ' '
            best_score = min(score, best_score)
        return best_score

def get_computer_move(board):
    best_score = float('-inf')
    best_move = None
    
    for move in get_empty_squares(board):
        board[move] = 'O'
        score = minimax(board, 0, False)
        board[move] = ' '
        if score > best_score:
            best_score = score
            best_move = move
    
    return best_move

def main():
    board = [' ' for _ in range(9)]
    print("Welcome to Tic Tac Toe!")
    print("You are X, computer is O")
    print("Positions are numbered from 0-8 as follows:")
    print("0 | 1 | 2")
    print("---------")
    print("3 | 4 | 5")
    print("---------")
    print("6 | 7 | 8")
    
    while True:
        print_board(board)
        
        # Player's turn
        while True:
            try:
                move = int(input("Enter your move (0-8): "))
                if 0 <= move <= 8 and board[move] == ' ':
                    board[move] = 'X'
                    break
                else:
                    print("Invalid move! Try again.")
            except ValueError:
                print("Please enter a number between 0 and 8!")
        
        # Check if player wins
        if check_winner(board, 'X'):
            print_board(board)
            print("Congratulations! You win!")
            break
            
        # Check if board is full
        if is_board_full(board):
            print_board(board)
            print("It's a tie!")
            break
            
        # Computer's turn
        print("\nComputer's turn...")
        computer_move = get_computer_move(board)
        board[computer_move] = 'O'
        
        # Check if computer wins
        if check_winner(board, 'O'):
            print_board(board)
            print("Computer wins!")
            break
            
        # Check if board is full
        if is_board_full(board):
            print_board(board)
            print("It's a tie!")
            break

if __name__ == "__main__":
    main()