#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int num[21][21];

int main() {
    int awin = 0;
    int bwin = 0;
    int x = 0;
    int y = 0;

    for (int i = 0; i < 21; i++) {
        num[0][i] = 3;
        num[20][i] = 3;
        num[i][0] = 3;
        num[i][20] = 3;
    }

    for (int i = 1; i < 20; i++) {
        for (int j = 1; j < 20; j++) {
            scanf("%d", &num[i][j]);
        }
    }

    for (int i = 1; i < 20 && !awin; i++) {
        for (int j = 1; j < 17 && !awin; j++) {
            if (num[i][j]==1&&num[i][j+1]==1&&num[i][j+2]==1&&num[i][j+3]==1) {
                if (num[i][j-1]==0||num[i][j+4]==0) {
                    awin = 1;
                    x = i;
                    y = j;
                }
            }
        }
    }

    for (int i = 1; i < 17 && !awin; i++) {
        for (int j = 1; j < 20 && !awin; j++) {
            if (num[i][j]==1&&num[i+1][j]==1&&num[i+2][j]==1&&num[i+3][j]==1) {
                if (num[i-1][j]==0||num[i+4][j]==0) {
                    awin = 1;
                    x = i;
                    y = j;
                }
            }
        }
    }

    for (int i = 1; i < 17 && !awin; i++) {
        for (int j = 1; j < 17 && !awin; j++) {
            if (num[i][j]==1&&num[i+1][j+1]==1&&num[i+2][j+2]==1&&num[i+3][j+3]==1) {
                if (num[i-1][j-1]==0||num[i+4][j+4]==0) {
                    awin = 1;
                    x = i;
                    y = j;
                }
            }
        }
    }

    for (int i = 4; i < 20 && !awin; i++) {
        for (int j = 1; j < 17 && !awin; j++) {
            if (num[i][j]==1&&num[i-1][j+1]==1&&num[i-2][j+2]==1&&num[i-3][j+3]==1) {
                if (num[i+1][j-1]==0||num[i-4][j+4]==0) {
                    awin = 1;
                    x = i-3;
                    y = j+3;
                }
            }
        }
    }

    for (int i = 1; i < 20 && !bwin; i++) {
        for (int j = 1; j < 17 && !bwin; j++) {
            if (num[i][j]==2&&num[i][j+1]==2&&num[i][j+2]==2&&num[i][j+3]==2) {
                if (num[i][j-1]==0||num[i][j+4]==0) {
                    bwin = 1;
                    x = i;
                    y = j;
                }
            }
        }
    }

    for (int i = 1; i < 17 && !bwin; i++) {
        for (int j = 1; j < 20 && !bwin; j++) {
            if (num[i][j]==2&&num[i+1][j]==2&&num[i+2][j]==2&&num[i+3][j]==2) {
                if (num[i-1][j]==0||num[i+4][j]==0) {
                    bwin = 1;
                    x = i;
                    y = j;
                }
            }
        }
    }

    for (int i = 1; i < 17 && !bwin; i++) {
        for (int j = 1; j < 17 && !bwin; j++) {
            if (num[i][j]==2&&num[i+1][j+1]==2&&num[i+2][j+2]==2&&num[i+3][j+3]==2) {
                if (num[i-1][j-1]==0||num[i+4][j+4]==0) {
                    bwin = 1;
                    x = i;
                    y = j;
                }
            }
        }
    }

    for (int i = 4; i < 20 && !bwin; i++) {
        for (int j = 1; j < 17 && !bwin; j++) {
            if (num[i][j]==2&&num[i-1][j+1]==2&&num[i-2][j+2]==2&&num[i-3][j+3]==2) {
                if (num[i+1][j-1]==0||num[i-4][j+4]==0) {
                    bwin = 1;
                    x = i-3;
                    y = j+3;
                }
            }
        }
    }

    if (awin) {
        printf("1:%d,%d\n", x, y);
    } else if (bwin) {
        printf("2:%d,%d\n", x, y);
    } else {
        printf("No\n");
    }

    return 0;
}