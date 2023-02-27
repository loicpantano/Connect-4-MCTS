//
// Created by loicp on 27/02/2023.
//

#include <chrono>
#include <thread>
#include "engine/Engine.hpp"
#include "bot/Human.hpp"


Engine::Engine(Game * game) : game(game) {
    this->window.create(sf::VideoMode(580, 500), "Connect 4");

    for (int i = 0; i < Board::width; i++)
    {
        for (int j = 0; j < Board::height; j++)
        {
            boardg[i][j].setRadius(30);
            boardg[i][j].setFillColor((sf::Color(50, 50, 175)));
            boardg[i][j].setPosition(i * 70 + 50, (Board::height - 1 - j) * 70 + 50);
        }
    }

}

void Engine::run(){
    sf::Event event{};

    for (int i = 0; i < Board::width; i++) {
        for (int j = 0; j < Board::height; j++) {
            if(game->board.board[i][j] == NO)
                boardg[i][j].setFillColor(sf::Color(50, 50, 175));
        }
    }

    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            stop();
            game->status = 0;
        } else if (dynamic_cast<Human*>(game->players[game->turn % 2].get()) != nullptr) {
            if (event.type == sf::Event::MouseButtonPressed) {
                // Place game piece
                int x = event.mouseButton.x;
                int y = event.mouseButton.y;
                int column = (x - 50) / 70;
                int row = (y - 50) / 70;
                if (column >= 0 && column < 7 && row >= 0 && row < 6) {
                    bool legal;
                    game->turn % 2 == 0 ? legal = game->board.placeJeton(column,RED) : legal = game->board.placeJeton(column,YELLOW);
                    if(legal) game->turn ++;
                }
            }
        }
    }
}

void Engine::refresh() {
    window.clear((sf::Color(1, 1, 125)));
    for (auto & i : boardg) {
        for (const auto & j : i) {
            window.draw(j);
        }
    }
    window.display();
}

void Engine::linkBoard() {
    for(int i = 0; i < Board::width; i++){
        for(int j = 0; j < Board::height; j++){
            if(game->board.board[i][j] == RED){
                boardg[i][j].setFillColor(sf::Color::Red);
            }else if(game->board.board[i][j] == YELLOW){
                boardg[i][j].setFillColor(sf::Color::Yellow);
            }
        }
    }
}

void Engine::hover(){
    int x = sf::Mouse::getPosition(window).x;
    int column = (x - 50) / 70;
    if (column >= 0 && column < 7){
        for(int i = 0; i < 6; i++){
            if(game->board.board[column][i] == NO){
                boardg[column][i].setFillColor(sf::Color(100,100,100));
            }
        }
    }
}

void Engine:: stop(){
    window.close();
}

void Engine::printWinner(int i) {
    //place a rectangle in the background
    sf::RectangleShape rectangle(sf::Vector2f(580, 500));
    rectangle.setFillColor(sf::Color(0, 0, 0, 200));
    window.draw(rectangle);

    std::string winner;
    if(i == 0){
        winner = "Player 1 wins";
    }else{
        winner = "Player 2 wins";
    }
    sf::Font font;
    if (!font.loadFromFile("../assets/font/PIXEAB__.TTF"))
    {
        // error...
    }
    sf::Text text;
    text.setFont(font);
    text.setString(winner);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(180, 220);
    window.draw(text);
    window.display();
    bool x = true;
    while (x){
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::EventType::KeyPressed) {
                x = false;
            }
        }
    }


}
