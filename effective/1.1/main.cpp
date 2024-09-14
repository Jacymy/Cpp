#include "test.h"
#include <cstdio>

int main(const int agrc, const char *argv[]) {
  std::printf("x = %d\n", x);
  int digitsSoFar = numDigits(111);
  std::printf("digitsSoFar = %d\n", digitsSoFar);
  std::printf("sizeof(Widgit) = %lu.\n", sizeof(Widget));
  Widget w1;     /* 调用默认的构造函数 */
  Widget w2(w1); /* 调用拷贝构造 */
  Widget w3 =
      w2; /* 调用拷贝构造函数
     NOTE: 新对象被定义，一定有一个构造函数被调用，但是不会拷贝赋值构造 */
  w1 =
      w2; /* 调用拷贝赋值构造函数, 由于没有新对象被调用，所以就会调用赋值操作 */

  int *p = 0; /* p是一个null指针 */
  std::printf("p = %p\n", &p);
  // std::printf("value = %d\n", *p); 解引用未知空间导致段错误

  char name[] = "Darla"; // name 是一个数组，大小是6，包含`\0`字符
  char ch = name[10];
  std::printf("ch = %c\n", ch);

  return 0;
}
