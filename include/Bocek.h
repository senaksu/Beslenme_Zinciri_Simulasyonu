#ifndef BOCEK_H
#define BOCEK_H

#include "Canli.h"

struct BOCEK{
    struct CANLI* super;
    
    void (*yoket)(struct BOCEK*);
};

struct BOCEK* bocekOlustur(int);
void bocekYokEt(struct BOCEK*);
#endif