#include "GameLib.h"
using namespace sf;
const int Height = 17;
const int Width = 150;
float offsetX = 0, offsetY = 0;

String MenuMap[Height] = {
"000000000000000000000000000000000",
"0                               0",
"0                               0",
"0      w             w          0",
"0            w                  0",
"0                               0",
"0     kk                        0",
"0    k  k    k   k              0",
"0    k      kkk kkk             0",
"0    k       k   k              0",
"0    k  k                       0",
"0     kk              t0        0",
"0G                    00    t0  0",
"0       d    g      d 00    00  0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP0",
};

String TileMap[Height] = {
"000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000",
"0                                                                                                                                                    0",
"0                                                                                    w                                                               0",
"0      w            w                                  w                   w                               w                                         0",
"0                                      w                                       kk                                             w                      0",
"0       w                                                                     k  k    k    k                                                         0",
"0                      c                                                      k      kkk  kkk  w                                                     0",
"0                                                                       r     k       k    k                w                                        0",
"0                                                                      rr     k  k                                                                   0",
"0                                                                     rrr      kk                                                                    0",
"0               c    kckck                                           rrrrr                                                                           0",
"0                                      t0                           rrrrrrr                                     t0                                   0",
"0G                                     00              t0          rrrrrrrrr         G                          00                    t0             0",
"0           d    g       d             00              00         rrrrrrrrrrr         d           d             00                    00             0",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
"PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP",
};