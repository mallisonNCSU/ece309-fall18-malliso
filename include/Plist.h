//For Plist.cpp
#include <stdio.h>
class Item { //strings, integers, and double values
	public:
		virtual void print() {printf("error\n");}
};

class String : public Item {
	private:
		const char* stringvalue;
	public:
		String(const char* str) {stringvalue = str;}
		void print() {printf("%s\n", stringvalue);}
};

class Integer : public Item {
	private:
		int integervalue;
	public:
		Integer(int integer) {integervalue = integer;}
		void print() {printf("%d\n", integervalue);}
};

class Double : public Item {
	private:
		double doublevalue;
	public:
		Double(double db) {doublevalue = db;}
		void print() {printf("%f\n", doublevalue);}
};

class List {
	private:
		class ListNode {
			private:
				Item* item;
				ListNode *next;
			public:
				ListNode(Item* i) {item = i; next = NULL;};
				void setNext(ListNode *n) {next = n;}
				Item* getItem() {return item;}
				ListNode* getNext() {return next;}
		};
		ListNode *head;
		ListNode *tail;
	
	public:
		class iterator {
			private:
				ListNode *node;
			public:
				iterator(ListNode *n=NULL) {node = n;}
				Item* getItem() {return node->getItem();}
				void increment() {node = node->getNext();}
				bool end() {return node==NULL;}
		};
		
		List();
		~List();
		iterator begin() {return iterator(head);}
		void push_back(Item* i);
		int length();
		void remove_front();
};
