#include "Film.h"

void createListPemeran(listPemeran &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_pemeran createElemenPemeran(infotype_pemeran p){
    adr_pemeran n = new elemenPemeran;
    info(n).nama = p.nama;
    info(n).gender = p.gender;
    info(n).nFilm = 0;
    next(n) = NULL;
    prev(n) = NULL;
    createListRelasi(child(n));
    return n;
}

void insertFirstPemeran(listPemeran &L, adr_pemeran p){
     if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
    }else {
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    }
}

void insertLastPemeran(listPemeran &L, adr_pemeran p){
    if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
    }else {
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}

void deletePemeran(listPemeran &LP){

}
void printShowAllPemeran(listPemeran L){
    int i = 1;
    adr_pemeran p = first(L);
    cout << "==== List Pemeran ====" << endl;
    while(p != NULL){
        cout << i << ". " << info(p).nama << " - " << info(p).gender << endl;
        i++;
        p = next(p);
    }
}

int sizePemeran(listPemeran L){
    int i = 0;
    adr_pemeran p = first(L);
    while(p != NULL){
        i++;
        p = next(p);
    }
    return i;
}

adr_pemeran searchPemeran(listPemeran LP){
    int NP = sizePemeran(LP);
    int pilihPemeran = 0;
    if(NP == 0){
        cout << "Pemeran Kosong" << endl;
        return NULL;
    }else{
        adr_pemeran arrPemeran[NP];
        adr_pemeran p = first(LP);
        int i = 0;
        bool stop = false;
        cout << "==== List Pemeran ====" << endl;
        while(p != NULL){
            arrPemeran[i] = p;
            i++;
            cout << i << ". " << info(p).nama << " - " << info(p).gender << endl;
            p = next(p);
        }

        while(!stop){
            cout << "Pilih Pemeran: ";
            cin >> pilihPemeran;
            if(pilihPemeran <= 0 || pilihPemeran > NP){
                cout << "Pilihan tidak ada" << endl;
            }else{
                p = arrPemeran[pilihPemeran-1];
                stop = true;
            }
        }
        return p;
    }
    
}

void showFilmWithSpecificActor(listPemeran LP){
    adr_pemeran ap = searchPemeran(LP);
    adr_relasi ar = first(child(ap));
    cout << "Pemeran: " << info(ap).nama << endl;
    while(ar != NULL){
        cout << "- " << info(next_film(ar)).nama << endl;
        ar = next(ar);
    }
}