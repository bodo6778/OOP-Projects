#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <iterator>
#include <tuple>

using namespace std;

class film{
private:
    int durata;
    string nume, tip;
public:
    film(){
        durata = 0;
        nume = "";
        tip = "";
    }

    film(int d, string n, string t){
        durata = d;
        nume = n;
        tip = t;
    }

    ~film(){};

    friend ostream & operator << (ostream &out, const film &f){
        out << "Filmul: " << f.nume << " | Tip: " << f.tip << " | Durata: " << f.durata;
        return out;
    }

    friend istream & operator >> (istream &in, film &f){
        cout << "Nume film: ";
        getline(in, f.nume);
        cout << "Tip: ";
        getline(in, f.tip);
        cout << "Durata: ";
        in >> f.durata;
        in.get();
        return in;
    }

    film & operator = (const film &f){
        if (this == &f){
            return *this;
        }
        nume = f.nume;
        tip = f.tip;
        durata = f.durata;
        return *this;
    }


};

#endif // FILM_H_INCLUDED
