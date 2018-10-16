#include "IntegerSet.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// can only hold positive integers
IntegerSetHT::IntegerSetHT(int htsize)
:IntegerSet(htsize)
{
  probeDistance = 20;
   table = new int[size];
   for(int i=0; i<size; i++)
      table[i] = empty_since_start;  // -1 means empty
}

int collisions = 0;

bool IntegerSetHT::insert(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( bucketsProbed++ < probeDistance )
  {
   if ( table[index] < 0 )
   {
     // if the entry is not being used, put the
    // data there
     table[ index ] = data;
     return true;
   }
   index = (index+1) % size;
   collisions++;
  }
  // otherwise give up
   return false;
}

bool IntegerSetHT::search(int data) const
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     return true;
   }
   index = (index+1) % size;
  }

  // data can only be in one location, check it
  return false;
}

void IntegerSetHT::remove(int data)
{
  int index = hash(data);
  int bucketsProbed = 0;
  while( table[index] != empty_since_start &&
         bucketsProbed++ < probeDistance )
  {
   if ( table[index] == data )
   {
     table[index] = empty_after_removal;
     //return;
   }
   index = (index+1) % size;
  }
}
/*
IntegerSetHTChain::IntegerSetHTChain(int htsize)
:IntegerSet(htsize)
{
  table = new List[size];
}

bool IntegerSetHTChain::insert(int data)
{
  List::iterator it;
  table[hash(data)].insertAfter(it,data);
  return true;
}

bool IntegerSetHTChain::search(int data) const
{
   List::iterator it = table[hash(data)].begin();
   while(!it.end())
   {
     if(it.getItem() == data)
        return true;
     it.increment();
   }
   return false;
}

void IntegerSetHTChain::remove(int data)
{
   List::iterator prev,it = table[hash(data)].begin();
   while(!it.end())
   {
     if(it.getItem() == data) {
        table[hash(data)].removeAfter(prev);
        return;
     }
     prev = it;
     it.increment();
   }
}
*/

int main()
{
	srand(time(NULL));
	IntegerSetHT set(1000);
	int failinsert = 0;
	int col = 0;
	int r = 0;
	for(int i = 0; i < 500; i++) {
		r = rand();
		if(set.insert(r) == false) {
			failinsert++;
		}
		if(collisions > 0) {
			col++;
			collisions = 0;
		}
	}

	printf("Number of collisions: %d\n", col);
	printf("Number of failed insertions: %d\n", failinsert);

	return 0;
}