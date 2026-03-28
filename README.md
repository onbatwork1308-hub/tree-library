# Tree Library (C++)

A modular, header-only C++ library implementing fundamental tree data structures with a clean and STL-inspired API.

---

## 🚀 Features

* Binary Search Tree (BST)
* AVL Tree (self-balancing)
* Header-only design (no compilation required for library)
* Clean and minimal API (`insert`, `erase`, `contains`)
* Designed with abstraction and encapsulation in mind

---

## 📦 Project Structure

```
tree-library/
│
├── include/
│   └── tree/
│       └── binary/
│           ├── binary_search_tree.h
│           ├── avl_tree.h
│           └── detail/          # internal implementation (not for users)
│
├── examples/                   # sample usage
├── CMakeLists.txt             # build configuration
├── README.md
└── .gitignore
```

---

## 🛠️ Requirements

* C++17 or higher
* CMake ≥ 3.10
* GCC / Clang / MSVC
* User-defined types must support comparison operators.

---

## ⚙️ Build Instructions

```bash
git clone <https://github.com/onbatwork1308-hub/tree-library.git>
cd tree-library

mkdir build
cd build

cmake ..
make
```

Run the example:

```bash
./example
```

---

## 💡 Usage

```cpp
#include <tree/binary/binary_search_tree.h>

int main() {
    binary_search_tree<int> tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(20);

    if (tree.contains(5)) {
        // element found
    }

    tree.erase(10);
}
```

---

## 🧩 Design Highlights

* Public API is separated from internal implementation using a `detail` namespace
* Composition is used to restrict direct access to internal structures
* Template-based design for generic data handling
* Inspired by STL container behavior

---

## 📈 Future Improvements

* Iterator support (`begin`, `end`)
* B-Tree implementation
* B+ Tree implementation
* Extended traversal utilities

---

## 👤 Author

Omini
onbatwork1308-hub

---
