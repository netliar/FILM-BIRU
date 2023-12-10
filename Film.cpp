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
    info(n).durasi = p.durasi;
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
void insertLastRelasi(listRelasi &L, adr_relasi p){
    if(first(L) == NULL){
        first(L) = p;
        last(L) = p;
        cout << "BBB" << endl;
    }else{
        adr_relasi q = first(L);
        bool ada = false;
        while(q != NULL && !ada){
            if(next_film(q) == next_film(p)){
                ada = true;
            }else{
                q = next(q);
            }
        }
        if(ada){
            cout << "Pilih film yang lain!" << endl;
        }else{
            next(last(L)) = p;
            prev(p) = last(L);
            last(L) = p;
                        cout << "Inserted as the last element." << endl;

        }
    }
}

void deleteFirstFilm(listFilm &L, adr_film &p){
    if(first(L) == NULL){
        p = NULL;
        cout << "LIST FILM KOSONG" << endl;
    }else if(next(first(L)) == NULL){
        p = first(L);
        first(L) = NULL;
        last(L) = NULL;
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
        cout << i << ". " << info(p).nama << " - " << info(p).durasi << " - " << info(p).genre << endl;
        i++;
        p = next(p);
    }
}

int menu(){
    int pilih;
    cout << "==== MENU ====" << endl;
    cout << "1. Tambah Film" << endl;
    cout << "2. Tambah Pemeran" << endl;
    cout << "3. Main Film" << endl;
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
    int NP = sizePemeran(LP);
    int NF = sizeFilm(LF);
    if(NP == 0 || NF == 0){
        cout << "Silahkan isi Pemeran atau Film terlebih dahulu!" << endl;
    }else{
        bool stop = false;

        adr_pemeran arrPemeran[NF];
        adr_film arrFilm[NF];

        adr_pemeran p = first(LP);
        adr_film f = first(LF);
        adr_relasi r = NULL;
        listRelasi LR;
        createListRelasi(LR);

        int pilihPemeran = 0;
        int pilihFilm = 0;
        int i = 0;
        cout << "==== List Pemeran ====" << endl;
        while(p != NULL){
            arrPemeran[i] = p;
            i++;
            cout << i << ". " << info(p).nama << " - " << info(p).gender << endl;
            p = next(p);
        }
        int z = 0;
        while(z < NP){
            cout << arrPemeran[z] << endl;
            z++;
        }
        while(!stop){
            cout << "Pilih Pemeran: ";
            cin >> pilihPemeran;
            if(pilihPemeran <= 0 || pilihPemeran > NP){
                cout << "Pilihan tidak ada" << endl;
            }else{
                p = arrPemeran[pilihPemeran-1];
                createListRelasi(child(p));  // Ensure child list is created
                stop = true;
            }
        }

        i = 0;
        stop = false;
        cout << "==== List Film ====" << endl;
        while(f != NULL){
            arrFilm[i] = f;
            i++;
            cout << i << ". " << info(f).nama << " - " << info(f).durasi << " - " << info(f).genre << endl;
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
        if(p == NULL && f == NULL){
            cout << "KSOSONG ANKAJSDLKAS" << endl;
        }else{
            r = createElemenRelasi(f);
            LR = child(p);
            insertLastRelasi(LR, r);
        }
    }
}
