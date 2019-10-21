#include<iostream>
struct node {
	int num;
	node* next;
};
class Llist {
	node *first;
	node* find(int n);
public:
	Llist();
	void insert(int n);
	void remove();
	Llist reverse();
	void print();
	Llist operator+(Llist l1);
};
