#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�Ű��Լ� ���� ?
int draw_othello;//������ �����   
int print_othello();  // ������ �Է� �ޱ� �� ������,��ġ ���� ���, ���Ӱ��� ����ؼ� ����ڰ� �� �� �ְ� �ϴ°� 
int isGameEnd(); //game ���� ���� Ȯ��
int isBoardPlay(); //��ġ���� ĭ Ȯ�� 
int turn(); //�� ������, �� ���� �˻��� ��   
int garo_check();//����  ���� �� �ٲٱ�  
int sero_check();
int degak1_check(); // y=-x
int degak2_check(); // y=x


void main (void) {	//�ʿ��� ������ ���� : WHITE���� , BLACK����  ,6*6 ������ , �Է��� ��ǥ  
//ĭ�� ������� : 0 
	int empty = 0;
//	ĭ�� �������� ���� : 1 : X
	int black = 1;
//	ĭ�� ����� ���� : -1 : O
	int white = -1;	

	int player_cnt;// ���� turn �� ���� 
	int player_t;//������ 1 Ʋ���� 0 != == 
	int game_cnt;//turn ����
	int pass_cnt=0; 
	int input1;
	int input2;
	
	//���� ���� � �������� �����ϴ� ���� turn�� �ϳ� ����
	//�����ʱ�ȭ 
	int gameboard[N][N] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,-1,1,0,0},
	{0,0,1,-1,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};
	game_cnt = 1;	
	while (isGameEnd() == 0) { //game ���� ���� Ȯ�� 
	 	 print_othello(); 
	 	 if (isBoardPlay() == 1) 
	 	 	{ //�� player ��� ��ġ�� �Ұ����ϸ� �ݺ����� ������������
			
 			printf(" out a new %f othello : ", player_t);
  			scanf(" %d %d  ",&input1, &input2); 
				  
	 	 	if ( input1<= 0 || input1>=6 || input2<=0 || input2 >=6 ) {  
			//�����ֽ� ����� ���, �� ĭ�� ���� ���� �迭��� ���� �°� O Ȥ�� X Ȥ�� �� ĭ���� ����� �ϸ� �˴ϴ�. 
					switch (gameboard[input1][input2])
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
							break;	
					}}
			else{
				printf(" invalid input! (should be less than 6)\n");
				//turn�Լ�����  � ����������cnt���� ���; 
				// �� �ٲ�
				if(isGameEnd == 0 && player_t == -1) 
					player_t = 1;
				else if(isGameEnd == 0 && player_t == 1)
					player_t = -1; 
	 	 	 }}
	 	 else if (isBoardPlay() == 0) 
			{
			  pass_cnt++;
			  continue; 
			if(isGameEnd == 0 && player_t == -1) 
				player_t = 1;
			else if(isGameEnd == 0 && player_t == 1)
				player_t = -1;
			 
				 
			}
			 
	//�� ������   			
	turn();
	game_cnt++;
	}
	if((game_cnt != 0) && (game_cnt % 2 == 0))

        {
			printf("winner is black");
			printf("black count is %d", player_cnt);
			
        }

        else if(game_cnt % 2 == 1) 

        {	printf("winner is white");
			printf("white count is %d", player_cnt);
			

        }

        else

               printf( " 0 \n" );
}

int draw_board()//������ �׸��� �Լ�
// 2/2 3/3 white 2/3 3/2 black
{	int gameboard[N][N] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};
	int i,j;

	printf("   0  1  2  3  4  5 \n");
	printf("=========================\n");
	
	for (i=0; i<N; i++)	
	{
		printf(" %d", i);
		for( j=0 ; j<N ; j++ )
		{
		printf("|%c|", gameboard[i][j]);	
		if (j == 5)
			printf("\n");
		} 
			printf(" ----------------------\n ");
	
	}
}

int print_othello(int player_cnt, int player_t, int game_cnt, int pass_cnt)
{	// ���� �������� �Ʒ� ��Ȳ �� ������ �ݵ�� ������� ����ڵ��� �� �� �ְ� �ؾ���
	//������ ����Ϳ� ����ؼ� O,X���� 2*2�� ���̰� �ؾ���.
	turn();
	int total_flip;
	//�� white = O , black = X
	int a;
	a = draw_board();
	printf("%f",a);
	//�˰���  status : white 2, black 2 
	if(player_t == -1)
		printf(" STATUS - WHITE : %d, BLACK : %d ", player_cnt, game_cnt-pass_cnt - player_cnt);
	else if (player_t == 1)
		printf(" STATUS - WHITE : %d, BLACK : %d ", game_cnt-pass_cnt - player_cnt, player_cnt);		
  	//��ġ ��� ���⺰ ���������� �� ����, �ѵ������� �˰��� 
  	
  	
	
	return total_flip;
 } 

  
int isGameEnd(int pass_cnt, int gameboard[N][N], int player_cnt) 
  {//������������
   //  isBoardPlay == 1�̸�  ����  
  //1 . ĭ�� ��� ����.  
  //2. ��� ���� �Ѱ��� ����� ���ϵȴ�.
  //3.���� player ��� �����Ⱑ ������ ĭ�� ���� ��� 
  int i,j;
  int x;
 
while(x==1)
{
  for(i=0; i<6; i++)
  {
  	for(j=0;j<6;j++)
  	{
  		if(	gameboard[i][j] == gameboard[i][j+1])
  				x= 1; 
  		else if ( gameboard[i][j] != 0 )
  			x = 1;
  		else if ( pass_cnt == 2 || player_cnt == 0 )
  			x = 1;	
  		else
	  		x = 0;
  		//break �ΰ� continue �ΰ�!!!!!!! �����ΰ�!!!!!! 
  	}
  	if(x==0)
  		break;
  	else if (x==1)
  		continue;
  }
}
  return x;
  }  


//isboardplay �� 0�̸� pass 
int isBoardPlay(int gameboard[N][N], int flip_cnt)
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
   if(flip_cnt ==0 || cnt == 36)
   		return 1;
	else 
  		 return 0;
  
   
int garo_check(int player_t,int input1, int input2, int gameboard[N][N])
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

//����  
int sero_check(int player_t,int input1, int input2, int gameboard[N][N])
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
//�밢 
int degak1_check(int player_t,int input1, int input2, int gameboard[N][N])
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

int degak2_check(int player_t,int input1, int input2, int gameboard[N][N])
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
{	if( gameboard[input1+i][input2-i] != 0 && gameboard[input1+i][input2-i] != gameboard[input1][input2])
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
int turn(int player_t, int gameboard[N][N], int game_cnt, int input1, int input2)
{ //������ ����   
//�� ���� ����  
//���� ���� �밢��1, �밢��2 
	int empty = 0;
	int east;
	int west;
	int north;
	int south;
	int x_en;
	int x_es;
	int x_wn;
	int x_ws; 
	int garo_cnt;
	int sero_cnt;
	int degak1_cnt;
	int degak2_cnt;
	int player_cnt;
	int playerAcnt; 
	int a,b,c,d; 
 
 while ( gameboard[input1][input2] == player_t)//22 --11,12,13,23,33,32,31,21
 {
 
 	if( gameboard[input1-1][input2-1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
			gameboard[input1-1][input2-1] =  gameboard[input1][input2] ;  
 		x_en++; 
}
 	else if( gameboard[input1-1][input2] != empty || gameboard[input1-1][input2-1] != player_t  )
 	{
		 	gameboard[input1-1][input2] = gameboard[input1][input2] ;
		north++; 
}
 	else if(gameboard[input1-1][input2+1] != empty || gameboard[input1-1][input2-1] != player_t )
	 {
			 gameboard[input1-1][input2+1] =  gameboard[input1][input2] ;
	 	 x_wn++; 
}
	else if( gameboard[input1][input2+1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
	 	gameboard[input1][input2+1] =  gameboard[input1][input2] ; 
 		west++; 
 }
 	else if( gameboard[input1+1][input2+1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
		 	gameboard[input1+1][input2+1] =  gameboard[input1][input2] ;
		x_ws++;  
 }
 	else if(gameboard[input1+1][input2] != empty || gameboard[input1-1][input2-1] != player_t )
	{
		 	gameboard[input1+1][input2] =  gameboard[input1][input2] ;
	 	south++; 
}
	else if( gameboard[input1+1][input2-1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
		 	gameboard[input1+1][input2-1] =  gameboard[input1][input2] ;  
 		x_es++; 
 }
 	else if( gameboard[input1][input2-1] != empty|| gameboard[input1-1][input2-1] != player_t )
 	{
		 	gameboard[input1][input2-1] =  gameboard[input1][input2] ; 
		east++;
 }
 	else
 	
 		break;
 
 }	
playerAcnt = east+west+north+south+x_en +x_es+x_wn+x_ws;//������ �� ���� ���� ����������   
 //���� �� �ٲٰ� ������ return��Ű�� �Լ�
  //int player_t,int input1, int input2, int gameboard[N][N]
a= garo_check();  
b= sero_check();
c= degak1_check(); 
d= degak2_check(); 

player_cnt = a+ b+ c+d + playerAcnt;
	if(game_cnt>1)
	{ printf("::flip result:: \n");
		 printf("E : %d, W : %d, N : %d, S : %d, NE : %d, SE : %d, NW : %d, SW : %d\n", east, west, north, south, x_en, x_es, x_wn, x_ws);
		printf("you has flipped %d othellos! ", east+west+north+south+x_en +x_es+x_wn+x_ws+garo_cnt+sero_cnt+degak1_cnt+degak2_cnt);
 	 }
		
	return player_cnt; 
	 
}


