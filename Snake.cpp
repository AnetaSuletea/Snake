#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define border (char)176
#define food (char)227
#define snakeFill (char) 127
#define space (char) 255

char board[41][41];
char snake[2000]={snakeFill,snakeFill,snakeFill};
char key;
bool gameover=0;
int t;
int h;
int points=0;
struct snake
{
    int col;
    int row;
}snB[1000];

struct point
{
          unsigned col;
          unsigned row;
}foodP;

using namespace std;

void moveHead();
void deleteTail();
void drawBoard();
void printBoard();

int main()
{
    drawBoard();
    do
    {
        srand(time(0));
        foodP.row=rand()%39+1;
        foodP.col=rand()%39+1;
        board[foodP.row][foodP.col]=food;
    }
    while (board[foodP.row][foodP.col]==snakeFill);

    printBoard();
    key=_getch();
    while (gameover==0)
    {
        moveHead();
        if (gameover==0)
        {
        printBoard();
            if(_kbhit())
            {
                key=_getch();
            }
        }
        else
        {
            system("CLS");
            cout<<"Game over!";
        }
    }
    return 0;
}

void drawBoard()
{
    int i;
    int j;
    for(i=0;i<41;i++)
    {
        for(j=0;j<41;j++)
        {
            if(i==0 || j==0 || i==40 || j==40)
            {
                board[i][j]=border;
            }
            else
            {
                board[i][j]=space;
            }
        }
    }
    snB[0].col=20;
    snB[0].row=20;
    snB[1].col=21;
    snB[1].row=20;
    snB[2].col=22;
    snB[2].row=20;
    h=2;
    t=0;
    for(i=t;i<=h;i++)
    {
       board[snB[i].row][snB[i].col]=snakeFill;
    }
}

void printBoard()
{
   system("CLS");
    cout<<"To start the game press w,a,s,d:"<<endl;
    cout<<"w for Up"<<endl<<"s for Down"<<endl<<"a for left"<<endl<<"d for right"<<endl<<endl;
    cout<<"Points:"<<points<<endl<<endl;
    int i;
    int j;
    for(i=0;i<41;i++)
    {
        for(j=0;j<41;j++)
        {
            cout<<board[i][j];
        }
        cout<<endl;
    }

}

void moveHead()
{
    switch (key)
    {
    case 'w':
        {
            snB[h+1].row=snB[h].row-1;
            snB[h+1].col=snB[h].col;
        }
        break;
    case 's':
        {
            snB[h+1].row=snB[h].row+1;
            snB[h+1].col=snB[h].col;
        }
        break;
    case 'a':
        {
            snB[h+1].row=snB[h].row;
            snB[h+1].col=snB[h].col-1;
        }
        break;
    case 'd':
        {
            snB[h+1].row=snB[h].row;
            snB[h+1].col=snB[h].col+1;
        }
        break;
    }
    h++;
    if(board[snB[h].row][snB[h].col]==space)
    {
        board[snB[h].row][snB[h].col]=snakeFill;
        deleteTail();
    }
    else if (board[snB[h].row][snB[h].col]==border || board[snB[h].row][snB[h].col]==snakeFill)
        {
            gameover=1;
        }
        else
        {
           // board[foodP.row][foodP.col]=space;
           points+=10;
            do
            {
                srand(time(0));
                foodP.row=rand()%39+1;
                foodP.col=rand()%39+1;
                board[foodP.row][foodP.col]=food;
            }
            while (board[foodP.row][foodP.col]==snakeFill);

        }
}

void deleteTail()
{
    board[snB[t].row][snB[t].col]=space;
    t++;
}
