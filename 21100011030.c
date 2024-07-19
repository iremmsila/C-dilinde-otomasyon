#include <stdio.h>
#include <stdlib.h>
//ÝREM SILA SARIKAYA 21100011030
typedef struct musteri
{
    
    char kitap_adi[100];
    int kitap_no;
    float kitap_fiyat;
    char kitap_yazar[100];
    
} musteri;

typedef struct turu
{
    char kitap_tur[20];
    int tur_no;
    int kitap_sayisi;
    musteri *kitap;
} turu;

turu *tur=NULL; //fonksiyona 1.girisiyle 2. girisini ayirmak icin null atadim

int i,j,sayi,kitap_numarasi;
int secenek,silinecek_tur,git,arama_numarasi,kitap_sayisi,tur_id,kitap_id,silinecek_kitap;
int arttir=0;
float toplam=0;


void ekleme()
{
    printf("\n-------<EKLEME FONKSIYONU>--------\n\n");


    if(tur==0)
    {
        arttir++;
        tur=(turu *)calloc(1,sizeof(turu));
        if(tur==NULL)
        {
            printf("yetersiz bellek!!\n");
            exit(1);
        }



        printf("kitap tur adi="); //filmin turu
        scanf("%s",&(tur)->kitap_tur);
        printf("tur numarasi=");
        scanf("%d",&(tur)->tur_no);
        printf("kitap sayisi=");
        scanf("%d",&(tur)->kitap_sayisi);

        (tur)->kitap=(musteri *)calloc((tur)->kitap_sayisi,sizeof(musteri));
        if((tur)->kitap==NULL){

            printf("yetersiz bellek!!\n");
            exit(1);
        }
        if((tur)->kitap==NULL)
        {
            printf("yetersiz bellek!!\n");
            exit(1);
        }


        for(j=0; j<(tur)->kitap_sayisi; j++)
        {

            printf("kitabin adi = ");
            scanf("%s",&((tur)->kitap+j)->kitap_adi);

            printf("kitap no = ");
            scanf("%d",&((tur)->kitap+j)->kitap_no);
            
            printf("kitabin fiyati = ");
            scanf("%f",&((tur)->kitap+j)->kitap_fiyat);
            
            printf("kitabin yazari = ");
            scanf("%s",&((tur)->kitap+j)->kitap_yazar);
        }
        printf("menuye donmek icin bir sayiya basiniz=");
        scanf("%d",&git);

    }

    else
    {
        arttir++; // yeni tur girerken hafizayi arttirmak icin kullandim
        tur=realloc(tur,arttir*sizeof(turu));
        if(tur==NULL){
            printf("yetersiz bellek!!\n");
            exit(1);
        }
        printf("tur adi="); //filmin tï¿½rï¿½
        scanf("%s",&(tur+(arttir-1))->kitap_tur);
        
        printf("tur no=");
        scanf("%d",&(tur+(arttir-1))->tur_no);
        
        printf("kitap sayisi=");
        scanf("%d",&(tur+(arttir-1))->kitap_sayisi);
        (tur+(arttir-1))->kitap=(musteri *)calloc((tur+(arttir-1))->kitap_sayisi,sizeof(musteri));
        if((tur+(arttir-1))->kitap==NULL){
            printf("yetersiz bellek\n");
            exit(1);
        }
        for(j=0; j<(tur+(arttir-1))->kitap_sayisi; j++)
        {

            printf("kitabin adi=");
            scanf("%s",&((tur+(arttir-1))->kitap+j)->kitap_adi);
            
            printf("film no=");
            scanf("%d",&((tur+(arttir-1))->kitap+j)->kitap_no);
            
            printf("film fiyati=");
            scanf("%f",&((tur+(arttir-1))->kitap+j)->kitap_fiyat);
            
            printf("filmin yonetmeni=");
            scanf("%s",&((tur+(arttir-1))->kitap+j)->kitap_yazar);
        }
        printf("menuye donmek icin bir sayiya basiniz=");
        scanf("%d",&git);
    }
}


void listeleme()
{
    int i,j;
    printf("\n----<LISTELEME FONKSIYONU>----\n");
    for(i=0; i<arttir; i++)
    {


        printf("tur adi=%s\ntur no=%d\n\n",(tur+i)->kitap_tur,(tur+i)->tur_no);

        for(j=0; j<(tur+i)->kitap_sayisi; j++)
        {
            if(((tur+i)->kitap+j)->kitap_no==0) //  kiatp numarasi 0 olanlari listelememek icin kullandim.
            {
                continue;
            }
            printf("%d nolu turun %d nolu kitabin adi=%s\n",(tur+i)->tur_no,((tur+i)->kitap+j)->kitap_no,((tur+i)->kitap+j)->kitap_adi);
            
            printf("%d nolu turun %d nolu kitabin nosu=%d\n",(tur+i)->tur_no,((tur+i)->kitap+j)->kitap_no,((tur+i)->kitap+j)->kitap_no);
            
            printf("%d nolu turun %d nolu kitabin fiyati=%f\n",(tur+i)->tur_no,((tur+i)->kitap+j)->kitap_no,((tur+i)->kitap+j)->kitap_fiyat);
            
            printf("%d nolu turun %d nolu kitabin yazari=%s\n",(tur+i)->tur_no,((tur+i)->kitap+j)->kitap_no,((tur+i)->kitap+j)->kitap_yazar);
            printf("-------------------\n");


        }
    }
    printf("menuye donmek icin bir sayiya basiniz=");
    scanf("%d",&git);


}


void silme()
{
    printf("\n----<SILME FONKSIYONU>----\n\n");
    printf("silinecek turun numarasi=");
    scanf("%d",&silinecek_tur);
    printf("silinecek kitabin numarasi=");
    scanf("%d",&silinecek_kitap);
    for(i=0; i<arttir; i++)
    {
        if((tur+i)->tur_no==silinecek_tur)
        {
            for(j=0; j<(tur+i)->kitap_sayisi; j++)
            {
                if(((tur+i)->kitap+j)->kitap_no==silinecek_kitap)
                {
                    ((tur+i)->kitap+j)->kitap_no=0;
                    printf("%d nolu tur %d nolu kitap silinmistir...\n",silinecek_tur,silinecek_kitap);
                    printf("menuye donmek icin bir sayiya basiniz=");
                    scanf("%d",&git);

                }


            }
        }
    }
}


void guncelleme()
{
    printf("\n----<GUNCELLEME FONKSIYONU>----\n\n");

    printf("guncellemek istediginiz kitabin tur numarasi=");
    scanf("%d",&tur_id);
    printf("guncelemek istediginiz kitabin numarasi=");
    scanf("%d",&kitap_id);
    for(i=0; i<arttir; i++)
    {
        if((tur+i)->tur_no==tur_id)
        {
            for(j=0; j<(tur+i)->kitap_sayisi; j++)
            {
                if(((tur+i)->kitap+j)->kitap_no==kitap_id)
                {
                    printf("kitabin yeni adi=");
                    scanf("%s",&((tur+i)->kitap+j)->kitap_adi);
                    
                    printf("kitabin yeni numarasi=");
                    scanf("%d",&((tur+i)->kitap+j)->kitap_no);
                    
                    printf("kitabin yeni fiyati=");
                    scanf("%f",&((tur+i)->kitap+j)->kitap_fiyat);
                    
                    printf("kitabin yeni yazari=");
                    scanf("%s",&((tur+i)->kitap+j)->kitap_yazar);

                    printf("menuye donmek icin bir sayiya basiniz=");
                    scanf("%d",&git);
                }

            }

        }
    }
}

void arama()
{
    printf("\n----<ARAMA FONKSIYONU>----\n\n");

    printf("aradiginiz turun numarasi=");
    scanf("%d",&arama_numarasi);
    printf("aradiginiz kitabin numarasi=");
    scanf("%d",&kitap_numarasi);
    for(i=0; i<arttir; i++)
    {
        if((tur+i)->tur_no==arama_numarasi)
        {
            printf("tur adi=%s\n",(tur+i)->kitap_tur);
            printf("tur numarasi=%d\n",(tur+i)->tur_no);

            for(j=0; j<(tur+i)->kitap_sayisi; j++)
            {
                if(kitap_numarasi==((tur+i)->kitap+j)->kitap_no)
                {
                    printf("%d nolu turun %d nolu kitabin adi=%s\n",(tur+i)->tur_no,((tur+i)->kitap+j)->kitap_no,((tur+i)->kitap+j)->kitap_adi);
                    
                    printf("%d nolu turun %d nolu kitabin numarasi=%d\n",(tur+i)->tur_no,((tur+i)->kitap+j)->kitap_no,((tur+i)->kitap+j)->kitap_no);
                    
                    printf("%d nolu turun %d nolu kitabin fiyati=%f\n",(tur+i)->tur_no,((tur+i)->kitap+j)->kitap_no,((tur+i)->kitap+j)->kitap_fiyat);
                    
                    printf("%d nolu turun %d nolu kitabin yazari=%s\n",(tur+i)->tur_no,((tur+i)->kitap+j)->kitap_no,((tur+i)->kitap+j)->kitap_yazar);
                    printf("-----------------------------------------\n");
                }
            }
            printf("menuye donmek icin bir sayiya basiniz=");
            scanf("%d",&git);
        }

    }
}

void satinalim()
{
    printf("\n----<SATIN ALMA FONKSIYONU>----\n\n");


    printf("satin alacaginiz kitabin tur numarasi=");
    scanf("%d",&tur_id);
    printf("satin alacaginiz filmin nosu=");
    scanf("%d",&kitap_id);
    for(i=0; i<arttir; i++)
    {
        if(tur_id==(tur+i)->tur_no)
        {
            for(j=0; j<(tur+i)->kitap_sayisi; j++)
            {
                if(kitap_id==((tur+i)->kitap+j)->kitap_no)
                {
                    toplam=((tur+i)->kitap+j)->kitap_fiyat+toplam;
                    printf("%d nolu tur %d nolu kitabi satin aldiniz! aldiginiz her kitap yeni bir dunya :)\n",(tur+i)->tur_no,((tur+i)->kitap+j)->kitap_no);
                    printf("toplam borcunuz=%f \n",toplam);
                    printf("menuye donmek icin bir sayiya basiniz=");
                    scanf("%d",&git);
                }
            }
        }
    }

}

int main()

{

    turu *ptr;
    secenek=9;
    printf("----------------KITAP BILGILENDIRME VE ALIM OTOMASYONU----------------\n\n");
    while(secenek!=7)
    {
        printf("----MENU----\n");
        printf("1->EKLE\n2->LISTELE\n3->GUNCELLE\n4->ARAMA YAP\n5->SIL\n6->SATIN AL\n7->CIKIS\n1 ile 7 arasinda sayi giriniz\n\nSECIM= ");
        scanf("%d",&secenek);
        
        if(secenek==1)
        {
            ekleme();
		}
		else if(secenek==2)
		{
			listeleme();
		}
		else if(secenek==3)
		{
			guncelleme();
		}
		else if(secenek==4)
		{
			arama();
		}
		else if(secenek==5)
		{
			silme();
		}
		else if(secenek==6)
		{
			satinalim();
		}
		else if(secenek==7)
		{
			printf("cikis yapiyorsunuz... Bizi tercih ettiginiz icin tesekkur ederiz!!");
			break;
		}
    }
    return 0;
}





