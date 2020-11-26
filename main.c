#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6

int gameboard[N][N] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,-1,1,0,0},
	{0,0,1,-1,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�Ű��Լ� ���� ?
void draw_board();//������ �����   
int print_othello(int player_cnt, int player_t, int game_cnt, int pass_cnt); // ������ �Է� �ޱ� �� ������,��ġ ���� ���, ���Ӱ��� ����ؼ� ����ڰ� �� �� �ְ� �ϴ°� 
int isGameEnd(int pass_cnt,int player_cnt, int flip_cnt, int game_cnt); //game ���� ���� Ȯ��
int isBoardPlay( int player_cnt); //��ġ���� ĭ Ȯ�� 
int turn(int player_t,int game_cnt, int input1, int input2); //�� ������, �� ���� �˻��� ��   
int garo_check(int player_t,int input1, int input2);//����  ���� �� �ٲٱ�  
int sero_check(int player_t,int input1, int input2);
int degak1_check(int player_t,int input1, int input2); // y=-x
int degak2_check(int player_t,int input1, int input2); // y=x
//int degak2_check(int player_t,int input1, int input2, int gameboard[N][N])

int main (void) {	//�ʿ��� ������ ���� : WHITE���� , BLACK����  ,6*6 ������ , �Է��� ��ǥ  
//ĭ�� ������� : 0 
	int empty = 0;
//	ĭ�� �������� ���� : 1 : X
	int black = 1;
//	ĭ�� ����� ���� : -1 : O
	int white = -1;	

	int player_cnt;////player�� �� ����
	int flip_cnt;//������ �� ����  
	int player_t=-1;//���� turn ���  
	int game_cnt=0;//turn ����
	int pass_cnt=0; 
	int input1;
	int input2;
	
	//���� ���� � �������� �����ϴ� ���� turn�� �ϳ� ����
	//�����ʱ�ȭ 

	player_cnt = 2;
	game_cnt = 1;	
		
  	//��ġ ��� ���⺰ ���������� �� ����, �ѵ������� �˰��� 
	while (isGameEnd(pass_cnt, player_cnt, flip_cnt, game_cnt) == 0 ) { //game ���� ���� Ȯ�� pass_cnt, gameboard[N][N], player_cnt//0�̸� ���� �� ���� 1�̸� ���� 
		print_othello(player_cnt, player_t, game_cnt, pass_cnt); 
		
	 	while (isBoardPlay(player_cnt) == 1) { //�� player ��� ��ġ�� �Ұ����ϸ� �ݺ����� ������������
	 	
			
 			printf(" out a new %d othello : ", player_t);
  			scanf(" %d %d  ",&input1, &input2); 
				  
	 	 	if ( ((input1>= 0)&& (input1<=6) )&& ((input2>=0) && (input2 <=6)) ) {  
			//�����ֽ� ����� ���, �� ĭ�� ���� ���� �迭��� ���� �°� O Ȥ�� X Ȥ�� �� ĭ���� ����� �ϸ� �˴ϴ�. 
					//�� ������   			
					flip_cnt = turn(player_t, game_cnt, input1, input2);
					game_cnt++;
					break;
			}
			else {
				printf(" invalid input! (should be less than 6)\n");
				//turn�Լ�����  � ����������cnt���� ���; 
				continue;	
			}
			
		}
		
	 	if (isBoardPlay(player_cnt) == 0) {
			pass_cnt++;
			continue; 
			if(isGameEnd(pass_cnt, player_cnt, flip_cnt, game_cnt) == 0 && player_t == -1) 
				player_t = 1;
			else if(isGameEnd(pass_cnt, player_cnt, flip_cnt,game_cnt) == 0 && player_t == 1)
				player_t = -1;
			
		}
			 

	}
	
	//winner ���ϴ� ��  
	if(isGameEnd==1)
	{
	if((game_cnt != 0) && (game_cnt % 2 == 0)){
		printf("winner is black\n");
		printf("black count is %d", player_cnt);
			
    }
    else if(game_cnt % 2 == 1) 
    {	
		printf("winner is white\n");
		printf("white count is %d", player_cnt);	
    }
 	}
	return 0;
}
