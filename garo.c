#include "common.h"
int garo_check(int player_t,int input1, int input2)
{
	int east;
	int west;
	int i,j;//N�� 6�̴ϱ� 
	int n1=0;
	int n2=0;//n1+n2=���� ������ ������
//���ο��� ���̿� �� �� �ٲٴ°�  
//���� Ȯ���� ��  
for(i=1;i<6;i++)
{	if( gameboard[input1][input2-i] != 0 && gameboard[input1][input2-i] != gameboard[input1][input2])
	//���� �ſ� �ٸ��� ������  
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

//���� Ȯ���� ��
 for(i=1;i<6;i++)
{	if( gameboard[input1][input2+i] != 0 && gameboard[input1][input2+i] != gameboard[input1][input2])
	//���� �ſ� �ٸ��� ������  
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


