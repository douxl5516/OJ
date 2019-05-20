/*
    |16/11/06ztx|
*/

struct node {
    double x; // 横坐标
    double y; // 纵坐标
};

typedef node Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x - B.y, A.y - B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y*p); }

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; } // 向量点乘
double Length(Vector A) { return sqrt(Dot(A, A)); }  // 向量模长
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }  // 向量之间夹角

double Cross(Vector A, Vector B) { // 叉积计算 公式
    return A.x*B.y - A.y*B.x;
}

Vector Rotate(Vector A, double rad) // 向量旋转 公式  {
    return Vector(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad));
}

Point getLineIntersection(Point P, Vector v, Point Q, Vector w) { // 两直线交点t1 t2计算公式
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);  // 求得是横坐标
    return P + v*t;  // 返回一个点
}
