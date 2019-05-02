#include <iostream>
#include <string>
using namespace std;

int main() {
    int strlen;
    string s;
    cin>>strlen>>s;

    for (int i=1;i<strlen;i++){
        if(s.at(i)<s.at(i-1)) {
            cout << "YES" << endl << i <<" "<< i + 1 << endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;

    return 0;
}