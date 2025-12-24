#include "gudang.h"

int main() {
    address gudang = nullptr;
    int pilihan, stok;
    infotype induk, baru;

    isiDataDummy(gudang); // Langsung isi 2 zona awal

    do {
        cout << "\n==========================================" << endl;
        cout << "   SISTEM MANAJEMEN GUDANG (ZONA-RAK)      " << endl;
        cout << "==========================================" << endl;
        cout << " 1. Tambah Data Baru                     " << endl;
        cout << " 2. Tampilkan Denah (Pre-Order)          " << endl;
        cout << " 3. Tampilkan Urutan In-Order            " << endl;
        cout << " 4. Tampilkan Urutan Post-Order          " << endl;
        cout << " 5. Cari Lokasi Barang                   " << endl;
        cout << " 0. Keluar                               " << endl;
        cout << "------------------------------------------" << endl;
        cout << " Pilih Menu: "; cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan Nama Induk: "; getline(cin, induk);
                cout << "Masukkan Nama Baru: "; getline(cin, baru);
                cout << "Masukkan Stok (0 jika bukan barang): "; cin >> stok;
                insertNode(gudang, induk, baru, stok);
                cout << ">>> Berhasil ditambahkan!\n";
                break;
            case 2:
                cout << "\n--- DENAH GUDANG (PRE-ORDER) ---\n";
                printPreOrder(gudang, 0);
                break;
            case 3:
                cout << "\n--- URUTAN IN-ORDER ---\n";
                printInOrder(gudang);
                cout << endl;
                break;
            case 4:
                cout << "\n--- URUTAN POST-ORDER ---\n";
                printPostOrder(gudang);
                cout << endl;
                break;
            case 5:
                cout << "\nMasukkan Nama yang dicari: "; getline(cin, baru);
                if (findNode(gudang, baru)) cout << ">>> Ditemukan!\n";
                else cout << ">>> Tidak ditemukan.\n";
                break;
        }
    } while (pilihan != 0);

    return 0;
}
