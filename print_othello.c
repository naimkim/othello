#include "common.h"

int print_othello(int player_cnt, int player_t, int game_cnt, int pass_cnt)
{	// ���� �������� �Ʒ� ��Ȳ �� ������ �ݵ�� ������� ����ڵ��� �� �� �ְ� �ؾ���
	//������ ����Ϳ� ����ؼ� O,X���� 2*2�� ���̰� �ؾ���.
	//�� white = O , black = X
	draw_board(gameboard[N][N]);
	//�˰���  status : white 2, black 2 
	if(player_t == -1)
		printf(" STATUS - WHITE : %d, BLACK : %d ", player_cnt, game_cnt-pass_cnt - player_cnt);
	else if (player_t == 1)
		printf(" STATUS - WHITE : %d, BLACK : %d ", game_cnt-pass_cnt - player_cnt, player_cnt);		
  	//��ġ ��� ���⺰ ���������� �� ����, �ѵ������� �˰��� 
  	
  	return 0;
 } 

