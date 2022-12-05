/*

Extra Notes on Vectors:
1. Vectors can be copied easily using '=' operator. O(n) time complexity.
2. v1 = v copies v to v1 and changes to v1 do not affect v.
3. &v1 = v copies the reference of v1 to v so, changes to v1 affect v.
4. v.pop_back() removes the last element of the vector.
5. v.begin() is an iterator to v[0].
6. v.end() is an iterator to v[n+1] where n+1 is the index next to the last element.
7. iterator declaration: vector<_type_> :: iterator _iterator name_

Iterators Notes:
1. iterator declaration: _container_ :: iterator _iterator name_
2. *(_iterator name_) gives the element the iterator is pointing to.
3. Using auto: auto _iterator name_ = given iterator.
4. Loop using auto:
    if wanting to change content: for(auto &_iterator name_ : _container name_)
    if not wanting to change content: for(auto _iterator name_ : _container name_)
5. Loop without using auto:(Not recommended)
    predefined iterator it.
    if wanting to change content: for(&it = _begin iterator_; &it != _end iterator_; &it++)
    if not wanting to change content: for(it = _begin iterator_; it != _end iterator_; it++)
6. _iterator name_++ moves to the next iterator and is not necessarily _iterator name_+=1.

*/