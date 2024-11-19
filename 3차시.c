#include <stdio.h>

#define PRODUCT_COUNT 5

typedef struct {
    char name[20];
    int stock;
    int sold;
    int inventory;
} Product;

void displayMenu() {
    printf("\n--- 재고 관리 시스템 ---\n");
    printf("1. 입고\n");
    printf("2. 판매\n");
    printf("3. 상품현황\n");
    printf("4. 프로그램 종료\n");
    printf("메뉴를 선택하세요: ");
}

void restock(Product products[]) {
    int productNumber, quantity;
    printf("\n입고할 상품 번호 (1~%d): ", PRODUCT_COUNT);
    scanf("%d", &productNumber);
    if (productNumber < 1 || productNumber > PRODUCT_COUNT) {
        printf("잘못된 상품 번호입니다.\n");
        return;
    }
    printf("입고 수량: ");
    scanf("%d", &quantity);
    products[productNumber - 1].stock += quantity;
    products[productNumber - 1].inventory += quantity;
    printf("입고 완료!\n");
}

void sell(Product products[]) {
    int productNumber, quantity;
    printf("\n판매할 상품 번호 (1~%d): ", PRODUCT_COUNT);
    scanf("%d", &productNumber);
    if (productNumber < 1 || productNumber > PRODUCT_COUNT) {
        printf("잘못된 상품 번호입니다.\n");
        return;
    }
    printf("판매 수량: ");
    scanf("%d", &quantity);
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
    printf("번호\t상품명\t입고수량\t판매수량\t재고수량\n");
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("%d\t%s\t%d\t\t%d\t\t%d\n",
            i + 1,
            products[i].name,
            products[i].stock,
            products[i].sold,
            products[i].inventory);
    }
}

int main() {
    Product products[PRODUCT_COUNT] = {
        {"상품1", 0, 0, 0},
        {"상품2", 0, 0, 0},
        {"상품3", 0, 0, 0},
        {"상품4", 0, 0, 0},
        {"상품5", 0, 0, 0},
    };

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            restock(products);
            break;
        case 2:
            sell(products);
            break;
        case 3:
            displayStatus(products);
            break;
        case 4:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}
