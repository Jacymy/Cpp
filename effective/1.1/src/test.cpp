#include "test.h"

int x; /* 定义变量x, 如果直接赋值的话, 我们称`变量的初始化` */

/**
 * @传入一个整数，并返回这个数的位数
 *
 * @para number int
 */
std::size_t numDigits(int number) {
  std::size_t digitsSoFar = 1;
  while ((number /= 10) != 0)
    ++digitsSoFar;
  return digitsSoFar;
}

// 实现C类内的函数
C::C(int x) { std::cout << "call C::C(int x) signature.\n"; }

// 实现Widget类内的函数
Widget::Widget() { std::cout << "call Widget::Widget() signature.\n"; }
Widget::Widget(const Widget &rhs) {
  std::cout << "call copy constructor function.\n";
}

Widget &Widget::operator=(const Widget &rhs) {
  if (this == &rhs) {
    return *this; // 处理自我赋值
  }

  std::cout << "call copy assignment constructor function.\n";

  // 清理当前资源
  // 例如：delete[] data;

  // 分配新资源并复制数据
  // 例如：
  // size = rhs.size;
  // data = new char[size + 1];
  // std::strcpy(data, rhs.data);

  return *this;
}

Widget::~Widget() {
  std::cout << "call Widget::~Widget() deconstructor function.\n";
}
