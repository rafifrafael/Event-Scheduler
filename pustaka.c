#include "pustaka.h"


void errorWaktu()
{
	int i=0;
	if(data[banyakData-1].wakMulai.h1<0 || data[banyakData-1].wakMulai.h1>23 || data[banyakData-1].wakMulai.m1<0 || data[banyakData-1].wakMulai.m1>=60)
    {
		fflush(stdin);
		system("cls");
		main();
	}
	else if(data[banyakData-1].wakSelesai.h2<0 || data[banyakData-1].wakSelesai.h2>23 || data[banyakData-1].wakSelesai.m2<0 || data[banyakData-1].wakSelesai.m2>=60)
	{
		fflush(stdin);
		system("cls");
		main();
	}
	else if(data[banyakData-1].wakMulai.h1 == data[banyakData-1].wakSelesai.h2 && data[banyakData-1].wakMulai.m1 == data[banyakData-1].wakSelesai.m2){
		fflush(stdin);
		system("cls");
		main();
	}
}

void jumlahhari (int *jmlh_hari,int bulan, int  tahun)
{
    if (bulan == 1 || bulan == 3 || bulan == 5 || bulan == 7 || bulan==8 || bulan == 10 || bulan ==12)
    {   ///kondisi untuk bulan yang memiliki jumlah hari 31
        *jmlh_hari = 31;
    }
    else if(bulan == 4|| bulan == 6 || bulan == 9 || bulan == 11)
    {  ///kondisi untuk bulan yang memiliki jumlah hari 30
        *jmlh_hari = 30;
    }
    else if (bulan == 2)
    {  ///kondisi untuk bulan februari
        if (tahun %4 ==0 && tahun %100 != 0 || tahun %400 == 0)
        {  ///kondisi untuk bulan februari dengan tahun kabisat
            *jmlh_hari = 29;
        }
        else
        {  ///kondisi untuk bulan februari selain tahun kabisat
            *jmlh_hari = 28;
        }
    }
}


void errorTgl()
{
	int i=0;
	int jumlah_hari;


    jumlahhari(&jumlah_hari, data[banyakData-1].tgl.mm, data[banyakData-1].tgl.yyyy);
    if(data[banyakData-1].tgl.dd<1 || data[banyakData-1].tgl.dd>jumlah_hari || data[banyakData-1].tgl.mm<1 || data[banyakData-1].tgl.mm>12 || data[banyakData-1].tgl.yyyy<2017)
    {
        printf("Tanggal yang anda masukkan salah!");
        banyakData--;
        getch();
        fflush(stdin);
        system("cls");
        main();
    }
}

int waktuSekarang()
{
	time_t Waktu;

	time(&Waktu);
	printf("Waktu Sekarang : %s", ctime(&Waktu));
}


void Menu()
{
	printf("Pilih Menu : \n");
	printf("1. Tambah Kegiatan\n");
	printf("2. Tampil Kegiatan\n");
	printf("3. Cari   Kegiatan\n");
	printf("4. Keluar\n");
}

void MenuPilihan()
{
	int pilihan;
	printf("Ketikkan Pilihan Menu : ");
        scanf("%d",&pilihan);
	if(pilihan<0 || pilihan >4){

	} else {
		switch(pilihan){
			case 1:
				input();
			break;
			case 2:
				output();
			break;
			case 3:
				cari();
			break;
			case 4:
				printf("Program Berhasil diclose");
				getch();
				exit(0);
			break;
		}
	}


}


void input()
{
	int i,j,jumlah_hari;
	int banyak_kegiatan;
	int pilihan;


		printf("\n=========== Tambah Kegiatan ===========\n\n");

		printf("Masukkan banyak Kegiatan : ");
            scanf("%d",&banyak_kegiatan);

		for(i=0;i<banyak_kegiatan;i++){
            banyakData++;
			printf("No. %i\n",i+1);
			printf("Masukkan Tanggal Kegiatan (dd-mm-yyyy)\t= ");
			scanf("%d-%d-%d",&data[banyakData-1].tgl.dd,&data[banyakData-1].tgl.mm,&data[banyakData-1].tgl.yyyy);
			errorTgl();
            }

			printf("Masukkan Waktu Mulai Kegiatan(hh:mm)\t= ");
			scanf("%d:%d",&data[banyakData-1].wakMulai.h1, &data[banyakData-1].wakMulai.m1);
			errorWaktu();

			printf("Masukkan Waktu Selesai Kegiatan(hh:mm)\t= ");
			scanf("%d:%d",&data[banyakData-1].wakSelesai.h2, &data[banyakData-1].wakSelesai.m2);
			errorWaktu();

			printf("Tempat Kegiatan\t\t= ");
			fflush(stdin);
                gets(data[banyakData - 1].tempat);
			printf("Nama Kegiatan\t\t= ");
			fflush(stdin);
                gets(data[banyakData - 1].kegiatan);
			printf("Orang2 yg Terlibat\t= ");
			fflush(stdin);
                gets(data[banyakData - 1].orangTerlibat);
			printf("Cat Tambahan\t\t= ");
			fflush(stdin);
                gets(data[banyakData - 1].catTambahan);
	}


void output()
{
	int i;
	int pilih_aksi;
    printf("Banyak data %d\n", banyakData);

	printf("|No |   Tanggal   | Waktu Mulai | Waktu Selesai | Tempat | Kegiatan | Orang yg Terilbat | Cat Tambahan |\n");
		for(i=0;i<banyakData;i++){
			printf("|%i  | %i-%i-%i  |   %i:%i     |     %i:%i     | %s | %s | %s | %s |\n",
				i+1, data[i].tgl.dd,data[i].tgl.mm,data[i].tgl.yyyy,
				data[i].wakMulai.h1,data[i].wakMulai.m1,data[i].wakSelesai.h2,data[i].wakSelesai.m2,
				data[i].tempat,data[i].kegiatan, data[i].orangTerlibat , data[i].catTambahan);
		}

	printf("\n\n");
	printf("Pilih Aksi : \n");
	printf("1. Hapus Data (berdasarkan nomor)\n");
	printf("2. Urutkan Data (berdasarkan Tanggal)\n");
	printf("3. Kembali ke Menu Utama\n");
	printf("Masukkan pilihan : ");
        scanf("%i",&pilih_aksi);

		switch(pilih_aksi){
			case 1:
				hapus();
			break;
			case 2:
				sortTgl();
			break;
			case 3:
				system("cls");
				main();
			break;
		}
}

void cari()
{
	int i;
	int cariTgl;

	printf("Masukkan Tanggal Kegiatan yang akan dicari : ");
        scanf("%d",&cariTgl);

	printf("|No | Tanggal | Waktu Mulai | Waktu Selesai | Tempat | Kegiatan | Orang yg Terlibat | Cat Tambahan |\n");
	for(i=0;i<=banyakData;i++){
		if(cariTgl == data[i].tgl.dd){
			printf("|%i | %i-%i-%i | %i:%i | %i:%i | %s | %s | %s |\n",
				i+1, data[i].tgl.dd,data[i].tgl.mm,data[i].tgl.yyyy,
				data[i].wakMulai.h1,data[i].wakMulai.m1,data[i].wakSelesai.h2,data[i].wakSelesai.m2,
				data[i].tempat,data[i].kegiatan, data[i].orangTerlibat ,data[i].catTambahan);
		}
	}
}



void hapus()
{
	int i,j;
	int pilihHapus;
	bool ketemu;

	printf("Masukkan Nomor Data yang akan dihapus : ");
        scanf("%d",&pilihHapus);

	for(i=0;i<banyakData;i++){
		if(pilihHapus == i+1){
			ketemu = true;
			if(ketemu){
				for(j=i;j<=banyakData+1;j++){
					data[j] = data[j+1];
				}
				banyakData--;
			}else{
				printf("Data yang akan dihapus TIDAK DITEMUKAN!!");
			}
		}
	}
}



void sortTgl()
{
	int i,j;
	for(i=0;i<banyakData;i++){
		for(j=0;j<banyakData;j++){
			if(data[j].tgl.yyyy > data[j+1].tgl.yyyy){
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			} else if(data[j].tgl.yyyy == data[j+1].tgl.yyyy && data[j].tgl.mm > data[j+1].tgl.mm){
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			} else if(data[j].tgl.yyyy== data[j+1].tgl.yyyy && data[j].tgl.mm == data[j+1].tgl.mm && data[j].tgl.dd > data[j+1].tgl.dd){
				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
		}
	}
	printf("|No | Tanggal | Waktu Mulai | Waktu Selesai | Tempat | Kegiatan | Orang yg Terilbat | Cat Tambahan |\n");
		for(j=0;j<banyakData;j++){
			printf("|%i | %i-%i-%i | %i:%i | %i:%i | %s | %s | %s | %s |\n",
				j+1, data[j+1].tgl.dd,data[j+1].tgl.mm,data[j+1].tgl.yyyy,
				data[j+1].wakMulai.h1,data[j+1].wakMulai.m1,data[j+1].wakSelesai.h2,data[j+1].wakSelesai.m2,
				data[j+1].tempat,data[j+1].kegiatan, data[j+1].orangTerlibat , data[j+1].catTambahan);
		}

}
