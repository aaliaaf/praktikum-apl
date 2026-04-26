#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
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
void inputAngka(double nilai, const string& pesanError) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw invalid_argument(pesanError + " harus berupa angka!");
    }
    if (nilai < 0) {
        throw invalid_argument(pesanError + " tidak boleh negatif!");
    }
}

void bubbleSortNama(TasSekolah *daftarTas, int jumlah) {
    try {
        if (jumlah <= 0) {
            throw runtime_error("Tidak ada data untuk diurutkan!");
        }
        for (int i = 0; i < jumlah - 1; i++) {
            for (int j = 0; j < jumlah - i - 1; j++) {
                if (daftarTas[j].nama > daftarTas[j + 1].nama) {
                    TasSekolah temp = daftarTas[j];
                    daftarTas[j] = daftarTas[j + 1];
                    daftarTas[j + 1] = temp;
                }
            }
        }
    } catch (const exception& e) {
        cout << "Error sorting: " << e.what() << endl;
        throw;
    }
}

void selectionSortDescending(TasSekolah *daftarTas, int jumlah) {
    try {
        if (jumlah <= 0) {
            throw runtime_error("Tidak ada data untuk diurutkan!");
        }
        for (int i = 0; i < jumlah - 1; i++) {
            int idMaxx = i;
            for (int j = i + 1; j < jumlah; j++) {
                if (daftarTas[j].harga > daftarTas[idMaxx].harga) {
                    idMaxx = j;
                }
            }
            if (idMaxx != i) {
                TasSekolah temp = daftarTas[i];
                daftarTas[i] = daftarTas[idMaxx];
                daftarTas[idMaxx] = temp;
            }
        }
    } catch (const exception& e) {
        cout << "Error sorting: " << e.what() << endl;
        throw;
    }
}

void insertionSortAscending(TasSekolah *daftarTas, int jumlah) {
    try {
        if (jumlah <= 0) {
            throw runtime_error("Tidak ada data untuk diurutkan!");
        }
        for (int i = 1; i < jumlah; i++) {
            TasSekolah key = daftarTas[i];
            int j = i - 1;
            while (j >= 0 && daftarTas[j].stok > key.stok) {
                daftarTas[j + 1] = daftarTas[j];
                j = j - 1;
            }
            daftarTas[j + 1] = key;
        }
    } catch (const exception& e) {
        cout << "Error sorting: " << e.what() << endl;
        throw;
    }
}

int binarySearchIdTas(const TasSekolah *daftarTas, int jumlah, int targetId) {
    try {
        if (jumlah <= 0) {
            throw runtime_error("Tidak ada data untuk dicari!");
        }
        if (daftarTas == nullptr) {
            throw runtime_error("Pointer daftar tas kosong!");
        }
        
        int low = 0;
        int high = jumlah - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2; 
            
            if (daftarTas[mid].id == targetId) {
                return mid;
            } else if (daftarTas[mid].id < targetId) {
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        return -1; 
    } catch (const exception& e) {
        cout << "Error binary search: " << e.what() << endl;
        throw;
    }
}

int linearSearchNamaTas(const TasSekolah *daftarTas, int jumlah, const string &targetNama) {
    try {
        if (jumlah <= 0) {
            throw runtime_error("Tidak ada data untuk dicari!");
        }
        if (daftarTas == nullptr) {
            throw runtime_error("Pointer daftar tas kosong!");
        }
        if (targetNama.empty()) {
            throw invalid_argument("Nama tas tidak boleh kosong!");
        }
        
        for (int i = 0; i < jumlah; i++) {
            if (daftarTas[i].nama == targetNama) {
                return i;
            }
        }
        return -1;
    } catch (const exception& e) {
        cout << "Error linear search: " << e.what() << endl;
        throw;
    }
}

void menuUtamaProgram() {
    cout << "\n+==========================================+" << endl;
    cout << "|          DAFTAR MENU UTAMA               |" << endl;
    cout << "+==========================================+" << endl;
    cout << "|  1. Tambah Tas (Create)                  |" << endl;
    cout << "|  2. Lihat Tas (Read)                     |" << endl;
    cout << "|  3. Update Stok (Update)                 |" << endl;
    cout << "|  4. Hapus Tas (Delete)                   |" << endl;
    cout << "|  5. Rincian Toko                         |" << endl;
    cout << "|  6. Urutkan Nama (Bubble - Asc)          |" << endl; 
    cout << "|  7. Urutkan Harga (Selection - Desc)     |" << endl; 
    cout << "|  8. Urutkan Stok (Insertion - Asc)       |" << endl; 
    cout << "|  9. Keluar                               |" << endl;
    cout << "| 10. Cari berdasarkan ID (Binary Search)  |" << endl;
    cout << "| 11. Cari berdasarkan Nama (Linear Search)|" << endl;
    cout << "+==========================================+" << endl;
}

void lihatDaftarTas(TasSekolah *daftarTas, int jumlah) {
    try {
        if (jumlah <= 0) {
            throw runtime_error("Belum ada data tas yang tersedia!");
        }
        if (daftarTas == nullptr) {
            throw runtime_error("Pointer daftar tas kosong!");
        }
        
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
        tekanEnter();
    } catch (const exception& e) {
        cout << "\nERROR " << e.what() << endl;
        tekanEnter();
    }
}

double hitungTotal(double *total, TasSekolah *daftarTas, int jumlah, char jenis) {
    try {
        if (total == nullptr) {
            throw runtime_error("Pointer total kosong!");
        }
        if (daftarTas == nullptr) {
            throw runtime_error("Pointer daftar tas kosong!");
        }
        if (jumlah <= 0) {
            throw runtime_error("Jumlah tas tidak valid!");
        }
        
        *total = 0;
        for (int i = 0; i < jumlah; i++) {
            if (jenis == 'h') *total += daftarTas[i].harga;
            else if (jenis == 's') *total += daftarTas[i].stok;
        }
        return *total;
    } catch (const exception& e) {
        cout << "ERROR hitungTotal " << e.what() << endl;
        throw;
    }
}

int mencariIdTas(TasSekolah *daftarTas, int jumlah, int id) {
    return binarySearchIdTas(daftarTas, jumlah, id);
}

void menuRegister(User daftarUser[], int& jumlahUser) {
    try {
        if (jumlahUser >= 100) {
            throw overflow_error("Kapasitas user penuh! Maksimal 100 user.");
        }
        
        cout << "\n--- DAFTAR AKUN BARU ---" << endl;
        string newUser, newPass;
        
        cout << "Masukkan Username baru : "; 
        cin >> newUser;
        
        if (newUser.empty()) {
            throw invalid_argument("Username tidak boleh kosong!");
        }
        
        cout << "Masukkan Password baru : "; 
        cin >> newPass;
        
        if (newPass.empty()) {
            throw invalid_argument("Password tidak boleh kosong!");
        }
        
        if (newPass.length() < 3) {
            throw invalid_argument("Password minimal 3 karakter!");
        }

        daftarUser[jumlahUser].username = newUser;
        daftarUser[jumlahUser].password = newPass;
        jumlahUser++;
        cout << "Pendaftaran berhasil! Silakan login." << endl;
        tekanEnter();
    } catch (const exception& e) {
        cout << "\nERROR Register " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        tekanEnter();
    }
}

bool loginRekursif(User daftarUser[], int jumlahUser, int kesempatan) {
    try {
        if (kesempatan == 0) {
            throw runtime_error("KESEMPATAN LOGIN HABIS!");
        }

        cout << "\n--- LOGIN (Sisa Kesempatan: " << kesempatan << ") ---" << endl;
        string usernameInput, passwordInput;
        
        cout << "Username : "; 
        cin >> usernameInput;
        cout << "Password : "; 
        cin >> passwordInput;

        if (usernameInput.empty() || passwordInput.empty()) {
            throw invalid_argument("Username dan password tidak boleh kosong!");
        }

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
    } catch (const exception& e) {
        cout << "\nERROR Login " << e.what() << endl;
        return false;
    }
}

void menuTambahTas(TasSekolah *daftarTas, int& jumlahTas, int& idTas) {
    try {
        if (jumlahTas >= 150) {
            throw overflow_error("Kapasitas tas penuh! Maksimal 150 tas.");
        }
        if (daftarTas == nullptr) {
            throw runtime_error("Pointer daftar tas kosong!");
        }
        
        cout << "\n--- TAMBAH TAS BARU ---" << endl;
        TasSekolah tas;
        tas.id = idTas++;

        cout << "Nama Tas : "; 
        cin.ignore(); 
        getline(cin, tas.nama);
        
        if (tas.nama.empty()) {
            throw invalid_argument("Nama tas tidak boleh kosong!");
        }

        cout << "Model : "; 
        getline(cin, tas.detail.model);
        
        if (tas.detail.model.empty()) {
            throw invalid_argument("Model tas tidak boleh kosong!");
        }

        cout << "Harga : "; 
        cin >> tas.harga;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Harga harus berupa angka!");
        }
        
        if (tas.harga <= 0) {
            throw invalid_argument("Harga harus lebih dari 0!");
        }

        cout << "Stok : "; 
        cin >> tas.stok;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Stok harus berupa angka!");
        }
        
        if (tas.stok < 0) {
            throw invalid_argument("Stok tidak boleh negatif!");
        }

        cout << "Bahan : "; 
        cin.ignore(); 
        getline(cin, tas.detail.bahan);
        
        if (tas.detail.bahan.empty()) {
            throw invalid_argument("Bahan tas tidak boleh kosong!");
        }

        daftarTas[jumlahTas] = tas;
        jumlahTas++;
        cout << "Tas berhasil ditambahkan!" << endl;
        tekanEnter();
    } catch (const exception& e) {
        cout << "\nERROR Tambah Tas " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        tekanEnter();
    }
}

void menuUpdateStokPointer(TasSekolah *ptrTas, int stokBaru) {
    try {
        if (ptrTas == nullptr) {
            throw runtime_error("Pointer tas kosong!");
        }
        
        if (stokBaru < 0) {
            throw invalid_argument("Stok tidak boleh negatif!");
        }
        
        (*ptrTas).stok = stokBaru;
        cout << "Stok berhasil diubah menjadi " << (*ptrTas).stok << endl;
    } catch (const exception& e) {
        cout << "[ERROR Update Stok] " << e.what() << endl;
        throw;
    }
}

void menuUpdateTas(TasSekolah *daftarTas, int jumlahTas) {
    try {
        if (jumlahTas <= 0) {
            throw runtime_error("Belum ada data tas untuk diupdate!");
        }
        if (daftarTas == nullptr) {
            throw runtime_error("Pointer daftar tas kosong!");
        }
        
        cout << "\n--- UPDATE STOK ---" << endl;
        lihatDaftarTas(daftarTas, jumlahTas);

        int idCari, stokBaru;
        cout << "Masukkan ID tas yang mau diupdate: "; 
        cin >> idCari;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("ID harus berupa angka!");
        }
        
        if (idCari <= 0) {
            throw invalid_argument("ID harus lebih dari 0!");
        }

        int idx = binarySearchIdTas(daftarTas, jumlahTas, idCari);

        if (idx != -1) {
            cout << "Ditemukan: " << daftarTas[idx].nama << endl;
            cout << "Stok lama: " << daftarTas[idx].stok << endl;
            cout << "Stok baru: "; 
            cin >> stokBaru;
            
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                throw invalid_argument("Stok harus berupa angka!");
            }
            
            menuUpdateStokPointer(&daftarTas[idx], stokBaru);
        } else {
            throw out_of_range("ID tas tidak ditemukan!");
        }
        tekanEnter();
    } catch (const exception& e) {
        cout << "\nERROR Update Tas " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        tekanEnter();
    }
}

void menuHapusTas(TasSekolah *daftarTas, int& jumlahTas) {
    try {
        if (jumlahTas <= 0) {
            throw runtime_error("Belum ada data tas untuk dihapus!");
        }
        if (daftarTas == nullptr) {
            throw runtime_error("Pointer daftar tas kosong!");
        }
        
        cout << "\n--- HAPUS TAS ---" << endl;
        lihatDaftarTas(daftarTas, jumlahTas);

        int idCari;
        cout << "Masukkan ID tas yang mau dihapus: "; 
        cin >> idCari;
        
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("ID harus berupa angka!");
        }
        
        if (idCari <= 0) {
            throw invalid_argument("ID harus lebih dari 0!");
        }
        
        int idx = binarySearchIdTas(daftarTas, jumlahTas, idCari);

        if (idx != -1) {
            cout << "Data: " << daftarTas[idx].nama << " berhasil dihapus!" << endl;
            for (int j = idx; j < jumlahTas - 1; j++) {
                daftarTas[j] = daftarTas[j+1];
            }
            jumlahTas--;
        } else {
            throw out_of_range("ID tas tidak ditemukan!");
        }
        tekanEnter();
    } catch (const exception& e) {
        cout << "\nERROR Hapus Tas " << e.what() << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        tekanEnter();
    }
}

void menuRincianToko(TasSekolah *daftarTas, int jumlahTas) {
    try {
        if (daftarTas == nullptr) {
            throw runtime_error("Pointer daftar tas kosong!");
        }
        
        cout << "\n--- RINCIAN TOKO ---" << endl;
        if (jumlahTas == 0) { 
            throw runtime_error("Belum ada data untuk dihitung.");
        }

        double totalHarta = 0, totalBarang = 0;
        hitungTotal(&totalHarta, daftarTas, jumlahTas, 'h');
        hitungTotal(&totalBarang, daftarTas, jumlahTas, 's');
        
        if (jumlahTas == 0) {
            throw runtime_error("Pembagian dengan nol tidak diperbolehkan!");
        }
        
        double rataRata = totalHarta / jumlahTas;

        TextTable ringkasan('-', '|', '+');
        ringkasan.add({"Keterangan", "Nilai"});
        ringkasan.add({"Total Jenis Tas", to_string(jumlahTas) + " Jenis"});
        ringkasan.add({"Total Stok", to_string((int)totalBarang) + " Produk"});
        ringkasan.add({"Rata-rata Harga", "Rp " + to_string((int)rataRata)});
        cout << ringkasan;
        tekanEnter();
    } catch (const exception& e) {
        cout << "\n[ERROR Rincian Toko] " << e.what() << endl;
        tekanEnter();
    }
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

    string namaAwal[] = {"Tas Ransel Backpack Standar", "Tas Sekolah Karakter 3D", "Tas Korean Style", "Tas Sekolah Beroda", "Tas Laptop"};
    double hargaAwal[] = {150000, 160000, 85000, 200000, 124000};
    int stokAwal[] = {25, 20, 40, 15, 18};
    string modelAwal[] = {"Ransel", "Ransel", "Selempang", "Koper Roda", "Laptop"};
    string bahanAwal[] = {"Nylon", "Polyester", "Kanvas", "Nylon", "Kulit Sintetis"};

    for(int i=0; i<5; i++){
        daftarTas[jumlahTas].id = idTas++;
        daftarTas[jumlahTas].nama = namaAwal[i];
        daftarTas[jumlahTas].harga = hargaAwal[i];
        daftarTas[jumlahTas].stok = stokAwal[i];
        daftarTas[jumlahTas].detail.model = modelAwal[i];
        daftarTas[jumlahTas].detail.bahan = bahanAwal[i];
        jumlahTas++;
    }

    cout << "\n=== SELAMAT DATANG DI MANAJEMEN TOKO TAS SEKOLAH ===\n";
    bool suksesLogin = false;

    while (!suksesLogin) {
        try {
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
                throw invalid_argument("Harap masukkan angka!");
            }

            if (pilihanAwal == 1) {
                suksesLogin = loginRekursif(daftarUser, jumlahUser, 3);
                if (!suksesLogin) { 
                    cout << "KESEMPATAN LOGIN HABIS. PROGRAM SELESAI."; 
                    return 0; 
                }
            } else if (pilihanAwal == 2) {
                menuRegister(daftarUser, jumlahUser);
            } else if (pilihanAwal == 3) {
                cout << "Terima kasih sudah menggunakan program ini!" << endl; 
                return 0;
            } else {
                throw out_of_range("Pilihan tidak tersedia!");
            }
        } catch (const invalid_argument& e) {
            cout << "\nERROR " << e.what() << endl;
            tekanEnter();
        } catch (const out_of_range& e) {
            cout << "\nERROR " << e.what() << endl;
            tekanEnter();
        } catch (const exception& e) {
            cout << "\nERROR SISTEM " << e.what() << endl;
            tekanEnter();
        }
    }

    int pilihan;
    while (true) {
        try {
            bersihkanLayar();
            menuUtamaProgram();
            cout << "Pilihan : ";

            if (!(cin >> pilihan)) {
                cin.clear(); 
                cin.ignore(1000, '\n');
                throw invalid_argument("Harap masukkan angka!");
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
                menuRincianToko(daftarTas, jumlahTas);
            } else if (pilihan == 6) { 
                bubbleSortNama(daftarTas, jumlahTas); 
                lihatDaftarTas(daftarTas, jumlahTas); 
            } else if (pilihan == 7) { 
                selectionSortDescending(daftarTas, jumlahTas); 
                lihatDaftarTas(daftarTas, jumlahTas); 
            } else if (pilihan == 8) { 
                insertionSortAscending(daftarTas, jumlahTas); 
                lihatDaftarTas(daftarTas, jumlahTas); 
            } else if (pilihan == 10) {
                cout << "\n--- CARI BERDASARKAN ID (BINARY SEARCH) ---" << endl;
                int idCari;
                cout << "Masukkan ID Tas: "; 
                cin >> idCari;
                
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    throw invalid_argument("ID harus berupa angka!");
                }
                
                int idx = binarySearchIdTas(daftarTas, jumlahTas, idCari);
                if (idx != -1) {
                    TextTable t('-', '|', '+');
                    t.add({"ID", "Nama Tas", "Harga", "Stok", "Model", "Bahan"});
                    t.add({to_string(daftarTas[idx].id), daftarTas[idx].nama, 
                           "Rp " + to_string((int)daftarTas[idx].harga), to_string(daftarTas[idx].stok),
                           daftarTas[idx].detail.model, daftarTas[idx].detail.bahan});
                    cout << "Ditemukan!\n" << t;
                } else {
                    throw out_of_range("ID tidak ditemukan!");
                }
                tekanEnter();
            } else if (pilihan == 11) {
                cout << "\n--- CARI BERDASARKAN NAMA (LINEAR SEARCH) ---" << endl;
                string namaCari;
                cout << "Masukkan Nama Tas: "; 
                cin.ignore(); 
                getline(cin, namaCari);
                
                int idx = linearSearchNamaTas(daftarTas, jumlahTas, namaCari);
                if (idx != -1) {
                    TextTable t('-', '|', '+');
                    t.add({"ID", "Nama Tas", "Harga", "Stok", "Model", "Bahan"});
                    t.add({to_string(daftarTas[idx].id), daftarTas[idx].nama, 
                           "Rp " + to_string((int)daftarTas[idx].harga), to_string(daftarTas[idx].stok),
                           daftarTas[idx].detail.model, daftarTas[idx].detail.bahan});
                    cout << "Ditemukan!\n" << t;
                } else {
                    throw out_of_range("Nama tidak ditemukan!");
                }
                tekanEnter();
            } else if (pilihan == 9) { 
                bersihkanLayar(); 
                cout << "\nTerima kasih sudah menggunakan program ini!" << endl; 
                break; 
            } else {
                throw out_of_range("Pilihan tidak tersedia. Pilih angka 1-11!");
            }
        } catch (const invalid_argument& e) {
            cout << "\nERROR INPUT " << e.what() << endl;
            tekanEnter();
        } catch (const out_of_range& e) {
            cout << "\nERROR " << e.what() << endl;
            tekanEnter();
        } catch (const runtime_error& e) {
            cout << "\nERROR RUNTIME " << e.what() << endl;
            tekanEnter();
        } catch (const overflow_error& e) {
            cout << "\nERROR OVERFLOW " << e.what() << endl;
            tekanEnter();
        } catch (const exception& e) {
            cout << "\nERROR SISTEM " << e.what() << endl;
            tekanEnter();
        }
    }
    return 0;
}