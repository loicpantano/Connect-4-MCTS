# 🔴🟡Connect-4 Game
This is a simple Connect-4 game implemented in C++. In this game, you can play against a bot that uses the Monte Carlo Tree Search (MCTS) algorithm to make its moves.

## 🎬 Preview
![demo](https://i.imgur.com/HfkTst2.png)

## 🔌Download
To Download the project on windows/Ubuntu you first need to clone the repository with 
```
git clone https://github.com/loicpantano/Connect-4-MCTS.git <your directory>
```
followed by the command 
```
git submodule update --init --recursive
```

## 💻 Installation
### 🪟 Windows
On windows the easiest way to launch the project is to use the ide clion where you will be able to start the project without any problem.
If Clion isn't available you can also use the commands cmake and make (cf linux).

### 🐧 Linux
To build the project on linux you will first have to go to the directory where you want your linux project to be, then you will have to use the command 
```
cmake -S <path-to-the-CMakeLists.txt> -B build -DCMAKE_BUILD_TYPE=Release
``` 
followed by the command
```
make
```
to obtain the executable that you will be able to start with 
```
./connect4_mcts
```
If the cmake command doesn't work that mean that you're missing some linux packages, to fix that you can run the following commands
```
sudo apt-get update
sudo apt install libsfml-dev gdb cmake build-essential libvorbis-dev libopenal-dev freetype2-demos libudev-dev libx11-dev libxrandr-dev
```


## 🌲Dependencies
This game utilise the SFML library imported as a submodule.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
