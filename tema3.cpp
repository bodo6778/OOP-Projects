#include <iostream>
#include <vector>
#include <string>
#include <set>
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
        cout << "Nume: ";  
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

class persoana{
protected: 
    int cnp, castig;
    string nume, nume_film;
public:
    persoana(){
        cnp = 0;
        castig = 0;
        nume = "";
        nume_film = "";
    }

    persoana(int cn, int ca, string n, string nf){
        cnp = cn;
        castig = ca;
        nume = n;
        nume_film = nf;
    }

    ~persoana(){};

    virtual ostream & operator << (ostream &out){
        out << "Nume: " << nume << " | CNP: " << cnp << " | Nume film: " << nume_film << " | Castig: " << castig << endl;
        return out;
    }

    virtual istream & operator >> (istream &in){
        cout << "Nume: ";  
        getline(in, nume);
        cout << "Nume film: ";  
        getline(in, nume_film);
        cout << "CNP: ";
        in >> cnp;  
        cout << "Castig: "; 
        in >> castig;
        in.get();
        return in;
    }

    virtual persoana & operator = (const persoana &p){
        if (this == &p)
            return *this;
        else{
            nume = p.nume;
            nume_film = p.nume_film;
            cnp = p.cnp;
            castig = p.castig;
            return *this;
        }
    }
};

class actor : public persoana {
private:
    const float bonus = 0.1;
    bool principal;
public:
    actor(){
        principal = false;
        cnp = 0;
        castig = 0;
        nume = "";
        nume_film = "";
    }
    
    actor(int cn, int ca, string n, string nf, bool p){
        cnp = cn;
        castig = ca + ca * bonus;
        nume = n;
        nume_film = nf;
        principal = p;
    }

    ~actor(){}

    friend istream & operator >> (istream &in, actor &a){
        cout << "Nume: ";  
        getline(in, a.nume);
        cout << "Nume film: ";  
        getline(in, a.nume_film);
        cout << "CNP: ";
        in >> a.cnp;  
        cout << "Castig: "; 
        in >> a.castig;
        in.get();
        cout << "Principal (y/n): ";
        string p;
        getline(in, p);
        if(p == "y")
            a.principal = true;
        if (a.principal == true)
            a.castig = a.castig + a.castig * a.bonus; 
        return in;
    }

    friend ostream & operator << (ostream &out, actor &a){
        out << "Nume: " << a.nume << " | CNP: " << a.cnp << " | Nume film: " << a.nume_film << " | Castig: " << a.castig;
        if (a.principal == true)
            out << " | Principal: DA";
        else
            out << " | Principal: NU";
        return out;
    }

    persoana & operator = (const actor &a){
        if (this == &a)
            return *this;
        else{
            nume = a.nume;
            nume_film = a.nume_film;
            cnp = a.cnp;
            castig = a.castig;
            principal = a.principal;
            return *this;
        }
    }
};

class regizor : public persoana{
private:
    const int bonus = 1000; //k euro
public:
    regizor(){
        cnp = 0;
        castig = 0;
        nume = "";
        nume_film = "";
    }
    
    regizor(int cn, int ca, string n, string nf){
        cnp = cn;
        castig = ca + ca * bonus;
        nume = n;
        nume_film = nf;
    }

    ~regizor(){}

    friend istream & operator >> (istream &in, regizor &a){
        cout << "Nume: ";  
        getline(in, a.nume);
        cout << "Nume film: ";  
        getline(in, a.nume_film);
        cout << "CNP: ";
        in >> a.cnp;  
        cout << "Castig: "; 
        in >> a.castig;
        a.castig = a.castig + a.bonus;
        in.get();
        return in;
    }

    friend ostream & operator << (ostream &out, regizor &a){
        out << "Nume: " << a.nume << " | CNP: " << a.cnp << " | Nume film: " << a.nume_film << " | Castig: " << a.castig << endl;
        return out;
    }

    persoana & operator = (const regizor &a){
        if (this == &a)
            return *this;
        else{
            nume = a.nume;
            nume_film = a.nume_film;
            cnp = a.cnp;
            castig = a.castig;
            return *this;
        }
    }
};

template<typename T>
class FirmaDistributie{
private:
};

int main(){
    persoana p;
    actor a;
    return 0;
}