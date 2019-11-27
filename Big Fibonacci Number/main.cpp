#include <iostream>
#include "numar_natural_mare.h"

using namespace std;

int main()
{
    int i,x;
    cout<<"Primele 22 de numere din sirul Fibonacci sunt: 0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946\n";
    cout<<"Cate numere fibonacci vor fi citite si afisate: "; cin>>x;
    numar_fibonacci_mare *n = new numar_fibonacci_mare[x+1];
    for(i = 1; i < x+1; i++)
        cin>>n[i];
    for(i = 1; i < x+1; i++)
        cout<<n[i];
    return 0;
}
