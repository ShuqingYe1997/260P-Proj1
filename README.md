# Project 1
Write a subroutine in C that will efficiently solve the following problem involving an array of n **distinctly-valued** elements.  
Determine the array indices of those elements having the k largest values, in descending value order, using as few element comparisons as possible.  
You will **NOT** have access to the elements, only to the results of comparing elements by using the provided **COMPARE** function.  

## Compile & Run
```Bash
gcc MAIN.c -o MAIN
MAIN > output
```
## Results
```C
// Binary Search
n=10000,  k=40:  maximum= 11583,  avg=11334.12

// Sequential Search
n=10000,  k=40:  maximum= 16609,  avg=15388.86
```
## Report
For more details, please see [report](/report/report.pdf).
## Criteria
| Avg Case  | Points|
| ---------- | -----------|
| < 10480   | 30   |
| < 10500   | 25   |
| < 10700   | 24   |
| < 11000   | 23   |
| < 11300   | 22   |
| < 11600   | 21   |
| < 12000   | 20   |
| < 12500   | 18   |
| < 13000   | 15   |
| < 15000   | 10   |