/*
    |16/11/06ztx|
*/

node P[35][105];

double Cross_Prouct(node A,node B,node C) {     //  计算BA叉乘CA
    return (B.x-A.x)*(C.y-A.y)-(B.y-A.y)*(C.x-A.x);
}
bool Intersect(node A,node B,node C,node D)  {  //  通过叉乘判断线段是否相交；
    if(min(A.x,B.x)<=max(C.x,D.x)&&         //  快速排斥实验；
       min(C.x,D.x)<=max(A.x,B.x)&&
       min(A.y,B.y)<=max(C.y,D.y)&&
       min(C.y,D.y)<=max(A.y,B.y)&&
       Cross_Prouct(A,B,C)*Cross_Prouct(A,B,D)<0&&      //  跨立实验；
       Cross_Prouct(C,D,A)*Cross_Prouct(C,D,B)<0)       //  叉乘异号表示在两侧；
       return true;
    else return false;
}
