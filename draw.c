#include <stdio.h>
#include <stdlib.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"

//Insert your line algorithm here
void draw_line(int x0, int y0, int x1, int y1, screen s, color c) {
  //switch points if necessary
  if (x0 > x1){
    int tempx = x0;
    int tempy = y0;
    x0 = x1;
    y0 = y1;
    x1 = tempx;
    y1 = tempy;
  }

  int x = x0;
  int y = y0;
  int a = y1 - y0;
  int b = (x1-x0) * -1;
  float m;
  if (y1 != y0){
    m = (float)(y1-y0)/(float)(x1-x0);
  } else {
    m = 0;
  }
  // printf("two points: (%d,%d), (%d,%d)\n",x0,y0,x1,y1);
  // printf("slope: %f\n",m);
  int d;

  //vertical lines
  if (x0 == x1){
    if (y0 > y1){
      int temppy = y0;
      y0 = y1;
      y1 = temppy;
    }
    y =y0;
    while (y <= y1){
      plot(s,c,x,y);
      y = y+1;
    }
  }

  //octants 2 and 6
  if (m > 1){
    d = a + 2*b;
    while (y <= y1){
      plot(s,c,x,y);
      if (d < 0){
        x = x+1;
        d = d + 2*a;
      }
      y = y+1;
      d = d + 2*b;
    }
  }

  //octants 1 and 5
  if (m <= 1 && m >= 0){
    d = 2*a + b;
    while (x <= x1){
      plot(s,c,x,y);
      if (d > 0){
        y = y+1;
        d = d + 2*b;
      }
      x = x+1;
      d = d + 2*a;
    }
  }

  // octants 8 and 4
  if (m < 0 && m >= -1){
    d = 2*a + b;
    while (x <= x1){
      plot(s,c,x,y);
      if (d < 0){
        y = y-1;
        d = d - 2*b;
      }
      x = x+1;
      d = d + 2*a;
    }
  }

  // octants 7 and 3
  if (m < -1){
    d = a + 2*b;
    while (y >= y1){
      plot(s,c,x,y);
      if (d > 0){
        x = x+1;
        d = d + 2*a;
      }
       y = y-1;
      d = d - 2*b;
    }
  }

}
