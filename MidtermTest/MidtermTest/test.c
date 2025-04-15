#include <stdio.h>
#include <windows.h>
#include <conio.h>

void _gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void print_colored_text() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    // ��� ����Ÿ(BLUE + RED), ���� �ʷ�
    SetConsoleTextAttribute(hConsole, BACKGROUND_RED | BACKGROUND_BLUE | FOREGROUND_GREEN);

    _gotoxy(20, 10); // â������ 2ĭ ��
    printf("���� �� ������ �����ֳ�?");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ���󺹱�
}

void print_ascii_art() {
    _gotoxy(20, 12); printf("       '");
    _gotoxy(20, 13); printf("      '''");
    _gotoxy(20, 14); printf("     '''''");
    _gotoxy(20, 15); printf("    '''''''");
    _gotoxy(20, 16); printf("   '''''''''");
    _gotoxy(20, 17); printf("  '''''''''''");
    _gotoxy(20, 18); printf(" '''''''''''''");
    _gotoxy(20, 19); printf("''''''''''''''''");
    _gotoxy(20, 20); printf("'      __      '");
    _gotoxy(20, 21); printf("'  [] |__| []  '");
    _gotoxy(20, 22); printf("'             '");
    _gotoxy(20, 23); printf("'             '");
}

void exit_program() {
    _gotoxy(20, 25);  // �׸� �Ʒ� ��ġ
    printf("���α׷��� �����մϴ�.");
}

void show_popup() {
    int x = 30, y = 10;
    _gotoxy(x, y);     printf("+------------------+");
    _gotoxy(x, y + 1); printf("|   ����� ����!   |");
    _gotoxy(x, y + 2); printf("+------------------+");
}

void show_error() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);

    _gotoxy(25, 26);  // �ܵ� �Ʒ� �ƹ� ��ġ
    printf("�ٽ� �Է����ּ���!!!");

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ���󺹱�
}

int main() {
    print_ascii_art();
    print_colored_text();

    while (1) {
        char key = getch();

        if (key == 'n') {
            exit_program();
            break;
        }
        else if (key == 'y') {
            show_popup();
        }
        else {
            show_error();
        }
    }

    return 0;
}
