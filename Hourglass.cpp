#include <stdio.h>
#include <windows.h>
#include <time.h>

int main()
{
	int i, j, k, l, size, seconds;
	float totalTime, displaySec;
	time_t start_t, end_t;
	double diff_t;

	// input to the user
	printf("Enter the time in seconds: ");
	scanf_s("%d", &seconds);
	printf("Enter the size of the sand clock: ");
	scanf_s("%d", &size);

	displaySec = totalTime = seconds * ((size / 2) - 1);
	displaySec = seconds;
	size += !(size % 2);
	for (l = 0; l < (size + 1) / 2; l++) {
		time(&start_t);
		for (i = 0, k = size - 1; i < size; i++, k--, totalTime--) {
			for (j = 0; j < size; j++) {
				if (i == j || j == i - 2 && j<k
					|| j == k - 2 && j<i || j == k
					|| j == k + 2 && j>i || j == i + 2 && j>k) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
					printf("0 ");
				}
				else if (j == i - 1 && j<k
					|| j == k - 1 && j<i
					|| j == k + 1 && j>i
					|| j == i + 1 && j>k) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
					printf("O ");
				}
				else if ((j > i && j<k && i>l - 1)
					|| (j<i && j>k && l > k)) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					printf("* ");
				}
				else printf("  ");
			}
			printf("\n");
		}
		for (i = 0; i < size - 12; i++) printf(" ");

		printf("Time left: %1.1f seconds", displaySec);
		displaySec -= seconds / ((float)size / 2);

		time(&end_t);
		diff_t = difftime(end_t, start_t);
		Sleep((1000 * (seconds / (size / 2))) - diff_t);
		system("cls");
	}
	// Time out display
	for (i = 0, k = size - 1; i < size; i++, k--) {
		for (j = 0; j < size; j++) {
			if (i == j || j == i - 2 && j<k
				|| j == k - 2 && j<i || j == k
				|| j == k + 2 && j>i || j == i + 2 && j>k) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
				printf("0 ");
			}
			else if (j == i - 1 && j<k
				|| j == k - 1 && j<i
				|| j == k + 1 && j>i
				|| j == i + 1 && j>k) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				printf("O ");
			}
			else if ((j > i && j<k && i>l - 1)
				|| (j<i && j>k && l > k)) {
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
				printf("* ");
			}
			else printf("  ");
		}
		printf("\n");
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);

	// printing spaces to align the TIMES OUT! text to center
	for (i = 0; i < size - 5; i++) printf(" ");

	printf("TIMES OUT!");
	// beep sound
	Beep(1000, 400);
	Beep(750, 200);
	Beep(1000, 400);
	Beep(750, 200);
	Beep(1000, 400);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}
