#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//매개함수 정열 
void draw_board();//게임판 그린겨 
int othello(); //게임초기화 
int print_othello();  // 게임자 입력 받기 전 게임판,배치 상태 출력, 게임과정 출력해서 사용자가 알 수 있게 하는거 
void isGameEnd(); //game 종료 조건 확인
void isBoardPlay(); //배치가능 칸 확인 
void display_stone();//게임판에 흰,검정 돌 놓기  
int isPlayerGB(); //입력 좌표가 적절한지 체크 
int turn(); //뒤집는 조건  
int winner(); //승리 조건
int check_result(); //결과 출력 

void main (void) {
	int gameboard[N][N];	//필요한 변수들 정의 : WHITE개수 , BLACK개수  ,6*6 게임판 , 입력한 좌표  
//칸이 비어있음 : 0 
	int empty = 0;
//	칸에 검정알이 있음 : 1
	int black = 1;
//	칸에 흰알이 있음 : -1
	int white = -1;
	int white_cnt;// 흰 돌 개수 
	int black_cnt;//검정 돌 개수 
	int player1;
	int player2;
	int game_cnt=0;//turn 개수 
	int input1;
	int input2;
			
	while (isGameEnd() == 0) { //game 종료 조건 확인 
	 	 print_othello(); 
	 	 if (isBoardPlay() == 0) 
	 	 	 continue; //두 player 모두 배치가 불가능하면 반복문을 빠져나가야함
					  	
	  		
	 			 if (isPlayerGB() == 0)
	 	 		 if ( ) {
				//turn함수에서  몇개 뒤집었는지cnt세서 출력; 
				// 턴 바꿈 
	 	 	 }
	 	 else
			 부적절한 입력임을 출력;
	game_cnt++;
	}	
	check_result(); //결과 출력 
}

void draw_board(int c, int r)//게임판 그리는 함수
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
{//게임초기화 : 게임판 - 검정,흰 돌 2개 대각선으로 위치 , 배치상태 표현 초기화 
print_othello();

 
 } 

int print_othello()
{	// 게임 과정에서 아래 상황 및 내용은 반드시 출력으로 사용자들이 알 수 있게 해야함
	//게임판 모니터에 출력해서 O,X형태 2*2로 보이게 해야함. 
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
  {//게임종료조건
   
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

int isPlayerGB(); //입력 좌표가 적절한지 체크
int turn(); //뒤집는 조건  
int winner(); //승리 조건
int check_result(); //결과 출력 
