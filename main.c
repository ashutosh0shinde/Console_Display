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
    screen[x-1][y-1] = onchar;
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
    for(i =1;i<5;i++)
    {
        drawPixel(3,i);   
        cls();
        render();    
        delay(1000);
        printf("\n%d",i);
    }
}
