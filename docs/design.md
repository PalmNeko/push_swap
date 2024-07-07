
# 設計

## フロー

```mermaid
flowchart TB
  node_1(["開始"])
  node_2["引数チェック"]
  node_3["数値に変換"]
  node_4["スタック生成"]
  node_5{"スタックAが３個を超えている？"}
  node_6[["最小の手数になるようにプッシュB\n(ps_push_with_min"]]
  node_7["スタックAをソート"]
  node_8["スタックBをスタックAの正しい位置に挿入"]
  node_9["コマンドの結果を出力"]
  node_10(["終了"])
  node_11(["ps_push_with_min 開始"])
  node_12["i番目の数値を取り出す"]
  node_13["値をプッシュBの正しい位置に挿入するときの手数を計算する"]
  node_14["最小の手数と比較して最小の手数を取得"]
  node_15["i番目の数値が最小手数を超えたら終了"]
  node_16["連番にする"]
  node_1 --> node_2
  node_2 --> node_3
  node_4 --> node_5
  node_5 --"yes"--> node_6
  node_6 --> node_5
  node_5 --"no"--> node_7
  node_7 --> node_8
  node_8 --> node_9
  node_9 --> node_10
  node_11 --> node_12
  node_12 --> node_13
  node_13 --> node_14
  node_14 --> node_15
  node_3 --> node_16
  node_16 --> node_4

```

## 一覧

### データ構造

* [t_push_swap](#t_push_swap)
* [t_ps_stack](#t_ps_stack)
* [t_ps_list](#t_ps_list)
* [t_ps_command_list](#t_ps_command_list)

### 関数

* ロジック系
	* turk_sort [ps_turk_sort](#ps_turk_sort)
	* 出力系
		* コマンドを出力 [ps_print_cmdlst](#ps_print_cmdlst)
		* エラーを出力 [ps_print_error](#ps_print_error)
* validate系（検証系）
	* 引数チェック [ps_validate_arguments](#ps_validate_arguments)
		* 重複チェック [ps_validate_no_duplicates](#ps_validate_no_duplicates)
		* 数値チェック [ps_validate_num](#ps_validate_num)
* 処理系
	* 連番にする。[ps_renumber](#ps_renumber)
	* 値をスタックの正しい位置を取得（降順&昇順）（スタックが正しい順序であること）[ps_get_insert_pos](#ps_get_insert_pos)
	* 昇順用比較関数 [ps_cmp_i_asc](#ps_cmp_i_asc)
	* 降順用比較関数 [ps_cmp_i_desc](#ps_cmp_i_desc)
	* スタックが昇順になっているかどうか [ps_is_asc](#ps_is_asc)
	* スタックが降順になっているかどうか[ps_is_desc](#ps_is_desc)
	* スタックが３個以下のときの特殊ソート [ps_sort_for_three](#ps_sort_for_three)
	* 数値に変換 [ps_args_to_int_array](#ps_args_to_int_array)
* t_push_swap系（controller系）
	* t_push_swap生成 [ps_new_ps](#ps_new_ps)
	* t_push_swap削除 [ps_destroy_ps](#ps_destroy_ps)
	* pa [ps_pa](#ps_pa)
	* pb [ps_pb](#ps_pb)
	* sa [ps_sa](#ps_sa)
	* sb [ps_sb](#ps_sb)
	* ra [ps_ra](#ps_ra)
	* rb [ps_rb](#ps_rb)
	* rra [ps_rra](#ps_rra)
	* rrb [ps_rrb](#ps_rrb)
	* ss [ps_ss](#ps_ss)
	* rr [ps_rr](#ps_rr)
	* rrr [ps_rrr](#ps_rrr)
* コマンド系（controller系）
	* コマンドを追加 [ps_append_cmdlst](#ps_append_cmdlst)
	* コマンドの取得 ない場合NULL [ps_get_cmdlst](#ps_get_cmdlst)
	* コマンド構造体生成 [ps_new_cmdlst](#ps_new_cmdlst)
	* コマンド構造体削除 [ps_destroy_cmdlst](#ps_destroy_cmdlst)
* スタック系（controller系）
	* スタックに値を追加 [ps_push_stack](#ps_push_stack)
	* スタックから値を取得 [ps_get_stack](#ps_get_stack)
	* スタックから値を取り出す＆削除 [ps_pop_stack](#ps_pop_stack)
	* スタックのトップを次の値に設定(rotate) [ps_rotate_stack](#ps_rotate_stack)
	* スタックのトップを前の値に設定 [ps_rrotate_stack](#ps_rrotate_stack)
	* トップとセカンドの値を入れ替える。[ps_swap_stack](#ps_swap_stack)

## 構造体設計
### t_push_swap

**概要**
* push_swapとしてデータ構造を保持する。

**パラメータ
* t_ps_command_list *commands コマンド列への先頭ポインタ
* t_ps_stack *stack_a スタックA
* t_ps_stack *stack_b スタックB

### t_ps_stack

**概要**

* 双方向循環リストでのスタック
* 一個も値がない場合はtopがNULLかつsize=0

**パラメータ**

* t_list *top - 最初の値へのポインタ
* int size - 現在の要素数
> Libftを双方向リストに変換

### t_ps_command_list

* t_listで実装可能

## 関数設計

### ps_turk_sort

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_print_cmdlst

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_print_error

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_validate_arguments

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_validate_no_duplicates

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_validate_num

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_renumber

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_get_insert_pos

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_cmp_i_asc

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_cmp_i_desc

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_is_asc

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_is_desc

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_sort_for_three

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_args_to_int_array

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_new_ps

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_destroy_ps

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_pa

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_pb

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_sa

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_sb

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_ra

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_rb

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_rra

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_rrb

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_ss

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_rr

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_rrr

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_append_cmdlst

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_get_cmdlst

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_new_cmdlst

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_destroy_cmdlst

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_push_stack

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_get_stack

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_pop_stack

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_rotate_stack

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_rrotate_stack

**概要**

**宣言**

**引数**

**戻り値**

**フロー**

### ps_swap_stack

**概要**

**宣言**

**引数**

**戻り値**

**フロー**
