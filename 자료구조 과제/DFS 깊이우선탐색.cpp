/*깊이우선 탐색*/

#include<iostream>
using namespace std;
#include<stack>

//인접리스트를 이용한 구현 

const int NODE_NUM = 8;

class Node {
public:
	int index;//v3대신에 3이런식으로 쓸려고 index변수를 쓰는 것이다. 
	Node* link;

	Node(int xindex) {
		index = xindex;
		link = NULL;
	}
};

class VNode {
public:
	string name;
	bool visited;//노드를 방문한 적이 있는지 보는 것 
	Node* link;
} graph[NODE_NUM];



void insert_node(int node_index, int adjacent_node_num) {

	//graph[node_index].link뒤에 adjecent_node_num노드를 연결
	Node* new_node = new Node(adjacent_node_num);
	new_node->link = graph[node_index].link;
	graph[node_index].link = new_node;
}

void print_graph() {
	for (int i = 0; i < NODE_NUM; i++) {
		cout << "정점 " << graph[i].name << ":";
		for (Node* list = graph[i].link; list != NULL; list = list->link) {
			//cout << "-->" << list->index;
			cout << "-->" << graph[list->index].name;
		}
		cout << endl;
	}
}

void print_node(int v) {
	cout << graph[v].name << "방문했습니다." << endl;
}

stack<int>mystack;

void DFS(int v) { // 순환 알고리즘 방식

	//해당 노드가 이미 방문한 적이 있으면, 무시
	if (graph[v].visited != 0) return; //방문한 적이 있으면 끝내라
	else graph[v].visited = 1;//방문한 적이 있으면 표시해라

	print_node(v);//노드 방문 결과 출력

	for (Node* w = graph[v].link; w != NULL; w = w->link)
		if (graph[w->index].visited == 0) DFS(w->index);//w는 포인터이고 w가 가리키는 인덱스를 읽는 것이다.


}

void DFS2(int v) { // 스택버전 

	mystack.push(v);

	while (!mystack.empty()) {
		v = mystack.top();
		mystack.pop(); mystack.pop();

		if (graph[v].visited != 0) continue; //방문한 적이 있으면
		else graph[v].visited = 1;//방문한 적이 있으면 표시해라 

		print_node(v);//노드 방문 결과 출력 

		for (Node* w = graph[v].link; w != NULL; w = w->link)
			if (graph[w->index].visited == 0) mystack.push(w->index);
	}
}

void main() {

	// 그래프 생성 - 시간이 걸린다. 
	graph[0].name = "v1"; graph[1].name = "v2";	graph[2].name = "v3"; graph[3].name = "v4";
	graph[4].name = "v5"; graph[5].name = "v6";	graph[6].name = "v7"; graph[7].name = "v8";
	for (int i = 0; i < NODE_NUM; i++) {
		graph[i].visited = 0;
		graph[i].link = NULL;
	}

	// DFS 순회 
	//노드 0, v1인접 노드 연결
	insert_node(0, 1);//0=v1과 1=v2를 연결하라 (v1-v2연결)
	insert_node(0, 2);//(v1-v3연결)

	//노드 1, v2인접 노드 연결
	insert_node(1, 0);//(v2-v1연결)
	insert_node(1, 3);//(v2-v4연결)
	insert_node(1, 4);//(v2-v5연결)

	//노드 2, v3인접 노드 연결
	insert_node(2, 0);//(v3-v1연결)
	insert_node(2, 5);//(v3-v6연결)
	insert_node(2, 6);//(v3-v7연결)

	//노드 3, v4인접 노드 연결
	insert_node(3, 1);//(v4-v2연결)
	insert_node(3, 7);//(v4-v8연결)

	//노드 4, v5인접 노드 연결
	insert_node(4, 1);//(v5-v2연결)
	insert_node(4, 7);//(v5-v8연결)

	//노드 5, v6인접 노드 연결
	insert_node(5, 2);//(v6-v3연결)
	insert_node(5, 7);//(v6-v8연결)

	//노드 6, v7인접 노드 연결
	insert_node(6, 2);//(v7-v3연결)
	insert_node(6, 7);//(v7-v8연결)

	//노드 7, v8인접 노드 연결
	insert_node(7, 3);//(v8-v4연결)
	insert_node(7, 4);//(v8-v5연결)
	insert_node(7, 5);//(v8-v6연결)
	insert_node(7, 6);//(v8-v7연결)


	print_graph();

	//DFS순회 
	DFS2(0);//v1부터 DFS순회를 하시오 


}

