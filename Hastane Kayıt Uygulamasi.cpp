#include<iostream>
#include<list>
#include<queue>

using namespace std;

class insan
{
        protected:
        string ad;
        string soyad;
        int yas;
        bool engelliMi;

        public:
        insan(string ad,string soyad,int yas,bool engelliMi=false)
        
        {
        	
            this->ad = ad;
            this->soyad = soyad;
            this->yas = yas;
            this->engelliMi = engelliMi;
            
        }

        void Yazdir() const
        
        {
        	
            cout<<"Ad: "<<ad<<endl;
            cout<<"Soyad: "<<soyad<<endl;
            cout<<"Yas: "<<yas<<endl;
            cout<<"Engellilik Durumu: ";

            if(engelliMi)

                cout<<"Evet"<<endl;

            else

                cout<<"Hayir"<<endl;
                
        }
        
};

class Hasta : public insan
{
    int hastaNo;
    int oncelikPuani;

    public:
        
        Hasta( int hastaNo , insan& i) : hastaNo(hastaNo), insan(i), oncelikPuani(0)
        {
        	
            oncelikPuaniHesapla();
            
        }
        Hasta(int hastaNo, string ad, string soyad, int yas, bool engelliMi=false) : hastaNo(hastaNo), insan(ad, soyad, yas, engelliMi), oncelikPuani(0)
        {
        	
            oncelikPuaniHesapla();
            
        }

        void oncelikPuaniHesapla()
        {
        	
            if (engelliMi)
            {
            	
                oncelikPuani += 30;
            }
            

            if (yas > 65)
            {
            	
                oncelikPuani += yas - 65;
            }
            
        }
        

        bool operator<(const Hasta& h) const
        {
        	
            return oncelikPuani < h.oncelikPuani;
        }
        

        void yazdir() const
        {
        	
            insan::Yazdir();
            cout<<"Hasta No: "<<hastaNo<<endl;
            cout<<"Oncelik Puani: "<<oncelikPuani<<endl;
        }
        
};

 class HastaKayit
 {
    
    list<Hasta> kayitSirasi; // kayıt sırası bir liste olusturduk
    priority_queue<Hasta> muayeneSirasi; // queue kuyruk olusturduk sırayı tuttuk
    
    public:
       void Kayit(insan& i)
       {
       	    
            Hasta hasta(kayitSirasi.size()+1, i);
            kayitSirasi.push_back(hasta);
            muayeneSirasi.push(hasta);
             
       }

       void kayitSirasiYazdir()
       {
          
          cout<<"### HASTA KAYIT SIRASI ###"<<endl;
          if (kayitSirasi.empty())
          {
          	
            cout<<"Kayitli hasta yok."<<endl;
          }

          else
          {
            list<Hasta>::iterator iter = kayitSirasi.begin();
            while(iter != kayitSirasi.end())
            {
            	Hasta hasta = *iter;
                hasta.yazdir();
                iter++;
                if(iter != kayitSirasi.end())
                cout<<endl;

            }

            
          }

       	 cout<<"### HASTA KAYIT SIRASI SONU ###"<<endl;
       }

         void muayeneSirasiYazdir()
         {
         	
             cout<<"### HASTA MUAYENE SIRASI ###"<<endl;
             if (muayeneSirasi.empty())
             {
             	
                cout<<"Muayene bekleyen hasta yok."<<endl;
             }
    
             else
             {
                priority_queue<Hasta> kuyruk = muayeneSirasi;
                while(!kuyruk.empty())
                {
                	
                 Hasta hasta = kuyruk.top();
                 hasta.yazdir();
                 kuyruk.pop();
                 if(!kuyruk.empty())
                 cout<<endl;
    
                }
    
                
             }
    
         	 cout<<"### HASTA MUAYENE SIRASI SONU ###"<<endl;
         }

         void hastaCagir()
         {
           
           
           if(muayeneSirasi.empty())
           {
           	
            cout<<"Muayene bekleyen hasta yok."<<endl;
           }

           else

           {

           	cout<<"Hasta cagiriliyor..."<<endl;
            Hasta hasta = muayeneSirasi.top();
            hasta.yazdir();
            muayeneSirasi.pop();
            

           }
            cout<<endl;
         }


 };

int main()
{
	insan insanlar[] = 

    {

    insan ("Emircan",  "Yetkin", 20),
    insan ("Bilge",   "Uzun", 19), 
    insan ("Furkan",  "Yalcin", 65,true),
    insan ("Eren Efe","Yildiz", 66,true),
    insan ("Dogukan", "Tekin", 67,true),
    insan ("Can",  "Tekin", 20),

    };
   
    HastaKayit bankosu;
    bankosu.Kayit(insanlar[0]);
    bankosu.Kayit(insanlar[1]);
    bankosu.Kayit(insanlar[2]);
    bankosu.Kayit(insanlar[3]);
    bankosu.Kayit(insanlar[4]);
    bankosu.Kayit(insanlar[5]);
    bankosu.kayitSirasiYazdir();
    cout<<endl;
    bankosu.muayeneSirasiYazdir();
    bankosu.hastaCagir();
    bankosu.hastaCagir();
    bankosu.hastaCagir();
    bankosu.hastaCagir();
    bankosu.hastaCagir();
    bankosu.hastaCagir();
    bankosu.kayitSirasiYazdir();
    cout<<endl;
    bankosu.muayeneSirasiYazdir();    
  

    system("color B");
    system("pause");



    return 0;
}