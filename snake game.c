#include<stdio.h>
#include<conio.h>
int height = 30 , width = 30, x ,y , fruitx, fruity, flag, gameend,score;
int tailx[100],taily[100];
int piece=0;
void draw()
{
    system("cls");
    int i,j,k;
    for(i=0;i<=height;i++)
    {
        for(j=0;j<=width;j++)
        {
            if(i==0  || j==0  )
            {
                printf(".");
            }
            else if(i== height || j== width)
            {
                printf(".");
            }
            else
            {
                if(i==x && j==y)
                {
                    printf("o");
                }
                else if(i== fruitx && j== fruity)
                {
                    printf("$");
                }
                else
                {
                    for(k=0;k<piece;k++)
                    {
                        if(i==tailx[k] && j==taily[k])
                        {
                            printf("o");

                        }
                    }

                    printf(" ");

                }

            }
        }

        printf("\n");
    }
    printf("your score : %d",score);


}
void setup()
{
    x=height/2;
    y=width/2;
    l:
    fruitx=rand()%30;
    if(fruitx==0)
        goto l;

    m:
    fruity=rand()%30;
    if(fruity==0)
        goto m;
    gameend=0;
    score=0;
    piece++;
}
void input()
{
    if(kbhit())
    {
      switch(getch())
      {
        case '8':
            {
                flag =1;
                break;
            }
        case '2':
            {
                flag =2;
                break;
            }
        case '4':
            {
                flag =3;
                break;
            }
        case '6':
            {
                flag =4;
                break;
            }
      }
    }
}
void makeLogic()
{
    int i;
    int prevx, prevy, prev2x, prev2y;
    prevx=tailx[0];
    prevy=taily[0];
    tailx[0]=x;
    taily[0]=y;
    for(i=1;i<=piece;i++)
    {
        prev2x=tailx[i];
        prev2y=taily[i];
        tailx[i]=prevx;
        taily[i]=prevy;
        prevx=prev2x;
        prevy=prev2y;
    }
    switch(flag)
    {
        case 1:
            {
                x--;
                break;
            }
        case 2:
            {
                x++;
                break;
            }
        case 3:
            {
                y--;
                break;
            }
        case 4:
            {
                y++;
                break;
            }

    }
    if(x==0 || x== height || y==0 || y== width)
    {
        gameend=1;
    }
    if(x== fruitx && y==fruity)
    {
        n:
        fruitx=rand()%30;
        if(fruitx==0)
            goto n;

        o:
        fruity=rand()%30;
        if(fruity==0)
            goto o;
        score=score+10;
        piece++;
    }
}
void main()
{
    setup();
    while(gameend!=1)
    {
        input();
        draw();
        makeLogic();

    }


}
