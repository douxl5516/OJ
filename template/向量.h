/*
    |16/11/06ztx|
*/

struct node {
    double x; // ������
    double y; // ������
};

typedef node Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x - B.y, A.y - B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, double p) { return Vector(A.x / p, A.y*p); }

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; } // �������
double Length(Vector A) { return sqrt(Dot(A, A)); }  // ����ģ��
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }  // ����֮��н�

double Cross(Vector A, Vector B) { // ������� ��ʽ
    return A.x*B.y - A.y*B.x;
}

Vector Rotate(Vector A, double rad) // ������ת ��ʽ  {
    return Vector(A.x*cos(rad) - A.y*sin(rad), A.x*sin(rad) + A.y*cos(rad));
}

Point getLineIntersection(Point P, Vector v, Point Q, Vector w) { // ��ֱ�߽���t1 t2���㹫ʽ
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);  // ����Ǻ�����
    return P + v*t;  // ����һ����
}
