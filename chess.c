#include<stdio.h>
int queen(char arr[][8], int size, int row, int column);
int rook(char arr[][8], int size, int row, int column);
int bishop(char arr[][8], int size, int row, int column);
int main()
{
  int i, j;
  char board[8][8];
  board[0][0]='r'; //Rook
  board[0][1]='h'; //Knight
  board[0][2]='b'; //Bishop
  board[0][3]='q'; //Queen
  board[0][4]='k'; //King
  board[0][5]='b';//Bishop
  board[0][6]='h'; //Knight
  board[0][7]='r'; //Rook
  board[1][0]='p'; //Pawn
  board[1][1]='p'; //Pawn
  board[1][2]='p'; //Pawn
  board[1][3]='p'; //Pawn
  board[1][4]='p'; //Pawn
  board[1][5]='p'; //Pawn
  board[1][6]='p'; //Pawn
  board[1][7]='p'; //Pawn
  board[2][0]=0;
  board[2][1]=0;
  board[2][2]=0;
  board[2][3]=0;
  board[2][4]=0;
  board[2][5]=0;
  board[2][6]=0;
  board[2][7]=0;
  board[3][0]=0;
  board[3][1]=0;
  board[3][2]=0;
  board[3][3]=0;
  board[3][4]=0;
  board[3][5]=0;
  board[3][6]=0;
  board[3][7]=0;
  board[4][0]=0;
  board[4][1]=0;
  board[4][2]=0;
  board[4][3]=0;
  board[4][4]=0;
  board[4][5]=0;
  board[4][6]=0;
  board[4][7]=0;
  board[5][0]='Q';
  board[5][1]=0;
  board[5][2]='Q';
  board[5][3]=0;
  board[5][4]=0;
  board[5][5]=0;
  board[5][6]=0;
  board[5][7]=0;
  board[6][0]='P'; //Pawn
  board[6][1]='P'; //Pawn
  board[6][2]='P'; //Pawn
  board[6][3]='P'; //Pawn
  board[6][4]='P'; //Pawn
  board[6][5]='P'; //Pawn
  board[6][6]='P'; //Pawn
  board[6][7]='P'; //Pawn
  board[7][0]='R'; //Rook 
  board[7][1]='H'; //Knight
  board[7][2]='B';//Bishop
  board[7][3]='K'; //King
  board[7][4]='Q'; //Queen
  board[7][5]='B'; //Bishop
  board[7][6]='H'; //Knight//horse
  board[7][7]='R'; //Rook
  
	printf("\n");
	printf("    0    1    2    3    4    5    6    7\n");
	printf("  ________________________________________\n\n");
	for(i = 0; i < 8; ++i)
	{
		printf("%d ", i);
	    for(j = 0; j < 8; ++j)
		{
	    	printf("| %c  ",board[i][j]);
    	}
		printf("\b|");
    	printf("\n");
		printf("  ---------------------------------------\n");
	}
		

		//first making conditions for player1
		
		//		PAWN
		
	//2 Types of conditions will be made
	
	// 1) A checking loop
	// 2) Execution loop
	
	//Each pawn can move only one step further hence:
		
	//if player chooses pawn

				
//Now combining both types of conditions

	int row=0, C=0, x=0;		
	int userChooses=0;
	int turn=1;
	int game=0;
	
	while(!game)
	{
		printf("The position of pawn or queen you want to move? for eg: 2,4  ");
		if(turn%2==1)
		{
			printf("player 1 turn");
			do	//for player 1
			{
				scanf("%d,%d", &row, &C);
				if( ((board[row-1][C-1]==0) && (board[row-1][C+1]==0) && (board[row-1][C]!=0)) && board[row][C]=='P')	//condition of a pawn
				{
					printf("You cannot move this pawn, enter again?");
				}
				else if(board[row][C]=='Q' && board[row+1][C]<92 && board[row-1][C]<92 && board[row][C+1]<92 && board[row][C-1]<92)
					printf("You cannot move this queen, enter again?");
				else
				{
					x=1;
				}
			}
			while(!x);
		}
		else
		{
			printf("player 2 turn");
			do	//for player 2
			{
				scanf("%d,%d", &row, &C);
				if( ((board[row+1][C-1]==0) && (board[row+1][C+1]==0) && (board[row-1][C]!=0)) && board[row][C]=='P')	//condition of a pawn
				{
					printf("You cannot move this pawn, enter again?");
				}
				else if(board[row][C]=='Q' && board[row+1][C]<92 && board[row-1][C]<92 && board[row][C+1]<92 && board[row][C-1]<92)
					printf("You cannot move this queen, enter again?");
				else
				{
					x=1;
				}
			}
			while(!x);
		}
		
	if(board[row][C]=='P')
	{
			if( (board[row-1][C+1]!=0) || (board[row-1][C-1]!=0) )
			{
				
				
				if(board[row-1][C]==0)
				{
					printf("Now you have two choices for moving this pawn\n");
					printf("if you want to move further without killing the opponent, press 1\n");
					if(board[row-1][C+1]!=0)
					{
						printf("Or if you want to kill the opponent on Right then press 2\n");
					}
					if(board[row-1][C-1]!=0)
					{
						printf("Or if you want to kill the opponent on left then press 3");
					}
					printf("and enter");
					scanf("%d", &userChooses);
					 
					//you can also move further without killing the opponent, as you wish
				
					//asks user, Or do you want to kill the opponent
				}
				else
				{
							board[row-1][C+1]='P';	//if the user wants to move
							board[row][C]=0;	// the old position of pawn becomes null
				}
						
					if(userChooses==1)
					{
							//row--;
							board[row-1][C]='P';	//if the user wants to move
							board[row][C]=0;	// the old position of pawn becomes null
					
					}
					else if(userChooses==2)
					{
						if(board[row-1][C+1]!=0)
						{	//row--;
							board[row-1][C+1]='P';	//if the user wants to move
							board[row][C]=0;	// the old position of pawn becomes null
						}
					}	
					else if(userChooses==3)
					{
						board[row-1][C-1]='P';	//if the user wants to move
						board[row][C]=0;	// the old position of pawn becomes null
					}
						
					
				
			}
			else if(board[row-1][C]==0)		//if the upper condtion is false
			{
					//automatically moves the pawn one position further		
				board[row-1][C]='P';	//if the user wants to move
				board[row][C]=0;	// the old position of pawn becomes null

			}


	}		//one condition is left that if the board finishes
	
			//		End of player 1 pawns
	
	// player 2 pawn conditions
	if(board[row][C]=='p')
	{
			if( (board[row+1][C+1]!=0) || (board[row+1][C-1]!=0) )
			{
				
				
				if(board[row+1][C]==0)
				{
					printf("Now you have two choices for moving this pawn\n");
					printf("if you want to move further without killing the opponent, press 1\n");
					printf("Or if you want to kill the opponent on Right then press 2");
					if(board[row+1][C-1]!=0)
					{
						printf("\nOr if you want to kill the opponent on left then press 3");
					}
					printf("and enter");
					scanf("%d", &userChooses);
					 
					//you can also move further without killing the opponent, as you wish
				
					//asks user, Or do you want to kill the opponent
				}
				else
				{
							board[row+1][C+1]='p';	//if the user wants to move
							board[row][C]=0;	// the old position of pawn becomes null
				}
						
					if(userChooses==1)
					{
							//row--;
							board[row+1][C]='p';	//if the user wants to move
							board[row][C]=0;	// the old position of pawn becomes null
					
					}
					else if(userChooses==2)
					{
						if(board[row+1][C+1]!=0)
						{	//row--;
							board[row-1][C+1]='p';	//if the user wants to move
							board[row][C]=0;	// the old position of pawn becomes null
						}
					}	
					else if(userChooses==3)
					{
						board[row+1][C-1]='p';	//if the user wants to move
						board[row][C]=0;	// the old position of pawn becomes null
					}
						
					
				
			}
			else if(board[row-1][C]==0)		//if the upper condtion is false
			{
					//automatically moves the pawn one position further		
				board[row-1][C]='p';	//if the user wants to move
				board[row][C]=0;	// the old position of pawn becomes null

			}


	}		//one condition is left that if the board finishes
	//		End of player 2 pawns
	
	if(board[row][C]=='Q' || board[row][C]=='q')
	{
		int desire=queen(board, 8, row, C);
		int r=desire/10;
		int co=desire%10;
		
		if(turn%2==0)
		board[r][co]='q';
	}
	
	if(board[row][C]=='R' || board[row][C]=='r')
	{
		int desire=rook(board, 8, row, C);
		int r=desire/10;
		int co=desire%10;
		
		if(turn%2==0)
		board[r][co]='r';
	}
	
	if(board[row][C]=='B' || board[row][C]=='b')
	{
		int desire=bishop(board, 8, row, C);
		int r=desire/10;
		int co=desire%10;
		
		if(turn%2==0)
		board[r][co]='r';
	}
	
	if(board[row][C]=='K' || board[row][C]=='k')
	{
		int desire=rook(board, 8, row, C);
		int r=desire/10;
		int co=desire%10;
		
		if(turn%2==0)
		board[r][co]='k';
	}
	
	printf("\n");
	printf("    0    1    2    3    4    5    6    7\n");
	printf("  ________________________________________\n\n");
	for(i = 0; i < 8; ++i)
	{
		printf("%d ", i);
	    for(j = 0; j < 8; ++j)
		{
	    	printf("| %c  ",board[i][j]);
    	}
		printf("\b|");
    	printf("\n");
		printf("  ---------------------------------------\n");
	}	
		
		turn++;
		
	}	
	
	
}


int queen(char arr[][8], int size, int row, int column)
{
	/* 						start of queen's conditions								*/
	int i,j, a, b, c, d, e, f, lH, rH, uV, dV;
	int check =0;
	int desiredRow=0, desiredColumn=0;
		
		printf("You can move on these positions:\n");
		int x=0, i=row, j=column;
		
		while(i>0 && j>0)	//moving left upwards diagonally like this '\'
		{
			if(i>0 && j>0)
			{
				i--;
				j--;
			}
			printf("[%d][%d]  ", i, j);
			if(arr[i][j]!=0)
			break;	
			
		}
		
		
		a=row, b=column;
		while(a<7 && b<7)	//moving right downwards diagonally like this '\'
		{
			a++;
			b++;
			printf("[%d][%d]  ", a, b);
			if(arr[a][b]!=0)
			break;
		}
		printf("\n");
		c=row, d=column;
		while(c>0 && d<7)	//moving right upwards diagonally like this '/'
		{
			if(c>0 && d<7)
			{
				c--;
				d++;
			}
			printf("[%d][%d]  ", c, d);
			if(arr[c][d]!=0)
			break;
		}
		
		e=row, f=column;
		while(e<7 && f>0)	//moving left downwards diagonally like this '/'
		{
			e++;
			f--;
			printf("[%d][%d]  ", e, f);
			if(arr[e][f]!=0)
			break;
		}
		printf("\n");
	
		lH=column;
		while(lH>0)	//lH means moving left horizontally
		{
			lH--;
			printf("[%d][%d]  ", row, lH);
			if(arr[row][lH]!=0)
			break;
		}

		rH=column;
		while(rH<7)	//rH means moving right horizontally
		{
			rH++;
			printf("[%d][%d]  ", row, rH);
			if(arr[row][rH]!=0)
			break;
		}
		printf("\n");

		uV=row;
		while(uV>0)	//uV means moving up vertically
		{
			uV--;
			printf("[%d][%d]  ", uV, column);
			if(arr[uV][column]!=0)
			break;
		}

		dV=row;
		while(dV>0)	//dV means moving down vertically
		{
			dV++;
			printf("[%d][%d]  ", dV, column);
			if(arr[dV][column]!=0)
			break;
		}
		printf("\n");
		
		printf("Enter your desired position? for eg: 2,4");
		do
		{
			scanf("%d,%d", &desiredRow, &desiredColumn);
			if( ((desiredRow<row && desiredColumn<column) && (desiredRow>=i && desiredColumn>=j)) 
				|| ( (desiredRow>row && desiredColumn>column) && (desiredRow<=a && desiredColumn<=b) ) 
				|| ( (desiredRow<row && desiredRow>=c) && (desiredColumn>column && desiredColumn<=d) )
				|| ( (desiredRow>row && desiredRow<=e) && (desiredColumn<column && desiredColumn>=f) ) )
				check=1;
			else
			printf("your desired position is not valid");
		}
		while(check==0);
		
		arr[desiredRow][desiredColumn]='Q';
		arr[row][column]=0;
	
	

	
}

int bishop(char arr[][8], int size, int row, int column)
{
	/* 						start of bishop's conditions								*/
	int i,j, a, b, c, d, e, f, lH, rH, uV, dV;
	int check =0;
	int desiredRow=0, desiredColumn=0;
		
		printf("You can move on these positions:\n");
		int x=0, i=row, j=column;
		
		while(i>0 && j>0)	//moving left upwards diagonally like this '\'
		{
			if(i>0 && j>0)
			{
				i--;
				j--;
			}
			printf("[%d][%d]  ", i, j);
			if(arr[i][j]!=0)
			break;	
			
		}
		
		
		a=row, b=column;
		while(a<7 && b<7)	//moving right downwards diagonally like this '\'
		{
			a++;
			b++;
			printf("[%d][%d]  ", a, b);
			if(arr[a][b]!=0)
			break;
		}
		printf("\n");
		c=row, d=column;
		while(c>0 && d<7)	//moving right upwards diagonally like this '/'
		{
			if(c>0 && d<7)
			{
				c--;
				d++;
			}
			printf("[%d][%d]  ", c, d);
			if(arr[c][d]!=0)
			break;
		}
		
		e=row, f=column;
		while(e<7 && f>0)	//moving left downwards diagonally like this '/'
		{
			e++;
			f--;
			printf("[%d][%d]  ", e, f);
			if(arr[e][f]!=0)
			break;
		}
		printf("\n");
	
		printf("Enter your desired position? for eg: 2,4");
		do
		{
			scanf("%d,%d", &desiredRow, &desiredColumn);
			if( ((desiredRow<row && desiredColumn<column) && (desiredRow>=i && desiredColumn>=j)) 
				|| ( (desiredRow>row && desiredColumn>column) && (desiredRow<=a && desiredColumn<=b) ) 
				|| ( (desiredRow<row && desiredRow>=c) && (desiredColumn>column && desiredColumn<=d) )
				|| ( (desiredRow>row && desiredRow<=e) && (desiredColumn<column && desiredColumn>=f) ) )
				check=1;
			else
			printf("your desired position is not valid");
		}
		while(check==0);
		
		arr[desiredRow][desiredColumn]='B';
		arr[row][column]=0;
	

}


int rook(char arr[][8], int size, int row, int column)
{
	/* 						start of rook's conditions								*/
	int lH, rH, uV, dV;
	int check =0;
	int desiredRow=0, desiredColumn=0;
		
		printf("You can move on these positions:\n");
		
		lH=column;
		while(lH>0)	//lH means moving left horizontally
		{
			lH--;
			printf("[%d][%d]  ", row, lH);
			if(arr[row][lH]!=0)
			break;
		}

		rH=column;
		while(rH<7)	//rH means moving right horizontally
		{
			rH++;
			printf("[%d][%d]  ", row, rH);
			if(arr[row][rH]!=0)
			break;
		}
		printf("\n");

		uV=row;
		while(uV>0)	//uV means moving up vertically
		{
			uV--;
			printf("[%d][%d]  ", uV, column);
			if(arr[uV][column]!=0)
			break;
		}

		dV=row;
		while(dV>0)	//dV means moving down vertically
		{
			dV++;
			printf("[%d][%d]  ", dV, column);
			if(arr[dV][column]!=0)
			break;
		}
		printf("\n");
		
		printf("Enter your desired position? for eg: 2,4");
			scanf("%d,%d", &desiredRow, &desiredColumn);
		
		arr[desiredRow][desiredColumn]='R';
		arr[row][column]=0;
	int g=(desiredRow*10)+desiredColumn;
	

return g;
}

int knight(char arr[][8], int size, int row, int column)
{
	/* 						start of knight's conditions								*/
	int i,j, a, b, c, d, e, f, g, h, l, m;
	int check =0;
	int desiredRow=0, desiredColumn=0;
		
		printf("You can move on these positions:\n");
	
		i=row-2, j=column+1;
		a=row-2, b=column-1;
		c=row-1, d=column-2;
		e=row-1, f=column-2;
		g=row+1, h=column+2;
		l=row-1, m=column+2;

		if(row-2>=0 && column+1<=7 && arr[i][j]<92)
		printf("[%d][%d]  ", i, j);
	
		if(row-2>=0 && column+1<=7 && arr[a][b]<92)	
		printf("[%d][%d]  ", a, b);

		if(row-1>=0 && column-2>=0 && arr[c][d]<92)
		printf("[%d][%d]  ", c, d);
	
		if(row-1>=0 && column-2>=0 && arr[i][j]<92)
		printf("[%d][%d]  ", e, f);
	
		if(row+1<=7 && column+2<=7 && arr[i][j]<92)
		printf("[%d][%d]  ", g, h);
	
		if(row-1>=0 && column+2<=7 && arr[i][j]<92)
		printf("[%d][%d]  ", l, m);

		printf("\n");
	
		printf("Enter your desired position? for eg: 2,4");
		
		scanf("%d,%d", &desiredRow, &desiredColumn);
		
		arr[desiredRow][desiredColumn]='K';
		arr[row][column]=0;
	
}


