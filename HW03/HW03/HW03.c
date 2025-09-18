#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

//매개변수 isExploded
//0: 폭발전 폭탄
//1: 폭발함
void printBomb(int isExploded)
{
    //폭탄은 항상 7칸
    if (isExploded)
    {
        printf("\x1b[A^^^^^^^");
        printf("\x1b[B\x1b[7D!!BAM!!");
        printf("\x1b[B\x1b[7D^^^^^^^");
    }
    else
        printf("(  b  )");
}

int main()
{
    int startX = 14, startY = 9;      // 불꽃 시작 좌표
    int x = startX, y = startY;

    int bombX = 2, bombY = 2;         // 폭탄 고정 좌표 (심지 시작점)
    const int BOMB_LEN = 7;           // "(  b  )" 폭 7칸

    /* 방향: ↓ → ↑ ← (반시계) */
    int dirX[4] = { 0, 1, 0, -1 };
    int dirY[4] = { 1, 0,-1,  0 };

    int tx, ty, nx, ny;
    int i, j, d;

    /* 1) 심지(#) 전체 그리기 */
    tx = x; ty = y;
    for (i = 0; i < 12; i++) {
        d = i % 4;

        // 이동 칸 수 규칙: 첫 구간=1, 마지막=13, 나머지=i+2
        int step = (i == 0 ? 1 : (i == 11 ? 13 : i + 2));

        for (j = 0; j < step; j++) {
            tx += dirX[d];
            ty += dirY[d];
            moveCursor(tx, ty);
            printf("#");
        }
    }

    /* 2) 폭탄 출력 */
    moveCursor(bombX, bombY);
    printBomb(0);

    /* 3) 불꽃 이동(200ms), 지나간 자리 ' ' 로 지움 */
    tx = x; ty = y;
    moveCursor(tx, ty); printf("*");

    for (i = 0; i < 12; i++) {
        d = i % 4;
        int step = (i == 0 ? 1 : (i == 11 ? 13 : i + 2));

        for (j = 0; j < step; j++) {
            Sleep(200);

            /* 현재 불꽃 지우기 */
            moveCursor(tx, ty); printf(" ");

            /* 다음 칸 계산 */
            nx = tx + dirX[d];
            ny = ty + dirY[d];

            /* 다음 칸이 폭탄 문자열 영역이면 즉시 폭발 */
            if (ny == bombY && nx >= bombX && nx <= bombX + BOMB_LEN - 1) {
                moveCursor(bombX, bombY);
                printBomb(1);
                moveCursor(10, 20);
                return 0;
            }

            /* 일반 이동 */
            tx = nx; ty = ny;
            moveCursor(tx, ty); printf("*");
        }
    }

    moveCursor(10, 20);
    return 0;
}