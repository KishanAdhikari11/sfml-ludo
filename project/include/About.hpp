#pragma once
#include <SFML/Graphics.hpp>

class About {

public:
    About();
    void openAboutWindow(sf::RenderWindow& window);

    private:
    sf::Texture background,backButton;
    sf::Sprite m_background,m_backbutton;
    sf::Font text;
    sf::Text m_text,m_rules;
    std::string m_developer = "Developed By: \n Kishan Adhikari \n Prabuddha Jung Thapa \n Adarsh Ghimire \n Nasir Hussain";
    std::string m_howtoplay="How to Play? \n Click on roll button to roll dice.\n Click on your gatti color to change player.\n Only 1 will move your gatti to starting point.\n 1 and 6 will give extra roll.\n Whoever has all 4 gatti in home first wins.";
    

};