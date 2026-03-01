#include <iostream>
using namespace std;

int main() {
    string nama, password;
    string username = "Alia";
    string pass = "015";
    int kesempatan = 3;
    bool aksesLogin = false;
    
    cout << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << "|   SELAMAT DATANG DI PROGRAM KONVERSI WAKTU   |" << endl;
    cout << "+----------------------------------------------+" << endl;
    cout << endl;
    
    while(kesempatan > 0) {
        cout << "Silahkan Login. Kesempatan Login: " << kesempatan << " kali" << endl;
        cout << "Nama     : ";
        getline(cin, nama);
        
        bool verifikasiNama = true;
        if(nama.empty()) {
            cout << "ERROR: Nama tidak boleh kosong!" << endl;
            verifikasiNama = false;
        } else {
            for(int i = 0; i < nama.length(); i++) {
                if(nama[i] >= '0' && nama[i] <= '9') {
                    cout << "ERROR: Nama tidak boleh berupa angka!" << endl;
                    verifikasiNama = false;
                    break;
                }
            }
        }
        if(!verifikasiNama) {
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore(1000, '\n');
            cin.get();
            continue; 
        }
        cout << "Password : ";
        getline(cin, password);
        
        bool verifikasiPassword = true;
        if(password.empty()) {
            cout << "ERROR: Password tidak boleh kosong!" << endl;
            verifikasiPassword = false;
        } else {    
            for(int i = 0; i < password.length(); i++) {
                if(password[i] < '0' || password[i] > '9') {
                    cout << "ERROR: Password harus berupa angka!" << endl;
                    verifikasiPassword = false;
                    break;
                }
            }
        }
        if(!verifikasiPassword) {
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore(1000, '\n');
            cin.get();
            continue;
        }
        if(nama == username && password == pass) {
            cout << endl;
            cout << "LOGIN BERHASIL!" << endl;
            cout << "Selamat datang, " << nama << "!" << endl;
            aksesLogin = true;
            break;
        } else {
            cout << endl;
            cout << "LOGIN GAGAL!" << endl;
            cout << "Pastikan nama dan password benar." << endl;
            cout << "Tekan Enter untuk mencoba lagi...";
            cin.ignore(1000, '\n');
            cin.get();
            kesempatan--;
        }
    }
    if(aksesLogin == false) {
        cout << endl;
        cout << "KESEMPATAN 3 KALI LOGIN SUDAH HABIS" << endl;
        cout << endl;
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
        
        if(!(cin >> pilihan)) {
            cout << endl;
            cout << "ERROR: Input harus berupa angka!" << endl;
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.clear();
            cin.ignore(1000, '\n');
            cin.get();
            continue;
        }
        
        cin.ignore(1000, '\n');
        
        if(pilihan < 1 || pilihan > 4) {
            cout << endl;
            cout << "ERROR: Pilihan hanya tersedia dari 1 sampai 4!" << endl;
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.get();
            continue;
        }
        
        if(pilihan == 1) {
            int jam;
            cout << endl;
            cout << "KONVERSI JAM KE MENIT & DETIK" << endl;
            
            while(true) {
                cout << "Masukkan jumlah jam: ";
                if(cin >> jam) {
                    cin.ignore(1000, '\n');
                    break;
                } else {
                    cout << "ERROR: Input harus berupa angka!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
            
            int menit = jam * 60;
            int detik = jam * 3600;
            
            cout << endl;
            cout << "HASIL KONVERSI:" << endl;
            cout << "" << jam << " jam = " << menit << " menit" << endl;
            cout << "" << jam << " jam = " << detik << " detik" << endl;
            
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.get();
        }
        else if(pilihan == 2) {
            int menit;
            cout << endl;
            cout << "KONVERSI MENIT KE JAM & DETIK" << endl;
            
            while(true) {
                cout << "Masukkan jumlah menit: ";
                if(cin >> menit) {
                    cin.ignore(1000, '\n');
                    break;
                } else {
                    cout << "ERROR: Input harus berupa angka!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
            
            int jam = menit / 60;
            int sisaMenit = menit % 60;
            int detik = menit * 60;
            
            cout << endl;
            cout << "HASIL KONVERSI:" << endl;
            cout << "" << menit << " menit = " << jam << " jam " << sisaMenit << " menit" << endl;
            cout << "" << menit << " menit = " << detik << " detik" << endl;
            
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.get();
        }
        else if(pilihan == 3) {
            int detik;
            cout << endl;
            cout << "KONVERSI DETIK KE JAM & MENIT" << endl;
            
            while(true) {
                cout << "Masukkan jumlah detik: ";
                if(cin >> detik) {
                    cin.ignore(1000, '\n');
                    break;
                } else {
                    cout << "ERROR: Input harus berupa angka!" << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
            
            int jam = detik / 3600;
            int sisa = detik % 3600;
            int menit = sisa / 60;
            int sisaDetik = sisa % 60;
            
            cout << endl;
            cout << "HASIL KONVERSI:" << endl;
            cout << "" << detik << " detik = " << jam << " jam " << menit << " menit " << sisaDetik << " detik" << endl;
            
            cout << "Tekan Enter untuk kembali ke menu...";
            cin.get();
        }
        else if(pilihan == 4) {
            cout << endl;
            cout << "PROGRAM SELESAI! TERIMA KASIH TELAH MENGGUNAKAN PROGRAM" << endl;
            cout << endl;
            break;
        }
    }
    return 0;
}