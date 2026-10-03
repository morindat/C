# C

Coursework and practice written while learning C, organised by topic. This is a
learning repository rather than a library — the code ranges from small exercises to
fuller data-structure implementations.

## Layout

| Directory | Contents |
| :--- | :--- |
| `DSA/` | Data structures and algorithms — BST, linked lists, deque, hashing, heaps, Huffman coding |
| `ProgrammingLab/` | Lab work — file I/O, frequency maps, Caesar cipher, Huffman |
| `CPC/` | Competitive-programming exercises (primality tests, factorisation) |
| `DM/` | Discrete-maths exercises (binary, DFA, Hanoi, matrices) |
| `General/` | Language fundamentals — datatypes, arrays, recursion, big-O |
| `Leetcode/` | C solutions to LeetCode problems |

## Build

Each file compiles on its own. Compile into `build/` so binaries stay untracked:

```sh
mkdir -p build
gcc -Wall -Wextra -std=c11 path/to/file.c -o build/out
./build/out
```

## Notes

Compiled binaries and editor artefacts that had accumulated in earlier commits were
removed; the repository now holds source and data files only. `DSA/` and
`ProgrammingLab/` are the most complete directories.
