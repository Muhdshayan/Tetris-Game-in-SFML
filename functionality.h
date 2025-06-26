/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//

#include <SFML/Graphics.hpp>
#include<sstream>
using namespace sf;

void BOMB(int n);
void gridclear();
void menuforhelp();
void fallingPiece(float &timer, float &delay, int &colorNum, int pos[4][2],int &n)
{
    if (timer > delay)
    {
        for (int i = 0; i < 4; i++)
        {
            point_2[i][0] = point_1[i][0];
            point_2[i][1] = point_1[i][1];


            point_1[i][1] +=1;
            // How much units downward
        }

        if (!anamoly())
        {
            for (int i = 0; i < 4; i++)
                gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;

                if(n==7)      //bomb block  is on position 7
                    {               
                    BOMB(n);      
                    }
                    
            colorNum = 1 + rand() % 7;
            n = rand() % 8;    // 8 block is of bomb
            
            //--- Un-Comment this Part When You Make BLOCKS array---//
            for (int i = 0; i < 4; i++)
            {
                point_1[i][0] = BLOCKS[n][i] % 2;
                point_1[i][1] = BLOCKS[n][i] / 2;
            }
           int x=rand()%10;    //for different positions of bomb
           if(n==7)
           {
            for(int i=0;i<4;i++)
            {
                point_1[i][0]=x;
            }
           }
        }
        timer = 0;
    }
}
/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
void shiftright(int &delta_x)   //for shifting the block right
{
    for (int a = 0; a < 4; a++)
    {
        point_1[a][0] += delta_x;  //adding deltax value in point 1 for shifting right
    }
}
void shiftleft(int &delta_x)
{
    for (int i = 0; i < 4; i++)
    {
        point_1[i][0] += delta_x;    //adding deltax value in point 1 for shifting left
    }
}
int scoring(int &score,int counter)
{
switch (counter)
{
case 1:
    score+=10;
    break;                 //scoring calculation according to rubrix
case 2:
    score+=30;
    break;
case 3:
    score+=60;
    break;
case 4:
    score+=100;
    break;

default:
    break;
}
return score;
}
void linedeleting(int &score)
{
    int t= 19;
    int counter=0;
    for (int x = 19; x > 0; x--)
    {
        int num = 0;
        for (int y = 0; y < N; y++)
        {
            if (gameGrid[x][y])
            {
                num+=1;
            }
            gameGrid[t][y] = gameGrid[x][y];    //swaping lines if all lines filled
        }
        if (N>num)          //if all lines are filled counter increase which calculates score
            t=t-1;
        else
        counter+=1;
    }
    scoring(score,counter);
}

bool anamoly1()
{
    for (int i = 0; i < 4; i++)
        if (point_1[i][1] >= M - 1)
            return 0;
        else if (gameGrid[point_1[i][1] + 1][point_1[i][0]])     //anamoly for space aa it deals only with y axis
            return 0;
    return 1;
}

bool anamoly2(int pos[4][2])                      //anamoly for shadow
{  
    for (int i = 0; i < 4; i++)
        if (pos[i][1] >= M - 1)
            return 0;
        else if (gameGrid[pos[i][1] + 1][pos[i][0]])
            return 0;
    return 1;
}

bool gameover()
{
    bool check = false;
    for (int i = 0; i < 10; i++)             //if any point at last grid is one so gameover
    {
        if (gameGrid[0][i])
            check = true;
    }
    return check;
}

void shadow1(int pos[4][2])                 //for position of shadow
{
    
    for (int i = 0; i < 4; i++)
        {
    pos[i][0] = point_1[i][0];
     pos[i][1] = point_1[i][1];
        }
    while (anamoly2(pos))
    {
        for (int i = 0; i < 4; i++)
        {
            pos[i][1] += 1;
        }
    }
}
void pause(float &timer)
{
    timer = 0;
}
void NewBlock()    //for removing single block thay come in first falling
{
    int n = rand() % 7;
    for (int i = 0; i < 4; i++)
    {
        point_1[i][0] = BLOCKS[n][i] % 2;
        point_1[i][1] = BLOCKS[n][i] / 2;
    }
}
void highest_score_menu()  //menu for highest score
{
    RenderWindow highest_window(VideoMode(320,480),title);
    Texture hs;
    hs.loadFromFile("img/highest.jpeg");

    Sprite hs_sprite;
    hs_sprite.setTexture(hs);

while(highest_window.isOpen())
    {
        Event event;
     while(highest_window.pollEvent(event))
    {
        if (Keyboard::isKeyPressed(Keyboard::BackSpace)) //back to menu
        {
            highest_window.close();
            return;
        }
        highest_window.draw(hs_sprite);
        highest_window.display();
    }
    }
}
void rotation()
{

    int pivot[1][2];
    pivot[0][0] = point_1[1][0];
    pivot[0][1] = point_1[1][1];     //making pivot of block for which all rotation is happening

    for (int i = 0; i < 4; i++)
    {
    if(point_1[i][0]==0 || point_1[i][0]==N-1)
        return ;
    }
    for (int i = 0; i < 4; i++)
    {
        int x = point_1[i][1] - pivot[0][1];
        int y = point_1[i][0] - pivot[0][0];   //calculating for rotation
        point_1[i][0] = pivot[0][0] + x;
        point_1[i][1] = pivot[0][1] - y; 
    }
    if (!anamoly())
        for (int i = 0; i < 4; i++)
        {
            point_1[i][0] = point_2[i][0];
            point_1[i][1] = point_2[i][1];
        }
}
void bombblockremoval()      //removing blocks for which bomb color and blocks r not same
{
    for(int a=0;a<4;a++)
    {
       gameGrid[point_2[a][1]+2][point_2[a][0]+1]=0;
       gameGrid[point_2[a][1]+2][point_2[a][0]]=0;
       gameGrid[point_2[a][1]+1][point_2[a][0]]=0;
       gameGrid[point_2[a][1]+1][point_2[a][0]+1]=0;
    }
}
void BOMB(int n)     //functioning for bomb
{
    for(int a=0;a<4;a++)
    {
        if((gameGrid[point_2[a][1]][point_2[a][0]]==gameGrid[point_1[a][1]][point_1[a][0]]) && (gameGrid[point_1[a][1]][point_1[a][0]]!=0))
        {
            gridclear();
        }
        else if(gameGrid[point_2[a][1]][point_2[a][0]]!=0)
        {
            bombblockremoval();
        }
        gameGrid[point_2[a][1]][point_2[a][0]]=0;
    }
}
void gridclear()             //making whole grid 0
{
    
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            gameGrid[i][j]={0};
        }
    }
}
void play(float &timer)       //for playing after pause


{
    timer = 1;
}
int menuwindow()      //open window for menu
{
    RenderWindow menu(VideoMode(320,480),title);
    menu.setTitle("menu");
    Texture a;
    a.loadFromFile("img/menu.jpeg");

    Sprite m;
    m.setTexture(a);

while(menu.isOpen())
{
    Event event;
    while(menu.pollEvent(event))
    {
        if(event.type == Event::Closed)
        {
            menu.close();
            return 0;
        }
         if (Keyboard::isKeyPressed(Keyboard::Enter))    // enter to start game
        {
            return 1;
        }
         else if (Keyboard::isKeyPressed(Keyboard::H))  //showing help menu
        {
            menuforhelp();
        }
         else if (Keyboard::isKeyPressed(Keyboard::S)) //showing high score
        {
            highest_score_menu();
        }
        else if (Keyboard::isKeyPressed(Keyboard::X))   //exit
        {
            menu.close();
            return 0;
        }
        menu.draw(m);
        menu.display();
    }
}
    return 0;

}
void menuforhelp()  //open window for help
{
    RenderWindow help(VideoMode(320,480),title);
    help.setTitle("help menu");
    Texture h;
    h.loadFromFile("img/help.jpeg");

    Sprite helps;
    helps.setTexture(h);

while(help.isOpen())
    {
        Event event;
     while(help.pollEvent(event))
    {
        if (Keyboard::isKeyPressed(Keyboard::BackSpace))
        {
            help.close();
            return;
        }
        help.draw(helps);
        help.display();
    }
    }
}

///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
