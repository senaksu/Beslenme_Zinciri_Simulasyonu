#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Canli.h>
#include <Bitki.h>
#include <Bocek.h>
#include <Sinek.h>
#include <Pire.h>
#include <Habitat.h>
#include <windows.h>

void generate_matrix(int satir, int sutun)
{
    int** matrix = (int**)malloc(satir * sizeof(int*));

    for(int i = 0; i < satir ; i++)
    {
        matrix[i] = (int*) malloc (sutun * sizeof(int));
    }

    srand(time(NULL));

    for(int i = 0 ; i < satir; i++)
    {
        for (int j = 0 ; j < sutun ; j++)
        {
            //matrix[i][j] = rand() %99 +1;
            matrix[i][j] = 6;
        }
    }

    for (int i = 0 ; i < satir ; i ++)
    {
        for (int j = 0 ; j < sutun ; j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // Dosya işlemleri için gerekli değişkenler
    FILE *dosya;
    char *dosyaAdi = "textVeri.txt";
    dosya = fopen(dosyaAdi, "r");

    // Dosya açıldı mı kontrol et
    if (dosya == NULL) {
        printf("Dosya açılamadı, lütfen kontrol edin..");
        return 1;
    }

    // Satır ve sütun sayılarını bul
    int satir_sayisi = 0, satirdaki_sayi_sayisi = 0;
    char c;
    while ((c = getc(dosya)) != EOF) {
        if (c == ' ') {
            satirdaki_sayi_sayisi++;
        } else if (c == '\n') {
            satir_sayisi++;
            satirdaki_sayi_sayisi++;
        }
    }

    fclose(dosya);  
    satir_sayisi++;
    satirdaki_sayi_sayisi += satir_sayisi;
    satirdaki_sayi_sayisi /= satir_sayisi;

    struct CANLI*** canli_dizisi  = (struct CANLI***)malloc(satir_sayisi * sizeof(struct CANLI**));
    if (canli_dizisi == NULL) {
        printf("Başarısız bellek yönetimi");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < satir_sayisi; i++) {
        canli_dizisi[i] = (struct CANLI**)malloc(satirdaki_sayi_sayisi * sizeof(struct CANLI*));
        if (canli_dizisi[i] == NULL) {
            printf("Başarısız bellek yönetimi");
            exit(EXIT_FAILURE);
        }
    }
    for(int i = 0 ; i < satir_sayisi; i++)
    {
        for (int j = 0 ; j < satirdaki_sayi_sayisi ; j++)
        {
            canli_dizisi[i][j] = NULL;
        }
    }

    dosya = fopen("textVeri.txt", "r");
    if (dosya == NULL) {
        printf("Dosya açılamadı, lütfen kontrol edin..");
        return 1;
    }
    int sayi = 0;
    for (int i = 0; i < satir_sayisi; i++) {
        for (int j = 0; j < satirdaki_sayi_sayisi; j++) {
            fscanf(dosya, "%d", &sayi);
            if(sayi >= 1 && sayi <= 9)
            {
                struct BITKI* bitki = bitkiOlustur(sayi);
                canli_dizisi[i][j] = bitki->super;
            }
            else if(sayi >= 10 && sayi <= 20)
            {
                struct BOCEK* bocek = bocekOlustur(sayi);
                canli_dizisi[i][j] = bocek->super;
            }
            else if(sayi >= 21 && sayi <= 50)
            {
                struct SINEK* sinek = sinekOlustur(sayi);
                canli_dizisi[i][j] = sinek->super->super;
            }
            else if(sayi >= 51 && sayi <= 99)
            {
                struct PIRE* pire= pireOlustur(sayi);
                canli_dizisi[i][j] = pire->super->super;
            }
            else
            {
                printf("Gecersiz veri araligi: %d\n", sayi);
                continue;
            }
        }
    }

    fclose(dosya);

    struct HABITAT* habitat = habitatOlustur(satir_sayisi,satirdaki_sayi_sayisi);



    for (int k = 0; k < satir_sayisi * satirdaki_sayi_sayisi; k++)
    {

        habitat->goster(habitat, canli_dizisi);
        
        habitat->guncelle(habitat, canli_dizisi);

        printf("------------------------\n");
    
        Sleep(1); 
        if(k != satir_sayisi * satirdaki_sayi_sayisi - 1)
            system("cls");
    }



    //habitat->yokEt(habitat);
    
    for(int i = 0 ; i < satir_sayisi ; i++)
    {
        for(int j = 0; j < satirdaki_sayi_sayisi; j ++)
        {
            if(canli_dizisi[i][j] != NULL)
                canli_dizisi[i][j]->yokEt(canli_dizisi[i][j]);
        }
        free(canli_dizisi[i]);
    }

    free(canli_dizisi);

    return 0;
}