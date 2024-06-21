# Odd Duplicates

There is an array of size n, find the duplicate values in a function and print another array containing only the repeated and odd ones.

### Example 1:
> Input: [0,1,2,3,4,4,1,5,5,7,7]
> 
> Output: [1,5,7]
>
> Explanation: Traverse through the array to identify elements that appear more than once. In this case, the duplicates are 1, 4, 5, and 7.
> After identifying duplicates (1, 4, 5, 7), filter out those that are odd numbers. Odd numbers among the duplicates are 1, 5, and 7.

### Example 2
> Input: [2,4,6,8,10,2,4,6,8,10]
>
> Output: []

### Example 3
> Input: [3,3,5,7,8,2,9,5,7]
>
> Output: [3,5,7]

#### Constraints
- 0 <= n <= 20
