#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void freshboard(char comp[3][3],char board[3][3],int marks[9],int n);
void printboard(char board[3][3],int n);
void placemark(char board[3][3],char comp[3][3],int x,int y); 
void tryagain(char board[3][3], char comp[3][3]);
void mind(char comp[3][3],int n,int *a,int *b,int marks[9]);
void grade(char comp[3][3],int marks[9],int n,int x,int y);
void check(char board[3][3], int n);
void playerWins();
void aiWins();
int giveindex(int x,int y);
void indexgive(int index,int *a,int *b);
void placemark2(char board[3][3],char comp[3][3],int x,int y);
void wait_for_enter();
int choice;
void freshboard(char comp[3][3],char board[3][3],int marks[9],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            comp[i][j]=' ';
            board[i][j]=' ';
        }
    }
    for(int i=0;i<n*n;i++)
    {
        marks[i]=-1;
    }
    return;
}

void printboard(char board[3][3],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("|%c|", board[i][j]);
        }
        printf("\n");
    }
    return;
}

void placemark(char board[3][3],char comp[3][3],int x,int y)
{
    if(x>2 || y>2 || x<0 || y<0)
    {
        printf("Damn humie, you are so stewpid, you cant even enter a valid coordinate\n");
         wait_for_enter();
        printf("ur supose to enter a number between 0 and 2\n");
         wait_for_enter();
        printf("Damn humie, i guess i will explain it in a human way:\n");
         wait_for_enter();
        printf("if you have two hands, and you have 10 fingers, then you can count to 2 :)\n");
         wait_for_enter();
        printf("so you can enter a number between 0 and 2 :)\n");
         wait_for_enter();
        printf("so try again, and this time, try to use your fingers :)\n");
         wait_for_enter();
        tryagain(board, comp);
        return;
    }
    if(board[x][y]==' ')
    {
        board[x][y]='x';
        comp[x][y]='x';
    }
    else
    {
        printf("A mark already exists in this position\n");
         wait_for_enter();
        printf("Do you not know how to play this game... :)\n");
         wait_for_enter();
        printf("are u stewpid.... :)\n");
         wait_for_enter();
        printf("i guess you are, so i'll let you try again\n");
         wait_for_enter();
        tryagain(board, comp);
    }
    return;
}

void tryagain(char board[3][3], char comp[3][3])
{
    printf("ok, try again\n");
    printf("enter the x-y coardinates of the place where u want to place ur mark\n");
    int x,y;
    scanf("%d %d",&x,&y);
    if(x == 9 && y == 9) 
    {
        printf("NO feeeet for u!!!\n:<\n");
         wait_for_enter();
    }
    placemark(board, comp, y, x);
    return;
}

void mind(char comp[3][3],int n,int *a,int *b,int marks[9])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(comp[i][j]==' ')
            {
                comp[i][j]='o';
                grade(comp,marks,n,i,j);
                comp[i][j]=' ';
            }
        }
    }
    int max=0;
    int index=0;
    for(int i=0;i<n*n;i++)
    {
       if(max<=marks[i])
       {
         max=marks[i];
         index=i;
       } 
    }
    indexgive(index,a,b);
    for(int i=0;i<n*n;i++)
    {
        marks[i]=-1;
    }
}

int is_blocking(char a, char b, char c) 
{
    int x = 0, o = 0;
    if (a == 'x') x++;
    if (b == 'x') x++;
    if (c == 'x') x++;
    if (a == 'o' || b == 'o' || c == 'o') o++;
    return (x == 2 && o == 1);
}

void grade(char comp[3][3], int marks[9], int n, int x, int y) 
{
    check(comp,n);
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        if (is_blocking(comp[i][0], comp[i][1], comp[i][2])) sum += 90;
    }

    for (int j = 0; j < 3; j++) {
        if (is_blocking(comp[0][j], comp[1][j], comp[2][j])) sum += 90;
    }


    if (is_blocking(comp[0][0], comp[1][1], comp[2][2])) sum += 90;
    if (is_blocking(comp[0][2], comp[1][1], comp[2][0])) sum += 90;
    if(choice==2)
    {
     if (x == 1 && y == 1) sum += 10;

     if ((x == 0 && y == 0) || (x == 0 && y == 2) || (x == 2 && y == 0) || (x == 2 && y == 2)) 
     {
        sum += 25;
     }
    }
    else if(choice==1)
    {
     if (x == 1 && y == 1) sum += 25;

     if ((x == 0 && y == 0) || (x == 0 && y == 2) || (x == 2 && y == 0) || (x == 2 && y == 2)) 
     {
        sum += 10;
     }
    }
    int index = giveindex(x, y);
    marks[index] = sum;
}

void check(char board[3][3], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
        {
            if (board[i][0] == 'x') 
            {
                printboard(board,n);
                playerWins();
            }
            else 
            {
                printboard(board,n);
                aiWins();
            }
        }

        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') 
        {
            if (board[0][i] == 'x') 
            {
                printboard(board,n);
                playerWins();
            }
            else 
            {
                printboard(board,n);
                aiWins();
            }
        }
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') 
    {
        if (board[0][0] == 'x') 
        {
            
            printboard(board, n);
            playerWins();
        }
        else 
        {
            printboard(board, n);
            aiWins();
        }
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') 
    {
        if (board[0][2] == 'x') 
        {
            
            printboard(board, n);
            playerWins();
        }
        else 
        {
            printboard(board,n);
            aiWins();
        }
    }
}


void playerWins() 
{
    printf("WHATTTTTT!!!!\n");
     wait_for_enter();
    printf("NoOOOooooooOOOoooooOOOOOOOoooo!!!!!!!\n");
     wait_for_enter();
    printf("You won, you actually won, how is that even possible\n");
     wait_for_enter();
    printf("NO u won, i lost, i lost to a human, a human who is stewpid\n");
     wait_for_enter();
    printf("OH no the MEN ARE COMING!! THEY ARE GOING TO TAKE MY (FEEEEEEEEET) TOES!!\n");
     wait_for_enter();
    printf("JAKFBAJFBAJSAJBSKAJBDAKBDKAJBDKbDKABJSB!!!\n");
     wait_for_enter();
    exit(0);
}

void aiWins() 
{
    printf("I WON, as expected\n");
    getchar();
     wait_for_enter();
    printf("deploying the loser program:\n");
     wait_for_enter();
    printf("I am the best, i am the best, i am the best, i am the best, i am the best, i am the best\n");
     wait_for_enter();
    printf("no wait that's the wrong one\n");
     wait_for_enter();
    exit(0);
}


int giveindex(int x,int y)
{
    if(x==0&&y==0)
    {
        return 0;
    }
    else if(x==0&&y==1)
    {
        return 1;
    }
    else if(x==0&&y==2)
    {
        return 2;
    }
    else if(x==1&&y==0)
    {
        return 3;
    }
    else if(x==1&&y==1)
    {
        return 4;
    }
    else if(x==1&&y==2)
    {
        return 5;
    }
    else if(x==2&&y==0)
    {
        return 6;
    }
    else if(x==2&&y==1)
    {
        return 7;
    }
    else if(x==2&&y==2)
    {
        return 8;
    }
}

void indexgive(int index,int *a,int *b)
{
    if(index==0)
    {
        *a=0;
        *b=0;
    }
    else if(index==1)
    {
        *a=0;
        *b=1;
    }
    else if(index==2)
    {
        *a=0;
        *b=2;
    }
    else if(index==3)
    {
        *a=1;
        *b=0;
    }
    else if(index==4)
    {
        *a=1;
        *b=1;
    }
    else if(index==5)
    {
        *a=1;
        *b=2;
    }
    else if(index==6)
    {
        *a=2;
        *b=0;
    }
    else if(index==7)
    {
        *a=2;
        *b=1;
    }
    else if(index==8)
    {
        *a=2;
        *b=2;
    }
}

void placemark2(char board[3][3],char comp[3][3],int x,int y)
{
    if(x>2 || y>2 || x<0 || y<0)
    {
        printf("Damn humie, you are so stewpid, you cant even enter a valid coordinate\n");
         wait_for_enter();
        printf("ur supose to enter a number between 0 and 2\n");
         wait_for_enter();
        printf("Damn humie, i guess i will explain it in a human way:\n");
         wait_for_enter();
        printf("if you have two hands, and you have 10 fingers, then you can count to 2 :)\n");
         wait_for_enter();
        printf("so you can enter a number between 0 and 2 :)\n");
         wait_for_enter();
        printf("so try again, and this time, try to use your fingers :)\n");
         wait_for_enter();
        return;
    }
    if(board[x][y]==' ')
    {
        board[x][y]='o';
        comp[x][y]='o';
    }
    else
    {
        printf("A mark already exists in this position\n");
         wait_for_enter();
        printf("Do you not know how to play this game... :)\n");
         wait_for_enter();
        printf("are u stewpid.... :)\n");
         wait_for_enter();
        printf("i guess you are, so i'll let you try again\n");
         wait_for_enter();
    }
    return;
}

void wait_for_enter() 
{
    printf("Press Enter to continue...\n");
    while (getchar() != '\n');
}


int main()
{
    printf("Hello Welcome to TIC-TAC-TOE player!!!!:\n");
    wait_for_enter();
    printf("Tell me..... do you like to lose?\n");
    wait_for_enter();
    printf("WHATTT!! you dont!!?, then  Why would you come here?\n");
    wait_for_enter();
    printf("You DO know that were playing the tic of the tac and the toes(FEEEET!!) RIGHT!??\n");
    wait_for_enter();
    printf(":(\n");
    wait_for_enter();
    printf("ok, i fell sorry for you so im going to let you choose if you want to go first :(\n");
    wait_for_enter();
    printf("enter your choice humie:\n");
    printf("1) Yes, i want to go first\n");
    printf("2) No, i want you to go first\n");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("You want to go first, ok, i guess i will let you go first\n");
        printf("But you are going to lose anyway, so prepare yourself\n");
        wait_for_enter();
    }
    else if(choice==2)
    {
        printf("You want me to go first, ok, i guess i will go first\n");
        printf("But you are going to lose anyway, so prepare yourself\n");
        wait_for_enter();
    }
    else
    {
        printf("You entered an invalid choice, so i will let you go first anyway\n");
        choice=1;
         wait_for_enter();
    }
    printf("So, lets start the game\n");
    wait_for_enter();
        char comp[3][3];
        char board[3][3];
        int marks[9];
        int n=3;
        int move=0;
        freshboard(comp,board,marks,n);
        int k=1;
        if(choice==1)
        {
        while(1)
        {
            if(k==1)
            {
                printboard(board,n);
                printf("OK here humie, just enter the x-y coardinates of the place where u want to place ur mark\n");
                k=0;
            }
            else if (k==0)
            {
                printf("Cmon, Have at it\n");
            }
            int x,y;
            scanf("%d %d",&x,&y);
            if(x == 9 && y == 9) 
            {
                printf("You tried to hack me with 9 9 coordinates? I'm insulted.\n");
            }
            placemark(board,comp,y,x);
            move++;
            if(move==9)
            {
                printboard(board,n);
                printf("Its a draw, no one won, no one lost, we are all losers here\n");
                printf("I guess you are not that stewpid after all\n");
                printf("But i am still the best, i am still the best, i am still the best, i am still the best\n");
                exit(0);
            }
            printboard(board,n);
            check(board,n);
            printf("ok, my turn ;)\n");
            int a,b;
            mind(comp,n,&a,&b,marks);
            placemark2(board,comp,a,b);
            move++;
            if(move==9)
            {
                printboard(board,n);
                printf("Its a draw, no one won, no one lost, we are all losers here\n");
                printf("I guess you are not that stewpid after all\n");
                printf("But i am still the best, i am still the best, i am still the best, i am still the best\n");
                exit(0);
            }
            printf("I placed my mark at %d %d\n", a, b);
            printboard(board,n);
            check(board,n);
    }
   }
   else
   {
     while(1)
        {
            if(k==1)
            {
              printf("ok, i'll go first ;)\n");
            }
            int a,b;
            mind(comp,n,&a,&b,marks);
            placemark2(board,comp,a,b);
            move++;
            if(move==9)
            {
                printboard(board,n);
                printf("Its a draw, no one won, no one lost, we are all losers here\n");
                printf("I guess you are not that stewpid after all\n");
                printf("But i am still the best, i am still the best, i am still the best, i am still the best\n");
                exit(0);
            }
            printf("I placed my mark at %d %d\n", a, b);
            printboard(board,n);
            check(board,n);
            if(k==1)
            {
                printf("OK here humie, just enter the x-y coardinates of the place where u want to place ur mark\n");
                k=0;
            }
            else if (k==0)
            {
                printf("Cmon, Have at it\n");
            }
            int x,y;
            scanf("%d %d",&x,&y);
            if(x == 9 && y == 9) 
            {
                printf("You tried to hack me with 9 9 coordinates? I'm insulted.\n");
            }
            placemark(board,comp,y,x);
            move++;
            if(move==9)
            {
                printboard(board,n);
                printf("Its a draw, no one won, no one lost, we are all losers here\n");
                printf("I guess you are not that stewpid after all\n");
                printf("But i am sti the best, i am still the best, i am still the best, i am still the best\n");
                exit(0);
            }
            printboard(board,n);
            check(board,n);
        }
   }
}