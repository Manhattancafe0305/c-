#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
    int goods;//상품종류
    int buy[100]; //입고수량
    int sell[100];//판매수량
    int id[100];
    int pd;
    int other[100];
    printf("상품개수 입력\n");
    scanf("%d", &goods);
    printf("상품별 입고 수량 입력\n");
    for (int i = 0; i < goods; i++) {
        scanf("%d", &buy[i]);
    }
    printf("상품별 판매수량 입력\n");
    for (int i = 0; i < goods; i++)
    {
        scanf("%d", &sell[i]);
    }
    for (int i = 0; i < goods; i++)
    {
        other[i] = buy[i] - sell[i];
    }
    for (int i = 0; i < goods; i++)
    {
        int x = 1;
        id[i] += x;
        x += 1;
    }
    printf("id입력\n");
    scanf("%d", &pd);
    pd -= 1;
    printf("해당id의 남은재고");
    printf("%d\n", other[pd]);
    for (int i = 0; i < goods; i++) {
        printf("남은 재고 %d ", other[i]);
    }
    return 0;
}