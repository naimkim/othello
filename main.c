#include <stdio.h>
#include <stdlib.h>
#include <Windows.h> 
#define N 6
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�Ű��Լ� ���� 
void draw_board();//������ �׸��� 
int othello(); //�����ʱ�ȭ 
int print_othello();  // ������ �Է� �ޱ� �� ������,��ġ ���� ��� 
int get_othello(); //��ġ�� ��ǥ �Է� �ޱ�
int isGameEnd(); //game ���� ���� Ȯ��
int isBoardPlay(); //��ġ���� ĭ Ȯ�� 
int isPlayerGB(); //�Է� ��ǥ�� �������� üũ
int turn(); //������ ����  
int winner(); //�¸� ����
int check_result(); //��� ��� 

void main (void) {
	int gameboard[N][N];	//�ʿ��� ������ ���� : WHITE���� , BLACK����  ,6*6 ������ , �Է��� ��ǥ  
	int whites = 2;
	int blacks = 2;
	
	int othello(); 			
	while (isGameEnd() == 0) { 
	 	 print_othello(); 
	 	 if (isBoardPlay() == 0) //���⼭���� ���ӽ�
	 	 	get_othello();
	 	 	 continue; //�� player ��� ��ġ�� �Ұ����ϸ� �ݺ����� ������������
	 	 	 
	 	 	 do
					{printf(" "); //�����̶� ǥ���ؾߵ� �͵� ���⿡ ǥ��
					printf(" "); // �¸��� ǥ��; 
					scanf(" "); //player�� ���� ���� �� �Է� �ޱ�  
			} while ( ) // ���� �¸��ڰ� ����� while�� �� 
	 		
	 	 if (isPlayerGB() == 0)
	 	 	 if ( ) {
				//turn�Լ�����  � ����������cnt���� ���; 
				// �� �ٲ� ;
	 	 	 }
	 	 else
			 �������� �Է����� ���;
}
check_result(); //��� ���
}

void draw_board(int c, int r)//������ �׸��� �Լ�
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
{//�����ʱ�ȭ : ������ - ����,�� �� 2�� �밢������ ��ġ , ��ġ���� ǥ�� �ʱ�ȭ 
print_othello();

 
 } 

int print_othello()
{	//������ ����Ϳ� ����ؼ� O,X���� 2*2�� ���̰� �ؾ���. 
	draw_board();
	
	// status : white 2, black 2 
	printf(" STATUS - WHITE : %d, BLACK : %d ", whites, blacks);
	
 } 
 
 int get_othello()
 {//��ġ�� ��ǥ �Է� �ޱ�  ������ ���� ������� ���������� if��
 	if  //���� ���ʰ� �����̿����� ��� �̷���  
 		printf(" out a new %f othello : like 3 5 ", order);
  		scanf(" %d %d ", )
  } 
