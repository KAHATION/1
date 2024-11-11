#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>


void SelectionSort(int mas1[], int size) {

	clock_t start_time, end_time;
	double total_time;

	start_time = clock();

	for (int i = 0; i < size - 1; i++) {
		int ind = i;
		for (int j = i + 1; j < size; j++) {
			if (mas1[j] < mas1[ind]) {
				ind = j;
			}
		}
		int el = mas1[i];
		mas1[i] = mas1[ind];
		mas1[ind] = el;
	}

	end_time = clock();
	total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

	printf("\nSelection Sort: ");
	for (int i = 0; i < size; i++) {
		printf("%d,", mas1[i]);
	}
	printf("\nSelection Sort time: %f seconds", total_time);
}


void InsertionSort(int mas2[], int size) {

	clock_t start_time, end_time;
	double total_time;

	start_time = clock();

	for (int i = 1; i < size; i++) {
		int key = mas2[i];
		int j = i - 1;
		while (j >= 0 && mas2[j] > key) {
			mas2[j + 1] = mas2[j];
			j = j - 1;
		}
		mas2[j + 1] = key;
	}

	end_time = clock();
	total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

	printf("\nInsertion Sort time: %f seconds", total_time);
	

}

void BubbleSort(int mas3[], int size) {

	clock_t start_time, end_time;
	double total_time;

	start_time = clock();

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (mas3[j] > mas3[j + 1]) {
				int el = mas3[j];
				mas3[j] = mas3[j + 1];
				mas3[j + 1] = el;
			}
		}
	}

	end_time = clock();
	total_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

	
	printf("\nBubble Sort time: %f seconds", total_time);
}


int main() {

	int *mas1, *mas2, *mas3;
	int size;
	printf("Enter the size of the masive: ");
	scanf_s("%d", &size);
	mas1 = (int*)malloc(size * sizeof(int));
	mas2 = (int*)malloc(size * sizeof(int));
	mas3 = (int*)malloc(size * sizeof(int));
	for (int i = 0; i < size; i++) {
		mas1[i] = mas2[i] = mas3[i] = rand() % 1000;
		printf("%d,", mas1[i]);
	}
	

	SelectionSort(mas1, size);
	InsertionSort(mas2, size);
	BubbleSort(mas3, size);

	free(mas1);
	free(mas2);
	free(mas3);

	return 0;
}