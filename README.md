# 🚀 DSA Daily – C++ Problem Solving Repository

Welcome to **DSA Daily**, a curated collection of my **Data Structures & Algorithms (DSA)** practice in **C++** — aimed at mastering **FAANG-level** and **Quant-level** problem-solving.

This repository is a daily log of my journey to become fluent in **algorithmic thinking**, **code optimization**, and **problem analysis**.

---

## 📊 Quick Profile Snapshot

| Platform | Handle | Stats (as of Nov 2025) |
|-----------|---------|------------------------|
| 🟩 **LeetCode** | [anNTyyxxlo](https://leetcode.com/u/anNTyyxxlo/) | 🧩 **67 problems solved** • ⚔️ **Contest Rating: 1727 (Top 11%)** |
| 🟠 **Codeforces** | *Coming soon* | Focus: algorithmic speed & optimization |
| 🟢 **GeeksforGeeks** | *Private logs* | Focus: concept reinforcement & detailed notes |

---

## 🧠 Focus Areas

### 1️⃣ Core Data Structures
- Arrays, Strings, Linked Lists  
- Stacks, Queues, Deques  
- Trees (BST, Segment Trees, Tries)  
- Heaps, Graphs, Hash Maps  

### 2️⃣ Core Algorithms
- Sorting & Searching  
- Sliding Window, Two Pointers  
- Recursion & Backtracking  
- Divide & Conquer  
- Greedy, Bit Manipulation  
- Dynamic Programming (1D, 2D, Space Optimized)  
- Graph Algorithms: BFS, DFS, Dijkstra, Union-Find, Topological Sort  

### 3️⃣ Advanced Topics
- Binary Search on Answers  
- DP Optimization (State Compression, Tabulation)  
- Prefix-Suffix Patterns  
- Number Theory, Probability, and Combinatorics  
- Quant-style Math & Logic Problems  

---

## 🏗️ Repository Structure

> All `.cpp` files are stored directly in the main directory for quick access.

📁 DSA-Daily/
│
├── array_two_sum.cpp
├── array_max_subarray_kadane.cpp
├── dp_longest_increasing_subsequence.cpp
├── dp_knapsack_01.cpp
├── graph_dijkstra.cpp
├── graph_bfs.cpp
├── string_longest_palindrome.cpp
├── linkedlist_reverse.cpp
├── problem_index.csv
└── README.md


---

## 📘 Problem Index Example

| # | Problem | Category | Platform | Difficulty | Concept | File |
|---|----------|-----------|------------|-------------|----------|------|
| 1 | Two Sum | Array | LeetCode | Easy | Hashmap | array_two_sum.cpp |
| 2 | Max Subarray (Kadane) | Array | GFG | Medium | Kadane’s Algorithm | array_max_subarray_kadane.cpp |
| 3 | Longest Increasing Subsequence | DP | LeetCode | Medium | DP + Binary Search | dp_longest_increasing_subsequence.cpp |
| 4 | Dijkstra’s Algorithm | Graph | LeetCode | Medium | Shortest Path | graph_dijkstra.cpp |
| 5 | Reverse Linked List | Linked List | LeetCode | Easy | Iterative / Recursive | linkedlist_reverse.cpp |

> Full list tracked in `problem_index.csv`

---

## ⚙️ Example Code Snippet

### 🔹 Example: Longest Substring Without Repeating Characters

```cpp
// Author: Gaurav Sah
// Problem: Longest Substring Without Repeating Characters
// Platform: LeetCode
// Approach: Sliding Window + Hashmap
// Time Complexity: O(n)
// Space Complexity: O(256)

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> last(256, -1);
    int maxLen = 0, start = 0;

    for (int end = 0; end < s.size(); ++end) {
        if (last[s[end]] >= start)
            start = last[s[end]] + 1;

        last[s[end]] = end;
        maxLen = max(maxLen, end - start + 1);
    }

    return maxLen;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}

