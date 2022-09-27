#include "List.h"
List::List() {
	head = tail = NULL;
	count = 0;
}
void List::Delete() {
	element* tmp = head;
	head = head->next;
	delete tmp;
	count--;
}
void List::DeleteAll() {
	for (int i = 1; i <= count; i++) {
		Delete();
	}
}
List::~List() {
	DeleteAll();
}
void List::Add(const char c) {
	element* tmp = new element;
	tmp->data = c;
	tmp->next = NULL;
	if (head != NULL) {
		tail->next = tmp;
		tail = tmp;
	}
	else {
		tail = head = tmp;
	}
	count++;
}
void List::Print() {
	element* tmp = head;
	while (tmp != NULL) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << "\ncount " << count;
}
int List::GetPos(const char c) {
	element* tmp = head;
	for (int i = 1; tmp !=0 ; i++) {
		if (tmp->data == c) {
			return i;
		}
		tmp = tmp->next;
	}
	return 0;
}
void List::AddTo(const char c, int pos) {
	if (pos > count + 1) {
		return;
	}
	element* tmp = new element;
	tmp->data = c;
	tmp->next = NULL;
	element* place = head;
	if (pos == 1) {
		tmp->next = head;
		head = tmp;
	}
	else if (pos == count + 1) {
		element* former_t = tail;
		former_t->next = tmp;
		tail = tmp;
	}
	else {
		for (int i = 1; i < pos-1; i++) {
			place = place->next;
		}
		tmp->next = place->next;
		place->next = tmp;
	}
	count++;
}
void List::DeleteFrom(int pos) {
	if (pos > count) {
		return;
	}
	element* tmp = head;
	if (pos == 1) {
		head = head->next;
		delete tmp;
	}
	else {
		for (int i = 1; i < pos-1; i++) {
			tmp = tmp->next;
		}
		if (pos == count) {
			element* former_t = tail;
			tail = tmp;
			tmp->next = NULL;
			delete former_t;
		}
		else {
			element* remove = tmp->next;
			tmp->next = remove->next;
			delete remove;
		}
	}
	count--;
}
void List::TailOut() {
	cout << endl << tail->data;
}