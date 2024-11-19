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
        snprintf(products[i].name, MAX_NAME_LENGTH, "��ǰ%d", i + 1);
        products[i].price = 1000 * (i + 1);
        products[i].stock = 0;
        products[i].sold = 0;
        products[i].total_sales = 0;
    }
}

void displayMenu() {
    printf("\n--- ��� ���� �ý��� ---\n");
    printf("1. �԰�\n");
    printf("2. �Ǹ�\n");
    printf("3. ������ǰ����\n");
    printf("4. ��ü��ǰ����\n");
    printf("5. ��ǰ��������\n");
    printf("6. ��ǰ������������\n");
    printf("7. ����\n");
    printf("�޴��� �����ϼ���: ");
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
    if (quantity > products[productNumber - 1].stock) {
        printf("��� ����! ���� ���: %d\n", products[productNumber - 1].stock);
        return;
    }
    products[productNumber - 1].stock -= quantity;
    products[productNumber - 1].sold += quantity;
    products[productNumber - 1].total_sales += quantity * products[productNumber - 1].price;
    printf("�Ǹ� �Ϸ�!\n");
}

void displayProduct(Product products[]) {
    int productNumber;
    printf("\n������ ��ȸ�� ��ǰ ��ȣ (1~%d): ", PRODUCT_COUNT);
    if (scanf("%d", &productNumber) != 1 || productNumber < 1 || productNumber > PRODUCT_COUNT) {
        printf("�߸��� ��ǰ ��ȣ�Դϴ�. �ٽ� �õ��ϼ���.\n");
        while (getchar() != '\n');
        return;
    }
    Product p = products[productNumber - 1];
    printf("\n--- ��ǰ ���� ---\n");
    printf("ID: %d\n", p.id);
    printf("�̸�: %s\n", p.name);
    printf("����: %d\n", p.price);
    printf("�԰�: %d\n", p.stock);
    printf("�Ǹŷ�: %d\n", p.sold);
    printf("�� �Ǹ� �ݾ�: %d\n", p.total_sales);
}

void displayAllProducts(Product products[]) {
    printf("\n--- ��ü ��ǰ ���� ---\n");
    printf("ID\t�̸�\t\t����\t�԰�\t�Ǹŷ�\t�� �Ǹ� �ݾ�\n");
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
        printf("���� ���� ����!\n");
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
    printf("��ǰ ������ ����Ǿ����ϴ�.\n");
}

void loadProducts(Product products[]) {
    FILE* file = fopen(FILE_NAME, "r");
    if (!file) {
        printf("���� �ҷ����� ����! ������ �������� �ʽ��ϴ�.\n");
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
    printf("��ǰ ������ �ҷ��������ϴ�.\n");
}

int main() {
    Product products[PRODUCT_COUNT];
    initializeProducts(products);

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
            printf("���α׷��� �����մϴ�.\n");
            return 0;
        default:
            printf("�߸��� �޴� �����Դϴ�. �ٽ� �õ��ϼ���.\n");
        }
    }
    return 0;
}
