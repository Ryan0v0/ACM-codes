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

### 2. Add Two Numbers

~~这道题去年做过2333 今年还是不会写指针的zwr~~

