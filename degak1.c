#include "common.h"
//�밢 
int degak1_check(int player_t,int input1, int input2)
{ // y=-x
 	int x_en;
	int x_ws;
	int i,j;//N�� 6�̴ϱ� 
	int d1=0;
	int d2=0;//n1+n2=���� ������ ������
//���ο��� ���̿� �� �� �ٲٴ°�  
//���� Ȯ���� ��  
for(i=1;i<6;i++)
{	if( gameboard[input1-i][input2-i] != 0 && gameboard[input1-i][input2-i] != gameboard[input1][input2])
	//���� �ſ� �ٸ��� ������  
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

//���� Ȯ���� ��
 for(i=1;i<6;i++)
{	if( gameboard[input1+i][input2+i] != 0 && gameboard[input1+i][input2+i] != gameboard[input1][input2])
	//���� �ſ� �ٸ��� ������  
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

