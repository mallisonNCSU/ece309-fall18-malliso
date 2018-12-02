#include <stdio.h>

namespace ece309 {


class IntegerSet {
protected:
	int size;
	int hash(int key) { return (key * 997) % size; }
public:
	IntegerSet(int htsize):size(htsize) {}  
	virtual bool insert(int) = 0;
	virtual bool search(int) const = 0;
	virtual void remove(int) = 0;
};

class IntegerSetArray : public IntegerSet {
	private:
		int* array;
		int index; //tracks up to where there have been values inserted
	public:
		IntegerSetArray(int asize):IntegerSet(asize) { array = new int[asize]; index = 0; }
		bool insert(int x) { 
			if(index < size) { //if array is not full, insert x
				array[index] = x;
				index++;
				return true;
			}
			return false;
		}
		bool search(int x) const { //return true if x is in array
			for(int i=0; i <= index ; i++) {
				if(array[i] == x) {
					return true;
				}
			}
			return false;
		}
		void remove(int x) { //remove all instances of x
			for(int i=0; i <= index ; i++) {
				if(array[i] == x) {
					for(int j=i; j < index ; j++) { //shift all values left when it finds x
						array[j] = array[j+1];
					}
					index--;
				}
			}
		}
};

}
