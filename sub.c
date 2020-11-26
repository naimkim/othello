#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6


int draw_board();//������ �����   
void print_othello();  // ������ �Է� �ޱ� �� ������,��ġ ���� ���, ���Ӱ��� ����ؼ� ����ڰ� �� �� �ְ� �ϴ°� 
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

	int player_cnt;////player_cnt�� �� ������ ������ �� ����
	int player_t=-1;//���� turn ���  
	int game_cnt=0;//turn ����
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
	player_cnt = 2;
	game_cnt = 1;	
	while (isGameEnd(pass_cnt, gameboard[N][N], player_cnt) == 0) { //game ���� ���� Ȯ�� pass_cnt, gameboard[N][N], player_cnt
	 {
		  print_othello(player_cnt, player_t, game_cnt, pass_cnt, gameboard[N][N]); 
	 	 if (isBoardPlay() == 1) 
	 	 	{ //�� player ��� ��ġ�� �Ұ����ϸ� �ݺ����� ������������
			
 			printf(" out a new %f othello : ", player_t);
  			scanf(" %d %d  ",&input1, &input2); 
				  
	 	 	if ( input1<= 0 || input1>=6 || input2<=0 || input2 >=6 ) {  
			//�����ֽ� ����� ���, �� ĭ�� ���� ���� �迭��� ���� �°� O Ȥ�� X Ȥ�� �� ĭ���� ����� �ϸ� �˴ϴ�. 
				break;
				}
			else{
				printf(" invalid input! (should be less than 6)\n");
				//turn�Լ�����  � ����������cnt���� ���; 
				continue;
				
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
	//winner ���ϴ� ��  
	if((game_cnt != 0) && (game_cnt % 2 == 0))

        {
			printf("winner is black");
			printf("black count is %d", player_cnt);
			
        }

        else if(game_cnt % 2 == 1) 

        {	printf("winner is white");
			printf("white count is %d", player_cnt);
			

        }

}}
