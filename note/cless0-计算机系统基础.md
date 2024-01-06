# c语言基础

### c语言运行过程：
    .c -> 预编译 -> .i -> 编译 -> .s -> 汇编 -> .o -> 链接 -> a.out
           -E             -S            -C

### include
#### <> 引入的头文件和 ""引入的区别
    它们都是把一部分文件复制粘贴过来
    是直接去c的库中去找
    ""是现在当前项目中找，然后去c中的库中找

#### include到底是什么意思

其本质就是复制粘贴他会把引用的东西原封不动的复制过来因此可以实现一些比较有趣的实验
```c
#include <stdio.h>

int main()
{
    printf(
#include "b.inc"
    );
}
```
像这种代码直接使用gcc编译是不会报错的就很神奇，并且会把include引入的东西放到printf中

### 预编译的过程

预编译的时候会把所以的宏执行下面有段代码
```c
#include <stdio.h>

int main()
{
#if aa == bb
    printf("Yes\n");
#else
    printf("No\n");
#endif
}
```
其会返回Yes这是为啥呢 因为在预编译的阶段aa和bb都是两个宏c语言设计的时候是不会声明这样子的名字的因此两个都为null因此返回为Yes

使用gcc -E我们可以查看预编译的结果
```c
int main()
{
    printf("Yes\n");
}
```
我们发现预编译的时候会替换宏因此就可以搞一些好玩的例如
```c
#include <stdio.h>

#define true (__LINE__ % 2 == 0)
int main()
{
    if (true)
        printf("yes, %d\n", __LINE__);
    if (true)
        printf("yes, %d\n", __LINE__);
    if (true)
        printf("yes, %d\n", __LINE__);
    if (true)
        printf("yes, %d\n", __LINE__);
    if (true)
        printf("yes, %d\n", __LINE__);
    if (true)
        printf("yes, %d\n", __LINE__);
}

```
我们用宏去修改true的值在这个代码中指挥打印奇数行的printf 如果多按一个回车就会导致一个都不打印