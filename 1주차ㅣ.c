#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
    int goods;//��ǰ����
    int buy[100]; //�԰����
    int sell[100];//�Ǹż���
    int id[100];
    int pd;
    int other[100];
    printf("��ǰ���� �Է�\n");
    scanf("%d", &goods);
    printf("��ǰ�� �԰� ���� �Է�\n");
    for (int i = 0; i < goods; i++) {
        scanf("%d", &buy[i]);
    }
    printf("��ǰ�� �Ǹż��� �Է�\n");
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
    printf("id�Է�\n");
    scanf("%d", &pd);
    pd -= 1;
    printf("�ش�id�� �������");
    printf("%d\n", other[pd]);
    for (int i = 0; i < goods; i++) {
        printf("���� ��� %d ", other[i]);
    }
    return 0;
}