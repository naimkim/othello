#include "common.h"
//�Ű��Լ� ========================================== 
void draw_board()//������ �׸��� �Լ�
// 2/2 3/3 white 2/3 3/2 black
{	
	int i,j;

		printf("    0   1   2   3   4   5 \n");
	printf("=========================\n");
	
	for (i=0; i<N; i++)	
	{
		printf(" %d", i);
		for( j=0 ; j<N ; j++ )
		{
		printf("|%c|", gameboard[i][j]);
			switch (gameboard[i][j])
					{
						case 0:
							printf(" ");
							break;
						case 1:
							printf("X");
							break;
						case -1:
							printf("O");
							break;	
			
						default:
							break;	}
		if (j == 5)
			printf("\n");
		} 
			printf(" ----------------------\n ");
}

}

