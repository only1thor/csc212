# notasjon fra første quiz. 

floor ⌊⌋ : 
the largest integer that is below or equal to a number.
5.9 -> 5
5.0 -> 5
6.1 -> 6

ceil ⌈⌉:
the smallest integer that is greater or equal to the number.
5.9 -> 6
5.0 -> 5
6.1 -> 7

# amount of resources needed for given program:
time Complexity (running time) 
this is time as a function of input size
T(n)= whatever, the actual equation is dependent on the operiation of 
the algorythm. 

Space Complexity (memory usage)
the amount of memory used by the alorithme. 

from: 
https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/index.html
6.3
6.4
6.5


# lest under undervising
8.2.1.5 - en animasjon av problem, algorytme, og et program. 


# til å se på etter timen:
8.2.1.5 - en animasjon av problem, algorytme, og et program. 

https://opendsa-server.cs.vt.edu/ODSA/Books/Everything/html/index.html
6.3
6.4
6.5

# empirical analysis
- implement alg
- run on different input sizes
- record actuall runnig times
- calculate hypothesis
- predict and validate. 

limitations: 
- requires implementing multiple algs for the same problem
	- may be diggicult and timeconsuming
	- implementtation details also play a role (one partiular alg 
	  may be "better written")
- requires extensive testing
	- time consuming
	- choice of testcases might favor one of the algs. 
- variations in HW, SW, and OS affect analysis. 

# Mathematical Modeling
-high-level analysis - no need to impliment
- computatianal cost number og basic operations required by the alg to 
imput... too sloooow. 

- analyze alg
- develop alg. 



# find upper bounds.
prove that:
20n^3+10nlogn+5=O(n^3)
since:
20n^3+10nlogn+5=<35n^3

c=35
n0=1









<=> // if and only if
| // such that. 

# invariance
in selection sort, the left side of the array is allways sorted. 
so if some code stays true to this, then it is a valid implimentation. (no invariance).


# Sorting algs, what's the most efficient. 

## Insertion sort.
an inversion is a pair of keys that are out of order. 
(it's basically a swap)
for partially-sorted array, insertion sort runs in linear time. 

## Stability. 
a stable sorting alg will preserve the order of items of the same value. 

take listing a plane departure table as an example. 
if the alg is stable and the list is sorted by departure times, and you 
sort it by name of destination, the times of the departures for a single 
destination will be in order of departure time. 

if the alg is not. you will get a jumble. 

### note: 
long distance swaps cause an alg to be non-stable. 
insertion sort is strable. 

# summary
table: 
|     | best case | average-case | worst-case | stable? | inplace? |
| --- |---	| ---		| ---		| ---   | ---	|
| selection sort | 0(n²) | 0(n²) | 0(n²) | no | yes |
| Insertion sort | 0(n) | 0(n²) | 0(n²) | yes | yes | 


# check out:
teptal.com sorting algorithms animation. 
# Title

## find preconditions for your functions
- ask for expected input range. 
- make sure inputs are correct, do tests. 
	* assert - terminate if false ( assert(n>0); usefull for debugging only.) 
	* trow, try, catch ( trows exception that can be cought later)
	* or just let the program misbehave, or crash at some point. 

## making a recursive function:
- solve the task by using smaller tastks of the same structure. 
- technically, a recursive function is one that calls it self. 
- in general form:
	* base case (solution for trivial case)
	it also used te stop the recursion. 
	* recursive calls.


# backtracking
- exhaustive search
	* preform a treaversal through all possible elemunts of a search space
- backtracking
	* "purine"ing a branch when further recursion is necessary. 
	(recall the n-queens problem.)
## problems that exemplify backtracking
- n-queens problem
- sudoku solve. 
- maze traversel.
## parts of memory


os kernel
stack (local vars, and functions)
shared libs
heap (Dynamic memory)
read/write segment .data .bss
readonly Segment .text .rodata (this is where the code is)

### mem during execution
int f(int,int);
int g(int);

int main(int argc, char** argv){
	int n1 = f(3,-5);
	n1=g(n1);
}

int f(){
	int x;
	int a[3];
	//....
	x=g(a[3]);
	return x;
}

os
stack
main(argc, argv) and n1 (this is a frame)
.
.
.


when f() is executed, it, and all its vars are loaded into mem as a new frame.

as functions are called they are loaded into mem.
And when the function ends, and returns its value.
It will be removed from mem.


### pointers:

- it points to somewhere int the process' virtual space.
- &foo produces the virtual address of foo. (the address in mem wher foo is stored.)

int x; //just a var.
int *p; // this is a var that can store mem addresses.
	// can also be written: int* p;
p=&x; //loads address of x into p.
*p=56; //puts 56 in x. since p refers to the address of x.


int *p1, p2; // this makes one pointer p1, and one int p2.


