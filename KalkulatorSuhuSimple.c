#include <stdio.h>

int main(){
    int suhu1, suhu2;					//Variabel untuk pilihan satuan suhu, suhu1 untuk satuan suhu awal, suhu2 untuk satuan suhu hasil.
    float suhuawal, suhudic, suhuakhir;	//Variabel untuk menyimpan suhu yang diinput, suhu penengah, dan suhu hasil kalkulasi.
    printf("## Kalkulator Suhu Celcius Reamur Fahrenheit Kelvin ##");
    
    do{	//Kalkulator akan terus berjalan selama belum ditutup lewat opsi pilihan.
        start:	
		//Pemilihan satuan suhu awal yang diinput.
        printf("\n 1. Celcius\n 2. Reamur\n 3. Fahrenheit\n 4. Kelvin\n ~. Tutup kalkulator\nPilihan Suhu Awal : ");	
		scanf("%d", &suhu1);
		if (suhu1>4){
		    printf("\nAplikasi Ditutup");
		    return 0;
		}
		
		//Pemilihan satuan suhu hasil kalkulasi.
		printf("\n 1. Celcius\n 2. Reamur\n 3. Fahrenheit\n 4. Kelvin\n 5. Ulangi Memilih Satuan Suhu\n ~. Tutup Kalkulator\nPilihan Suhu Akhir : ");	
		scanf("%d", &suhu2);
		if (suhu2==5){		//Menginput angka 5 maka akan mengulang memilih satuan suhu awal, menginput angka lebih besar dari 5 akan menutup kalkulator.
		    goto start;
		} else if (suhu2>5){
		    printf("\nAplikasi Ditutup");
		    return 0;
		}
		
        
		switch (suhu1){		//kalkulasi dari satuan suhu awal ke satuan C dimana digunakan sebagai suhu penengah
			case 1:
			    printf("\nSuhu Awal dalam Celcius : ");
		        scanf("%f", &suhuawal);
				suhudic = suhuawal;
				break;
			case 2:
			    printf("\nSuhu Awal dalam Reamur : ");
		        scanf("%f", &suhuawal);
				suhudic = suhuawal*5/4;
				break;
			case 3:
			    printf("\nSuhu Awal dalam Fahrenheit : ");
		        scanf("%f", &suhuawal);
				suhudic = (suhuawal-32.00)*9/5;
				break;
			case 4:
			    printf("\nSuhu Awal dalam Kelvin: ");
		        scanf("%f", &suhuawal);
				suhudic = suhuawal-273.00;
				break;
			default:
				return 0;
				break;
		}

        switch (suhu2){	//Kalkulasi dari satuan suhu penengah(C) ke satuan suhu akhir sekaligus menunjukkan hasil kalkulasi
			case 1:
				suhuakhir = suhudic;
				printf("Suhu Akhir dalam Celcius : %.3f C\n", suhuakhir);
				break;
			case 2:
				suhuakhir = suhudic*4/5;
				printf("Suhu Akhir dalam Reamur : %.3f R\n", suhuakhir);
				break;
			case 3:
				suhuakhir = (suhudic*9/5)+32;
				printf("Suhu Akhir dalam Fahrenheit : %.3f F\n", suhuakhir);
				break;
			case 4:
				suhuakhir = suhudic+273.00;
				printf("Suhu Akhir dalam Kelvin : %.3f K\n", suhuakhir);
				break;
			default:
				return 0;
				break;
        }
    } while (suhu1<5|suhu2<6);
}