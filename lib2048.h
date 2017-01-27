#include <stdint.h>
#ifdef L2_VER
#define L2_EX 
#else
#define L2_EX extern
typedef uint_least8_t L2_pv;
	/*L2_pv	格子中的数字(指数，如：格子中的数字为16，该值为4)*/
typedef uint_least32_t L2_sv;
	/*L2_sv	分数*/
typedef uint_least8_t L2_xy;
	/*L2_xy	坐标的数值*/
struct L2_point{
	L2_xy x;	/*横坐标*/
	L2_xy y;	/*纵坐标*/
};
	/*struct L2_point	格坐标*/
typedef struct L2_point L2_point; 
	/*L2_point	同struct L2_point*/
struct L2_gb{
	struct L2_point point;	/*格坐标*/
	L2_pv val;	/*格子中的数字(指数)*/
};
	/*struct L2_gb	一个格子完整的信息*/
typedef struct L2_gb L2_gb;
	/*L2_gb	同struct L2_gb*/
typedef L2_sv L2_tab[4][4];
	/*L2_tab	一个棋盘*/
typedef uint_least8_t L2_sint;
	/*L2_sint	常用短整数*/
typedef uint_least32_t L2_pvf;
	/*L2_pvf	格子实际数值*/
struct L2_game{
	L2_sv soc;	/*分数*/
	L2_tab table;	/*棋盘*/
	L2_sint num;	/*已占用格子数，值为1则游戏未开始，值为0则游戏结束或刚开始未生成格子*/
	L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e);	/*自定义随机函数，返回[s,e]之间的整数(s<=e)，game传入该游戏实例的指针*/
	void (*rands)(struct L2_game *game);	/*自定义随机初始化函数，game传入该游戏实例的指针*/
	void *randi;	/*供自定义随机函数使用的指针，与库无关*/
};
	/*struct L2_game	游戏实例*/
typedef struct L2_game L2_game;
	/*L2_game	同struct L2_game*/
L2_EX L2_game *l2_init(L2_game *game,L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e),void (*rands)(struct L2_game *game),void *randi);
	/*L2_game *l2_start(L2_game *game,L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e),void (*rands)(struct L2_game *game),void *randi)	初始化一个游戏实例(但不生成初始数格)；
			返回传入的指针*/
L2_EX L2_game *l2_start(L2_game *game);
	/*L2_game *l2_start(L2_game *game)	开始新游戏(生成初始数格)；
			返回传入的指针*/
L2_EX L2_sint l2_mx(L2_game *game);	/*向x正方向划动*/
L2_EX L2_sint l2_fx(L2_game *game);	/*向x负方向划动*/
L2_EX L2_sint l2_my(L2_game *gmae);	/*向y正方向划动*/
L2_EX L2_sint l2_fy(L2_game *game);	/*向y负方向划动*/
	/*以上四个函数，若划动成功，返回已占用格子数，划动不成功返回0*/
L2_EX L2_sint l2_num(const L2_game *game);
	/*L2_sint l2_end(const L2_game *game)	 返回占用格子数；
			游戏未开始返回1，游戏已结束返回0*/
L2_EX L2_gb l2_new(L2_game *game);	
	/*L2_gd l2_new(L2_game *game)	随机生成新数字。
			返回新生成的格子*/
L2_EX L2_gb l2_new_pv(L2_game *game,const L2_gb gb);
	/*L2_gd l2_new(L2_game *game,const L2_gb gb)	生成新数字，gd参数为自定生成数字的位置以及数值，gb中坐标值取4则坐标随机，数值取0则数值随机。
			返回新生成的格子*/
L2_EX void l2_set_gd(L2_game *game,const L2_gb gb);
	/*void l2_set_gb(L2_game *game,const L2_gb gb)	设置棋盘上的数值*/
L2_EX L2_pv l2_get_pv(const L2_game *game,const L2_point point);
	/*L2_pv l2_get_pv(const L2_game *game,const L2_point point)	获取指定坐标上的数值
			返回该坐标上的数值*/
L2_EX L2_tab *l2_get_table(const L2_game *game,L2_tab *table);
	/*L2_tab *l2_get_table(const L2_game *game,L2_tab *table)	获取整个棋盘，table指针用于储存棋盘；
			返回table指针*/
L2_EX L2_tab *l2_clone(const L2_game *game,L2_game *target,L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e),void (*rands)(struct L2_game *game),void *randi);
	/*L2_tab *l2_clone(const L2_game *game,L2_game *target,L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e),void (*rands)(struct L2_game *game),void *randi)	克隆一个有相同数据(随机函数会复位为默认)的游戏实例；
			返回target指针*/
L2_EX L2_pv l2_set_pv(L2_game *game,const L2_gb gb);
	/*L2_pv l2_set_pv(L2_game *game,const L2_gb gb)	设置特定坐标上格子的数值；
			返回原数值*/
