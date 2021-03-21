#pragma once

template <class T>
struct ListNode {
	T data;
	ListNode<T>* next;

	explicit ListNode(T _data) {
		data = _data;
		next = nullptr;
	}
};

template <class T>
struct List {
	ListNode<T>* first, * last;

	List() {
		first = last = nullptr;
	}

	void push_back(T data) {
		auto newNode = new ListNode<T>(data);

		if (first == nullptr) {
			first = last = newNode;
		}
		else {
			last->next = newNode;
			last = newNode;
		}
	}
};

struct GraphNode {
	int idx;
	List<GraphNode*> neighbours;

	explicit GraphNode(int _idx) {
		idx = _idx;// cout << "*" << " ";
	}
	~GraphNode() {
		// cout << "~" << " ";
	}

	void addNeighbour(GraphNode* other) {
		neighbours.push_back(other);
	}
};

struct Graph {
	GraphNode** nodes;
	int numberOfNodes;

	explicit Graph(int _numberOfNodes) {
		numberOfNodes = _numberOfNodes;
		nodes = new GraphNode* [numberOfNodes];
		for (int i = 0; i < numberOfNodes; i++) {
			nodes[i] = new GraphNode(i);
		}
	}

	~Graph() {
		for (int i = 0; i < numberOfNodes; i++)
			delete nodes[i];
		delete[] nodes;
	}

	void addEdge(int i, int j) {
		nodes[i]->addNeighbour(nodes[j]);
		nodes[j]->addNeighbour(nodes[i]);
	}
};
