#include "common.h"
//����  
int sero_check(int player_t,int input1, int input2)
{
	int north;
	int south;
	int i,j;//N�� 6�̴ϱ� 
	int n3=0;
	int n4=0;//n1+n2=���� ������ ������
//���ο��� ���̿� �� �� �ٲٴ°�  
//���� Ȯ���� ��  
for(i=1;i<6;i++)
{	if( gameboard[input1-i][input2] != 0 && gameboard[input1-i][input2] != gameboard[input1][input2])
	//���� �ſ� �ٸ��� ������  
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

//���� Ȯ���� ��
 for(i=1;i<6;i++)
{	if( gameboard[input1+i][input2] != 0 && gameboard[input1+i][input2] != gameboard[input1][input2])
	//���� �ſ� �ٸ��� ������  
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

