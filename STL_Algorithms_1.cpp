/*
STL Algorithms:
(in all cases _begin iterator_ is included in range and _end iterator_ is excluded)
1. min_element(_begin iterator_, _end iterator_); ->returns iterator to minimum element in range.
2. max_element(_begin iterator_, _end iterator_); ->returns iterator to maximum element in range.
3. accumulate(_begin iterator_, _end iterator_, _initial sum_); ->returns sum of all elements within range added to initial sum.
4. count(_begin iterator_, _end iterator_, _element_); ->returns count of element in that range.
        - for sets use: _set name_.count(_element_);
        - for maps use: _map name_.count(_element_); (counts keys only)
5. find(_begin iterator_, _end iterator_, _element_); ->returns iterator to the first instance of the element in the range or _end iterator_ if element not found.
        - for sets and maps use: _set/map name_.find(_element_);
        - finds key only in map.
6. reverse((_begin iterator_, _end iterator_); ->reverses the elements in the range. Works for vectors and strings.

*/