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
        prev(first(L)) = last(L);
        next(last(L)) = first(L);
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
        prev(first(L)) = last(L);
        next(last(L)) = first(L);
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
        prev(first(L)) = last(L);
        next(last(L)) = first(L);
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
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
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
    }else {
        next(last(L)) = p;
        prev(p) = last(L);
        last(L) = p;
    }
}

void deleteFirstFilm(listFilm &L, adr_film &p);
void deleteFirstPemeran(listPemeran &L, adr_pemeran &p);
void deleteFirstRelasi(listRelasi &L, adr_pemeran &p);

void deleteLastFilm(listFilm &L, adr_film &p);
void deleteLastPemeran(listPemeran &L, adr_pemeran &p);
void deleteLastRelasi(listRelasi &L, adr_pemeran &p);

void printShowAllFilm(listFilm L);
void printShowAllPemeran(listPemeran L);
void printShowAllRelasi(listRelasi L);