#include <iostream>
#include <string>

using namespace std;

int main()
{
	int lengths[100];
	int lastline = 0;
	char line [100];

	for (int i = 0; i < 100; i = i + 1)
	{
		int linelength = 0;
		cin.getline(line, 80);
		linelength = linelength + 1;
		lengths[i] = sizeof(line);
		if (cin.eof())
		{
			lastline = i;
			break;
		}
	}
	int max = 0;
	for (int i = 0; i < 100; i = i + 1)
	{
		if (lengths[i] > max)
		{
			max = lengths[i];
		}
	}

	int differences = 0;
	for (int i = 0; i < lastline; i = i + 1)
	{
		int diff = (max - lengths[i])*(max - lengths[i]);	
		cout << diff << endl;
		differences = differences + diff;
	}
	cout << differences << endl;

	return 0;
}
