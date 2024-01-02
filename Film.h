#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <iostream>
#define info(p) p->info
#define next(p) p->next
#define prev(p) p->prev
#define child(Z) Z->child
#define next_film(n) n->next_film
#define first(L) L.first
#define last(L) L.last
using namespace std;

struct pemeran{
    string nama;
    char gender;
    int usia;
    int nFilm;
};

struct film{
    string nama;
    int terbit;
    string genre;
};

typedef struct elemenPemeran *adr_pemeran;
typedef struct elemenFilm *adr_film;
typedef struct elemenRelasi *adr_relasi;

typedef struct film infotype_film;
typedef struct pemeran infotype_pemeran;

struct listFilm{
    adr_film first;
    adr_film last;
};

struct listPemeran{
    adr_pemeran first;
    adr_pemeran last;
};

struct listRelasi{
    adr_relasi first;
    adr_relasi last;
};


struct elemenPemeran{
    infotype_pemeran info;
    adr_pemeran next;
    adr_pemeran prev;
    listRelasi child;
};

struct elemenFilm{
    infotype_film info;
    adr_film prev;
    adr_film next;
};

struct elemenRelasi{
    adr_film next_film;
    adr_relasi next;
    adr_relasi prev;
};

void createListFilm(listFilm &L);
void createListPemeran(listPemeran &L);
void createListRelasi(listRelasi &L);

adr_film createElemenFilm(infotype_film p);
adr_pemeran createElemenPemeran(infotype_pemeran p);
adr_relasi createElemenRelasi(adr_film p);

void insertFirstFilm(listFilm &L, adr_film p);
void insertFirstPemeran(listPemeran &L, adr_pemeran p);
void insertFirstRelasi(listRelasi &L, adr_relasi p);

void insertLastFilm(listFilm &L, adr_film p);
void insertLastPemeran(listPemeran &L, adr_pemeran p);
void insertLastRelasi(listRelasi &LR, adr_film f);

void deleteFirstFilm(listFilm &L, adr_film &af);
void deleteFirstPemeran(listPemeran &L, adr_pemeran &p);
void deleteFirstRelasi(listRelasi &LR, adr_relasi &r);

void deleteLastFilm(listFilm &LF, adr_film &af);
void deleteLastPemeran(listPemeran &L, adr_pemeran &p);
void deleteLastRelasi(listRelasi &LR, adr_relasi &r);

void printShowAllFilm(listFilm L);
void printShowAllPemeran(listPemeran L);
void printShowAllRelasi(listRelasi L);

void mainFilm(listPemeran &LP, listFilm &LF);

int menu();

int sizeFilm(listFilm L);
int sizePemeran(listPemeran L);

adr_film searchFilm(listFilm LF);
adr_pemeran searchPemeran(listPemeran LP);

adr_relasi searchFilmRelasi(listRelasi LR, adr_film pf);

void deleteFilm(listFilm &LF, listPemeran &LP);
void deleteRelasiPemeran(listPemeran &LP, adr_film af);
void deleteRelasi(listRelasi &LR, adr_relasi &ar);
void showFilmWithActors(listPemeran LP, listFilm LF);

bool isExist(listRelasi q, adr_film f);

void showFilmWithSpecificActor(listPemeran LP);
void showActorsFromFilm(listPemeran LP, listFilm LF);
void showTopActorOrActress(listPemeran LP, listFilm LF);
void deletePemeran(listPemeran &LP);
void deleteAllRelasiPemeran(listRelasi &LR, adr_relasi &ar);
#endif // FILM_H_INCLUDED
