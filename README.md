# cpp-minesweeper

C++で作ったコンソール版マインスイーパーです。  
2次元配列、8方向探索、再帰処理の練習として作りました。

## 機能

- 10x10 の盤面
- 地雷15個
- 初回に開くマスは安全
- 空白マスの連鎖オープン
- 旗コマンド
- 勝敗判定

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
