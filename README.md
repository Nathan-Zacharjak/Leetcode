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

