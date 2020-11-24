#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�Ű��Լ� ���� ?
int draw_othello;//������ �����  
int initial_othello(); //�����ʱ�ȭ 
int print_othello();  // ������ �Է� �ޱ� �� ������,��ġ ���� ���, ���Ӱ��� ����ؼ� ����ڰ� �� �� �ְ� �ϴ°� 
int isGameEnd(); //game ���� ���� Ȯ��
int isBoardPlay(); //��ġ���� ĭ Ȯ�� 
int turn(); //�� ������, �� ���� �˻��� ��  
int check_result(); //��� ��� 


void main (void) {
	int gameboard[N][N];	//�ʿ��� ������ ���� : WHITE���� , BLACK����  ,6*6 ������ , �Է��� ��ǥ  
//ĭ�� ������� : 0 
	int empty = 0;
//	ĭ�� �������� ���� : 1 : X
	int black = 1;
//	ĭ�� ����� ���� : -1 : O
	int white = -1;	

	int white_cnt;// �� �� ���� 
	int black_cnt;//���� �� ���� 
	int player1;
	int player2;
	int player_t = 1;//player���� p1 : 1 ; p2 : 2 
	int game_cnt;//turn ���� 
	int input1;
	int input2;
	int whiteblack;//white�������� black��������  
	
	initial_othello();	//�����ʱ�ȭ 	
	while (isGameEnd() == 0) { //game ���� ���� Ȯ�� 
	 	 print_othello(); 
	 	 if (isBoardPlay() == 0) 
	 	 	 continue; //�� player ��� ��ġ�� �Ұ����ϸ� �ݺ����� ������������
			
 			printf(" out a new %f othello : ", order);
  			scanf(" %d %d  ",&input1, &input2); 
				  	
	 	 	if ( input1<= 0 || input1>=6 || input2<=0 || input2 >=6 ) {  
			//�� .. �̰� �ƴѰŰ�����.. ����  
			//�����ֽ� ����� ���, �� ĭ�� ���� ���� �迭��� ���� �°� O Ȥ�� X Ȥ�� �� ĭ���� ����� �ϸ� �˴ϴ�. 
					switch (gameboard[input1][input2])
					{
						case 0:
							printf(" ");
							break;
						case 1;
							printf("X");
							break;
						case -1:
							printf("O");
							break;	
			
						default:
							break;	
					}		
				//turn�Լ�����  � ����������cnt���� ���; 
				// �� �ٲ� 
	 	 	 }
	 	 else
			 printf(" invalid input! (should be less than 6)\n");
			 
			 
	game_cnt++;
	//���� �ٲٱ�, �� �ٲٱ�  
	if(isGameEnd == 0 && player_t == 1) 
		player_t = 2;
	else if(isGameEnd == 0 && player_t == 2)
		player_t = 1;
	else 
		break;
			
	turn();
	}	
	check_result(); //��� ��� 
}

void draw_board(int c, int r)//������ �׸��� �Լ�
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

	printf("    0 1 2 3 4 5");
	printf("==============");
	
	for (i=0; i<N; i++)	
	{
		printf(" %d", i);
		for( j=0 ; j<N ; j++ )
		{
		printf("|%c|", gameboard[i][j]);
		
		printf(" ----------------------\n ");	
	
		 } 
	}
	
int initial_othello()
{//�����ʱ�ȭ : ������ 2,2 3,3 2,3 3,2���� ��ĭ���� , ī���� �� 0����,  
int gameboard[N][N] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,-1,1,0,0},
	{0,0,1,-1,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};
	
	int white_cnt = 2;
	int black_cnt = 2;
	int game_cnt=1;
 
 } 

int print_othello(int input1, int input2)
{	// ���� �������� �Ʒ� ��Ȳ �� ������ �ݵ�� ������� ����ڵ��� �� �� �ְ� �ؾ���
	//������ ����Ϳ� ����ؼ� O,X���� 2*2�� ���̰� �ؾ���.
	int east;
	int west;
	int north;
	int south;
	int x_en;
	int x_es;
	int x_wn;
	int x_ws; 
	//�� white = O , black = X
	printf("%d", drawboard());  
	//�˰���  status : white 2, black 2 
	printf(" STATUS - WHITE : %d, BLACK : %d ", white_cnt, black_cnt);
			
  	//��ġ ��� ���⺰ ���������� �� ����, �ѵ������� �˰��� 
  	if(game_cnt>1)
		 printf("::flip result:: \n");
		 printf("E : %d, W : %d, N : %d, S : %d, NE : %d, SE : %d, NW : %d, SW : %d\n", east, west, north, south, x_en, x_es, x_wn, x_ws);
	 	 printf("you has flipped %d othellos! ", east+west+north+south+x_en +x_es+x_wn+x_ws);
  	else
  		break;
  		
 } 
  
int isBoardPlay()
  {//��ġ ���� ĭ ����  
   //���� ���� ĭ�ΰ�
   int gameboard[N][N];
   
   if(gameboard[input1][input2]==0) {
   		if(turn != 0)
   			return 1;
   		else
   			break;
 	else 
 		return 0;
   }		
   	//pass �ȴ�. turn�ٲ��.  ��������. 
   			
  }
  
int isGameEnd()
  {//������������
   //  isBoardPlay == 0; 
  //1 . ĭ�� ��� ����.  
  //2. ��� ���� �Ѱ��� ����� ���ϵȴ�.
  //3.���� player ��� �����Ⱑ ������ ĭ�� ���� ��� �̰��� ����. 
  int i,j;
  int x;
 
while(x==0)
  for(i=0; i<7; i++)
  {
  	for(j=0<j<7;j++)
  	{
  		if(	gameboard[i][j] == gameboard[i][j+1])
  			x = 0;
  			break; 
  		else if ( gameboard[i][j] != 0 )
  			x = 0;
  			break;
  		else if ( turn == 0 )
  			x = 0;
  			break;	
  		else
	  		x = 1;
	  		break;
  		//break �ΰ� continue �ΰ�!!!!!!! �����ΰ�!!!!!!! 
  	}
  }
  return x;
  }  
  
  /*
int horizontal_check()
{
//���ο��� ������ �� �˻�
int east;
int west;
int hori_cnt=0;//���� ������ �� 
	while( east != 0 || west != 0)
		if(���� �÷��̾�� != ���� �� ) 
			���� �� == ���� �÷��̾��;
			hori_cnt++;
		else if (���� �÷��̾�� == ���� �� ) 
			continue; 
		
}*/
int turn(int player_t)
{ //������ ����   
//���� ���� �밢��1, �밢��2 
 int gameboard[input1][input2];
 if ( player_t == 1)//22 --11,12,13,23,33,32,31,21
 	if( gameboard[input1-1][input2-1] != 0 )
 		gameboard[input1-1][input2-1] = white;  
 		break;
 	if( gameboard[input1-1][input2] != 0 )
 		gameboard[input1-1][input2] = white;  
 		break;
 		
 	gameboard[input1-1][input2+1] = white;
 	gameboard[input1][input2+1] = white; 
 	gameboard[input1+1][input2+1] = white;
 	gameboard[input1+1][input2] = white;
 	gameboard[input1+1][input2-1] = white; 
 	gameboard[input1][input2-1] = white;
 	 
 else if ( player_t == 2)
 	gameboard[input1-1][input2-1] = black; //33
 	gameboard[input1-1][input2] = black;
 	gameboard[input1-1][input2+1] = black;
 	gameboard[input1][input2+1] = black; 
 	gameboard[input1+1][input2+1] = black;
 	gameboard[input1+1][input2] = black;
 	gameboard[input1+1][input2-1] = black; 
 	gameboard[input1][input2-1] = black;
else

int horizontal_check();//���ο��� ������ �� �˻�
int vertical_check();//���ο��� ������ �� �˻�
int diagonal1_check();  // �밢��1 �˻� y= x
int diagonal2_check();  // �밢��2 �˻� y= -x	
 	
 return gameboard[N][N];
}
int check_result()
{ //��� ��� 

printf("���� ��� : �̱��� : %c, �̱� ��� �� ���� : %d", winner, winner_cnt);
}
