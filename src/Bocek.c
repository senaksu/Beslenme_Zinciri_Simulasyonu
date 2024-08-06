#include "Bocek.h"

struct BOCEK* bocekOlustur(int sayi)
{
    struct BOCEK* this;
    this = (struct BOCEK*)malloc(sizeof(struct BOCEK));
    this->super = canliOlustur(sayi);
    this->yoket = &bocekYokEt;
    return this;
}

void bocekYokEt(struct BOCEK* this){
    if(this == NULL) return;
    this->super->yokEt(this->super);
    free(this);
}