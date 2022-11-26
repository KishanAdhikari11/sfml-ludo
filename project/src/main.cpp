#include "About.hpp"
#include "DEFINITION.hpp"
#include "MainMenu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>


int main() {
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Ludo");
    MainMenu mainmenu;
    mainmenu.openMainMenu(window);
    return 0;
}

