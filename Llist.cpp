#include"Llist.h"
using namespace std;
Llist::Llist() {
	//EFFECT: build a new empty linked list
	this->first = NULL;
}
void Llist::insert(int n) {
	//REQUIRE: n is an integer
	//EFFECT: insert n into this
	//MODIFY: this
	node* nd = new node;
	nd->num = n;
	nd->next = this->first;
	this->first = nd;
}
void Llist::print() {
	//EFFECT: print all the elements in this in order
	node* now = this->first;
	cout << "the number is:";
	while (now != NULL) {
		cout << now->num;
		now = now->next;
	}
}
void Llist::remove() {
	//REQUIRE: this is not empty
	//EFFECT: remove the first elementin the linked list
	//MODIFY: this
	node* victim = this->first;
	this->first = victim->next;
	delete victim;
}
Llist Llist::reverse() {
	Llist rev;
	node* now = this->first;
	while (now != NULL) {
		int n = now->num;
		rev.insert(n);
		now = now->next;
	}
	delete now;
	return rev;
}
Llist Llist::operator+(Llist l1) {
	Llist res;
	node* now1 = new node;
	node* now2 = new node;
	now1 = this->first;
	now2 = l1.first;
	bool flag = false;
	while (now1 != NULL && now2 != NULL) {
		int n = now1->num + now2->num;
		if (flag) {
			n++;
			flag = false;
		}
		if (n >= 10) {
			n -= 10;
			flag = true;
		}
		res.insert(n);
		now1 = now1->next;
		now2 = now2->next;
	}
	while (now1 != NULL) {
		int n = now1->num;
		if (flag) {
			n++;
			flag = false;
		}
		if (n >= 10) {
			n -= 10;
			flag = true;
		}
		res.insert(n);
		now1 = now1->next;
	}
	while (now2 != NULL) {
		int n = now2->num;
		if (flag) {
			n++;
			flag = false;
		}
		if (n >= 10) {
			n -= 10;
			flag = true;
		}
		res.insert(n);
		now2 = now2->next;
	}
	return res;
}
/*
node* Llist::find(int n) {
	//EFFECT: return the pointer of the node of n, if n is in the linked list, else return NULL
	node* res = NULL;
	node* now = this->first;
	while (now != NULL) {
		if (now->num == n) {
			res = now;
			break;
		}
		now = now->next;
	}
	return res;
}*/
