#ifndef TEST_H
#define TEST_H
/**
 * 头文件是用来干什么的？
 * 1. 变量: 不能定义变量,但可以通过关键字`extern`来声明变量.
 * 2. 常量: 可以定义变量,但必须初始化；也可以使用`extern`来声明变量.
 * 3. 函数: 头文件内必须声明函数,不可用于实现函数，实现函数放在对应源文件中;
 * 4. 类: 可以前置声明，也可以定义类；但是类内函数实现必须在源文件;
 */

#include <iostream>

extern int x; /* 声明外部链接, 基本类型定义不能放在头文件中; 变量 x
                 的声明，告诉编译器 x 是一个整型变量，但不分配内存。 */

std::size_t numDigits(int number); /* 函数声明式 */

class Widget; /* 前置声明(forward declaration), 直接使用会导致类的定义不完整 */
class Widget {
public:
  Widget();                             /* 声明默认构造函数 */
  Widget(const Widget &rhs);            /* 拷贝构造 浅拷贝 */
  Widget &operator=(const Widget &rhs); /* 赋值构造 */
  ~Widget();                            /* 声明默认析构函数 */
  // ...

private:
  int data;
}; /* 类的定义式,由于没有实现方法,故类的定义是完整的 NOTE: 空类的空间大小为:1*/

template <typename T> class GraphNode {
public:
  GraphNode();
  ~GraphNode();
  // ...
}; /* 模板类的定义式  NOTE: 模板类是完整的,需要时指定类型即可. */

class A {
public:
  A(); /* default 构造函数 */
};

class B {
public:
  explicit B(int x = 0, bool b = true); /* default 构造函数 */
};

// 声明且定义类
class C {
public:
  explicit C(        /* NOTE: C c=28 <==> C c(28) 不可行 */
             int x); /* 不是默认构造函数; NOTE:
                        显示构造：它不会自动的进行隐式转换*/

private:
  int x; /* 类内可以定义变量 */
};

#endif // TEST_H
