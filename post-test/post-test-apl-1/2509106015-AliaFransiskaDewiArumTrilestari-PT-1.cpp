#include <iostream>
using namespace std;

int main() {
    string nama, password;
    string username = "Alia";
    string pass = "015";
    int kesempatan = 3;
    bool aksesLogin = false;
    
    cout << "+----------------------------------------------+" << endl;
    cout << "|   SELAMAT DATANG DI PROGRAM KONVERSI WAKTU   |" << endl;
    cout << "+----------------------------------------------+" << endl;

    while(kesempatan > 0) {
        cout << "\nSilahkan Login. Kesempatan Login: " << kesempatan << endl;
        cout << "Nama     : ";
        cin >> nama;
        cout << "Password : ";
        cin >> password;
        
        if(nama == username && password == pass) {
            cout << "LOGIN BERHASIL! " << nama << endl;
            aksesLogin = true;
            break;
        } else {
            cout << "Login tidak berhasil! Pastikan nama dan password benar." << endl;
            kesempatan = kesempatan - 1; 
        }
    }
    if(aksesLogin == false) {
        cout << "\nKESEMPATAN LOGIN SEBANYAK 3 KALI SUDAH HABIS!" << endl;
        return 0;
    }
    int pilihan;
    while(true) {
        cout << endl;
        cout << "+========================================+" << endl;
        cout << "|              DAFTAR MENU               |" << endl;
        cout << "+========================================+" << endl;
        cout << "|  1. Konversi Jam ke Menit dan Detik    |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "|  2. Konversi Menit ke Jam dan Detik    |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "|  3. Konversi Detik ke Jam dan Menit    |" << endl;
        cout << "+----------------------------------------+" << endl;
        cout << "|  4. Keluar                             |" << endl;
        cout << "+========================================+" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        
        if(pilihan == 1) {
            int jam;
            cout << "\n=== KONVERSI JAM KE MENIT & DETIK ===" << endl;
            cout << "Masukkan jumlah jam: ";
            cin >> jam;
            
            int menit = jam * 60;
            int detik = jam * 3600;
            
            cout << "\nHasil Konversi:" << endl;
            cout << jam << " jam = " << menit << " menit" << endl;
            cout << jam << " jam = " << detik << " detik" << endl;
        }
        else if(pilihan == 2) {
            int menit;
            cout << "\n=== KONVERSI MENIT KE JAM & DETIK ===" << endl;
            cout << "Masukkan jumlah menit: ";
            cin >> menit;
            
            int jam = menit / 60;
            int sisaMenit = menit % 60;
            int detik = menit * 60;
            
            cout << "\nHasil Konversi:" << endl;
            cout << menit << " menit = " << jam << " jam " << sisaMenit << " menit" << endl;
            cout << menit << " menit = " << detik << " detik" << endl;
        }
        else if(pilihan == 3) {
            int detik;
            cout << "\n=== KONVERSI DETIK KE JAM & MENIT ===" << endl;
            cout << "Masukkan jumlah detik: ";
            cin >> detik;
            
            int jam = detik / 3600;
            int sisa = detik % 3600;
            int menit = sisa / 60;
            int sisaDetik = sisa % 60;
            
            cout << "\nHasil Konversi:" << endl;
            cout << detik << " detik = " << jam << " jam " << menit << " menit " << sisaDetik << " detik" << endl;
        }
        else if(pilihan == 4) {
            cout << "\nPROGRAM SELESAI! TERIMA KASIH TELAH MENGGUNAKAN PROGRAM" << endl;
            break;
        }
        else {
            cout << "\nPilihan tidak tersedia! Pilih angka 1-4." << endl;
        }
    }
    return 0;
}