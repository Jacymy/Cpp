# Cpp
learn cpp programmer,let us start!

## how to create project directory?
```css
.
├── build -- 构建目录
│   ├── bin
│   ├── CMakeCache.txt
│   ├── CMakeFiles
│   ├── cmake_install.cmake
│   └── Makefile
├── CMakeLists.txt  -- cmake文件，用于生成MakeFile的可依赖文件
├── effective_chapter1_3.cpp -- 源文件，可以用来生成动态库和依赖库
├──include -- 头文件包含，用于存放头文件
│   └── effective_chapter1_3.h
├── lcompile.sh -- 编译脚本
├── llaunch.sh -- 编译+运行脚本
├── lrun.sh -- 运行脚本
└── src -- 源文件
    └── effective_chapter1_cxx.cpp
```

## CMakeLists.txt 文件
一、设置项目所需的最低的cmake版本 `cmake_minimum_required(VERSION<min>[...<policy_max>][FATAL_ERROR])`

二、设置项目名称 `project(<PROJECT-NAME> [<language-name>...])`
```txt
作用:
设置项目名称，并将其存储在变量中 PROJECT_NAME。从顶层调用时还 CMakeLists.txt会将项目名称存储在变量中CMAKE_PROJECT_NAME。

还设置变量:

PROJECT_SOURCE_DIR，<PROJECT-NAME>_SOURCE_DIR
项目源目录的绝对路径。

PROJECT_BINARY_DIR，<PROJECT-NAME>_BINARY_DIR
项目二进制目录的绝对路径。

PROJECT_IS_TOP_LEVEL，<PROJECT-NAME>_IS_TOP_LEVEL
布尔值，指示该项目是否为顶级项目。

```
三、设置变量 `set(<variable> <value>... [PARENT_SCOPE])`
```txt
设置正常变量:
<variable>在当前函数或目录范围内设置或取消设置:
    1. 如果至少<value>...给出一个，则将变量设置为该值。
    2. 如果没有给出值，则取消设置变量。这相当于 unset(<variable>)。
```
四、将包含目录添加到构建中。`include_directories([AFTER|BEFORE] [SYSTEM] dir1 [dir2 ...])`
```txt
将给定的目录添加到编译器用于搜索包含文件的目录中。相对路径被解释为相对于当前源目录。
```
五、添加可执行文件 `add_executable(<name> <options>... <sources>...)`
```txt
添加一个可执行目标，该目标<name>将从命令调用中列出的源文件构建。
```

## .clangd 文件
```txt
配置存储在 YAML 文件中。这些文件可以是：

项目配置.clangd：源树中命名的文件。（clangd 在活动文件的所有父目录中搜索）。

一般来说，这应该用于共享和签入设置。

（可以删除已命名的现有目录.clangd。这些目录在版本 11 之前被 clangd 用于临时存储。）

用户配置：config.yaml操作系统特定目录中的文件：

Linux 和其它：$XDG_CONFIG_HOME/clangd/config.yaml通常 ~/.config/clangd/config.yaml。
```

## .clang-format 格式化文件
代码风格检查、代码格式化工具
