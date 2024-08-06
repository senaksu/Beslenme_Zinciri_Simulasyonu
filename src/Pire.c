#include "Pire.h"

struct PIRE* pireOlustur(int sayi)
{
    struct PIRE* this;
    this = (struct PIRE*)malloc(sizeof(struct PIRE));
    this->super = bocekOlustur(sayi);
    this->yoket = &pireYokEt;
    return this;
}

void pireYokEt(struct PIRE* this){
    if(this == NULL) return;
    this->super->yoket(this->super);
    free(this);
}