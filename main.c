#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//매개함수 정열 
void draw_board();//게임판 그린겨 
int othello(); //게임초기화 
int print_othello();  // 게임자 입력 받기 전 게임판,배치 상태 출력 
int get_othello(); //배치할 좌표 입력 받기
int isGameEnd(); //game 종료 조건 확인
int isBoardPlay(); //배치가능 칸 확인 
int isPlayerGB(); //입력 좌표가 적절한지 체크
int turn(); //뒤집는 조건  
int winner(); //승리 조건
int check_result(); //결과 출력 

void main (void) {
	int gameboard[N][N];	//필요한 변수들 정의 : WHITE개수 , BLACK개수  ,6*6 게임판 , 입력한 좌표  
	int whites = 2;
	int blacks = 2;
	
	int othello(); 			
	while (isGameEnd() == 0) { 
	 	 print_othello(); 
	 	 if (isBoardPlay() == 0) //여기서부터 게임시
	 	 	get_othello();
	 	 	 continue; //두 player 모두 배치가 불가능하면 반복문을 빠져나가야함
	 	 	 
	 	 	 do
					{printf(" "); //조건이랑 표현해야될 것들 여기에 표시
					printf(" "); // 승리자 표시; 
					scanf(" "); //player가 돌을 놓을 곳 입력 받기  
			} while ( ) // 게임 승리자가 생기면 while문 끝 
	 		
	 	 if (isPlayerGB() == 0)
	 	 	 if ( ) {
				//turn함수에서  몇개 뒤집었는지cnt세서 출력; 
				// 턴 바꿈 ;
	 	 	 }
	 	 else
			 부적절한 입력임을 출력;
}
check_result(); //결과 출력
}

void draw_board(int c, int r)//게임판 그리는 함수
// 2/2 3/3 white 2/3 3/2 black
{	int i,j;
	
	printf("   ");
	for( i=0 ; i<N ; i++)
	{	
		printf(" %d", i);
			}
		printf("\n");
		
	for( j=0 ; j<N ; j++ )
	{
		printf(" %d| | | | | | |\n", j);
		printf(" ----------------------\n ");	
	
 } 
int othello()
{//게임초기화 : 게임판 - 검정,흰 돌 2개 대각선으로 위치 , 배치상태 표현 초기화 
print_othello();

 
 } 

int print_othello()
{	//게임판 모니터에 출력해서 O,X형태 2*2로 보이게 해야함. 
	draw_board();
	
	// status : white 2, black 2 
	printf(" STATUS - WHITE : %d, BLACK : %d ", whites, blacks);
	
 } 
 
 int get_othello()
 {//배치할 좌표 입력 받기  순서에 따라 흰색인지 검정색인지 if문
 	if  //저번 차례가 검정이였으면 햐양 이런식  
 		printf(" out a new %f othello : like 3 5 ", order);
  		scanf(" %d %d ", )
  } 
