#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>

int main()
{
    int map[9][9], ans[9][9], control[9][9];
    int bug;
    char difficulty = 'e';
    srand((unsigned int)time(NULL));
    printf("If you forced waiting 1 minute, please restart this program.\n");

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
            retry:
            map[i][j] = rand() % 9 + 1;
            ans[i][j] = map[i][j];
            for(int k = 0; k < j; k++)
            {
                if(map[i][j] == map[i][k])
                {
                    j = 0;
                    for(int m = 0; m < 9; m++)
                    {
                        map[i][m] = 0;
                    }
                    goto retry;
                }
            }
            for(int k = 0; k < i; k++)
            {
                if(map[i][j] == map[k][j])
                {
                    j = 0;
                    for(int m = 0; m < 9; m++)
                    {
                        map[i][m] = 0;
                    }
                    goto retry;
                }
            }
            bug = 0;
            for(int k = 0; k < 3; k++)
            {
                for(int l = 0; l < 3; l++)
                {
                    if(i < 3 && j < 3 && map[i][j] == map[k][l])
                    {
                        bug++;
                    }
                    else if(i < 3 && j > 2 && j < 6 && map[i][j] == map[k][l + 3])
                    {
                        bug++;
                    }
                    else if(i < 3 && j > 5 && j < 9 && map[i][j] == map[k][l + 6])
                    {
                        bug++;
                    }
                    else if(i > 2 && i < 6 && j < 3 && map[i][j] == map[k + 3][l])
                    {
                        bug++;
                    }
                    else if(i > 2 && i < 6 && j > 2 && j < 6 && map[i][j] == map[k + 3][l + 3])
                    {
                        bug++;
                    }
                    else if(i > 2 && i < 6 && j > 5 && j < 9 && map[i][j] == map[k + 3][l + 6])
                    {
                        bug++;
                    }
                    else if(i > 5 && i < 9 && j < 3 && map[i][j] == map[k + 6][l])
                    {
                        bug++;
                    }
                    else if(i > 5 && i < 9 && j > 2 && j < 6 && map[i][j] == map[k + 6][l + 3])
                    {
                        bug++;
                    }
                    else if(i > 5 && i < 9 && j > 5 && j < 9 && map[i][j] == map[k + 6][l + 6])
                    {
                        bug++;
                    }

                    if(bug > 1)
                    {
                        j = 0;
                        for(int m = 0; m < 9; m++)
                        {
                            map[i][m] = 0;
                        }
                        goto retry;
                    }
                }
            }
        }
    }

    int x = 0, y = 0;
    char move = ' ';
    int blank = 0, misslimit = 0;
    int misscount = 0;

    printf("Difficulty(e/n/h/m):");
    do
    {
        difficulty = getch();
        printf("%c", difficulty);
    }while(difficulty != 'e' && difficulty != 'n' && difficulty != 'h' && difficulty != 'm' && difficulty != 'c');
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
    if(difficulty == 'c')
    {
        for(int i = 0; i < 9; i++)
        {
            blank = 1 + rand() % 2;
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
                printf(" %c", control[i][j]);
                if(j == 2 || j == 5) printf("    ");
            }
            puts("");
            for(int j = 0; j < 9; j++)
            {
                if(map[i][j] == 0) printf("  ");
                else printf(" %d", map[i][j]);
                if(j == 2 || j == 5) printf("  | ");
            }
            puts("");
            if(i == 2 || i == 5) printf("\n---------------------------\n");
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
        if(move == 'e') break;

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
