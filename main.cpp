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
            cout << ">> Nama: "; 
            getline(cin >> ws, x.nama);
            bool isValid = false;
            while(!isValid){
                cout << ">> Tahun terbit: ";
                cin >> x.terbit;
                if(cin.fail()){
                    cout << "Input tidak valid" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }else{
                    isValid = true;
                }
            }
            cout << ">> Genre: ";
            getline(cin >> ws, x.genre);
            adr_film p;
            p = createElemenFilm(x);
            insertFirstFilm(LF, p);
            cout << "Tambah Film Berhasil!" << endl;
        }else if(pilih == 2){
            cout << "=== Tambah Pemeran ===" << endl;
            infotype_pemeran x;
            cout << ">> Nama: ";
            getline(cin >> ws, x.nama);
            bool isValid = false;
            while(!isValid){
                cout << ">> Usia: ";
                cin >> x.usia;
                if(cin.fail()){
                    cout << "Input tidak valid" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }else{
                    isValid = true;
                }
            }
            bool isGender = false;
            while(!isGender){
                cout << ">> Gender(L/P): ";
                cin >> x.gender;
                if(x.gender == 'L' || x.gender == 'P'){
                    isGender = true;
                }
            }
            adr_pemeran p;
            p = createElemenPemeran(x);
            insertLastPemeran(LP, p);
            cout << "Tambah Pemeran Berhasil!" << endl;
        }else if(pilih == 3){
            deleteFilm(LF, LP);
        }else if(pilih == 4){
            deletePemeran(LP);
        }else if(pilih == 5){
            mainFilm(LP, LF);
        }else if(pilih == 6){
            showFilmWithActors(LP, LF);
        }else if(pilih == 7){
            showFilmWithSpecificActor(LP);
        }else if (pilih == 8){
            showActorsFromFilm(LP,LF);
        }else if (pilih == 9){
            showTopActorOrActress(LP,LF);
        }else{
            cout << "Terima kasih!" << endl;
            stop = true;
        }
        cout << endl;
    }

    return 0;
}
