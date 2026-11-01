// doubly linked list

// => As compared to vector, the list has slow traversal
// => but once a position has been found, insertion and deletion are quick

// Iteration:
list<int> g;
list<int>::iterator it;
for (it = g.begin(); it != g.end(); ++it)   //begin and end
    cout <<" "<< *it;
  
//push: O(1) time
g.push_back(i);
g.push_front(i);

//Front and back: O(1) time
g.front();
g.back();

//pop: O(1) time
g.pop_front();
g.pop_back();

//erase: O(1) => This is for a single iterator, because you only relink neighbouring pointers.
list<int>::iterator itr = g.begin();
g.erase(itr);
 
//reverse: O(n)
g.reverse();

//sort: O(n*log(n))
g.sort();

//VVIMP NOW => used in LRU and LFU cache:
g.splice(itr1, g, itr2);
// what is splice?
//    1. take a node in the doublly linked list
//    2. remove that node from its posn, and put it to another posn in the list
// time complxity?
//    1. since we know the pointer from where to pick and where to put, it just becomes playing with pointers
//    2. so time: O(1)
// SYNTAX:
//    1. itr1 => means the node will be placed BEFORE itr1
//    2. g => means we'll make this node location change inside list g
//    3. itr2 => means this node at itr2 will be placed BEFORE itr1
// VVIMP:
//    1. No iterators are invalidated. 
//    2. The iterator itr2 still points to the same node after the move, so a map holding it needs no update
//    3. That's why it's used in LRU and LFU.
