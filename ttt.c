#include <stdio.h>
#include <stdlib.h>
#include "ttt_func.h"  

int main(){
	char board[10]="         ";//10 instead of 9 to make room for \0 (null terminator)
	int move;
	int game_over=0;
	int repeat=0;
	
	board_print(board);
	
	while(game_over==0){//Print board->My move-> Print board->game_over check->ai's move->game_over check (prints on loop restart or in victory if statement
	//board[0]='O';//test
		
		//Move selection
		printf("X, Make a move (1-9): ");
		scanf("%d",&move);
		getchar();
		printf("\n");
		//wrong input test
		while(board[move-1]!=32){//32 is dec for (space)
			printf("Select an unused space: ");
			scanf("%d",&move);
			getchar();
			printf("\n");
		}
		
		board[move-1]='X';
		board_print(board);
		game_over=check_win(board,0);
		
		if(game_over==0){//Skips turn if game is over
			
			//AI's turn
			move=ai_move_decide(board,move);
			while(board[move-1]!=32){
				move=ai_move_decide(board,move);
			}

			board[move-1]='O';
			board_print(board);
			game_over=check_win(board,1);
		}
	}

	return 0;
}


