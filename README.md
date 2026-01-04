# 📚 Algorithm & Data Structures

> 记录 LeetCode 刷题历程，以及常用算法与数据结构的 C++ 实现。

![Language](https://img.shields.io/badge/language-C++-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

## 📖 简介 (Introduction)

本仓库 (`Alogrithm_Datastruct`) 主要用于记录个人的算法学习与 LeetCode 刷题过程。内容涵盖了常见的数据结构实现、经典算法模板以及 LeetCode 高频题目的解法。



## 📖 目录 (Table of Contents)

- [简介 (Introduction)](#-简介-introduction)
- [项目结构 (Project Structure)](#-项目结构-project-structure)
- [核心内容 (Core Contents)](#-核心内容-core-contents)
- [本地运行与调试 (Build & Run)](#-本地运行与调试-build--run)
- [代码规范 (Code Style)](#-代码规范-code-style)
- [作者 (Author)](#-作者-author)

---

## 📖 简介 (Introduction)

本项目旨在通过 C++ 语言深入理解计算机科学的核心基石——数据结构与算法。
主要内容涵盖了常见的数据结构实现、经典算法模板以及 LeetCode 高频题目的解法。

---

## 📂 项目结构 (Project Structure)

基于按算法类型分类的目录结构：

```text
Alogrithm_Datastruct/
├── 📂 Array/                # 数组相关题目与操作
├── 📂 BFS/                  # 广度优先搜索 (Breadth-First Search)
├── 📂 Binary_Search/        # 二分查找及其变种
├── 📂 Bit_Manipulation/     # 位运算技巧
├── 📂 BST/                  # 二叉搜索树 (Binary Search Tree)
├── 📂 DFS/                  # 深度优先搜索 (Depth-First Search)
├── 📂 Dynamic_Programming/  # 动态规划 (DP)
├── 📂 Exercise/             # 综合练习与杂项
├── 📂 Linked_List/          # 链表操作
├── 📂 Math/                 # 数学逻辑类题目
├── 📂 Network_Flow/         # 网络流算法
├── 📂 Sort/                 # 排序算法实现 (QuickSort, MergeSort...)
├── 📂 Stack/                # 栈与单调栈
├── 📂 String/               # 字符串处理 (KMP, Trie...)
├── 📂 Tree/                 # 二叉树通用遍历与构造
└── 📂 Trie/                 # 字典树 (前缀树)

```

---

## 🧠 核心内容 (Core Contents)

### 1. 经典算法模板 (Algorithms)

* **排序算法**:
* [x] Quick Sort (快速排序)
* [x] Merge Sort (归并排序)
* [x] Heap Sort (堆排序)


* **搜索算法**:
* [x] DFS (递归与非递归) / BFS
* [x] Binary Search (二分查找模板)


* **图论**:
* [ ] 最短路径 (Dijkstra, Floyd)
* [ ] 最小生成树 (Prim, Kruskal)



### 2. LeetCode 题解 (Solutions)

| 类别 (Category) | 说明 |
| --- | --- |
| **Dynamic Programming** | 背包问题、线性 DP、区间 DP 等 |
| **Tree / BST** | 树的遍历、层序遍历、最近公共祖先等 |
| **Graph / Search** | 岛屿问题、全排列、组合总和等 |
| **Data Structure** | 链表反转、LRU 缓存、单调栈接雨水等 |

---

## 🛠️ 本地运行与调试 (Build & Run)

本项目建议使用 `g++` 编译器或 `CMake` 进行构建。

### 环境要求

* **Compiler**: GCC 7.0+ / Clang 5.0+ / MSVC 2019+
* **Standard**: C++11 或 C++17

### 命令行编译示例

```bash
# 编译二分查找的某个示例
g++ -std=c++17 Binary_Search/001_Example.cpp -o main

# 运行
./main

```

---

## 🎨 代码规范 (Code Style)

为了保持代码整洁，本项目遵循以下规范 (参考 Google C++ Style)：

* **命名**:
* 变量名: `snake_case` (如 `max_value`)
* 函数名: `CamelCase` (如 `SolveProblem`)


* **注释**: 核心逻辑必须包含简短的注释，解释 "Why" 而不是 "What"。

---

## 👤 作者 (Author)

**Bruce**

* Github: [@bruce1408](https://github.com/bruce1408)

---

**如果觉得这个项目对你有帮助，请给一个 ⭐️ Star！谢谢！**
