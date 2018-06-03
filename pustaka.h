#ifndef PUSTAKA_H_INCLUDED
#define PUSTAKA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

    struct tanggal{
		int dd;
		int mm;
		int yyyy;
	};

	struct waktuMulai{
		int h1;
		int m1;
	};

	struct waktuSelesai{
		int h2;
		int m2;
	};

	struct{
		struct tanggal tgl;
		struct waktuMulai wakMulai;
		struct waktuSelesai wakSelesai;
		char tempat[30];
		char kegiatan[50];
		char orangTerlibat[100];
		char catTambahan[100];
	}data[],temp;



    void input();
	void output();
	void hapus();
	void cari();
	void sortTgl();
	void pilihAksi();
	int Sekarang();
	int banyakData;
	void Menu();
	void MenuPilihan();
	void errorTgl();
	void errorWaktu();
	void jumlahhari (int *jmlh_hari,int bulan, int  tahun);


#endif // PUSTAKA_H_INCLUDED
