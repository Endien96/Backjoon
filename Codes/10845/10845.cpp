#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
vector<int> queue;

int size() {
	return queue.size();
}

bool empty() {
	if (queue.size() == 0)
		return true;
	else
		return false;
}

void push(int x) {
	queue.push_back(x);
}

int pop() {
	if (empty())
		return -1;

	vector<int> temp;

	int s = queue.size();
	for (int i = 1; i < s; i++)
		temp.push_back(queue[i]);

	int p = queue.front();
	queue = temp;

	return p;
}

int front() {
	if (empty())
		return -1;

	return queue.front();
}

int back() {
	if (empty())
		return -1;

	return queue.back();
}

int main() {
	int n;
	cin >> n;
	stringstream s;

	for (int i = 0; i <= n; i++) {
		string text;
		int b;
		getline(cin, text);

		if (text.substr(0, 4) == "push") {
			b = stoi(text.substr(5, text.length() - 5));
			text = text.substr(0, 4);
		}

		int r;
		if (text == "push")
			push(b);
		else if (text == "pop") {
			r = pop();
			s << r << '\n';
		}
		else if (text == "size") {
			r = size();
			s << r << '\n';
		}
		else if (text == "empty") {
			r = empty();
			s << r << '\n';
		}
		else if (text == "front") {
			r = front();
			s << r << '\n';
		}
		else if (text == "back") {
			r = back();
			s << r << '\n';
		}
	}

	cout << s.str();

	return 0;
}
