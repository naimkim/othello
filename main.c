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
//매개함수 정열 ?
void draw_board();//게임판 만들기   
int print_othello(int player_cnt, int player_t, int game_cnt, int pass_cnt); // 게임자 입력 받기 전 게임판,배치 상태 출력, 게임과정 출력해서 사용자가 알 수 있게 하는거 
int isGameEnd(int pass_cnt,int player_cnt, int flip_cnt, int game_cnt); //game 종료 조건 확인
int isBoardPlay( int player_cnt); //배치가능 칸 확인 
int turn(int player_t,int game_cnt, int input1, int input2); //돌 뒤집고, 돌 개수 검사하 기   
int garo_check(int player_t,int input1, int input2);//가로  낑긴 돌 바꾸기  
int sero_check(int player_t,int input1, int input2);
int degak1_check(int player_t,int input1, int input2); // y=-x
int degak2_check(int player_t,int input1, int input2); // y=x
//int degak2_check(int player_t,int input1, int input2, int gameboard[N][N])

int main (void) {	//필요한 변수들 정의 : WHITE개수 , BLACK개수  ,6*6 게임판 , 입력한 좌표  
//칸이 비어있음 : 0 
	int empty = 0;
//	칸에 검정알이 있음 : 1 : X
	int black = 1;
//	칸에 흰알이 있음 : -1 : O
	int white = -1;	

	int player_cnt;////player의 돌 개수
	int flip_cnt;//뒤집은 돌 개수  
	int player_t=-1;//현재 turn 사람  
	int game_cnt=0;//turn 개수
	int pass_cnt=0; 
	int input1;
	int input2;
	
	//현재 턴이 어떤 색인지를 저장하는 변수 turn을 하나 정의
	//게임초기화 

	player_cnt = 2;
	game_cnt = 1;	
		
  	//배치 결과 방향별 뒤집어지는 알 개수, 총뒤집어진 알개수 
	while (isGameEnd(pass_cnt, player_cnt, flip_cnt, game_cnt) == 0 ) { //game 종료 조건 확인 pass_cnt, gameboard[N][N], player_cnt//0이면 게임 안 종료 1이면 종료 
		print_othello(player_cnt, player_t, game_cnt, pass_cnt); 
		
	 	while (isBoardPlay(player_cnt) == 1) { //두 player 모두 배치가 불가능하면 반복문을 빠져나가야함
	 	
			
 			printf(" out a new %d othello : ", player_t);
  			scanf(" %d %d  ",&input1, &input2); 
				  
	 	 	if ( ((input1>= 0)&& (input1<=6) )&& ((input2>=0) && (input2 <=6)) ) {  
			//문의주신 출력의 경우, 각 칸에 대해 위의 배열요소 값에 맞게 O 혹은 X 혹은 빈 칸으로 출력을 하면 됩니다. 
					//돌 뒤집기   			
					flip_cnt = turn(player_t, game_cnt, input1, input2);
					game_cnt++;
					break;
			}
			else {
				printf(" invalid input! (should be less than 6)\n");
				//turn함수에서  몇개 뒤집었는지cnt세서 출력; 
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
	
	//winner 정하는 식  
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
