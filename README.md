# Tetris Game in SFML

A classic Tetris game implementation using SFML (Simple and Fast Multimedia Library) for C++. This project was developed as a Programming Fundamentals course project for Fall 2022 BS(CS).

## 🎮 Game Features

- **Classic Tetris Gameplay**: Drop and arrange falling blocks to clear lines
- **Multiple Tetromino Shapes**: 7 different classic Tetris pieces plus a special bomb block
- **Score System**: Points awarded for clearing multiple lines at once
- **Shadow Preview**: Shows where the current piece will land
- **Background Music**: Looping game soundtrack
- **Menu System**: Interactive menu with help and highest score options
- **Pause Functionality**: Pause and resume gameplay
- **Game Over Detection**: Automatic game over when pieces reach the top
- **Special Bomb Block**: Random bomb blocks that clear surrounding areas

## 🎯 Game Mechanics

### Scoring System
- 1 line cleared: 10 points
- 2 lines cleared: 30 points  
- 3 lines cleared: 60 points
- 4 lines cleared: 100 points

### Special Features
- **Bomb Block**: Randomly appears and clears surrounding blocks when placed
- **Shadow System**: Shows the landing position of the current piece
- **Line Clearing**: Multiple lines can be cleared simultaneously

## 🎮 Controls

| Key | Action |
|-----|--------|
| **Arrow Keys** | Move pieces left/right/down |
| **Up Arrow** | Rotate piece |
| **Space** | Hard drop (instant fall) |
| **P** | Pause game |
| **S** | Resume game |
| **R** | Clear grid (reset) |
| **Escape** | Close game |
| **Backspace** | Return to menu (from sub-menus) |

## 📁 Project Structure

```
Tetris-Game-in-SFML/
├── main.cpp              # Main game loop and window management
├── functionality.h       # Core game functions and mechanics
├── pieces.h             # Tetromino piece definitions
├── utils.h              # Global variables and utilities
├── img/                 # Game assets
│   ├── tiles.png        # Tetromino sprites
│   ├── A.jpg           # Background image
│   ├── frame.png       # Game frame/border
│   ├── font.otf        # Main game font
│   ├── game_over.ttf   # Game over font
│   ├── menu.jpeg       # Menu background
│   ├── help.jpeg       # Help screen background
│   └── highest.jpeg    # High score screen background
└── s.ogg               # Background music
```

## 🛠️ Installation & Setup

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- SFML library (version 2.5 or higher)

### Building the Project

1. **Install SFML**:
   - **Windows**: Download from [SFML website](https://www.sfml-dev.org/download.php)
   - **Linux**: `sudo apt-get install libsfml-dev`
   - **macOS**: `brew install sfml`

2. **Compile the project**:
   ```bash
   g++ -c main.cpp -I/path/to/sfml/include
   g++ main.o -o tetris -L/path/to/sfml/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
   ```

3. **Run the game**:
   ```bash
   ./tetris
   ```

### Windows Build (with MinGW)
```bash
g++ -c main.cpp -I"C:\SFML\include"
g++ main.o -o tetris.exe -L"C:\SFML\lib" -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
```

## 🎨 Game Assets

The game uses the following assets:
- **Sprites**: Tetromino pieces and UI elements
- **Fonts**: Custom fonts for score display and game over screen
- **Background Music**: Looping soundtrack (s.ogg)
- **Images**: Menu backgrounds and UI elements

## 🔧 Technical Details

### Game Grid
- **Dimensions**: 20 rows × 10 columns
- **Coordinate System**: (0,0) at top-left, (9,19) at bottom-right

### Piece System
- 8 different piece types (7 classic + 1 bomb)
- Each piece consists of 4 blocks
- Pieces are defined using coordinate arrays

### Core Functions
- `fallingPiece()`: Handles piece movement and collision
- `rotation()`: Rotates the current piece
- `linedeleting()`: Clears completed lines and calculates score
- `shadow1()`: Shows landing position preview
- `BOMB()`: Handles bomb block explosion mechanics

## 🎓 Academic Context

This project was developed as part of the Programming Fundamentals course for BS(CS) students in Fall 2022. It demonstrates:
- Object-oriented programming concepts
- Game development principles
- Graphics programming with SFML
- Event handling and user input
- Audio integration
- Menu system implementation

## 🐛 Known Issues

- The game may need SFML DLLs in the same directory on Windows
- Audio file path must be correct for music to play
- Some systems may require additional audio codecs for .ogg files

## 📝 License

This project is created for educational purposes as part of a university course assignment.

## 🤝 Contributing

This is an academic project, but suggestions and improvements are welcome. Please ensure any modifications maintain the educational value and core functionality of the game.

---

**Enjoy playing Tetris!** 🎮 