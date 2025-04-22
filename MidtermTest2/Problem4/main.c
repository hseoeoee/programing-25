#include <stdio.h>
// #include <conio.h>  // getch() ����� ���� ����� ����
#include <unistd.h>   // UNIX ȯ�濡�� sleep() �Լ� ����� ���� �߰�

int main() {
    char* RESET = "\x1b[0m";
    int happyShown = 0;
    int birthdayShown = 0;

    while (1) {
        // ȭ�� �ʱ�ȭ�� (���� ����)
        printf("\x1b[2J\x1b[H");

        // �к� (0: ���, ��� ����)
        printf("\x1b[40;33m    0   0\n");

        // �� (|: �Ķ�/�ʷ�, ��� ����)
        printf("\x1b[40;34m    |   |\n");
        printf("\x1b[32m   *** ***\n");

        // ���� ������� (����Ÿ ���, ��� ����)
        printf("\x1b[45;37m   /\\/\\/\\/\\/\\\n");

        // ���� ��ü (�� ���, ���� ����)
        printf("\x1b[40;37m  ");
        printf("\x1b[47;30m|          |\n");

        // ���� �Ʒ� ���� (��Ÿ ����: ��� ����)
        printf("\x1b[40;37m  ------------\n");

        // "Happy" ��� (���� �߾ӿ�)
        if (happyShown) {
            printf("\x1b[47;35m  Happy   ");  // ��ũ �۾�
        }
        else {
            printf("\x1b[47;30m~~~~~~~~~~");
        }

        // �Ʒ��� ������� (����Ÿ ���, ��� ����)
        printf("\x1b[45;37m|\\/\\/\\/\\/\\/\\/|\n");
        printf("|/\\/\\/\\/\\/\\/\\|\n");

        // �Ʒ��� ��ü (�� ���, ���� ����)
        printf("\x1b[40;37m|");
        if (birthdayShown) {
            printf("\x1b[47;36m Birthday ");  // �ϴû� �۾�
        }
        else {
            printf("\x1b[47;30m____________");
        }
        printf("\x1b[40;37m|\n");

        // �Ʒ��� �ٴ� (�� ���, ���� ����)
        printf("\x1b[40;37m|_____________|\n");

        // ���� ����
        printf("%s", RESET);

        // �ȳ� ����
        printf("\nPress 'H' to reveal message, or any other key to exit...\n");

        // getchar()�� ����Ͽ� Ű �Է� �ޱ�
        char ch = _getchar();  // 'getch()' ��� 'getchar()' ���
        if (ch == 'H' || ch == 'h') {
            if (!happyShown) {
                happyShown = 1;  // "Happy" ���
            }
            else if (!birthdayShown) {
                birthdayShown = 1;  // "Birthday" ���
            }
            else {
                break;  // �� �޽����� ��� ��µǾ����� ����
            }
        }
        else {
            break;  // �ٸ� Ű ������ ����
        }
    }

    return 0;
}
