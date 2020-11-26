#include "common.h"
int garo_check(int player_t,int input1, int input2)
{
	int east;
	int west;
	int i,j;//N은 6이니까 
	int n1=0;
	int n2=0;//n1+n2=가로 뒤집은 돌개수
//가로에서 사이에 낀 돌 바꾸는거  
//동쪽 확인할 때  
for(i=1;i<6;i++)
{	if( gameboard[input1][input2-i] != 0 && gameboard[input1][input2-i] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		n1++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< n1-1;j++)
{
	 gameboard[input1][input2-j]==player_t;
}

//서쪽 확인할 때
 for(i=1;i<6;i++)
{	if( gameboard[input1][input2+i] != 0 && gameboard[input1][input2+i] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		n2++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< n2-1;j++)
{
	 gameboard[input1][input2+j]==player_t;
}

	return (n1+n2);
}


