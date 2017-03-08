#define L2_VER 1
#include <lib2048.h>

static L2_pvf _TWO[19]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144};
	/*TWO[n]=2^n*/
static L2_sv _l2_plus_sv(L2_sv sv,L2_pv pv){
	return sv+_TWO[pv];
}

L2_EX L2_game *l2_init(L2_game *game,L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e),void (*rands)(void *randi),void *randi){
/*	game->soc=0;	*/
/*	for(int n=0,n<=3,n++) for(int m=0,m<=3,m++)game->table[n][m]=0;	*/
	game->num=17;
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
#define _l2_move(ok) { \
	L2_xy hb=0; \
	L2_sint tmp=0; \
	for(L2_xy h=0;hl<=3;hl++){ \
		if(tmp){ \
			if(s(nl)==s(nb)){ \
				ok=1; \
				tmp=0; \
				soc+=_ls_plus_sv(o,++s(nb++)); \
				continue; \
			} else ++nb; \
		} \
		if(nl!=nb){ \
			s(nl)=s(nb); \
			ok=1; \
		} \
		tmp=1; \
	} \
	for(nb+=tmp;nb<=3;nb++) s(nb)=0; \
}
#define _l2_move_f() {\
	L2_sint ok=0; \
	for(L2_sint h=0;h<=3;h++) \
		_l2_move(ok); \
	return ok?l2_num(game):0; \
}
#define s(n) (game->table[3-(n)][(h)])
L2_EX L2_sint l2_mx(L2_game *game)_l2_move_f();     /*向x正方向划动*/
#undef s(n)
#define s(n) (game->table[(n)][(h)])
L2_EX L2_sint l2_fx(L2_game *game)_l2_move_f();     /*向x负方向划动*/
#undef s(n)
#define s(n) (game->table[(h)][3-(n)])
L2_EX L2_sint l2_my(L2_game *gmae)_l2_move_f();     /*向y正方向划动*/
#undef s(n)
#define s(n) (game->table[(h)][(n)])
L2_EX L2_sint l2_fy(L2_game *game)_l2_move_f();     /*向y负方向划动*/
#undef s(n)
        /*以上四个函数，若划动成功，返回已占用格子数，划动不成功返回0*/
L2_EX L2_sint l2_num(const L2_game *game){
/*	return game->num;*/
	#define t (game->table)
	if(game->num==16){
		for(L2_xy h=0;h<=3;h++){
			if(
				t[h][0]==t[h][1]||
				t[h][1]==t[h][2]||
				t[h][2]==t[h][3]||
				t[0][h]==t[1][h]||
				t[1][h]==t[2][h]||
				t[2][h]==t[3][h]
			)return 16;
		}
		game->num=17;
		return 17;
	}
}
        /*L2_sint l2_num(const L2_game *game)    返回占用格子数；
                        游戏已结束返回17*/
L2_EX L2_gb l2_new(L2_game *game){
	return L2_new_pv(game,(L2_gb){.point=(L2_point){.x=4,.y=4},.val=0});
}
        /*L2_gd l2_new(L2_game *game)   随机生成新数字。
                        返回新生成的格子*/
L2_EX L2_gb l2_new_pv(L2_game *game,const L2_gb gb){
	L2_sint count=0;
	L2_point tmp[16];
	for(L2_xy x=(gb.point.x==4?0:gb.point.x);x<=(gb.point.x==4?3:gb.point.x);x++)
		for(y=(gb.point.y==4?0:gb.point.y);y<=(gb.point.y==4?3:gb.point.y);y++)
			if(game.table[x][y]==0) tmp[count++]=(L2_point){.x=x,.y=y};
	L2_gb gb_tmp=(L2_gb){
		.point=tmp[(gb.point.x==4&&point.point.y==4)?0:*(game->rand)(game->randi,0,count-1)],
		.val=(gb.val?gb.val:*(game->rand)(game->randi,1,2))
	};
	L2_set_gb(game,gb_tmp);
	return gb_tmp;
}
        /*L2_gd l2_new(L2_game *game,const L2_gb gb)    生成新数字，gd参数为自定生成数字的位置以及数值，gb中坐标值取4则坐标随机，数值取0则数值随机。
                        返回新生成的格子*/
L2_EX void l2_set_gb(L2_game *game,const L2_gb gb){
	game->table[gb.point.x][gb.point.y]=gb.val;
}
        /*void l2_set_gb(L2_game *game,const L2_gb gb)  设置棋盘上的数值*/
L2_EX L2_pv l2_get_pv(const L2_game *game,const L2_point point){
	return game->table[point.x][point.y];
}
        /*L2_pv l2_get_pv(const L2_game *game,const L2_point point)     获取指定坐标上的数值
                        返回该坐标上的数值*/
L2_EX L2_tab *l2_get_table(const L2_game *game,L2_tab *table){
	for(int n=0;n<=3;n++) for(int m=0;m<=3;m++) table[n][m]=game->table[n][m];
	return table;
}
        /*L2_tab *l2_get_table(const L2_game *game,L2_tab *table)       获取整个棋盘，table指针用于储存棋盘；
                        返回table指针*/
L2_EX L2_tab *l2_clone(const L2_game *game,L2_game *target,L2_sint (*rand)(void *randi,L2_sint s,L2_sint e),void (*rands)(void *randi),void *randi){
	*target=*game;
	target->rand=rand;
	target->rands=rands;
	target->randi=randi;
	return target;
}
        /*L2_tab *l2_clone(const L2_game *game,L2_game *target,L2_sint (*rand)(void *randi,L2_sint s,L2_sint e),void (*rands)(void *randi),void *randi) 克隆一个有相同数据(随机函数另外传入)的游戏实例；
                        返回target指针*/
L2_EX L2_pv l2_set_pv(L2_game *game,const L2_gb gb){
	L2_pv pv=game->table[gb.point.x][gb.point.y];
	game->table[gb.point.x][gb.point.y]=gb.val;
	return pv;
}
        /*L2_pv l2_set_pv(L2_game *game,const L2_gb gb) 设置特定坐标上格子的数值；
                        返回原数值*/

