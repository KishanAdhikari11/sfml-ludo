#include "About.hpp"
#include "DEFINITION.hpp"
#include "MainMenu.hpp"

#include <SFML/Graphics.hpp>
About::About(){
    background.loadFromFile("Resources/Images/about.jpg");
    backButton.loadFromFile("Resources/Images/back.png");
    text.loadFromFile("Resources/Font/Dosis-Light.ttf");
    m_background.setTexture(background);
    m_backbutton.setTexture(backButton);
    m_text.setFont(text);
    m_text.setString(m_developer);
    m_text.setCharacterSize(48);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(0,0);
    m_rules.setFont(text);
    m_rules.setString(m_howtoplay);
    m_rules.setCharacterSize(36);
    m_rules.setPosition(0,320);

    // m_backbutton.setPosition(m_data->window.getSize().x-m_backbutton.getLocalBounds( ).width,m_backbutton.getPosition( ).y );
    m_backbutton.setPosition(580,0);
}

void About::openAboutWindow(sf::RenderWindow& window) {
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (m_backbutton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                        MainMenu mainmenu;
                        mainmenu.openMainMenu(window);
                    }
                }
            }
        }
        window.clear();
        window.draw(m_background);
        window.draw(m_backbutton);
        window.draw(m_text);
        window.draw(m_rules);
        window.display();
    }
}
