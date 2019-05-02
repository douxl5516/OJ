#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int strlen;
    string number;
    cin>>strlen;
    cin >> number;
    int bound=strlen-11+1;
    int cnt=0;
    for (int i = 0; i <bound;i++){
        if (number.at(i)=='8'){
            cnt++;
        }
    }
    if (2*cnt>bound){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}