//#include <stdio.h>
//#include <stdlib.h>

//#define R 15
//#define C 30

// gorrila[1][Y] is gorrila1's y location

#include "terminalmode.h"

#define G0 0  // gorrila0
#define G1 1  // gorrila1
#define X  0  // gorrila x
#define Y  1  // gorrila y
/*
init( char garea[R][C])
{int i, j;

 for(i=0; i<R; i++)
 {  for(j=0; j<C; j++)
       garea[i][j]=' ';
 }
}
show( char garea[R][C])
{int i, j;

 for(i=0; i<C; i++)
    printf("=");
 printf("\n");
 //for(i=0; i<R; i++)
// for(i=R; i>=0; i--)
 for(i=1; i<=R; i++)
 {  for(j=0; j<C; j++)
      printf("%c", garea[R-i][j]);
    printf("\n");
 }
 for(i=0; i<C; i++)
    printf("=");
 printf("\n");
}
*/



int main(void)
{
int col, row, i,j, j0;
int takasa, haba;

//char game[R][C];
char ch='a';

int gorrila[2][2];

// filling the gaming area
//
//  init(game);

//
//set_terminal_reset();
//
led_canvas_clear();


  j0= col = 0;
  do
  { takasa = rand()%8;
    haba = rand()%3 + 3; // rand()%3 is bad
    j0=col;
    col= col+haba;
    if(col >= LED_COL) col = LED_COL;
printf("takasa=%d,haba=%d  --j0=%d to  col=%d\n", 
	  takasa, haba,      j0,       col );

    for(row=0; row<takasa; row++)
    {//printf("row=%d: ", row );
     for(j=j0; j<col; j++)
     {//   printf(" %d  ", j );
        //game[row][j] = ch;
        text_canvas_write_char(LED_ROW - row-1,j, ch, 200);
     }
     //printf("\n");
    }
    ch++;
   // show(game);
   // printf("----------------\n");


  }while(col<LED_COL);

  // show(game);


  // gorrila0, gorrila1  locations

  gorrila[G0][X] = rand()%10;
  gorrila[G1][X] = LED_COL - rand()%10;
  printf("g0 x=%d  g1 x=%d\n", gorrila[G0][X], gorrila[G1][X]);


  
  // look for ' ' in gorrila0 and gorrila1's y location
  for(i=0; i<LED_ROW; i++)
  { char data;

    if( led_canvas_peek(i,gorrila[G0][X], &data) ) 
    { // if here, it is text data 
      if( data == ' ')
      { text_canvas_write_char(LED_ROW - i-1,gorrila[G0][X],'@', 100);
        gorrila[G0][Y]=i;
        break;
      }
    }

  }
  for(i=0; i<LED_ROW; i++)
  { char data;

    if( led_canvas_peek(i,gorrila[G0][X], &data) ) 
    { // if here, it is text data
      if(data==' ')
      { text_canvas_write_char(LED_ROW - i-1, gorrila[G1][X], '$', 102);
        gorrila[G1][Y]=i;
        break;
      }
    }

  }

  //show(game);

  // let's shoot from (0.0)
  // angle 45 deg with veolocity 1
  //
  // y = a(x*x)
{
double aa, yy, xx,  delta_x, x0,y0;
  
  x0=gorrila[G0][X];
  y0=gorrila[G0][Y];
  delta_x = 2.0;

  double A;
  x0= 0.0;   //3.0;   //0.0;
  y0= 7.9;   //4.0;   //7.0;
  A = -0.03;

  /* given gravity, A, and tangent, dY, at (x0, y0);
   * for y=A*x*x + B*x + C
   * B = dY - 2*A*x0;
   * C = y0 - (A*x0*x0 + B*x0) 
   * 
   */

  printf("x0,y0 = %5.1lf, %5.1lf\n", x0, y0);
  double dY = 0.5;
  double B;

  for(xx=x0;  xx<LED_COL;   xx=xx+delta_x)
   {
/*
     j=xx;
     i=yy;
     game[i][j]='*';
     i++;
*/
     B= (dY - 2*A*x0);
     yy =
     A*xx*xx + B*xx + (y0 - (A*x0*x0 + B*x0)) ;

     printf("yy=%5.1lf, xx=%5.1lf  (xx-x0)=%5.1lf\n",
             yy ,    xx,      (xx-x0) );
     if( yy <0 )
       break;

     j=xx;
     i=yy;

     printf("====== x=%d    y=%d\n", j, i);
     if((i<LED_ROW) && (j<30))
     text_canvas_write_char(LED_ROW - i-1, j, '*', 104);

     //show(game);
     led_canvas_display();
     sleep(1);
   }   
  }

  //show(game);
  //led_canvas_display();


return 0;

}
