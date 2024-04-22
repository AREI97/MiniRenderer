
#include<iostream>
#include<vector>
using namespace std;

void mySort(vector<int>& arr) {
	bool indicator = true;
	int countLoop = 0;
	while (indicator)
	{
		indicator = false;
		for (int i = 0; i + 1 < arr.size(); i++) {
			if (arr[i] > arr[i + 1]) {
				swap(arr[i], arr[i + 1]);
				indicator = true;
			}
		}
		countLoop++;
		
	}
	cout << countLoop;
}


int main() {
	vector<int> arr = { 1,2,3,4,5 };
	mySort(arr);
	return 0;
}

