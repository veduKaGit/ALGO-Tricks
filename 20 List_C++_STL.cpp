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
