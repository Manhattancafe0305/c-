#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
    int goods;//��ǰ����
    int buy[100]; //�԰����
    int sell[100];//�Ǹż���
    int id = 0;
    int pd;
    int other[100];
    int buy1 = 0;
    int sell1 = 0;
    int chlekvksao = 0;
    printf("��ǰ���� �Է�\n");
    scanf("%d", &goods);
    printf("��ǰ�� �԰� ���� �Է�\n");
    for (int i = 0; i < goods; i++) {//�԰����
        scanf("%d", &buy[i]);
        buy1 += buy[i];
    }
    printf("��ǰ�� �Ǹż��� �Է�\n");//�ĳ�������
    for (int i = 0; i < goods; i++)
    {
        scanf("%d", &sell[i]);
        sell1 += sell[i];
    }
    for (int i = 0; i < goods; i++)//�������
    {
        other[i] = buy[i] - sell[i];
    }

    for (int i = 0; i < goods; i++) {
        printf("���� ��� %d ", other[i]);
    }
    float per = (sell1 / buy1) * 100;//�Ǹŷ�
    printf("���Ǹŷ�%d(%0.2f)\n)", sell1, per);
    for (int i = 0; i < goods; i++) {//�ִ��Ǹŷ����ϱ�
        if (chlekvksao < sell[i]) {
            chlekvksao = sell[i];
            id = i;
        }
    }
    printf("���� �����ȸ� ��ǰ��id[%d] �Ǹŷ���%d\n", id + 1, chlekvksao);
    for (int i = 0; i < goods; i++) {//�ּ��Ǹŷ����ϱ�
        if (chlekvksao > sell[i]) {
            chlekvksao = sell[i];
            id = i;
        }
    }
    printf("���� �����ȸ� ��ǰ��id[%d] �Ǹŷ���%d\n", id + 1, chlekvksao);
    for (int i = 0; i < goods; i++) {//������
        if (other[i] < 2 || other[i] == 2) {
            id = i;
            printf("��ǰ ��ȣ%d:������ %d\n", id + 1, other[i]);
        }
    }

    return 0;
}   