#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>
#endif

#include "problems/p2013_majority.h"

// ---------------------------------------------------------------
// 408 刷题练习入口
// 每道题写成一个函数，在 main() 里调用并打印结果
// 注意：本文件保存为 UTF-8 with BOM，否则 MSVC 在中文系统下
//      会按 GBK 解析中文注释而报语法错误
// ---------------------------------------------------------------

// 让 Windows 控制台按 UTF-8 解释输出字节。
// 中文 Windows 的控制台默认代码页是 936(GBK)，而源码里的
// 中文经过编译后是以 UTF-8 字节写出的，不切换就会显示成乱码。
static void enableUtf8Console() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);   // 输出：控制台按 UTF-8 解码
    SetConsoleCP(CP_UTF8);         // 输入：有中文输入时也一致
#endif
}

// 热身：顺序表逆置（数据结构 · 线性表）
void reverseArray(std::vector<int>& a) {
    int i = 0, j = static_cast<int>(a.size()) - 1;
    while (i < j) {
        std::swap(a[i], a[j]);
        ++i;
        --j;
    }
}

void printArray(const std::vector<int>& a, const std::string& label) {
    std::cout << label << ": [";
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i] << (i + 1 < a.size() ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

int main() {
    enableUtf8Console();

    // ---- 热身：顺序表逆置 ----
    std::vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
    printArray(data, "before");
    reverseArray(data);
    printArray(data, "after ");

    // ---- 真题练习 ----
    runP2013Majority();

    std::cout << "\nEnvironment OK. Ready for 408 practice." << std::endl;
    return 0;
}
