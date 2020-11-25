#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//매개함수 정열 ?
int draw_othello;//게임판 만들기   
int print_othello();  // 게임자 입력 받기 전 게임판,배치 상태 출력, 게임과정 출력해서 사용자가 알 수 있게 하는거 
int isGameEnd(); //game 종료 조건 확인
int isBoardPlay(); //배치가능 칸 확인 
int turn(); //돌 뒤집고, 돌 개수 검사하 기   
int garo_check();//가로  낑긴 돌 바꾸기  
int sero_check();
int degak1_check(); // y=-x
int degak2_check(); // y=x


void main (void) {	//필요한 변수들 정의 : WHITE개수 , BLACK개수  ,6*6 게임판 , 입력한 좌표  
//칸이 비어있음 : 0 
	int empty = 0;
//	칸에 검정알이 있음 : 1 : X
	int black = 1;
//	칸에 흰알이 있음 : -1 : O
	int white = -1;	

	int player_cnt;// 현재 turn 돌 개수 
	int player_t;//맞으면 1 틀리면 0 != == 
	int game_cnt;//turn 개수
	int pass_cnt=0; 
	int input1;
	int input2;
	
	//현재 턴이 어떤 색인지를 저장하는 변수 turn을 하나 정의
	//게임초기화 
	int gameboard[N][N] = {
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,-1,1,0,0},
	{0,0,1,-1,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0}
	};
	game_cnt = 1;	
	while (isGameEnd() == 0) { //game 종료 조건 확인 
	 	 print_othello(); 
	 	 if (isBoardPlay() == 1) 
	 	 	{ //두 player 모두 배치가 불가능하면 반복문을 빠져나가야함
			
 			printf(" out a new %f othello : ", player_t);
  			scanf(" %d %d  ",&input1, &input2); 
				  
	 	 	if ( input1<= 0 || input1>=6 || input2<=0 || input2 >=6 ) {  
			//문의주신 출력의 경우, 각 칸에 대해 위의 배열요소 값에 맞게 O 혹은 X 혹은 빈 칸으로 출력을 하면 됩니다. 
					switch (gameboard[input1][input2])
					{
						case 0:
							printf(" ");
							break;
						case 1:
							printf("X");
							break;
						case -1:
							printf("O");
							break;	
			
						default:
							break;	
					}}
			else{
				printf(" invalid input! (should be less than 6)\n");
				//turn함수에서  몇개 뒤집었는지cnt세서 출력; 
				// 턴 바꿈
				if(isGameEnd == 0 && player_t == -1) 
					player_t = 1;
				else if(isGameEnd == 0 && player_t == 1)
					player_t = -1; 
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
			 
	//돌 뒤집기   			
	turn();
	game_cnt++;
	}
	if((game_cnt != 0) && (game_cnt % 2 == 0))

        {
			printf("winner is black");
			printf("black count is %d", player_cnt);
			
        }

        else if(game_cnt % 2 == 1) 

        {	printf("winner is white");
			printf("white count is %d", player_cnt);
			

        }

        else

               printf( " 0 \n" );
}

int draw_board()//게임판 그리는 함수
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

	printf("   0  1  2  3  4  5 \n");
	printf("=========================\n");
	
	for (i=0; i<N; i++)	
	{
		printf(" %d", i);
		for( j=0 ; j<N ; j++ )
		{
		printf("|%c|", gameboard[i][j]);	
		if (j == 5)
			printf("\n");
		} 
			printf(" ----------------------\n ");
	
	}
}

int print_othello(int player_cnt, int player_t, int game_cnt, int pass_cnt)
{	// 게임 과정에서 아래 상황 및 내용은 반드시 출력으로 사용자들이 알 수 있게 해야함
	//게임판 모니터에 출력해서 O,X형태 2*2로 보이게 해야함.
	turn();
	int total_flip;
	//판 white = O , black = X
	int a;
	a = draw_board();
	printf("%f",a);
	//알개수  status : white 2, black 2 
	if(player_t == -1)
		printf(" STATUS - WHITE : %d, BLACK : %d ", player_cnt, game_cnt-pass_cnt - player_cnt);
	else if (player_t == 1)
		printf(" STATUS - WHITE : %d, BLACK : %d ", game_cnt-pass_cnt - player_cnt, player_cnt);		
  	//배치 결과 방향별 뒤집어지는 알 개수, 총뒤집어진 알개수 
  	
  	
	
	return total_flip;
 } 

  
int isGameEnd(int pass_cnt, int gameboard[N][N], int player_cnt) 
  {//게임종료조건
   //  isBoardPlay == 1이면  종료  
  //1 . 칸이 모두 찬다.  
  //2. 모든 알이 한가지 색깔로 통일된다.
  //3.양쪽 player 모두 뒤집기가 가능한 칸이 없는 경우 
  int i,j;
  int x;
 
while(x==1)
{
  for(i=0; i<6; i++)
  {
  	for(j=0;j<6;j++)
  	{
  		if(	gameboard[i][j] == gameboard[i][j+1])
  				x= 1; 
  		else if ( gameboard[i][j] != 0 )
  			x = 1;
  		else if ( pass_cnt == 2 || player_cnt == 0 )
  			x = 1;	
  		else
	  		x = 0;
  		//break 인가 continue 인가!!!!!!! 무엇인가!!!!!! 
  	}
  	if(x==0)
  		break;
  	else if (x==1)
  		continue;
  }
}
  return x;
  }  


//isboardplay 가 0이면 pass 
int isBoardPlay(int gameboard[N][N], int flip_cnt)
  {//배치 가능 칸이 있는지 확인   있으면 1 없으면 0 
   //알이 없는 칸인가
   int i,j;
   int cnt=0;// cnt 가 36이 되면 배치가능한 칸 없음  
   for(i=0;i<6;i++)
   {
   		for(j=0;j<6;j++)
   		{
   			if(gameboard[i][j]==0)
   				break;
   			else
   				cnt++;
   				continue;
		   }
   }
   if(flip_cnt ==0 || cnt == 36)
   		return 1;
	else 
  		 return 0;
  
   
int garo_check(int player_t,int input1, int input2, int gameboard[N][N])
{
	int east;
	int west;
	int i,j;//N은 6이니까 
	int n1=0;
	int n2=0;//n1+n2=가로 뒤집은 돌개수
//가로에서 사이에 낀 돌 바꾸는거  
//동쪽 확인할 때  
for(i=1;i<6;i++)
{	if( gameboard[input1][input2-i] != 0 && gameboard[input1][input2-i] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		n1++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< n1-1;j++)
{
	 gameboard[input1][input2-j]==player_t;
}

//서쪽 확인할 때
 for(i=1;i<6;i++)
{	if( gameboard[input1][input2+i] != 0 && gameboard[input1][input2+i] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		n2++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< n2-1;j++)
{
	 gameboard[input1][input2+j]==player_t;
}

	return (n1+n2);
}

//세로  
int sero_check(int player_t,int input1, int input2, int gameboard[N][N])
{
	int north;
	int south;
	int i,j;//N은 6이니까 
	int n3=0;
	int n4=0;//n1+n2=가로 뒤집은 돌개수
//가로에서 사이에 낀 돌 바꾸는거  
//동쪽 확인할 때  
for(i=1;i<6;i++)
{	if( gameboard[input1-i][input2] != 0 && gameboard[input1-i][input2] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		n3++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< n3-1;j++)
{
	 gameboard[input1-j][input2]==player_t;
}

//서쪽 확인할 때
 for(i=1;i<6;i++)
{	if( gameboard[input1+i][input2] != 0 && gameboard[input1+i][input2] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		n4++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< n4-1;j++)
{
	 gameboard[input1+j][input2]==player_t;
}

	return (n3+n4);	
}
//대각 
int degak1_check(int player_t,int input1, int input2, int gameboard[N][N])
{ // y=-x
 	int x_en;
	int x_ws;
	int i,j;//N은 6이니까 
	int d1=0;
	int d2=0;//n1+n2=가로 뒤집은 돌개수
//가로에서 사이에 낀 돌 바꾸는거  
//동쪽 확인할 때  
for(i=1;i<6;i++)
{	if( gameboard[input1-i][input2-i] != 0 && gameboard[input1-i][input2-i] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		d1++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< d1-1;j++)
{
	 gameboard[input1-j][input2-j]==player_t;
}

//서쪽 확인할 때
 for(i=1;i<6;i++)
{	if( gameboard[input1+i][input2+i] != 0 && gameboard[input1+i][input2+i] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		d2++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< d2-1;j++)
{
	 gameboard[input1+j][input2+j]==player_t;
}

	return (d1+d2);
}

int degak2_check(int player_t,int input1, int input2, int gameboard[N][N])
{
 // y=x
 
	int x_wn;
	int x_es;
	int i,j;//N은 6이니까 
	int d3=0;
	int d4=0;//n1+n2=가로 뒤집은 돌개수
//가로에서 사이에 낀 돌 바꾸는거  
//동쪽 확인할 때  
for(i=1;i<6;i++)
{	if( gameboard[input1+i][input2-i] != 0 && gameboard[input1+i][input2-i] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		d3++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< d3-1;j++)
{
	 gameboard[input1+j][input2-j]==player_t;
}

//서쪽 확인할 때
 for(i=1;i<6;i++)
{	if( gameboard[input1-i][input2+i] != 0 && gameboard[input1-i][input2+i] != gameboard[input1][input2])
	//현재 거와 다른색 돌인지  
	{
		d4++; 
		continue;
	}
	else
	{
		break; 
	}
	
}
for (j=0;j< d4-1;j++)
{
	 gameboard[input1-j][input2+j]==player_t;
}

	return (d3+d4);	
}
int turn(int player_t, int gameboard[N][N], int game_cnt, int input1, int input2)
{ //뒤집는 조건   
//돌 개수 세기  
//가로 세로 대각선1, 대각선2 
	int empty = 0;
	int east;
	int west;
	int north;
	int south;
	int x_en;
	int x_es;
	int x_wn;
	int x_ws; 
	int garo_cnt;
	int sero_cnt;
	int degak1_cnt;
	int degak2_cnt;
	int player_cnt;
	int playerAcnt; 
	int a,b,c,d; 
 
 while ( gameboard[input1][input2] == player_t)//22 --11,12,13,23,33,32,31,21
 {
 
 	if( gameboard[input1-1][input2-1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
			gameboard[input1-1][input2-1] =  gameboard[input1][input2] ;  
 		x_en++; 
}
 	else if( gameboard[input1-1][input2] != empty || gameboard[input1-1][input2-1] != player_t  )
 	{
		 	gameboard[input1-1][input2] = gameboard[input1][input2] ;
		north++; 
}
 	else if(gameboard[input1-1][input2+1] != empty || gameboard[input1-1][input2-1] != player_t )
	 {
			 gameboard[input1-1][input2+1] =  gameboard[input1][input2] ;
	 	 x_wn++; 
}
	else if( gameboard[input1][input2+1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
	 	gameboard[input1][input2+1] =  gameboard[input1][input2] ; 
 		west++; 
 }
 	else if( gameboard[input1+1][input2+1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
		 	gameboard[input1+1][input2+1] =  gameboard[input1][input2] ;
		x_ws++;  
 }
 	else if(gameboard[input1+1][input2] != empty || gameboard[input1-1][input2-1] != player_t )
	{
		 	gameboard[input1+1][input2] =  gameboard[input1][input2] ;
	 	south++; 
}
	else if( gameboard[input1+1][input2-1] != empty || gameboard[input1-1][input2-1] != player_t )
 	{
		 	gameboard[input1+1][input2-1] =  gameboard[input1][input2] ;  
 		x_es++; 
 }
 	else if( gameboard[input1][input2-1] != empty|| gameboard[input1-1][input2-1] != player_t )
 	{
		 	gameboard[input1][input2-1] =  gameboard[input1][input2] ; 
		east++;
 }
 	else
 	
 		break;
 
 }	
playerAcnt = east+west+north+south+x_en +x_es+x_wn+x_ws;//뒤집은 돌 개수 세고 빠져나오기   
 //낑긴 돌 바꾸고 갯수를 return시키는 함수
  //int player_t,int input1, int input2, int gameboard[N][N]
a= garo_check();  
b= sero_check();
c= degak1_check(); 
d= degak2_check(); 

player_cnt = a+ b+ c+d + playerAcnt;
	if(game_cnt>1)
	{ printf("::flip result:: \n");
		 printf("E : %d, W : %d, N : %d, S : %d, NE : %d, SE : %d, NW : %d, SW : %d\n", east, west, north, south, x_en, x_es, x_wn, x_ws);
		printf("you has flipped %d othellos! ", east+west+north+south+x_en +x_es+x_wn+x_ws+garo_cnt+sero_cnt+degak1_cnt+degak2_cnt);
 	 }
		
	return player_cnt; 
	 
}


