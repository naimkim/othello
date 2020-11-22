#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//매개함수 정열 ?
int initial_othello(); //게임초기화 
int print_othello();  // 게임자 입력 받기 전 게임판,배치 상태 출력, 게임과정 출력해서 사용자가 알 수 있게 하는거 
void isGameEnd(); //game 종료 조건 확인
void isBoardPlay(); //배치가능 칸 확인 
int order(); //순서 왔다갔다리 어떻게 만듭니까!!!!! 
int turn(); //뒤집는 조건  
int winner(); //승리 조건
int check_result(); //결과 출력 

void main (void) {
	int gameboard[N][N];	//필요한 변수들 정의 : WHITE개수 , BLACK개수  ,6*6 게임판 , 입력한 좌표  
//칸이 비어있음 : 0 
	int empty = 0;
//	칸에 검정알이 있음 : 1 : X
	int black = 1;
//	칸에 흰알이 있음 : -1 : O
	int white = -1;
	int white_cnt;// 흰 돌 개수 
	int black_cnt;//검정 돌 개수 
	int player1;
	int player2;
	int game_cnt;//turn 개수 
	int input1;
	int input2;
	int whiteblack;//white순서인지 black순서인지  
	
	
	initial_othello();	//게임초기화 	
	while (isGameEnd() == 0) { //game 종료 조건 확인 
	 	 print_othello(); 
	 	 if (isBoardPlay() == 0) 
	 	 	 continue; //두 player 모두 배치가 불가능하면 반복문을 빠져나가야함
					  	
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
int initial_othello()
{//게임초기화 : 게임판 0으로 , 순서 카운팅도 0으로,  
	int gameboard[N][N] = 0;
	gameboard[2][2] = white;
	gameboard[3][3] = white;
	gameboard[2][3] = black;
	gameboard[3][2] = black;
	
	int game_cnt=1;
 
 } 

int print_othello(int input1, int input2)
{	// 게임 과정에서 아래 상황 및 내용은 반드시 출력으로 사용자들이 알 수 있게 해야함
	//게임판 모니터에 출력해서 O,X형태 2*2로 보이게 해야함. 
	//판 white = O , black = X
	printf("%d", gameboard);  
	//알개수  status : white 2, black 2 
	printf(" STATUS - WHITE : %d, BLACK : %d ", white_cnt, black_cnt);
	//turn pass됐는지!
	printf("pass되면 1이 뜬다 : %d", turn_pass); 
	do{
			printf(" invalid input! (should be less than 6)\n");
 			printf(" out a new %f othello : ", order);
  			scanf(" %d %d  ",&input1, &input2);
  			}
  			while (input1<= 0 || input1>=6 || input2<=0 || input2 >=6);
  			
  	//배치 결과 방향별 뒤집어지는 알 개수, 총뒤집어진 알개수 
	 printf("east : %d, north : %d, south : %d, x_en : %d, x_es : %d, x_wn : %d, x_ws : %d\n", east, west, north, south, x_en, x_es, x_wn, x_ws);
	 
	 printf("total turning counting : %d", east+west+north+south+x_en+x_es+x_wn+x_ws);
  	
  	//게임 종료 후 최종결과 : check_result 함수 있어서 여기서 출력할 필요 없지 않습니까.?  
	   
  	return input1;
  	return input2;
 } 
  
  void isBoardPlay()
  {//배치 가능 칸 조건  
   //알이 없는 칸인가
   int gameboard[N][N];
   
   if(gameboard[input1][input2]==0) 
   		if(order == black )
   			gameboard[input1][input2] = 1;
   		else
   			gameboard[input1][input2] = -1;
   			
   	else 
   	turn_pass++;
   	break;//pass 된다. turn바뀐다.  어케하지. 
   			
  }
  
void isGameEnd()
  {//게임종료조건
   //  isBoardPlay == 0; 
  //1 . 칸이 모두 찬다. 
  if(gameboard[N][N] != 0) 
  //2. 모든 알이 한가지 색깔로 통일된다.
  int i,j;
  while(1) 
  { 
  for(i=0<i<7;i++){
  	for(j=0<j<7;j++)
  		if(	gameboard[i][j] == gamboard[i][j+1])
  	
  }
	//3.양쪽 player 모두 뒤집기가 가능한 칸이 없는 경우 이경우는 뭐야. 
  }

   if()
  }  
int order(int order)
{//순서 바꾸기~!!  돌아가면서. 바뀐다. black&white 

 } 
int turn(int input1, int input2)
{ //뒤집는 조건  
 int gameboard[input1][input2];
 if ( order == black)//22 --11,12,13,23,33,32,31,21
 	gameboard[input1-1][input2-1] = white; //하나하나 변수로 만듭시다. 배열로 늦은 밤 정신 없어서 미안합니다.  
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
{ //승리 조건
	turn == 0;
}
int check_result()
{ //결과 출력 

printf("최종 결과 : 이긴사람 : %c, 이긴 사람 알 개수 : %d", winner, winner_cnt);
}
