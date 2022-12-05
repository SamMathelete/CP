/*

Some Observations on Binary Numbers:
1. Odd numbers end with 1.
2. Powers of 2 have only one 1 in their binary exapnsion.
3. 2^n-1 will have all binary digits as 1s in their binary expansion.(2^n means 2 to the power n here.)

Binary Operators:
1. Bitwise AND(&): 
    0 & 1 = 1 & 0 = 0 & 0 = 0 
    1 & 1 = 1
2. Bitwise OR(|):
    0 | 1 = 1 | 1 = 1 | 0 = 1
    0 | 0 = 0
3. Bitwise XOR(|):
    1 ^ 0 = 0 ^ 1 = 1
    1 ^ 1 = 0 ^ 0 = 0

(The above 3 operators are commutative and associative.)

4. Bitwise NOT(~):
    ~0 = 1
    ~1 = 0

5. Left Shift(<<):
    x << n : Shifts all binary digits of x to the left by n digits
    e.g : 3 << 1 = 6 (11 << 1 = 110)(base 2)
6. Right Shift(>>):
    x << n : Shifts all binary digits of x to the right by n digits.
    e.g : 3 >> 1 = 1 (11 >> 1 = 1)(base 2)

7. 1 << n = 2^n (2^n means 2 to the power n here.)

*/