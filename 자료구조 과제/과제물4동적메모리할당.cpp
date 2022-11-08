/*������ #9. ������ ����*/

#include<iostream>
using namespace std;

//degine �ؼ� elenemt�� const�� ���� ���̴ٶ�� ����
#define element int
const int MAX_STACK_SIZE = 100;

class Stack {
public:
	element stack[MAX_STACK_SIZE];
	int top;

	Stack() {
		top = -1;
	}
	int is_stack_empty() {
		return(top == -1);
	}

	bool is_stack_full() {
		return(top == MAX_STACK_SIZE - 1);

	}

	void push(int value) {
		if (is_stack_full()) {
			cout << "ERROR : Stack Overflow" << endl;
			exit(1);//return���� �� ���� �������� ���α׷��� ������ ��
		}
		else {
			stack[++top] = value;
		}
	}

	element pop() {
		if (is_stack_empty()) {//����ִµ� �䱸�ϸ�
			cout << "ERROR : Stack Overflow" << endl;
			exit(1);
		}
		else {
			return stack[top--];
		}
	}

	element peek() {
		if (is_stack_empty()) {
			cout << "EROOR : Stack Empty" << endl;
		}
		else return stack[top];
	}

	void print_stack() {
		cout << "##���� ���� ���##" << endl;
		//���� ���ݻ� top���� ������ �Ʒ��� ���
		for (int i = top; i >= 0; i--)
			cout << stack[i] << endl;

	}
};

void main() {
	Stack s;

	s.push(10);
	s.push(20);
	s.pop();
	s.push(30);
	s.push(40);
	s.push(50);
	s.pop();
	s.print_stack();
}
