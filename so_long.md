# so_long

## flow
1. read_map
1. check_map
1. mlx

## error
- check_file_name
- check_component
	- Is it make of only five elements (0, 1, C, E, P)?
	- Only one E
	- Only one P
	- at least one C
- check_rect
- check_surrounded_walls
- check_valid_path


## mlx
1. mlx_init
1. mlx_new_window
1. mlx_xpm_file_to_image
1. mlx_put_image_to_window
1. mlx_destroy_image

error 出力2
f_map_09弾けない

WINDOW_SIZEは固定?
エスケープの数字はどのようにしらべた？

mlx_initはfree必要なのか

destoroy image
destroy window

11111
1PEC1
11111
弾けない

jisキーからUSkeyへ対応させる


freeについて
vprintf




header fileの書き方
ifeq
shell uname
macの時のheaderfile

find . -type f -name '*.c' | xargs cflow --format=posix >>flow
find . -type f -name '*.c' | xargs cflow --format=posix --reverse >>rflow
htags . --suggest --call-tree=flow --callee-tree=rflow
open HTML/index.html

ps aux | less

dprintf

expose

nm -u obj/*.o
error exit

ファイルを読んでから、ファイルの名前のチェックをするということが気になった。

エラーを出すなら使い方を出せ

errornoはmalloc errorの時などに番号が変わる。

x11のマニュアルを見たりして、調べる
x_event, 
