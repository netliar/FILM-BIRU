#include "Film.h"

int main(){
    listFilm LF;
    listPemeran LP;
    createListFilm(LF);
    createListPemeran(LP);
    bool stop = false;
    while(!stop){
        int pilih = menu();
        if(pilih == 1){
            cout << "=== Tambah Film ===" << endl;
            infotype_film x;
            cout << "Nama: ";
            cin >> x.nama;
            cout << "Tahun terbit: ";
            cin >> x.terbit;
            cout << "Genre: ";
            cin >> x.genre;
            adr_film p;
            p = createElemenFilm(x);
            insertLastFilm(LF, p);
        }else if(pilih == 2){
            cout << "=== Tambah Pemeran ===" << endl;
            infotype_pemeran x;
            cout << "Nama: ";
            cin >> x.nama;
            cout << "Gender: ";
            cin >> x.gender;
            adr_pemeran p;
            p = createElemenPemeran(x);
            insertLastPemeran(LP, p);
        }else if(pilih == 3){
            mainFilm(LP, LF);
        }else if(pilih == 4){
            cout << "Terima kasih!" << endl;
            stop = true;
        }
    }
    printShowAllPemeran(LP);
    printShowAllFilm(LF);

    return 0;
}
