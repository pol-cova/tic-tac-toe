//
// Created by Paul Contreras on 01/12/22.
//

#include <stdio.h>
#include <stdbool.h>

void game_intro(){
    printf("TIC TAC TOE\n");
    printf("Developed by Paul Conteras\n");
    printf("1 / 12 / 2022\n");
    system("clear");
}

void game_board(char board[]){
    int i;
    for (i = 0; i < 9; ++i)
    {
        printf("%c", board[i]);
        if (((i + 1)%3) == 0)
        {
            printf("\n");
        }
    }
}

void player_input(char board[], char *playerTurn){
    int index;
    printf("Turn of %c\nEnter index : ", *playerTurn);
    scanf("%d", &index);
    board[index - 1] = *playerTurn;
}

void switch_turn(char *playerTurn){
    if (*playerTurn == 'x'){
        *playerTurn = 'o';
    } else {
        *playerTurn = 'x';
    }
}

bool check_win(char board[]) {
    bool win = false;

    //Horizontal 1
    if (board[0] != '-') {
        if (board[0] == board[1]) {
            if (board[0] == board[2]) {
                win = true;
            }
        }
    }
    //Horizontal 2
    if (board[3] != '-') {
        if (board[3] == board[4]) {
            if (board[3] == board[5]) {
                win = true;
            }
        }
    }
    //Horizontal 3
    if (board[6] != '-') {
        if (board[6] == board[7]) {
            if (board[6] == board[8]) {
                win = true;
            }
        }
    }

    //Vertical 1
    if (board[0] != '-') {
        if (board[0] == board[3]) {
            if (board[0] == board[6]) {
                win = true;
            }
        }
    }
    //Vertical 2
    if (board[1] != '-') {
        if (board[1] == board[4]) {
            if (board[1] == board[7]) {
                win = true;
            }
        }
    }
    //Vertical 3
    if (board[2] != '-') {
        if (board[2] == board[5]) {
            if (board[2] == board[8]) {
                win = true;
            }
        }
    }

    //Diagonal 1
    if (board[0] != '-') {
        if (board[0] == board[4]) {
            if (board[0] == board[8]) {
                win = true;
            }
        }
    }
    //Diagonal 2
    if (board[2] != '-') {
        if (board[2] == board[4]) {
            if (board[2] == board[6]) {
                win = true;
            }
        }
    }

    return win;
}

bool check_draw(int turnCounter) {
    if (turnCounter < 9) {
        return false;
    }
    else {
        return true;
    }
}