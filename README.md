# C++ 408 刷题练习

考研 408（数据结构 / 计算机组成原理 / 操作系统 / 计算机网络）的代码练习与实验记录。

## 目录结构

```
cpp-408-practice/
├── cpp-408-practice.sln            # Visual Studio 解决方案，双击打开
├── cpp-408-practice.vcxproj        # 项目配置（C++17 / x64 / v143）
├── src/
│   ├── main.cpp                    # 练习代码入口（含控制台 UTF-8 初始化）
│   └── problems/                   # 按真题编号组织的解题代码
│       ├── p2013_majority.h
│       └── p2013_majority.cpp
├── notes/                          # 学习笔记（Markdown）
└── README.md
```

## 已收录题目

| 编号 | 题目 | 考点 | 复杂度 |
|---|---|---|---|
| 2013-41 | 求主元素 | 摩尔投票法（Boyer-Moore） | 时间 O(n) / 空间 O(1) |

每道题目文件里都包含：完整题面注释 → 参考解法 → 边界用例 → 与暴力解法随机对拍。

## 环境

| 项目 | 版本 |
|---|---|
| IDE | Visual Studio 2022 Community 17.14 |
| 编译器 | MSVC 14.44（平台工具集 v143） |
| C++ 标准 | C++17 |
| 目标平台 | x64 |
| Windows SDK | 10.0.26100 |

## 编译运行

**方式一：Visual Studio（推荐）**

双击 `cpp-408-practice.sln` 打开，然后：

| 快捷键 | 作用 |
|---|---|
| `F5` | 编译 + 调试运行（可打断点） |
| `Ctrl+F5` | 编译 + 直接运行（不调试，更快） |
| `Ctrl+Shift+B` | 仅编译 |

**方式二：命令行**

```bat
msbuild cpp-408-practice.sln /p:Configuration=Debug /p:Platform=x64
x64\Debug\cpp-408-practice.exe
```

## 编码注意事项（两个不同的问题）

中文程序在 Windows 上有**两处**编码陷阱，必须分别处理。本项目两处都已修好，
可以作为模板参考。

### ① 编译期：源码文件的编码

源文件必须保存为 **UTF-8 with BOM**。

MSVC 在中文 Windows（默认代码页 936）下会把**无 BOM** 的 UTF-8 中文注释按 GBK 解析，
导致注释吞掉代码、报一堆 `C2065 / C2143` 语法错误。

- 工程里已加 `/utf-8` 编译选项
- 更稳妥的做法是保存时选「UTF-8 带签名」（VS：文件 → 另存为 → 保存按钮下拉 → 编码保存）

### ② 运行期：控制台的代码页

即使编译正确，程序运行时中文仍可能显示成乱码（`骞?408 閿熻...` 这种）。

原因：源码里的中文编译后是 **UTF-8 字节**，而中文 Windows 控制台默认按
**代码页 936 (GBK)** 解释这些字节，两边对不上。

解决：程序启动时把控制台切到 UTF-8。`src/main.cpp` 里已经封装好：

```cpp
#ifdef _WIN32
#include <windows.h>
#endif

static void enableUtf8Console() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);   // 输出按 UTF-8 解码
    SetConsoleCP(CP_UTF8);         // 输入也一致
#endif
}

int main() {
    enableUtf8Console();
    // ...
}
```

> 也有人在命令行用 `chcp 65001` 临时切换，但那只对当前这个控制台窗口有效；
> 写进程序里才能保证在任何环境下都正确。

## 新增一道题的做法

1. 在 `src\problems\` 下新建 `p<年份>_<题号>_<名字>.h` 和 `.cpp`
2. 头文件里声明 `void runP<年份><题号>();`
3. 在 `main.cpp` 里 `#include` 并调用 `runP2013Majority();`
4. **必须**通过 VS「右键项目 → 添加 → 新建项」创建，或在「显示所有文件」里右键「包括在项目中」
   —— 手动复制进目录的 `.cpp` 不会被编译
5. 同步更新本文件「已收录题目」表格

## 计划

- [x] 数据结构：2013 真题 · 主元素
- [ ] 数据结构：顺序表、链表、栈、队列、树、图
- [ ] 排序与查找算法实现
- [ ] 操作系统：进程调度、页面置换模拟
- [ ] 计算机网络：简单协议解析

## 提交约定

```bat
git add -A
git commit -m "完成 2013-41 主元素"
git push
```
