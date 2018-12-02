#ifndef INTEGERSET_H
#define INTEGERSET_H
#include <stdio.h>

namespace ece309 {

//#include "List.h"

// IntegerSet abstract base class to demonstrate hash table concepts
class IntegerSet {
protected:
   int size;
   int hash(int key) const { return (key * 997) % size; }
public:
   IntegerSet(int htsize):size(htsize) {}
   virtual bool insert(int) = 0;
   virtual bool search(int) const = 0;
   virtual void remove(int) = 0;
};

// Hash Table with Linear Probing
class IntegerSetHT : public IntegerSet {
protected:
  int *table;
  int probeDistance;
  static const int empty_since_start = -2;
  static const int empty_after_removal = -1;
public:
	IntegerSetHT(void);
   IntegerSetHT(int htsize);
   virtual bool insert(int);
   virtual bool search(int) const;
   virtual void remove(int);
   class iterator {
	  private:
		int *table;
		int index;
		int size;
	  public:
		iterator(int *, int);
		int &getInt() { return table[index]; }
		void increment();
		bool end() {  return index >= size; }
  };
  iterator begin()
  {
    return iterator(table, size);
  }
};

// Hash Table with Chaining
/*
class IntegerSetHTChain : public IntegerSet {
protected:
  List *table;
public:
   IntegerSetHTChain(int htsize);
   virtual bool insert(int);
   virtual bool search(int) const;
   virtual void remove(int);
};
*/

}
#endif //INTEGERSET_H
