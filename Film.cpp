#include "Film.h"

void createListFilm(listFilm &L){
    first(L) = NULL;
    last(L) = NULL;
}
void createListPemeran(listPemeran &L){
    first(L) = NULL;
    last(L) = NULL;
}
void createListRelasi(listRelasi &L){
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
adr_pemeran createElemenPemeran(infotype_pemeran p){
    adr_pemeran n = new elemenPemeran;
    info(n).nama = p.nama;
    info(n).gender = p.gender;
    next(n) = NULL;
    prev(n) = NULL;
    createListRelasi(child(n));
    return n;
}
adr_relasi createElemenRelasi(adr_film p){
    adr_relasi n = new elemenRelasi;
    next_film(n) = p;
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
void insertFirstRelasi(listRelasi &L, adr_relasi p){
     if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
    }else {
        next(p) = first(L);
        prev(first(L)) = p;
        first(L) = p;
    }
}
void insertLastRelasi(listRelasi &LR, adr_film f){
        adr_relasi r = NULL;
        r = createElemenRelasi(f);
        if(first(LR) == NULL){
            first(LR) = r;
            last(LR) = r;
        }else{
            bool ada = isExist(LR, r);
            if(ada){
                cout << "Pilih film yang lain!" << endl;
            }else{
                next(last(LR)) = r;
                prev(r) = last(LR);
                last(LR) = r;
            }
        }
}

adr_relasi searchFilmRelasi(listRelasi LR, adr_film pf){
    adr_relasi c = first(LR);
    while(c != NULL){
        if(next_film(c) == pf){
            return c;
        }
        c = next(c);
    }
    return c;
}

void deleteFirstRelasi(listRelasi &LR, adr_relasi &r){
    if(first(LR) == NULL){
        r = NULL;
        cout << "TIDAK MAIN FILM" << endl;
    }else if(next(first(LR))== NULL){
        first(LR) = NULL;
        last(LR) = NULL;
    }else{
        r = first(LR);
        first(LR) = next(r); 
        next(r) = NULL;
        prev(r) = NULL;
        prev(first(LR)) = NULL;
    }
}


void deleteLastRelasi(listRelasi &LR, adr_relasi &r){
    if(first(LR) == NULL){
        r = NULL;
        cout << "TIDAK MAIN FILM" << endl;
    }else if(next(first(LR))== NULL){
        first(LR) = NULL;
        last(LR) = NULL;
    }else{
        r = first(LR);
        first(LR) = next(r); 
        next(r) = NULL;
        prev(r) = NULL;
        prev(first(LR)) = NULL;
    }
}

void deleteFirstFilm(listFilm &LF, listPemeran &LP, adr_film pf, adr_pemeran &pp){
    if(first(LF) == NULL){
        pf = NULL;
        cout << "LIST FILM KOSONG" << endl;
    }else if(next(first(LF)) == NULL){
        pf = first(LF);
        pp = first(LP);
        adr_relasi childPP;
        while(pp != NULL){
            childPP = searchFilmRelasi(child(pp), pf); 
            adr_relasi tempChild;
            if(childPP == first(child(pp)) ){
                deleteFirstRelasi(child(pp), tempChild);
            }else if(childPP == last(child(pp))){
                deleteLastRelasi(child(pp), tempChild);
            }else{

            }
        }
    }else{
        
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
    cout << "||" << endl;
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

int sizePemeran(listPemeran L){
    int i = 0;
    adr_pemeran p = first(L);
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
