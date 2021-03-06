[趣学C语言](https://www.bilibili.com/video/BV1NE411A74T?p=24)

# 数据类型和变量

## 字面量

字面量也叫常量，指的是数值固定的常量。“一眼就能看出来”。在程序中，常量只能被引用，不能被修改。

### 1. 整型（整数类型）

```C
printf("%d", 300);
```

### 2. 浮点数

```c
printf("%f",2.2);
```

- 默认输出保留到6位

### 3. 字符型

在程序中，使用英文单引号括起来的字符被称为字符型。

```c
printf("%c", 'A')
```

### 4. 字符串

在程序中，使用英文双引号将若干字符括起来的都是字符串

```c
printf("hello world!")
```

## 变量

在C语言中，一个合法的变量由3部分组：

- **变量类型**：变量的类型是用来规定变量对应内存空间的大小和能盛放的东西
- **变量名**：变量名是用来标记变量对应的内存空间，通过变量名就可以精准地找到变量对应的内存空间
- **变量值**：变量值是变量名标记的内存空间中的数据

## 标识符与关键字

### 1. 标识符

在C语言中，用来对变量、函数、数组等命名的字符序列被称为标识符。比如变量名、a、函数名printf都叫标识符。

C语言对标识符有以下规定：

- 只能用26个**英文字母**、**数字**或**下划线**3种字符组成
- 第一个字符只能是**字母**或**下划线**
- **大小写**敏感的
  - C语言是严格区分大小写的，比如max,Max,mAx,maX就是4个不同的标识符
- 不能全部是关键字

### 2. 关键字

C语言中具有特殊用途的单词称为关键字，当定义标识符时，不要让标识符和关键字相同，否则编译无法通过。

比如break,case,char,const,for,if,void,int,long

## 基本数据类型

### 1. 整数类型

```c
int a = 200;
printf("%d", a);
```

### 2. 浮点数类型

#### 单精度浮点数

```c
float a = 3.14f;
printf("%f", a);
```

#### 双精度浮点数

```c
double a = 3.14;
printf("%lf",a);
```

> C89语法要求所有变量都要提前进行声明

### 3. 字符型

```c
char c1 = 'a';
printf("%c", c1);
```

### 4. 转义字符

在C语言中有一类特殊字符，该类特殊字符是以字符\开头的字符序列，例如'\n'，它代表一个换行符。这类字符无法用一般形式表示，只能采用这种特殊的形式表示，这类字符被称为转义字符。

- \\"表示普通的双引号
  - C语言中字符串以双引号开始和结束
- \\\表示普通的反斜线
  - C语言中反义字符以反斜线开始
  - \\\\\\\表示两个反斜线

> 在C语言中是没有字符串类型的，字符串本质上是由单个字符构成，使用双引号括起来。在printf中使用%s输出字符串。
>
> 字符串被拆分为单个字符存储，输出时也按照存储的顺序连续输出。

| 占位符 | 类型   | 说明                                            |
| ------ | ------ | ----------------------------------------------- |
| %d或%i | int    | 以十进制输出                                    |
| %f     | float  | 可以指定精度，%.2f就是保留两位小数              |
| %lf    | double |                                                 |
| %c     | char   | 也可以用%d输出char，这时候输出的是字符的ASCII码 |
| %s     | 字符串 |                                                 |

## 注释

### 单行注释

```c
// 这是一个注释
```

### 多行注释

```c
/*
注释1
注释2
注释3
……
*/
```

## 变量

### 定义变量

```
变量类型 变量名 = 变量值
```

```
变量类类型 变量名
变量名 = 变量值
```

### 引用变量

**变量赋值**：给变量进行赋值

```
变量名 = 变量值
```

**变量取值**：读取变量中保存的数据

```
变量名1 = 变量名2
```

### 定义多个变量

```c
int i,j,k;
i = 1;
j = 2;
k = 3;
```

```c
int i = 1, j = 2, k = 3;
```

## 语句和语句块

在C语言中，程序执行的最小单位是语句，一条合法的语句必须在末尾有一个分号。C语言中常用的语句由以下5种：

- 赋值语句
- 函数调用语句
- 空语句
- 复合语句（语句块）
- 控制语句

### 赋值语句

赋值语句是C语言中最基本的语句，需要使用赋值符号=，该符号的作用是将一个数值赋给一个变量。

```c
int i;
i = 100;
```

### 函数调用语句

函数调用语句是C程序中比较常用的语句，由函数调用和分号构成，例如

```c
printf("Hello World!");
```

```c
getchar();
```

### 空语句

该语句只有一个分号

```c
；
```

### 复合语句（语句块）

复合语句又叫语句块，在程序中使用{}将多行语句括起来就可以成为复合语句。例如

```c
{
    int a, b, c;
    a = 1;
    b = 2;
    c = 3;
}
```

左花括号表示复合语句开始，右花括号表示复合语句结束，复合语句不会影响程序的正常执行，常常和控制语句一起使用。

复合语句之间可以进行嵌套

## 程序结构

### 顺序结构

顺序结构是C程序中最简单的程序结构，顺序结构的程序从第一行语句开始，按照代码排列的顺序，从上到下依次逐句执行，上一条语句执行结束后吓一跳语句才能执行，直到最后一条语句结束。

## 变量需要注意的问题

### 变量必须定义才能使用

### 变量的声明必须在方法的最开始

C89标准要求所有变量的声明必须放在方法的最开始，VS2012执行的是C89标准

VS2019执行的是C99标准，可以不把所有变量的声明放在方法的最开始

### 变量重名问题

C语言规定，同一个作用域内变量定义不能重名

## 局部变量

C语言中，变量的定义的位置可以分为3

- 在函数内定义
- 在函数内的语句块中定义
- 在函数外部定义

函数内部定义的变量称为局部变量，在函数外部定义的变量称为全局变量。定义在main函数中的变量都是局部变量。

### 局部变量的作用域

变量的作用域指的是变量的有效作用范围，局部变量的作用域仅限于函数内部以及语句块中。局部变量的作用域需要分两种情况来讨论

- 在函数内部定义的变量只在本函数范围内有效，也就是说只有本函数内才能引用，本函数之外都不能引用这些变量
- 在函数内部语句块中定义的变量，只在本语句块范围内有效（包括该语句块内嵌套的其他语句块），也就是说只有在该语句块内才能引用，该语句块之外都不能引用这些变量
- 语句块中可以定义变量，也必须在语句块之前

> 局部变量的作用域仅限于大括号！

### 局部变量在使用之前必须初始化

# 运算符和表达式

## 算术运算符

### 常用算术运算符

```c
+ //加或正值
- //减或负值
* //乘法
/ //除法
% //求余
```

### 算术表达式

将算数运算符、小括号、操作数连接起来，符合C语言规则的式子被称为算术表达式，参与运算的操作数可以说字面量、变量、函数等。

### 算术运算符的优先级

## 赋值运算符和赋值表达式

### 赋值运算符

赋值运算符的优先级最低

### 赋值表达式

将赋值运算符、小括号、操作数连接起来，符合C语言的式子称为赋值表达式，参与运算的操作数可以是字面量、变量、表达式、函数等。

赋值表达式左边只能是变量。

C语言中任何一个表达式都会产生一个结果值，赋值表达式也是如此。赋值表达式的结果就是赋值运算符左边被赋值变量的值

```c
int a = 1;
printf("%d", a = a + 1); //输出2
```

### 复合赋值运算符

```
a += 10; // a = a + 10
a -= 10; // a = a - 10
a *= 10; // a = a * 10
a /= 10; // a = a / 10
a %= 10; // a = a % 10
```

## 自增、自减运算符

```c
int a = 100;
int b;
b = ++a; //b = 101
b = a++; //b = 100
printf("%d", a++); //输出100
printf("%d", ++a); //输出101
```

- 自减与自加类似

## 关系运算符与关系表达式

```python
<
<=
>
>=
==
!=
```

```c
printf("%d", 1>0); // 输出1
printf("%d", 1<0); // 输出0
//C语言没有bool类型。0代表假，非0代表真
```

将关系运算符、小括号、操作数连接起来，符合C语言规则的式子被称为关系表达式，参与运算的操作数可以是字面量、变量、表达式等。



## 逻辑运算符和逻辑表达式

```python
&& 逻辑与（双目运算符）
|| 逻辑或（双目运算符）
！ 逻辑非（单目运算符）
```

将逻辑运算符、小括号、操作数连接起来，符合C语言规则的式子被称为逻辑表达式，参与运算的操作数可以是字面量、变量、表达式等。

## 条件运算符与条件表达式

```c
int a = 3;
int b = a > 4 ? 5 : 8;
printf("%d", b); //输出为8
```

- 冒号两边的类型一致！

## `sizeof`运算符 

求字节数运算符`sizeof`用于计算变量、字面量、类型所占字节数。该运算符是C语言中唯一一个使用单词作为运算符的。返回括号中的类型在当前系统下所占字节数，括号中的类型可以是字面量也可以是数据类型。

# 选择结构

## `if`语句

```c
if (<test>)
{
    //code to execute if <test> if true
}
```

```c
int r = 8;
if (r > 18);
{
    print("hello!");
}//最终会打印出hello，注意分号

if (r > 18)
    printf("hello!");
	printf("nihao!");
//最终会打印出nihao
```

- if语句块结束后可以加分号也可以不加分号

```c
if (<test>)
    // one line code to execute
```

```c
if (<test1>)
{
    //code to execute if <test1> is true
}
else if (<test2>)
{
    //code to execute if <test2> is true
}
else
{
    //code to execute if <test s> is false
}
```

## `switch case`语句

```c
#include<stdio.h>
int main()
{
	int a = 1;
	switch (a)
	{
	case 0:
		printf("%d", 0);
		break;
	case 1:
		printf("%d", 1);
		break;
	case 2:
		printf("%d", 2);
		break;
	case 3:
		printf("%d", 3);
		break;
	default:
		printf("default");
		break;
	}
	return 0;
}
```

> 每个`case`语句块末尾都要有`break`，如果没有的话会继续向下执行而不进行`case`的匹配，直到下一个`break`语句

> `switch`中的表达式必须为整型常量表达式（long, int, short, char, 注意是包括字符类型），不能是浮点型等其他类型。`case`后面的字面量表达式运算结果也必须是整数类型

```c
#include<stdio.h>
int main()
{
	int a = 1;
	switch (a)
	{
	case 0:
		printf("%d", 0);
		//break;
	case 1:
		printf("%d", 1);
		//break;
	case 2:
		printf("%d", 2);
		//break;
	case 3:
		printf("%d", 3);
		//break;
	default:
		printf("default");
		//break;
	}
	return 0;
}//输出为123default
```

可以利用这一特点：

```c
#include<stdio.h>
int main()
{
	int month = 12;
	switch (month)
	{
	case 1:
	case 2:
	case 12:
		printf("春天");
		break;
	case 3:
	case 4:
	case 5:
		printf("夏天");
		break;
	case 6:
	case 7:
	case 8:
		printf("秋天");
		break;
	case 9:
	case 10:
	case 11:
		printf("冬天");
		break;
	default:
		printf("非法输入");
		break;
	}
	return 0;
}
```

# 循环结构

## while语句

```c
while(<test>)
{
    //code to execute
}
```

## do-while语句

```c#
do
{
	//code to be looped
}while(<test>);
```

- 至少执行一次循环体

## for语句

```c
for (表达式1;表达式2;表达式3)
{
    //code to be looped
}
```

- 表达式2为空表示为`true`，循环会一直进行下去

## break,continue语句

只影响最近的外层循环

# 数组

## 数组初始化

```c
int a[3];
a = {1}; // a为{1,0,0}
```

## 数组长度

```
sizeof(Array) / sizeof(Array[0])
```

## 字符数组

```c
char s1 [] = "zjx";
char s2 [] = {'z','j','x','\0'}
```

## 字符数组的长度

### sizeof

实际上算得到的是**数组长度**

```c
sizeof(s1) / sizeof(s1[0]) // 为4，包含了字符\0
```

C语言中没有字符串类型，使用字符数组来表示字符串，以`\0`代表字符串的结束

```c
char s1 [] = "z\0jx";
char s2 [] = {'z','\0''j','x','\0'};
int size_s1 = sizeof(s1) / sizeof(s1[0]); //5，字符数组的长度不变
int size_s2 = sizeof(s2) / sizeof(s2[0]); //5，字符数组的长度不变
printf("%s",s1);//‘z’，打印字符串的时候到\0为止
printf("%s",s2);//'z'，打印字符串的时候到\0为止
```

### strlen

**引入头文件**

```c
#include<string.h>
```

**计算字符串长度**

计算到`\0`为止且不包含`\0`的字符个数：

```c
char s1 [] = "z\0jx";
char s2 [] = {'z','\0''j','x','\0'};
int len_s1 = strlen(s1);//1
int len_s2 = strlen(s2);//1
```

### 中文字符串的长度

一个中文字符占2个字节

## 字符串元素遍历

```c
char s[] = "zjx";
int len = sizeof(s) / sizeof(s[0]);
int i ;
for(i = 0; i < len ; i++)
{
    char s = s[i];
    print("%c", s);
}
```

**小知识**

```c
prinf("%d,%d,%d", 0, '\0', '0');// 0,0,48
```

> 说明数字`0`和`\0`是ASCII码是一样的，和字符`'0'`是不一样的

## char*定义字符串

```c
char* s1 = "zjx";
```

这时获取字符串的长度不能使用`sizeof`，只能使用`strlen`

## 字符串相关函数

### `atoi`字符串转整型函数

**引入头文件**

```c
#include<stdlib.h>
```

**函数原型**

```c
int myInteger = atoi(myString)
```

**示例**

```c
char s1[] = "123";
int i1 = atoi(s1);
```

### `itoa`整型转字符串

**引入头文件**

```c
#include<stdlib.h>
```

**函数原型**

```c
itoa(myInteger, char* myString, int radix);
```

- `myInteger`：要转化的整数
- `myString`：要存放字符串的字符数组（注意大小）
- `radix`：整数的进制

**示例**

```c
int myInteger = 123;
char myString [4] = {0};
itoa(myInteger, myString, 10);
```

### `sprintf`字符串格式化函数

**引入头文件**

```c
#include<stdio.h>
```

**函数原型**

```c
sprintf(char* buffer, const char *format, [argument]...)
```

- `buffer`：格式化后的字符串要存储的字符列表
- `format`：格式化后的字符串（参考`printf`）

- `argument`：参数
- 这个函数会自动在字符末尾添加`\0`

**示例**

```c
char s1 [19];
sprintf(s1, "a = %d, b = %d", a, b);
```

> `springtf`也可以实现整数到字符串的转化：
>
> ```c
> int i = 123;
> char buffer[128];
> sprintf(buffer, "%d", i);
> ```
>
> - 也可以实现浮点数转化为字符串

P91