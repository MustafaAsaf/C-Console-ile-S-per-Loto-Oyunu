#include <stdio.h>
#include <stdlib.h>
#define size 60  //say�lar�n gidebilece�i en son s�n�r
#define sayilar 6 //say�lardan se�ilebilecek en son s�n�r
#include<time.h>
    
int main()
{
    int static oyuncu_tercih[size]={0};//ve  sadece bir kez olu�ur (bir kez s�f�r kullan�l�r)
    
    anaMENU(oyuncu_tercih);
    return 0;
}

void anaMENU(int oyuncu_tercih[])
{
    int menu;
    char cikis;//char de�i�kenler i�in kullan�l�r
    
			
            printf("****MILLI PIYANGO SUPER LOTO ANA MENUSU ***\n");
            printf("1. Super Loto (6/54) Oynama Manuel\n");
            printf("2. Super Loto (6/54) Oynama Otomatik\n");
            printf("3. Cikis\n\n");
    do{
   	 do{
            printf("Menuden Secim Yapiniz: ");
            scanf("%d",&menu);printf("\n");
	   }
    while(menu<1 || menu>3);//Dogru giris yapilincaya kadar beklenir�
    
    switch(menu)
	{
        case 1: //fonksiyonlara dizi ve sayilar gonderiliyor�
        system("CLS"); //Menuden se�ilen se�ene�i ayr� bir ekranda a�ar.
        super_loto(oyuncu_tercih);//fonksiyon cagiriliyor�
        break;
        
        
        case 2:
        system("CLS");//Menuden se�ilen se�ene�i ayr� bir ekranda a�ar.
        OtoSuperLoto(oyuncu_tercih);	
        break;
        
        case 3:
        system("CLS");	//Menuden se�ilen se�ene�i ayr� bir ekranda a�ar.
        do{//cevap dogru girilinceye kadar bekleniyor�
        printf("Cikmak istediginize emin misiniz(e/E/h/H)?: ");
        fflush(stdin);//stdin dosyas�n�n bufferlar�n� bo�altmak i�in kullan�l�r g�venli veri aktar�m�n� sa�lar
        cikis=getchar();//klavyeden karakter okumak i�in kullan�l�r
        }

    	while ( cikis != 'e' && cikis != 'E' && cikis!='h' && cikis!='H');
    }
    }

    while(cikis == 'H' || cikis == 'h');//cikilmak istenmiyorsa basa donuluyor�
}

int OtoSuperLoto(int oyuncu_tercih[])
{
	 int sayi[6]={0};//ve bilgisayar tekrar say� belirliyor�
	 char son;
			int miktar;
            int tahmin[6]={0};//tahminlere s�f�r  atan�yor�
            int i,a;//her oyunda tahminlere s�f�r  atan�yor
            int dogru_tahmin=0; //Kullan�c�n�n yapt��� her bir tahmin.
            
            srand(time(NULL));//Program Her Ac�ld�g�nda Farkl� Say�lar Vericek 
            //Sistem Kendi Say�lar�n� Hesapl�yor
            for(i=0;i<=5;i++)
			{
                sayi[i]=1+(rand()%60);
                if(i>0)
				{//sayilarin ayni olmamasi saglaniyor..
                    for(a=0;a<=(i-1);a++)
					{
                        while(sayi[a]==sayi[i])
						{
                            sayi[i]=(1+rand()%60);
						}
        			}
        		}
  		    }
  		
  		
  		printf("Oyuna Min. 10tl yatiriniz\n");
  		
  		yeniden:
  		printf("Oyuna Yatirilacak Para Miktari:");
  		scanf("%d",&miktar);printf("\n");
  		
  		if(miktar<10)
  		{
  			printf("!!! Oyuna Min. 10tl para yatirilabilir !!!\n");
  			goto yeniden;
		}
  		
  		
  		printf("Otomatik Kolonlar Dolduruluyor...\n");
  		
  		for(i=0;i<=5;i++)
		{
          tahmin[i]=1+(rand()%60);
          if(i>0)//sayilarin ayni olmamasi saglaniyor..
          for(a=0;a<=(i-1);a++)
		  {
			while(tahmin[a]==tahmin[i])
			{
				tahmin[i]=1+rand()%60;
			}
          }
  	    }
  	    
  	    
  	   //tahminler ve sayilar karsilastiriliyor�
  	   for(i=0;i<6;i++)
	   {
        for(a=0;a<=5;a++)
		{
            if (sayi[i]==tahmin[a])
			{
                dogru_tahmin++;
            }
        }
       }
       
       printf("\n Bilgisayarin yaptigi tahminler        Sizin Tahminleriniz\n");
    printf("\n*******************************        *********************\n");
    bubbleSortPC(sayi); //Bilgisayar�n Girdi�i Say�lar� K���kten B�y��e S�ralayan Fonksiyon
    bubbleSortKullanici(tahmin); //Kullan�c�n�n Girdi�i Say�lar� K���kten B�y��e S�ralayan Fonksiyon
    for(i=0;i<=5;i++)
	{
        printf("%15d %35d\n\n",sayi[i],tahmin[i]);
    }
    switch(dogru_tahmin)
	{//dogru tahmin sayisina gore odul belirleniyor ve kac kez kazanildigi sayiliyor�

        case 0:case 1: printf("Dogru tahmin sayiniz:%d  Uzgunum  odul kazanamadiniz.\n\n",dogru_tahmin);
        break;
        
        case 2: printf("Dogru tahmin sayisi:2 TEBRIKLER kazandiginiz odul:%d TL\n\n",(miktar*1));
        break;
        
        case 3: printf("Dogru tahmin sayisi:3 TEBRIKLER kazandiginiz odul:%d TL\n\n",(miktar*3));
        break;
        
        case 4: printf("Dogru tahmin sayisi:3 TEBRIKLER kazandiginiz odul:%d TL\n\n",(miktar*5));
        break;
        
        case 5: printf("Dogru tahmin sayisi:5 TEBRIKLER kazandiginiz odul:%d TL\n\n",(miktar*7));
        break;
        
        case 6: printf("Dogru tahmin sayisi:6 TEBRIKLER kazandiginiz odul:%d TL\n\n",(miktar*50));
        break;
    }
    
    printf("**** Oyunun Tekrar Oynamak Istermisimiz ****\n\n");
    printf("Evet->'E','e' Hayir->'H','h': ");
    scanf("%s",&son);printf("\n");
    
    switch(son)
    {
    	case 'E': goto yeniden;
    	break;
    	
    	case 'e': goto yeniden;
    	break;
    	
    	case 'h':  break;
    	
    	case 'H': break;	
    	
    	default:printf("!!!Hatali Kod Girdiniz!!!"); break;
	}

    return 0; 	
}

int super_loto(int oyuncu_tercih[] )
{    
	//srand(time(NULL));//Program Her Ac�ld�g�nda Farkl� Say�lar Vericek
            //rand() 0-MAX de�erleri ara�ndan se�ti�i say�lar� alma i�lemi
            int sayi[6]={0};//ve bilgisayar tekrar say� belirliyor�
            int son2;
			int miktar2;
            int tahmin[6]={0};//tahminlere s�f�r  atan�yor�
            int i,a;//her oyunda tahminlere s�f�r  atan�yor
            int dogru_tahmin=0; //Kullan�c�n�n yapt��� her bir tahmin.
            
            //Bilgisayar Kendi say�lar�n� yaz�yor ve haf�zaya kaydediyor.
            srand(time(NULL));
            for(i=0;i<=5;i++)
			{
                sayi[i]=1+(rand()%60);
                if(i>0)//sayilarin ayni olmamasi saglaniyor..
                    for(a=0;a<=(i-1);a++)
					{

                        while(sayi[a]==sayi[i]){

                            sayi[i]=1+rand()%60;}
        			}
  		    }
  		    
  		printf("Oyuna Min. 10tl yatiriniz\n");
  		
  		yeniden:
  		printf("Oyuna Yatirilacak Para Miktari:");
  		scanf("%d",&miktar2);printf("\n");
  		
  		if(miktar2<10)
  		{
  			printf("!!! Oyuna Min. 10tl para yatirilabilir !!!\n");
  			goto yeniden;
		}
  		    
    printf("Kolonlari Doldurunuz...\n");
    for(i=0;i<6;i++)
	{//tahminler aliniyor�
    {
        printf("%d.Kolon: ",i+1);
        scanf("%d",&tahmin[i]);
	}
        while(tahmin[i]<1 || tahmin[i]>60)//hata mesaji veriliyor..
		{
            printf("Hatali giris yaptiniz. Lutfen [0-60] araliginda bir deger girin.\n");
            scanf("%d",&tahmin[i]);
        }
            
        if(i>0)
            for(a=0;a<=(i-1);a++)
			{
                while(tahmin[a]==tahmin[i])
				{//ayni olup olmadigi kontrol ediliyor�
                    printf("Ayni sayiyi girdiniz.Lutfen farkli sayilar kullanarak tekrar giris yapiniz.\n");
                    scanf("%d",&tahmin[i]);
          	     }
             }
   }

    
    for(i=0;i<6;i++)
	{//tahminler ve sayilar karsilastiriliyor�
        for(a=0;a<=5;a++)
		{
            if (sayi[i]==tahmin[a])
			{
                dogru_tahmin++;
            }
        }
    }
    
    
    printf("\n Bilgisayarin yaptigi tahminler        Sizin Tahminleriniz\n");
    printf("\n*******************************        *********************\n");
    bubbleSortPC(sayi); //Bilgisayar�n Girdi�i Say�lar� K���kten B�y��e S�ralayan Fonksiyon
    bubbleSortKullanici(tahmin); //Kullan�c�n�n Girdi�i Say�lar� K���kten B�y��e S�ralayan Fonksiyon
    for(i=0;i<6;i++)
	{
        printf("%15d %35d\n\n",sayi[i],tahmin[i]);
    }
    switch(dogru_tahmin)
	{//dogru tahmin sayisina gore odul belirleniyor ve kac kez kazanildigi sayiliyor�

        case 0:case 1: printf("Dogru tahmin sayiniz:%d  Uzgunum  odul kazanamadiniz.\n",dogru_tahmin);
        break;
        
        case 2: printf("Dogru tahmin sayisi:2 TEBRIKLER kazandiginiz odul:%d TL\n",(miktar2*1));
        break;
        
        case 3: printf("Dogru tahmin sayisi:3 TEBRIKLER kazandiginiz odul:%d TL\n",(miktar2*3));
        break;
        
        case 4: printf("Dogru tahmin sayisi:3 TEBRIKLER kazandiginiz odul:%d TL\n",(miktar2*5));
        break;
        
        case 5: printf("Dogru tahmin sayisi:5 TEBRIKLER kazandiginiz odul:%d TL\n",(miktar2*7));
        break;
        
        case 6: printf("Dogru tahmin sayisi:6 TEBRIKLER kazandiginiz odul:%d TL\n",(miktar2*50));
        break;
    }
    
    printf("**** Oyunun Tekrar Oynamak Istermisimiz ****\n\n");
    printf("Evet->'E','e' Hayir->'H','h': ");
    scanf("%s",&son2);printf("\n");
    
    switch(son2)
    {
    	case 'E': goto yeniden;
    	break;
    	
    	case 'e': goto yeniden;
    	break;
    	
    	case 'h':  break;
    	
    	case 'H': break;	
    	
    	default:printf("!!!Hatali Kod Girdiniz!!!"); break;
	}
    return 0; 
}


int bubbleSortPC(int dizi[])
{
	int i,j;

	for(i=0; i<6; i++)
	{
		for(j=1; j<6; j++)
		{
			if(dizi[j-1]>dizi[j])
			{
				int gecici;
				gecici=dizi[j];
				dizi[j] = dizi[j-1];
				dizi[j-1] = gecici;
			}
		}
	}
}

int bubbleSortKullanici(int dizi2[])
{
	int a,b;
	for(a=0; a<6; a++ )
	{
		for(b=1; b<6; b++)
		{
			if(dizi2[b-1]>dizi2[b])
			{
				int temp;
				temp=dizi2[b];
				dizi2[b]=dizi2[b-1];
				dizi2[b-1]=temp;
			}
		}
	}
}

