#include "p2013_majority.h"

#include <iostream>
#include <random>

// -------------------------------------------------------------
// 主解法：摩尔投票法
// 第一遍：边扫描边"抵消"，找出候选者
// 第二遍：统计候选者出现次数，确认是否真的 > n/2
// 时间复杂度 O(n)，空间复杂度 O(1)
// -------------------------------------------------------------
int findMajority(const std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    if (n == 0) {
        return -1;
    }

    // ---- 第一遍：找候选者 ----
    int candidate = a[0];
    int count = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] == candidate) {
            ++count;            // 同伙，票数 +1
        } else if (--count == 0) {
            candidate = a[i];   // 抵消光了，换下一个候选者
            count = 1;
        }
    }

    // ---- 第二遍：验证 ----
    int occurrences = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == candidate) {
            ++occurrences;
        }
    }

    return (occurrences > n / 2) ? candidate : -1;
}

// -------------------------------------------------------------
// 暴力解法：O(n^2)，仅用于对拍验证，不满足题目要求
// -------------------------------------------------------------
static int findMajorityBruteForce(const std::vector<int>& a) {
    const int n = static_cast<int>(a.size());
    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (a[j] == a[i]) {
                ++cnt;
            }
        }
        if (cnt > n / 2) {
            return a[i];
        }
    }
    return -1;
}

static void printVec(const std::vector<int>& a) {
    std::cout << "{ ";
    for (size_t i = 0; i < a.size(); ++i) {
        std::cout << a[i];
        if (i + 1 < a.size()) {
            std::cout << ", ";
        }
    }
    std::cout << " }";
}

// 跑一个用例并比对期望值
static bool runCase(const std::vector<int>& a, int expect) {
    const int got = findMajority(a);
    const bool ok = (got == expect);

    printVec(a);
    std::cout << "  ->  " << got << "   (期望 " << expect << ")  "
              << (ok ? "PASS" : "FAIL") << std::endl;
    return ok;
}

void runP2013Majority() {
    std::cout << "\n========================================\n";
    std::cout << " 2013 年 408 真题：求主元素\n";
    std::cout << " 要求 O(n) 时间 / O(1) 空间\n";
    std::cout << "========================================\n";

    int passed = 0;
    int total = 0;

    // ---- 题目给出的两个例子 ----
    ++total; passed += runCase({ 0, 5, 5, 3, 5, 7, 5, 5 }, 5) ? 1 : 0;
    ++total; passed += runCase({ 0, 5, 5, 3, 5, 1, 5, 7 }, -1) ? 1 : 0;

    // ---- 边界用例 ----
    ++total; passed += runCase({ 1 }, 1) ? 1 : 0;                    // 单个元素
    ++total; passed += runCase({ 9, 9, 9, 9 }, 9) ? 1 : 0;           // 全部相同
    ++total; passed += runCase({ 1, 2 }, -1) ? 1 : 0;                // 各占一半不算主元素
    ++total; passed += runCase({ 2, 2, 1 }, 2) ? 1 : 0;              // 恰好 2/3
    ++total; passed += runCase({ 1, 2, 3, 4, 5 }, -1) ? 1 : 0;       // 全不同
    ++total; passed += runCase({ 3, 3, 4, 4, 3 }, 3) ? 1 : 0;        // 3 出现 3/5

    std::cout << "\n固定用例: " << passed << "/" << total << " 通过\n";

    // ---- 随机对拍：与暴力解法比较 ----
    std::mt19937 rng(20251114u);
    std::uniform_int_distribution<int> lenDist(1, 40);
    std::uniform_int_distribution<int> valDist(0, 9);

    const int rounds = 20000;
    int mismatch = 0;

    for (int r = 0; r < rounds; ++r) {
        const int n = lenDist(rng);
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = valDist(rng);
        }
        if (findMajority(a) != findMajorityBruteForce(a)) {
            ++mismatch;
            if (mismatch == 1) {
                std::cout << "  首个不一致用例: ";
                printVec(a);
                std::cout << std::endl;
            }
        }
    }

    std::cout << "随机对拍: " << rounds << " 组，不一致 " << mismatch << " 组\n";
    std::cout << "结论: " << ((mismatch == 0 && passed == total) ? "全部通过" : "存在失败") << "\n";
}
