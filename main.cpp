#include <iostream>

using namespace std;

class Myyja
{
public:
    string etuNimi;
    string sukuNimi;
    string email;
    string puhelinNumero;

    Myyja()
    {
        etuNimi = "";
        sukuNimi = "";
        email = "";
        puhelinNumero = "";
    }

    Myyja(string etuNimi, string sukuNimi, string email, string puhelinNumero)
    {
        this->etuNimi = etuNimi;
        this->sukuNimi = sukuNimi;
        this->email = email;
        this->puhelinNumero = puhelinNumero;
    }

    void print()
    {
        cout << "Etunimi: " << etuNimi << endl;
        cout << "Sukunimi: " << sukuNimi << endl;
        cout << "Sähköposti: " << email << endl;
        cout << "Puhelinnumero: " << puhelinNumero << endl;
    }
};

class Tuote
{
public:
    string tuoteNumero;
    string tuoteNimi;
    string koko;
    double hinta;

    Tuote()
    {
        tuoteNumero = "";
        tuoteNimi = "";
        koko = "";
        hinta = 0;
    }
    Tuote(string tuoteNumero, string tuoteNimi, string koko, double hinta)
    {
        this->tuoteNumero = tuoteNumero;
        this->tuoteNimi = tuoteNimi;
        this->koko = koko;
        this->hinta = hinta;
    }

    void print()
    {
        cout << "Tuotenumero: " << tuoteNumero << endl;
        cout << "Tuotenimi: " << tuoteNimi << endl;
        cout << "Koko: " << koko << endl;
        cout << "Hinta: " << hinta << endl;
    }
};

class OstosKori
{
public:
    Myyja myyja;
    Tuote tuote;

    OstosKori()
    {
        myyja = Myyja();
        tuote = Tuote();
    }

    OstosKori(Myyja myyja, Tuote tuote)
    {
        this-> myyja = myyja;
        this-> tuote = tuote;
    }

    void print()
    {
        myyja.print();
        tuote.print();
    }
};

class OstosKoriSystem
{
public:
//
    OstosKori ostosKori;

    OstosKoriSystem()
    {
        ostosKori = OstosKori();
    }
    OstosKoriSystem(OstosKori ostosKori)
    {
        this-> ostosKori = ostosKori;
    }

    void print()
    {
        ostosKori.print();
    }
};

int main()
{
    OstosKoriSystem ostosKoriSystem;
    string etuNimi;
    string sukuNimi;
    string email;
    string puhelinNumero;
    string tuoteNumero;
    string tuoteNimi;
    string koko;
    double hinta;
    int valinta;

    while (true)
    {
        cout << "1. Lisää myyjän tiedot" << endl;
        cout << "2. Lisää tuotetiedot (Huom! käytä hinnan erottimena pistettä)" << endl;
        cout << "3. Myy tuote" << endl;
        cout << "4. Etsi tuote tuotenumerolla" << endl;
        cout << "5. Tulosta myyjän tiedot" << endl;
        cout << "6. Poistu" << endl;
        cout << "Syötä valinta: ";
        cin >> valinta;

        if(valinta == 1)
        {
            cout << "Syötä etunimi: ";
            cin >> etuNimi;
            cout << "Syötä sukunimi: ";
            cin >> sukuNimi;
            cout << "Syötä sähköposti: ";
            cin >> email;
            cout << "Syötä puhelinnumero: ";
            cin >> puhelinNumero;
            Myyja myyja(etuNimi, sukuNimi, email, puhelinNumero);
            ostosKoriSystem.ostosKori.myyja = myyja;
        }
         else if (valinta == 2)
        {
            cout << "Syötä tuotenumero: ";
            cin >> tuoteNumero;
            cout << "Syötä tuotenimi: ";
            cin >> tuoteNimi;
            cout << "Syötä koko: ";
            cin >> koko;
            cout << "Syötä hinta: ";
            cin >> hinta;
            Tuote tuote(tuoteNumero, tuoteNimi, koko, hinta);
            ostosKoriSystem.ostosKori.tuote = tuote;
        }
        else if (valinta == 3)
        {
            ostosKoriSystem.print();
        }
        else if (valinta == 4)
        {
            cout << "Syötä tuotenumero: ";
            cin >> tuoteNumero;
            Tuote tuote = ostosKoriSystem.ostosKori.tuote;
            if (tuote.tuoteNumero == tuoteNumero)
            {
                tuote.print();
            }
            else
            {
                cout << "Tuotetta ei löydy" << endl;
            }
        }
        else if (valinta == 5)
        {
            Myyja myyja = ostosKoriSystem.ostosKori.myyja;
            myyja.print();
        }
        else if (valinta == 6)
        {
            break;
        }
        else
        {
            cout << "Epäkelpo valinta" << endl;
        }
    }
    return 0;
}
