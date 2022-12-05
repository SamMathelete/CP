/*

Bit Manipulation:
(for a decimal integer x)
1. If:
    x & 1 == 0 : x is even
    x & 1 == 1 : x is odd
    (faster than x % 2)
    
2. x << 1 == x*2
3. x >> 1 == x/2
4. x << n == x *((int)pow(2, n)) 
5. x >> n == x/((int)pow(2, n))
(LHS faster to compute than RHS in all cases)

6. For a alphabet character c, 
    c ^ (1 << 5) : changes uppercase to lowercase and vice-versa
 or c ^ ' ' : changes uppercase to lowercase and vice-versa (xor with space)

7. For Uppercase Conversion(strict):
    c & '_'
8. For Lowercase Conversion(strict):
    c | ' '

9. Unset all LSBs till nth index bit:
    x & (~((1 << (n+1)) - 1))
10. Set all LSBs till nth index bit:
    x | ((1 << (n+1)) - 1)
11. Unset all MSBs till nth index bit:
    x & (((1 << (n)) - 1))
(nth index included in all the above cases)

12. If:
        x & (x-1) == 0 : x is a power of 2
        x & (x-1) != 0 : x is not power of 2
*/