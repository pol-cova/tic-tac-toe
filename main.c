/*
 * Created by Paul Contreras 1/12/2022
 * My first game
 * TIC TAC TOE C version
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game.h"

int main() {

    bool game = true;
    char userOption;
    char playerTurn = 'x', board[] = {'-', '-','-','-','-','-','-','-','-'};
    int turnCounter = 0;

    //Initialize main game
    game_intro();

    printf("Press c to start the game! or 'q' to quit the game\n");
    scanf("%c", &userOption);

    switch (userOption) {
        case 'c':
            while (game){
                game_board(board);
                player_input(board, &playerTurn);
                turnCounter++;

                //Check if player win!!!
                if (check_win(board)) {
                    game_board(board);
                    printf("%c Wins!!!! :)", playerTurn);
                    getchar();
                    exit(0);
                }
                //Check if draw exist!!!
                if (check_draw(turnCounter)){
                    game_board(board);
                    printf("Oh no :( this is a draw!");
                    getchar();
                    exit(0);
                }
                switch_turn(&playerTurn);
            }
        case 'q':
            exit(0);
    }

    return 0;
}
