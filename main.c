#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//매개함수 정열 ?
int draw_othello;//게임판 만들기  
int initial_othello(); //게임초기화 
int print_othello();  // 게임자 입력 받기 전 게임판,배치 상태 출력, 게임과정 출력해서 사용자가 알 수 있게 하는거 
int isGameEnd(); //game 종료 조건 확인
int isBoardPlay(); //배치가능 칸 확인 
int turn(); //돌 뒤집고, 돌 개수 검사하 기  
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
	int player_t = 1;//player순서 p1 : 1 ; p2 : 2 
	int game_cnt;//turn 개수 
	int input1;
	int input2;
	int whiteblack;//white순서인지 black순서인지  
	
	initial_othello();	//게임초기화 	
	while (isGameEnd() == 0) { //game 종료 조건 확인 
	 	 print_othello(); 
	 	 if (isBoardPlay() == 0) 
	 	 	 continue; //두 player 모두 배치가 불가능하면 반복문을 빠져나가야함
			
 			printf(" out a new %f othello : ", order);
  			scanf(" %d %d  ",&input1, &input2); 
				  	
	 	 	if ( input1<= 0 || input1>=6 || input2<=0 || input2 >=6 ) {  
			//엥 .. 이거 아닌거같은데.. 쉬발  
			//문의주신 출력의 경우, 각 칸에 대해 위의 배열요소 값에 맞게 O 혹은 X 혹은 빈 칸으로 출력을 하면 됩니다. 
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
				//turn함수에서  몇개 뒤집었는지cnt세서 출력; 
				// 턴 바꿈 
	 	 	 }
	 	 else
			 printf(" invalid input! (should be less than 6)\n");
			 
			 
	game_cnt++;
	//순서 바꾸기, 돌 바꾸기  
	if(isGameEnd == 0 && player_t == 1) 
		player_t = 2;
	else if(isGameEnd == 0 && player_t == 2)
		player_t = 1;
	else 
		break;
			
	turn();
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
{//게임초기화 : 게임판 2,2 3,3 2,3 3,2빼고 빈칸으로 , 카운팅 다 0으로,  
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
{	// 게임 과정에서 아래 상황 및 내용은 반드시 출력으로 사용자들이 알 수 있게 해야함
	//게임판 모니터에 출력해서 O,X형태 2*2로 보이게 해야함.
	int east;
	int west;
	int north;
	int south;
	int x_en;
	int x_es;
	int x_wn;
	int x_ws; 
	//판 white = O , black = X
	printf("%d", drawboard());  
	//알개수  status : white 2, black 2 
	printf(" STATUS - WHITE : %d, BLACK : %d ", white_cnt, black_cnt);
			
  	//배치 결과 방향별 뒤집어지는 알 개수, 총뒤집어진 알개수 
  	if(game_cnt>1)
		 printf("::flip result:: \n");
		 printf("E : %d, W : %d, N : %d, S : %d, NE : %d, SE : %d, NW : %d, SW : %d\n", east, west, north, south, x_en, x_es, x_wn, x_ws);
	 	 printf("you has flipped %d othellos! ", east+west+north+south+x_en +x_es+x_wn+x_ws);
  	else
  		break;
  		
 } 
  
int isBoardPlay()
  {//배치 가능 칸 조건  
   //알이 없는 칸인가
   int gameboard[N][N];
   
   if(gameboard[input1][input2]==0) {
   		if(turn != 0)
   			return 1;
   		else
   			break;
 	else 
 		return 0;
   }		
   	//pass 된다. turn바뀐다.  어케하지. 
   			
  }
  
int isGameEnd()
  {//게임종료조건
   //  isBoardPlay == 0; 
  //1 . 칸이 모두 찬다.  
  //2. 모든 알이 한가지 색깔로 통일된다.
  //3.양쪽 player 모두 뒤집기가 가능한 칸이 없는 경우 이경우는 뭐야. 
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
  		//break 인가 continue 인가!!!!!!! 무엇인가!!!!!!! 
  	}
  }
  return x;
  }  
  
  /*
int horizontal_check()
{
//가로에서 뒤집을 돌 검사
int east;
int west;
int hori_cnt=0;//가로 뒤집은 돌 
	while( east != 0 || west != 0)
		if(현재 플레이어돌색 != 옆의 돌 ) 
			옆의 돌 == 현재 플레이어돌색;
			hori_cnt++;
		else if (현재 플레이어돌색 == 옆의 돌 ) 
			continue; 
		
}*/
int turn(int player_t)
{ //뒤집는 조건   
//가로 세로 대각선1, 대각선2 
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

int horizontal_check();//가로에서 뒤집을 돌 검사
int vertical_check();//세로에서 뒤집을 돌 검사
int diagonal1_check();  // 대각선1 검사 y= x
int diagonal2_check();  // 대각선2 검사 y= -x	
 	
 return gameboard[N][N];
}
int check_result()
{ //결과 출력 

printf("최종 결과 : 이긴사람 : %c, 이긴 사람 알 개수 : %d", winner, winner_cnt);
}
