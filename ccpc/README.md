## 比赛注意

1. 看清题目的限定条件：操作的元素是否相邻、整数区间划分成的区间是否必须是整数、最大化的个数是distinct还是总数

2. 精度问题的坑

   `int sgn(double a){return a < -eps ? -1 : a < eps ? 0 : 1;}`

   | 传统意义 | 修正写法1       | 修正写法2         |
   | -------- | --------------- | ----------------- |
   | a == b   | sgn(a - b) == 0 | fabs(a – b) < eps |
   | a != b   | sgn(a - b) != 0 | fabs(a – b) > eps |
   | a < b    | sgn(a - b) < 0  | a – b < -eps      |
   | a <= b   | sgn(a - b) <= 0 | a – b < eps       |
   | a > b    | sgn(a - b) > 0  | a – b > eps       |
   | a >= b   | sgn(a - b) >= 0 | a – b > -eps      |

3. LL的坑

4. 卡时限

   STL的size()函数也是有常数的，所以循环次数多时尽量不要用

   例如: for(int i=0; i<a.size(); i++) 可以把他改成 for (int i=a.size()-1, i>=0; i--)

   在卡时限的时候比较有用

   另外struct的构造函数也是有常数的

5. 表达式求值时注意运算符优先级

   