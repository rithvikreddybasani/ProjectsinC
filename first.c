#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// This is a tic-tac-toe
char board[3][3];
const char PLAYER_1='X';
const char PLAYER_2='O';
const char COMPUTER='O';

void initialboard();
void printboard();
void player1move();
void player2move();
void computermove();
int checkfreespaces();
char checkwinner();
void printwinner(char winner);


int main(){
      int choice;
      char winner=' ';
      printf("WELCOME TO TIC TAC TOE\n\n\n");
      initialboard();
      printboard();
      printf("PLAYER_1(X)  PLAYER_2(O)  COMPUTER(O)\n");
      printf("Enter your choice: \n 1)2-PLAYER MODE\n 2)VS COMPUTER\n");
      scanf("%d", &choice);
      switch(choice){
        case 1:
        
        while(winner==' ' && checkfreespaces()!=0 ){
            
            player1move();
            printboard();
            winner=checkwinner();
            if(winner!=' ' || checkfreespaces()==0){
                break;
            }
            player2move();
            printboard();
            winner=checkwinner();
            if(winner!=' '|| checkfreespaces()==0){
                break;
            }
        }
        printboard();
        printwinner(winner);
        break;
        case 2:
         initialboard();
        while(winner==' ' && checkfreespaces()!=0 ){
            printboard();
            player1move();
            printboard();
            winner=checkwinner();
            if(winner!=' ' || checkfreespaces()==0){
                break;
            }
            computermove();
            winner=checkwinner();
            if(winner!=' '|| checkfreespaces()==0){
                break;
            }
        }
        printboard();
        printwinner(winner);
        break;
      }
    return 0;
}

void initialboard(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            board[i][j]=' ';
        }
    }
}


int checkfreespaces(){
    int freespaces=9;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=' '){
                freespaces--;
            }
        }
        
    }
    return freespaces;
}

void printboard(){
    printf(" %c | %c | %c ",board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c ",board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c \n",board[2][0],board[2][1],board[2][2]);
    printf("\n\n");

}


void player1move(){
    int x,y;
    do{
    printf("PLAYER 1: \n");
    printf("Enter the row(1-3): \n");
    scanf("%d", &x);
    x--;
    printf("Enter the column(1-3): \n");
    scanf("%d", &y);
    y--;
    if(board[x][y]!=' '){
        printf("INVALID MOVE\n");
    }
    else{
        board[x][y]=PLAYER_1;
        break;
    }


    }while(board[x][y]!=' ');
    printf("\n\n");

}

void player2move(){
    int x,y;
    do{
    printf("PLAYER 2: \n");
    printf("Enter the row(1-3): \n");
    scanf("%d", &x);
    x--;
    printf("Enter the column(1-3): \n");
    scanf("%d", &y);
    y--;
    if(board[x][y]!=' '){
        printf("INVALID MOVE\n");
    }
    else{
        board[x][y]=PLAYER_2;
        break;
    }


    }while(board[x][y]!=' ');
    printf("\n\n");
}


void computermove(){
    srand(time(0));
      int x,y;
    if(checkfreespaces!=0){
        do{
        x=rand()%3;
        y=rand()%3;
       
    }while(board[x][y]!=' ');
    board[x][y]=COMPUTER;
    }
    
    else{
        printwinner(' ');
    }
    printf("\n\n");
    
}


char checkwinner(){
    for(int i=0;i<3;i++){
        if(board[i][0]==board[i][1]  && board[i][0]==board[i][2]){
            return board[i][0];
        }
    }
    for(int j=0;j<3;j++){
        if(board[0][j]==board[1][j]  && board[0][j]==board[2][j]){
            return board[0][j];
        }
    }
        if(board[0][0]==board[1][1]  && board[0][0]==board[2][2]){
            return board[0][0];
        }
        else if(board[0][2]==board[1][1]  && board[0][2]==board[2][0]){
            return board[0][2];
        }
        else{
            return ' ';
        }
    
}


void printwinner(char winner){
    if(winner==PLAYER_1){
        printf("YOU WIN!\n");
    }
    else if(winner==PLAYER_2){
        printf("YOU LOSE!\n");
    }
    else{
        printf("DRAWN!\n");
    }

}