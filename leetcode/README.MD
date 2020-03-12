Way to Google SWE Intern

### 3. Longest Substring Without Repeating Characters

一眼双指针。但还可以再优化。只需记录每一个数字最近出现的位置即可完成跳转。

### 11. Container With Most Waters

很有趣的题，考虑从两边到中间贪心。注意和最大子矩阵区分，不满足单调性，故无法用单调栈求解。

### 15. 3Sum

思考角度很重要。

重难点在于如何处理unique三元组（组内可有重复元素），故切记不可排序

利用单调性+”双指针“的思想，可以在不增加空间复杂度的前提下，将$O(n^2logn)$优化为$O(n^2)$

### 31. Next Permutation

有固定解法（From [Wikipedia](https://en.wikipedia.org/wiki/Permutation#Generation_in_lexicographic_order)）

1. Find the largest index `k` such that `nums[k] < nums[k + 1]`. If no such index exists, just reverse `nums` and done.
2. Find the largest index `l > k` such that `nums[k] < nums[l]`.
3. Swap `nums[k]` and `nums[l]`.
4. Reverse the sub-array `nums[k + 1:]`.



## Linked Lists

### 2. Add Two Numbers

~~这道题去年做过2333 今年还是不会写指针的zwr~~

### 19. Remove Nth Node From End of List

双指针面试经典题

### 21. Merge Two Sorted Lists

也算是双指针的一种，在归并排序的每层处理中用到

注意最后剩余的那部分，直接tail指向当前头指针就好

### 138. Copy List with Random Pointer

这个题很有趣！用到的链表写法也很重要



## Trees and Graphs





## Recursion

6996

6969

s[i] = rev(s[n +1 - i])

n -> n + 1

n - 1

1,1

6,9

8,8

0,0



### 208. Implement Trie (Prefix Tree)

Trie树模板

Trie树在Google面试中似乎考得挺多的



### 17. Letter Combinations of a Phone Number

![image-20200311211940728](https://tva1.sinaimg.cn/large/00831rSTly1gcqaxti3cij30x80a4n19.jpg)



### 22. Generate Parentheses

递归思路解括号序列问题



### 351.Android Unlock Patterns

对于任意两个点的坐标（x1，y1），（x2，y2），如果((x1+x2)%2==0 && (y1+y2)%2==0)，说明两点连线之间存在一个中点((x1+x2)/2, (y1+y2)/2)。如果这个中点被访问过，则这两点是可以连通的；如果中点没有被访问过，则两点不能连通。如果两点间不存在中点，则两点也是可以连通的。



### 57. Insert Interval

（这题竟然是hard难度？我惊了）

![image-20200312005805272](/Users/zhaowanru/Library/Application Support/typora-user-images/image-20200312005805272.png)

除了上图之外，还要考虑inter将newInterval完全覆盖的情况，注意输出顺序即可