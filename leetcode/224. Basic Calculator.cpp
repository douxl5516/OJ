#include <iostream>
#include <stack>
using namespace std;
//Input: s = "1 + 1"
//Output: 2
//Input: s = " 2-1 + 2 "
//Output: 3
//Input: s = "(1+(4+5+2)-3)+(6+8)"
//Output: 23
//1 <= s.length <= 3 * 105
//s consists of digits, '+', '-', '(', ')', and ' '.
//s represents a valid expression.
//'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
//'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
//There will be no two consecutive operators in the input.
//Every number and running calculation will fit in a signed 32-bit integer.


class Solution {
public:
    int calculate(string s) {
        stack<int> st_num;  //数字栈
        stack<char> st_op;   //符号栈
        int num=0;
        for (int i=0;i<s.length();i++){
            char c=s[i];
            bool is_num=(c>='0' && c<='9');
            if (is_num){
               num*=10;
               num+=c-'0';
            }else{
                st_num.push(num);
                num=0;
                st_op.push(c);
            }
            if (st_op.top()=='+' || st_op.top()=='-'){
                int num_1=st_num.top();
                st_num.pop();
                int num_2=st_num.top();
                st_num.pop();
                char op=st_op.top();
                st_op.pop();
                if (op=='+') {
                    st_num.push(num_1 + num_2);
                }else if(op=='-'){
                    st_num.push(num_2-num_1);
                }
            }else if (st_op.top()==')'){

            }
        }
    }
};

int main(){
    Solution s;
    cout<<s.calculate("(1+(4+5+2)-3)+(6+8)")<<endl;
}