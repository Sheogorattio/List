#pragma once
#include <iostream>
using namespace std;
struct element {
	char data;
	element* next;
};

class List
{
	element* head;
	element* tail;
	int count;
public:
	List();
	~List();
	void Add(const char c);
	void Delete();
	void DeleteAll();
	void Print();
	int GetPos(const char c);
	void AddTo(const char c, int pos);
	void DeleteFrom(int pos);
	void TailOut();
};




