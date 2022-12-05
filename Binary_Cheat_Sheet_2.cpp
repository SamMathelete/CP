/*

More Observations:
1. For a binary number, its right most digit is called the least significant bit(LSB) 
   and its left most digit is called its most significant bit.
2. Indexing is done from LSB to MSB starting with index 0 at LSB.
3. A bit is called set if it is 1, and unset if it is 0.
4. If:
    x & (1 << n) == (1 << n) then nth index bit of x is set(1).
    x & (1 << n) == 0 then nth index bit of x is unset(0).
5. (x >> n) & 1 gives the bit at nth index of x.
6. To set the bit at nth index of decimal number x:
    x | (1 << n)
7. To unset the bit at nth index of decimal number x:
    x & (~(1 << n))
8. To toggle the bit at nth index of decimal number x:
    x ^ (1 << n)

*/