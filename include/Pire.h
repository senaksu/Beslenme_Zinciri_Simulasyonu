#ifndef PIRE_H
#define PIRE_H

#include "Bocek.h"

struct PIRE{
    struct BOCEK* super;
    
    void (*yoket)(struct PIRE*);
};

struct PIRE* pireOlustur(int);
void pireYokEt(struct PIRE*);
#endif