#include <iostream>
#include "List.h"
using namespace std;

int main() {
	List list;
	char str[] = "some text";
	for (int i = 0; str[i] != '\0'; i++) {
		list.Add(str[i]);
	}
	list.Print();
	cout << endl<< list.GetPos(' ');
	list.AddTo('q', 10);
	list.AddTo('F', 11);
	cout << endl;
	list.Print();
	list.TailOut();
	list.DeleteFrom(11);
	cout << endl;
	list.Print();
	list.TailOut();
}