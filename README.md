## 22

1. 错误的思路：归纳法

当 num == 1 时，()

当 num == 2 时，在 1 的基础上进行两种加工：

    1. 两侧分别加一对括弧的效果时一样
    2. 把情况 1 用括弧包起来

无奈当 num == 3 时，我不知道怎么在 2 的基础加工出 3。

2. 括弧一个一个进栈

令栈内 `(` 的数量为 leftNum
令栈内 `)` 的数量为 rightNum
    1. 新建一个栈，`(` 进栈
    2. 当 leftNum == n 时，剩余的 `)` 进栈，该栈完整，加入栈列表 List<Stack>
        否则，当前栈复制为两个栈，其中一个 `(` 进栈另一个 `)` 进栈
    3. 遍历当前所有的栈，直到都加入栈列表中
    
#### 不知道递归的解法时如何想出来的。我只能从这种循环的解法再推递归的解法

先构造一个递归方法

```
dfs()
```

递归的尽头是解空间的一个解。所以循环跳出的条件为

```
if (rightNum == n)
{
    list.add(stack);
    return;
}
```

其它部分的代码就是老老实实地分道扬镳

```
if (leftNum < n) dfs() // 这个对应一个解空间
if (rightNum < leftNum) dfs() // 这个也对应一个解空间
```


#### 22 结束

## 39

见 22 题
## 46

见 22 题

这道题有个地方要说一下

p 方法里的形参的类型若为引用类型时占用的内存更少

当类型为非引用类型时，占用 11.8 MB 的内存，

而当类型为引用类型时，占用 10.5 MB 的内存。
