#include <iostream>
#include "CLinkedList.h"
using namespace std;

// Double Linked List.
int main() {
	
	CLinkedList<int>	listInt;
	for (int i = 0; i < 100; i++)
	{
		listInt.push_Back(i);
	}

	cout << listInt.size() << endl;
	cout << listInt.front() << endl;
	return 0;
}