#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int map[9][9], ans[9][9], choice[9][5];
    char control[9][9];
    srand((unsigned int)time(NULL));

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            map[i][j] = 0;
            control[i][j] =' ';
        }
    }    

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j < 9; j++)
        {
            for(int k = 0; k < 5; k++)
            {
                for(int l = 0; l < 9; l++)
                {
                    choice[l][k] = 0;
                }
            }
            int a = 0, b = 0; /*カウンタ*/
            for(int k = 0; k < 9; k++)
            {
                if(map[i][k] > 0)
                {
                    choice[a][0] = map[i][k];
                    a++;
                }
                if(map[k][j] > 0)
                {
                    choice[b][1] = map[k][j];
                    b++;
                }
            }
            a = 0;
            for(int k = 0; k < 3; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    if((i < 3) && (j < 3) && (map[k][l] > 0))
                    {
                        choice[a][2] = map[k][l];
                        a++;
                    }
                    else if((i < 3) && (j > 2) && (j < 6) && (map[k][l + 3] > 0))
                    {
                        choice[a][2] = map[k][l + 3];
                        a++;
                    }
                    else if((i < 3) && (j > 5) && (map[k][l + 6] > 0))
                    {
                        choice[a][2] = map[k][l + 6];
                        a++;
                    }
                    else if((i > 2) && (i < 6) && (j < 3) && (map[k + 3][l] > 0))
                    {
                        choice[a][2] = map[k + 3][l];
                        a++;
                    }
                    else if((i > 2) && (i < 6) && (j > 2) && (j < 6) && (map[k + 3][l + 3] > 0))
                    {
                        choice[a][2] = map[k + 3][l + 3];
                        a++;
                    }
                    else if((i > 2) && (i < 6) && (j > 5) && (map[k + 3][l + 6] > 0))
                    {
                        choice[a][2] = map[k + 3][l + 6];
                        a++;
                    }
                    else if((i > 5) && (j < 3) && (map[k + 6][l] > 0))
                    {
                        choice[a][2] = map[k + 6][l];
                        a++;
                    }
                    else if((i > 5) && (j > 2) && (j < 6) && (map[k + 6][l + 3] > 0))
                    {
                        choice[a][2] = map[k + 6][l + 3];
                        a++;
                    }
                    else if((i > 5) && (j > 5) && (map[k + 6][l + 6] > 0))
                    {
                        choice[a][2] = map[k + 6][l + 6];
                        a++;
                    }
                }
            }
            a = 0;
            for(int k = 0; k < 9; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    for(int m = 0; m < 9; m++)
                    {
                        if((choice[k][3] != choice[m][l]) && (choice[m][l] > 0))
                        {
                            choice[a][3] = choice[m][l];
                            a++;
                        }
                    }
                }
            }
            b = 0;
            for(int k = 1; k <= 9; k++)
            {
                next:
                for(int l = 0; l < a; l++)
                {
                    if(choice[l][3] == k)
                    {
                        k++;
                        goto next;
                    }
                }
                choice[b][4] = k;
                b++;
                if(b >= 9) break;
            }
            map[i][j] = choice[rand() % b][4];
            ans[i][j] = map[i][j];
        }
    }

    int x = 0, y = 0;
    char move = ' ';
    char difficulty = ' ';
    int blank = 0, misslimit = 0;
    int misscount = 0;

    printf("Difficulty(e/n/h/m):");
    do
    {
        difficulty = getch();
        printf("%c", difficulty);
    }while(difficulty != 'e' && difficulty != 'n' && difficulty != 'h' && difficulty != 'm');
    printf("\nMiss limit(1~/0=unlimited):");
    do
    {
        scanf("%d", &misslimit);
    }while(misslimit < 0);
    if(difficulty == 'e')
    {
        for(int i = 0; i < 9; i++)
        {
            blank = 3 + rand() % 4;
            for(int j = 0; j < blank; j++)
            {
                map[i][rand() % 9] = 0;
            }
        }
    }
    if(difficulty == 'n')
    {
        for(int i = 0; i < 9; i++)
        {
            blank = 4 + rand() % 4;
            for(int j = 0; j < blank; j++)
            {
                map[i][rand() % 9] = 0;
            }
        }
    }
    if(difficulty == 'h')
    {
        for(int i = 0; i < 9; i++)
        {
            blank = 4 + rand() % 5;
            for(int j = 0; j < blank; j++)
            {
                map[i][rand() % 9] = 0;
            }
        }
    }
    if(difficulty == 'm')
    {
        for(int i = 0; i < 9; i++)
        {
            blank = 5 + rand() % 5;
            for(int j = 0; j < blank; j++)
            {
                map[i][rand() % 9] = 0;
            }
        }
    }

    do{
        system("cls");
        control[y][x] = '@';
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                printf("%c", control[i][j]);
                if(j == 2 || j == 5) printf("\t");
            }
            puts("");
            for(int j = 0; j < 9; j++)
            {
                if(map[i][j] == 0) printf(" ");
                else printf("%d", map[i][j]);
                if(j == 2 || j == 5) printf("\t");
            }
            puts("");
            if(i == 2 || i == 5) printf("\n\n");
        }
        if(misslimit == 0) printf("Miss(%d/unlimited)", misscount);
        else printf("Miss(%d/%d)", misscount, misslimit);
        if(misscount >= misslimit && misslimit != 0) move = 'e';
        int check = 0;
        for(int i = 0; i < 9; i++)
        {
            for(int j = 0; j < 9; j++)
            {
                if(map[i][j] == ans[i][j])
                {
                    check++;
                    if(check >= 81)
                    {
                        puts("Complete!!!");
                        move = 'e';
                    }
                }
            }
        }

        move = getch();
        if(move == 'w')
        {
            control[y][x] = ' ';
            if(y != 0) y--;
        }
        else if(move == 'd')
        {
            control[y][x] = ' ';
            if(x != 8) x++;
        }
        else if(move == 's')
        {
            control[y][x] = ' ';
            if(y != 8) y++;
        }
        else if(move == 'a')
        {
            control[y][x] = ' ';
            if(x != 0) x--;
        }
        else if(map[y][x] == 0)
        {
            if(move == '1' && ans[y][x] == 1) map[y][x] = 1;
            else if(move == '2' && ans[y][x] == 2) map[y][x] = 2;
            else if(move == '3' && ans[y][x] == 3) map[y][x] = 3;
            else if(move == '4' && ans[y][x] == 4) map[y][x] = 4;
            else if(move == '5' && ans[y][x] == 5) map[y][x] = 5;
            else if(move == '6' && ans[y][x] == 6) map[y][x] = 6;
            else if(move == '7' && ans[y][x] == 7) map[y][x] = 7;
            else if(move == '8' && ans[y][x] == 8) map[y][x] = 8;
            else if(move == '9' && ans[y][x] == 9) map[y][x] = 9;
            else misscount++;
        }

    }while(move != 'e');

    puts("");
    system("pause");
    system("cls");
    return 0;
}
