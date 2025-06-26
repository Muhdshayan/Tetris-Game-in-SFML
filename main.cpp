/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You don't need to change anything in the driver code/main function except the part(s) where instructed.
 * You are expected to define your functionalities in the "functionality.h" header and call them here in the instructed part(s).
 * The game is started with a small box, you need to create other possible in "pieces.h" file in form of array.
    E.g., Syntax for 2 pieces, each having four coordinates -> int Pieces[2][4];
 * Load the images into the textures objects from img directory. 
 * Don't make any changes to the "utils.h" header file except for changing the coordinate of screen or global variables of the game.
 * SUGGESTION: If you want to make changes in "utils.h", do it once you complete rest of the functionalities.
 * TIP: You can study SFML for drawing scenes, sprites and window.
 * */

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"
#include<sstream>
#include<iostream>

using namespace sf;
using namespace std;
int main(){
   
   int z=menuwindow();    //for displaying menu                        
  if(z==0)
  {
    return 1;
  }



    int pos[4][2];        // array for position of shadow
    srand(time(0));
    RenderWindow window(VideoMode(320, 480), title);
    window.setTitle("Pf project");
    Texture obj1, obj2, obj3,obj4;
    //-------------------for uploading files---------------------
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/A.jpg");
    obj3.loadFromFile("img/frame.png");  
    obj4.loadFromFile("img/tiles.png");
   
   
//---------------------- Score board -------------------------------------------------
sf::Font font;
font.loadFromFile("img/font.otf");
   sf::Text text;
text.setFont(font); 
text.setString("SCORE");
text.setCharacterSize(35); // in pixels, not points!
text.setFillColor(sf::Color::Red);
text.setStyle(sf::Text::Bold | sf::Text::Underlined);
text.setPosition(230,70);
window.draw(text);
// ----------------------------Score display-----------------------------------------
sf::Text scoring;
scoring.setFont(font);
scoring.setFillColor(sf::Color::White);
scoring.setScale(1,1);
 scoring.setPosition(260,120);

 //-----------------------Gameover-------------------------------------
 sf::Font font1;
font1.loadFromFile("img/game_over.ttf");
sf::Text text1;
text1.setFont(font1); 
text1.setString("GAME OVER");
text1.setCharacterSize(90); // in pixels, not points!
text1.setFillColor(sf::Color::White);
text1.setStyle(sf::Text::Bold); //| sf::Text::Underlined);
text1.setPosition(50,50);

// inside the main loop, between window.clear() and window.display()
    Sprite sprite(obj1), background(obj2), frame(obj3),shadow(obj4);
    int delta_x=0, colorNum=1;
    float timer=0, delay=0.3,delaybomb=0.3;
    bool rotate=0,temp=true; int score=0;
    float timer1=0;;bool f=0;bool game=true;
    int n;
       NewBlock();  //for removing single block in starting    copy paste
         //-----------------------------------for adding music in game---------------------------------

    Clock clock;
    sf::Music music;
// Open it from an audio file
if (!music.openFromFile("s.ogg"))
{
    // error...
}
// Change some parameters
music.setPosition(0, 1, 10); // change its 3D position
//music.setPitch(2);           // increase the pitch
music.setVolume(50);         // reduce the volume
music.setLoop(true);         // make it loop
// Play it
music.play();
       
       

    while (window.isOpen()){
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        if (temp==true)
        {
            timer+=time;
        }
        
        

        //---Event Listening Part---//
        
        Event e;
        if(n!=7)
        {
        while (window.pollEvent(e)){                    //Event is occurring - until the game is in running state
            if (e.type == Event::Closed)                   //If cross/close is clicked/pressed
                window.close();                            //Opened window disposes
            if (e.type == Event::KeyPressed) {             //If any other key (not cross) is pressed
                if (e.key.code == Keyboard::Up) 
                {                                             //Check if the other key pressed is UP key
                    rotate = true;  
                }                                           //Rotation gets on
                else if (e.key.code == Keyboard::Left)  {   //Check if the other key pressed is LEFT key
                   bool check=1;
                    for(int i=0;i<4;i++)
                    {
                    if(point_1[i][0]==0) 
                     check=0;
                    else if (gameGrid[point_1[i][1]][point_1[i][0]-1]) 
                    check=0;
                    }
                    if(check){
                    delta_x= -1;  
                    shiftleft(delta_x);
                    }
                    }                                        //Change in X-Axis - Negative
                else if (e.key.code == Keyboard::Right){    //Check if the other key pressed is RIGHT key
                  bool check1=1;
                    for(int i=0;i<4;i++)
                    {
                    if(point_1[i][0]==N-1) 
                     check1=0;
                    else if (gameGrid[point_1[i][1]][point_1[i][0]+1]) 
                    check1=0;
                    }
                    if(check1){
                    delta_x=1;                                //Change in X-Axis - Positive
                    shiftright(delta_x);
                    }
                    }  
                    else if (e.key.code == Keyboard::Space)
                    {
                        while(anamoly1()){

                        for(int i=0;i<4;i++)
                        {
                                point_1[i][1]+=1;

                               gameGrid[point_1[i][1]][point_1[i][0]];
                        }
                        }

                    }   
                     else if (e.key.code == Keyboard::P)
                     {
                        pause(timer); 
                        temp=false; 
                     }
                      else if (e.key.code == Keyboard::S)
                     {
                        temp=true;
                     }
                      else if (e.key.code == Keyboard::R)
                     {
                        gridclear();
                     }
        }
        }
         if (Keyboard::isKeyPressed(Keyboard::Down))   //Just another way to detect key presses without event listener
            delay=0.05;  
        }

        
                                         //If DOWN key is pressed, delay in falling piece decreases from 0 to 0.05
             if (Keyboard::isKeyPressed(Keyboard::Escape))
             window.close();
        
        ///////////////////////////////////////////////
        ///*** START CALLING YOUR FUNCTIONS HERE ***///

        if(rotate){
            rotation();
            rotate=0;
        }
        fallingPiece(timer, delay,colorNum,pos,n);  
        linedeleting(score);  
        //Example: fallingPiece() function is called here
        shadow1(pos);
        //fallingPiece1(bomb,timer1,delaybomb,b);
        ///*** YOUR CALLING STATEMENTS END HERE ***///
        //////////////////////////////////////////////
       
        delta_x=0;
        delay=0.3;
        scoring.setString(std::to_string(score));

        window.clear(Color::Black);
        window.draw(background);
        for (int i=0; i<M; i++){
            for (int j=0; j<N; j++){
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++){
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);

          }


          //--------------------------for displaying shadow----------------
          if(n!=7)
          {
          for (int i=0; i<4; i++){
            shadow.setTextureRect(IntRect(colorNum*18,0,18,18));
            shadow.setColor(Color(225,225,225,80));  
            shadow.setPosition(pos[i][0]*18,pos[i][1]*18);
            shadow.move(28,31); 
            window.draw(shadow);
          }
          }
        
        //---The Final on Which Everything is Drawn Over is Loaded---
        window.draw(frame);
        window.draw(scoring);
        window.draw(text);text.setFont(font);
        window.draw(sprite);
        if(gameover())
        {
          music.pause();
          // song.pause();
          //over.play();
       
          
          window.draw(text1);
          timer=0;
          
        }
        //---The Window that now Contains the Frame is Displayed---//
        window.display();
    }
    return 0;
}
// grid neeche jaake khatam horha waha y ke value 19, point 1 mai jo value hai usai aik value -1 
