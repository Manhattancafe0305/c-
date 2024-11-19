#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODUCT_COUNT 5
#define MAX_NAME_LENGTH 50
#define FILE_NAME "product_data.txt"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int price;
    int stock;
    int sold;
    int total_sales;
} Product;

void initializeProducts(Product products[]) {
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        products[i].id = i + 1;
        snprintf(products[i].name, MAX_NAME_LENGTH, "상품%d", i + 1);
        products[i].price = 1000 * (i + 1);
        products[i].stock = 0;
        products[i].sold = 0;
        products[i].total_sales = 0;
    }
}

void displayMenu() {
    printf("\n--- 재고 관리 시스템 ---\n");
    printf("1. 입고\n");
    printf("2. 판매\n");
    printf("3. 개별상품정보\n");
    printf("4. 전체상품정보\n");
    printf("5. 상품정보저장\n");
    printf("6. 상품정보가져오기\n");
    printf("7. 종료\n");
    printf("메뉴를 선택하세요: ");
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
    if (quantity > products[productNumber - 1].stock) {
        printf("재고 부족! 현재 재고: %d\n", products[productNumber - 1].stock);
        return;
    }
    products[productNumber - 1].stock -= quantity;
    products[productNumber - 1].sold += quantity;
    products[productNumber - 1].total_sales += quantity * products[productNumber - 1].price;
    printf("판매 완료!\n");
}

void displayProduct(Product products[]) {
    int productNumber;
    printf("\n정보를 조회할 상품 번호 (1~%d): ", PRODUCT_COUNT);
    if (scanf("%d", &productNumber) != 1 || productNumber < 1 || productNumber > PRODUCT_COUNT) {
        printf("잘못된 상품 번호입니다. 다시 시도하세요.\n");
        while (getchar() != '\n');
        return;
    }
    Product p = products[productNumber - 1];
    printf("\n--- 상품 정보 ---\n");
    printf("ID: %d\n", p.id);
    printf("이름: %s\n", p.name);
    printf("가격: %d\n", p.price);
    printf("입고량: %d\n", p.stock);
    printf("판매량: %d\n", p.sold);
    printf("총 판매 금액: %d\n", p.total_sales);
}

void displayAllProducts(Product products[]) {
    printf("\n--- 전체 상품 정보 ---\n");
    printf("ID\t이름\t\t가격\t입고량\t판매량\t총 판매 금액\n");
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("%d\t%-10s\t%d\t%d\t%d\t%d\n",
            products[i].id,
            products[i].name,
            products[i].price,
            products[i].stock,
            products[i].sold,
            products[i].total_sales);
    }
}

void saveProducts(Product products[]) {
    FILE* file = fopen(FILE_NAME, "w");
    if (!file) {
        printf("파일 저장 실패!\n");
        return;
    }
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        fprintf(file, "%d,%s,%d,%d,%d,%d\n",
            products[i].id,
            products[i].name,
            products[i].price,
            products[i].stock,
            products[i].sold,
            products[i].total_sales);
    }
    fclose(file);
    printf("상품 정보가 저장되었습니다.\n");
}

void loadProducts(Product products[]) {
    FILE* file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("파일 불러오기 실패! 파일이 존재하지 않습니다.\n");
        return;
    }
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        fscanf(file, "%d,%[^,],%d,%d,%d,%d\n",
            &products[i].id,
            products[i].name,
            &products[i].price,
            &products[i].stock,
            &products[i].sold,
            &products[i].total_sales);
    }
    fclose(file);
    printf("상품 정보가 불러와졌습니다.\n");
}

int main() {
    Product products[PRODUCT_COUNT];
    initializeProducts(products);

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
            displayProduct(products);
            break;
        case 4:
            displayAllProducts(products);
            break;
        case 5:
            saveProducts(products);
            break;
        case 6:
            loadProducts(products);
            break;
        case 7:
            printf("프로그램을 종료합니다.\n");
            return 0;
        default:
            printf("잘못된 메뉴 선택입니다. 다시 시도하세요.\n");
        }
    }
    return 0;
}
