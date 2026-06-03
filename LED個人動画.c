#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include "led-matrix-c.h"
#include "mnb_bmp.h" 

int main(int argc, char const **argv)
{
    struct RGBLedMatrixOptions options;
    struct RGBLedMatrix *matrix;
    struct LedCanvas *offscreen_canvas;
    char rgb_sequence[] = "GBR";

    memset(&options, 0, sizeof(options));
    options.rows = options.cols = 64;
    options.led_rgb_sequence = rgb_sequence;
    matrix = led_matrix_create_from_options(&options, &argc, (char***)&argv);
    if (matrix == NULL) return 1;
    offscreen_canvas = led_matrix_create_offscreen_canvas(matrix);

    pthread_t recthread;
    if(pthread_create(&recthread, NULL, (void*)takeTimelapse, NULL)) {
        return -1;
    }

    int width, height;
    led_canvas_get_size(offscreen_canvas, &width, &height);





//みなさんが書き換えるのはこれ以降の部分
//あらかじめ宣言されいて使用可能な変数は，以下の4つ
//  int width, heigh; //width=64, height=64です
//  struct RGBLedMatrix *matrix; //LEDディスプレイパネルを表す変数
//  struct LedCanvas *offscreen_canvas; //バッファ
//LEDディスプレイパネルを光らせるのに使用する特別な関数は以下の4つのみ
//  void led_canvas_clear(struct LedCanvas *canvas); //LEDディスプレイパネル前面を黒にする
//  void led_canvas_set_pixel(struct LedCanvas *canvas, int x, int y,
//                            uint8_t r, uint8_t g, uint8_t b); //canvasのx,yにr,g,bの色を出す
//  struct LedCanvas *led_matrix_swap_on_vsync(struct RGBLedMatrix *matrix,
//                                             struct LedCanvas *canvas); //canvasの内容をLEDパネルに転送
//  int usleep(useconds_t usec); //usecマイクロ秒待機する．usecは1000000（1秒待つ）

led_canvas_clear(offscreen_canvas);

int i,j;

for (i = 0; i < 7; ++i) {
        for ( j = 10; j < 64; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138,82);
        }}
    for ( i = 7; i < 64; ++i) {
        for ( j = 10; j < 17; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138, 82);
        }}
    for ( i = 42; i < 64; ++i) {
        for ( j = 10; j < 63; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138, 82);
        }}
    for ( i = 7; i < 64; ++i) {
        led_canvas_set_pixel(offscreen_canvas, i, 63, 189, 138, 82);
    }
    int centerX = 16;
    int centerY = 53;
    int radius = 9;

    for (j = centerY - radius; j <= centerY + radius; ++j) {
        for (i = centerX - radius; i <= centerX + radius; ++i) {
            if ((i - centerX) * (i - centerX) + (j - centerY) * (j - centerY) <= radius * radius) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 255,255,0); 
            }
        }
    }

    int pinkX = 13;
    int pinkY = 39;
    int pinkr = 6;

    for (j = pinkY - pinkr; j <= pinkY + pinkr; ++j) {
        for (i = pinkX - pinkr; i <= pinkX + pinkr; ++i) {
            if ((i - pinkX) * (i - pinkX) + (j - pinkY) * (j - pinkY) <= pinkr * pinkr) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 255,105,180); 
            }
        }
    }

int gX =30;
    int gY = 38;
    int gr = 12;

    for (j = gY - gr; j <= gY + gr; ++j) {
        for (i = gX - gr; i <= gX + gr; ++i) {
            if ((i - gX) * (i - gX) + (j - gY) * (j - gY) <= gr * gr) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 124,252,99); 
            }
        }
    }


    int oX = 13;
    int oY = 24;
    int or = 7;

    for (j = oY - or; j <= oY + or; ++j) {
        for (i = oX - or; i <= oX + or; ++i) {
            if ((i - oX) * (i - oX) + (j - oY) * (j - oY) <= or * or) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 255,140,0); 
            }
        }
    }

    int pX = 21;
    int pY = 20;
    int pr = 4;

    for (j = pY - pr; j <= pY + pr; ++j) {
        for (i = pX - pr; i <= pX + pr; ++i) {
            if ((i - pX) * (i - pX) + (j - pY) * (j - pY) <= pr * pr) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 186,85,211); 
            }
        }
    }


    int puX = 7;
    int puY = 5;
    int pur = 4;

    for (j = puY - pur; j <= puY + pur; ++j) {
        for (i = puX - pur; i <= puX + pur; ++i) {
            if ((i - puX) * (i - puX) + (j - puY) * (j - puY) <= pur * pur) {
                // 円の内部に色をセットj
                led_canvas_set_pixel(offscreen_canvas, i, j, 186,85,211); 
            }
        }
    }


    for (j = puY - pur; j <= puY + pur; ++j) {
        for (i = puX - pur; i <= puX + pur; ++i) {
            if ((i - puX) * (i - puX) + (j - puY) * (j - puY) <= pur * pur) {
                led_canvas_set_pixel(offscreen_canvas, i, j,  186,85,211); // 円の内部に色をセット
            }
        }
    }

    int steps = 16; // 移動するステップ数
    int moveDelayUs = 100000; // 移動の間隔（マイクロ秒）
    int step;
    for ( step = 0; step < steps; ++step) {
        // 現在の円を消す
        for (j = puY - pur; j <= puY + pur; ++j) {
            for (i = puX - pur; i <= puX + pur; ++i) {
                if ((i - puX) * (i - puX) + (j - puY) * (j - puY) <= pur * pur) {
                    led_canvas_set_pixel(offscreen_canvas, i, j, 0, 0, 0); // 現在の位置をクリア
                }
            }
        }

        // 新しい位置に円を描画
        puX += 1;
        for (j = puY - pur; j <= puY + pur; ++j) {
            for (i = puX - pur; i <= puX + pur; ++i) {
                if ((i - puX) * (i - puX) + (j - puY) * (j - puY) <= pur * pur) {
                    led_canvas_set_pixel(offscreen_canvas, i, j, 186, 85, 211); // 新しい位置に円を描画
                }
            }
        }

        // LEDディスプレイに反映させる
        led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(500000); // 少し待機する
    }

 led_matrix_swap_on_vsync(matrix, offscreen_canvas);

    // 真下に移動するループ
    int moveDownSteps = 7; // 下に移動するステップ数
    int Downstep;
    for (Downstep = 0; Downstep < moveDownSteps; ++Downstep) {
        // 現在の円を消す
        for (j = puY - pur; j <= puY + pur; ++j) {
            for (i = puX - pur; i <= puX + pur; ++i) {
                if ((i - puX) * (i - puX) + (j - puY) * (j - puY) <= pur * pur) {
                    led_canvas_set_pixel(offscreen_canvas, i, j, 0, 0, 0); // 現在の位置をクリア
                }
            }
        }

  puY += 1;
        for (j = puY - pur; j <= puY + pur; ++j) {
            for (i = puX - pur; i <= puX + pur; ++i) {
                if ((i - puX) * (i - puX) + (j - puY) * (j - puY) <= pur * pur) {
                    led_canvas_set_pixel(offscreen_canvas, i, j, 186, 85, 211); // 新しい位置に円を描画
                }
            }
        }
         led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(500000); // 少し待機する
    }

for ( i = 7; i < 64; ++i) {
        for ( j = 7; j < 10; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 0, 0,0);
        }
    }


int puwX = 21;
int puwY = 20;
int puwr = 4;
for (j = puwY - puwr; j <= puwY + puwr; ++j) {
        for (i = puwX - puwr; i <= puwX + puwr; ++i) {
            if ((i - puwX) * (i - puwX) + (j - puwY) * (j - puwY) <= puwr * puwr) {
                led_canvas_set_pixel(offscreen_canvas, i, j,  0,0,0); // 円の内部に色をセット
            }
        }
    }
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(500); // 少し待機する

for ( i = 7; i < 64; ++i) {
        for ( j = 10; j < 17; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138, 82);
        }
    }
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(500000); // 少し待機する

    int owX = 21;
    int owY = 16;
    int owr = 7;

    for (j = owY - owr; j <= owY + owr; ++j) {
        for (i = owX - owr; i <= owX + owr; ++i) {
            if ((i - owX) * (i - owX) + (j - owY) * (j - owY) <= owr * owr) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 255,140,0); 
            }
        }
    }
    led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(500000); // 少し待機する
        
    int opwwX = 13;
    int opwwY = 24;
    int opwwr = 7;

    for (j = opwwY - opwwr; j <= opwwY + opwwr; ++j) {
        for (i = opwwX - opwwr; i <= opwwX + opwwr; ++i) {
            if ((i - opwwX) * (i - opwwX) + (j - opwwY) * (j - opwwY) <= opwwr * opwwr) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 0,0,0); 
            }
        }
    }

    led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(500); // 少し待機する

   for ( i = 7; i < 64; ++i) {
        for ( j = 10; j < 17; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138, 82);
        }
    }
        led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(500); // 
        
    //オレンジ色を黒にする//
for ( i = 7; i < 64; ++i) {
        for ( j = 10; j < 17; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138, 82);
        }
}
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(500); // 少し待機する

for(i=8;i<41;++i){
    for(j=17;j<26;++j){
        led_canvas_set_pixel(offscreen_canvas, i, j, 0, 0, 0);
    }
}
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(500000);

    int wpinkX = 14;
    int wpinkY = 28;
    int wpinkr = 6;

    for (j = wpinkY - wpinkr; j <= wpinkY + wpinkr; ++j) {
        for (i = wpinkX - wpinkr; i <= wpinkX + wpinkr; ++i) {
            if ((i - wpinkX) * (i - wpinkX) + (j - wpinkY) * (j - wpinkY) <= wpinkr * wpinkr) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 255,105,180); 
            }
        }
    }
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
usleep(500000);

for(i=8;i<20;++i){
    for(j=19;j<45;++j){
        led_canvas_set_pixel(offscreen_canvas, i, j, 0, 0, 0);
    }
}
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(1000000); 

    int wyX = 13;
    int wyY = 35;
    int wyr = 9;

    for (j = wyY - wyr; j <= wyY + wyr; ++j) {
        for (i = wyX - wyr; i <= wyX + wyr; ++i) {
            if ((i - wyX) * (i - wyX) + (j - wyY) * (j - wyY) <= wyr * wyr) {
           led_canvas_set_pixel(offscreen_canvas, i, j, 255,255,0); 
            }
        }
    }   
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(1000000);

 int wwyX = 13;
    int wwyY = 35;
    int wwyr = 9;

    for (j = wwyY - wwyr; j <= wwyY + wwyr; ++j) {
        for (i = wwyX - wwyr; i <= wwyX + wwyr; ++i) {
            if ((i - wwyX) * (i - wwyX) + (j - wwyY) * (j - wwyY) <= wwyr * wwyr) {
           led_canvas_set_pixel(offscreen_canvas, i, j, 0,0,0); 
            }
        }
    }   
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(300000);

int centerXw = 16;
    int centerYw = 53;
    int radiusw = 9;

    for (j = centerYw - radiusw; j <= centerYw + radiusw; ++j) {
        for (i = centerXw - radiusw; i <= centerXw + radiusw; ++i) {
            if ((i - centerXw) * (i - centerXw) + (j - centerYw) * (j - centerYw) <= radiusw * radiusw) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 0,0,0); 
            }
        }
    }
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(300000); 

for (i = 0; i < 7; ++i) {
        for ( j = 10; j < 64; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138,82);
        }}
    for ( i = 7; i < 64; ++i) {
        for ( j = 10; j < 17; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138, 82);
        }}
    for ( i = 42; i < 64; ++i) {
        for ( j = 10; j < 63; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138, 82);
        }}
    for ( i = 7; i < 64; ++i) {
        led_canvas_set_pixel(offscreen_canvas, i, 63, 189, 138, 82);
    }
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(100000);

    int wgX =15;
    int wgY = 46;
    int wgr = 12;

    for (j = wgY - wgr; j <= wgY + wgr; ++j) {
        for (i = wgX - wgr; i <= wgX + wgr; ++i) {
            if ((i - wgX) * (i - wgX) + (j - wgY) * (j - wgY) <= wgr * wgr) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 124,252,99); 
            }
        }
    }
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(1000000);

for ( i = 7; i < 42; ++i) {
        for ( j = 18; j < 62; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 0, 0, 0);
        }
}


for (i = 0; i < 7; ++i) {
        for ( j = 10; j < 64; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138,82);
        }}
    for ( i = 7; i < 64; ++i) {
        for ( j = 10; j < 17; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138, 82);
        }}
    for ( i = 42; i < 64; ++i) {
        for ( j = 10; j < 63; ++j) {
            led_canvas_set_pixel(offscreen_canvas, i, j, 189, 138, 82);
        }}
    for ( i = 7; i < 64; ++i) {
        led_canvas_set_pixel(offscreen_canvas, i, 63, 189, 138, 82);
    }

led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(100000);

    int A =23;
    int B = 46;
    int C = 17;

    for (j = B - C; j <= B + C; ++j) {
        for (i = A - C; i <= A + C; ++i) {
            if ((i - A) * (i - A) + (j - B) * (j - B) <= C * C) {
                // 円の内部に色をセット
                led_canvas_set_pixel(offscreen_canvas, i, j, 255,0,0); 
            }
        }
    }
led_matrix_swap_on_vsync(matrix, offscreen_canvas);
        usleep(5000000);



 return 0;
}
