#include <iostream>
#include <conio.h>
#include <limits>

using namespace std;

int main() {
	int noRekening, pinRekening;
	int saldo = 10000;
	int tambahTabungan;
	int ambilTabungan;
	int simpananWajibBank;
	int pilihTransaksi;
	char backToLogin, backToTransaksi, backToTT, backToAT;
		
	backToLogin:
	cout << "#======================================#\n\n 	      PT.BANK ABC\n\n#======================================#\n\n";
	cout << "Selamat datang di PT.BANK ABC. Silahkan masukan No.Rekening dan PIN untu melakukan Transaksi !\n\n";
	
	while(cout << "O> Masukan No.Rekening 	: " && !(cin >> noRekening)){
		cout << "\n";
		cout << "O> Message : No.Rekening berupa angka !. anda tidak boleh menginputkan Huruf.";
		cout << "\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	while(cout << "O> Masukan PIN Rekening : " && !(cin >> pinRekening)) {
		cout << "\n";
		cout << "O> Message : PIN Rekening berupa angka !. anda tidak boleh menginputkan Huruf.";
		cout << "\n\n";
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	system("CLS");
	{
		if(noRekening == 15637981 and pinRekening == 1234) {
			backToTransaksi:
			cout << "\n";
			cout << "Selamat datang !. Silahkan pilih Transaksi yang ingin anda proses.\n\n";
			
			cout << "O> Jumlah saldo anda : " << saldo;
			cout << "\n\n";
			
			cout << "O> 1. Tambah Tabungan\n";
			cout << "O> 2. Ambil Tabungan\n";
			cout << "O> 3. Keluar\n\n";
			
			while(cout << "Masukan kode transaksi : " && !(cin >> pilihTransaksi)) {
				cout << "O> Keyword yang anda masukan salah. Harap masukan keyword yang sudah di sediakan !\n\n";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "\n";	
			}
			{
				if(pilihTransaksi == 1) {
					backToTT:
					cout << "\n";
					while(cout << "Masukan nominal tabungan anda : " && !(cin >> tambahTabungan)){
						cout << "O> Message : Harap masukan nominal berupa Angka.";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\n";
					}
					{
						if(tambahTabungan < 50000) {
							cout << "O> Mohon maaf anda tidak bisa menabung, Karena batas minimal menabung senilai Rp.50.000\n\n";
						
							cout << "Ingin mengulanginya ? (Y/N) : ";
							cin >> backToTT;
							cout << "\n";
							if(backToTT == 'y' || backToTT == 'Y') {
								goto backToTT;
							}
						}
						else{
							saldo = saldo + tambahTabungan;
							cout << "O> Berhasil menambah tabungan, Saldo anda saat ini senilai Rp." << saldo;
							cout << "\n\n";	
						}	
					}
				}
				else if(pilihTransaksi == 2) {
					backToAT:
					cout << "\n";
					while(cout << "Masukan nominal yang ingin anda ambil : " && !(cin >> ambilTabungan)){
						cout << "O> Message : Harap masukan nominal berupa Angka.";
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "\n\n";
					}
					{
						simpananWajibBank = saldo - ambilTabungan;
					
						if(ambilTabungan < 50000) {
							cout << "O> Mohon maaf anda tidak bisa mengambil uang tabungan anda. Karena minimal pengambilan uang sebesar Rp.50.000\n\n";
							
							cout << "Ingin mengulanginya ? (Y/N) : ";
							cin >> backToAT;
							cout << "\n";
								
							if(backToAT == 'y' || backToAT == 'Y') {
								goto backToAT;
							}
						}
						else{
							if(ambilTabungan > saldo) {
								cout << "O> Mohon maaf saldo anda tidak mencukupi !.\n\n";
								
								cout << "Ingin mengulanginya ? (Y/N) : ";
								cin >> backToAT;
								cout << "\n";
								
								if(backToAT == 'y' || backToAT == 'Y') {
									goto backToAT;
								}
							}
							else if(simpananWajibBank < 10000) {
								cout << "O> Mohon maaf anda tidak bisa mengambil uang tabungan anda, Karena harus ada simpanan wajib di bank sebesar Rp.10.000\n\n";
								
								cout << "Ingin mengulanginya ? (Y/N) : ";
								cin >> backToAT;
								cout << "\n";
								
								if(backToAT == 'y' || backToAT == 'Y') {
									goto backToAT;
								}
							}
							else{
								saldo = saldo - ambilTabungan;
								cout << "O> Berhasil mengambil uang, Sisa saldo anda saat ini : Rp." << saldo;
								cout << "\n\n";
							}
						}	
					}						
				}
				
				else if(pilihTransaksi == 3) {
					cout << "\n";
					cout << "Terimakasih telah melakukan Transaksi";
					exit(0);
				}
				else{
					cout << "O> Keyword yang anda masukan salah. Harap masukan keyword yang sudah di sediakan !\n\n";
				}
				
				cout << "Ingin melakukan transaksi lagi ? (Y/N) : ";
				cin >> backToTransaksi;
				cout << "\n";
				if(backToTransaksi == 'y' || backToTransaksi == 'Y') {
					system("CLS");
					goto backToTransaksi;
				}
				else{
					system("CLS");
					goto backToLogin;
				}
			}
		}
		else{
			cout << "\n";
			cout << "O> Message : Mohon maaf. Harap masukan kembali No.Rekening dan PIN dengan benar !\n\n";
			
			cout << "Ingin mengulang kembali ? (Y/N) : ";
			cin >> backToLogin;
			cout << "\n";
			if(backToLogin == 'y' || backToLogin == 'Y') {
				system("CLS");
				goto backToLogin;
			}
			else{
				system("CLS");
				cout << "Terimakasih telah datang di bank kami !.";
				exit(0);
			}
		}
	}
}
