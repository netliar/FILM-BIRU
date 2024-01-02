#include "Film.h"

int menu(){
    int pilih;
    cout << "||======================================================||" << endl;
    cout << "||                    SELAMAT DATANG                    ||" << endl;
    cout << "||======================================================||" << endl;
    cout << "||1. Tambah Film                                        ||" << endl;
    cout << "||2. Tambah Pemeran                                     ||" << endl;
    cout << "||3. Hapus Film                                         ||" << endl;
    cout << "||4. Hapus Pemeran                                      ||" << endl;
    cout << "||5. Main Film                                          ||" << endl;
    cout << "||6. Daftar lengkap film beserta pemeran-pemerannya     ||" << endl;
    cout << "||7. Film Dengan Partisipasi Aktor/aktris Tertentu      ||" << endl;
    cout << "||8. Informasi Pemeran Dalam Suatu Film                 ||" << endl;
    cout << "||9. Informasi Teratas Untuk Satu Aktor Dan Satu Aktris ||" << endl;
    cout << "||0. Keluar                                             ||" << endl;
    cout << "||======================================================||" << endl;
    cout << ">> Masukkan pilihan: ";
    cin >> pilih;
    return pilih;
}