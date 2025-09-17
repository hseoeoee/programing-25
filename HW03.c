#include <stdio.h>
#include <windows.h>

// 콘솔 커서 이동 함수 (Windows API 사용)
void gotoxy(int x, int y) {
    // Windows 콘솔 좌표는 (X, Y)이며 0-based
    COORD pos;
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    pos.X = (SHORT)x;
    pos.Y = (SHORT)y;
    SetConsoleCursorPosition(hOut, pos);
}

// 폭발(또는 폭탄) 출력 함수
// isExploded == 0 : 폭탄 모양 출력
// isExploded != 0 : 폭발 연출 출력
void printBomb(int bx, int by, int isExploded) {
    if (isExploded) {
        // 폭발 텍스트를 폭탄 위치 기준으로 위, 중간, 아래에 표시
        gotoxy(bx, by - 1);
        printf("  !!!!  ");
        gotoxy(bx, by);
        printf(" !BAAM! ");
        gotoxy(bx, by + 1);
        printf("  !!!!  ");
    }
    else {
        // 평상시 폭탄 모양 (길이 7로 가정)
        gotoxy(bx, by);
        printf("( b )");
        // 괜찮다면 폭탄 오른쪽 공백 채워서 지워짐 방지
        printf("   ");
    }
    fflush(stdout);
}

int main(void) {
    // --- 설정값 ---
    int sx = 14, sy = 9;     // 심지(불꽃) 시작 위치
    int bx = 2, by = 2;      // 폭탄 위치
    // 방향: 아래, 오른쪽, 위, 왼쪽 (y 증가 = 아래)
    int dx[4] = { 0, 1, 0, -1 };
    int dy[4] = { 1, 0, -1, 0 };
    // 각 단계별 이동 칸 수 (원래 코드 값 유지)
    int mv[12] = { 1,2,4,4,6,6,8,8,10,10,12,13 };

    int x, y;
    int i, j, d;

    // 콘솔 초기화 (커서 숨김 옵션 등 필요하면 추가 가능)
    // (여기선 단순히 화면에 그리는 것만 처리)

    // --- 심지(경로) 전체 그리기: '#'로 표시 ---
    x = sx; y = sy;  // 시작 좌표
    gotoxy(x, y);
    // 시작점을 표시하지 않으려면 주석처리 가능
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

    // --- 폭탄 출력 (초기 상태) ---
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
            // 다음 위치로 이동
            x += dx[d];
            y += dy[d];

            if (y == by && x >= bx && x <= bx + 6) {
                // 폭발 출력
                printBomb(bx, by, 1);
                // 커서를 정리하고 종료
                gotoxy(0, 25);
                return 0;
            }

            // 새로운 불꽃 그리기
            gotoxy(x, y);
            printf("*");
            fflush(stdout);
        }
    }

    // 끝까지 도달했으나 폭발이 안 일어났다면 커서 위치 정리 후 종료
    gotoxy(0, 25);
    return 0;
}
