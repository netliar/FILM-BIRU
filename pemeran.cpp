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

void deleteFirstPemeran(listPemeran &LP, adr_pemeran &ap){
    if(first(LP) == NULL){
        ap = NULL;
        cout << "TIDAK ADA PEMERAN" << endl;
    }else if(next(first(LP))== NULL){
        first(LP) = NULL;
        last(LP) = NULL;
    }else{
        ap = first(LP);
        first(LP) = next(ap); 
        next(ap) = NULL;
        prev(ap) = NULL;
        prev(first(LP)) = NULL;
    }
}

void deleteLastPemeran(listPemeran &LP, adr_pemeran &ap){
    if(first(LP) == NULL){
        ap = NULL;
        cout << "TIDAK MAIN FILM" << endl;
    }else if(next(first(LP))== NULL){
        first(LP) = NULL;
        last(LP) = NULL;
    }else{
        ap = last(LP);
        last(LP) = prev(ap); 
        prev(ap) = NULL;
        next(last(LP)) = NULL;
    }
}

void deletePemeran(listPemeran &LP){
    adr_pemeran ap = searchPemeran(LP);
    if(ap != NULL){
        if(ap == first(LP)){
            deleteFirstPemeran(LP, ap);
        }else if(ap == last(LP)){
            deleteLastPemeran(LP, ap);
        }else{
            adr_pemeran prec = prev(ap);
            next(prec) = next(ap);
            prev(next(ap)) = prec;
            prev(ap) = NULL;
            next(ap) = NULL;
        }
        adr_relasi ar;
        deleteAllRelasiPemeran(child(ap), ar);
        cout << "Hapus Pemeran Berhasil!" << endl;
    }
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
    if(NP == 0){
        cout << "Pemeran Kosong" << endl;
        return NULL;
    }else{
        adr_pemeran arrPemeran[NP];
        adr_pemeran p = first(LP);
        int i = 0;
        cout << "==== List Pemeran ====" << endl;
        while(p != NULL){
            arrPemeran[i] = p;
            i++;
            cout << i << ". " << info(p).nama << " (" << info(p).gender << ")" << endl;
            p = next(p);
        }

        bool stop = false;
        int pilihPemeran = 0;
        while(!stop){
            cout << ">> Pilih Pemeran: ";
            cin >> pilihPemeran;
            if(pilihPemeran <= 0 || pilihPemeran > NP || cin.fail()){
                cout << "Pilihan tidak ada" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
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
    if(ap != NULL){
        adr_relasi ar = first(child(ap));
        cout << "Pemeran: " << info(ap).nama << endl;
        cout << "Daftar Film: " << endl;
        int i = 1;
        while(ar != NULL){
            cout << i << ". "<< info(next_film(ar)).nama << " (" << info(next_film(ar)).terbit << ", " << info(next_film(ar)).genre << ")" << endl;
            ar = next(ar);
        }
    }
}

void showTopActorOrActress(listPemeran LP, listFilm LF){
    adr_pemeran ap = first(LP);
    adr_pemeran lTop = NULL;
    adr_pemeran pTop = NULL;
    int lnTop = 0;
    int pnTop = 0;
    while(ap != NULL){
        if (info(ap).nFilm > lnTop && info(ap).gender == 'L'){
            lnTop = info(ap).nFilm;
            lTop = ap;
        }
        if (info(ap).nFilm > pnTop && info(ap).gender == 'P'){
            pnTop = info(ap).nFilm;
            pTop = ap;
        }
        ap = next(ap);
    }

    cout << "=== Top Aktor dan Aktris ==="  << endl;
    if(lTop == NULL){
        cout << "Tidak Ada Aktor" << endl;
    }else{
        cout << "Aktor: " << info(lTop).nama << endl;
    }
    if(pTop == NULL){
        cout << "Tidak Ada Aktris" << endl;
    }else{
        cout << "Aktris: " << info(pTop).nama << endl;
    }
}