#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�Ű��Լ� ���� ?
int initial_othello(); //�����ʱ�ȭ 
int print_othello();  // ������ �Է� �ޱ� �� ������,��ġ ���� ���, ���Ӱ��� ����ؼ� ����ڰ� �� �� �ְ� �ϴ°� 
void isGameEnd(); //game ���� ���� Ȯ��
void isBoardPlay(); //��ġ���� ĭ Ȯ�� 
int order(); //���� �Դٰ��ٸ� ��� ����ϱ�!!!!! 
int turn(); //������ ����  
int winner(); //�¸� ����
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
	int game_cnt;//turn ���� 
	int input1;
	int input2;
	int whiteblack;//white�������� black��������  
	
	
	initial_othello();	//�����ʱ�ȭ 	
	while (isGameEnd() == 0) { //game ���� ���� Ȯ�� 
	 	 print_othello(); 
	 	 if (isBoardPlay() == 0) 
	 	 	 continue; //�� player ��� ��ġ�� �Ұ����ϸ� �ݺ����� ������������
					  	
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
int initial_othello()
{//�����ʱ�ȭ : ������ 0���� , ���� ī���õ� 0����,  
	int gameboard[N][N] = 0;
	gameboard[2][2] = white;
	gameboard[3][3] = white;
	gameboard[2][3] = black;
	gameboard[3][2] = black;
	
	int game_cnt=1;
 
 } 

int print_othello(int input1, int input2)
{	// ���� �������� �Ʒ� ��Ȳ �� ������ �ݵ�� ������� ����ڵ��� �� �� �ְ� �ؾ���
	//������ ����Ϳ� ����ؼ� O,X���� 2*2�� ���̰� �ؾ���. 
	//�� white = O , black = X
	printf("%d", gameboard);  
	//�˰���  status : white 2, black 2 
	printf(" STATUS - WHITE : %d, BLACK : %d ", white_cnt, black_cnt);
	//turn pass�ƴ���!
	printf("pass�Ǹ� 1�� ��� : %d", turn_pass); 
	do{
			printf(" invalid input! (should be less than 6)\n");
 			printf(" out a new %f othello : ", order);
  			scanf(" %d %d  ",&input1, &input2);
  			}
  			while (input1<= 0 || input1>=6 || input2<=0 || input2 >=6);
  			
  	//��ġ ��� ���⺰ ���������� �� ����, �ѵ������� �˰��� 
	 printf("east : %d, north : %d, south : %d, x_en : %d, x_es : %d, x_wn : %d, x_ws : %d\n", east, west, north, south, x_en, x_es, x_wn, x_ws);
	 
	 printf("total turning counting : %d", east+west+north+south+x_en+x_es+x_wn+x_ws);
  	
  	//���� ���� �� ������� : check_result �Լ� �־ ���⼭ ����� �ʿ� ���� �ʽ��ϱ�.?  
	   
  	return input1;
  	return input2;
 } 
  
  void isBoardPlay()
  {//��ġ ���� ĭ ����  
   //���� ���� ĭ�ΰ�
   int gameboard[N][N];
   
   if(gameboard[input1][input2]==0) 
   		if(order == black )
   			gameboard[input1][input2] = 1;
   		else
   			gameboard[input1][input2] = -1;
   			
   	else 
   	turn_pass++;
   	break;//pass �ȴ�. turn�ٲ��.  ��������. 
   			
  }
  
void isGameEnd()
  {//������������
   //  isBoardPlay == 0; 
  //1 . ĭ�� ��� ����. 
  if(gameboard[N][N] != 0) 
  //2. ��� ���� �Ѱ��� ����� ���ϵȴ�.
  int i,j;
  while(1) 
  { 
  for(i=0<i<7;i++){
  	for(j=0<j<7;j++)
  		if(	gameboard[i][j] == gamboard[i][j+1])
  	
  }
	//3.���� player ��� �����Ⱑ ������ ĭ�� ���� ��� �̰��� ����. 
  }

   if()
  }  
int order(int order)
{//���� �ٲٱ�~!!  ���ư��鼭. �ٲ��. black&white 

 } 
int turn(int input1, int input2)
{ //������ ����  
 int gameboard[input1][input2];
 if ( order == black)//22 --11,12,13,23,33,32,31,21
 	gameboard[input1-1][input2-1] = white; //�ϳ��ϳ� ������ ����ô�. �迭�� ���� �� ���� ��� �̾��մϴ�.  
 	gameboard[input1-1][input2] = white;
 	gameboard[input1-1][input2+1] = white;
 	gameboard[input1][input2+1] = white; 
 	gameboard[input1+1][input2+1] = white;
 	gameboard[input1+1][input2] = white;
 	gameboard[input1+1][input2-1] = white; 
 	gameboard[input1][input2-1] = white;
 else 
 	gameboard[input1-1][input2-1] = black; //33
 	gameboard[input1-1][input2] = black;
 	gameboard[input1-1][input2+1] = black;
 	gameboard[input1][input2+1] = black; 
 	gameboard[input1+1][input2+1] = black;
 	gameboard[input1+1][input2] = black;
 	gameboard[input1+1][input2-1] = black; 
 	gameboard[input1][input2-1] = black;
 	
 return gameboard[N][N];
}
int winner()
{ //�¸� ����
	turn == 0;
}
int check_result()
{ //��� ��� 

printf("���� ��� : �̱��� : %c, �̱� ��� �� ���� : %d", winner, winner_cnt);
}
