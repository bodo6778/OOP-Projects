#include <iostream>
#include <string>
using namespace std;

class passPolicy{
private:
    int lengthMin, lengthMax;
    int classType;
    string included;
    string nincluded;
    int repetition;
    int consecutive;
public:
    passPolicy() : lengthMin(0), lengthMax(0), classType(0), nincluded(""), included(""), repetition(0), consecutive(0) {}
    passPolicy(int lm, int lM, int cT, string i, string ni, int r, int c) : lengthMin(lm), lengthMax(lM), classType(cT), nincluded(ni), included(i), repetition(r), consecutive(c) {}
    virtual ~passPolicy() {}

    void setLengthMin(int l){
        lengthMin = l;
    }

    void setLengthMax(int l){
        lengthMax = l;
    }

    void setClassType(int t){
        classType = t;
    }

    void setIncluded(string s){
        included.append(s);
    }

    void setNotIncluded(string s){
        nincluded.append(s);
    }

    void setRepetition(int r){
        repetition = r;
    }

    void setConsecutive(int c){
        consecutive = c;
    }

    bool passwordChecker(string s){
        if (lengthMin != 0 && s.length() < lengthMin){
            return false;
        }

        if (lengthMax != 0 && s.length() > lengthMax){
            return false;
        }

        if (classType != 0){
            size_t found;
            int numberOfTypes = 0;
            found = s.find_first_of("qwertyuiopasdfghjklzxcvbnm");
                    if (found != string::npos)
                        numberOfTypes++;
            found = s.find_first_of("QWERTYUIOPASDFGHJKLZXCVBNM");
                    if (found != string::npos)
                        numberOfTypes++;
            found = s.find_first_of("0123456789");
                    if (found != string::npos)
                        numberOfTypes++;
            found = s.find_first_of("!@#$%^&*().");
                    if (found != string::npos)
                        numberOfTypes++;
            if (numberOfTypes < classType) {
                return false;
            }
        }

        if (included.length() > 0){
            size_t found;
            for (int i = 0; i < included.length(); i++){
                if (included.at(i) == 'a'){
                    found = s.find_first_of("qwertyuiopasdfghjklzxcvbnm");
                    if (found == string::npos){
                        return false;
                    }
                }
                if (included.at(i) == 'A'){
                    found = s.find_first_of("QWERTYUIOPASDFGHJKLZXCVBNM");
                    if (found == string::npos){
                        return false;
                    }
                }
                if (included.at(i) == '0'){
                    found = s.find_first_of("0123456789");
                    if (found == string::npos){
                        return false;
                    }
                }
                if (included.at(i) == '$'){
                    found = s.find_first_of("!@#$%^&*().");
                    if (found == string::npos){
                        return false;
                    }
                }
            }
        }

        if (nincluded.length() > 0){
            for (int i = 0; i < nincluded.length(); i++){
                if (nincluded.at(i) == 'a'){
                    size_t found = s.find_first_of("qwertyuiopasdfghjklzxcvbnm");
                    if (found != string::npos){
                        return false;
                    }
                }
                if (nincluded.at(i) == 'A'){
                    size_t found = s.find_first_of("QWERTYUIOPASDFGHJKLZXCVBNM");
                    if (found != string::npos){
                        return false;
                    }
                }
                if (nincluded.at(i) == '0'){
                    size_t found = s.find_first_of("0123456789");
                    if (found != string::npos){
                        return false;
                    }
                }
                if (nincluded.at(i) == '$'){
                    size_t found = s.find_first_of("!@#$%^&*().");
                    if (found != string::npos){
                        return false;
                    }
                }
            }
        }

        if (repetition > 0){
            int repeated = 1;
            for (int i = 0; i < s.length() - 1; i++){
                if (s.at(i) == s.at(i+1))   repeated++;
                if (repeated > repetition){
                        return false;
                }
                if (s.at(i) != s.at(i+1))   repeated = 1;
            }
        }

        if (consecutive > 0){
            int repeated = 1;
            for (int i = 0; i < s.length() - 1; i++){
                if ((s[i] <= '9' && s[i] >= '0') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')){
                    if ((int)s.at(i)+1 == (int)s.at(i+1))   repeated++;
                    if (repeated > consecutive){
                        return false;
                    }
                    if ((int)s.at(i)+1 != (int)s.at(i+1)){
                        repeated = 1;
                    }
                }
            }

        }
        return true;
    }
};

int main(){
    int n;
    string str;
    cin >> n;
    passPolicy p;
    cin >> str;
    if (str == "length"){
        cin >> str;
        p.setLengthMin(stoi(str));
        cin >> str;
        if (str.find_first_of("0123456789") != string::npos){
            p.setLengthMax(stoi(str));
            cin >> str;
        }
    }

    if (str == "class"){
        cin >> str;
        p.setClassType(stoi(str));
        cin >> str;
    }

    while (str == "include"){
        cin >> str;
        p.setIncluded(str);
        cin >> str;
    }

    while (str == "ninclude"){
        cin >> str;
        p.setNotIncluded(str);
        cin >> str;
    }

    if (str == "consecutive"){
        cin >> str;
        p.setConsecutive(stoi(str));
        cin >> str;
    }

    if (str == "repetition"){
        cin >> str;
        p.setRepetition(stoi(str));
        cin >> str;
    }
    int nr= 0;
    if (p.passwordChecker(str) == true) cout << "OK\n"; else cout << "NOK\n";
    while(cin >> str){
        if (p.passwordChecker(str) == true) cout << "OK\n"; else cout << "NOK\n";
    }
    return 0;
}
