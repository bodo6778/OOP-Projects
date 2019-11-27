#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include <math.h>

using namespace std;

struct nod{
    int inf;
    nod *urm;
};

class Vector{
    protected:
        nod *cap,*coada; // cap = primul, u = ultimul;
    public:
        Vector(){
            cap = NULL;
            coada = NULL;
        }

        ~Vector(){
            nod *tmp = new nod;
            while (cap != NULL){
                tmp = cap;
                cap = cap->urm;
                delete tmp;
            }
        }

        void adauga_nod_final(int x){
            nod *tmp = new nod;
            tmp->inf = x;
            tmp->urm = NULL;
            if (cap == NULL){
                cap = tmp;
                coada = tmp;
                tmp = NULL;
            } else {
                coada->urm = tmp;
                coada = tmp;
            }
        }

        void adauga_nod_inceput(int x){
            nod *tmp = new nod;
            tmp->inf = x;
            tmp->urm = NULL;
            if (cap == NULL){
                cap = tmp;
                coada = tmp;
                tmp = NULL;
            } else {
                tmp->urm = cap;
                cap = tmp;
            }
        }

        void adaugare_nod_index(int pos, int x){
            nod *pre = new nod;
            nod *curr = new nod;
            nod *tmp = new nod;
            tmp->inf = x;
            tmp->urm = NULL;
            curr = cap;

            for (int i = 1; i < pos; i++){
                pre = curr;
                curr = curr->urm;
            }
            pre->urm = tmp;
            tmp->urm = curr;
        }

        void afisare_lista(){
            nod *tmp = new nod;
            tmp = cap;
            while (tmp != NULL){
                cout<<tmp->inf<<" ";
                tmp = tmp->urm;
            }

        }

        int lungime_lista(){
            nod *tmp = new nod;
            tmp = cap;
            int nr;
            while (tmp != NULL){
                nr++;
                tmp = tmp->urm;
            }
            return nr;
        }

        int returnare_element_dupa_pozitie(int index){
            if (cap == NULL){
                cout<<"Lista nedefinita";
                return -1;
            }
            nod *tmp = new nod;
            tmp = cap;
            for (int i = 1; i < index; i++)
                tmp = tmp->urm;
            if(tmp == NULL){
                cout<<"Index out of scope";
                return -1;
            }
            return tmp->inf;
        }

        void stergere(){
            nod *tmp = new nod;
            while (cap != NULL){
                tmp = cap;
                cap = cap->urm;
                delete tmp;
            }
        }

        friend ostream & operator << (ostream &out, const Vector &v)
        {
            nod *tmp = new nod;
            tmp = v.cap;
            while (tmp != NULL){
                out << tmp->inf << " ";
                tmp = tmp->urm;
            }
            return out;
        }

        friend istream & operator >> (istream &in, Vector &v){
            int x;
            in >> x;
            while(x){
                v.adauga_nod_final(x);
                in >> x;

            }
            return in;
        }

        int & operator [] (int index){
            if (cap == NULL){
                exit(1);
            }
            nod *tmp = new nod;
            tmp = cap;
            for (int i = 1; i < index; i++)
                tmp = tmp->urm;
            if(tmp == NULL){
                exit(1);
            }
            return tmp->inf;
        }

        Vector & operator = (const Vector &w){
            if (this == &w)
                return *this;
            stergere();
            nod *tmp1 = new nod;
            tmp1 = w.cap;
            while(tmp1 != NULL){
                adauga_nod_final(tmp1->inf);
                tmp1=tmp1->urm;
            }
            return *this;
        }

        void afisare_fara_spatii(){
            nod *tmp = new nod;
            tmp = cap;
            while (tmp != NULL){
                cout << tmp->inf;
                tmp = tmp->urm;
            }
        }

        int toInt(){
            int x = 0;
            nod *tmp = new nod;
            tmp = cap;
            while (tmp != NULL){
                x = (x * 10) + tmp->inf;
                tmp = tmp->urm;
            }
            return x;
        }

};


#endif // VECTOR_H_INCLUDED
