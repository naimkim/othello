#include "common.h"

extern int gameboard[N][N];

int isGameEnd(int pass_cnt,  int player_cnt, int flip_cnt) 
  {//������������
   //  isBoardPlay == 1�̸�  ����  
  //1 . ĭ�� ��� ����.  
  //2. ��� ���� �Ѱ��� ����� ���ϵȴ�.
  //3.���� player ��� �����Ⱑ ������ ĭ�� ���� ��� 
  int i,j;
  int x;
 

  for(i=0; i<6; i++)
  {
  	for(j=0;j<6;j++)
  	{
  		if ( gameboard[i][j] != 0 )
  		{
			x = 1;
  			continue; }
  	
  		else
	  	{
			x = 0;
	  		break; }
  	}
  }
  
 	if(	player_cnt == 36)
  		{
			x = 1; 
  			//break; 
		}
  			
  	else if ( pass_cnt == 2 || flip_cnt == 0 )
  		{
			x = 1;
			//break; 
		}
				


  return x;
  }  

