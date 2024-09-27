#include <stdio.h>

int main(){
    unsigned int suhu1, suhu2;   //Variabel untuk pilihan satuan suhu, suhu1 untuk satuan suhu awal, suhu2 untuk satuan suhu hasil.
    unsigned int appmode=2;     /*Variabel untuk mode aplikasi. Mode 1 akan menggunakan suhu sama yang sudah diinput sebelumnya.
                                  Mode 2 operator harus menginput suhu baru. Lebih dari 2 akan menutup kalkulator. */
    float suhuawal, suhudic, suhuakhir; //Variabel untuk menyimpan suhu yang diinput, suhu penengah, dan suhu hasil kalkulasi.
    printf("## Kalkulator Konversi Suhu Celcius Reamur Fahrenheit Kelvin ##");
    
    do{ //Kalkulator akan terus berjalan selama belum ditutup lewat opsi pilihan.
        pilihsuhuawal:  //Pemilihan satuan suhu awal yang diinput.
        printf("\n 1. Celcius\n 2. Reamur\n 3. Fahrenheit\n 4. Kelvin\n ~. Tutup kalkulator\nPilihan Suhu Awal : ");
		scanf("%d", &suhu1);    //Menginput angka lebih besar dari 4 akan menutup kalkulator.
		if (suhu1>4){   
		    printf("\nKalkulator Ditutup");
		    return 0;
		}
		
		pilihsuhuakhir: //Pemilihan satuan suhu hasil kalkulasi.
		printf("\n 1. Celcius\n 2. Reamur\n 3. Fahrenheit\n 4. Kelvin\n 5. Ulangi Memilih Satuan Suhu\n ~. Tutup Kalkulator\nPilihan Suhu Akhir : ");
		scanf("%d", &suhu2);
		if (suhu2==5){  //Menginput angka 5 maka akan mengulang memilih satuan suhu awal, menginput angka lebih besar dari 5 akan menutup kalkulator.
		    goto pilihsuhuawal;
		} else if (suhu2>5){
		    printf("\nKalkulator Ditutup");
		    return 0;
		}
		
		if(appmode==2){    //jika appmode=1 maka kalkulator akan menggunakan suhu sebelumnya, jika appmode=2 operator harus menginput angka suhu baru
    		switch (suhu1){ //kalkulasi dari satuan suhu awal ke satuan C dimana digunakan sebagai suhu penengah
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
		}

        switch (suhu2){ //Kalkulasi dari satuan suhu penengah(C) ke satuan suhu akhir sekaligus menunjukkan hasil kalkulasi
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
        
        printf("\n 1. Lanjut dengan suhu yang sama\n 2. Masukkan suhu berbeda\n ~. Tutup Kalkulator\n Lanjutkan? ");  //Pemilihan mode kalkulator.
        scanf("%d", &appmode);
        switch (appmode){
            case 1:
                goto pilihsuhuakhir;
                break;
            case 2:
                goto pilihsuhuawal;
                break;
            default:
                printf("Kalkulator Ditutup");
                return 0;
        }
    } while (suhu1<5|suhu2<6);
}