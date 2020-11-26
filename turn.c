#include "common.h"


int turn(int player_t, int game_cnt, int input1, int input2)
{ //뒤집는 조건   
//돌 개수 세기  
//가로 세로 대각선1, 대각선2 
	int empty = 0;
	int east;
	int west;
	int north;
	int south;
	int x_en;
	int x_es;
	int x_wn;
	int x_ws; 
	int garo_cnt;
	int sero_cnt;
	int degak1_cnt;
	int degak2_cnt;
	int player_cnt;
	int playerAcnt;
	int flip_cnt; 
	int a,b,c,d; 
 
 while ( gameboard[input1][input2] == player_t)//22 --11,12,13,23,33,32,31,21
 {
 
 	if( gameboard[input1-1][input2-1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
			gameboard[input1-1][input2-1] =  gameboard[input1][input2] ;  
 		x_en++; 
}
 	else if( gameboard[input1-1][input2] != empty || gameboard[input1-1][input2-1] != player_t  )
 	{
		 	gameboard[input1-1][input2] = gameboard[input1][input2] ;
		north++; 
}
 	else if(gameboard[input1-1][input2+1] != empty || gameboard[input1-1][input2-1] != player_t )
	 {
			 gameboard[input1-1][input2+1] =  gameboard[input1][input2] ;
	 	 x_wn++; 
}
	else if( gameboard[input1][input2+1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
	 	gameboard[input1][input2+1] =  gameboard[input1][input2] ; 
 		west++; 
 }
 	else if( gameboard[input1+1][input2+1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
		 	gameboard[input1+1][input2+1] =  gameboard[input1][input2] ;
		x_ws++;  
 }
 	else if(gameboard[input1+1][input2] != empty || gameboard[input1-1][input2-1] != player_t )
	{
		 	gameboard[input1+1][input2] =  gameboard[input1][input2] ;
	 	south++; 
}
	else if( gameboard[input1+1][input2-1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
		 	gameboard[input1+1][input2-1] =  gameboard[input1][input2] ;  
 		x_es++; 
 }
 	else if( gameboard[input1][input2-1] != empty|| gameboard[input1-1][input2-1] != player_t )
 	{
		 	gameboard[input1][input2-1] =  gameboard[input1][input2] ; 
		east++;
 }
 	else
 	
 		break;
 
 }	
playerAcnt = east+west+north+south+x_en +x_es+x_wn+x_ws;//뒤집은 돌 개수 세고 빠져나오기   
 //낑긴 돌 바꾸고 갯수를 return시키는 함수
  //int player_t,int input1, int input2, int gameboard[N][N]

a= garo_check(player_t, input1, input2, gameboard[N][N]);  
b= sero_check(player_t, input1, input2, gameboard[N][N]);
c= degak1_check(player_t, input1, input2, gameboard[N][N]); 
d= degak2_check(player_t, input1, input2, gameboard[N][N]); 

flip_cnt = a+ b+ c+d + playerAcnt;
	if(game_cnt>1)
	{ printf("::flip result:: \n");
		 printf("E : %d, W : %d, N : %d, S : %d, NE : %d, SE : %d, NW : %d, SW : %d\n", east, west, north, south, x_en, x_es, x_wn, x_ws);
		printf("you has flipped %d othellos! ", flip_cnt);
 }
		
	return flip_cnt;   
}
