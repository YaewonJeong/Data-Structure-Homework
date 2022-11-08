/*과제물#7.다항식 덧셈 프로그램 완성*/

#include<iostream>
using namespace std;


typedef struct Node {
    float coef;//계수
    int expo;//지수
    struct Node* link;
} Node;

typedef struct ListHead {
    //리스트의 첫번째 주소 노드 가지고 있음 
    Node* head;
    Node* tail;
} ListHead;

ListHead* createLinkedList(void) {
    ListHead* L = (ListHead*)malloc(sizeof(ListHead));//헤드 생성 
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
    //현재 다항식 리스트가 공백이 아닌 경우, 
    else {
        p = L->head;
        while (p->link != NULL) {
            p = p->link;
        }     
        p->link = newNode;
    }
}

//두 다항식의 합을 구하는 연산 ( C = A + B )
void poly_add(ListHead* A, ListHead* B, ListHead* C) {
    Node* a = A->head;
    Node* b = B->head;
    int sum;

    //두 다항식에 노드가 있는 동안 반복 수행 
    while (a && b) {
        //다항식 A의 지수가 다항식 B의 지수와 같은 경우 
        if (a->expo == b->expo) {
            sum = a->coef + b->coef;
            insert_last(C, sum, a->expo);
            a = a->link; b = b->link;
        }
        //다항식 A의 지수가 다항식 B의 지수보다 큰 경우 
        else if (a->expo > b->expo) {
            insert_last(C, a->coef, a->expo);
            a = a->link;
        }
        //다항식 A의 지수가 다항식 B의 지수보다 작은 경우 
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

//다항식 리스트를 출력하는 연산 
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
