#include <iostream>
#include <vector>
#include <string>

// ---------------------------------------------------------------
// 408 刷题练习入口
// 每道题写成一个函数，在 main() 里调用并打印结果
// 注意：本文件保存为 UTF-8 with BOM，否则 MSVC 在中文系统下
//      会按 GBK 解析中文注释而报语法错误
// ---------------------------------------------------------------

// 示例：顺序表逆置（数据结构 · 线性表）
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
    std::vector<int> data = { 1, 2, 3, 4, 5, 6, 7 };
    printArray(data, "before");
    reverseArray(data);
    printArray(data, "after ");

    std::cout << "\nEnvironment OK. Ready for 408 practice." << std::endl;
    return 0;
}
