#include "Bitki.h"

struct BITKI* bitkiOlustur(int sayi)
{
    struct BITKI* this;
    this = (struct BITKI*)malloc(sizeof(struct BITKI));
    this->super = canliOlustur(sayi);
    this->yoket = &bitkiYokEt;
    return this;
}

void bitkiYokEt(struct BITKI* this){
    if(this == NULL) return;
    this->super->yokEt(this->super);
    free(this);
}