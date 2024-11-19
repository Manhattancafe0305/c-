#include <stdio.h>
#include <string.h>

#define PRODUCT_COUNT 5
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int stock;     
    int sold;     
    int inventory;
} Product;

void displayMenu() {
    printf("\n--- 재고 관리 시스템 ---\n");
    printf("1. 입고\n");
    printf("2. 판매\n");
    printf("3. 상품명 입력\n");
    printf("4. 상품현황\n");
    printf("5. 프로그램 종료\n");
    printf("메뉴를 선택하세요: ");
}

void inputProductNames(Product products[]) {
    printf("\n--- 상품명 입력 ---\n");
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("상품 %d의 이름을 입력하세요: ", i + 1);
        scanf(" %[^\n]s", products[i].name); 
    }
    printf("상품명 입력이 완료되었습니다.\n");
}

void restock(Product products[]) {
    int productNumber, quantity;
    printf("\n입고할 상품 번호 (1~%d): ", PRODUCT_COUNT);
    if (scanf("%d", &productNumber) != 1 || productNumber < 1 || productNumber > PRODUCT_COUNT) {
        printf("잘못된 상품 번호입니다. 다시 시도하세요.\n");
        while (getchar() != '\n');
        return;
    }
    printf("입고 수량: ");
    if (scanf("%d", &quantity) != 1 || quantity < 0) {
        printf("잘못된 수량입니다. 다시 시도하세요.\n");
        while (getchar() != '\n');
        return;
    }
    products[productNumber - 1].stock += quantity;
    products[productNumber - 1].inventory += quantity;
    printf("입고 완료!\n");
}

void sell(Product products[]) {
    int productNumber, quantity;
    printf("\n판매할 상품 번호 (1~%d): ", PRODUCT_COUNT);
    if (scanf("%d", &productNumber) != 1 || productNumber < 1 || productNumber > PRODUCT_COUNT) {
        printf("잘못된 상품 번호입니다. 다시 시도하세요.\n");
        while (getchar() != '\n');
        return;
    }
    printf("판매 수량: ");
    if (scanf("%d", &quantity) != 1 || quantity < 0) {
        printf("잘못된 수량입니다. 다시 시도하세요.\n");
        while (getchar() != '\n');
        return;
    }
    if (quantity > products[productNumber - 1].inventory) {
        printf("재고 부족! 현재 재고: %d\n", products[productNumber - 1].inventory);
        return;
    }
    products[productNumber - 1].sold += quantity;
    products[productNumber - 1].inventory -= quantity;
    printf("판매 완료!\n");
}

void displayStatus(Product products[]) {
    printf("\n--- 상품 현황 ---\n");
    printf("번호\t상품명\t\t입고수량\t판매수량\t재고수량\n");
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("%d\t%-15s\t%d\t\t%d\t\t%d\n",
            i + 1,
            strlen(products[i].name) > 0 ? products[i].name : "미입력",
            products[i].stock,
            products[i].sold,
            products[i].inventory);
    }
}

int main() {
    Product products[PRODUCT_COUNT] = { 0 }; 
    int choice;

    while (1) {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
            while (getchar() != '\n'); 
            continue;
        }

        switch (choice) {
        case 1:
            restock(products);
            break;
        case 2:
            sell(products);
            break;
        case 3:
            inputProductNames(products);
            break;
        case 4:
            displayStatus(products);
            break;
        case 5:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 메뉴 선택입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}
