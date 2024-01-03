#include "Film.h"

void createListRelasi(listRelasi &L){
    first(L) = NULL;
    last(L) = NULL;
}

adr_relasi createElemenRelasi(adr_film p){
    adr_relasi n = new elemenRelasi;
    next_film(n) = p;
    next(n) = NULL;
    prev(n) = NULL;
    return n;
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
            next(last(LR)) = r;
            prev(r) = last(LR);
            last(LR) = r;
        }
}

adr_relasi searchFilmRelasi(listRelasi LR, adr_film af){
    adr_relasi c = first(LR);
    while(c != NULL){
        if(next_film(c) == af){
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
        r = last(LR);
        last(LR) = prev(r); 
        prev(r) = NULL;
        next(last(LR)) = NULL;
    }
}

void deleteRelasiPemeran(listPemeran &LP, adr_film af){
    adr_pemeran ap = first(LP);
    while(ap != NULL){
        adr_relasi ar = searchFilmRelasi(child(ap), af);
        deleteRelasi(child(ap), ar);
        info(ap).nFilm--;
        ap = next(ap);
    }
}

void deleteAllRelasiPemeran(listRelasi &LR, adr_relasi &ar){
    if(first(LR) == NULL && last(LR) == NULL){
        ar = NULL;
    }else{
        while(first(LR) != NULL && last(LR) != NULL){
            deleteFirstRelasi(LR, ar);
        }
    }
}

void deleteRelasi(listRelasi &LR, adr_relasi &ar){
    if(ar != NULL){
        if(ar == first(LR)){
            deleteFirstRelasi(LR, ar);
        }else if(ar == last(LR)){
            deleteLastRelasi(LR, ar);
        }else{
            adr_relasi prec = prev(ar);
            next(prec) = next(ar);
            prev(next(ar)) = prec;
            prev(ar) = NULL;
            next(ar) = NULL;
        }
    }
}