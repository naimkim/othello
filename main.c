#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�Ű��Լ� ���� 
void draw_board();//������ �׸��� 
int othello(); //�����ʱ�ȭ 
int print_othello();  // ������ �Է� �ޱ� �� ������,��ġ ���� ���, ���Ӱ��� ����ؼ� ����ڰ� �� �� �ְ� �ϴ°� 
void isGameEnd(); //game ���� ���� Ȯ��
void isBoardPlay(); //��ġ���� ĭ Ȯ�� 
void display_stone();//�����ǿ� ��,���� �� ����  
int isPlayerGB(); //�Է� ��ǥ�� �������� üũ 
int turn(); //������ ����  
int winner(); //�¸� ����
int check_result(); //��� ��� 

void main (void) {
	int gameboard[N][N];	//�ʿ��� ������ ���� : WHITE���� , BLACK����  ,6*6 ������ , �Է��� ��ǥ  
//ĭ�� ������� : 0 
	int empty = 0;
//	ĭ�� �������� ���� : 1
	int black = 1;
//	ĭ�� ����� ���� : -1
	int white = -1;
	int white_cnt;// �� �� ���� 
	int black_cnt;//���� �� ���� 
	int player1;
	int player2;
	int game_cnt=0;//turn ���� 
	int input1;
	int input2;
			
	while (isGameEnd() == 0) { //game ���� ���� Ȯ�� 
	 	 print_othello(); 
	 	 if (isBoardPlay() == 0) 
	 	 	 continue; //�� player ��� ��ġ�� �Ұ����ϸ� �ݺ����� ������������
					  	
	  		
	 			 if (isPlayerGB() == 0)
	 	 		 if ( ) {
				//turn�Լ�����  � ����������cnt���� ���; 
				// �� �ٲ� 
	 	 	 }
	 	 else
			 �������� �Է����� ���;
	game_cnt++;
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
int othello()
{//�����ʱ�ȭ : ������ - ����,�� �� 2�� �밢������ ��ġ , ��ġ���� ǥ�� �ʱ�ȭ 
print_othello();

 
 } 

int print_othello()
{	// ���� �������� �Ʒ� ��Ȳ �� ������ �ݵ�� ������� ����ڵ��� �� �� �ְ� �ؾ���
	//������ ����Ϳ� ����ؼ� O,X���� 2*2�� ���̰� �ؾ���. 
	//white = O , black = X

	gameboard[2][2] = white;
	gameboard[3][3] = white;
	gameboard[2][3] = black;
	gameboard[3][2] = black;
	
	// status : white 2, black 2 
	printf(" STATUS - WHITE : %d, BLACK : %d ", white_cnt, black_cnt);
	do{
			printf(" invalid input! (should be less than 6)\n");
 			printf(" out a new %f othello : ", order);
  			scanf(" %d %d  ",&input1, &input2);
  			}
  			while (input1<= 0 || input1>=6 || input2<=0 || input2 >=6);
 } 
  void isGameEnd()
  {//������������
   
  }
  
  void isBoardPlay()
  {
  }
  
  void display_stone()
  {
  	int i,x,y;
  	char *stone[2] = { "O", "X"};
  	
  	for (i=0; i<2; i++)
  		for (x=1; x<24; x++)
  			for ( y=1; y<24; y++)
  			{
  				
			  }
  }

int isPlayerGB(); //�Է� ��ǥ�� �������� üũ
int turn(); //������ ����  
int winner(); //�¸� ����
int check_result(); //��� ��� 
