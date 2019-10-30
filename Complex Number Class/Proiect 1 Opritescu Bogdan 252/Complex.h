#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED

#include <iostream>
#include <math.h>
#include <complex>
#include <vector>

using namespace std;

class Complex{
    private:
        double re,im;
    public:
        //constructor
        Complex (double re = 0, double im = 0){
            this->re = re;
            this->im = im;
        }

        //copy constructor
        Complex (const Complex &c2){
            re = c2.re;
            im = c2.im;
        }

        //getter
        void get_nr_Complex(){
            cout<<re<<"+i"<<im<<endl;
        }

        double get_real(){
            return re;
        }

        double get_imaginar(){
            return im;
        }

        //setter
        void set_real(double reSet){
            re = reSet;
        }

        void set_imaginar(double imSet){
            im = imSet;
        }

        //overload operatori
        friend ostream & operator << (ostream &out, const Complex &c);
        friend istream & operator >> (istream &in,  Complex &c);
        friend Complex operator + (Complex const &);
        friend Complex operator - (Complex const &);
        friend Complex operator + (Complex const &, Complex const &);
        friend Complex operator + (double const &, Complex const &);
        friend Complex operator + (Complex const &, double const &);
        friend Complex operator - (Complex const &, Complex const &);
        friend Complex operator - (double const &, Complex const &);
        friend Complex operator - (Complex const &, double const &);
        friend Complex operator / (Complex const &, Complex const &);
        friend Complex operator / (double const &, Complex const &);
        friend Complex operator / (Complex const &, double const &);
        friend Complex operator * (Complex const &, Complex const &);
        friend Complex operator * (double const &, Complex const &);
        friend Complex operator * (Complex const &, double const &);
        friend bool operator == (Complex const &, Complex const &);
        friend bool operator == (double const &, Complex const &);
        friend bool operator == (Complex const &, double const &);
        friend bool operator != (Complex const &, Complex const &);
        friend bool operator != (double const &, Complex const &);
        friend bool operator != (Complex const &, double const &);
        friend Complex operator ^ (Complex const &, int const &);
        friend Complex operator += (Complex const &, double const &);
        friend Complex operator += (Complex const &, Complex const &);
        friend Complex operator -= (Complex const &, double const &);
        friend Complex operator -= (Complex const &, Complex const &);
        friend Complex operator /= (Complex const &, double const &);
        friend Complex operator /= (Complex const &, Complex const &);
        friend Complex operator *= (Complex const &, double const &);
        friend Complex operator *= (Complex const &, Complex const &);
        friend double abs (Complex const &);
        friend std::complex<double> sqrt (Complex const &);



};

ostream & operator << (ostream &out, const Complex &c)
{
    if (c.re != 0)
        out << c.re;
    if (c.im > 0)
        out << "+i" <<c.im;
    if (c.im < 0)
        out << "-i" <<-c.im;
    out << endl;
    return out;
}

istream & operator >> (istream &in,  Complex &c)
{
    cout << "Parte reala: ";
    in >> c.re;
    cout << "Parte imaginara: ";
    in >> c.im;
    return in;
}

Complex operator + (Complex const &c){
    return Complex(c.re, c.im);
}

Complex operator - (Complex const &c){
    return Complex(-c.re, -c.im);
}

Complex operator + (Complex const &c1, Complex const &c2){
    return Complex(c1.re + c2.re, c1.im + c2.im);
}

Complex operator + (double const &c1, Complex const &c2){
    return Complex(c1 + c2.re, c2.im);
}

Complex operator + (Complex const &c1, double const &c2){
    return Complex(c1.re + c2, c1.im);
}

Complex operator - (Complex const &c1, Complex const &c2){
    return Complex(c1.re - c2.re, c1.im - c2.im);
}

Complex operator - (double const &c1, Complex const &c2){
    return Complex(c1 - c2.re, -c2.im);
}

Complex operator - (Complex const &c1, double const &c2){
    return Complex(c1.re - c2, c1.im);
}

Complex operator / (Complex const &c1, Complex const &c2){
    return Complex((c1.re * c2.re + c1.im * c2.im) / (c2.re * c2.re + c2.im * c2.im), (c2.re * c1.im - c1.re * c2.im) / (c2.re * c2. re + c2.im * c2.im));
}

Complex operator / (double const &c1, Complex const &c2){
    return Complex((c1 * c2.re + c1 * c2.im) / (c2.re * c2.re + c2.im * c2.im), (c2.re * c1 - c1 * c2.im) / (c2.re * c2. re + c2.im * c2.im));
}

Complex operator / (Complex const &c1, double const &c2){
    return Complex(c1.re / c2, c1.im / c2);
}

Complex operator * (Complex const &c1, Complex const &c2){
    return Complex(c1.re * c1.im - c2.re * c2.im, c1.re * c2.im + c1.re * c2.im + c1.im * c2.re);
}

Complex operator * (double const &c1, Complex const &c2){
    return Complex(c1 * c2.re, c1 * c2.im);
}

Complex operator * (Complex const &c1, double const &c2){
    return Complex(c1.re * c2, c1.im * c2);
}

bool operator == (Complex const &c1, Complex const &c2){
    if (c1.re == c2.re && c1.im == c2.im)
        return true;
    return false;
}

bool operator == (double const &c1, Complex const &c2){
    if (c1 == c2.re && 0 == c2.im)
        return true;
    return false;
}

bool operator == (Complex const &c1, double const &c2){
    if (c1.re == c2 && c1.im == 0)
        return true;
    return false;
}

bool operator != (Complex const &c1, Complex const &c2){
    if (c1.re == 0 && c1.im == c2.im)
        return false;
    return true;
}

bool operator != (double const &c1, Complex const &c2){
    if (c1 == c2.re && 0 == c2.im)
        return false;
    return true;
}

bool operator != (Complex const &c1, double const &c2){
    if (c1.re == 0 && c1.im == c2)
        return false;
    return true;
}

Complex operator ^ (Complex const &c1, int const &c2){
    return Complex(pow(c1.re, c2), pow(c1.im, c2));
}

Complex operator += (Complex const &c1, Complex const &c2){
    return Complex(c1.re + c2.re, c1.im + c2.im);
}

Complex operator += (Complex const &c1, double const &c2){
    return Complex(c1.re + c2, c1.im);
}

Complex operator -= (Complex const &c1, Complex const &c2){
    return Complex(c1.re - c2.re, c1.im - c2.im);
}

Complex operator -= (Complex const &c1, double const &c2){
    return Complex(c1.re - c2, c1.im);
}

Complex operator /= (Complex const &c1, Complex const &c2){
    return Complex((c1.re * c2.re + c1.im * c2.im) / (c2.re * c2.re + c2.im * c2.im), (c2.re * c1.im - c1.re * c2.im) / (c2.re * c2. re + c2.im * c2.im));
}

Complex operator /= (Complex const &c1, double const &c2){
    return Complex(c1.re / c2, c1.im / c2);
}

Complex operator *= (Complex const &c1, Complex const &c2){
    return Complex(c1.re * c1.im - c2.re * c2.im, c1.re * c2.im + c1.re * c2.im + c1.im * c2.re);
}

Complex operator *= (Complex const &c1, double const &c2){
    return Complex(c1.re * c2, c1.im * c2);
}

double abs (Complex const &c){
    return sqrt(c.re * c.re + c.im * c.im);
}

std::complex<double> sqrt (Complex const &c){
    return sqrt(std::complex<double>(c.re, c.im));
}




#endif // COMPLEX_H_INCLUDED
