#include <stdio.h>
#include <conio.h>
#include <windows.h>

// gotoxy �Լ�
void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int main() {
    char ch;
    char c;

    gotoxy(2, 2);
    printf("input> ");

    while (1) {
        ch = _getch();

        if (ch >= '0' && ch <= '9') {
            c = ch;
            gotoxy(9, 2);        // ���� ��� ��ġ
            printf("%c", c);

            // ���� �޽��� ����
            gotoxy(2, 3);
            printf("                         ");
            break;  // ���� �Է� ���� �� ���� ����
        }
        else {
            gotoxy(2, 3);  // ���� �޽��� ���
            printf("Error: not a number");
        }
    }

    return 0;
}
