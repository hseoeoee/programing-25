#include <stdio.h>

int PassOrFail(int score) {
    if (score >= 50) {
        return 1;
    }
    else {
        return 0;
    }
}

int main() {
    int score = 65; // 여기에 본인의 예상 점수를 넣으세요
    int result = PassOrFail(score);

    if (result == 1) {
        printf("재시험 없습니다!\n");
    }
    else {
        printf("재시험 있습니다\n");
    }

    return 0;
}