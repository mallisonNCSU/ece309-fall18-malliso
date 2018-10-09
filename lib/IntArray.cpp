#include <stdio.h>

class IntArray {
	private:
		int *array;
		int length;
	public:
		IntArray(const char* str) {
			length = 0;
			while(str[length] != NULL) {
				length++;
			}
			array = new int[length];
			int i = 0;
			while(str[i] != NULL) {
				array[i] = int(str[i]);
				i++;
			}
		}
		
		IntArray(int size, int val=0):length(size) {
			array = new int[size];
			for(int i=0; i < length; i++) {
				array[i] = val;
			}
		}
		
		int& operator[](int index) {
			return array[index];
		}
		
		IntArray& operator+=(const IntArray &rhs) {
			for(int i=0; i< length && i< rhs.length; i++) {
				array[i] = array[i] + rhs.array[i];
			}	
			return *this;
		}
		
		IntArray operator+(const IntArray &rhs) const {
			IntArray newArray(length);
			int i = 0;
			for(i=0; i< length && i< rhs.length; i++) {
				newArray.array[i] = array[i] + rhs.array[i];
			}
			for(; i< length; i++) {
				newArray.array[i] = array[i];
			}
			return newArray;
		}
		
		IntArray operator-(const IntArray &rhs) const {
			IntArray newArray(length);
			int i = 0;
			for(i=0; i< length && i< rhs.length; i++) {
				newArray.array[i] = array[i] - rhs.array[i];
			}
			for(; i< length; i++) {
				newArray.array[i] = array[i];
			}
			return newArray;
		}
		
		IntArray operator*(int x) const {
			IntArray newArray(length);
			int i = 0;
			for(i=0; i< length; i++) {
				newArray.array[i] = array[i] * x;
			}
			return newArray;
		}
		
		IntArray operator/(int x) const {
			IntArray newArray(length);
			int i = 0;
			for(i=0; i< length; i++) {
				newArray.array[i] = array[i] / x;
			}
			return newArray;
		}
		
		IntArray operator<<(int count) const {
			IntArray newArray(length);
			int i = 0;
			for(i=0; i< length - 1; i++) {
				newArray.array[i+1] = array[i];
			}
			newArray.array[0] = array[length - 1];
			return newArray;
		}
		
		operator char*() const {
			char* str = new char[length + 1];
			
			for(int i=0; i< length; i++) {
				if(array[i] < 0 || array[i] > 255) {
					str[i] = char(32);
				} else {
					str[i] = char(array[i]);
				}
			}
			str[length] = NULL;
			
			return str;
		}
		
		operator int() const {
			int average = 0;
			for(int i=0; i< length ; i++) {
				average += array[i];
			}
			return average / length;
		}
		
		int get(int x) {
			return array[x];
		}
		
		void set(int x, int value) {
			array[x] = value;
		}
		
		int getLength(void) {
			return length;
		}
};