#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	int number[10];
	int total = 0;
	int max, min;
	float avg = 0.0;
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		number[i] = (rand() % 100) + 1;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%3d\t", number[i]);
		if ((i + 1) % 5 == 0)printf("\n");
	}
	for (int i = 0; i < 10; i++)
	{
		total += number[i];
	}
	avg = (float)total / 10;
	max = number[0];
	min = number[0];
	for (int i = 1; i < 10; i++)
	{
		if (max < number[i])max = number[i];
		if (max > number[i])max = number[i];
	}
	print("%f,%d,%d\n", avg, max, min);
	return 0;
}