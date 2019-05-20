/*
    |16/11/06ztx|
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>

using namespace std;

#define N 1000010

char str[N], keyword[N];
int head, tail;

struct node {
    node *fail;
    node *next[26];
    int count;
    node() { //init
        fail = NULL;// Ĭ��Ϊ��
        count = 0;
        for(int i = 0; i < 26; ++i)
            next[i] = NULL;
    }
}*q[N];

node *root;

void insert(char *str)  { // ����Trie
    int temp, len;
    node *p = root;
    len = strlen(str);
    for(int i = 0; i < len; ++i)  {
        temp = str[i] - 'a';
        if(p->next[temp] == NULL)
            p->next[temp] = new node();
        p = p->next[temp];
    }
    p->count++;
}

void build_ac() { // ��ʼ��failָ�룬BFS ����ģ����У�
    q[tail++] = root;
    while(head != tail)  {
        node *p = q[head++]; // ������ͷ
        node *temp = NULL;
        for(int i = 0; i < 26; ++i)  {
            if(p->next[i] != NULL)  {
                if(p == root) { // ��һ��Ԫ��fail��ָ���
                    p->next[i]->fail = root;
                }else {
                    temp = p->fail; // ʧ��ָ��
                    while(temp != NULL) { // 2�����������ƥ��Ϊ��or�ҵ�ƥ��
                        if(temp->next[i] != NULL) { // �ҵ�ƥ��
                            p->next[i]->fail = temp->next[i];
                            break;
                        }
                        temp = temp->fail;
                    }
                    if(temp == NULL) // Ϊ�����ͷƥ��
                        p->next[i]->fail = root;
                }
                q[tail++] = p->next[i]; // ���
            } } }
}

int query() // ɨ��
{
    int index, len, result;
    node *p = root; // Tire���
    result = 0;
    len = strlen(str);
    for(int i = 0; i < len; ++i)
    {
        index = str[i] - 'a';
        while(p->next[index] == NULL && p != root) // ��תʧ��ָ��
            p = p->fail;
        p = p->next[index];
        if(p == NULL)
            p = root;
        node *temp = p; // p������temp�����׺��
        while(temp != root && temp->count != -1)   {
            result += temp->count;
            temp->count = -1;
            temp = temp->fail;
        }
    }
    return result;
}

int main() {
    int num;
    head= tail = 0;
    root = new node();
    scanf("%d", &num);
    getchar();
    for(int i = 0; i < num; ++i) {
       scanf("%s",keyword);
        insert(keyword);
    }
    build_ac();
    scanf("%s", str);
    if(query())
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}

/*
    ������N��ģʽ����ƽ������ΪL�����³���ΪM�� ����Trie����O(N*L) ����failָ�룺O(N*L) ģʽƥ�䣺O(M*L) ���ԣ���ʱ�临�Ӷ�Ϊ:O( (N+M)*L )��
*/
