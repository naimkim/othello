#include "common.h"
//대각 
int degak1_check(int player_t,int input1, int input2)
{ // y=-x
 	int x_en;
	int x_ws;
	int i,j;//N은 6이니까 
	int d1=0;
	int d2=0;//n1+n2=가로 뒤집은 돌개수
//가로에서 사이에 낀 돌 바꾸는거  
//동쪽 확인할 때  
for(i=1;i<6;i++)
{	if( gameboard[input1-i][input2-i] != 0 && gameboard[input1-i][input2-i] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		d1++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< d1-1;j++)
{
	 gameboard[input1-j][input2-j]==player_t;
}

//서쪽 확인할 때
 for(i=1;i<6;i++)
{	if( gameboard[input1+i][input2+i] != 0 && gameboard[input1+i][input2+i] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		d2++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< d2-1;j++)
{
	 gameboard[input1+j][input2+j]==player_t;
}

	return (d1+d2);
}

