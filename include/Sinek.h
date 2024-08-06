#ifndef SINEK_H
#define SINEK_H

#include "Bocek.h"

struct SINEK{
    struct BOCEK* super;
    
    void (*yoket)(struct SINEK*);
};
typedef struct SINEK* Sinek;
struct SINEK* sinekOlustur(int);
void sinekYokEt(struct SINEK*);
#endif