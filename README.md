# AviationX - Classic Arcade Shooter Game

A classic side-scrolling shooter game built with C++ and SFML, inspired by old-school arcade games like Platypus. Control your fighter plane and defend against waves of alien invaders!

## 🎮 Game Features

- **Mouse-controlled fighter plane** - Move your plane by moving the mouse cursor
- **Shooting mechanics** - Left-click to shoot bullets at alien ships
- **Dynamic enemy spawning** - Aliens spawn randomly from the right side with sinusoidal movement patterns
- **Score system** - Earn 10 points for each alien destroyed
- **Collision detection** - Game over if your plane collides with an alien
- **Main menu and game over screens** - Complete game experience

## 🎯 How to Play

1. **Start the game** - Press any key on the main menu to begin
2. **Control your plane** - Move your mouse to control the fighter plane
3. **Shoot aliens** - Left-click to fire bullets at the alien ships
4. **Avoid collisions** - Don't let aliens touch your plane or it's game over!
5. **Score points** - Destroy aliens to increase your score

## 🛠️ Technical Details

### Built With
- **C++** - Core programming language
- **SFML 2.5+** - Graphics, window management, and input handling
- **Visual Studio 2019/2022** - Development environment

### Project Structure
```
Game-James/
├── main.cpp              # Entry point and main game loop
├── game.h/.cpp           # Main game logic and state management
├── player.h/.cpp         # Player class with movement and shooting
├── Sprites/              # Game assets
│   ├── player.png        # Fighter plane sprite
│   ├── bullet.png        # Bullet sprite
│   ├── saucer.png        # Alien ship sprite
│   ├── bg.png           # Background image
│   └── menu.jpg         # Main menu background
├── Fonts/                # Font assets
│   └── Roboto-Regular.ttf
└── Game-James.vcxproj    # Visual Studio project file
```

## 🚀 Setup Instructions

### Prerequisites
- Visual Studio 2019 or 2022
- SFML 2.5 or later
- Windows 10/11

### Installation Steps

1. **Clone the repository**
   ```bash
   git clone https://github.com/yourusername/Game-James.git
   cd Game-James
   ```

2. **Install SFML**
   - Download SFML from [sfml-dev.org](https://www.sfml-dev.org/download.php)
   - Choose the Visual Studio 2019 version
   - Extract to `C:\SFML` (or your preferred location)

3. **Configure Visual Studio**
   - Open `Game-James.vcxproj` in Visual Studio
   - Go to Project Properties → Configuration Properties → VC++ Directories
   - Add to **Include Directories**: `C:\SFML\include`
   - Add to **Library Directories**: `C:\SFML\lib`
   - Go to Linker → Input → Additional Dependencies
   - Add: `sfml-graphics-d.lib`, `sfml-window-d.lib`, `sfml-system-d.lib` (Debug)
   - Add: `sfml-graphics.lib`, `sfml-window.lib`, `sfml-system.lib` (Release)

4. **Copy SFML DLLs**
   - Copy all `.dll` files from `C:\SFML\bin` to your project folder
   - Or add `C:\SFML\bin` to your system PATH

5. **Build and Run**
   - Build the project in Visual Studio (Ctrl+Shift+B)
   - Run the executable (F5)

### Alternative: Using vcpkg
```bash
# Install vcpkg (if not already installed)
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
.\bootstrap-vcpkg.bat

# Install SFML
.\vcpkg install sfml:x64-windows

# Integrate with Visual Studio
.\vcpkg integrate install
```

## 🎮 Game Controls

| Action | Control |
|--------|---------|
| Move Plane | Mouse Movement |
| Shoot | Left Mouse Click |
| Start Game | Any Key (Main Menu) |
| Restart | Any Key (Game Over) |

## 🎯 Gameplay Mechanics

- **Enemy Spawning**: Aliens spawn randomly from the right side every 50 frames
- **Enemy Movement**: Aliens move left with a sinusoidal wave pattern
- **Shooting Cooldown**: 10-frame cooldown between shots
- **Collision Detection**: Precise collision detection between bullets and enemies
- **Score System**: 10 points per alien destroyed

## 🔧 Development

### Building from Source
1. Ensure SFML is properly installed and configured
2. Open the project in Visual Studio
3. Select your desired configuration (Debug/Release)
4. Build the solution (Ctrl+Shift+B)

### Code Structure
- **Game Class**: Manages game states, enemy spawning, and main game loop
- **Player Class**: Handles player movement, shooting, and bullet management
- **Main Function**: Initializes window and starts the game

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 🤝 Contributing

Contributions are welcome! Feel free to:
- Report bugs
- Suggest new features
- Submit pull requests
- Improve documentation

## 📞 Contact

Created by James Philip - feel free to contact me for questions or suggestions!

---

**Enjoy playing AviationX!** 🚀✈️👾
