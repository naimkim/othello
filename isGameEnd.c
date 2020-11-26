#include "common.h"

extern int gameboard[N][N];

int isGameEnd(int pass_cnt,  int player_cnt, int flip_cnt, int game_cnt) 
  {//게임종료조건
   //  isBoardPlay == 1이면  종료  
  //1 . 칸이 모두 찬다.  
  //2. 모든 알이 한가지 색깔로 통일된다.
  //3.양쪽 player 모두 뒤집기가 가능한 칸이 없는 경우 
  int i,j;
  int x;
 
  
 	if(	(player_cnt == 36) || (game_cnt >= 36))
  		{
			x = 1; 
  			//break; 
		}
  	
	
  	else if ( (pass_cnt == 2 )||( flip_cnt == 0 ))
  		{
			x = 1;
			//break; 
		}
	else
		{
			x = 0;
		}
			
  return x;
  }  

