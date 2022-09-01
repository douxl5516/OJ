#include <stack>
#include <iostream>
using namespace std;
class CQueue {
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {

    }

    void appendTail(int value) {
        s1.push(value);
    }

    int deleteHead() {
        if(s2.empty()){
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int res=s2.top();
        s2.pop();
        return res;
    }
};

int main(){
    CQueue* obj = new CQueue();
    obj->appendTail(1);
    obj->appendTail(2);
    obj->appendTail(3);
    int param_2 = obj->deleteHead();
    obj->appendTail(4);
    int param_3=obj->deleteHead();
    cout<<param_2<<endl;
    cout<<param_3<<endl;
}
