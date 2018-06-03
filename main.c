#include "pustaka.h"


int main(void)
{
	int pilihan;
	do{
		waktuSekarang();
		printf("============================================");

		printf("\n\n");

		Menu();

		MenuPilihan();

	printf("\n\n");

	fflush(stdin);
		printf("\n\nTekan 0 untuk kembali ke Menu "); scanf("%i",&pilihan);
		system("cls");

	}while(pilihan==0);
}
