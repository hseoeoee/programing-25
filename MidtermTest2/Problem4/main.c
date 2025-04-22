#include <stdio.h>
// #include <conio.h>  // getch() 사용을 위한 헤더는 제거
#include <unistd.h>   // UNIX 환경에서 sleep() 함수 사용을 위해 추가

int main() {
    char* RESET = "\x1b[0m";
    int happyShown = 0;
    int birthdayShown = 0;

    while (1) {
        // 화면 초기화용 (선택 사항)
        printf("\x1b[2J\x1b[H");

        // 촛불 (0: 노랑, 배경 검정)
        printf("\x1b[40;33m    0   0\n");

        // 초 (|: 파랑/초록, 배경 검정)
        printf("\x1b[40;34m    |   |\n");
        printf("\x1b[32m   *** ***\n");

        // 윗단 지그재그 (마젠타 배경, 흰색 글자)
        printf("\x1b[45;37m   /\\/\\/\\/\\/\\\n");

        // 윗단 본체 (흰 배경, 검정 글자)
        printf("\x1b[40;37m  ");
        printf("\x1b[47;30m|          |\n");

        // 윗단 아래 라인 (기타 라인: 흰색 글자)
        printf("\x1b[40;37m  ------------\n");

        // "Happy" 출력 (윗단 중앙에)
        if (happyShown) {
            printf("\x1b[47;35m  Happy   ");  // 핑크 글씨
        }
        else {
            printf("\x1b[47;30m~~~~~~~~~~");
        }

        // 아랫단 지그재그 (마젠타 배경, 흰색 글자)
        printf("\x1b[45;37m|\\/\\/\\/\\/\\/\\/|\n");
        printf("|/\\/\\/\\/\\/\\/\\|\n");

        // 아랫단 본체 (흰 배경, 검정 글자)
        printf("\x1b[40;37m|");
        if (birthdayShown) {
            printf("\x1b[47;36m Birthday ");  // 하늘색 글씨
        }
        else {
            printf("\x1b[47;30m____________");
        }
        printf("\x1b[40;37m|\n");

        // 아랫단 바닥 (흰 배경, 검정 글자)
        printf("\x1b[40;37m|_____________|\n");

        // 색상 리셋
        printf("%s", RESET);

        // 안내 문구
        printf("\nPress 'H' to reveal message, or any other key to exit...\n");

        // getchar()를 사용하여 키 입력 받기
        char ch = _getchar();  // 'getch()' 대신 'getchar()' 사용
        if (ch == 'H' || ch == 'h') {
            if (!happyShown) {
                happyShown = 1;  // "Happy" 출력
            }
            else if (!birthdayShown) {
                birthdayShown = 1;  // "Birthday" 출력
            }
            else {
                break;  // 두 메시지가 모두 출력되었으면 종료
            }
        }
        else {
            break;  // 다른 키 누르면 종료
        }
    }

    return 0;
}
