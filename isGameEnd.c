#include "common.h"

extern int gameboard[N][N];

int isGameEnd(int pass_cnt,  int player_cnt, int flip_cnt, int game_cnt) 
  {//������������
   //  isBoardPlay == 1�̸�  ����  
  //1 . ĭ�� ��� ����.  
  //2. ��� ���� �Ѱ��� ����� ���ϵȴ�.
  //3.���� player ��� �����Ⱑ ������ ĭ�� ���� ��� 
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

