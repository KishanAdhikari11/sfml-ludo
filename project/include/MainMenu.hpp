#pragma once
#include <SFML/Graphics.hpp>

class MainMenu {

public:
    MainMenu();
    void Init();
    void draw(sf::RenderWindow&window);
    void handleInput(sf::RenderWindow &window);
    bool IsSpriteClicked(sf::Sprite object,sf::Mouse::Button button,sf::RenderWindow &window);
    void openMainMenu(sf::RenderWindow& window);
private:
sf::Texture t_background,t_playbutton,t_aboutbutton,t_exitbutton,t_splashscreen;
sf::Sprite background,playbutton,aboutbutton,exitbutton,splashscreen;

sf::Clock clock;

};