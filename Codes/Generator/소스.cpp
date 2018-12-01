#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <ctime>
#include <cmath>

using namespace std;

#define MAX_SIZE 1000
char inputString[MAX_SIZE];
int numbers[MAX_SIZE];

int display();
void input(int count);

int main() {
	clock_t begin, end;
	int count = display();
	bool t = false;
	int nump;
	char data[40];
	
	cout << "�����Ͻðڽ��ϱ�?" <<endl;
	 
	double temp =  (time(NULL) * 100);
	srand(temp);
	do {
		nump = rand() % 20000 + 1000;

		for (int i = 0; i < count; i++)
			if (nump == numbers[i]) {
				t = true;
				break;
			}
	} while (t);
	begin = clock();
	cout << nump << "�� Ǯ��ÿ�" << endl;
	cout << "Ǯ������ ������ȣ�� �Է��Ͻÿ�";

	input(count);

	display();

	end = clock();
	cout << "����ð� : " << ((end - begin) / CLOCKS_PER_SEC) << endl;

	system("PAUSE");
	return 0;
}

int display() {
	int count = 0;
	string temp[MAX_SIZE] = {};

	ifstream inFile("���� ��ȣ.txt");

	while (!inFile.eof()) {
		inFile.getline(inputString, 100);\
		numbers[count] = atoi(inputString);
		count++;
	}
	count--;
	
	for (int i = 0; i < count; i++)
		cout << numbers[i] << endl;

	cout << count << "���� ���α׷��� Ǯ�����ϴ�." << endl;
	inFile.close();

	return count;
}

void input(int count) {
	fstream outFile("���� ��ȣ.txt");

	int num = 0;

	cin >> num;
	numbers[count++] = num;

	for (int i = 0; i < count; i++)
		outFile << numbers[i] << endl;
	
	outFile.close();

}
