#include <iostream>
#include <vector>
#include <string>
#include "../../table/text_table.h"
using namespace std;

int main() {
    struct User {
        string username;      
        string password;   
    };
    struct RincianTas {
        string model;
        string bahan;
    };
    struct TasSekolah {
        int id;
        string nama;
        double harga;
        int stok;
        RincianTas detail;
    };

    User daftarUser[100];
    int jumlahUser = 0;
    
    daftarUser[jumlahUser].username = "alia";
    daftarUser[jumlahUser].password = "015";
    jumlahUser++;
    
    TasSekolah daftarTas[150];
    int jumlahTas = 0;
    int idTas = 1;

    daftarTas[jumlahTas].id = idTas++;
    daftarTas[jumlahTas].nama = "Tas Ransel Backpack Standar";
    daftarTas[jumlahTas].harga = 150000;
    daftarTas[jumlahTas].stok = 25;
    daftarTas[jumlahTas].detail.model = "Ransel";
    daftarTas[jumlahTas].detail.bahan = "Nylon";
    jumlahTas++;

    daftarTas[jumlahTas].id = idTas++;
    daftarTas[jumlahTas].nama = "Tas Sekolah Karakter 3D";
    daftarTas[jumlahTas].harga = 160000;
    daftarTas[jumlahTas].stok = 20;
    daftarTas[jumlahTas].detail.model = "Ransel";
    daftarTas[jumlahTas].detail.bahan = "Polyester";
    jumlahTas++;

    daftarTas[jumlahTas].id = idTas++;
    daftarTas[jumlahTas].nama = "Tas Korean Style";
    daftarTas[jumlahTas].harga = 85000;
    daftarTas[jumlahTas].stok = 40;
    daftarTas[jumlahTas].detail.model = "Selempang";
    daftarTas[jumlahTas].detail.bahan = "Kanvas";
    jumlahTas++;

    daftarTas[jumlahTas].id = idTas++;
    daftarTas[jumlahTas].nama = "Tas Sekolah Beroda";
    daftarTas[jumlahTas].harga = 200000;
    daftarTas[jumlahTas].stok = 15;
    daftarTas[jumlahTas].detail.model = "Koper Roda";
    daftarTas[jumlahTas].detail.bahan = "Nylon";
    jumlahTas++;

    daftarTas[jumlahTas].id = idTas++;
    daftarTas[jumlahTas].nama = "Tas Laptop";
    daftarTas[jumlahTas].harga = 124000;
    daftarTas[jumlahTas].stok = 18;
    daftarTas[jumlahTas].detail.model = "Laptop";
    daftarTas[jumlahTas].detail.bahan = "Kulit Sintetis";
    jumlahTas++;

    bool login = false;
    int pilihanLogin, pilihanMenu;
    
    string nama, pass;
    int kesempatanLogin = 3;
    int inputId, stokBaruTas;

    while (!login) {
        cout << "\n+==========================================+" << endl;
        cout << "|               Menu Login                 |" << endl;
        cout << "+==========================================+" << endl;
        cout << "|  1. Login                                |" << endl;
        cout << "|  2. Register                             |" << endl;
        cout << "|  3. Keluar                               |" << endl;
        cout << "+==========================================+" << endl;
        cout << "Pilihan : ";
        cin >> pilihanLogin;

        if (pilihanLogin == 2) {
            cout << "\n=== REGISTER ===" << endl;
            cout << "Username : ";
            cin >> daftarUser[jumlahUser].username;
            cout << "Password : ";
            cin >> daftarUser[jumlahUser].password;
            jumlahUser++; 
            cout << "Berhasil! Silakan login." << endl;
        } 
        else if (pilihanLogin == 1) {
            bool aksesLogin = false;
            kesempatanLogin = 3; 

            while (kesempatanLogin > 0) {
                cout << "\n=== LOGIN ===" << endl;
                cout << "Kesempatan: " << kesempatanLogin << endl;
                cout << "Username : ";
                cin >> nama;
                cout << "Password : ";
                cin >> pass;

                for (int i = 0; i < jumlahUser; i++) {
                    if (daftarUser[i].username == nama && daftarUser[i].password == pass) {
                        aksesLogin = true;
                        login = true;
                        cout << "LOGIN BERHASIL! Selamat datang di program." << endl;
                        break;
                    }
                }

                if (aksesLogin) break;
                else {
                    cout << "LOGIN GAGAL! Pastikan nama dan password benar." << endl;
                    kesempatanLogin--;
                    if (kesempatanLogin == 0) {
                        cout << "\nKESEMPATAN SEBANYAK 3 KALI SUDAH HABIS!" << endl;
                        return 0;
                    }
                }
            }
        } 
        else if (pilihanLogin == 3) {
            cout << "\nTerima kasih!" << endl;
            return 0;
        } 
        else {
            cout << "Pilihan tidak tersedia! Pilih angka 1-3" << endl;
        }
    }

    while (true) {
        cout << "\n+======================================+" << endl;
        cout << "|             DAFTAR MENU              |" << endl;
        cout << "+======================================+" << endl;
        cout << "|  1. Tambah Tas (Create)              |" << endl;
        cout << "|  2. Lihat Tas (Read)                 |" << endl;
        cout << "|  3. Update Stok (Update)             |" << endl;
        cout << "|  4. Hapus Tas (Delete)               |" << endl;
        cout << "|  5. Rincian Toko                     |" << endl;
        cout << "|  6. Logout                           |" << endl;
        cout << "+======================================+" << endl;
        cout << "Pilihan : ";
        cin >> pilihanMenu;

        if (pilihanMenu == 1) {
            cout << "\n=== TAMBAH TAS SEKOLAH ===" << endl;
            daftarTas[jumlahTas].id = idTas++;
            
            cout << "Nama Tas : ";
            cin.ignore(1000, '\n');
            getline(cin, daftarTas[jumlahTas].nama);
            
            cout << "Model : ";
            getline(cin, daftarTas[jumlahTas].detail.model);
            
            cout << "Harga (Rp) : ";
            cin >> daftarTas[jumlahTas].harga;
            
            cout << "Stok : ";
            cin >> daftarTas[jumlahTas].stok;
            
            cout << "Bahan : ";
            cin.ignore(1000, '\n');
            getline(cin, daftarTas[jumlahTas].detail.bahan);

            jumlahTas++; 
            cout << "Tas berhasil ditambahkan!" << endl;
            cout << "Tekan Enter untuk lanjut...";
            cin.get();
        } 
        else if (pilihanMenu == 2) {
            cout << "\n=== KATALOG TAS SEKOLAH ===" << endl;
            if (jumlahTas == 0) {
                cout << "Belum ada tas." << endl;
            } else {
                TextTable tabel('-', '|', '+');
                
                vector<string> header = {"ID", "Nama Tas", "Harga", "Stok", "Model", "Bahan"};
                tabel.add(header);
                
                for (int i = 0; i < jumlahTas; i++) {
                    vector<string> row;
                    row.push_back(to_string(daftarTas[i].id));
                    row.push_back(daftarTas[i].nama);
                    row.push_back("Rp " + to_string((int)daftarTas[i].harga));
                    row.push_back(to_string(daftarTas[i].stok));
                    row.push_back(daftarTas[i].detail.model);
                    row.push_back(daftarTas[i].detail.bahan);
                    tabel.add(row);
                }
                
                cout << tabel;
            }
            cout << "Tekan Enter untuk lanjut...";
            cin.ignore(1000, '\n'); 
            cin.get();
        } 
        else if (pilihanMenu == 3) {
            cout << "\n=== UPDATE STOK ===" << endl;
            TextTable tabel('-', '|', '+');
                
            vector<string> header = {"ID", "Nama Tas", "Harga", "Stok", "Model", "Bahan"};
            tabel.add(header);
                
            for (int i = 0; i < jumlahTas; i++) {
                vector<string> row;
                row.push_back(to_string(daftarTas[i].id));
                row.push_back(daftarTas[i].nama);
                row.push_back("Rp " + to_string((int)daftarTas[i].harga));
                row.push_back(to_string(daftarTas[i].stok));
                row.push_back(daftarTas[i].detail.model);
                row.push_back(daftarTas[i].detail.bahan);
                tabel.add(row);
            }
                
            cout << tabel << endl;
            cout << "ID Tas : ";
            cin >> inputId;

            bool ditemukan = false;
            for (int i = 0; i < jumlahTas; i++) {
                if (daftarTas[i].id == inputId) {
                    cout << "Ditemukan: " << daftarTas[i].nama << endl;
                    cout << "Stok Sekarang: " << daftarTas[i].stok << endl;
                    cout << "Stok Baru : ";
                    cin >> stokBaruTas;
                    
                    daftarTas[i].stok = stokBaruTas;
                    cout << "Stok diupdate!" << endl;
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) cout << "ID tidak ditemukan!" << endl;
            cout << "Tekan Enter untuk lanjut...";
            cin.ignore(1000, '\n'); 
            cin.get();
        } 
        else if (pilihanMenu == 4) {
            cout << "\n=== HAPUS TAS ===" << endl;
            TextTable tabel('-', '|', '+');
                
            vector<string> header = {"ID", "Nama Tas", "Harga", "Stok", "Model", "Bahan"};
            tabel.add(header);
                
            for (int i = 0; i < jumlahTas; i++) {
                vector<string> row;
                row.push_back(to_string(daftarTas[i].id));
                row.push_back(daftarTas[i].nama);
                row.push_back("Rp " + to_string((int)daftarTas[i].harga));
                row.push_back(to_string(daftarTas[i].stok));
                row.push_back(daftarTas[i].detail.model);
                row.push_back(daftarTas[i].detail.bahan);
                tabel.add(row);
            }
                
            cout << tabel << endl;
            cout << "ID Tas : ";
            cin >> inputId;

            bool ditemukan = false;
            for (int i = 0; i < jumlahTas; i++) {
                if (daftarTas[i].id == inputId) {
                    cout << "Menghapus: " << daftarTas[i].nama << endl;
                    
                    for (int j = i; j < jumlahTas - 1; j++) {
                        daftarTas[j] = daftarTas[j + 1];
                    }
                    jumlahTas--;
                    cout << "Tas dihapus!" << endl;
                    
                    ditemukan = true;
                    break;
                }
            }
            if (!ditemukan) cout << "ID tidak ditemukan!" << endl;
            cout << "Tekan Enter untuk lanjut...";
            cin.ignore(1000, '\n'); 
            cin.get();
        }
        else if (pilihanMenu == 5) {
            cout << "\n=== RINCIAN TOKO ===" << endl;
            
            int totalStok = 0;
            double totalHarga = 0;  
            
            for (int i = 0; i < jumlahTas; i++) {
                totalStok += daftarTas[i].stok;
                totalHarga += daftarTas[i].harga; 
            }

            double rataRata = (jumlahTas > 0) ? (totalHarga / jumlahTas) : 0;

            TextTable ringkasan('-', '|', '+');
            
            ringkasan.add({"Rincian", "Nilai"});
            ringkasan.add({"Total Jenis Tas", to_string(jumlahTas) + " Jenis"});
            ringkasan.add({"Total Stok", to_string(totalStok) + " Produk"});
            ringkasan.add({"Rata-rata Harga", "Rp " + to_string((int)rataRata)});
            
            cout << ringkasan;
            
            cout << "Tekan Enter untuk lanjut...";
            cin.ignore(1000, '\n'); 
            cin.get();
        }
        else if (pilihanMenu == 6) {
            cout << "\nPROGRAM SELESAI! TERIMAKASIH SUDAH MENGGUNAKAN PROGRAM" << endl;
            break;
        } 
        else {
            cout << "Pilihan tidak tersedia! Pilih angka 1-6" << endl;
        }
    }

    return 0;
}