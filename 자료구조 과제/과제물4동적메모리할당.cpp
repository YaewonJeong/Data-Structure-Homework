/*과제물 #9. 스택의 구현*/

#include<iostream>
using namespace std;

//degine 해서 elenemt는 const와 같은 것이다라고 내포
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
			exit(1);//return보다 더 강한 수준으로 프로그램을 끝내는 것
		}
		else {
			stack[++top] = value;
		}
	}

	element pop() {
		if (is_stack_empty()) {//비어있는데 요구하면
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
		cout << "##스택 상태 출력##" << endl;
		//스택 성격상 top부터 위에서 아래로 출력
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
