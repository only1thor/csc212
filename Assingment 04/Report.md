# Report
_Author: Thor Christian Cusick, 100667449_
## Circularly linked list.
I chose to use a circularly linked list. 
The list only uses 1 pointer in the list class, it is called "current", and it moves along the list like the head of a record player. 
since the insert function inserts items after the previously added item, and moves the pointer to point at the new item, after reading a file, the "current" pointer is at the last element. and due to the circular nature of the data structure, the move function can be called with the argument "1" to move the current-pointer to the fist item inserted, witch allows the output to be in the same sequence as the input file. 

Each node has a next, and a neighbor (named nabo in the class) pointer. The next pointer is of course a pointer to the next element in the list and is updated on the node currently pointed to when the insert method is called, and the new node is inserted and pointed to the next node in the list (or circle). 

<img src="http://tcuc.info/pic/files/CirularList.png" alt="" style="width:50%;">

## Find nearest neighbors Method.
to be able to generate the javascript file (looks more like a csv, but still), the nearest neighbor must be found so that the visualizer can draw connections. 

### Explanation.
The find nearest neighbors method, sets all the pointers in each node to the address of the node with the shortest euclidian distance to itself via the distance method. The distance method simply applies the equation: <img src="http://tcuc.info/pic/files/dist.png" alt="" style="width:35%;"> between the "*current" node and the node passed as an argument.  

### Runtime.
The method runs from the "*current" node, through the entire size of the list. the size is found from the size function, it simply returns the size variable that is incremented every insert.  
The method uses nested for loops to check every node to every other node (but not itself). 
the runtime is therefore: <img src="http://tcuc.info/pic/files/theta.png" alt="" style="width:7%;">! or exactly: n(n-1). 


## Figures.

| 5yzm | 1mro |
| --- | --- |
|<img src="http://tcuc.info/pic/files/5yzm.gif" alt="" style="width:100%;"> | <img src="http://tcuc.info/pic/files/1mro.gif" alt="" style="width:100%;">|
