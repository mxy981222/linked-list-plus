#include<iostream>
#include"Llist.h"
using namespace std;
int main() {
	Llist l1, l2;
	l1.insert(1);
	l1.insert(4);
	l1.insert(9);
	l1.insert(9);
	l2.insert(1);
	l2.insert(1);
	(l1 + l2).print();
}
