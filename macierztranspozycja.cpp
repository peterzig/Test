#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <float.h>


float **stworzTablice(int n, int m) {
	float **tab = (float **)malloc(sizeof(float *) * n);
	for (int i = 0; i < n; ++i) {
		tab[i] = (float *)malloc(sizeof(float) * m);
	}
	return tab;
}

void zwolnijPamiec(float **tab, int n) {
	for (int i = 0; i < n; ++i) {
		free(tab[i]);
	}
	free(tab);
}

void wyswietl(float **tab, int n, int m) {
	for (int i = 0; i < n; ++i) {
		printf("");
		for (int j = 0; j < m; ++j) {
			printf("%.2f ", tab[i][j]);
		}
		printf("\n");
	}
}
void transpozycja(float **tab, int n, int m) {
	for (int i = 0; i < m; ++i) {
		printf("");
		for (int j = 0; j < n; ++j) {
			printf("%.2f ", tab[j][i]);
		}
		printf("\n");
	}
}



int main() {
	int n, m;
	float min = FLT_MAX, max = FLT_MIN;
	int minIndeks = 0, maxIndeks = 0; //indeks pierwszej tablicy (i)
	int minIndeks2 = 0, maxIndeks2 = 0; //potrzebujemy zapisac gdzies jeszcze drugi indeks tablicy (j)

	do {
		printf("Podaj liczbe wierszy: ");
		scanf("%d", &n);
	} while (n<1);

	do {
		printf("Podaj liczbe kolumn: ");
		scanf("%d", &m);
	} while (m<1);

	float **tab2 = stworzTablice(n, m);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			printf("T[%d, %d] = ", i + 1, j + 1);
			scanf("%f", &tab2[i][j]);

			if (tab2[i][j] < min) {
				min = tab2[i][j];
				minIndeks = i;
				minIndeks2 = j;
			}
			if (tab2[i][j] > max) {
				max = tab2[i][j];
				maxIndeks = i;
				maxIndeks2 = j;
			}
		}
	}

	wyswietl(tab2, n, m);
	printf("\n");
	transpozycja(tab2, n, m);

	printf("Wartosc najmniejsza = %lf na pozycji [%d, %d].\n", min, minIndeks + 1, minIndeks2 + 1);
	printf("Wartosc najwieksza = %lf na pozycji [%d, %d].\n", max, maxIndeks + 1, maxIndeks2 + 1);

	zwolnijPamiec(tab2, n);

	_getch();
	return 0;
}
