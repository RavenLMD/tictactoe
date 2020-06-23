#include <stdio.h>  
#include <stdlib.h>
#include "ttt_func.h"  

void board_print(char board[10]){
	//Board printing
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\n %c | %c | %c \n",board[0],board[1],board[2]);
	printf("------------\n");
	printf(" %c | %c | %c \n",board[3],board[4],board[5]);
	printf("------------\n");
	printf(" %c | %c | %c \n\n",board[6],board[7],board[8]);
}

int ai_move_decide(char board[10],int move){
		int ai_move=(rand() % 9);
		//if()
		//if()
	return ai_move;
}

int check_win(char board[10],int last_move_made){
	int game_over=2;
	//int space_left=1;
	int i=0;
	//printf("\n%d %d %d\n",board[0], board[1], board[2]);
	
	//Checks for a tie
	//while((space_left==1)&&(i<9)){
		for(int i=0;i<9;i++){
			if(board[i]==32)
			game_over=0;
		}
	//}
	for(int i=0;i<9;i+=3){//Horizontal check
		if((board[i]==board[i+1])&&(board[i]==board[i+2])&&(board[i]!=32))   {//&&(board[i]!=32)){
			//printf("test case 1");
			game_over=1;
		}
	}
	for(int i=0;i<3;i++){//Vertical check
		if((board[i]==board[i+3])&&(board[i]==board[i+6])&&(board[i]!=32)){
			//printf("test case 2");
			game_over=1;
		}
	}
	if((board[0]==board[4])&&(board[0]==board[8])&&(board[0]!=32)){//Diagnol checks [(1-1),(5-1),(9-1)]
	//printf("test case 3");
		game_over=1;
	}
	if((board[2]==board[4])&&(board[2]==board[6])&&(board[2]!=32)){//[(3-1),(5-1),(7-1) checks if its unfilled
	//printf("test case 4");
		game_over=1;
	}
	
	
	
	//Prints at end of game
	if(game_over==1){
		if(last_move_made==0){
			printf("\nYou Win :D\a\n\n");
		}
		else{
			printf("\nThe AI wins!\a\n\n");
		}
	}
	else if(game_over==2){
		printf("Tie!\a\n\n");
	}
	return game_over;
}
