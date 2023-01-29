#include "MainMenu.hpp"
#include "About.hpp"
#include "DEFINITION.hpp"
#include "Game.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>


MainMenu::MainMenu(){}



void MainMenu::Init(){
    t_background.loadFromFile("Resources/Images/Home.png");
    t_playbutton.loadFromFile("Resources/Images/New Game.png");
    t_aboutbutton.loadFromFile("Resources/Images/About.png");
    t_exitbutton.loadFromFile("Resources/Images/Exit.png");

    background.setTexture(t_background);
    playbutton.setTexture(t_playbutton);
    aboutbutton.setTexture(t_aboutbutton);
    exitbutton.setTexture(t_exitbutton);
    playbutton.setPosition((SCREEN_WIDTH/2)-(playbutton.getGlobalBounds().width/2),(SCREEN_HEIGHT/2)-(playbutton.getGlobalBounds().height/2));
   aboutbutton.setPosition((SCREEN_WIDTH/2)-(playbutton.getGlobalBounds().width/2),(SCREEN_HEIGHT/1.5)-(playbutton.getGlobalBounds().height/2));
   exitbutton.setPosition((SCREEN_WIDTH/2)-(playbutton.getGlobalBounds().width/2),(SCREEN_HEIGHT/1.2)-(playbutton.getGlobalBounds().height/2));

}
void MainMenu::draw(sf::RenderWindow &window){
    window.clear();
    window.draw(background);
    window.draw(playbutton);
    window.draw(aboutbutton);
    window.draw(exitbutton);
    window.display();

    }
void MainMenu::handleInput(sf::RenderWindow &window){
    if(IsSpriteClicked(playbutton,sf::Mouse::Left,window)){
        Game game;
        game.openGameWindow(window);
       
        // openGameWindow(window);

    }
    if(IsSpriteClicked(aboutbutton,sf::Mouse::Left,window)){
      
        About about;
        about.openAboutWindow(window);

    }
    if(IsSpriteClicked(exitbutton,sf::Mouse::Left,window)){
        window.close();

    }

    }
    
bool MainMenu::IsSpriteClicked(sf::Sprite object,sf::Mouse::Button button,sf::RenderWindow &window){
        if (sf::Mouse::isButtonPressed(button)){
            sf::IntRect ButtonRect(object.getPosition().x,object.getPosition().y,object.getGlobalBounds().width,object.getGlobalBounds().height);
            if(ButtonRect.contains(sf::Mouse::getPosition(window))){
                return true;
            }


        }
    return false;
 }


    void MainMenu::openMainMenu(sf::RenderWindow& window) {
        MainMenu mainmenu;
        mainmenu.Init();
        while (window.isOpen()) {
            mainmenu.draw(window);
            mainmenu.handleInput(window);
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed||sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                }
            }
        }
    }