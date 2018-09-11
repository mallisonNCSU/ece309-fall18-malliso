#include <stdio.h>

class Item {
private:
	const char* string;
public:
	Item(const char* s = "") {string = s;}
	const char* getString() { return string; }
};

class ArrayList {
private:
	Item* array;
	int len; //len (length) keeps track of how many items are in list
	int size; //size keeps track of space allotted
	
public:
	ArrayList(int s=1) { array = new Item[s]; len = 0; size = s; }
	~ArrayList() { delete array; }
	Item get(int n) { 
		if(n < len) { //n has to be within the scope of len or it isn't an item in list
			return array[n]; 
		}
		return NULL;
	}
	int length() { return len; }
	Item remove_front() { //returns head item, and shifts every item left in array, updating len in the process
		Item tmp = array[0];
		for(int i=0;i<(len-1);i++) {
			array[i] = array[i+1];
		}
		
		len--;
		return tmp;
	}
	void push_back(Item string) {
		if(len == size) { //if list is full, make new, bigger array to make space for new item and move every item over to bigger array
			Item* newArray = new Item[size + 1];
			for(int i=0;i<size;i++) {
				newArray[i] = array[i];
			}
			delete array;
			array = newArray;
			size++;
		}
		array[len] = string;
		len++;
	}
	
};