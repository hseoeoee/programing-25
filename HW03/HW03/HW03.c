#include <stdio.h>
#include <math.h>
#include <Windows.h>

#define PI 3.14159226535897

void moveCursor(int x, int y)
{
    printf("\x1b[%d;%dH", y, x);
}

//�Ű����� isExploded
//0: ������ ��ź
//1: ������
void printBomb(int isExploded)
{
    //��ź�� �׻� 7ĭ
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
    int startX = 14, startY = 9;      // �Ҳ� ���� ��ǥ
    int x = startX, y = startY;

    int bombX = 2, bombY = 2;         // ��ź ���� ��ǥ (���� ������)
    const int BOMB_LEN = 7;           // "(  b  )" �� 7ĭ

    /* ����: �� �� �� �� (�ݽð�) */
    int dirX[4] = { 0, 1, 0, -1 };
    int dirY[4] = { 1, 0,-1,  0 };

    int tx, ty, nx, ny;
    int i, j, d;

    /* 1) ����(#) ��ü �׸��� */
    tx = x; ty = y;
    for (i = 0; i < 12; i++) {
        d = i % 4;

        // �̵� ĭ �� ��Ģ: ù ����=1, ������=13, ������=i+2
        int step = (i == 0 ? 1 : (i == 11 ? 13 : i + 2));

        for (j = 0; j < step; j++) {
            tx += dirX[d];
            ty += dirY[d];
            moveCursor(tx, ty);
            printf("#");
        }
    }

    /* 2) ��ź ��� */
    moveCursor(bombX, bombY);
    printBomb(0);

    /* 3) �Ҳ� �̵�(200ms), ������ �ڸ� ' ' �� ���� */
    tx = x; ty = y;
    moveCursor(tx, ty); printf("*");

    for (i = 0; i < 12; i++) {
        d = i % 4;
        int step = (i == 0 ? 1 : (i == 11 ? 13 : i + 2));

        for (j = 0; j < step; j++) {
            Sleep(200);

            /* ���� �Ҳ� ����� */
            moveCursor(tx, ty); printf(" ");

            /* ���� ĭ ��� */
            nx = tx + dirX[d];
            ny = ty + dirY[d];

            /* ���� ĭ�� ��ź ���ڿ� �����̸� ��� ���� */
            if (ny == bombY && nx >= bombX && nx <= bombX + BOMB_LEN - 1) {
                moveCursor(bombX, bombY);
                printBomb(1);
                moveCursor(10, 20);
                return 0;
            }

            /* �Ϲ� �̵� */
            tx = nx; ty = ny;
            moveCursor(tx, ty); printf("*");
        }
    }

    moveCursor(10, 20);
    return 0;
}