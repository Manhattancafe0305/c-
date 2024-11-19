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
    printf("\n--- ��� ���� �ý��� ---\n");
    printf("1. �԰�\n");
    printf("2. �Ǹ�\n");
    printf("3. ��ǰ�� �Է�\n");
    printf("4. ��ǰ��Ȳ\n");
    printf("5. ���α׷� ����\n");
    printf("�޴��� �����ϼ���: ");
}

void inputProductNames(Product products[]) {
    printf("\n--- ��ǰ�� �Է� ---\n");
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("��ǰ %d�� �̸��� �Է��ϼ���: ", i + 1);
        scanf(" %[^\n]s", products[i].name); 
    }
    printf("��ǰ�� �Է��� �Ϸ�Ǿ����ϴ�.\n");
}

void restock(Product products[]) {
    int productNumber, quantity;
    printf("\n�԰��� ��ǰ ��ȣ (1~%d): ", PRODUCT_COUNT);
    if (scanf("%d", &productNumber) != 1 || productNumber < 1 || productNumber > PRODUCT_COUNT) {
        printf("�߸��� ��ǰ ��ȣ�Դϴ�. �ٽ� �õ��ϼ���.\n");
        while (getchar() != '\n');
        return;
    }
    printf("�԰� ����: ");
    if (scanf("%d", &quantity) != 1 || quantity < 0) {
        printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        while (getchar() != '\n');
        return;
    }
    products[productNumber - 1].stock += quantity;
    products[productNumber - 1].inventory += quantity;
    printf("�԰� �Ϸ�!\n");
}

void sell(Product products[]) {
    int productNumber, quantity;
    printf("\n�Ǹ��� ��ǰ ��ȣ (1~%d): ", PRODUCT_COUNT);
    if (scanf("%d", &productNumber) != 1 || productNumber < 1 || productNumber > PRODUCT_COUNT) {
        printf("�߸��� ��ǰ ��ȣ�Դϴ�. �ٽ� �õ��ϼ���.\n");
        while (getchar() != '\n');
        return;
    }
    printf("�Ǹ� ����: ");
    if (scanf("%d", &quantity) != 1 || quantity < 0) {
        printf("�߸��� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        while (getchar() != '\n');
        return;
    }
    if (quantity > products[productNumber - 1].inventory) {
        printf("��� ����! ���� ���: %d\n", products[productNumber - 1].inventory);
        return;
    }
    products[productNumber - 1].sold += quantity;
    products[productNumber - 1].inventory -= quantity;
    printf("�Ǹ� �Ϸ�!\n");
}

void displayStatus(Product products[]) {
    printf("\n--- ��ǰ ��Ȳ ---\n");
    printf("��ȣ\t��ǰ��\t\t�԰����\t�Ǹż���\t������\n");
    for (int i = 0; i < PRODUCT_COUNT; i++) {
        printf("%d\t%-15s\t%d\t\t%d\t\t%d\n",
            i + 1,
            strlen(products[i].name) > 0 ? products[i].name : "���Է�",
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
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
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
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �޴� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }

    return 0;
}
