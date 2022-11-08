/*���̿켱 Ž��*/

#include<iostream>
using namespace std;
#include<stack>

//��������Ʈ�� �̿��� ���� 

const int NODE_NUM = 8;

class Node {
public:
	int index;//v3��ſ� 3�̷������� ������ index������ ���� ���̴�. 
	Node* link;

	Node(int xindex) {
		index = xindex;
		link = NULL;
	}
};

class VNode {
public:
	string name;
	bool visited;//��带 �湮�� ���� �ִ��� ���� �� 
	Node* link;
} graph[NODE_NUM];



void insert_node(int node_index, int adjacent_node_num) {

	//graph[node_index].link�ڿ� adjecent_node_num��带 ����
	Node* new_node = new Node(adjacent_node_num);
	new_node->link = graph[node_index].link;
	graph[node_index].link = new_node;
}

void print_graph() {
	for (int i = 0; i < NODE_NUM; i++) {
		cout << "���� " << graph[i].name << ":";
		for (Node* list = graph[i].link; list != NULL; list = list->link) {
			//cout << "-->" << list->index;
			cout << "-->" << graph[list->index].name;
		}
		cout << endl;
	}
}

void print_node(int v) {
	cout << graph[v].name << "�湮�߽��ϴ�." << endl;
}

stack<int>mystack;

void DFS(int v) { // ��ȯ �˰��� ���

	//�ش� ��尡 �̹� �湮�� ���� ������, ����
	if (graph[v].visited != 0) return; //�湮�� ���� ������ ������
	else graph[v].visited = 1;//�湮�� ���� ������ ǥ���ض�

	print_node(v);//��� �湮 ��� ���

	for (Node* w = graph[v].link; w != NULL; w = w->link)
		if (graph[w->index].visited == 0) DFS(w->index);//w�� �������̰� w�� ����Ű�� �ε����� �д� ���̴�.


}

void DFS2(int v) { // ���ù��� 

	mystack.push(v);

	while (!mystack.empty()) {
		v = mystack.top();
		mystack.pop(); mystack.pop();

		if (graph[v].visited != 0) continue; //�湮�� ���� ������
		else graph[v].visited = 1;//�湮�� ���� ������ ǥ���ض� 

		print_node(v);//��� �湮 ��� ��� 

		for (Node* w = graph[v].link; w != NULL; w = w->link)
			if (graph[w->index].visited == 0) mystack.push(w->index);
	}
}

void main() {

	// �׷��� ���� - �ð��� �ɸ���. 
	graph[0].name = "v1"; graph[1].name = "v2";	graph[2].name = "v3"; graph[3].name = "v4";
	graph[4].name = "v5"; graph[5].name = "v6";	graph[6].name = "v7"; graph[7].name = "v8";
	for (int i = 0; i < NODE_NUM; i++) {
		graph[i].visited = 0;
		graph[i].link = NULL;
	}

	// DFS ��ȸ 
	//��� 0, v1���� ��� ����
	insert_node(0, 1);//0=v1�� 1=v2�� �����϶� (v1-v2����)
	insert_node(0, 2);//(v1-v3����)

	//��� 1, v2���� ��� ����
	insert_node(1, 0);//(v2-v1����)
	insert_node(1, 3);//(v2-v4����)
	insert_node(1, 4);//(v2-v5����)

	//��� 2, v3���� ��� ����
	insert_node(2, 0);//(v3-v1����)
	insert_node(2, 5);//(v3-v6����)
	insert_node(2, 6);//(v3-v7����)

	//��� 3, v4���� ��� ����
	insert_node(3, 1);//(v4-v2����)
	insert_node(3, 7);//(v4-v8����)

	//��� 4, v5���� ��� ����
	insert_node(4, 1);//(v5-v2����)
	insert_node(4, 7);//(v5-v8����)

	//��� 5, v6���� ��� ����
	insert_node(5, 2);//(v6-v3����)
	insert_node(5, 7);//(v6-v8����)

	//��� 6, v7���� ��� ����
	insert_node(6, 2);//(v7-v3����)
	insert_node(6, 7);//(v7-v8����)

	//��� 7, v8���� ��� ����
	insert_node(7, 3);//(v8-v4����)
	insert_node(7, 4);//(v8-v5����)
	insert_node(7, 5);//(v8-v6����)
	insert_node(7, 6);//(v8-v7����)


	print_graph();

	//DFS��ȸ 
	DFS2(0);//v1���� DFS��ȸ�� �Ͻÿ� 


}

