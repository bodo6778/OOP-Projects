#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class wbs{
private:
    int length, blockLength;
    string bits, compressedBits;
public:
    wbs(): length(0), blockLength(0), bits(""){}
    wbs(int l, int bl, string b): length(l), blockLength(bl), bits(b) {}
    ~wbs(){}
    
    friend istream & operator >> (istream &in, wbs &w){
        string str;
        in >> w.length;
        in >> w.blockLength;
        for (int i = 0; i < w.length; i++){
            in >> str;
            w.bits.append(str);
        }
        return in;
    }
    
    friend ostream & operator << (ostream &out, const wbs &w){
        out << w.bits;
        return out;
    }

    void showString(string &str, float rate){
        cout << rate << endl;
        for (int i = 0; i < str.length(); i++)
            cout << str[i] << endl;
    }

    void compress(){
        string compressOne = "1", compressZero = "0", aux;
        float compressRateOne, compressRateZero;
        int i = 0, j;

        // Compressing by ignoring the ones
        while (i < length){
            aux.append(bits, i, blockLength);
            if (aux.find_first_of("0") == string::npos && aux.length() == blockLength){
                compressOne.append("1");
            } else {
                compressOne.append("0");
                compressOne.append(aux);
            }
            aux = "";
            i = i + blockLength;
        }

        // Compressing by ignoring the zeros
        i = 0;
        while (i < length){
            aux.append(bits, i, blockLength);
            if (aux.find_first_of("1") == string::npos && aux.length() == blockLength){
                compressZero.append("0");
            } else {
                compressZero.append("1");
                compressZero.append(aux);
            }
            aux = "";
            i = i + blockLength;
        }
        compressRateZero = roundf((float)bits.length()/compressZero.length() * 100) / 100;
        compressRateOne = roundf((float)bits.length()/compressOne.length() * 100) / 100;
        if (compressRateZero >= compressRateOne)
            showString(compressZero, compressRateZero);
        else
            showString(compressOne, compressRateOne);
    }

};

int main(){
    wbs w;
    cin >> w;
    w.compress();
    return 0;
}