#define L2_VER 1
#include <lib2048.h>

static L2_pvf _TWO[19]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};
	/*TWO[n]=2^n*/
static L2_sv _l2_plus_sv(L2_sv sv,L2_pv pv){
	return sv+_TWO[pv];
}

L2_EX L2_game *l2_init(L2_game *game,L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e),void (*rands)(struct L2_game *game),void *randi){
/*	game->soc=0;	*/
/*	for(int n=0,n<=3,n++) for(int m=0,m<=3,m++)game->table[n][m]=0;	*/
	game->num=1;
	game->rand=rand;
	game->rands=rands;
	game->randi=randi;
	return game;
}
        /*L2_game *l2_start(L2_game *game)      初始化一个游戏实例(但不生成初始数格)；
                        返回传入的指针*/
L2_EX L2_game *l2_start(L2_game *game){
	game->soc=0;
	for(int n=0;n<=3;n++) for(int m=0;m<=3;m++)game->table[n][m]=0;
	game->num=0;
	return game;
}
        /*L2_game *l2_start(L2_game *game)      开始新游戏(生成初始数格)；
                        返回传入的指针*/
L2_EX L2_sint l2_mx(L2_game *game);     /*向x正方向划动*/
L2_EX L2_sint l2_fx(L2_game *game);     /*向x负方向划动*/
L2_EX L2_sint l2_my(L2_game *gmae);     /*向y正方向划动*/
L2_EX L2_sint l2_fy(L2_game *game);     /*向y负方向划动*/
        /*以上四个函数，若划动成功，返回已占用格子数，划动不成功返回0*/
L2_EX L2_sint l2_num(const L2_game *game){
	return game->num;
}
        /*L2_sint l2_end(const L2_game *game)    返回占用格子数；
                        游戏未开始返回1，游戏已结束返回0*/
L2_EX L2_gb l2_new(L2_game *game){
	return L2_new_pv(game,(L2_gb){.point=(L2_point){.x=4,.y=4},.val=0});
}
        /*L2_gd l2_new(L2_game *game)   随机生成新数字。
                        返回新生成的格子*/
L2_EX L2_gb l2_new_pv(L2_game *game,const L2_gb gb);
        /*L2_gd l2_new(L2_game *game,const L2_gb gb)    生成新数字，gd参数为自定生成数字的位置以及数值，gb中坐标值取5则坐标>随机，数值取0则数值随机。
                        返回新生成的格子*/
L2_EX void l2_set_gd(L2_game *game,const L2_gb gb){
	game->table[gb.point.x][gb.point.y]=gb.val;
}
        /*void l2_set_gb(L2_game *game,const L2_gb gb)  设置棋盘上的数值*/
L2_EX L2_pv l2_get_pv(const L2_game *game,const L2_point point){
	return game->table[point.x][point.y];
}
        /*L2_pv l2_get_pv(const L2_game *game,const L2_point point)     获取指定坐标上的数值
                        返回该坐标上的数值*/
L2_EX L2_tab *l2_get_table(const L2_game *game,L2_tab *table);{
	for(int n=0;n<=3;n++) for(int m=0;m<=3;m++) table[n][m]=game->table[n][m];
	return table;
}
        /*L2_tab *l2_get_table(const L2_game *game,L2_tab *table)       获取整个棋盘，table指针用于储存棋盘；
                        返回table指针*/
L2_EX L2_tab *l2_clone(const L2_game *game,L2_game *target,L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e),void (*rands)(struct L2_game *game),void *randi){
	*target=*game;
	target->rand=rand;
	target->rands=rands;
	target->randi=randi;
	return target;
}
        /*L2_tab *l2_clone(const L2_game *game,L2_game *target,L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e),void (*rands)(struct L2_game *game),void *randi) 克隆一个有相同数据(随机函数除外)的游戏实例；
                        返回target指针*/
L2_EX L2_pv l2_set_pv(L2_game *game,const L2_gb gb){
	L2_pv pv=game->table[gb.point.x][gb.point.y];
	game->table[gb.point.x][gb.point.y]=gb.val;
	return pv;
}
        /*L2_pv l2_set_pv(L2_game *game,const L2_gb gb) 设置特定坐标上格子的数值；
                        返回原数值*/

