#include<stdio.h>
#include<stdlib.h>

typedef struct point {
	int x;
	int y;
}POINT;
int inputMenu(void) {
	int input;
	printf("1.�����,2.����ϱ�,3.Ŭ����,4.��������,5.���Ϸε�,-1");
	printf("%d", &input);
	return input;
}
POINT* makePoint(void) {
	POINT* p = (POINT*)malloc(sizeof(POINT));
	p->x = rand() % 100;
	p->y = rand() % 100;
	return p;
}
void printPoint(POINT* p[], int size) {
	for (int i = 0; i < size; i++)
		printf("x:%d,y%d\n", p[i]->x, p[i]->y);
}
void freePoints(POINT* p[], int size) {
	for (int i = 0; i < size; i++) free(p[i]);
}
int saveFile(POINT* p[], int count) {
	FILE* fp;
	fp = fopen("points.bin", "ab");
	if (fp == NULL)return 0;
	for (int i = 0; i < count; i++)
		fwrite(p[i], sizeof(POINT), 1, fp);
	fclose(fp);
	return 1;
}


int loadFile(POINT* p[], int max) {
	FILE* fp;
	int fSize, fCount;
	fp = fopen("points.bin", "rb");
	if (fp == NULL)return 0;

	fseek(fp, 0, SEEK_END);
	fSize = ftell(fp);
	fCount = fSize / sizeof(POINT);
	rewind(fp);

	for (int i = 0; i < fCount; i++)
	{
		if (i == max)break;
		p[i] = (POINT*)malloc(sizeof(POINT));
		fread(p[i], sizeof(POINT), 1, fp);
	}
	fclose(fp);
	return fCount;

}
int main()

{
	int count = 0;
	int menu;
	POINT* points[100];
	do {
		menu = inputMenu();
		switch (menu){
		case 1:
			points[count] = makePoint();
			count++;
			break;
		case 2:printPoint(points, count);
			break;
		case 3:
			system("clear");
			break;
		case 4:
			if (!saveFile(points, count))printf("file open error...\n");
			else print("file writing success..\n");
			break;
		case 5:
			count = loadFile(points, count);
			break;
		case -1:
			freePoints(points, count);
			printf("���α׷��������մϴ�\n");


		}

	} while (menu > 0);

	return 0;
}
/*
{	
	int count = 0;
	int menu;
	POINT* points[100];
	do {
		menu = inputMenu();
		if (menu == 1) {
			points[count] = makePoint();
			count++;
			printf("�߸������\n");
		}
		else if (menu == 2) {
			printPoint(points, count);
		}
		else if (menu - 1) {
			freePoint(points, count);
			printf("���α׷��������մϴ�\n");
		
		};
	} while (menu > 0);
	return 0;
}*/
/*
	POINT* points;
	int counts;
	scanf("%d", &counts);

	points = (POINT*)malloc(sizeof(POINT) * count);
	for (int i = 0; i < count; i++)
	{
		points[i].x = rand() % 100;
		points[i].y = rand() % 100;
	}
	for (int i = 0; i < count; i++) {
		printf("x-%d,y%d\n", points[i].x, points[i].y);
	}
	free(points);
	return 0;
}*/