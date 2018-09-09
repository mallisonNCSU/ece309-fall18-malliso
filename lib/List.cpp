#include <stdio.h>
class List {
	private:
		class ListNode {
		private:
			const char* item;
			ListNode *next;
		public:
			ListNode(const char* a) {item = a; next = NULL;}
			void setNext (ListNode *n) {next = n;}
			const char* getItem() {return item;}
			ListNode* getNext() {return next;}
		};
	
		ListNode *head;
		ListNode *tail;
	public:
		List() {head = NULL ; tail = NULL;}
		~List() {
			while(tail != NULL) {
				remove_front();
			}
		}
		void push_back(const char* string) {
			ListNode *node = new ListNode(string);
			if(head==NULL) {
				head = node;
				tail = node;
			} else {
				tail->setNext(node);
				tail = node;
			}
		}
		const char* get(int n) {
			if(length() >= n) {
				ListNode *node = head;
				for(int i = 1; i < n; i++) {
					node = node->getNext();
				}
				return node->getItem();
			} else {
				return NULL;
			}
		}
		int length() {
			int count = 0;
			ListNode *node = head;
			while(node != NULL) {
				node = node->getNext();
				count++;
			}
			return count;
		}
		const char* remove_front() {
			if(head != NULL) {
				const char* data = head->getItem();
				ListNode *tmp = head->getNext();
				delete head;
				head = tmp;
				if(tmp == NULL) {
					tail = NULL;
				}
				return data;
			}
			return NULL;
		}
	
	
};
