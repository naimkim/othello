#include "common.h"
//세로  
int sero_check(int player_t,int input1, int input2)
{
	int north;
	int south;
	int i,j;//N은 6이니까 
	int n3=0;
	int n4=0;//n1+n2=가로 뒤집은 돌개수
//가로에서 사이에 낀 돌 바꾸는거  
//동쪽 확인할 때  
for(i=1;i<6;i++)
{	if( gameboard[input1-i][input2] != 0 && gameboard[input1-i][input2] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		n3++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< n3-1;j++)
{
	 gameboard[input1-j][input2]==player_t;
}

//서쪽 확인할 때
 for(i=1;i<6;i++)
{	if( gameboard[input1+i][input2] != 0 && gameboard[input1+i][input2] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		n4++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< n4-1;j++)
{
	 gameboard[input1+j][input2]==player_t;
}

	return (n3+n4);	
}

