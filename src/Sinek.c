#include "Sinek.h"

struct SINEK* sinekOlustur(int sayi)
{
    struct SINEK* this;
    this = (struct SINEK*)malloc(sizeof(struct SINEK));
    this->super = bocekOlustur(sayi);
    this->yoket = &sinekYokEt;
    return this;
}

void sinekYokEt(struct SINEK* this){
    if(this == NULL) return;
    this->super->yoket(this->super);
    free(this);
}