#include <stdio.h>
#include <windows.h>

// �ܼ� Ŀ�� �̵� �Լ� (Windows API ���)
void gotoxy(int x, int y) {
    // Windows �ܼ� ��ǥ�� (X, Y)�̸� 0-based
    COORD pos;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = (SHORT)x;
    pos.Y = (SHORT)y;
    SetConsoleCursorPosition(hOut, pos);
}

// ����(�Ǵ� ��ź) ��� �Լ�
// isExploded == 0 : ��ź ��� ���
// isExploded != 0 : ���� ���� ���
void printBomb(int bx, int by, int isExploded) {
    if (isExploded) {
        // ���� �ؽ�Ʈ�� ��ź ��ġ �������� ��, �߰�, �Ʒ��� ǥ��
        gotoxy(bx, by - 1);
        printf("  !!!!  ");
        gotoxy(bx, by);
        printf(" !BAAM! ");
        gotoxy(bx, by + 1);
        printf("  !!!!  ");
    }
    else {
        // ���� ��ź ��� (���� 7�� ����)
        gotoxy(bx, by);
        printf("( b )");
        // �����ٸ� ��ź ������ ���� ä���� ������ ����
        printf("   ");
    }
    fflush(stdout);
}

int main(void) {
    // --- ������ ---
    int sx = 14, sy = 9;     // ����(�Ҳ�) ���� ��ġ
    int bx = 2, by = 2;      // ��ź ��ġ
    // ����: �Ʒ�, ������, ��, ���� (y ���� = �Ʒ�)
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    // �� �ܰ躰 �̵� ĭ �� (���� �ڵ� �� ����)
    int mv[12] = { 1,2,4,4,6,6,8,8,10,10,12,13 };

    int x, y;
    int i, j, d;

    // �ܼ� �ʱ�ȭ (Ŀ�� ���� �ɼ� �� �ʿ��ϸ� �߰� ����)
    // (���⼱ �ܼ��� ȭ�鿡 �׸��� �͸� ó��)

    // --- ����(���) ��ü �׸���: '#'�� ǥ�� ---
    x = sx; y = sy;  // ���� ��ǥ
    gotoxy(x, y);
    // �������� ǥ������ �������� �ּ�ó�� ����
    // printf("#");

    for (i = 0; i < 12; i++) {
        d = i % 4;
        for (j = 0; j < mv[i]; j++) {
            x += dx[d];
            y += dy[d];
            gotoxy(x, y);
            printf("#");
        }
    }

    // --- ��ź ��� (�ʱ� ����) ---
    printBomb(bx, by, 0);

    
    x = sx;
    y = sy;
    gotoxy(x, y);
    printf("*");
    fflush(stdout);

    for (i = 0; i < 12; i++) {
        d = i % 4;
        for (j = 0; j < mv[i]; j++) {
            Sleep(110);                  
            gotoxy(x, y);
            printf(" ");
            // ���� ��ġ�� �̵�
            x += dx[d];
            y += dy[d];

            if (y == by && x >= bx && x <= bx + 6) {
                // ���� ���
                printBomb(bx, by, 1);
                // Ŀ���� �����ϰ� ����
                gotoxy(0, 25);
                return 0;
            }

            // ���ο� �Ҳ� �׸���
            gotoxy(x, y);
            printf("*");
            fflush(stdout);
        }
    }

    // ������ ���������� ������ �� �Ͼ�ٸ� Ŀ�� ��ġ ���� �� ����
    gotoxy(0, 25);
    return 0;
}
