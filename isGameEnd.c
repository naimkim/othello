#include "common.h"

extern int gameboard[N][N];

int isGameEnd(int pass_cnt,  int player_cnt, int flip_cnt, int game_cnt) 
  {//������������
   //  isBoardPlay == 1�̸�  ����  
  //1 . ĭ�� ��� ����.  
  //2. ��� ���� �Ѱ��� ����� ���ϵȴ�.
  //3.���� player ��� �����Ⱑ ������ ĭ�� ���� ��� 
  int i,j;
 
  
 	if	(player_cnt == 36)
  		{
			printf("1"); 
  			//break; 
		}
  	
  	else if ( (pass_cnt == 2 )||( flip_cnt == 0 ))
  		{
		printf("1"); 
			//break; 
		}
	else
		{
		printf("0"); 
		}
			
  return 0;
  }  

