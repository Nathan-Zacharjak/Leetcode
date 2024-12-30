# 1837. Sum of Digits in Base K
## Converting a number to base K
- You can get the last digit of a number in base k by taking the modulo of that number and k.
- If you divide by k, it removes the rightmost digit of the base k number, allowing you to get the next number by taking the modulo again
- This only works if your base is from 2-10, because we don't have enough characters to represent more than 10 digits in say, base 16.
- This works because all numbers can be written as "... coefficient x base^2 + coefficient x base^1 + coefficient x base^0", where the coefficients represent the digits of the base k number.
- e.g. 2 x 3^2 + 0 x 3^1 + 1 x 3^0, represents 19 in base 3! (201)

# 2094. Finding 3-Digit Even Numbers
## Frequency maps
- "Frequency maps" are what you called "character banks" for string problems
- Frequency maps don't have to be maps, they can be any dictionary, e.g. arrays/vectors if you have integers
- Instead of looping through the bank, you could check there are enough characters in the bank for every possible result, by creating a second bank for each result
- OR you could withdraw each character from the possible result, until you try to withdraw a character with none left and continue, or insert the value as a solution, and make sure to deposit the withdrawn characters back.
