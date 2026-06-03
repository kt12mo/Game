/******************************************* 
 *
 *  Snake.c
 *
 * History:
 * 2022/06/22  k.imamura    Initial coding
 * 2022/07/13  k.imamura    Added:
 *                          1 check snake eating itself
 *                          2 ansi color
 * 
 *******************************************/

#include "terminalmode.h"

#define ROW 12 
#define COL 20 

#define SNAKEROW 1
#define SNAKECOL 2
#define MAXSNAKE 240 


initscreen(char game[ROW][COL])
     {int i, j;

       for(i=0; i<ROW; i++)
       { for(j=0; j<COL; j++)
         { game[i][j]=' ';
         }
       }
       i=rand()%ROW;
       j=rand()%COL;
       game[i][j]='$';
     }

//showscreen()
showscreen(char game[ROW][COL])
{int i, j;

       printf(" --------------------"); printf("%c%c",0xD, 0xA);
       for(i=ROW-1; i>=0; i--)
       {
         printf("|");
	 for(j=0; j<COL; j++)
         {  //printf("%2d,%2d ", i, j); //, game[i][j]);
		 if( game[i][j] == '@')
		 { printf(HGRN);
                   printf("%c", game[i][j]);
		 }
		 else if(game[i][j] == '*')
		 { printf(GRN);
                   printf("%c", game[i][j]);
		 }
		 else
		 {
                   printf("%c", game[i][j]);
		 }

		 printf(CRESET);
         }
         printf("|%c%c",0xD, 0xA);
       }
       //printf("%c", 0x0D);
       printf(" --------------------"); printf("%c%c",0xD, 0xA);
}

init_snake(char snake[][4], char game[][COL],int row, int col)
{int i;

  //printf("init_snake %d %d\n", row,col);
  for(i=1; i<MAXSNAKE; i++ )
  {
	  snake[i][0] = 0;
	  snake[i][SNAKEROW] = 0;
	  snake[i][SNAKECOL] = 0;
	  snake[i][3] = 0; 
  }

  snake[0][0] = 1;
  snake[0][SNAKEROW] = row;
  snake[0][SNAKECOL] = col;
  snake[0][3] = 0;

  game[row][col] = '*';
}

// snake debugging
snake_check(char snake[][4], int snakelen)
{int i;

printf("snake_check  snakelen=%d", snakelen);
printf("%c%c", 0xD, 0xA);
  for(i=0; i<snakelen; i++)
  { 
  printf("snake row=%d  ", snake[i][SNAKEROW]);
  printf("col=%d",         snake[i][SNAKECOL]);
	printf("%c%c", 0xD, 0xA);
  }
}

slide_snake(char snake[][4], int snakelen)
{ int i;
// shift snake to tail, leave snakehead free 

  for(i=snakelen; i>0; i--)
  { 
  snake[i][0] = snake[i-1][0];
  snake[i][1] = snake[i-1][1];
  snake[i][2] = snake[i-1][2];
  snake[i][3] = snake[i-1][3];
  }
}


int mv_snake(char snake[][4], char game[][COL], int snakelen, char ch)
{
  int i, retval;
  int newheadrow, newheadcol; // new snake head location

  //snake_check(snake, snakelen);
  newheadrow = snake[0][SNAKEROW]; 
  newheadcol = snake[0][SNAKECOL]; 

        if( ch == 'l' )
        { // go left 
	   if( snake[0][SNAKECOL]-1 >= 0 )
	   {
	      newheadcol = snake[0][SNAKECOL] - 1;
	   }
	   else return(snakelen);
        }
        else if( ch == 'r' )
        { // go right
	   if( snake[0][SNAKECOL]+1 < COL )
	   {
	      newheadcol = snake[0][SNAKECOL] + 1;
	   }
	   else return(snakelen);
        }
        else if( ch == 'u' )
        { // go up
	   if( snake[0][SNAKEROW]+1 < ROW )
	   {
	      newheadrow = snake[0][SNAKEROW] + 1;
	   }
	   else return(snakelen);
        }
        else if( ch == 'd' )
        { // go down
	   if( snake[0][SNAKEROW]-1 >= 0 )
	   {
              newheadrow = snake[0][SNAKEROW] - 1;
	   }
	   else return(snakelen);
        }
	else return(snakelen);

     //snake_check(snake, snakelen);
      { int i;
        for( i=1; i<snakelen; i++)
        {
          if( (newheadrow == snake[i][SNAKEROW]) &&
              (newheadcol == snake[i][SNAKECOL])  )
          { // snake eating itself!!!
              game[ newheadrow ][ newheadcol ] = '!';
              showscreen(game);
              printf("\n - GAME OVER -\n");
              return( -1 );
          }
        }
      }

     slide_snake(snake, snakelen);
     snake[0][SNAKECOL] = newheadcol; //snake[0][SNAKECOL] - 1;
     snake[0][SNAKEROW] = newheadrow; //snake[0][SNAKEROW] + 1;

      // done snake updating

      if( game[snake[0][SNAKEROW]] [snake[0][SNAKECOL]]=='$')
      { //printf("HIT\n"); getchar();
        snakelen++; //exit(0);

        { int i, r, c;

          do_again:    // make sure we do not put $ on the snake !!
          r= rand()%ROW;  // This is not a good random number....
          c= rand()%COL;  // This is not a good random number....

          //check if snake is there. If so, goto do_again and do over.  
          for(i=0; i<snakelen; i++) //check if snake is there  
          { 
             if( (snake[i][SNAKEROW] == r) &&  (snake[i][SNAKECOL] == c) ) 
                 goto do_again;
          }
          game[r][c]='$';
        }
      }
      else  // erase the snake tail after moved forward 
      {
        game[snake[snakelen][SNAKEROW]] [snake[snakelen][SNAKECOL]]= ' ';
      }


//  printf("snake_check 1\n");
//  snake_check(snake, snakelen);

      //Write the snake to the gaming board
      game[snake[0][SNAKEROW]] [snake[0][SNAKECOL]]='@';
      for(i=1; i<snakelen; i++)
      {
     // printf("snake[%d][row=%d, col=%d]\n",
     //            i,snake[i][SNAKEROW],snake[i][SNAKECOL]);

        game[snake[i][SNAKEROW]] [snake[i][SNAKECOL]]='*';
      }
       
// printf("mv_snake for done   snakelen=%d\n",  snakelen); getchar();
   return( snakelen );
}


int show_menu()
{
     printf("UP       up arrow key %c%c",0xD, 0xA);
     printf("Right right arrow key %c%c",0xD, 0xA);
     printf("LEFT   left arrow key %c%c",0xD, 0xA);
     printf("Down   down arrow key %c%c",0xD, 0xA);
     printf("'x' to quit%c%c",0xD, 0xA);
}

int main(int argc, char *argv[]) 
{
  unsigned int usec; // micro second
  unsigned int counter, speed; // screen updata and object moving spped
  time_t   t;

  char ch;
  char str[40];
  int  i, j, n, t0, snakelen, invaderROW, invaderCOL;
  char game[ROW][COL];
  char snake[MAXSNAKE][4]; // 0 show, 1 row, 2 col, 3 reserved
//  int  test;


    usec=700000; // our default sleep duration
    speed=13; // our default speed
    srand( time(&t) ); // 17 should be changed later...

   initscreen(game); // fill game[][] with ' ', clear game field 

   /*****************************************/
   /* Set keyboard input non-canonical mode */
   /*****************************************/

    set_terminal_reset(); // set terminal raw mode

   /*****************************/
   /*   set Non-blocking        */
   /*****************************/

   // nonblock(); //fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);

   /*****************************/

    snakelen = 1;
    init_snake(snake, game, ROW/2 , COL/2);
    counter = 0;
    show_menu();
    printf("Hit return to start\n");
    getchar();

    while (1) 
    {
      counter++;
      clrscr(); // clear screen, printing starts at upper-left corner
      showscreen(game);
      show_menu();
     printf("%c%c",0xD, 0xA);
     printf("Your Score is %d.", snakelen);
     printf("%c%c",0xD, 0xA);
      counter++;
      
   
   /*******************************/
   /* Read one byte from keyboard */
   /*******************************/
      // read (0, &ch, 1);
      ch = getchar();
      //printf("--%0X--\n", ch);
      if( ch == 0x1B )
      { ch = getchar();  //printf("--%0X--\n", ch);
        ch = getchar(); // printf("--%0X--\n", ch);

	if(ch==0x41)        ch='u';
	else if(ch==0x42)   ch='d';
	else if(ch==0x43)   ch='r';
	else if(ch==0x44)   ch='l';
      }


     // sleep (1);

   /*****************************/

        if( ch == 'x' )
            {   break;
            }

     snakelen = mv_snake(snake, game, snakelen, ch);
     if( snakelen == -1) // then game is over
     {  reset_terminal_mode();
        break; //return 0;
     }


     /* loop below is for debugging */
/*
     {
      int ii;
      for(ii=0; ii<snakelen; ii++)
      { printf("snake[%d][%d,%d]\n",
             ii, snake[ii][SNAKEROW],snake[ii][SNAKECOL]);
      }
      getchar();
     }
*/

    } // end while(1)

    reset_terminal_mode();
    // block();
    // ch=getkbchar(); //read (0, &ch, 1);
    // printf("ch=%c ch=%X\n", ch,ch);
    printf("%c%c\n", 0xA,0xD);

    return 0; 
}
