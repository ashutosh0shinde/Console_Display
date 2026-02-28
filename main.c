#include<stdio.h>
#define ROW 8
#define COL 60

char screen[ROW][COL];
int i,j;
char offchar = '0';
char onchar = '#';

void resetScreen()
{
    char *ptr = *screen;
    for(i = 0;i<ROW*COL;i++)
    {
        *(ptr+i) = offchar; 
    }
}
void render()
{
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
    render();
}
