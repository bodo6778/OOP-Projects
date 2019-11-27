#ifndef NUMAR_NATURAL_MARE_H_INCLUDED
#define NUMAR_NATURAL_MARE_H_INCLUDED

#include <iostream>
#include <math.h>
#include "vector.h"

using namespace std;

class numar_natural_mare{
    protected:
        int nrCif;
        Vector v;

        void int_to_object(int x){
            nrCif = 0;
            v.stergere();
            while(x){
                v.adauga_nod_inceput(x%10);
                x = x/10;
                nrCif++;
            }
        }
    public:
        numar_natural_mare(){
            nrCif = 0;
            Vector v;
        }

        numar_natural_mare(int x){
            while(x){
                v.adauga_nod_inceput(x%10);
                x = x/10;
                nrCif++;
            }
        }

        ~numar_natural_mare(){
            v.stergere();
            nrCif = 0;
        }

        int getNrCif(){
            return nrCif;
        }


        friend istream & operator >> (istream &in, numar_natural_mare &n){
            int x;
            in >> x;
            n.nrCif = 0;
            while(x){
                n.v.adauga_nod_inceput(x%10);
                x = x/10;
                n.nrCif++;
            }
            return in;
        }

        virtual ostream & operator << (ostream &out){
            v.afisare_fara_spatii();
            return out;
        }

        numar_natural_mare & operator = (const numar_natural_mare &other){
            if(this == &other)
                return *this;
            nrCif = other.nrCif;
            v = other.v;
            return *this;
        }

        numar_natural_mare & operator + (numar_natural_mare &other){
            int Z;
            Z = v.toInt() + other.v.toInt();
            int_to_object(Z);
            return *this;
        }

        numar_natural_mare & operator * (numar_natural_mare &other){
            int Z;
            Z = v.toInt() * other.v.toInt();
            int_to_object(Z);
            return *this;
        }

        numar_natural_mare & operator - (numar_natural_mare &other){
            if (v.toInt() >= other.v.toInt()){
                int Z;
                Z = v.toInt() - other.v.toInt();
                int_to_object(Z);
                return *this;
            } else {
                cout << "Numar negativ dupa scadere!";
                exit(1);
            }
        }

        numar_natural_mare & operator / (numar_natural_mare &other){
            int Z;
            Z = v.toInt() / other.v.toInt();
            int_to_object(Z);
            return *this;
        }

        bool operator == (numar_natural_mare &other){
            if (v.toInt() == other.v.toInt())
                return true;
            else
                return false;
        }

        bool operator != (numar_natural_mare &other){
            if (v.toInt() != other.v.toInt())
                return true;
            else
                return false;
        }

};

class numar_fibonacci_mare : public numar_natural_mare{
    public:
        numar_fibonacci_mare(){}
        ~numar_fibonacci_mare(){}

        friend ostream & operator << (ostream &out, numar_fibonacci_mare &n){
            n.v.afisare_fara_spatii();
            out << "=" << round(n.v.toInt() * 0.618) << "+" << round(n.v.toInt() - (n.v.toInt() * 0.618)) << endl;
            return out;
        }
};


#endif // NUMAR_NATURAL_MARE_H_INCLUDED
