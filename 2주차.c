#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
    int goods;//상품종류
    int buy[100]; //입고수량
    int sell[100];//판매수량
    int id = 0;
    int pd;
    int other[100];
    int buy1 = 0;
    int sell1 = 0;
    int chlekvksao = 0;
    printf("상품개수 입력\n");
    scanf("%d", &goods);
    printf("상품별 입고 수량 입력\n");
    for (int i = 0; i < goods; i++) {//입고수량
        scanf("%d", &buy[i]);
        buy1 += buy[i];
    }
    printf("상품별 판매수량 입력\n");//파내ㅁ수량
    for (int i = 0; i < goods; i++)
    {
        scanf("%d", &sell[i]);
        sell1 += sell[i];
    }
    for (int i = 0; i < goods; i++)//남은재고
    {
        other[i] = buy[i] - sell[i];
    }

    for (int i = 0; i < goods; i++) {
        printf("남은 재고 %d ", other[i]);
    }
    float per = (sell1 / buy1) * 100;//판매량
    printf("총판매량%d(%0.2f)\n)", sell1, per);
    for (int i = 0; i < goods; i++) {//최다판매량구하기
        if (chlekvksao < sell[i]) {
            chlekvksao = sell[i];
            id = i;
        }
    }
    printf("가장 많이팔린 상품은id[%d] 판매량은%d\n", id + 1, chlekvksao);
    for (int i = 0; i < goods; i++) {//최소판매량구하기
        if (chlekvksao > sell[i]) {
            chlekvksao = sell[i];
            id = i;
        }
    }
    printf("가장 적게팔린 상품은id[%d] 판매량은%d\n", id + 1, chlekvksao);
    for (int i = 0; i < goods; i++) {//재고부족
        if (other[i] < 2 || other[i] == 2) {
            id = i;
            printf("상품 번호%d:재고부족 %d\n", id + 1, other[i]);
        }
    }

    return 0;
}   