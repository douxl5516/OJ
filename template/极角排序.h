/*
    |16/11/06ztx|
*/

double cross(point p1, point p2, point q1, point q2) {  // �������
    return (q2.y - q1.y)*(p2.x - p1.x) - (q2.x - q1.x)*(p2.y - p1.y);
}
bool cmp(point a, point b)  {
    point o;
    o.x = o.y = 0;
    return cross(o, b, o, a) < 0; // ����ж�
}
sort(convex + 1, convex + cnt, cmp); // ��������, ��С����
