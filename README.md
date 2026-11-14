# C++ 408 刷题练习

考研 408（数据结构 / 计算机组成原理 / 操作系统 / 计算机网络）的代码练习与实验记录。

## 目录结构

```
cpp-408-practice/
├── cpp-408-practice.sln            # Visual Studio 解决方案，双击打开
├── cpp-408-practice.vcxproj        # 项目配置（C++17 / x64 / v143）
├── src/
│   └── main.cpp                    # 练习代码入口
├── notes/                          # 学习笔记（Markdown）
└── README.md
```

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

或者不建工程、单文件直编：

```bat
cl /nologo /std:c++17 /utf-8 /EHsc src\main.cpp
```

## 编码注意事项

源文件必须保存为 **UTF-8 with BOM**。

MSVC 在中文 Windows（代码页 936）下会把无 BOM 的 UTF-8 中文注释按 GBK 解析，
导致注释吞掉代码、报一堆 `C2065 / C2143` 语法错误。工程里已加 `/utf-8` 编译选项，
但带 BOM 是更稳妥的做法（VS 保存时选「UTF-8 带签名」）。

## 计划

- [ ] 数据结构：顺序表、链表、栈、队列、树、图
- [ ] 排序与查找算法实现
- [ ] 操作系统：进程调度、页面置换模拟
- [ ] 计算机网络：简单协议解析

## 提交约定

```bat
git add -A
git commit -m "完成顺序表逆置"
git push
```
