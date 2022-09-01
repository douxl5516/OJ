//
// Created by Admin on 2022/8/26.
//

#include <iostream>
#include <vector>
using namespace std;


int solution(vector<int> &A, vector<int> &B) {
    // write your code in C++ (C++14 (g++ 6.2.0))
    unordered_map<int,bool> exist;
    for (int i=0;i<A.size();i++){
        exist[max(A[i],B[i])]=true;
    }
    for (int i=1;i<=A.size()+1;i++){
        if (exist.find(i)==exist.end()){
            return i;
        }
    }
}

