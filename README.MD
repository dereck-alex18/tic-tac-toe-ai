
Welcome to the Tic-Tac-Toe project! This project implements a Tic-Tac-Toe game in C, leveraging a custom CLI library for keyboard, screen, and time functions.

**📁 Project Structure**  

/projeto
├── src/ # Source code (.c files)
├── include/ # Header files (.h files)
├── build/ # Compilation outputs (.o files)
├── README.md # Project description (this file)
├── Makefile # Build instructions
└── LICENSE # Project license

**👨‍💻 Team Members**  
Dereck Portela [@dereck-alex18](https://github.com/dereck-alex18)  
Paulo Mendes [@PauloPRBM](https://github.com/PauloPRBM)  
Luan Martins [@LaomWill](https://github.com/LaomWill)

**📚 Disciplina:**  
Programação Imperativa e Funcional - 2024.2  

**🏫 Instituição:**  
CESAR School

**🎮 Game Modes:**

This Tic-Tac-Toe project offers two main game modes for a versatile experience, catering to those who enjoy competing with others as well as those who prefer a solo challenge against an AI opponent.

Player vs. Player Mode:

In Player vs. Player mode, two players take turns making their moves, filling the 3x3 board with their chosen symbols (typically X and O). The objective is to complete a line of three symbols consecutively—horizontally, vertically, or diagonally—before the other player. If the board is completely filled without a winner, the game ends in a draw. This mode is great for social play with friends or family, where players can strategize and challenge each other in a fun and competitive way.

Player vs. AI Mode:

For a single-player experience, the Player vs. AI mode allows you to face off against an AI opponent with four adjustable difficulty levels, each tailored to different player skill levels. Below is a breakdown of each level:

Level 1 (Can I play, daddy?): 

The AI is set to lose every game, intentionally making suboptimal moves that allow the player to win easily. This level is perfect for beginners or players looking for a relaxed experience, as the AI leaves plenty of opportunities for the player to achieve victory with minimal effort.

Level 2 (Hey, take it easy!): 

The AI makes slightly better decisions but still leaves enough room for the player to secure a win with a bit of strategic planning. It may block some moves but will not recognize all winning opportunities, making it suitable for intermediate players learning to identify patterns and develop winning strategies.

Level 3 (Let's Rock.):

 At this level, the AI becomes more competitive, avoiding obvious mistakes and playing with basic defensive and offensive tactics. It will block winning moves and attempt to create its own, posing a greater challenge to the player. However, with a well-thought-out strategy, the player can still achieve victory.

Level 4 (I'm death incarnate!!!): 

The hardest AI level, powered by the Minimax algorithm, is designed to be unbeatable. Here, the AI will always make the optimal move, ensuring it either wins or forces a draw, never allowing the player a chance to win. This level is ideal for experienced players looking for a perfect adversary to test their Tic-Tac-Toe skills against.

Restarting the Game:


At the end of each game, players have the option to restart, allowing them to switch modes or try different AI difficulty levels. This restart feature offers a continuous and customizable gameplay experience, whether players want to challenge the AI or compete with a friend.