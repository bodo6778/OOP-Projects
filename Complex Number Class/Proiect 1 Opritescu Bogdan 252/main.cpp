#include <iostream>
#include <math.h>
#include <complex>
#include "Complex.h"

using namespace std;

//ecuatie grad 2
void ecuatie_coef_complex(Complex a, Complex b, Complex c){
    Complex r = b * b - 4 * a * c;
    Complex z1 = ( -b - r) / 2 * a;
    Complex z2 = ( -b + r) / 2 * a;
    cout<<"Radacinile ecuatiei sunt: \nz1 = "<<z1<<"z2 = "<<z2;
}

void citire_numere(){
            int x,i;
            cout<<"Cate numere complexe vor fi citite si afisate: "; cin>>x;
            Complex *c = new Complex[x+1];
            for (i = 1; i < x+1; i++){
                cin>>c[i];
            }
            for (i = 1; i < x+1; i++)
                cout<<c[i];
        }

int main(){
    Complex c1(4,0);
    Complex c2(0,6);
    Complex c3(0,-2);
    Complex c4(3,6);
    Complex c42(3,6);
    Complex c5(1,-3);
    int x = 0;
    cout<<"c1: "<<c1<<"c2: "<<c2<<"c3: "<<c3<<"c4: "<<c4<<"c5: "<<c5;
    cout<<"Adunare c1 + c2: "<<c1+c2;
    cout<<"Adunare c1 + 2: "<<c1+2;
    cout<<"Adunare 2 + c2: "<<2+c2;
    cout<<"Scadere c1 - c2: "<<c1-c2;
    cout<<"Scadere c4 - 2: "<<c4-2;
    cout<<"Scadere 2 - c4: "<<2-c4;
    cout<<"Impartire c1 / c2: "<<c1/c2;
    cout<<"Impartire c4 / 2: "<<c4/2;
    cout<<"Impartire 2 / c4: "<<2/c4;
    cout<<"Inmultire c1 * c2: "<<c1*c2;
    cout<<"Inmultire c4 * 2: "<<c4*2;
    cout<<"Inmultire 2 * c4: "<<2*c4;
    cout<<"+c4: "<<+c4;
    cout<<"-c4: "<<-c4;
    if (c4 == c42)
        cout<<"Test egalitate c4"<<endl;
    if (c1 == 4)
        cout<<"Test egalitate c1 == 4"<<endl;
    if (4 == c1)
        cout<<"Test egalitate 4 == c1"<<endl;
    if (c4 != c3)
        cout<<"Test neegalitate c4 != c3"<<endl;
    if (c1 != 5)
        cout<<"Test neegalitate c4 != 5"<<endl;
    if (5 != c1)
        cout<<"Test neegalitate 5 != c4"<<endl;
    c4 = c4 += c5;
    cout<<"Adunare c4 += c5: "<<c4;
    c4 = c42;
    c4 = c4 += 2;
    cout<<"Adunare c4 += 2: "<<c4;
    c4 = c42;
    c4 = c4 -= c5;
    cout<<"Scadere c4 -= c5: "<<c4;
    c4 = c42;
    c4 = c4 -= 2;
    cout<<"Scadere c4 -= 2: "<<c4;
    c4 = c42;
    c4 = c4 *= c5;
    cout<<"Inmultire c4 *= c5: "<<c4;
    c4 = c42;
    c4 = c4 *= 2;
    cout<<"Inmultire c4 *= 2: "<<c4;
    c4 = c42;
    c4 = c4 /= c5;
    cout<<"Impartire c4 /= c5: "<<c4;
    c4 = c42;
    c4 = c4 /= 2;
    cout<<"Impartire c4 /= 2: "<<c4;
    c4 = c42;
    cout<<"Modul de c4: "<<abs(c4)<<endl;
    cout<<"Radical de c4 "<<sqrt(c4)<<endl;
    cout<<"Polinom complex cu coeficientii c1, c2, c2: "<<endl;
    ecuatie_coef_complex(c1,c2,c3);
    citire_numere();
    return 0;
}
