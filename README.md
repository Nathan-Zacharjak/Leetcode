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

# 2192. All Ancestors of a Node in a Directed Acyclic Graph
## Reverse Directed Graphs & DFS
- If you reverse the direction of edges in a directed graph, you'll have a graph where all reachable nodes are the node's ancestors!
- By performing DFS, you can easily find all ancestors of a node. (Make sure to not count the original node)
- By flagging a node as visited in the DFS, rather than inserting a node straight away, you can simply iterate through all possible nodes in a separate loop! Then, inserting into a vector of vectors happens in order! (With no need for a vector of sets to maintain order!)
- If you do the "visited" flagging first, before traversing in DFS, you can save yourself DFS-ing down an already searched node!

## Finding ancestors using DFS
- By iterating over all possible node labels, and performing a DFS from each node, we can find each node's reachable nodes!
- You take each node as the "ancestor" node to add to all other node's ancestor vectors.
- Since you iterate over all possible answers in order, a set is not needed to ensure the lists of ancestors are in order! (You can use a vector/array)
- You can prevent DFS-ing into already explored nodes by first checking if the child node's last added ancestor is the current node, then you know the DFS has already backed out of that node and can be skipped!
- On exploring a node with DFS, you can immediately add the ancestor node into the node's ancestor list, but make sure the node isn't the ancestor node itself!

## How to topological sort a DAG
- "Kahn's algorithim"
1. Make an adjacency list and count vector of the number of incoming edges per node
2. For all nodes without incoming edges, add them to a basic queue
3. Pop the next node, add it to the topological sort array
4. Decrease the count of all outgoing edges' end nodes by 1 (Remove that node's outgoing edges from the graph)
5. If a node's incoming edge count reaches 0, add it to the queue
6. Pop the next node until the queue is empty
7. Done! You have topologically sorted the graph! (Who's order is now contained in an array)
- Basically, you need to put all nodes with no incoming edges into a queue, and remove each popped node's edges from the graph, in order to add new edgeless nodes to the queue

## How to find all ancestors of a node using topological sort
- Once you have a topological sort, you now have an order to process each node to ensure all of a node's possible ancestors have been considered as you go.
- You have to use a list of hash tables in order to ensure only one copy of each node's ancestor is added
- You process each node by topological order, and add it to all of its outgoing nodes as an ancestor
- Then you add each of the node's ancestors (if any) to each of the outgoing nodes
- Then you iterate to the next node in topological order, and continue until the last node
- Finally, to convert a list of hash tables into a list of ordered lists, you iterate through all possible nodes in index order, and add it to each ancestor list it is a part of

# 2553. Separate the Digits in an Array
## Getting digits from an int
- Convert the integer into a string, makes numbers easier to deal with!
- You can just loop through the string from the start, and just convert each character back into an int using the ASCII trick!
- There's a difference between a frequency map and a frequency table! (Hash map vs. table!)

# 1684. Count the Number of Consistent Strings
## Bit array vs. hash table
- Although using a bit array give O(1) complexity, as opposed to a hash table's O(m) complexity, where m is the number of allowed characters, this is misleading, as a hash table to store allowed characters offers more flexibility to store more possible elements in the hash table

## Bit manipulation
- Anything that can use a bit vector can use a bitmask instead! (So long as the size of the bit vector is known, and it isn't too large! So long as bit vector is less than 32/64 you're good!)
- Vector.size() runs in O(1) time, so setting a count of allowed things to the total number of things, then decreasing by 1 whenever we find a not allowed thing is a cleaner way to count the total number of allowed things
- We can use a bit mask to store allowed characters in an integer, which will lead to flexibility (use larger int) and O(1) space complexity
- We use 1, and bit shift left x number of times, where x represents an index representing the allowed object, and OR-ing with the 32-bit 0 integer
- We then find if an object is allowed by bit shifting the bit mask right x times, and AND-ing with 1, where x is the index of the object (Like in a boolean array)
- For bit flags, OR = insert, AND = check
- Then simply decrement the allowed object counter by 1, and return the allowed object count

# 3216. Lexicographically Smallest String After a Swap
## Check for number "parity"
- "Parity" means if 2 numbers are both even or both odd, if they are, they're the same parity!
- You can check for parity easily by doing: num1 % 2 == num2 % 2
- Using swap() in c++ is fine! So long as you are actually swapping 2 pointers in memory that is actually going to be saved outside of the current scope! (And the pointers are to simple data types and not objects, instead use the object's in-built obj.swap() function!)


# 206. Reverse Linked List
## Recursive space complexity
- Not necessarily true that a recursive approach will have a linear space complexity!
- All recursive functions can be written iteratively!
- And because of DP, it's very possible that a linear approach can be written in a O(1) space complexity way, using 1 or 2 variables to store the data needed for a DP approach!


# 2807. Insert Greatest Common Divisors in Linked List
## In-built functions
- Look up what in-built functions are available for your language!!!
- You might not need to invent the whole solution yourself, in-built functions are almost always going to have the best time and space complexity!
- (You might still need to know the complexity of the in-built function itself however...)

## Calculating the GCD
- There's an in-built function for this in C++, which runs in O(log(n)) time!
- It uses the "Euclidean algorithm", which involves repeatedly dividing the larger number by the smaller number, and replacing the larger number with the remainder, and the smaller number by the original larger number, until one of the numbers becomes 0!
- How many times can you repeatedly divide something? O(log n) times!


# 1110. Delete Nodes And Return Forest
## Pre/post-order traversal tree node deletion
- You can use either post or pre-order tree traversal to traverse and safely delete nodes from a tree
- For pre-order traversal, you need to pass the parent node as a parameter in a traversal call, and check whether the parent was deleted to safely mark it as so, and mark the current node as a new root
- Post-order traversal, you pass the child node as a return value, and update the parent node's left/right pointer to this value, where the child node already had its possible deletion processed


# 136. Single Number
## XOR operator
- i ^ i = 0
- xor is commutative! j^i^i = i^j^i = i^i^j = j
- Use this to simply explain how to do the xor nums trick!
- You can start with an initial value of 0, since XOR-ing with 0 does nothing! 0^i = i
- Bit operators can use the "+=" notation, e.g. result ^= i

## Large integers
- When the size of an integer is very large, you need to consider whether it will actually fit in an "int" type variable!
- int16_t = 16 bits > 10^3
- int32_t = 32 bits > 10^8
- int64_t = 64 bits > 10^18


# 3152. Special Array II
## Prefix Sum
- You can label indexes into groups in an array using a so-called "prefix sum"
- This is where each index in the same group is labelled by the number of the group it's in, where every element in the same group is in one *continuous* block
- E.g. you could label by "breakfast" and "dessert": ["egg", "bacon", "chocolate", "ice cream"] = [0,0,1,1]
- "egg" and "bacon" belong to group 0, and "chocolate" and "ice cream" belong to group 1
- Now, simply by taking away the value of the end of a sub-array, with the beginning of a sub-array, you can tell if all elements in that sub-array are in the same group or not!
- If the subtraction is 0, then all elements are in the same group!
- The labelling can be done easily by adding 1 from the last prefix if 2 adjacent pairs aren't in the same group, in linear time!
- The prefix sum could also be interpreted as the total number of groups so far
- This only works if all array groups are *continuous*, e.g. adding "toast" to the end of the example would label "toast" in a different group to the other "breakfast" elements


# 1545. Find Kth Bit in Nth Binary String
## Simulated recursion
- You don't have to explicitly do as the question describes for recursive problems!
- You can "simulate" the problem by finding clever patterns in the recursive problem and base cases, but never actually calculate their values! (other than the base cases)
- In this case, you only know about outright adding the numbers '0' and '1' in specific scenarios, and can return them when they show up, but now, you need to find a way to reduce the problem down into 'cases' which eventually lead to one of the 2 base cases!

## Finding the number of doubles
- To find the size of a number after n doubles, just bit shift 1 n times! i.e. 1 << n = 2^n

## Converting recursive to iterative without DP
- Converting recursive to iterative functions without using DP is hard, but one trick is to turn the base case into the condition of a while loop!
- Then you may need to save a running number to keep track of the indexes you are searching through, rather than making a new recursive call with different arguments, e.g. the 'size' parameter in this function
- You may also need to keep track of entirely new variables like 'invertCount', just to simulate what recursion was doing in terms of running the recursive calls in a necessary order.


# 2379. Minimum Re-colours to Get K Consecutive Black Blocks
## Sliding window
- For edit distance-like problems, you may not have to jump straight to DP!
- If a problem involves *consecutive* characters, that is where you should think of a "sliding window"!
- A sliding window performs a brute force-like linear search through the problem, where you consider if any one possible window is a solution
- However, in this problem, we actually need the minimum number, so we just take a running minimum as we're moving the window!
- Your window does not have to stay at a fixed size! You can dynamically adjust your window and when it reaches a certain size, mark the window as an answer!
- You can even initially grow your window up one by one to a certain size, and once it reaches a size, starts moving along! You can then add each front value, and take away each back value's cost as you go along to keep an accurate cost count for that window!


# 202. Happy number
## Tortoise & Hare algorithm (Cycle detection)
- You can use a "Tortoise & Hare" algorithm for finding if there is a cycle in a linked list, or any potential cycle of values!
- You make 2 pointers, then have a fast pointer move twice, for every time the slow pointer moves once
- If they ever meet, you have a cycle
- If the hare makes it to the end, you don't have a cycle
- This is especially useful for detecting cycles in linked lists!


# 287. Find the Duplicate Number
## Sign marking
- Travel through the numbers using the current number as the index for the next, and mark the numbers with negative signs as you go!
- E.g. if [2,3,1] -> [-2,3,1] -> [-2,-3,1] for the first number 2, flip the number at index 2! (which is 3)
- Then when you try to flip the sign of a number that is already negative, the index number must have been a duplicate!
- *Only works for positive numbers!*

## Pigeonhole principle
- If you try to rearrange every number so each number goes into its equivalent index, e.g. [3,0,2,1,3] -> [0,1,2,3-3], you will eventually try to place a number in an index that is already taken!
- So, if you start with an arbitrary index, then on placing the number, now move the number already in that index into its index, then move that number to its index and so on, until you find the duplicate!

## Binary search
- The trick is to count the number of elements less than or equal to a number in the array!
- If this equals the number, then it is less than the duplicate, if it is greater, then it is equal to or greater than the duplicate!
- This only works if there is only 1 number that is a duplicate (else you have to check for duplicates from the smallest number upwards, removing a value each time)
- Then, you can just search the numbers greater than it, or just search the numbers less than it, depending on the value of lessThanOrEqualCount for that number!
- (You build up count just using a linear scan running sum)
- Once the search range is just one element, process that last number, and return the smallest number that had an unequal lessThanOrEqualCount to itself! (Using a running min)

## Tortoise and Hare algorithm
- Make a tortoise and hare pointer like usual
- Let them go by repeatedly visiting the index of the current number
- Eventually they meet
- When they do, set the tortoise back to the start, and leave the hare at the intersection point
- Make the hare now travel at the same speed as the tortoise, the maths checks out, they will now meet at *the* entry point in the cycle, which is the duplicate node!


# 1319. Number of Operations to Make Network Connected
## Using Union-Find to find the number of disjoint sets
- You have to implement the Union() and Find() functions from memory, and remember to initialise a parent & rank size array, since C++ does not have an in-built implementation of Union-Find...
- To count the number of disjoint sets, simply start a counter at the number of nodes in your graph
- Then decrement this value by one every time Union() actually unions 2 sets!
- Remember to initialise each value of size[i] to 1, and parent[i] to i

# 2801. Count Stepping Numbers in Range
## Digit DP Basics
- When you are asked to find the count of numbers in a range that satisfy a certain property, this is digit DP!
- The key thing is the count of numbers satisfying the property is given by: G(b) - G(a-1)
- So the count of satisfying numbers from a to b is the count of satisfying numbers from 0 to b, minus the count of satisfying numbers from 0 to a-1
- If you can solve the problem for just 0 to b, you can solve the whole problem!
- So, it comes down to coming up with a recursive algorithm that solves the problem from 0 to n (even if the recursive algorithm times out!)
- The other key thing is to have an array or string representation of your numbers!
- (BTW, it is perfectly fine to use 64-bit numbers for any problem if really required! (long long) This normally wouldn't be the case for digit DP unless the output needs to be a number)
- Digit DP tends to use a mix of recursion, *and* DP! It is essentially just recursion with memoisation, rather than transforming exponential recursion into a polynomial iterative function...

## Digit DP Variables
- You work your way from having 1 digit, to n digits (or the other way around for the recursive approach!)
- You can look at numbers with less digits than max by adding leading zeros to match the number of digits max has to make the DP approach easier!
- Index: The current index of the digit in the string to have a digit inserted (can be from left-to-right, or the other way around)
- Tight: Whether the digits before the current digit match the max number or not. This signifies that the current digit can only go from 0 to max's digit at that index
- E.g. If the max is 3245, and 32** have already been selected, the next digit can only go up to 4! I.e. 320* -> 324*, and 324*'s next digit is now tight! (up to 5)
- The canonical and easy way to do this, is to do a left-to-right DP and set the first call to the recursive function to have tight=true, and pass the max number string!
- Then, you can just calculate the max digit for that index to be max[index], and set nextTight to true if the current number is tight, and the current looped digit is equal to the max digit!

## Digit DP Implementation
- Typically the way digit DP is implemented is like this:
- First is your base case, it could be when you have an empty string, reached the number of digits max has, all digits are 0s, when the current index is -1 or 0 or string.size(), depends on the problem!
- Then, you check if the current DP iteration has already been calculated or not
- Then you use the given value of tight, to determine if you are restricted up to max's digit at that index, or free to call the whole range of digits from 0 to 9
- Then you calculate the new value of tight, for each of the digits, only the last digit in the range should have its tight value set to true in the recursive call
- Then finally you make the recursive call from your last value (to go down to the base case), normally by doing res += recursiveFunc(lastIndex), a running sum of your result 
- Then save your result into the DP array, and then return it!
- Your DP array is normally 3 or 4 dimensions, and you use memset(dp, -1, sizeof(dp)); to initialise the DP array to all -1s
- You could also simply look at the number of i-digit satisfying numbers ending in digit j, to give DP[i][j], and then implement the tight variable afterwards!


# 233. Number of Digit One
## Handling memory with digit DP
- The size of the array at one dimension does not equal the maximum value of an integer stored there, merely the total number of values you will have to store for the largest size of the question! (You can think about the needed size either way, whichever is easier to understand!)
- E.g. For the "tight" bool, you will always use 2,
- For the index, you will always use the maximum length of the input number string (10^_ + 1, e.g. 10^9 = 10 digits, e.g. 10^0 has 1 digit)
- For the result, you should be able to simply do a running sum off of the recursive call, e.g. int result = 0, result += DigitDPFunc()
- For the count, you might not need it, and could maybe re-write your function so that it returns 0 or 1 in the base case, and add that number as +1 to the total number of valid numbers instead
- However, you might need it when you have *stacking* running sums, like the total number of 1s in the numbers from 1 to n, so you need the max possible value of count in one recursive call tree, which is when every digit is 1, so if the max number of digits in the input is 10, the max number of 1s must also be 10!
- If the problem returns an int, you should be able to use a DP array of ints, rather than long longs...


# 552. Student Attendance Record II
## Finding the recursive solution to DP
- When you have a max number, instead of passing it and counting up indexes, try just passing the max, and decrement the max down to 0 as the base case, then return 1
- To make iterative translation easier, don't use digit DP-style deciding on valid values and looping through them, instead try to check if you're outside the bounds at the start of each recursive call and return 0, using constant known bounds on passed variables into the function!
- (Apparently, if you don't do this, you might miss the fact your recursive algorithm is going through already dead solutions! Returning from already seen solutions isn't enough! You need to check that your recursive solution is actually stopping itself from continuing down any dead solutions, and the best way to do this sometimes, is to handle dead solutions at the start of your function. Try this if you are TLE-ing with the recursive solution!)
- When doing a DP problem, don't worry about passing by reference, or consts, since writing the state transitions in the recursive calls themselves makes translating to iterative DP easier!
- When you have a modConst question, perform the mod each time you add to count, *and* when you add count's value to the DPArray! (Else you might overflow...)
- For the final return value, try to cache to the dpArray and return at the same time! (Will also make iterative translation easier!)
- You can use vector<vector<vector... as your DP array, which is harder to initialise than memset(), BUT it allows you to only set as much memory as you need at runtime! Just set the dpArray to a vector with sizes initialised, and don't forget to add 1 to the index size for the 0-index!
- E.g. dpArray = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(2, vector<int>(3,-1)));


## Finding the iterative solution to DP
- Typically, in the iterative version, you loop through the index in the reverse of what you did in the recursive solution. So that's why making your recursive solution start at n, and end at 0, makes the iterative solution translation much easier!
- It might also be easier to think of the index variable as an outright sub-problem size variable! E.g. instead of "indexes left", call it "size"! Since you've divided the problem into independent sub-problems! (This will make it much easier to come up with the base cases)
- So, you need to first nested loop through all recursion variables in order.
- Then, you typically reverse the iteration for the index in each recursive call, e.g. index -1 becomes index +1
- Then from there, you can just copy the implementation of the recursive algorithm, and replace the recursive calls with indexation into the DPArray! (usually no need to reverse the iterations for the non-index state variables)
- You should be able to remove the cache check from the recursive algorithm, and remove the return from the return DPArray[][][] = result
- Finally, you need to come up with the base cases, typically when index/size = 0. Remember that the solution needs to be possible given the parameters! (and that an empty string could count as a possible solution!)
- So, set DPArray[0][0][0] to 1, to count the empty string as a possible solution if appropriate, and set all other values in DPArray[0] to 0, if they are not possible scenarios at all! (Even if the constraints don't allow index/size = 0!)
- Then finally, make sure to initialise all other values of the DPArray to 0, (though in the iterative solution this is not strictly necessary!)
- To calculate the result, you typically need to sum up all the counts of valid paths of the entirety of the last value of index/size of the DPArray, i.e. sum(DPArray[n][0 to max][0 to max]...)

## Space optimising iterative DP
- Simply print out your DPArray at each iteration and see if you can find a pattern that makes previous table values redundant!
- Typically you only need DPArray[n] and DPArray[n-1], which you could store as prevDPState, and currentDPState!
- Don't forget to reset the next DPArray state to 0s at the end of each index/size iteration!


# 832. Flipping an image
## Flipping a bit simply!
- If you XOR a bit with 1, it flips it!
- E.g. bit ^= 1; = flipped bit!


# 205. Isomorphic Strings
## Comparing the shape of 2 strings
- It may be useful to replace each character of 2 strings to be compared, with the *index of the first occurrence of that character*
- That way, you can tell if 2 strings are "isomorphic" i.e. have the same "shape" or pattern of characters that can be mapped 1-1 to each other

## Reversing an array
- To save on an extra O(n) time calling vector.reverse, when you're doing more than just reversing an array it will save an extra +O(n) of non-asymptotic time doing the reversing with whatever else you are doing in the array in 1 loop!
- To do this, use: "length -1 -i", to find the mirrored element in the array to swap with the ith element!
- To iterate up to the middle element use: "(length + 1) / 2"! (Or length / 2 to ignore the middle element)

## Comparing push_backed strings vs. vectors
- You might get the wrong result if you push_back into a string rather than a vector if you are checking if they are equal!
- You might get: "12345", when the result really was: [1,2,34,5]
- This happens when pushing back integers or strings with multiple characters! *Use a vector instead!*


# 1926. Nearest Exit from Entrance in Maze
## BFS visited marking
- Instead of making a whole unordered_set to store the matrix coordinates already visited, you might be able to take advantage of the format of the input!
- In this question, walls are marked with +, empty space marked with .
- So, we can just mark coordinates as visited simply by changing a position's '.' with a '+'! And the BFS algorithm will automatically ignore it without using extra space!


# 593. Valid Square
## Finding the distance between 2 points
- Remember you can find the "squared" distance between 2 points using dist = a^2 + b^2, which translates to this for 2 coordinate points: (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) (You don't need abs() because of the square!)
- Typically, a dist(p1, p2) helper function is really useful here!

## Sorting shape coordinates
- You might be able to significantly narrow down the possible cases for a question with shapes by sorting the shape's coordinates first!
- What you need to do for this question is sort the coordinates by x-coordinate first, then by y-coordinate in case of a tie!
- Then you are only left with 3 shape possibilities! A right-tilted square, a left-tiled square, or a perfectly straight square!
- Now you can traverse all sides of possible squares in an order that guarantees a line between point 0 and 1, and point 2 and 3 is a side of a square, and point 0 and 3, and point 1 and 2 form the diagonals of all 3 possible squares!
- From there, you can just check that the distances between these points in a way that ensures both width and height of the square is of equal length, and the diagonals are of equal length too!

## Using a set to check for equal lengths
- You could alternatively use an unordered_set to store all lengths of all sides of the shape, and the 2 diagonals, and simply check that the size of the unordered_set is 2! (1 for the length of the sides, 1 for the length of the diagonals)
- (This only works if the length of the diagonals can never equal the length of the sides, e.g. only integer lengths, no square roots!)


# 2492. Minimum Score of a Path Between Two Cities
## BFS space complexity
- Breadth-first search has a space complexity of O(n), as you can have up to all graph nodes -1 in the queue at one time
- HOWEVER, if you aren't given an adjacency list, and have to build one yourself, guess what? You now have to take into account the space complexity of the adjacency list! Therefore the space complexity becomes: O(n + m)!


# 2937. Make Three Strings Equal
## Longest matching prefix
- To find the longest prefix contained in multiple strings, you just have to do 2 things:
- 1. Find the minimum length string, can be found with min() using a list initialiser! E.g. min({s1.size(), s2.size(), s3.size()})
- 2. Find the position of the first different character of all strings, which can easily be done with a while loop
- The longest matching prefix are the characters up to that position in any string


# 590. N-ary Tree Postorder Traversal
## Iterative Pre/Post-order traversal
- To convert recursive post-order tree traversal to iterative, you require using a stack to reverse the iterative result
- So the space complexity (and time) is no better than just using the recursive implementation!


# 488. Zuma Game
## Memoisation with unknown max states
- You can use "serialisation" to allow for sneakily storing multiple input values in an unordered_map memo!
- Using an unordered_map allows for caching with DP, when you don't know the max  number of possible values for every state variable! (Otherwise you just use memset() + a C array!)
- This works if you can change each of your input variables into a string! Just transform each state variable into a string, concatenate a "#" between them (or some unused symbol), then use that string as the map's key!


# 1582. Special Positions in a binary matrix
## Handling coordinates
- Don't use struct! Use pair<int,int>, or tuple<int,int,int>!

## Direction vector grid searching
- When grid searching one grid point at a time, create a "direction vector" or a "direction tuple"!
- E.g. vector<pair<int,int>>dir = {{-1,0}, {1,0}, {0,-1}, {0,1}}
- E.g. for 3D matrix grid: tuple<int,int,int>example; get<0>(example); get<1>(example)
- This will make iterating in all cardinal directions from a single starting point much easier!


# 1222. Queens That Can Attack the King
## DFS grid searching
- If you can afford to, you can speed up grid searching by search one cardinal direction at a time!
- Instead of making a direction array, just double loop through -1, 0 and 1!
- E.g. for int i = -1 to 1, for int j = -1 to 1
- Then you can simply multiply these numbers by a multiplier "k" in a third loop!
- E.g. for int k = 1 to 7 (for an 8x8 grid)
- You can then multiply i and j by k, and add an origin to then search out from that origin!
- This only works if if the grid is small, or you can break the k-loop as soon as you find something, else DFS may not be as efficient as BFS, depends on the problem!


# 877. Stone Game
## 2-player DP
- For questions about 2 players and asking who will win, a neat trick is to not store the 2 player's score's separately
- Instead, store one score, and add when player 1 gains score, and minus when player 2 gains score!
- This allows you to store a single value (the current score) in a DP array, to minimise your state variables!
- You then need to, in your recursive relation, make sure that when it's player 1's turn, to try to *maximise* their score from previous DP states, and for player 2 to *minimise* their score from previous DP states!


# 3081. Replace Question Marks in String to Minimize Its Value
## Lexicographically smallest string tiebreaker
- When tie-breaking multiple correct string answers with the "Lexicographically smallest" one, just sort the string!
- You might not be able to sort the final string if it involves editing an input string, but instead, just sort the order of the characters you input into it!


# 2217. Find Palindrome With Fixed Length
## Size of 1st half, rounded up!
- You can get the first half of a string rounded down easily, just take the first size/2 characters!
- But for rounded up, so 5/2 = 3, then you need to take the first (size + 1)/2 characters!
- E.g. int size = 5; int sizeOf1stHalf = (size + 1) / 2;

## String numbers
- Only use string numbers when necessary! Keeping numbers as numbers when they can fit in a long long is normally faster than string operations!

## Non-string integer reversal
- You can use /= 10 and % 10 to reverse an integer if it is small enough to fit in an int!
- No need to turn the int into a string!
- This only works if you know the number of digits in the number to start with! Because you need to check if it has an even or odd number of digits!


# 432. All O`one Data Structure
## Keeping track of incremental maxs/mins
- A doubly linked list is great at keeping track of the max/min so far
- Combined with a hashmap of a key to its node in the linked list of frequencies (where each node also contains a hashset of all keys with that value), you can keep track of the counts of each key inserted so far in O(1) time!
- So long as incrementing and decrementing is only +1/-1 at a time, you can carefully implement this map + doubly linked list to get O(1) average time complexity for all operations!
- (IncrementKey1, DecrementKey1, GetMax, GetMin)

## Maps of sets, and sets of maps!
- You can have a map contain sets as values, and sets contain maps as values!
- (You just can't have a set be a map's key, or a map be a set's key...)


# 1280. Students and Examinations
## SQL Cross Join
- "Cross Join" is actually useful in SQL! When you are counting the number of records with types of labels, where there may be labels with no records!
- Cross join lets you generate all possible combinations of an ID (e.g. student) and each possible label! (E.g. subject)

## SQL "And" joins
- You can use "AND" in joins!
- This makes it so for a record to show, it has to match 2 different IDs!
- E.g. student_id AND subject_name

## SQL Multiple value "Group By"
- GROUP BY can contain more than 1 value
- When it does, it will condense multiple records that have the same value for ALL given columns into 1 group
- You can then COUNT() or SUM(), or use some other "aggregate" function to count the number groups or otherwise
- Basically, if you're wanting to use WHERE with COUNT(), you're probably looking for GROUP BY!
- In the COUNT() or whatever function, you will have to count the number of some kind of ID that you have GROUP'ed BY, in a different table than you have selected! E.g. Examinations.student_id, not Students.student_id!

## SQL Left/right joins
- LEFT JOIN adds all of the first table's records, regardless if there is a matching ID in the second table or not
- RIGHT JOIN adds all of the second table's records, regardless if there is a matching ID in the first table or not
- If you combine a CROSS JOIN with a LEFT JOIN, you will find all combinations that don't exist in the second table, these records will have IDs with NULL values
- If you then COUNT() and GROUP BY, you will find the total number of records for every group of records with the same column values (that you specify in GROUP BY), that exist

## SQL quick table name aliases
- You can just type "FROM Students s", which will allow you to use "s" as an alias for the table "Students"
- This will save a lot of typing! e.g. SELECT s.student_id, s.student_name FROM Students s


# 1239. Maximum Length of a Concatenated String with Unique Characters
## Bitset duplicate char detection
- Bit sets are great for unique string problems!
- If you only need a 26 size bool vector to check for duplicate characters, just use a bitset<26>!
- You can use bs.set(4) to set the 4th bit to true (and bs.unset(4) to unset)
- Using bitsets will handle all the << >> &, etc operations for you as if you were just using a single 32-bit int! (Check the docs for the max size of a bitset, probably 64)
- You can then do a cool trick for finding a string with duplicate characters, just set each bit to true for every character's ASCII code - 'a'
- Then check if the count of set bits (bs.count()) equals the number of characters int the string! (s.size()) i.e. bs.count == s.size()

## All in-order permutations of array elements
- If you're trying to find all permutations of an array, where you only want the permutations of array elements in order (skipping elements allowed), there's a neat iterative approach!
- Initialise a "DP" array of sets, starting with 1 empty set
- Then iterate over each array element
- Then if your array element passes criteria, iterate over all elements in the set array
- It is better to iterate over all DP array elements in reverse order, as this will maximise the depth of the last element in the DP array (but it may not matter depending on the question)
- If the union is valid, union the current set with the current DP array set, and add it to the DP array of sets!
- Then keep a running sum, max, etc, so far for the current union, or simply count the number of permutations after iterating over all input array elements! (Whatever the question asks)
- This only works for sets with a limited number of values, or input arrays with a limited size! (Else, the usual DFS backtracking approach works well here)


# 208. Implement Trie (Prefix Tree)
## Trie node storage
- Instead of storing the current letter as a char in a node, you can just store a "children" array with 26 indexes! (If only lowercase English characters, else use a map from char to Node*)
- Then using the ASCII trick, you can create a new node inside the corresponding index of the children array, based on the current letter you are inserting!
- You can then tell if it's the end of a word by adding a isWord bool flag to each node
- And that the word is not in the prefix tree if the current char in word does not have a corresponding child in the current node!
- Then to initilise the Trie, just create an empty head node! All prefix tree nodes start off with an empty children array/map!
- It's the connection between the current node and its child that represents a character, not a character value in the node itself!
- The head node represents the empty string, if its isWord flag is set to true!


# 2085. Count Common Words With One Occurrence
## Helper functions
- If you're making a helper function to avoid iterating over 2 arrays one at a time, it might be faster to just iterate one at a time, if the loops are very simple!

## Simplifying the solution
- Don't be afraid to go with your gut instinct for an easy question, just make the brute force and simplify from there!
- Spend time making sure you're answering the right question, rather than worrying about complexity to start with!


# 179. Largest Number
## Finding the largest concatenation between 2 numbers
- First, change both numbers into strings
- Then make both possible concatenations of both numbers, first number then second, and second number then first
- See which number in both concatenations are larger
- Sort the 2 numbers by which concatenation was larger!
- Finally, if you have an array of these numbers, sort them by this criteria, then loop through the sorted array and concatenate all elements in order in the array!

## Lexicographical string number comparison
- You can compare 2 numbers as ints with < or >, even if the numbers are strings!

## Space complexity of std::sort()
- std::sort() has a space complexity greater than O(1)! (Even if sorting in-place!)
- This extra space comes from the Quick-Heap-Insertion sort hybrid c++'s sort() function uses!
- The space complexity is O(log n) (The time complexity is obviously O(n log n))


# 30. Substring with Concatenation of All Words
## Comparing big string to small strings *of same length* (No sliding window O(n^3))
- Instead of copying a frequency map for each iteration, just slowly build one up, by counting upwards each time there is a match, and compare that count with the original frequency map!
- Try to make a helper function to check if a valid starting index is a valid substring!
- You know that each valid substring is going to be the length of a small string * the number of small strings!
- Sometimes making a hashmap and saving potential starting indexes is a bad idea... There might not be saving any time by caching potential answers, if you have to quadratically search through a string to find the potential answers anyway!
- Instead of iterating (to the end of the string - some constraint size) at the end of each loop, just iterate from the starting index, up until (the starting index + max answer size)! (It will save a lot of time!)

## Comparing big string to small strings of *same length* (Sliding window, O(n^2)!)
- This method runs independently of the number of smaller strings you have!
- Sliding window method to comparing a big string to many smaller strings *only works if the smaller strings are all the same size!*
- The key thing is to move the left sliding window pointer, until there isn't an "excess" word any more!
- As soon as an excess word is encountered, you have to keep moving the sliding window's left side until the excess word's count is under the limit
- If an invalid word is encountered, you have to move the sliding window's left and right pointers to the next potential word, 1 word after the right pointer's current position
- You only need to set off the sliding window from index 0 to wordSize amount of times! This is because you only need to try each offset of the sliding window once! E.g. for index wordSize + 1, the sliding window looks at the same sets of characters as index 0, except for the first potential word


# 13. Roman to Integer
## Map -> Switch statement!
- If the input is limited enough, it might be worth replacing a map with a switch statement
- Always consider if a map can be replaced by a switch statement! If your logic is simple, it may be doable, and you save the map's space, AND the time to build the map!


# 2250. Count Number of Rectangles Containing Each Point
## Binary Search constraints
- If the constraints are one number is very large, but another related number is very small, e.g. coordinates, you're probably wanting to do binary search!

## Shapes with one short length
- You can map all the shapes with the same shorter length, and contain a set of all the shapes with that length!
- In the case of a rectangle, you could map all rectangles of a certain height, to all the widths with that height!
- From there, you can do something like sort the widths for each height and perform binary search!

## Getting the middle index for binary search
- To get the middle index for binary search, do: middle = left + (right - left)/2
- This means you have ignored everything on the left of left, and are now looking at the middle element on the right hand side

## Binary search with "std::lower_bound()"
- You can perform an easy binary search by using std::lower_bound()!
- Basically, you pass the 2 iterators to an container with sorted values...
- Then, you give the target value as the 3rd argument...
- And finally, it returns an iterator to the first value in that container that that is equal to or greater than the target value!
- i.e... A lower bound!


# 451. Sort Characters By Frequency
## Sorting by frequency
- The easiest way to sort by frequency, is to first count the frequencies of your container
- Then, simply place the keys of the frequency map into an array, and sort the array based on the frequencies!
- Then you can re-create the array by looping through all sorted keys, and repeatedly adding the key as many times as it appears in the frequency map to the final sorted-by-frequency array!

## Bucket sort
- Buuut... an even better way to sort elements by frequency, is to use bucket sort!
- Bucket sort is one of the few sorting algorithms with O(n) time, buuuuut it usually comes at a hefty cost of space!
- Bucket sort places keys based on their values, basically a reverse map, but sorted in O(n) time!
- Most useful when wanting to sort a map by value with a lot of keys, but not many possible values!


# 2032. Two Out of Three
## Counts from multiple arrays, and limited possible values to count
- If creating a value bank for more than one array at once, it may be more space efficient to use a 2D vector where the first index is the array number, and the second index is the count of that number in the array, where the index represents the number!
- If your output is very limited, e.g. there's only 101 possible numbers to have to count, just use a vector of size 101!
- When the values to count are integers, and the number of possible values is low, just use a vector of vectors!

## Seeing if a value is contained between x number of containers
- If all you're seeing is if a value is contained within a set of containers, *don't count! Just use a bool!*

## Bool vector to bitmask
- While the compiler will optimise a bool vector to a bit mask, you can directly use a bitmask when the approach is simple!
- If you have many 3-long bool vectors, just have 1 vector of ints, initialised to 0, and bit-push 1 to the left 0, 1, or 2 times if the number appears in vector 0, 1, or 2!


# 993. Cousins in Binary Tree
## DFS layer-finding pruning
- If you are finding if 2 nodes are one the same layer of a binary tree, stop the search if you are searching bellow the first found layer!
- When performing DFS, always, always, always see if you can prune the search!!!

# Tree-layer comparing
- If ever you are trying to compare values between a layer of a tree, *use BFS!*
- Level-order traversal is much more natural for any problem involving comparing the values of the layer of a tree!


# 1722. Minimize Hamming Distance After Swap Operations
## Infinite array swapping
- If you are allowed to swap values in an array an infinite number of times, in any order, *you don't have to simulate the swapping!*
- Just use a DSU to get the different sets of elements that can be swapped between each other!


# 1536. Minimum Swaps to Arrange a Binary Grid
## Finding minimum adjacent swaps
- For a minimum adjacent swaps question, you want to use a *greedy* approach!
- Basically, you want to find the first value in the list that meets the requirement, then swap that value up the list with bubble sort!
- Minimum swaps = greedy for most questions, just bubble sort the list, looking for the first valid value!


# 2818. Apply Operations to Maximize Score
## Things to look up:
- Sieve of eratosthenes, divide number by each smaller prime to get number of prime factors
- Monotonic stack, multiply number of valid left positions by valid right per largest num
- Used to find the number of valid sub-arrays quickly, without for for O(n^2) loop
- Efficient calculate pow(), to make a powWithMod() function, in a mod 10^9 + 7 question
- Add pow(nums[i], sub-array count) to score at each iteration
- This question: https://leetcode.com/problems/largest-rectangle-in-histogram/description/


# 2006. Count Number of Pairs With Absolute Difference K
## Count vector vs. count map
- If the constraints are tight, *always use a vector count when you can over a map!*
- Using a map<int, int> over a vector uses more memory!


# 143. Reorder List
## Finding the middle node in a linked list
- Use the "Tortoise and Hare" algorithm!
- Increment a "fast" and "slow" pointer where the fast pointer travels twice for every time the slow pointer travels once!
- Make sure your while loop stops once the fast pointer has reached the end (odd number of nodes), or has gone 1 beyond the end! (even number of nodes)
- i.e. while (fast != nullptr && fast->next != nullptr)

## Reversing a linked list
- Make 3 pointers, "prev", "curr" and "tmp"
- Then set these 3 pointers to a nullptr, the head, and the head, respectively
- Then, simply traverse through the list, pointing tmp to tmp->next, curr to prev, then setting prev to curr, curr to tmp, moving each pointer down the list one node at a time!
- Finally, stop looping once curr is null!

## Merging two linked lists
- To slot together 2 linked lists, where the a's first points to b's first, then a's second, then b's second, etc.
- With the heads of the 2 lists, save each of their next nodes
- Then, point a's head to b's, then point b's head to a's next node
- Then set the heads of a and b to their saved next nodes, and continue until the next node of a's head or b's head is null!
- Finally, point a's head to b's, and point b's head to a's next node, if it isn't null!


# 746. Min Cost Climbing Stairs
## Easy DP
- Just because a question is easy, doesn't mean it can't be dynamic programming!
- Have to make decisions that depend on the decisions made previously = DP!
- Always start with the recursive DP! From there it is much easier to see the iterative approach!
- The first step, is always to look for a "recurrence relation"! Not always possible with complex DP, but this will make writing a recursive 1-liner much easier, and therefore make converting to an iterative solution very possible!
- Don't forget to look for space optimisation when doing iterative DP!


# 1400. Construct K Palindrome Strings
## Counting odd/even numbers
- Use a bitset! You can just flip the bit every time you encounter the number, and if it is flipped, that number is odd!
- This only works when you have a small number of unique numbers/characters to possibly find in the array to count their occurrences
- You can then use bitset.count() to count the number of flipped bits!


# 278. First Bad Version
## Binary search!
- To find the middle index, and always have an index available on the left for even numbers of indices, use: "middle = left + (right - left) / 2"!
- Doing this instead of (left + right) / 2 will avoid integer overflow!
- Be warned that for even numbers, this gives you the left-middle element! (The other way gives you the right-middle!)
- Typically binary search ends once left >= right, so do: "while(left < right)", but "right - left > 1" works as well!


# 1217. Minimum Cost to Move Chips to The Same Position
## Counting odds or evens shortcut
- To count the number of odd or even values in an array, just count one of them! Then, to get the count of the other, just take evenCount = array.size() - oddCount, or oddCount = array.size() - evenCount!


# 3286. Find a Safe Walk Through a Grid
## Dijkstra's!
- Just BFS with a priority queue... but it also has a "bestCost<node, int>" array! (E.g. bestCosts[x][y] = cost!)
- Basically, you need to keep track of the best cost so far seen for reaching a node
- Then, *only add to the priority queue if the node's cost is better!*
- Initially, the best cost for each node is -1, for lowest cost, or 0 for highest cost
- So, every unvisited node always has its cost updated, which automatically tracks which nodes are visited or not for you! (No need for a hashset of visited nodes!)
- Dijkstra's can even work for these types of questions that look like an A*-search type of grid questions
- If you have a grid, consider if you can use Dijkstra's, and figure out the question's potential "cost" to turn it into finding the shortest path!


# 3399. Smallest Substring With Identical Characters II
## Minimum number of separators needed to divide array of size n into at most k-sized sub-arrays
- *Each separator replaces the value at that spot in the array!*
- Given by separatorCount = n / (k + 1)
- Apparently the number of operations to turn a binary string of size n into groups of same digits with size less than or equal to a given size is operations += currentGroupSize / (givenLength + 1), whenever you find the end of a group
- This is because the number of sections with k dividers is k + 1, and you want to have n total groups, so if you want groups of 3s, you want to place a divider at every 4th index, therefore 4 total sections, therefore you can fit arraySize / 4 complete 3-sized sections, therefore: n / (k + 1) !

## Binary search with min-max substring problems
- You can use binary search with some min-max substring problems, if you're clever about what ordered number you're actually searching!
- You might be able to just binary search the answer directly! But you need a method of how you're going to decide to search the left or right of the answer!
- When deciding to go to the left or right of the answer, *you don't necessarily use the value of the answer!*
- Instead, you might use some criteria you can calculate from the input, that takes in the answer guess (middle) as an input, and outputs a calculated value that is linked to the answer indirectly!
- Basically, if this calculated value is greater than something from the question input, then that *implies* that the answer must be smaller (or larger) than what was guessed (middle)!
- And hopefully this indirect value should be easy to calculate!
- Typically you do: while (left <= right)
- guess = left + (right - left) / 2;
- int indirectQualifier = getQualifier(array, guess);
- if (indirectQualifier > questionArgK) left = guess + 1;
- else right = guess - 1; answer = guess;
- return answer;


