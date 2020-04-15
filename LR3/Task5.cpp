#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node {
public:
	explicit Node(int id) : id(id) {};
	int id;
	vector<int> edges;
};

bool operator==(const Node& n1, const Node& n2) {
	return n1.id == n2.id ? true : false;
}

class Graph {
public:
	Graph(const vector<int>& starts, const vector<int>& ends) {
		if (starts.size() != ends.size()) {
			throw invalid_argument("array size differ");
		}
		for (int i = 0; i < starts.size();i++) {
			auto node = Node(starts[i]);
			auto it = find(map.begin(), map.end(),node);
			if (it == map.end()) {
				node.edges.push_back(ends[i]);
				map.push_back(node);
			}
			else {
				(*it).edges.push_back(ends[i]);
			}
		}
	}
	int NumOutgoing(const int nodeId) const {
		auto node = Node(nodeId);
		auto it = find(map.begin(), map.end(), node);
		if (it == map.end()) {
			throw invalid_argument("unknown node");
		}
		else {
			return Adjacent(nodeId).size();
		}
	}
	const vector<int>& Adjacent(const int nodeId) const {
		static vector<int> result; //костыль из-за интерфейса
		result.clear();
		auto node = Node(nodeId);
		auto it = find(map.begin(), map.end(), node);
		if (it == map.end()) {
			return result;
		}
		else {
			queue<int> q;
			for (auto edge : (*it).edges) {
				q.push(edge);
				result.push_back(edge);
			}
			while (!q.empty()) {
				auto curNode = Node(q.front());
				q.pop();
				it = find(map.begin(), map.end(), curNode);
				if (it != map.end()) {
					for (auto edge : (*it).edges) {
						if (find(result.begin(), result.end(), edge) == result.end()) {
							q.push(edge);
							result.push_back(edge);
						}
					}
				}
			}
			return result;
		}
	}
private:
	vector<Node> map;
};

int main() {
	vector<int> starts;
	vector<int> ends;
	for (int i = 0; i < 10; i++)
	{
		starts.push_back(i);
		ends.push_back(9 - i);
	}
	auto graph = Graph(starts, ends);
	auto c =graph.Adjacent(3);
	for (auto g : c) {
		cout << g << endl;
	}
	cout << graph.NumOutgoing(3) <<endl;
	
}