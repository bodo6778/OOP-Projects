#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <iterator>
#include <tuple>
#include "film.h"
#include "persoana.h"
#include "firma.h"

using namespace std;

int main(){
    FirmaDistributie<int> firma;
    firma.afisareInformatii();

    persoana *act = new actor; // RTTI sort of
    persoana *pers = dynamic_cast<persoana*>(act);
    if(pers != NULL)
        cout<<"It is working";
    else
        cout<<"cannot cast persoana* to actor*";
    return 0;
}
