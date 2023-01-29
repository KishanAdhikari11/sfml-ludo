#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


// class Game {
// public:
//     Game();



// bool IsSpriteClicked(sf::Sprite object,sf::Mouse::Button button,sf::RenderWindow &window);
// void openGameWindow(sf::RenderWindow& window);
// int rollDice();
// void Killgatti(sf::Sprite &gatti1,sf::Sprite &gatti2,int i,int (&gatti2currentPos) [4],sf::Vector2f (&HomePos) [4],bool &canKill);

// void movegatti(int dicevalue,bool& requires,sf::Vector2f position);
// void draw(sf::RenderWindow& window);
// void Init();




//  private:

       
class Game {
    public:
    Game();
    bool IsSpriteClicked(sf::Sprite object,sf::Mouse::Button button,sf::RenderWindow &window);
    void openGameWindow(sf::RenderWindow& window);
    void Killgatti(sf::Sprite &gatti1,sf::Sprite &gatti2,int i,int (&gatti2currentPos) [4],sf::Vector2f (&HomePos) [4],bool &canKill);
    void movegatti(int dicevalue,bool& requires,sf::Vector2f position);
    void draw(sf::RenderWindow& window);
    int rollDice();

    private:
    bool canredKill=false;
	bool canblueKill=false;
	bool canyellowKill=false;
	bool cangreenKill=false;
	int diceValue=0;
	

	sf::Font font;
	sf::Text text,dicetext;
	sf::SoundBuffer buffer,gattimove,gattihome,killSoundBuffer,gattiKilled;

	sf::Sound sound,gatti,kill,gattiKilledSound,gattiHomeSound;



	int blueHomegatti=0;
	int redHomegatti=0;
	int greenHomegatti=0;
	int yellowHomegatti=0;

	int totalPlayer=4;
	int playerTurn=0;
	bool isSafe = false;

	//Dice
	sf::Texture Dice1;
	sf::Texture Dice2;
	sf::Texture Dice3;
	sf::Texture Dice4;
	sf::Texture Dice5;
	sf::Texture Dice6;
	sf::Texture Roll;
	sf::Sprite dice;
	sf::Sprite roll;

	sf::Vector2f RedHomePosition[4] ={sf::Vector2f(72,64),sf::Vector2f(156,64),sf::Vector2f(156,142),sf::Vector2f(72,142)};
	sf::Vector2f BlueHomePosition[4] ={sf::Vector2f(72,478),sf::Vector2f(156,478),sf::Vector2f(156,556),sf::Vector2f(72,556)};
	sf::Vector2f GreenHomePosition[4] ={sf::Vector2f(488,64),sf::Vector2f(572,64),sf::Vector2f(572,142),sf::Vector2f(488,142)};
	sf::Vector2f YellowHomePosition[4] ={sf::Vector2f(488,478),sf::Vector2f(572,478),sf::Vector2f(572,556),sf::Vector2f(488,556)};


	sf::Vector2f RedMovement[57]={sf::Vector2f(48,260),sf::Vector2f(94,260),sf::Vector2f(140,260),sf::Vector2f(186,260),sf::Vector2f(232,260),sf::Vector2f(278,230),sf::Vector2f(278,180),sf::Vector2f(278,135),sf::Vector2f(278,85),
	sf::Vector2f(278,42),sf::Vector2f(278,0),sf::Vector2f(324,0),sf::Vector2f(370,0),sf::Vector2f(370,42),sf::Vector2f(370,85),sf::Vector2f(370,135),sf::Vector2f(370,180),sf::Vector2f(370,230),sf::Vector2f(416,260),
	sf::Vector2f(462,260),sf::Vector2f(508,260),sf::Vector2f(554,260),sf::Vector2f(600,260),sf::Vector2f(646,260),sf::Vector2f(646,306),sf::Vector2f(646,352),sf::Vector2f(600,352),sf::Vector2f(554,352),sf::Vector2f(508,352),
	sf::Vector2f(462,352),sf::Vector2f(416,352),sf::Vector2f(370,398),sf::Vector2f(370,444),sf::Vector2f(370,490),sf::Vector2f(370,536),sf::Vector2f(370,582),sf::Vector2f(370,628),sf::Vector2f(324,628),sf::Vector2f(278,628),
	sf::Vector2f(278,582),sf::Vector2f(278,536),sf::Vector2f(278,490),sf::Vector2f(278,444),sf::Vector2f(278,398),sf::Vector2f(232,352),sf::Vector2f(186,352),sf::Vector2f(140,352),sf::Vector2f(94,352),sf::Vector2f(48,352),
	sf::Vector2f(2,352),sf::Vector2f(2,306),sf::Vector2f(48,306),sf::Vector2f(94,306),sf::Vector2f(140,306),sf::Vector2f(186,306),sf::Vector2f(232,306),sf::Vector2f(278,306)};


	sf::Vector2f GreenMovement[57]={sf::Vector2f(370,42),sf::Vector2f(370,85),sf::Vector2f(370,135),sf::Vector2f(370,180),sf::Vector2f(370,230),
	sf::Vector2f(416,260),sf::Vector2f(462,260),sf::Vector2f(508,260),sf::Vector2f(554,260),sf::Vector2f(600,260),sf::Vector2f(646,260),sf::Vector2f(646,306),
	sf::Vector2f(646,352),sf::Vector2f(600,352),sf::Vector2f(554,352),sf::Vector2f(508,352),sf::Vector2f(462,352),sf::Vector2f(416,352),sf::Vector2f(370,398),
	sf::Vector2f(370,444),sf::Vector2f(370,490),sf::Vector2f(370,536),sf::Vector2f(370,582),sf::Vector2f(370,628),sf::Vector2f(324,628),sf::Vector2f(278,628),
	sf::Vector2f(278,582),sf::Vector2f(278,536),sf::Vector2f(278,490),sf::Vector2f(278,444),sf::Vector2f(278,398),sf::Vector2f(232,352),sf::Vector2f(186,352),
	sf::Vector2f(140,352),sf::Vector2f(94,352),sf::Vector2f(48,352),sf::Vector2f(2,352),sf::Vector2f(2,306),sf::Vector2f(2,260),sf::Vector2f(48,260),sf::Vector2f(94,260),
	sf::Vector2f(140,260),sf::Vector2f(186,260),sf::Vector2f(232,260),sf::Vector2f(278,230),sf::Vector2f(278,180),sf::Vector2f(278,135),sf::Vector2f(278,85),sf::Vector2f(278,42),sf::Vector2f(278,0),sf::Vector2f(324,0),
	sf::Vector2f(324,42),sf::Vector2f(324,85),sf::Vector2f(324,135),sf::Vector2f(324,180),sf::Vector2f(324,230),sf::Vector2f(324,260)};


	sf::Vector2f YellowMovement[57]={sf::Vector2f(600,352),sf::Vector2f(554,352),sf::Vector2f(508,352),sf::Vector2f(462,352),sf::Vector2f(416,352),sf::Vector2f(370,398),sf::Vector2f(370,444),sf::Vector2f(370,490),sf::Vector2f(370,536),sf::Vector2f(370,582),sf::Vector2f(370,628),sf::Vector2f(324,628),sf::Vector2f(278,628),
	sf::Vector2f(278,582),sf::Vector2f(278,536),sf::Vector2f(278,490),sf::Vector2f(278,444),sf::Vector2f(278,398),sf::Vector2f(232,352),sf::Vector2f(186,352),sf::Vector2f(140,352),sf::Vector2f(94,352),sf::Vector2f(48,352),sf::Vector2f(2,352),sf::Vector2f(2,306),sf::Vector2f(2,260),sf::Vector2f(48,260),sf::Vector2f(94,260),sf::Vector2f(140,260),sf::Vector2f(186,260),sf::Vector2f(232,260),sf::Vector2f(278,230),sf::Vector2f(278,180),sf::Vector2f(278,135),sf::Vector2f(278,85),sf::Vector2f(278,42),sf::Vector2f(278,0),sf::Vector2f(324,0),
	sf::Vector2f(370,0),sf::Vector2f(370,42),sf::Vector2f(370,85),sf::Vector2f(370,135),sf::Vector2f(370,180),sf::Vector2f(370,230),sf::Vector2f(416,260),sf::Vector2f(462,260),sf::Vector2f(508,260),sf::Vector2f(554,260),sf::Vector2f(600,260),sf::Vector2f(646,260),sf::Vector2f(646,306),sf::Vector2f(600,306),sf::Vector2f(554,306),sf::Vector2f(508,306),sf::Vector2f(462,306),sf::Vector2f(416,306),sf::Vector2f(370,306)};

	sf::Vector2f BlueMovement[57]={sf::Vector2f(278,582),sf::Vector2f(278,536),sf::Vector2f(278,490),sf::Vector2f(278,444),sf::Vector2f(278,398),sf::Vector2f(232,352),sf::Vector2f(186,352),sf::Vector2f(140,352),sf::Vector2f(94,352),sf::Vector2f(48,352),sf::Vector2f(2,352),sf::Vector2f(2,306),sf::Vector2f(2,260),sf::Vector2f(48,260),sf::Vector2f(94,260),sf::Vector2f(140,260),sf::Vector2f(186,260),sf::Vector2f(232,260),sf::Vector2f(278,230),sf::Vector2f(278,180),sf::Vector2f(278,135),sf::Vector2f(278,85),sf::Vector2f(278,42),sf::Vector2f(278,0),sf::Vector2f(324,0),
	sf::Vector2f(370,0),sf::Vector2f(370,42),sf::Vector2f(370,85),sf::Vector2f(370,135),sf::Vector2f(370,180),sf::Vector2f(370,230),sf::Vector2f(416,260),sf::Vector2f(462,260),sf::Vector2f(508,260),sf::Vector2f(554,260),sf::Vector2f(600,260),sf::Vector2f(646,260),sf::Vector2f(646,306),
	sf::Vector2f(646,352),sf::Vector2f(600,352),sf::Vector2f(554,352),sf::Vector2f(508,352),sf::Vector2f(462,352),sf::Vector2f(416,352),sf::Vector2f(370,398),sf::Vector2f(370,444),sf::Vector2f(370,490),sf::Vector2f(370,536),sf::Vector2f(370,582),sf::Vector2f(370,628),sf::Vector2f(324,628),sf::Vector2f(324,582),sf::Vector2f(324,536),sf::Vector2f(324,490),sf::Vector2f(324,444),sf::Vector2f(324,398),sf::Vector2f(324,352)};


	sf::Vector2f SafePosition[8]={sf::Vector2f(48,260),sf::Vector2f(370,42),sf::Vector2f(600,352),sf::Vector2f(278,582),sf::Vector2f(278,85),sf::Vector2f(94,352),sf::Vector2f(370,536),sf::Vector2f(554,260)};




	sf::Texture Red,Green,Yellow,Blue,Board;
	sf::Sprite red1,red2,red3,red4,green1,green2,green3,green4,blue1,blue2,blue3,blue4,yellow1,yellow2,yellow3,yellow4;
	sf::Sprite board;
    int redCurrentPosition[4]={0,0,0,0};
    int greenCurrentPosition[4]={0,0,0,0};
    int blueCurrentPosition[4]={0,0,0,0};
    int yellowCurrentPosition[4]={0,0,0,0};

        
};
    

      


