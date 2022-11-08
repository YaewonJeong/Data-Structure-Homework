/*������#7.���׽� ���� ���α׷� �ϼ�*/

#include<iostream>
using namespace std;


typedef struct Node {
    float coef;//���
    int expo;//����
    struct Node* link;
} Node;

typedef struct ListHead {
    //����Ʈ�� ù��° �ּ� ��� ������ ���� 
    Node* head;
    Node* tail;
} ListHead;

ListHead* createLinkedList(void) {
    ListHead* L = (ListHead*)malloc(sizeof(ListHead));//��� ���� 
    L->head = L->tail = NULL;
    return L;
}

void insert_last(ListHead* L, float coef, int expo) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    Node* p;
    newNode->coef = coef;
    newNode->expo = expo;
    newNode->link = NULL;
    if (L->head == NULL) {
        L->head = newNode;
        return;
    }
    //���� ���׽� ����Ʈ�� ������ �ƴ� ���, 
    else {
        p = L->head;
        while (p->link != NULL) {
            p = p->link;
        }     
        p->link = newNode;
    }
}

//�� ���׽��� ���� ���ϴ� ���� ( C = A + B )
void poly_add(ListHead* A, ListHead* B, ListHead* C) {
    Node* a = A->head;
    Node* b = B->head;
    int sum;

    //�� ���׽Ŀ� ��尡 �ִ� ���� �ݺ� ���� 
    while (a && b) {
        //���׽� A�� ������ ���׽� B�� ������ ���� ��� 
        if (a->expo == b->expo) {
            sum = a->coef + b->coef;
            insert_last(C, sum, a->expo);
            a = a->link; b = b->link;
        }
        //���׽� A�� ������ ���׽� B�� �������� ū ��� 
        else if (a->expo > b->expo) {
            insert_last(C, a->coef, a->expo);
            a = a->link;
        }
        //���׽� A�� ������ ���׽� B�� �������� ���� ��� 
        else {
            insert_last(C, b->coef, b->expo); 
            b = b->link;
        }
    }
    for (; a != NULL; a = a->link)
        insert_last(C, a->coef, a->expo);
           for (; b != NULL; b = b->link)
        insert_last(C, b->coef, b->expo);
}

//���׽� ����Ʈ�� ����ϴ� ���� 
void printPoly(ListHead* L) {
    Node* p = L->head;
    for (; p; p = p->link) {
        printf("%3.0fx^%d +", p->coef, p->expo);
    }
    cout << endl;
}

void main(void) {
    ListHead* A, * B, * C;
    A = createLinkedList();
    B = createLinkedList();
    C = createLinkedList();


    insert_last(A, 3, 12);   
    insert_last(A, 2, 8);
    insert_last(A, 1, 0);
    cout << endl;
    cout << "A(x)=";
    printPoly(A);

    insert_last(B, 8, 12);
     insert_last(B, -3, 10);
    insert_last(B, 10, 6);
    cout << endl;
    cout << "B(x)=";
    printPoly(B);

    poly_add(A, B, C);
    cout << endl;
    cout << "C(x)=";
    printPoly(C);

}
