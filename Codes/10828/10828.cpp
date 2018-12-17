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

	int p = queue.back();
	
	queue.pop_back();

	return p;
}

int top() {
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
		else if (text == "top") {
			r = top();
			s << r << '\n';
		}
	}

	cout << s.str();

	return 0;
}
