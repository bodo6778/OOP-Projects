#ifndef FIRMA_H_INCLUDED
#define FIRMA_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <iterator>
#include <tuple>
#include "film.h"
#include "persoana.h"
using namespace std;




template<typename T>
class FirmaDistributie{
private:
    static int persoane;
    int actori = 0;
    T s;
public:
    FirmaDistributie(){
    }

    vector<tuple <persoana,film,int> > getFilme(){
        int nFilme,nPersoane,nActori;
        film f;
        actor a;
        persoana p;
        vector<tuple <persoana,film,int> > filme;
        cout << "Numarul de filme din acest an: "; cin >> nFilme;
        cin.get();
        for (int i = 0; i < nFilme; i++){
            cin >> f;
            cout << "Numar persoane din staff: "; cin >> nPersoane;
            cin.get();
           for (int j = 0; j < nPersoane; j++){
                cin >> p;
                //persoane++;
                filme.push_back(make_tuple(p,f,p.getCastig()));
           }
           cout << endl;
           cout << "Numar actori: "; cin >> nActori;
           cin.get();
           cout << actori;
           for (int j = 0; j < nActori; j++){
                cin >> a;
                filme.push_back(make_tuple(a,f,a.getCastig()));
           }
           cout << endl << "   ----------------------" << endl;
        }

        return filme;
    }

    void afisareInformatii(){
        auto filmea = getFilme();
        for (auto itr : filmea){
            cout << get<0>(itr);
        }
    }
};


#endif // FIRMA_H_INCLUDED
