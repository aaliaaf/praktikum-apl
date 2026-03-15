#include <iostream>
#include <string>
#include <vector>
#include "../../table/text_table.h" 
using namespace std;

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
struct User {
    string username;
    string password;
};

void bersihkanLayar() {
    system("cls"); 
}

void tekanEnter() {
    cout << "\nTekan Enter untuk melanjutkan...";
    cin.ignore(1000, '\n'); 
    cin.get();
}

void menuUtamaProgram() {
    cout << "\n+======================================+" << endl;
    cout << "|          DAFTAR MENU UTAMA           |" << endl;
    cout << "+======================================+" << endl;
    cout << "|  1. Tambah Tas (Create)              |" << endl;
    cout << "|  2. Lihat Tas (Read)                 |" << endl;
    cout << "|  3. Update Stok (Update)             |" << endl;
    cout << "|  4. Hapus Tas (Delete)               |" << endl;
    cout << "|  5. Rincian Toko                     |" << endl;
    cout << "|  6. Keluar                           |" << endl;
    cout << "+======================================+" << endl;
}

void lihatDaftarTas(TasSekolah daftarTas[], int jumlah) {
    TextTable tabel('-', '|', '+');
    vector<string> header = {"ID", "Nama Tas", "Harga", "Stok", "Model", "Bahan"};
    tabel.add(header);

    for (int i = 0; i < jumlah; i++) {
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

double hitungTotal(TasSekolah daftarTas[], int jumlah, string jenis) {
    double total = 0;
    for (int i = 0; i < jumlah; i++) {
        if (jenis == "harga") {
            total += daftarTas[i].harga;
        } else if (jenis == "stok") {
            total += daftarTas[i].stok;
        }
    }
    return total;
}
double hitungTotal(TasSekolah daftarTas[], int jumlah, char jenis) {
    double total = 0;
    for (int i = 0; i < jumlah; i++) {
        if (jenis == 'h') {
            total += daftarTas[i].harga;
        } else if (jenis == 's') {
            total += daftarTas[i].stok;
        }
    }
    return total;
}
int mencariIdTas(TasSekolah daftarTas[], int jumlah, int id) {
    for (int i = 0; i < jumlah; i++) {
        if (daftarTas[i].id == id) {
            return i; 
        }
    }
    return -1; 
}

void menuRegister(User daftarUser[], int& jumlahUser) {
    cout << "\n--- DAFTAR AKUN BARU ---" << endl;

    string newUser, newPass;
    cout << "Masukkan Username baru : ";
    cin >> newUser;

    cout << "Masukkan Password baru : ";
    cin >> newPass;

    daftarUser[jumlahUser].username = newUser;
    daftarUser[jumlahUser].password = newPass;
    jumlahUser++;

    cout << "Pendaftaran berhasil! Silakan login." << endl;
    tekanEnter();
}

bool loginRekursif(User daftarUser[], int jumlahUser, int kesempatan) {
    if (kesempatan == 0) {
        return false; 
    }

    cout << "\n--- LOGIN (Sisa Kesempatan: " << kesempatan << ") ---" << endl;
    string usernameInput, passwordInput;
    cout << "Username : "; 
    cin >> usernameInput;
    cout << "Password : "; 
    cin >> passwordInput;

    bool loginBerhasil = false;
    for (int i = 0; i < jumlahUser; i++) {
        if (daftarUser[i].username == usernameInput && daftarUser[i].password == passwordInput) {
            loginBerhasil = true;
            break;
        }
    }

    if (loginBerhasil) {
        cout << "\nLogin berhasil! Selamat datang di program." << endl;
        tekanEnter();
        return true;
    } else {
        cout << "Login gagal! Username atau password salah." << endl;
        return loginRekursif(daftarUser, jumlahUser, kesempatan - 1);
    }
}

void menuTambahTas(TasSekolah daftarTas[], int& jumlahTas, int& idTas) {
    cout << "\n--- TAMBAH TAS BARU ---" << endl;

    TasSekolah tas;
    tas.id = idTas;
    idTas++;

    cout << "Nama Tas : ";
    cin.ignore(); 
    getline(cin, tas.nama);

    cout << "Model : ";
    getline(cin, tas.detail.model);

    cout << "Harga : ";
    cin >> tas.harga;

    cout << "Stok : ";
    cin >> tas.stok;

    cout << "Bahan : ";
    cin.ignore();
    getline(cin, tas.detail.bahan);

    daftarTas[jumlahTas] = tas;
    jumlahTas++;
    cout << "Tas berhasil ditambahkan!";
    
    tekanEnter();
}

void menuUpdateTas(TasSekolah daftarTas[], int jumlahTas) {
    cout << "\n--- UPDATE STOK ---" << endl;
    lihatDaftarTas(daftarTas, jumlahTas);

    int idCari;
    cout << "Masukkan ID tas yang mau diupdate: ";
    cin >> idCari;

    int idx = mencariIdTas(daftarTas, jumlahTas, idCari);

    if (idx != -1) {
        cout << "Ditemukan: " << daftarTas[idx].nama << endl;
        cout << "Stok lama: " << daftarTas[idx].stok << endl;
        cout << "Stok baru: ";
        cin >> daftarTas[idx].stok;
        cout << "Stok berhasil diubah!" << endl;
    } else {
        cout << "ID tidak ditemukan!" << endl;
    }
    tekanEnter();
}

void menuHapusTas(TasSekolah daftarTas[], int& jumlahTas) {
    cout << "\n--- HAPUS TAS ---" << endl;
    lihatDaftarTas(daftarTas, jumlahTas);

    int idCari;
    cout << "Masukkan ID tas yang mau dihapus: ";
    cin >> idCari;

    int idx = mencariIdTas(daftarTas, jumlahTas, idCari);

    if (idx != -1) {
        cout << "Data: " << daftarTas[idx].nama << endl;
    
        for (int j = idx; j < jumlahTas - 1; j++) {
            daftarTas[j] = daftarTas[j+1];
        }
        jumlahTas--;
        cout << "Data berhasil dihapus!" << endl;
        
    } else {
        cout << "ID tidak ditemukan!" << endl;
    }
    tekanEnter();
}

void menuRincian(TasSekolah daftarTas[], int jumlahTas) {
    cout << "\n--- RINCIAN TOKO ---" << endl;
    
    if (jumlahTas == 0) {
        cout << "Belum ada data untuk dihitung." << endl;
        tekanEnter();
        return;
    }

    double totalHarta = hitungTotal(daftarTas, jumlahTas, "harga"); 
    double totalBarang = hitungTotal(daftarTas, jumlahTas, 's');   
    double rataRata = totalHarta / jumlahTas;

    TextTable ringkasan('-', '|', '+');
    ringkasan.add({"Keterangan", "Nilai"});
    ringkasan.add({"Total Jenis Tas", to_string(jumlahTas) + " Jenis"});
    ringkasan.add({"Total Stok", to_string((int)totalBarang) + " Produk"});
    ringkasan.add({"Rata-rata Harga", "Rp " + to_string((int)rataRata)});
    
    cout << ringkasan;
    tekanEnter();
}

int main() {
    User daftarUser[100];
    int jumlahUser = 0;
    
    TasSekolah daftarTas[150];
    int jumlahTas = 0;
    int idTas = 1;

    daftarUser[0].username = "alia";
    daftarUser[0].password = "015";
    jumlahUser = 1;

    daftarTas[0].id = idTas++;
    daftarTas[0].nama = "Tas Ransel Backpack Standar";
    daftarTas[0].harga = 150000;
    daftarTas[0].stok = 25;
    daftarTas[0].detail.model = "Ransel";
    daftarTas[0].detail.bahan = "Nylon";
    jumlahTas++;

    daftarTas[1].id = idTas++;
    daftarTas[1].nama = "Tas Sekolah Karakter 3D";
    daftarTas[1].harga = 160000;
    daftarTas[1].stok = 20;
    daftarTas[1].detail.model = "Ransel";
    daftarTas[1].detail.bahan = "Polyester";
    jumlahTas++;

    daftarTas[2].id = idTas++;
    daftarTas[2].nama = "Tas Korean Style";
    daftarTas[2].harga = 85000;
    daftarTas[2].stok = 40;
    daftarTas[2].detail.model = "Selempang";
    daftarTas[2].detail.bahan = "Kanvas";
    jumlahTas++;

    daftarTas[3].id = idTas++;
    daftarTas[3].nama = "Tas Sekolah Beroda";
    daftarTas[3].harga = 200000;
    daftarTas[3].stok = 15;
    daftarTas[3].detail.model = "Koper Roda";
    daftarTas[3].detail.bahan = "Nylon";
    jumlahTas++;

    daftarTas[4].id = idTas++;
    daftarTas[4].nama = "Tas Laptop";
    daftarTas[4].harga = 124000;
    daftarTas[4].stok = 18;
    daftarTas[4].detail.model = "Laptop";
    daftarTas[4].detail.bahan = "Kulit Sintetis";
    jumlahTas++;

    cout << "\n=== SELAMAT DATANG DI MANAJEMEN TOKO TAS SEKOLAH ===\n";

    bool suksesLogin = false;
    
    while (!suksesLogin) {
        bersihkanLayar();
        cout << "\n+============================+" << endl;
        cout << "|       MENU AKUN USER       |" << endl;
        cout << "+============================+" << endl;
        cout << "|  1. Login                  |" << endl;
        cout << "|  2. Register               |" << endl;
        cout << "|  3. Keluar                 |" << endl;
        cout << "+============================+" << endl;
        cout << "Pilihan : ";
        
        int pilihanAwal;
        if (!(cin >> pilihanAwal)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Harap masukkan angka!" << endl;
            tekanEnter();
            continue;
        }

        if (pilihanAwal == 1) {
            suksesLogin = loginRekursif(daftarUser, jumlahUser, 3);
            if (!suksesLogin) {
                cout << "KESEMPATAN LOGIN HABIS. PROGRAM SELESAI." << endl;
                return 0;
            }
        } else if (pilihanAwal == 2) {
            menuRegister(daftarUser, jumlahUser);
        } else if (pilihanAwal == 3) {
            cout << "Terima kasih sudah menggunakan program ini!" << endl;
            return 0;
        } else {
            cout << "Pilihan tidak tersedia! Pilih angka 1-3!" << endl;
            tekanEnter();
        }
    }

    int pilihan;
    while (true) {
        bersihkanLayar();
        menuUtamaProgram();
        cout << "Pilihan : ";
        
        if (!(cin >> pilihan)) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Harap masukkan angka!" << endl;
            tekanEnter();
            continue;
        }

        if (pilihan == 1) {
            menuTambahTas(daftarTas, jumlahTas, idTas);
        } else if (pilihan == 2) {
            lihatDaftarTas(daftarTas, jumlahTas);
        } else if (pilihan == 3) {
            menuUpdateTas(daftarTas, jumlahTas);
        } else if (pilihan == 4) {
            menuHapusTas(daftarTas, jumlahTas);
        } else if (pilihan == 5) {
            menuRincian(daftarTas, jumlahTas);
        } else if (pilihan == 6) {
            bersihkanLayar();
            cout << "\nTerima kasih sudah menggunakan program ini!" << endl;
            break;
        } else {
            cout << "Pilihan tidak tersedia. Pilih angka 1-6!" << endl;
            tekanEnter();
        }
    }

    return 0;
}