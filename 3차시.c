#include <stdio.h>

#define PRODUCT_COUNT 5

typedef struct {
    char name[20];
    int stock;
    int sold;
    int inventory;
} Product;

void displayMenu() {
    printf("\n--- ��� ���� �ý��� ---\n");
    printf("1. �԰�\n");
    printf("2. �Ǹ�\n");
    printf("3. ��ǰ��Ȳ\n");
    printf("4. ���α׷� ����\n");
    printf("�޴��� �����ϼ���: ");
}

void restock(Product products[]) {
    int productNumber, quantity;
    printf("\n�԰��� ��ǰ ��ȣ (1~%d): ", PRODUCT_COUNT);
    scanf("%d", &productNumber);
    if (productNumber < 1 || productNumber > PRODUCT_COUNT) {
        printf("�߸��� ��ǰ ��ȣ�Դϴ�.\n");
        return;
    }
    printf("�԰� ����: ");
    scanf("%d", &quantity);
    products[productNumber - 1].stock += quantity;
    products[productNumber - 1].inventory += quantity;
    printf("�԰� �Ϸ�!\n");
}

void sell(Product products[]) {
    int productNumber, quantity;
    printf("\n�Ǹ��� ��ǰ ��ȣ (1~%d): ", PRODUCT_COUNT);
    scanf("%d", &productNumber);
    if (productNumber < 1 || productNumber > PRODUCT_COUNT) {
        printf("�߸��� ��ǰ ��ȣ�Դϴ�.\n");
        return;
    }
    printf("�Ǹ� ����: ");
    scanf("%d", &quantity);
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
    printf("��ȣ\t��ǰ��\t�԰����\t�Ǹż���\t������\n");
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
        {"��ǰ1", 0, 0, 0},
        {"��ǰ2", 0, 0, 0},
        {"��ǰ3", 0, 0, 0},
        {"��ǰ4", 0, 0, 0},
        {"��ǰ5", 0, 0, 0},
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
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
    return 0;
}
