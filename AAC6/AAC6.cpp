#include <iostream>
#include <fstream>

using namespace std;

int getMaxWeight(bool* &arr, int size) {
	do {
		--size;
	} while (!arr[size]);
	return size;
}

int main()
{
	int allowedWeight = 0;
	int num = 0;
	int* weight = NULL;
	bool* arr = NULL;
	string filename;
	cin >> filename;
	ifstream file(filename.c_str());
	if (!file.is_open()) cout << "file is not opened!" << endl;
	else {
		int temp;
		file >> temp;
		if ((temp >= 0) && (temp <= 10000)) {
			allowedWeight = temp;
			cout << temp << " ";
		}
		else cout << "wrong allowed weight!" << endl;
		file >> temp;
		if ((temp >= 0) && (temp <= 300)) {
			num = temp;
			cout << temp << endl;
		}
		else cout << "wrong number of objects!" << endl;
		weight = new int[num];
		for (int i = 0; i < num; i++) {
			file >> temp;
			if ((temp >= 0) && (temp <= 100000)) {
				weight[i] = temp;
				cout << temp << " ";
			}
			else cout << "wrong object weight!" << endl;
		}
		arr = new bool[allowedWeight + 1];
		for (int i = 1; i <= allowedWeight; i++) arr[i] = false;
		arr[0] = 1;
	}
	cout << endl;
	for (int i = 0; i < num; i++) {
		int w = weight[i];
		for (int k = allowedWeight; k >= w; k--) {
			if (arr[k - w]) arr[k] = true;
		}
	}
	cout << endl << getMaxWeight(arr, allowedWeight + 1);
}