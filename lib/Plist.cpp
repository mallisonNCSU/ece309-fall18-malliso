#include <stdio.h>
#include "Plist.h"

namespace ece309 {

//List
List::List() {
	head = NULL; 
	tail = NULL;
}
		
List::~List() {
	while(tail != NULL) {
		remove_front();
	}
}
void List::push_back(Item* i) {
	ListNode *node = new ListNode(i);
	if(head==NULL) {
		head = node;
		tail = node;
	} else {
		tail->setNext(node);
		tail = node;
	}
}
int List::length() {
	int count = 0;
	ListNode *node = head;
	while(node != NULL) {
		node = node->getNext();
		count++;
	}
	return count;
}
void List::remove_front() {
	if(head != NULL) {
		ListNode *tmp = head->getNext();
		delete head->getItem();
		head = tmp;
		if(tmp == NULL) {
			tail = NULL;
		}
		return;
	}
}

/*void main() {
	List l;
	Item* str = new String("hello");
	Item* db = new Double(5.5);
	Item* integ = new Integer(2);
	l.push_back(str);
	l.push_back(db);
	l.push_back(integ);
	
	List::iterator i = l.begin();
	while(!i.end()) {
		Item* item = i.getItem();
		item->print();
		i.increment();
	}
	
	return 0;
}*/

}
