#include "common.h"
int degak2_check(int player_t,int input1, int input2)
{
 // y=x
 
	int x_wn;
	int x_es;
	int i,j;//N�� 6�̴ϱ� 
	int d3=0;
	int d4=0;//n1+n2=���� ������ ������
//���ο��� ���̿� �� �� �ٲٴ°�  
//���� Ȯ���� ��  
for(i=1;i<6;i++)
{	if( (gameboard[input1+i][input2-i] != 0 )&& (gameboard[input1+i][input2-i] != gameboard[input1][input2]))
	//���� �ſ� �ٸ��� ������  
	{
		d3++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< d3-1;j++)
{
	 gameboard[input1+j][input2-j]==player_t;
}

//���� Ȯ���� ��
 for(i=1;i<6;i++)
{	if( gameboard[input1-i][input2+i] != 0 && gameboard[input1-i][input2+i] != gameboard[input1][input2])
	//���� �ſ� �ٸ��� ������  
	{
		d4++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< d4-1;j++)
{
	 gameboard[input1-j][input2+j]==player_t;
}

	return (d3+d4);	
}

