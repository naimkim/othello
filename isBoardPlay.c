#include "common.h"

//isboardplay �� 0�̸� pass 
int isBoardPlay( int player_cnt)
  {//��ġ ���� ĭ�� �ִ��� Ȯ��   ������ 1 ������ 0 
   //���� ���� ĭ�ΰ�
   int i,j;
   int cnt=0;// cnt �� 36�� �Ǹ� ��ġ������ ĭ ����  
   
   for(i=0;i<6;i++)
   {
   		for(j=0;j<6;j++)
   		{
   			if(gameboard[i][j]==0)
   				break;
   			else
   				cnt++;
   				continue;
		   }
   }
   
   if(player_cnt ==0 || cnt == 36)
   		return 0;
	else 
  		return 1;
  
}

