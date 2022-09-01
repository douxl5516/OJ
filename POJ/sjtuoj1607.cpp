
#include <iostream>

using namespace std;


template<class T>
class queue{
public:
    virtual bool isEmpty()const =0;
    virtual void enQueue(const T &x)=0;
    virtual T deQueue()=0;
    virtual T getHead()const=0;
    virtual ~queue(){}

} ;

template<class T>
class seqQueue:public queue<T>{
private:
    T *elem;
    int maxsize;
    int front,rear;
    void doubleSpace();

public:
    seqQueue(int size=10);
    ~seqQueue();
    bool isEmpty()const;
    void enQueue(const T &x);
    T deQueue();
    T getHead()const;
};


template<class T>
seqQueue<T>::seqQueue(int size){
    elem=new T[size];
    maxsize=size;
    front=rear=0;
}


template<class T>
seqQueue<T>::~seqQueue(){
    delete []elem;
}

template<class T>
bool seqQueue<T>::isEmpty()const{
    return front==rear;
}
template<class T>
T seqQueue<T>::deQueue(){
    front=(front+1)%maxsize;
    return elem[front];
}

template<class T>
T seqQueue<T>::getHead()const{
    return elem[(front+1)%maxsize];
}
template<class T>
void seqQueue<T>::enQueue(const T &x){
    if((rear+1)%maxsize==front) doubleSpace();

    rear=(rear+1)%maxsize;
    elem[rear]=x;
}
template<class T>
void seqQueue<T>::doubleSpace(){
    T *tmp=elem;

    elem=new T[2*maxsize];
    for(int i=1;i<maxsize-1;++i){elem[i]=tmp[(front+i)%maxsize];}
    front=0;rear=maxsize-1;
    maxsize*=2;
    delete tmp;
}

template<class T>
class linkQueue:public queue<T>{
private:
    struct node{
        T data;
        node *next;
        node(const T &x,node *N=NULL){data=x;next=N;}
        node():next(NULL){}
        ~node(){}
    };

    node *front,*rear;

public:
    linkQueue();
    ~linkQueue();
    bool isEmpty()const;
    void enQueue(const T &x);
    T deQueue();
    T getHead()const;
    void insert(T &x,int location);
    node *find(int location)const;
    int finddex(T &x)const;
};
template<class T>
typename linkQueue<T>::node *linkQueue<T>::find(int location)const{
    node *p;
    p=front;
    while(--location>=0) {

        p=p->next;
    }
    return p;
}

template<class T>
void linkQueue<T>::insert(T &x,int location){
    node *tmp=find(location);
    node *del=tmp->next;
    tmp->next=new node(x);
    tmp->next->next=del;
}

template<class T>
int linkQueue<T>::finddex(T &x)const{
    node *p=front;
    int dex=-1;
    if(!p) return -1;
    int i=0;

    while(p!=NULL){
        if(p->data==x) dex=i;
        ++i;
        p=p->next;
    }

    return dex;
}

template<class T>
linkQueue<T>::linkQueue(){
    front=rear=NULL;

}
template<class T>
linkQueue<T>::~linkQueue(){
    node *tmp;
    while(front!=NULL){
        tmp=front;
        front=front->next;
        delete tmp;
    }
}
template<class T>
bool linkQueue<T>::isEmpty()const{
    return front==NULL;
}
template<class T>
T linkQueue<T>::getHead()const{
    return front->data;
}
template<class T>
void linkQueue<T>::enQueue(const T &x){
    if(rear==NULL) front=rear=new node(x);

    else rear=rear->next=new node(x);
}
template<class T>
T linkQueue<T>::deQueue(){
    node *tmp;
    tmp=front;
    T value=front->data;
    front=front->next;
    if(front==NULL) rear=NULL;
    delete tmp;
    return value;
}








int main()
{
    int cnt=0;
    int n;
    cin>>n;
    int *id;
    id=new int[n];
    for(int i=0;i<=n-1;++i){
        cin>>id[i];
    }


    int q;
    cin>>q;
    int event;

    linkQueue<int> que;
    int index;
    int en;


    for(int i=0;i<=q-1;++i){
        cin>>event;
        if(event==0){
            if(cnt==n) continue;
            index=que.finddex(id[cnt]);
            if(index==-1){
                que.enQueue(id[cnt]);
                ++cnt;
            }
            else{
                que.insert(id[cnt],index);
                ++cnt;
            }
        }
        else{
            if(que.isEmpty())
                cout<<-1<<endl;
            else{
                for(int j=0;j<=n-1;j++){
                    if(id[j]==que.getHead()){
                        cout<<j+1<<endl;
                        que.deQueue();
                        id[j]=-2;
                        break;
                    }
                }

            }

        }

    }

    return 0;
}

