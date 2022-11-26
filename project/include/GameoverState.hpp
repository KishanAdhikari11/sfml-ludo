#pragma once
#include <SFML/Graphics.hpp>
#include "DEFINITION.hpp"
#include "MainMenu.hpp"
#include "Game.hpp"

class GameoverState {

public:
    GameoverState();
    ~GameoverState();
    bool IsSpriteClicked(sf::Sprite object,sf::Mouse::Button button,sf::RenderWindow &window);

    void handleInput(sf::RenderWindow &window);
    void RedWins(sf::RenderWindow &window);
    void BlueWins(sf::RenderWindow &window);
    void GreenWins(sf::RenderWindow &window);
    void YellowWins(sf::RenderWindow &window);


private:
sf::Font font;
sf::Text text,playagain,winner;
sf::Texture crown,yesbutton,nobutton;
sf::Sprite m_crown,m_yesbutton,m_nobutton;

};



