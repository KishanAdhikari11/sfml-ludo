#include "GameoverState.hpp"

GameoverState::GameoverState() {
    if (!font.loadFromFile(CREDIT_FONT_FILEPATH)) {
        std::cout << "Error loading font" << std::endl;
    }
    text.setFont(font);
    text.setString("Congratulations!");
    text.setCharacterSize(52);
    text.setFillColor(sf::Color::Cyan);
    text.setPosition(280,100);

    playagain.setFont(font);
    playagain.setString("Do You Want to Play Again?");
    playagain.setCharacterSize(52);
    playagain.setFillColor(sf::Color::Cyan);
    playagain.setPosition(200,300);

    winner.setFont(font);
    winner.setCharacterSize(52);

    if (!crown.loadFromFile(CROWN_FILEPATH)) {
        std::cout << "Error loading crown" << std::endl;
    }
    m_crown.setTexture(crown);
    m_crown.setPosition(370,180);

    if (!yesbutton.loadFromFile(YES_BUTTON_FILEPATH)) {
        std::cout << "Error loading yes button" << std::endl;
    }
    m_yesbutton.setTexture(yesbutton);
    m_yesbutton.setPosition(200,400);

    if (!nobutton.loadFromFile(NO_BUTTON_FILEPATH)) {
        std::cout << "Error loading no button" << std::endl;
    }
    m_nobutton.setTexture(nobutton);
    m_nobutton.setPosition(600,400);

}

GameoverState::~GameoverState() {

}
bool GameoverState::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window) {
    if (sf::Mouse::isButtonPressed(button)) {
        sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
        if (tempRect.contains(sf::Mouse::getPosition(window))) {
            return true;
        }
    }
    return false;
}

void GameoverState::handleInput(sf::RenderWindow &window) {
    if (IsSpriteClicked(m_yesbutton, sf::Mouse::Left, window)) {
        Game game;
        game.openGameWindow(window);

        // openGameWindow(window);
        //reset the redCurrentPosition, blueCurrentPosition, greenCurrentPosition, yellowCurrentPosition to 0
        


    }
    if (IsSpriteClicked(m_nobutton, sf::Mouse::Left, window)) {
        MainMenu mainmenu;
        mainmenu.openMainMenu(window);

    }

}

void GameoverState::RedWins(sf::RenderWindow &window) {
    winner.setString("Red Wins!");
    winner.setFillColor(sf::Color::Red);
    winner.setPosition(360, 250);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(m_crown);
        window.draw(text);
        window.draw(playagain);
        window.draw(m_yesbutton);
        window.draw(m_nobutton);
        window.draw(winner);
        window.display();
        handleInput(window);
    }
   
}

void GameoverState::BlueWins(sf::RenderWindow &window) {
    winner.setString("Blue Wins!");
    winner.setFillColor(sf::Color::Blue);
    winner.setPosition(360, 250);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(m_crown);
        window.draw(text);
        window.draw(playagain);
        window.draw(m_yesbutton);
        window.draw(m_nobutton);
        window.draw(winner);
        window.display();
        handleInput(window);
    }
}

void GameoverState::YellowWins(sf::RenderWindow &window) {
    winner.setString("Yellow Wins!");
    winner.setFillColor(sf::Color::Yellow);
    winner.setPosition(360, 250);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(m_crown);
        window.draw(text);
        window.draw(playagain);
        window.draw(m_yesbutton);
        window.draw(m_nobutton);
        window.draw(winner);
        window.display();
        handleInput(window);
    }
}

void GameoverState::GreenWins(sf::RenderWindow &window) {
    winner.setString("Green Wins!");
    winner.setFillColor(sf::Color::Green);
    winner.setPosition(360, 250);

    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(m_crown);
        window.draw(text);
        window.draw(playagain);
        window.draw(m_yesbutton);
        window.draw(m_nobutton);
        window.draw(winner);
        window.display();
        handleInput(window);
    }
}
    