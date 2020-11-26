#include "common.h"

int print_othello(int player_cnt, int player_t, int game_cnt, int pass_cnt)
{	// 게임 과정에서 아래 상황 및 내용은 반드시 출력으로 사용자들이 알 수 있게 해야함
	//게임판 모니터에 출력해서 O,X형태 2*2로 보이게 해야함.
	//판 white = O , black = X
	draw_board(gameboard[N][N]);
	//알개수  status : white 2, black 2 
	if(player_t == -1)
		printf(" STATUS - WHITE : %d, BLACK : %d ", player_cnt, game_cnt-pass_cnt - player_cnt);
	else if (player_t == 1)
		printf(" STATUS - WHITE : %d, BLACK : %d ", game_cnt-pass_cnt - player_cnt, player_cnt);		
  	//배치 결과 방향별 뒤집어지는 알 개수, 총뒤집어진 알개수 
  	
  	return 0;
 } 

