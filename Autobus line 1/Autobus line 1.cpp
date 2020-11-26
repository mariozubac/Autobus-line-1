#include<iostream>
using namespace std;

const char* crt = "\n---------------------------------------------------------\n";

class AutobuskaLinija {
    int _brojLinije;
    char _odrediste[30];
    int _kapacitet;
    int _rezervisanoKarata;
public:

    AutobuskaLinija() {};

    AutobuskaLinija(int no, const char dest[], int seats)

    {
        _brojLinije = no;
        _kapacitet = seats;
        strncpy_s(_odrediste, dest, 30);
    };


    int GetBrojLinije() { return _brojLinije; }
    const char* GetOdrediste() { return _odrediste; }
    int Getseats() { return _kapacitet; }
    int Getrez() { return _rezervisanoKarata; }
    void setRezMjesta(int brMjesta) { _rezervisanoKarata = brMjesta; }


};

const int maxBrojLinija(10);




class RedVoznje {

    AutobuskaLinija* _raspored = new AutobuskaLinija[maxBrojLinija] ; //Dinamički niz objekata
    int _trenutnoLinija=0;

public:

    /*
  Funkcija DodajAutobuskuLiniju evidentira novu autobusku liniju u red voznje.

  Autobuska linija sa istim brojem ne može biti dodana više puta u isti red vožnje.

  Maksimalan broj autobuskih linija također ne smije biti prekoračen.

  Funkcija, u zavisnosti od uspješnosti dodavanja autobuske linije, vraća logičku vrijednost true ili false
  */

  //AutobuskaLinija* _raspored = new AutobuskaLinija[maxBrojLinija];


    bool DodajAutobuskuLiniju(AutobuskaLinija line)

    {
        for (int i = 0; i <= _trenutnoLinija; i++)
        {
            cout << " here " << _raspored[i].GetBrojLinije() << endl;
            if (_raspored[i].GetBrojLinije() == line.GetBrojLinije())
                return false;
        }

        if (_trenutnoLinija > maxBrojLinija)
            return false;
            
       
        _raspored[_trenutnoLinija++] = line;
        return true;
        

           
           
    
        cout << "hello" << endl;
    }


    /*Funkcija RezervisiKarte treba da rezerviše određeni broj karata za odredište koje je
    proslijeđeno kao parametar. Ukoliko odredište nije pronađeno ili nije moguće rezervisati sve karte,
    funkcija vraća logičku vrijednost false, a u suprotnom vraća true.*/


    bool RezervisiKarte(const char* dest, int rez)
    {

        for (int i = 0; i < maxBrojLinija; i++)
        {

            if (strcmp(_raspored[i].GetOdrediste(), dest) == 1) {
                if (rez < GetBrojDostupnihKarata(dest)) {
                    _raspored[i].setRezMjesta(rez);
                    return true;
                }
               
            }

        }

        return false;

    }

    int GetBrojDostupnihKarata(const char* imeGrada) {
        for (int i = 0; i < maxBrojLinija; i++)
        {
            if (strcmp(_raspored[i].GetOdrediste(), imeGrada) == 1) {
                return _raspored[i].Getseats() - _raspored[i].Getrez();
            }
        }
    }

    void Ispis() {

        cout << "here we'll print the output" << endl;
    }
    //Implementirati funkcije potrebne za rad sa klasom
    //Implementirati destruktor
};

int main()
{
    //Kreiranje instanci klase AutobuskaLinija sa definisanjem: broja linije, odredišta i kapaciteta (broj mjesta)
    AutobuskaLinija L1(1, "Zagreb", 30);
    AutobuskaLinija L2(2, "Sarajevo", 25);
    AutobuskaLinija L3(3, "Čapljina", 30);
    AutobuskaLinija L4(4, "Tuzla", 25);
    AutobuskaLinija L5(5, "Konjic", 50);

    //Kreiranje instance klase RedVoznje
    RedVoznje redVoznje;
    /*
    Funkcija DodajAutobuskuLiniju evidentira novu autobusku liniju u red voznje.

    Autobuska linija sa istim brojem ne može biti dodana više puta u isti red vožnje.

    Maksimalan broj autobuskih linija također ne smije biti prekoračen.

    Funkcija, u zavisnosti od uspješnosti dodavanja autobuske linije, vraća logičku vrijednost true ili false
    */
    if (redVoznje.DodajAutobuskuLiniju(L1))
        cout << "Autobuska linija sa brojem " << L1.GetBrojLinije() << " za " << L1.GetOdrediste() << " uspjesno evidentirana." << endl;

    if (redVoznje.DodajAutobuskuLiniju(L2))
        cout << "Autobuska linija sa brojem " << L2.GetBrojLinije() << " za " << L2.GetOdrediste() << " uspjesno evidentirana." << endl;

    cout << crt;
    if (!redVoznje.DodajAutobuskuLiniju(L1))
        cout << "Autobuska linija sa brojem " << L1.GetBrojLinije() << " je vec evidentirana ili ste dostigli maksimalan broj linija u redu voznje." << endl;
    cout << crt;

    if (redVoznje.DodajAutobuskuLiniju(L3))
        cout << "Autobuska linija sa brojem " << L3.GetBrojLinije() << " za " << L3.GetOdrediste() << " uspjesno evidentirana." << endl;

    if (redVoznje.DodajAutobuskuLiniju(L4))
        cout << "Autobuska linija sa brojem " << L4.GetBrojLinije() << " za " << L4.GetOdrediste() << " uspjesno evidentirana." << endl;

    if (redVoznje.DodajAutobuskuLiniju(L5))
        cout << "Autobuska linija sa brojem " << L5.GetBrojLinije() << " za " << L5.GetOdrediste() << " uspjesno evidentirana." << endl;

    cout << crt;

    /*Funkcija Ispis vrši ispis svih podataka o autobuskim linijama u sklopu jednog reda vožnje.*/

    //redVoznje.Ispis();




    /*Funkcija RezervisiKarte treba da rezerviše određeni broj karata za odredište koje je
    proslijeđeno kao parametar. Ukoliko odredište nije pronađeno ili nije moguće rezervisati sve karte,
    funkcija vraća logičku vrijednost false, a u suprotnom vraća true.*/

    if (redVoznje.RezervisiKarte("Tuzla", 4))
        cout << "Vase karte su uspjesno rezervisane." << endl;

    /*Za ispis broja dostupnih karata implementirati funkciju GetBrojDostupnihKarata, koja na osnovu odredišta
    primljenog kao parametar vraća broj dostupnih karata pronađene autobuske linije.*/

    if (!redVoznje.RezervisiKarte("Konjic", 60))
    cout << "Rezervacija karata nije uspjela. Dostupno karata: " << redVoznje.GetBrojDostupnihKarata("Konjic") << endl;
    
    return 0;
}