# cpp-minesweeper

C++で作ったコンソール版マインスイーパーです。  

## 概要

2次元配列、8方向探索、再帰処理を使って、マインスイーパーの基本的なゲーム進行を実装しました。

## 実装内容

- 2次元配列による盤面管理
- 8方向探索による周囲の地雷数計算
- 初回オープン時の安全保証
- 再帰による空白マスの連鎖オープン
- 旗コマンドと勝敗判定

## 遊び方

以下の形式で入力します。

```text
command row col
```

例:

o 0 0
open 3 4
f 2 5
flag 7 1
help

`o` / `open`: マスを開く  
`f` / `flag`: 旗を立てる  
`help`: 遊び方を表示する

座標は `0` から `9` で指定します。

## 実行例

```txt
# # # # # # # # # #
# # # # # # # # # #
# # # # # # # # # #
# # # # # # # # # #
# # # # # # # # # #
# # # # # # # # # #
# # # # # # # # # #
# # # # # # # # # #
# # # # # # # # # #
# # # # # # # # # #

## ビルドと実行

Windows PowerShellの場合:

```powershell
g++ -std=c++17 -Wall -Wextra src/main.cpp -o minesweeper.exe
.\minesweeper.exe
```

Git Bash / MSYS2の場合:

```bash
g++ -std=c++17 -Wall -Wextra src/main.cpp -o minesweeper.exe
./minesweeper.exe
```

Linux / WSLの場合:

```bash
g++ -std=c++17 -Wall -Wextra src/main.cpp -o minesweeper
./minesweeper
```
