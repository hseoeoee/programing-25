#include <stdio.h>
#include <conio.h>
#include <windows.h>

// gotoxy 함수
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
            gotoxy(9, 2);        // 숫자 출력 위치
            printf("%c", c);

            // 오류 메시지 제거
            gotoxy(2, 3);
            printf("                         ");
            break;  // 숫자 입력 성공 → 루프 종료
        }
        else {
            gotoxy(2, 3);  // 오류 메시지 출력
            printf("Error: not a number");
        }
    }

    return 0;
}
