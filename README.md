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

