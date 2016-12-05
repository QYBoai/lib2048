##类型  
```c
typedef L2_pv ...;
	/*L2_pv	格子中的数字(指数，如：格子中的数字为16，该值为4)*/
```
```c
typedef L2_sv ...;
	/*L2_sv	分数*/
```
```c
typedef L2_xy ...;
	/*L2_xy	坐标的数值*/
```
```c
typedef L2_point ...;
	/*L2_point	同struct L2_point*/
```
```c
typedef L2_gb ...;
	/*L2_gb	同struct L2_gb*/
```
```c
typedef L2_sv L2_tab[4][4];
	/*L2_tab	一个棋盘*/
```
```c
typedef L2_sint ...;
	/*L2_sint	常用短整数*/
```
```c
typedef L2_pvf ...;
	/*L2_pvf	格子实际数值*/
```
```c
typedef L2_game ...;
	/*L2_game 同struct L2_game*/
```
##函数
```c
L2_game *l2_init(L2_game *game);
	/*L2_game *l2_start(L2_game *game)	初始化一个游戏实例(但不生成初始数格)；
				返回传入的指针*/
```
```c
l2_game *l2_start(L2_game *game);
	/*L2_game *l2_start(L2_game *game)	开始新游戏(生成初始数格)；
			返回传入的指针*/
```
```c
L2_sint l2_mx(L2_game *game);	/*向x正方向划动*/
L2_sint l2_fx(L2_game *game);	/*向x负方向划动*/
L2_sint l2_my(L2_game *gmae);	/*向y正方向划动*/
L2_sint l2_fy(L2_game *game);	/*向y负方向划动*/
	/*以上四个函数，若划动成功，返回已占用格子数，划动不成功返回0*/
```
```c
L2_sint l2_num(const L2_game *game);
	/*L2_sint 12_end(const L2_game *game)	 返回占用格子数；
			游戏未开始返回1，游戏已结束返回0*/
```
```c
L2_gd 12_new(L2_game *game);	
	/*L2_gd l2_new(L2_game *game)	随机生成新数字。
			返回新生成的格子*/
```
```c
L2_gb l2_new_pv(L2_game *game,const L2_gb gb);
	/*L2_gd l2_new(L2_game *game,const L2_gb gb)	生成新数字，gd参数为自定生成数字的位置以及数值，gb中坐标值取5则坐标随机，数值取0则数值随机。
			返回新生成的格子*/
```
```c
void 12_set_pv(L2_game *game,const L2_gb gb);
	/*void 12_set_gb(L2_game *game,const L2_gb gb)	设置棋盘上的数值*/
```
```c
L2_pv l2_get_pv(const L2_game *game,const L2_point);
	/*L2_pv l2_get_pv(const L2_game *game,const L2_point)	获取指定坐标上的数值
			返回该坐标上的数值*/
```
```c
L2_table *l2_get_table(const L2_game *game,L2_table *table);
	/*L2_table *l2_get_table(const L2_game *game,L2_table *table)	获取整个棋盘，table指针用于储存棋盘；
			返回table指针*/
```
```c
L2_table *l2_clone(const L2_game *game,L2_table *target);
	/*L2_table *l2_clone(const L2_game *game,L2_game *target)	克隆一个有相同数据(随机函数会复位为默认)的游戏实例；
			返回target指针*/
```
```c
L2_pv l2_set_pv(L2_game *game,const L2_gd gd);
	/*L2_pv l2_set_pv(L2_game *game,const L2_gd gd)	设置特定坐标上格子的数值；
			返回原数值*/
```
