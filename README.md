# lib2048
##关于“2048”
略
##类型  
L2_pv	格子中的数字(指数，如：格子中的数字为16，该值为4)
```c
typedef uint_least8_t L2_pv;
	/*L2_pv	格子中的数字(指数，如：格子中的数字为16，该值为4)*/
```
L2_sv	分数
```c
typedef uint_least32_t L2_sv;
	/*L2_sv	分数*/
```
L2_xy	坐标的数值
```c
typedef uint_least8_t L2_xy;
	/*L2_xy	坐标的数值*/
```
struct L2_point	格坐标  
L2_point	同struct L2_point
```c
struct L2_point{
	L2_xy x;	/*横坐标*/
	L2_xy y;	/*纵坐标*/
};
	/*struct L2_point	格坐标*/
typedef struct L2_poing L2_point;
	/*L2_point	同struct L2_point*/
```
struct L2_gb	一个格子完整的信息  
L2_gb	同struct L2_gb
```c
struct L2_gb{
	struct L2_point point;	/*格坐标*/
	L2_pv val;	/*格子中的数字(指数)*/
};
	/*struct L2_gb	一个格子完整的信息*/
typedef struct L2_gb L2_gb;
	/*L2_gb	同struct L2_gb*/
```
L2_tab	一个棋盘
```c
typedef L2_sv L2_tab[4][4];
	/*L2_tab	一个棋盘*/
```
L2_sint	常用短整数
```c
typedef uint_least8_t L2_sint;
	/*L2_sint	常用短整数*/
```
L2_pvf	格子实际数值
```c
typedef uint_least32_t L2_pvf;
	/*L2_pvf	格子实际数值*/
```
struc L2_game	游戏实例  
L2_game 同struct L2_game
```c
struct L2_game{
	L2_sv soc;	/*分数*/
	L2_tab table;	/*棋盘*/
	L2_sint num;	/*已占用格子数，值为1则游戏未开始，值为0则游戏结束*/
	L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e);	/*自定义随机函数，返回[s,e]之间的整数(s<=e)，game传入该游戏实例的指针*/
	void (*rands)(struct L2_game *game);	/*自定义随机初始化函数，game传入该游戏实例的指针*/
	void *randi;	/*供自定义随机函数使用的指针，与库无关*/
};
	/*struc L2_game	游戏实例*/
typedef struct L2_game L2_game;
	/*L2_game 同struct L2_game*/
```
