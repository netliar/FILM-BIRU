#include "Film.h"

void createListFilm(listFilm &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_film createElemenFilm(infotype_film p){
    adr_film n = new elemenFilm;
    info(n).nama = p.nama;
    info(n).terbit = p.terbit;
    info(n).genre = p.genre;
    next(n) = NULL;
    prev(n) = NULL;
    return n;
}
void insertFirstFilm(listFilm &L, adr_film p){
    if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
    }else {
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    }
}

void insertLastFilm(listFilm &L, adr_film p){
    if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
    }else {
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}

bool isExist(listRelasi q, adr_relasi r){
    adr_relasi z = first(q);
    bool ada = false;
    while(z != NULL && !ada){
        if(next_film(z) == next_film(r)){
            ada = true;
        }else{
            z = next(z);
        }
    }
    
    return ada;
}

void deleteFirstFilm(listFilm &LF, adr_film &af){
    if(first(LF) == NULL){
        af = NULL;
        cout << "LIST FILM KOSONG" << endl;
    }else if(next(first(LF)) == NULL){
        af = first(LF);
        first(LF) = NULL;
        last(LF) = NULL;
    }else{
        af = first(LF);
        first(LF) = next(af);
        prev(first(LF)) = NULL;
        next(af) = NULL;
    }
}

void deleteLastFilm(listFilm &LF, adr_film &af){
    if(first(LF) == NULL){
        af = NULL;
        cout << "TIDAK MAIN FILM" << endl;
    }else if(next(first(LF))== NULL){
        af = last(LF);
        first(LF) = NULL;
        last(LF) = NULL;
    }else{
        af = last(LF);
        last(LF) = prev(af); 
        prev(af) = NULL;
        next(last(LF)) = NULL;
    }
}

void printShowAllFilm(listFilm L){
    int i = 1;
    adr_film p = first(L);
    cout << "==== List Film ====" << endl;
    while(p != NULL){
        cout << i << ". " << info(p).nama << " - " << info(p).terbit << " - " << info(p).genre << endl;
        i++;
        p = next(p);
    }
}

int menu(){
    int pilih;
    cout << "||   ==== MENU ====   " << endl;
    cout << "||1. Tambah Film" << endl;
    cout << "||2. Tambah Pemeran" << endl;
    cout << "||3. Main Film" << endl;
    cout << "||4. Tunjukkan daftar lengkap film beserta pemeran-pemerannya" << endl;
    cout << "||5. Tunjukkan film dengan partisipasi aktor/aktris tertentu" << endl;
    cout << "||6. Tunjukkan informasi pemeran dalam suatu film." << endl;
    cout << "||7. Tunjukkan informasi teratas untuk satu aktor dan satu aktris" << endl;
    cout << "Pilih: ";
    cin >> pilih;
    return pilih;
}

int sizeFilm(listFilm L){
    int i = 0;
    adr_film p = first(L);
    while(p != NULL){
        i++;
        p = next(p);
    }
    return i;
}

void mainFilm(listPemeran &LP, listFilm &LF){
    if(first(LP) == NULL || first(LF) == NULL){
        cout << "Silahkan isi Pemeran atau Film terlebih dahulu!" << endl;
    }else{
        adr_film f = searchFilm(LF);
        adr_pemeran p = searchPemeran(LP);
        insertLastRelasi(child(p), f);
    }
}

adr_film searchFilm(listFilm LF){
    int NF = sizeFilm(LF);
    int pilihFilm = 0;
    if(NF == 0){
        cout << "Film Kosong" << endl;
        return NULL;
    }else{
        adr_film arrFilm[NF];
        adr_film f = first(LF);
        int i = 0;
        bool stop = false;
        cout << "==== List Film ====" << endl;
        cout << "{nama film} - {tahun terbit} - {genre}" << endl;
        while(f != NULL){
            arrFilm[i] = f;
            i++;
            cout << i << ". " << info(f).nama << " - " << info(f).terbit << " - " << info(f).genre << endl;
            f = next(f);
        }
        while(!stop){
            cout << "Pilih Film: ";
            cin >> pilihFilm;
            if(pilihFilm <= 0 || pilihFilm > NF){
                cout << "Pilihan tidak ada" << endl;
            }else{
                f = arrFilm[pilihFilm-1];
                stop = true;
            }
        }
        return f;
    }
}


void deleteFilm(listFilm &LF, listPemeran &LP, adr_film af){
    if(af == first(LF)){
        deleteFirstFilm(LF, af);
    }else if(af == last(LF)){
        deleteLastFilm(LF, af);
    }else{
        adr_film prec = prev(af);
        next(prec) = next(af);
        prev(next(af)) = prec;
        prev(af) = NULL;
        next(af) = NULL;
    }
    deleteRelasiPemeran(LP);
}

void showFilmWithActors(listPemeran LP, listFilm LF){
    adr_film af = first(LF);
    while(af != NULL){
        cout << "- " << info(af).nama << endl;
        adr_pemeran ap = first(LP);
        int i = 1;
        while(ap != NULL){
            adr_relasi ar = searchFilmRelasi(child(ap), af);
            if(ar != NULL){
                cout << i << ". " <<  info(ap).nama << endl;
            }
            i++;
            ap = next(ap);
        }
        af = next(af);
    }

}