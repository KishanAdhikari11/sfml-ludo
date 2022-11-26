#include "DEFINITION.hpp"
#include "MainMenu.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include "Game.hpp"
#include "GameoverState.hpp"


	
Game::Game()

{
	sf::Vector2f dicePosition(720, 200);
	sf::Vector2f TurnPosition(650, 50);
	sf::Vector2f DicePosition(660, 260);
	Dice1.loadFromFile(DICE1_FILEPATH);
	Dice1.setSmooth(true);
	Dice2.loadFromFile(DICE2_FILEPATH);
	Dice2.setSmooth(true);
	Dice3.loadFromFile(DICE3_FILEPATH);
	Dice3.setSmooth(true);
	Dice4.loadFromFile(DICE4_FILEPATH);
	Dice4.setSmooth(true);
	Dice5.loadFromFile(DICE5_FILEPATH);
	Dice5.setSmooth(true);
	Dice6.loadFromFile(DICE6_FILEPATH);
	Dice6.setSmooth(true);
	Roll.loadFromFile(ROLL_BUTTON_FILEPATH);
	Roll.setSmooth(true);
	roll.setTexture(Roll);
	roll.setPosition(720, 400);
	dice.setPosition(dicePosition);
	Red.loadFromFile(RED_PIECE_FILEPATH);
	Red.setSmooth(true);
	Yellow.loadFromFile(YELLOW_PIECE_FILEPATH);
	Yellow.setSmooth(true);
	Green.loadFromFile(GREEN_PIECE_FILEPATH);
	Green.setSmooth(true);
	Blue.loadFromFile(BLUE_PIECE_FILEPATH);
	Blue.setSmooth(true);
	red1.setTexture(Red);
	red2.setTexture(Red);
	red3.setTexture(Red);
	red4.setTexture(Red);
	green1.setTexture(Green);
	green2.setTexture(Green);
	green3.setTexture(Green);
	green4.setTexture(Green);
	blue1.setTexture(Blue);
	blue2.setTexture(Blue);
	blue3.setTexture(Blue);
	blue4.setTexture(Blue);
	yellow1.setTexture(Yellow);
	yellow2.setTexture(Yellow);
	yellow3.setTexture(Yellow);
	yellow4.setTexture(Yellow);
	Board.loadFromFile(BOARD_FILEPATH);
	Board.setSmooth(true);
	board.setTexture(Board);
	board.setPosition(0, 0);
	red1.setPosition(RedHomePosition[0]);
	red2.setPosition(RedHomePosition[1]);
	red3.setPosition(RedHomePosition[2]);
	red4.setPosition(RedHomePosition[3]);

	green1.setPosition(GreenHomePosition[0]);
	green2.setPosition(GreenHomePosition[1]);
	green3.setPosition(GreenHomePosition[2]);
	green4.setPosition(GreenHomePosition[3]);

	yellow1.setPosition(YellowHomePosition[0]);
	yellow2.setPosition(YellowHomePosition[1]);
	yellow3.setPosition(YellowHomePosition[2]);
	yellow4.setPosition(YellowHomePosition[3]);

	blue1.setPosition(BlueHomePosition[0]);
	blue2.setPosition(BlueHomePosition[1]);
	blue3.setPosition(BlueHomePosition[2]);
	blue4.setPosition(BlueHomePosition[3]);

	font.loadFromFile(CREDIT_FONT_FILEPATH);
	text.setFont(font);
	dicetext.setFont(font);
	text.setCharacterSize(36);
	text.setPosition(700, 60);
	dicetext.setCharacterSize(36);
	dicetext.setPosition(720, 500);

	// sound
	if (!buffer.loadFromFile(ROLL_SOUND_FILEPATH))
	{
		std::cout << "Error loading sound" << std::endl;
	}
	sound.setBuffer(buffer);

	// gatti movement sound
	if (!gattimove.loadFromFile(GATTI_SOUND_FILEPATH))
	{
		std::cout << "Error loading sound" << std::endl;
	}
	gatti.setBuffer(gattimove);

	// gatti home sound
	if (!gattihome.loadFromFile(WIN_SOUND_FILEPATH))
	{
		std::cout << "Error loading sound" << std::endl;
	}
	gattiHomeSound.setBuffer(gattihome);

	if (!gattiKilled.loadFromFile(KILL_SOUND_FILEPATH))
	{
		std::cout << "Error loading sound" << std::endl;
	}
	kill.setBuffer(gattiKilled);
}

bool Game::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(button))
	{
		sf::IntRect ButtonRect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width, object.getGlobalBounds().height);
		if (ButtonRect.contains(sf::Mouse::getPosition(window)))
		{
			return true;
		}
	}
	return false;
}

void Game ::draw(sf::RenderWindow &window)
{
	window.clear();
	window.draw(board);
	window.draw(red1);
	window.draw(red2);
	window.draw(red3);
	window.draw(red4);
	window.draw(blue1);
	window.draw(blue2);
	window.draw(blue3);
	window.draw(blue4);
	window.draw(green1);
	window.draw(green2);
	window.draw(green3);
	window.draw(green4);
	window.draw(yellow1);
	window.draw(yellow2);
	window.draw(yellow3);
	window.draw(yellow4);
	window.draw(dice);
	window.draw(roll);
	window.draw(text);
	window.draw(dicetext);
	window.display();
}

int Game::rollDice()
{
	srand((unsigned)time(0));

	int num = (rand() % 6) + 1;
	switch (num)
	{
	case 1:
		dice.setTexture(Dice1);
		break;
	case 2:
		dice.setTexture(Dice2);
		break;
	case 3:
		dice.setTexture(Dice3);
		break;
	case 4:
		dice.setTexture(Dice4);
		break;
	case 5:
		dice.setTexture(Dice5);
		break;
	case 6:
		dice.setTexture(Dice6);
		break;
	default:
		break;
	}
	return num;
}
void Game::Killgatti(sf::Sprite &gatti1, sf::Sprite &gatti2, int i, int (&gatti2currentPos)[4], sf::Vector2f (&HomePos)[4], bool &canKill)
{
	if (gatti2.getPosition() == SafePosition[0] || gatti2.getPosition() == SafePosition[1] || gatti2.getPosition() == SafePosition[2] || gatti2.getPosition() == SafePosition[3] || gatti2.getPosition() == SafePosition[4] || gatti2.getPosition() == SafePosition[5] || gatti2.getPosition() == SafePosition[6] || gatti2.getPosition() == SafePosition[7])
	{
		isSafe = true;
	}
	else
	{
		isSafe = false;
	}

	if (gatti1.getPosition() == gatti2.getPosition() && isSafe == false)
	{
		canKill = true;
		gatti2.setPosition(HomePos[i]);
		gatti2currentPos[i] = 0;
		kill.play();
	}
}

void Game::movegatti(int dicevalue, bool& requires, sf::Vector2f position)
{
	bool actionTaken = false;
	static bool canredKill = false;
	static bool canblueKill = false;
	static bool canyellowKill = false;
	static bool cangreenKill = false;

	if (playerTurn == 0)
	{

		if (blue1.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && blue1.getPosition() == BlueHomePosition[0])
			{
				blueCurrentPosition[0] = 0;
				blue1.setPosition(BlueMovement[blueCurrentPosition[0]]);
				gatti.play();
			}
			else if (blueCurrentPosition[0] + dicevalue > 56)
			{
				blueCurrentPosition[0] += 0;
				blue1.setPosition(BlueMovement[blueCurrentPosition[0]]);
			}
			else if (dicevalue == 1 && blue1.getPosition() != BlueHomePosition[0])
			{
				blueCurrentPosition[0]++;
				blue1.setPosition(BlueMovement[blueCurrentPosition[0]]);
			}
			else if (dicevalue != 1 && blue1.getPosition() == BlueHomePosition[0] && blueCurrentPosition[0] == 56)
			{
				requires = true;
			}
			else if (dicevalue != 1 && blue1.getPosition() != BlueHomePosition[0])
			{
				blueCurrentPosition[0] += dicevalue;
				blue1.setPosition(BlueMovement[blueCurrentPosition[0]]);
				gatti.play();
			}
			else if (blueCurrentPosition[0] == 56)
			{
				blueHomegatti += 1;
			}

			// check if blue 1 can kill red if it is in same position and not kill if it is in safe position

			Killgatti(blue1, red1, 0, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue1, red2, 1, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue1, red3, 2, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue1, red4, 3, redCurrentPosition, RedHomePosition, canblueKill);

			// check if blue 1 can kill yellow if it is in same position and not kill if it is in safe position
			Killgatti(blue1, yellow1, 0, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue1, yellow2, 1, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue1, yellow3, 2, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue1, yellow4, 3, yellowCurrentPosition, YellowHomePosition, canblueKill);

			// check if blue 1 can kill green if it is in same position and not kill if it is in safe position
			Killgatti(blue1, green1, 0, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue1, green2, 1, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue1, green3, 2, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue1, green4, 3, greenCurrentPosition, GreenHomePosition, cangreenKill);
		}

		else if (blue2.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && blue2.getPosition() == BlueHomePosition[1])
			{
				blueCurrentPosition[1] = 0;
				blue2.setPosition(BlueMovement[blueCurrentPosition[1]]);
				gatti.play();
			}
			else if (blueCurrentPosition[1] + dicevalue > 56)
			{
				blueCurrentPosition[1] += 0;
				blue2.setPosition(BlueMovement[blueCurrentPosition[1]]);
			}
			else if (dicevalue == 1 && blue2.getPosition() != BlueHomePosition[1])
			{
				blueCurrentPosition[1]++;
				blue2.setPosition(BlueMovement[blueCurrentPosition[1]]);
				gatti.play();
			}
			else if (dicevalue != 1 && blue2.getPosition() == BlueHomePosition[1])
			{
				requires = true;
			}
			else if (dicevalue != 1 && blue2.getPosition() != BlueHomePosition[1])
			{
				blueCurrentPosition[1] += dicevalue;
				blue2.setPosition(BlueMovement[blueCurrentPosition[1]]);
				gatti.play();
			}
			else if (blueCurrentPosition[1] == 56)
			{
				blueHomegatti += 1;
			}

			// check if blue 2 gatti can kill red gatti
			Killgatti(blue2, red1, 0, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue2, red2, 1, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue2, red3, 2, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue2, red4, 3, redCurrentPosition, RedHomePosition, canblueKill);

			// check if blue 2 gatti can kill yellow gatti
			Killgatti(blue2, yellow1, 0, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue2, yellow2, 1, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue2, yellow3, 2, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue2, yellow4, 3, yellowCurrentPosition, YellowHomePosition, canblueKill);

			// check if blue 2 gatti can kill green gatti
			Killgatti(blue2, green1, 0, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue2, green2, 1, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue2, green3, 2, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue2, green4, 3, greenCurrentPosition, GreenHomePosition, cangreenKill);
		}

		else if (blue3.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && blue3.getPosition() == BlueHomePosition[2])
			{
				blueCurrentPosition[2] = 0;
				blue3.setPosition(BlueMovement[blueCurrentPosition[2]]);
				gatti.play();
			}
			else if (blueCurrentPosition[2] + dicevalue > 56)
			{
				blueCurrentPosition[2] += 0;
				blue3.setPosition(BlueMovement[blueCurrentPosition[2]]);
			}
			else if (dicevalue == 1 && blue3.getPosition() != BlueHomePosition[2])
			{
				blueCurrentPosition[2]++;
				blue3.setPosition(BlueMovement[blueCurrentPosition[2]]);
				gatti.play();
			}
			else if (dicevalue != 1 && blue3.getPosition() == BlueHomePosition[2])
			{
				requires = true;
			}
			else if (dicevalue != 1 && blue3.getPosition() != BlueHomePosition[2])
			{
				blueCurrentPosition[2] += dicevalue;
				blue3.setPosition(BlueMovement[blueCurrentPosition[2]]);
				gatti.play();
			}
			else if (blueCurrentPosition[2] == 56)
			{
				blueHomegatti += 1;
			}

			// check if blue 3 gatti can kill red gatti
			Killgatti(blue3, red1, 0, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue3, red2, 1, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue3, red3, 2, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue3, red4, 3, redCurrentPosition, RedHomePosition, canblueKill);

			// check if blue 3 gatti can kill yellow gatti
			Killgatti(blue3, yellow1, 0, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue3, yellow2, 1, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue3, yellow3, 2, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue3, yellow4, 3, yellowCurrentPosition, YellowHomePosition, canblueKill);

			// check if blue 3 gatti can kill green gatti
			Killgatti(blue3, green1, 0, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue3, green2, 1, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue3, green3, 2, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue3, green4, 3, greenCurrentPosition, GreenHomePosition, cangreenKill);
		}

		else if (blue4.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && blue4.getPosition() == BlueHomePosition[3])
			{
				blueCurrentPosition[3] = 0;
				blue4.setPosition(BlueMovement[blueCurrentPosition[3]]);
				gatti.play();
			}
			else if (blueCurrentPosition[3] + dicevalue > 56)
			{
				blueCurrentPosition[3] += 0;
				blue4.setPosition(BlueMovement[blueCurrentPosition[3]]);
			}
			else if (dicevalue == 1 && blue4.getPosition() != BlueHomePosition[3])
			{
				blueCurrentPosition[3]++;
				blue4.setPosition(BlueMovement[blueCurrentPosition[3]]);
				gatti.play();
			}
			else if (dicevalue != 1 && blue4.getPosition() == BlueHomePosition[3])
			{
				requires = true;
			}
			else if (dicevalue != 1 && blue4.getPosition() != BlueHomePosition[3])
			{
				blueCurrentPosition[3] += dicevalue;
				blue4.setPosition(BlueMovement[blueCurrentPosition[3]]);
				gatti.play();
			}
			else if (blueCurrentPosition[3] == 56)
			{
				blueHomegatti += 1;
				gattiHomeSound.play();
			}

			// check if blue 4 gatti can kill red gatti
			Killgatti(blue4, red1, 0, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue4, red2, 1, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue4, red3, 2, redCurrentPosition, RedHomePosition, canblueKill);
			Killgatti(blue4, red4, 3, redCurrentPosition, RedHomePosition, canblueKill);
			// check if blue 4 gatti can kill yellow gatti
			Killgatti(blue4, yellow1, 0, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue4, yellow2, 1, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue4, yellow3, 2, yellowCurrentPosition, YellowHomePosition, canblueKill);
			Killgatti(blue4, yellow4, 3, yellowCurrentPosition, YellowHomePosition, canblueKill);
			// check if blue 4 gatti can kill green gatti
			Killgatti(blue4, green1, 0, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue4, green2, 1, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue4, green3, 2, greenCurrentPosition, GreenHomePosition, cangreenKill);
			Killgatti(blue4, green4, 3, greenCurrentPosition, GreenHomePosition, cangreenKill);
		}
	}

	if (playerTurn == 1)
	{
		if (red1.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && red1.getPosition() == RedHomePosition[0])
			{
				redCurrentPosition[0] = 0;
				red1.setPosition(RedMovement[redCurrentPosition[0]]);
				gatti.play();
			}
			else if (redCurrentPosition[0] + dicevalue > 56)
			{
				redCurrentPosition[0] += 0;
				red1.setPosition(RedMovement[redCurrentPosition[0]]);
			}
			else if (dicevalue == 1 && red1.getPosition() != RedHomePosition[0])
			{
				redCurrentPosition[0]++;
				red1.setPosition(RedMovement[redCurrentPosition[0]]);
				gatti.play();
			}
			else if (dicevalue != 1 && red1.getPosition() == RedHomePosition[0])
			{
				requires = true;
			}
			else if (dicevalue != 1 && red1.getPosition() != RedHomePosition[0])
			{
				redCurrentPosition[0] += dicevalue;
				red1.setPosition(RedMovement[redCurrentPosition[0]]);
				gatti.play();
			}
			else if (red2.getPosition() == RedMovement[56])
			{
				redHomegatti += 1;
				gattiHomeSound.play();
			}

			// check if red 1 gatti can kill yellow gatti
			Killgatti(red1, yellow1, 0, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red1, yellow2, 1, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red1, yellow3, 2, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red1, yellow4, 3, yellowCurrentPosition, YellowHomePosition, canredKill);

			// check if red 1 gatti can kill green gatti
			Killgatti(red1, green1, 0, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red1, green2, 1, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red1, green3, 2, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red1, green4, 3, greenCurrentPosition, GreenHomePosition, canredKill);

			// check if red 1 gatti can kill blue gatti
			Killgatti(red1, blue1, 0, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red1, blue2, 1, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red1, blue3, 2, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red1, blue4, 3, blueCurrentPosition, BlueHomePosition, canredKill);
		}
		else if (red2.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && red2.getPosition() == RedHomePosition[1])
			{
				redCurrentPosition[1] = 0;
				red2.setPosition(RedMovement[redCurrentPosition[1]]);
				gatti.play();
			}
			else if (redCurrentPosition[1] + dicevalue > 56)
			{
				redCurrentPosition[1] += 0;
				red2.setPosition(RedMovement[redCurrentPosition[1]]);
			}
			else if (dicevalue == 1 && red2.getPosition() != RedHomePosition[1])
			{
				redCurrentPosition[1]++;
				red2.setPosition(RedMovement[redCurrentPosition[1]]);
				gatti.play();
			}
			else if (dicevalue != 1 && red2.getPosition() == RedHomePosition[1])
			{
				requires = true;
			}
			else if (dicevalue != 1 && red2.getPosition() != RedHomePosition[1])
			{
				redCurrentPosition[1] += dicevalue;
				red2.setPosition(RedMovement[redCurrentPosition[1]]);
				gatti.play();
			}
			else if (red2.getPosition() == RedMovement[56])
			{
				redHomegatti += 1;
				gattiHomeSound.play();
			}

			// check if red 2 can kill yellow gatti
			Killgatti(red2, yellow1, 0, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red2, yellow2, 1, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red2, yellow3, 2, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red2, yellow4, 3, yellowCurrentPosition, YellowHomePosition, canredKill);

			// check if red 2 gatti can kill green gatti
			Killgatti(red2, green1, 0, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red2, green2, 1, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red2, green3, 2, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red2, green4, 3, greenCurrentPosition, GreenHomePosition, canredKill);

			// check if red 2 gatti can kill blue gatti
			Killgatti(red2, blue1, 0, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red2, blue2, 1, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red2, blue3, 2, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red2, blue4, 3, blueCurrentPosition, BlueHomePosition, canredKill);
		}

		else if (red3.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && red3.getPosition() == RedHomePosition[2])
			{
				redCurrentPosition[2] = 0;
				red3.setPosition(RedMovement[redCurrentPosition[2]]);
				gatti.play();
			}
			else if (redCurrentPosition[2] + dicevalue > 56)
			{
				redCurrentPosition[2] += 0;
				red3.setPosition(RedMovement[redCurrentPosition[2]]);
			}
			else if (dicevalue == 1 && red3.getPosition() != RedHomePosition[2])
			{
				redCurrentPosition[2]++;
				red3.setPosition(RedMovement[redCurrentPosition[2]]);
				gatti.play();
			}
			else if (dicevalue != 1 && red3.getPosition() == RedHomePosition[2])
			{
				requires = true;
			}
			else if (dicevalue != 1 && red3.getPosition() != RedHomePosition[2])
			{
				redCurrentPosition[2] += dicevalue;
				red3.setPosition(RedMovement[redCurrentPosition[2]]);
				gatti.play();
			}
			else if (redCurrentPosition[2] == 56)
			{
				redHomegatti += 1;
				gattiHomeSound.play();
			}
			// check if red 3 gatti can kill yellow gatti
			Killgatti(red3, yellow1, 0, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red3, yellow2, 1, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red3, yellow3, 2, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red3, yellow4, 3, yellowCurrentPosition, YellowHomePosition, canredKill);

			// check if red 3 gatti can kill blue gatti
			Killgatti(red3, blue1, 0, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red3, blue2, 1, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red3, blue3, 2, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red3, blue4, 3, blueCurrentPosition, BlueHomePosition, canredKill);

			// check if red 3 gatti can kill green gatti
			Killgatti(red3, green1, 0, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red3, green2, 1, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red3, green3, 2, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red3, green4, 3, greenCurrentPosition, GreenHomePosition, canredKill);
		}

		else if (red4.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && red4.getPosition() == RedHomePosition[3])
			{
				redCurrentPosition[3] = 0;
				red4.setPosition(RedMovement[redCurrentPosition[3]]);
				gatti.play();
			}
			else if (redCurrentPosition[3] + dicevalue > 56)
			{
				redCurrentPosition[3] += 0;
				red4.setPosition(RedMovement[redCurrentPosition[3]]);
			}
			else if (dicevalue == 1 && red4.getPosition() != RedHomePosition[3])
			{
				redCurrentPosition[3]++;
				red4.setPosition(RedMovement[redCurrentPosition[3]]);
				gatti.play();
			}
			else if (dicevalue != 1 && red4.getPosition() == RedHomePosition[3])
			{
				requires = true;
			}
			else if (dicevalue != 1 && red4.getPosition() != RedHomePosition[3])
			{
				redCurrentPosition[3] += dicevalue;
				red4.setPosition(RedMovement[redCurrentPosition[3]]);
				gatti.play();
			}
			else if (redCurrentPosition[3] == 56)
			{
				redHomegatti += 1;
				gattiHomeSound.play();
			}
			// check if red 4 gatti can kill blue gatti
			Killgatti(red4, blue1, 0, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red4, blue2, 1, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red4, blue3, 2, blueCurrentPosition, BlueHomePosition, canredKill);
			Killgatti(red4, blue4, 3, blueCurrentPosition, BlueHomePosition, canredKill);

			// check if red 4 gatti can kill yellow gatti
			Killgatti(red4, yellow1, 0, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red4, yellow2, 1, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red4, yellow3, 2, yellowCurrentPosition, YellowHomePosition, canredKill);
			Killgatti(red4, yellow4, 3, yellowCurrentPosition, YellowHomePosition, canredKill);

			// check if red 4 gatti can kill green gatti
			Killgatti(red4, green1, 0, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red4, green2, 1, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red4, green3, 2, greenCurrentPosition, GreenHomePosition, canredKill);
			Killgatti(red4, green4, 3, greenCurrentPosition, GreenHomePosition, canredKill);
		}
	}

	if (playerTurn == 2)
	{
		if (green1.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && green1.getPosition() == GreenHomePosition[0])
			{
				greenCurrentPosition[0] = 0;
				green1.setPosition(GreenMovement[greenCurrentPosition[0]]);
				gatti.play();
			}
			else if (greenCurrentPosition[0] + dicevalue > 56)
			{
				greenCurrentPosition[0] += 0;
				green1.setPosition(GreenMovement[greenCurrentPosition[0]]);
			}
			else if (dicevalue == 1 && green1.getPosition() != GreenHomePosition[0])
			{
				greenCurrentPosition[0]++;
				green1.setPosition(GreenMovement[greenCurrentPosition[0]]);
				gatti.play();
			}
			else if (dicevalue != 1 && green1.getPosition() == GreenHomePosition[0])
			{
				requires = true;
			}
			else if (dicevalue != 1 && green1.getPosition() != GreenHomePosition[0])
			{
				greenCurrentPosition[0] += dicevalue;
				green1.setPosition(GreenMovement[greenCurrentPosition[0]]);
				gatti.play();
			}
			else if (greenCurrentPosition[0] == 56)
			{
				greenHomegatti += 1;
				gattiHomeSound.play();
			}

			// check if green 1 gatti can kill red gatti
			Killgatti(green1, red1, 0, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green1, red2, 1, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green1, red3, 2, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green1, red4, 3, redCurrentPosition, RedHomePosition, cangreenKill);

			// check if green 1 gatti can kill yellow gatti
			Killgatti(green1, yellow1, 0, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green1, yellow2, 1, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green1, yellow3, 2, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green1, yellow4, 3, yellowCurrentPosition, YellowHomePosition, cangreenKill);
		}
		else if (green2.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && green2.getPosition() == GreenHomePosition[1])
			{
				greenCurrentPosition[1] = 0;
				green2.setPosition(GreenMovement[greenCurrentPosition[1]]);
				gatti.play();
			}
			else if (greenCurrentPosition[1] + dicevalue > 56)
			{
				greenCurrentPosition[1] += 0;
				green2.setPosition(GreenMovement[greenCurrentPosition[1]]);
			}
			else if (dicevalue == 1 && green2.getPosition() != GreenHomePosition[1])
			{
				greenCurrentPosition[1]++;
				green2.setPosition(GreenMovement[greenCurrentPosition[1]]);
				gatti.play();
			}
			else if (dicevalue != 1 && green2.getPosition() == GreenHomePosition[1])
			{
				requires = true;
			}
			else if (dicevalue != 1 && green2.getPosition() != GreenHomePosition[1])
			{
				greenCurrentPosition[1] += dicevalue;
				green2.setPosition(GreenMovement[greenCurrentPosition[1]]);
				gatti.play();
			}
			else if (greenCurrentPosition[1] == 56)
			{
				greenHomegatti += 1;
				gattiHomeSound.play();
			}
			// check if green 2 gatti can kill red gatti
			Killgatti(green2, red1, 0, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green2, red2, 1, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green2, red3, 2, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green2, red4, 3, redCurrentPosition, RedHomePosition, cangreenKill);

			// check if green 2 gatti can kill yellow gatti
			Killgatti(green2, yellow1, 0, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green2, yellow2, 1, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green2, yellow3, 2, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green2, yellow4, 3, yellowCurrentPosition, YellowHomePosition, cangreenKill);

			// check if green 2 gatti can kill blue gatti
			Killgatti(green2, blue1, 0, blueCurrentPosition, BlueHomePosition, cangreenKill);
			Killgatti(green2, blue2, 1, blueCurrentPosition, BlueHomePosition, cangreenKill);
			Killgatti(green2, blue3, 2, blueCurrentPosition, BlueHomePosition, cangreenKill);
			Killgatti(green2, blue4, 3, blueCurrentPosition, BlueHomePosition, cangreenKill);
		}
		else if (green3.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && green3.getPosition() == GreenHomePosition[2])
			{
				greenCurrentPosition[2] = 0;
				green3.setPosition(GreenMovement[greenCurrentPosition[2]]);
				gatti.play();
			}
			else if (greenCurrentPosition[2] + dicevalue > 56)
			{
				greenCurrentPosition[2] += 0;
				green3.setPosition(GreenMovement[greenCurrentPosition[2]]);
			}
			else if (dicevalue == 1 && green3.getPosition() != GreenHomePosition[2])
			{
				greenCurrentPosition[2]++;
				green3.setPosition(GreenMovement[greenCurrentPosition[2]]);
				gatti.play();
			}
			else if (dicevalue != 1 && green3.getPosition() == GreenHomePosition[2])
			{
				requires = true;
			}
			else if (dicevalue != 1 && green3.getPosition() != GreenHomePosition[2])
			{
				greenCurrentPosition[2] += dicevalue;
				green3.setPosition(GreenMovement[greenCurrentPosition[2]]);
				gatti.play();
			}
			else if (greenCurrentPosition[2] == 56)
			{
				greenHomegatti += 1;
				gattiHomeSound.play();
			}

			// check if green 3 gatti can kill red gatti
			Killgatti(green3, red1, 0, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green3, red2, 1, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green3, red3, 2, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green3, red4, 3, redCurrentPosition, RedHomePosition, cangreenKill);

			// check if green 3 gatti can kill yellow gatti
			Killgatti(green3, yellow1, 0, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green3, yellow2, 1, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green3, yellow3, 2, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green3, yellow4, 3, yellowCurrentPosition, YellowHomePosition, cangreenKill);

			// check if green 3 gatti can kill blue gatti
			Killgatti(green3, blue1, 0, blueCurrentPosition, BlueHomePosition, cangreenKill);
			Killgatti(green3, blue2, 1, blueCurrentPosition, BlueHomePosition, cangreenKill);
			Killgatti(green3, blue3, 2, blueCurrentPosition, BlueHomePosition, cangreenKill);
			Killgatti(green3, blue4, 3, blueCurrentPosition, BlueHomePosition, cangreenKill);
		}
		else if (green4.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && green4.getPosition() == GreenHomePosition[3])
			{
				greenCurrentPosition[3] = 0;
				green4.setPosition(GreenMovement[greenCurrentPosition[3]]);
				gatti.play();
			}
			else if (greenCurrentPosition[3] + dicevalue > 56)
			{
				greenCurrentPosition[3] += 0;
				green4.setPosition(GreenMovement[greenCurrentPosition[3]]);
			}
			else if (dicevalue == 1 && green4.getPosition() != GreenHomePosition[3])
			{
				greenCurrentPosition[3]++;
				green4.setPosition(GreenMovement[greenCurrentPosition[3]]);
				gatti.play();
			}
			else if (dicevalue != 1 && green4.getPosition() == GreenHomePosition[3])
			{
				requires = true;
			}
			else if (dicevalue != 1 && green4.getPosition() != GreenHomePosition[3])
			{
				greenCurrentPosition[3] += dicevalue;
				green4.setPosition(GreenMovement[greenCurrentPosition[3]]);
				gatti.play();
			}
			else if (greenCurrentPosition[3] == 56)
			{
				greenHomegatti += 1;
				gattiHomeSound.play();
			}

			// check if green 4 gatti can kill red gatti
			Killgatti(green4, red1, 0, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green4, red2, 1, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green4, red3, 2, redCurrentPosition, RedHomePosition, cangreenKill);
			Killgatti(green4, red4, 3, redCurrentPosition, RedHomePosition, cangreenKill);

			// check if green 4 gatti can kill yellow gatti
			Killgatti(green4, yellow1, 0, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green4, yellow2, 1, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green4, yellow3, 2, yellowCurrentPosition, YellowHomePosition, cangreenKill);
			Killgatti(green4, yellow4, 3, yellowCurrentPosition, YellowHomePosition, cangreenKill);

			// check if green 4 gatti can kill blue gatti
			Killgatti(green4, blue1, 0, blueCurrentPosition, BlueHomePosition, cangreenKill);
			Killgatti(green4, blue2, 1, blueCurrentPosition, BlueHomePosition, cangreenKill);
			Killgatti(green4, blue3, 2, blueCurrentPosition, BlueHomePosition, cangreenKill);
			Killgatti(green4, blue4, 3, blueCurrentPosition, BlueHomePosition, cangreenKill);
		}
	}
	if (playerTurn == 3)
	{
		if (yellow1.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && yellow1.getPosition() == YellowHomePosition[0])
			{
				yellowCurrentPosition[0] = 0;
				yellow1.setPosition(YellowMovement[yellowCurrentPosition[0]]);
				gatti.play();
			}
			else if (yellowCurrentPosition[0] + dicevalue > 56)
			{
				yellowCurrentPosition[0] += 0;
				yellow1.setPosition(YellowMovement[yellowCurrentPosition[0]]);
			}
			else if (dicevalue == 1 && yellow1.getPosition() != YellowHomePosition[0])
			{
				yellowCurrentPosition[0]++;
				yellow1.setPosition(YellowMovement[yellowCurrentPosition[0]]);
				gatti.play();
			}
			else if (dicevalue != 1 && yellow1.getPosition() == YellowHomePosition[0])
			{
				requires = true;
			}
			else if (dicevalue != 1 && yellow1.getPosition() != YellowHomePosition[0])
			{
				yellowCurrentPosition[0] += dicevalue;
				yellow1.setPosition(YellowMovement[yellowCurrentPosition[0]]);
				gatti.play();
			}
			else if (yellowCurrentPosition[0] == 56)
			{
				yellowHomegatti += 1;
				gattiHomeSound.play();
			}
			// check if yellow 1 gatti can kill red gatti
			Killgatti(yellow1, red1, 0, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow1, red2, 1, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow1, red3, 2, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow1, red4, 3, redCurrentPosition, RedHomePosition, canyellowKill);

			// check if yellow 1 gatti can kill green gatti
			Killgatti(yellow1, green1, 0, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow1, green2, 1, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow1, green3, 2, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow1, green4, 3, greenCurrentPosition, GreenHomePosition, canyellowKill);

			// check if yellow 1 gatti can kill blue gatti
			Killgatti(yellow1, blue1, 0, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow1, blue2, 1, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow1, blue3, 2, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow1, blue4, 3, blueCurrentPosition, BlueHomePosition, canyellowKill);
		}
		else if (yellow2.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && yellow2.getPosition() == YellowHomePosition[1])
			{
				yellowCurrentPosition[1] = 0;
				yellow2.setPosition(YellowMovement[yellowCurrentPosition[1]]);
				gatti.play();
			}
			else if (yellowCurrentPosition[1] + dicevalue > 56)
			{
				yellowCurrentPosition[1] += 0;
				yellow2.setPosition(YellowMovement[yellowCurrentPosition[1]]);
			}
			else if (dicevalue == 1 && yellow2.getPosition() != YellowHomePosition[1])
			{
				yellowCurrentPosition[1]++;
				yellow2.setPosition(YellowMovement[yellowCurrentPosition[1]]);
				gatti.play();
			}
			else if (dicevalue != 1 && yellow2.getPosition() == YellowHomePosition[1])
			{
				requires = true;
			}
			else if (dicevalue != 1 && yellow2.getPosition() != YellowHomePosition[1])
			{
				yellowCurrentPosition[1] += dicevalue;
				yellow2.setPosition(YellowMovement[yellowCurrentPosition[1]]);
				gatti.play();
			}
			else if (yellowCurrentPosition[1] == 56)
			{
				yellowHomegatti += 1;
				gattiHomeSound.play();
			}
			// check if yellow 2 gatti can kill red gatti
			Killgatti(yellow2, red1, 0, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow2, red2, 1, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow2, red3, 2, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow2, red4, 3, redCurrentPosition, RedHomePosition, canyellowKill);

			// check if yellow 2 gatti can kill green gatti
			Killgatti(yellow2, green1, 0, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow2, green2, 1, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow2, green3, 2, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow2, green4, 3, greenCurrentPosition, GreenHomePosition, canyellowKill);

			// check if yellow 2 gatti can kill blue gatti
			Killgatti(yellow2, blue1, 0, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow2, blue2, 1, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow2, blue3, 2, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow2, blue4, 3, blueCurrentPosition, BlueHomePosition, canyellowKill);
		}
		else if (yellow3.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && yellow3.getPosition() == YellowHomePosition[2])
			{
				yellowCurrentPosition[2] = 0;
				yellow3.setPosition(YellowMovement[yellowCurrentPosition[2]]);
				gatti.play();
			}
			else if (yellowCurrentPosition[2] + dicevalue > 56)
			{
				yellowCurrentPosition[2] += 0;
				yellow3.setPosition(YellowMovement[yellowCurrentPosition[2]]);
			}
			else if (dicevalue == 1 && yellow3.getPosition() != YellowHomePosition[2])
			{
				yellowCurrentPosition[2]++;
				yellow3.setPosition(YellowMovement[yellowCurrentPosition[2]]);
				gatti.play();
			}
			else if (dicevalue != 1 && yellow3.getPosition() == YellowHomePosition[2])
			{
				requires = true;
			}
			else if (dicevalue != 1 && yellow3.getPosition() != YellowHomePosition[2])
			{
				yellowCurrentPosition[2] += dicevalue;
				yellow3.setPosition(YellowMovement[yellowCurrentPosition[2]]);
				gatti.play();
			}
			else if (yellowCurrentPosition[2] == 56)
			{
				yellowHomegatti += 1;
				gattiHomeSound.play();
			}

			// check if yellow 3 gatti can kill red gatti
			Killgatti(yellow3, red1, 0, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow3, red2, 1, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow3, red3, 2, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow3, red4, 3, redCurrentPosition, RedHomePosition, canyellowKill);

			// check if yellow 3 gatti can kill green gatti
			Killgatti(yellow3, green1, 0, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow3, green2, 1, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow3, green3, 2, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow3, green4, 3, greenCurrentPosition, GreenHomePosition, canyellowKill);

			// check if yellow 3 gatti can kill blue gatti
			Killgatti(yellow3, blue1, 0, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow3, blue2, 1, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow3, blue3, 2, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow3, blue4, 3, blueCurrentPosition, BlueHomePosition, canyellowKill);
		}
		else if (yellow4.getGlobalBounds().contains(position))
		{
			actionTaken = true;
			if (dicevalue == 1 && yellow4.getPosition() == YellowHomePosition[3])
			{
				yellowCurrentPosition[3] = 0;
				yellow4.setPosition(YellowMovement[yellowCurrentPosition[3]]);
				gatti.play();
			}
			else if (yellowCurrentPosition[3] + dicevalue > 56)
			{
				yellowCurrentPosition[3] += 0;
				yellow4.setPosition(YellowMovement[yellowCurrentPosition[3]]);
			}
			else if (dicevalue == 1 && yellow4.getPosition() != YellowHomePosition[3])
			{
				yellowCurrentPosition[3]++;
				yellow4.setPosition(YellowMovement[yellowCurrentPosition[3]]);
				gatti.play();
			}
			else if (dicevalue != 1 && yellow4.getPosition() == YellowHomePosition[3])
			{
				requires = true;
			}
			else if (dicevalue != 1 && yellow4.getPosition() != YellowHomePosition[3])
			{
				yellowCurrentPosition[3] += dicevalue;
				yellow4.setPosition(YellowMovement[yellowCurrentPosition[3]]);
				gatti.play();
			}
			else if (yellowCurrentPosition[3] == 56)
			{
				yellowHomegatti += 1;
				gattiHomeSound.play();
			}
			// check if yellow 4 gatti can kill red gatti
			Killgatti(yellow4, red1, 0, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow4, red2, 1, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow4, red3, 2, redCurrentPosition, RedHomePosition, canyellowKill);
			Killgatti(yellow4, red4, 3, redCurrentPosition, RedHomePosition, canyellowKill);

			// check if yellow 4 gatti can kill green gatti
			Killgatti(yellow4, green1, 0, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow4, green2, 1, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow4, green3, 2, greenCurrentPosition, GreenHomePosition, canyellowKill);
			Killgatti(yellow4, green4, 3, greenCurrentPosition, GreenHomePosition, canyellowKill);

			// check if yellow 4 gatti can kill blue gatti
			Killgatti(yellow4, blue1, 0, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow4, blue2, 1, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow4, blue3, 2, blueCurrentPosition, BlueHomePosition, canyellowKill);
			Killgatti(yellow4, blue4, 3, blueCurrentPosition, BlueHomePosition, canyellowKill);
		}
	}
	if (actionTaken)
	{
		// dont change turn if dice value is 6 or 1 or if the player has to move a piece from home  or if player kills another piece
		if ((dicevalue == 6 || dicevalue == 1 ) && requires)
		{
			playerTurn = playerTurn;
		}
		else
		{
			playerTurn = (playerTurn + 1) % 4;
			requires = false;
		}
	}
}

void Game::openGameWindow(sf::RenderWindow &window)
{
	// Initialize();
	Game game;
	GameoverState gameover;

	bool requiresRollDice = true;
	bool requiresPawnInput = false;
	window.create(sf::VideoMode(900, 860), "Ludo");

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if (playerTurn == 0)
		{
			text.setString("Current Player:\n\t\tBlue");
			text.setFillColor(sf::Color::Blue);
			dicetext.setFillColor(sf::Color::Blue);
			// dicetext.setString("Blue Got:\n\t" + std::to_string(diceValue));
		}
		else if (playerTurn == 1)
		{
			text.setString("Current Player:\n\t\tRed");
			text.setFillColor(sf::Color::Red);
			dicetext.setFillColor(sf::Color::Red);
			// dicetext.setString("Red Got:\n\t" + std::to_string(diceValue));
		}
		else if (playerTurn == 2)
		{
			text.setString("Current Player:\n\t\tGreen");
			text.setFillColor(sf::Color::Green);
			dicetext.setFillColor(sf::Color::Green);
			
		}
		else if (playerTurn == 3)
		{
			text.setString("Current Player:\n\t\tYellow");
			text.setFillColor(sf::Color::Yellow);
			dicetext.setFillColor(sf::Color::Yellow);

		}

		if (IsSpriteClicked(roll, sf::Mouse::Left, window))
		{
			if (requiresRollDice)
			{

				requiresRollDice = false;
				requiresPawnInput = true;
				diceValue = rollDice();
				sound.play();
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			// Get position of mouse
			sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

			// Check if mouse is inside the sprite

			if (diceValue == 1 || diceValue == 6)
			{
				requiresRollDice = requiresPawnInput;
				requiresPawnInput = true;
			}

			if (requiresPawnInput)
			{
				sf::Vector2f mousePositionf = sf::Vector2f(mousePosition.x, mousePosition.y);
				movegatti(diceValue, requiresPawnInput, mousePositionf);
			}
			else
			{
				requiresRollDice = !requiresPawnInput;
			}
		}

		draw(window);
		if(redCurrentPosition[0]==56 && redCurrentPosition[1]==56 && redCurrentPosition[2]==56 && redCurrentPosition[3]==56){
			gameover.RedWins(window);
			
		}
		else if(greenCurrentPosition[0]==56 && greenCurrentPosition[1]==56 && greenCurrentPosition[2]==56 && greenCurrentPosition[3]==56){
			gameover.GreenWins(window);
			
		}
		else if(blueCurrentPosition[0]==56 && blueCurrentPosition[1]==56 && blueCurrentPosition[2]==56 && blueCurrentPosition[3]==56){
			gameover.BlueWins(window);
			
		}
		else if(yellowCurrentPosition[0]==56 && yellowCurrentPosition[1]==56 && yellowCurrentPosition[2]==56 && yellowCurrentPosition[3]==56){
			gameover.YellowWins(window);
			
		}
		window.display();
		
		
		
	}
	
}


