#include<stdio.h>
#include<stdlib.h>

//checking the current os and importing 
//delay functions for respective os 
#ifdef _WIN32
#include<windows.h>
#else
#include<unistd.h>
#endif

#define ROW 8
#define COL 60

char screen[ROW][COL];
char offchar = '.';
char onchar = '#';

#define C_X 5
#define C_Y 7
char letters[5][5][7] ={
    {//0
        {'.','.','#','#','#','.','.'},
        {'.','#','.','.','.','#','.'},
        {'.','#','#','#','#','#','.'},
        {'.','#','.','.','.','#','.'},
        {'.','#','.','.','.','#','.'}
    },
    {//1
        {'.','#','#','#','#','.','.'},
        {'.','#','.','.','.','#','.'},
        {'.','#','#','#','#','#','.'},
        {'.','#','.','.','.','#','.'},
        {'.','#','#','#','#','.','.'}
    },
    {//2
        {'.','.','#','#','#','#','.'},
        {'.','#','.','.','.','.','.'},
        {'.','#','.','.','.','.','.'},
        {'.','#','.','.','.','.','.'},
        {'.','.','#','#','#','#','.'}
    },
    {//3
        {'.','#','#','#','#','.','.'},
        {'.','#','.','.','.','#','.'},
        {'.','#','.','.','.','#','.'},
        {'.','#','.','.','.','#','.'},
        {'.','#','#','#','#','.','.'}
    },
    {//4
        {'.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.'}
    }
};

void drawPixel(int x, int y);
void printChar(int ind, int st_x,int st_y)
{
    int i,j;
    for(i = 0; i < C_X; i++)
    {
        for(j = 0; j < C_Y; j++)
        {
            if(letters[ind][i][j] == onchar)
            {
                // if(i+st_x < ROW && j+st_y < COL)
                // {
                //     drawPixel(i+st_x, j+st_y);
                // }
                // else if(i+st_x < ROW)
                // {
                //     drawPixel(i+st_x, j+st_y-COL);
                // }
                // else if(j+st_y < COL)
                // {
                //     drawPixel(i+st_x-ROW, j+st_y);
                // }
                // else
                // {
                //     drawPixel(i+st_x-ROW, j+st_y-COL);
                // }
                drawPixel((i+st_x)%ROW, (j+st_y)%COL); //correct it, may give negative values when tried moving left/up
            }
        }
    }
}
void delay(int ms)
{
    #ifdef _WIN32
    Sleep(ms); // for windows: ms
    #else
    usleep(ms*1000); // for linux/macos: uf*1000 = ms
    #endif
}
void cls(){
    // #ifdef _WIN32
    // system("cls");
    // #else
    // system("clear");
    // #endif
    printf("\033[2J\033[H"); //moves cursor to top left, creating 
                            // illusion of refrashing screen
}
void resetScreen()
{
    int i;
    char *ptr = *screen;
    for(i = 0;i<ROW*COL;i++)
    {
        *(ptr+i) = offchar; 
    }
}
void drawPixel(int x, int y)
{
    screen[x][y] = onchar;
}
void render()
{
    int i,j;
    printf("\n");
    for(i =0; i<ROW; i++)
    {
        for(j = 0;j<COL; j++)
        {
            printf("%c",screen[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main()
{
    resetScreen();
    

    int i;
    for(i =1;i<100;i++)
    {
        cls();
        resetScreen();
        printChar(0, 2,i);
        printChar(1, 2,i+7);
        printChar(2, 2,i+14);
        printChar(3, 2,i+21);
        render();    
        delay(50);
    }
}
