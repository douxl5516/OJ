#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    int val;
    node* next;
    node():val(0),next(nullptr){}
    node(int c):val(c),next(nullptr){}
} node_type;

node* create_list(){
    node* head=new node_type();
    node* cur_node=head;
    int a[]={1,10,2,9,3,8,4,7};

    for (int i=0;i<8;i++){
        node* new_node = new node_type(a[i]);
        cur_node->next=new_node;
        cur_node=new_node;
        cur_node->next = NULL;
    }
    node* result=head->next;
    delete head;
    return result;
}

void split_list(node * input_list, node * output_list_1, node * output_list_2){
    node * p_1 = output_list_1;
    node * p_2 = output_list_2;

    if (input_list == nullptr){
        return;
    }else if(input_list -> next == nullptr){
        p_1->next=input_list;
        return;
    }else{
        int cnt=0;
        while(input_list){
            if (cnt%2 == 0){
                p_1->next = input_list;
                p_1 = p_1-> next;
                input_list = input_list->next;
                p_1->next = nullptr;
            } else{
                p_2->next = input_list;
                p_2 = p_2->next;
                input_list = input_list->next;
                p_2->next = nullptr;
            }
            cnt+=1;
        }
    }
}

void revert(node* phead){
    node * p = phead->next;
    if(!p or !p->next){
        return;
    }
    node *p1=p, *p2=p->next;
    node * tmp=p2->next;
    p1->next = nullptr;
    p2->next = p1;
    p1=p2;
    p2=tmp;
    while(p2){
        tmp=p2->next;
        p2->next=p1;
        p1=p2;
        p2=tmp;
    }
    phead->next=p1;
}

void merge(node* out, node* in_1, node* in_2){
    node *pout=out, *p_in_1=in_1->next, *p_in_2=in_2->next;
    while(p_in_1 and p_in_2){
        if (p_in_1->val>p_in_2->val){
            pout->next=p_in_2;
            p_in_2=p_in_2->next;
            pout=pout->next;
            pout->next = nullptr;
        }else{
            pout->next=p_in_1;
            p_in_1=p_in_1->next;
            pout=pout->next;
            pout->next = nullptr;
        }
    }
    while(p_in_1){
        pout->next=p_in_1;
        p_in_1=p_in_1->next;
        pout=pout->next;
        pout->next = nullptr;
    }
    while(p_in_2){
        pout->next=p_in_2;
        p_in_2=p_in_2->next;
        pout=pout->next;
        pout->next = nullptr;
    }
}

int main(){
    node * list = create_list();
    node * list_odd = new node();
    node * list_even = new node();
    node * list_final = new node();
    split_list(list,list_odd,list_even);
    revert(list_even);
    merge(list_final,list_odd,list_even);

    list_final=list_final->next;
    while(list_final){
        cout<<list_final->val<<endl;
        list_final=list_final->next;
    }
}