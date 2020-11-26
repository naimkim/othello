#include "common.h"

//isboardplay 가 0이면 pass 
int isBoardPlay( int player_cnt)
  {//배치 가능 칸이 있는지 확인   있으면 1 없으면 0 
   //알이 없는 칸인가
   int i,j;
   int cnt=0;// cnt 가 36이 되면 배치가능한 칸 없음  
   
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

