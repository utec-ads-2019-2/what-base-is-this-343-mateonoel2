#include <iostream>
#include <cmath>
#include <string>
#define unt unsigned int
using namespace std;

bool esNum(char x){
    char numeros[10] = {'0','1','2','3','4','5','6','7','8','9'};
    for(char c : numeros)
        if (x == c)
            return true;
    return false;
}

unt charToNum(char x){
    if(esNum(x)) return x - 48;
    else return x - 55;
}

unt base10(string num, unt base) {
    unt numero = 0;
    unt power = 0;
    unt resultado = 0;
    for(int i = num.size()-1; i >= 0; --i){
        numero = charToNum(num[i]);
        resultado += numero * pow(base, power);
        power++;
    }
    return resultado;
}

unt minBase(const string& number){
    char maxChar = '1';
    for(char c : number){
        if(maxChar < c){
            maxChar = c;
        }
    }
    return charToNum(maxChar) + 1;
}

void searchComonBase(const string& x, const string& y){
    unt xBase = minBase(x);
    unt yBase = minBase(y);
    for(unt i = xBase; i<=36; i++){
        for(unt j = yBase; j<=36; j++){
            if(base10(x, i) == base10(y, j)){
                cout<< x <<" (base "<<i<<") = "<< y <<" (base "<<j<<")\n";
                return;
            }
        }
    }
    cout<<x<<" is not equal to "<<y<<" in any base 2..36\n";
}

int main() {
    string x;
    string y;
    while(cin>>x>>y){
        searchComonBase(x, y);
    }
    return 0;
}