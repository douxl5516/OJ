#include <iostream>

using namespace std;

class SBTNode {
public:
	//size:������С(�����Ե�ǰ���Ϊ�����ɵ����ж��ٽ��)
	//data:Ȩֵ���������ϵĽ�㴢���ֵ
	//value:Ӧ������ʱ����Ȩֵ��
    int data, size, value;
    SBTNode * lchild, * rchild, * father;
	//���캯���������ֱ�Ϊ Ȩֵ���Ե�ǰ���Ϊ�������Ĵ�С�����׽��
    SBTNode(int init_data, int init_size = 0, SBTNode * init_father = NULL);
    ~SBTNode();
	//����������
	//�����������Ĳ��룬��������ǰ�����Һ�̣��Ƴ�ĳ����Ϊ0��1�Ľ�㣬�Ƴ�ĳ��Ȩֵ�ĵ㣬�ҳ���k���Ԫ��
    void insert(int value);
    SBTNode * search(int value);
    SBTNode * predecessor();
    SBTNode * successor();
    void remove_node(SBTNode * delete_node);
    bool remove(int value);
    int select(int k);
};

class BinaryTree {
private:
    SBTNode * root;
public:
    BinaryTree();
    ~BinaryTree();
	//����������
	//�������Ĳ��� ���� ɾ����� �ҳ���k�����������������Ľ����ĺ���Ϊ������
    void insert(int value);
    bool find(int value);
    bool remove(int value);
    int select(int k);
};

//������˸�ȨֵΪ0�Ľ�㣬�����ڱ߽����ʱ�Կ�ָ�루NULL���������У����Խ�����ԭ��ָ���ָ����������Ϊָ��һ�� ZPTR�������� size ����Ϊ 0���Ӷ����ʹ��븴�Ӷȡ�
SBTNode ZERO(0);
SBTNode * ZPTR = &ZERO;

SBTNode::SBTNode(int init_data, int init_size, SBTNode * init_father) {
    data = init_data;
    size = init_size;
    lchild = ZPTR;
    rchild = ZPTR;
    father = init_father;
}

SBTNode::~SBTNode() {
    if (lchild != ZPTR) {
        delete lchild;
    }
    if (rchild != ZPTR) {
        delete rchild;
    }
}

//���������Һ��ӱ�Ϊ������㡱����ǰ�����ĸ���㣩���Һ��ӵ����Ӿͱ��ԭ���ĸ������Һ���
//����ע���У�node��ԭ���ĸ���㣩���Һ����á�����㡱��˵
SBTNode * left_rotate(SBTNode * node) {
	//��temp���桰����㡱
    SBTNode * temp = node->rchild;
	//������㡱������  ���node��ԭ���ĸ���㣩���Һ���
    node->rchild = temp->lchild;
	//���¡�����㡱ԭ�������ӵĸ���Ϊnode��ԭ���ĸ���㣩
    temp->lchild->father = node;
	//node��ԭ���ĸ���㣩 �ͱ�ɡ�����㡱������
    temp->lchild = node;
	//������㡱�ĸ��׸���Ϊnode��ԭ���ĸ���㣩�ĸ���
    temp->father = node->father;
	//node��ԭ���ĸ���㣩�ĸ��׸���Ϊ������㡱
    node->father = temp;
	//������㡱�Ĵ�С����Ϊnode��ԭ���ĸ���㣩�Ĵ�С������Ĵ�С���Ըý��Ϊ�����ɵ����Ľ��ĸ�����
    temp->size = node->size;
	//node��ԭ���ĸ���㣩�Ĵ�С����Ϊ �����Ӻ��Һ��ӵĴ�С�����ϱ���1
    node->size = node->lchild->size + node->rchild->size + 1;
	//����������ĸ����
    return temp;
}

//�����������ӱ�Ϊ������㡱����ǰ�����ĸ���㣩�����ӵ��Һ��Ӿͱ��ԭ���ĸ���������
//����ע���У�node��ԭ���ĸ���㣩�������á�����㡱��˵
//����������ϼ����෴
SBTNode * right_rotate(SBTNode * node) {
	//��temp���桰����㡱
    SBTNode * temp = node->lchild;
	//������㡱���Һ���  ���node��ԭ���ĸ���㣩������
    node->lchild = temp->rchild;
	//���¡�����㡱ԭ�����Һ��ӵĸ���Ϊnode��ԭ���ĸ���㣩
    temp->rchild->father = node;
	//node��ԭ���ĸ���㣩 �ͱ�ɡ�����㡱���Һ���
    temp->rchild = node;
	//������㡱�ĸ��׸���Ϊnode��ԭ���ĸ���㣩�ĸ���
    temp->father = node->father;
	//node��ԭ���ĸ���㣩�ĸ��׸���Ϊ������㡱
    node->father = temp;
	//������㡱�Ĵ�С����Ϊnode��ԭ���ĸ���㣩�Ĵ�С������Ĵ�С���Ըý��Ϊ�����ɵ����Ľ��ĸ�����
    temp->size = node->size;
	//node��ԭ���ĸ���㣩�Ĵ�С����Ϊ �����Ӻ��Һ��ӵĴ�С�����ϱ���1
    node->size = node->lchild->size + node->rchild->size + 1;
	//����������ĸ����
    return temp;
}

//������������������е����ĺ���
//flagΪfalse���������������ߵ���������������������ߵ����
//node:Ҫ�����������ĸ����
SBTNode * maintain(SBTNode * node, bool flag) {
	//���������������ߣ����߽����Ҫ�
    if (flag == false) {
		//LL�ͣ�����������������Ԫ�ظ���������������Ԫ�ظ�����Ӧ��������
        if (node->lchild->lchild->size > node->rchild->size) {
			//���������������ĸ����
            node = right_rotate(node);
        }
		//LR�ͣ�����������������Ԫ�ظ���������������Ԫ�ظ���
		//��ô�ȶ������������������ͱ��LL�ͣ�����������
		else if (node->lchild->rchild->size > node->rchild->size) {
			//�����������������ĸ����
            node->lchild = left_rotate(node->lchild);
			//���������¸��ڵ�
            node = right_rotate(node);
        } else {
			//˵��ƽ���ˣ����ظ��ڵ�
            return node;
        }
	//���������������ߣ����߽����Ҫ�
    } else {
		//RR�ͣ�����������������Ԫ�ظ���������������Ԫ�ظ���,Ӧ��������
        if (node->rchild->rchild->size > node->lchild->size) {
			//���������¸��ڵ�
            node = left_rotate(node);
        }
		//RL��: ����������������Ԫ�ظ���������������Ԫ�ظ���
		//��ô�ȶ��������������������RR�ͣ�����������
		else if (node->rchild->lchild->size > node->lchild->size) {
			//�����������������ĸ����
            node->rchild = right_rotate(node->rchild);
			//���������¸��ڵ�
            node = left_rotate(node);
        } else {
			//˵��ƽ���ˣ����ظ��ڵ�
            return node;
        }
    }
	//����Ϊ�ݹ���ã���Ϊ��ʱ����ĵ�����������������������ĳ����㻹�ǲ�ƽ��

	//�ݹ���ã�����������������������߶ȸ��ߵ����
	//false��ʾ�������ϸ�
    node->lchild = maintain(node->lchild, false);
	//�����������������߶ȸ��ߵ����
    node->rchild = maintain(node->rchild, true);
	//����ٶ��������������������ݹ���е���
    node = maintain(node, false);
    node = maintain(node, true);
	//���ص�����������ĸ����
    return node;
}

SBTNode * insert(SBTNode * node, int value) {
    if (value == node->data) {
        return node;
    } else {
        node->size++;
        if (value > node->data) {
            if (node->rchild == ZPTR) {
                node->rchild = new SBTNode(value, 1, node);
            } else {
                node->rchild = insert(node->rchild, value);
            }
        } else {
            if (node->lchild == ZPTR) {
                node->lchild = new SBTNode(value, 1, node);
            } else {
                node->lchild = insert(node->lchild, value);
            }
        }
    }
    return maintain(node, value > node->data);
}

SBTNode * SBTNode::search(int value) {
    if (data == value) {
        return this;
    } else if (value > data) {
        if (rchild == ZPTR) {
            return ZPTR;
        } else {
            return rchild->search(value);
        }
    } else {
        if (lchild == ZPTR) {
            return ZPTR;
        } else {
            return lchild->search(value);
        }
    }
}

SBTNode * SBTNode::predecessor() {
    SBTNode * temp = lchild;
    while (temp != ZPTR && temp->rchild != ZPTR) {
        temp = temp->rchild;
    }
    return temp;
}

SBTNode * SBTNode::successor() {
    SBTNode * temp = rchild;
    while (temp != ZPTR && temp->lchild != ZPTR) {
        temp = temp->lchild;
    }
    return temp;
}

void SBTNode::remove_node(SBTNode * delete_node) {
    SBTNode * temp = ZPTR;
    if (delete_node->lchild != ZPTR) {
        temp = delete_node->lchild;
        temp->father = delete_node->father;
        delete_node->lchild = ZPTR;
    }

    if (delete_node->rchild != ZPTR) {
        temp = delete_node->rchild;
        temp->father = delete_node->father;
        delete_node->rchild = ZPTR;
    }
    if (delete_node->father->lchild == delete_node) {
        delete_node->father->lchild = temp;
    } else {
        delete_node->father->rchild = temp;
    }
    temp = delete_node;
    while (temp != NULL) {
        temp->size--;
        temp = temp->father;
    }
    delete delete_node;
}

bool SBTNode::remove(int value) {
    SBTNode * delete_node, * current_node;
    current_node = search(value);
    if (current_node == ZPTR) {
        return false;
    }
    size--;
    if (current_node->lchild != ZPTR) {
        delete_node = current_node->predecessor();
    } else if (current_node->rchild != ZPTR) {
        delete_node = current_node->successor();
    } else {
        delete_node = current_node;
    }
    current_node->data = delete_node->data;
    remove_node(delete_node);
    return true;
}

int SBTNode::select(int k) {
    //rank��ʾ��ǰ�������������λ
	int rank = lchild->size + 1;
	//��rank���ڵ�kС��k��˵������Ҫ�ҵ�ֵ��ֱ�ӷ���Ȩֵ����
	if (rank == k) {
		return data;
	}else if (k < rank) {
	//С��rank���ͱ���Ҫ�ұȵ�ǰ����С�ģ�������߲���
		return lchild->select(k);
	}else{
	//���ھ����ұ߿�
		//����Ϊʲô��k - rank�أ���Ϊ�����Ѿ���ǰrank�ų��ˣ�
		//�൱������Ҫ������������������һ���µ���ȥ���ң���������λ��ȻҪ��ȥrank��
		return rchild->select(k - rank);
	}
}

BinaryTree::BinaryTree() {
    root = NULL;
}

BinaryTree::~BinaryTree() {
    if (root != NULL) {
        delete root;
    }
}

void BinaryTree::insert(int value) {
    if (root == NULL) {
		//��ʼ��ʱֻ�и���㣬����������СΪ1
        root = new SBTNode(value, 1);
    } else {
        root = ::insert(root, value);
    }
}

bool BinaryTree::find(int value) {
    if (root->search(value) == NULL) {
        return false;
    } else {
       return true;
    }
}

bool BinaryTree::remove(int value) {
    return root->remove(value);
}

int BinaryTree::select(int k) {
    return root->select(k);
}

int main() {
    BinaryTree binarytree;
    int arr[10] = { 16, 9, 20, 3, 18, 15, 6, 30, 7, 25 };
    for (int i = 0; i < 10; i++) {
        binarytree.insert(arr[i]);
    }
	cout<<"�������kС��Ԫ�أ�"<<endl;
    int k;
    cin >> k;
	cout<<endl<<"��"<<k<<"С��Ԫ��Ϊ��"<<endl;
    cout << binarytree.select(k) << endl;
    return 0;
}
