# C++ Console Minesweeper

C++で実装したコンソール版マインスイーパーです。

競技プログラミングで学んだ2次元配列、8方向探索、再帰処理を使って、ユーザー入力に応じて盤面状態が変化するゲームを作りました。

## Features

- 10x10 のマインスイーパー
- 地雷数は15個
- 初回に開いたマスは必ず安全
- 8方向探索による周囲地雷数の計算
- 再帰処理による空白マスの連鎖オープン
- 旗を立てる機能
- 勝敗判定

## Symbols

| Symbol | Meaning |
|---|---|
| `#` | Hidden cell |
| `P` | Flag |
| `.` | Opened empty cell |
| `1`-`8` | Number of adjacent mines |
| `*` | Mine |

## How to Play

起動後、以下の形式でコマンドを入力します。

```text
command row col
```

Examples:

```text
o 0 0
open 3 4
f 2 5
flag 7 1
help
```

Commands:

| Command | Description |
|---|---|
| o, open | Open a cell |
| f, flag | Put a flag on a cell |
| help | Show help message |

Rows and columns are indexed from 0 to 9.

## Build and Run

Windows PowerShell:

g++ -std=c++17 -Wall -Wextra src/main.cpp -o minesweeper.exe
.\minesweeper.exe

Git Bash / MSYS2:

g++ -std=c++17 -Wall -Wextra src/main.cpp -o minesweeper.exe
./minesweeper.exe

Linux / WSL:

g++ -std=c++17 -Wall -Wextra src/main.cpp -o minesweeper
./minesweeper

## Implementation Notes

- hw manages the actual board.
  - * means mine.
  - - means safe cell.
- bhw manages the visible board.
  - # means hidden.
  - P means flag.
  - . or numbers are shown after opening cells.
- The board is generated after the first open command so that the first opened cell is always safe.
- Empty cells are opened recursively using 8-direction search.

## Verified Environment

- C++17
- g++ / MSYS2 UCRT64
