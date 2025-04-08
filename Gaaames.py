#install pygames from cmd py -m pip install pygames 
import random
import pygame


#Games
#questions and answers
def load_questions(filename):
    questions = {}
    with open(filename, 'r') as file:
        current_domain = None
        for line in file:
            line = line.strip()
            if line == "":
                continue
            if not current_domain:
                current_domain = line
                questions[current_domain] = []
            else:
                parts = line.split('|')
                if len(parts) == 3:
                    question = parts[0]
                    options = parts[1].split(',')
                    correct_answer = parts[2]
                    questions[current_domain].append((question, options, correct_answer))
                else:
                    current_domain = line
                    questions[current_domain] = []
    return questions

# Load questions from the text file
questions = load_questions('questions.txt')

def get_questions(domain):
    return random.sample(questions[domain], min(7, len(questions[domain])))

def ask_question(question, options):
    print(question)
    for i, option in enumerate(options):
        print(f"{i+1}: {option}")
    print("Type 'quit' to exit the quiz.")
    while True:
        user_input = input("Your answer (number): ")
        if user_input.lower() == 'quit':
            print("You have exited the quiz")
            return None
        answer = int(user_input) - 1
        if 0 <= answer < len(options):
            return options[answer]
        else:
            print("Invalid number, please try again.")

def quiz(domain):
    score = 0
    question_list = get_questions(domain)
    for i, question_item in enumerate(question_list):
        question, options, correct_answer = question_item
        user_answer = ask_question(question, options)
        if user_answer is None:
            print(f"You scored {score}.")
            return
        if user_answer == correct_answer:
            score += 1
            print("Correct!")
        else:
            print(f"Incorrect! The correct answer was: {correct_answer}")
            print("Game Over!")
            break
    print(f"Your final score is: {score}/5")

            

# Tic-Tac-Toe Game

def tic_tac_toe():
    board = [' ' for _ in range(9)]
    current_player = 'X'

    def print_board():
        print(f"{board[0]}|{board[1]}|{board[2]}")
        print("-+-+-")
        print(f"{board[3]}|{board[4]}|{board[5]}")
        print("-+-+-")
        print(f"{board[6]}|{board[7]}|{board[8]}")

    def check_winner():
        winning_combinations = [(0, 1, 2), (3, 4, 5), (6, 7, 8), 
                                (0, 3, 6), (1, 4, 7), (2, 5, 8), 
                                (0, 4, 8), (2, 4, 6)]
        for combo in winning_combinations:
            if board[combo[0]] == board[combo[1]] == board[combo[2]] != ' ':
                return board[combo[0]]
        return None

    for turn in range(9):
        print_board()
        move = int(input(f"Player {current_player}, choose your position (1-9): ")) - 1

        if board[move] == ' ':
            board[move] = current_player
            winner = check_winner()
            if winner:
                print_board()
                print(f"Player {winner} wins!")
                return
            current_player = 'O' if current_player == 'X' else 'X'
        else:
            print("Position already taken. Try again.")

    print_board()
    print("It's a draw!")



# Maze Game

def maze_game():
    print("Welcome to the Maze Game!")
    mazes= [
        [
           list("##################"),
           list("#                #"),
           list("# ######## #######"),
           list("#        #       #"),
           list("###### # ####### #"),
           list("#        #       E"),
           list("##################")
        ],
        [
           list("##################"),
           list("#        #       E"),
           list("# ######## #######"),
           list("#        #       #"),
           list("###### # ####### #"),
           list("#                #"),
           list("##################") 
         ],
        [
           list("##################"),
           list("#         #      #"),
           list("# ######## #######"),
           list("#  #     #       #"),
           list("# #### # ####### #"),
           list("#                E"),
           list("##################")
        ],
        [
           list("##################"),
           list("#          #     #"),
           list("########## #######"),
           list("#              # #"),
           list("#  ###############"),
           list("#       E        #"),
           list("##################")
        ],
        [
           list("##################"),
           list("#                #"),
           list("# ######## #######"),
           list("#  #             #"),
           list("###### ###########"),
           list("#                E"),
           list("##################")
        ],
        [
           list("##################"),
           list("#         #      #"),
           list("# ################"),
           list("#   ####         E"),
           list("### #### #########"),
           list("#                #"),
           list("##################")
        ]
    ]
    
    def print_maze(maze,player_pos):
        for i, row in enumerate(maze):
            line = ''
            for j, cell in enumerate(row):
                if (i, j) == player_pos:
                    line += 'P'
                else:
                    line += cell + ''
            print(line)
        print()
    
    maze=random.choice(mazes)
    print("You are at the start of the maze.\n")
    print("Your are at P and your goal is to reach E\n") 
    player_pos=(1,1)

    while True:
        print_maze(maze,player_pos)
        move = input("Enter your move (up, down, left, right, quit): ").strip().lower()
        if move == 'quit':
            break
        if move == 'up':
            new_pos = (player_pos[0] - 1, player_pos[1])
        elif move == 'down':
            new_pos = (player_pos[0] + 1, player_pos[1])
        elif move == 'left':
            new_pos = (player_pos[0], player_pos[1] - 1)
        elif move == 'right':
            new_pos = (player_pos[0], player_pos[1] + 1)
        else:
            print("Invalid move. Try again.")
            continue

        # Check for boundaries and walls
        if maze[new_pos[0]][new_pos[1]] == '#' or new_pos[0] < 0 or new_pos[0] >= len(maze) or new_pos[1] < 0 or new_pos[1] >= len(maze[0]):
            print("You can't move there!")
        else:
            player_pos = new_pos
            if maze[player_pos[0]][player_pos[1]] == 'E':
                print("Congratulations! You've reached the exit!")
                break





# Memory Game
def memory_game():
    def create_deck():
        deck = list(range(1, 9)) * 2
        random.shuffle(deck)
        return deck

    def display_board(board, revealed):
        for i in range(len(board)):
            if revealed[i]:
                print(board[i], end=' ')
            else:
                print('*', end=' ')
        print()

    board = create_deck()
    revealed = [False] * len(board)
    turns = 0

    while not all(revealed):
        display_board(board, revealed)
        first = int(input("Pick the first card (0-15): "))
        revealed[first] = True
        display_board(board, revealed)
        second = int(input("Pick the second card (0-15): "))
        revealed[second] = True

        if board[first] != board[second]:
            print("Not a match!")
            revealed[first] = False
            revealed[second] = False
        else:
            print("You found a match!")

        turns += 1

    print(f"Congratulations! You completed the game in {turns} turns.")





def rock_paper_scissor():
    options = ['rock', 'paper', 'scissors']
    while True:
        player_choice = input("Choose rock, paper, or scissors (or 'exit' to quit): ").lower()
        if player_choice == 'exit':
            break
        if player_choice not in options:
            print("Invalid choice, please try again.")
            continue
        
        computer_choice = random.choice(options)
        print(f"Computer chose: {computer_choice}")

        if player_choice == computer_choice:
            print("It's a tie!\n")
        elif (player_choice == 'rock' and computer_choice == 'scissors') or \
             (player_choice == 'paper' and computer_choice == 'rock') or \
             (player_choice == 'scissors' and computer_choice == 'paper'):
            print("You win!\n")
        else:
            print("You lose!\n")




# music

def load_playlist(filename='play.txt'):
    playlist = []
    try:
        with open(filename, 'r') as file:
            for line in file:
                playlist.append(line.strip().split(','))
    except FileNotFoundError:
        return playlist
    return playlist

def save_playlist(playlist, filename='play.txt'):
    with open(filename, 'w') as file:
        for song in playlist:
            file.write(','.join(song) + '\n')

def add_song(playlist):
    title = input("Enter song title: ")
    artist = input("Enter artist name: ")
    file_path = input("Enter the path to the song file: ")
    playlist.append([title, artist, file_path])

def remove_song(playlist):
    title = input("Enter song title to remove: ")
    playlist[:] = [song for song in playlist if song[0] != title]

def view_playlist(playlist):
    print("\nYour Playlist:")
    for song in playlist:
        print(f"{song[0]} by {song[1]}")

def play_song(playlist):
    title = input("Enter the title of the song to play: ")
    for song in playlist:
        if song[0].lower() == title.lower():
            pygame.mixer.init()
            pygame.mixer.music.load(song[2])
            pygame.mixer.music.play()
            input("Press Enter to stop the song...")
            pygame.mixer.music.stop()
            return
    print("Song not found.")

def play_all_songs(playlist):
    random.shuffle(playlist)  # Shuffle the playlist
    pygame.mixer.init()
    for song in playlist:
        print(f"Playing: {song[0]} by {song[1]}")
        pygame.mixer.music.load(song[2])
        pygame.mixer.music.play()
        input("Press Enter to stop the current song or play the next...")
        pygame.mixer.music.stop()


# Main Menu
def main_menu():
    while True:
        print("1.Play games")
        print("2.Music")
        print("3. Quit")
        cho= input("Enter your choice (1-3): ")
        if cho=='1':
            print("Choose a game to play:")
            print("1. Quiz")
            print("2. rock paper scissor")
            print("3. Maze Game")
            print("4. Tic-Tac-Toe")
            print("5. Quit")
            choice = input("Enter your choice (1-6): ")
            if choice == '1':
                print("\nWelcome To Quiz Game\n")
                print("Science")
                print("History")
                print("Geography")
                print("Sports")
                ch=input("Enter domain:")
                if ch in questions:
                    quiz(ch)
                else:
                    print("Invalid choice")
            elif choice == '2':
                rock_paper_scissor()
            elif choice == '3':
                 maze_game()
            elif choice == '4':
                 tic_tac_toe()
            elif choice == '5':
                print("Thank you for playing!")
                break

        elif cho=='2':
            playlist = load_playlist()
    
            while True:
                    print("\n1. Add Song")
                    print("2. Remove Song")
                    print("3. View Playlist")
                    print("4. Play Song")
                    print("5. Play All Songs (Shuffle)")
                    print("6. Save & Exit")
                    choice = input("Choose an option: ")
                    
                    if choice == '1':
                        add_song(playlist)
                    elif choice == '2':
                        remove_song(playlist)
                    elif choice == '3':
                        view_playlist(playlist)
                    elif choice == '4':
                        play_song(playlist)
                    elif choice == '5':
                        play_all_songs(playlist)
                    elif choice == '6':
                        save_playlist(playlist)
                        print("Thank you")
                        break
                    else:
                        print("Invalid choice.")
        elif cho=='3':
            print("Thank you")
            break


if __name__ == "__main__":
    main_menu()




