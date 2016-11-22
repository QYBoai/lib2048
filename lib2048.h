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
typedef struct L2_poing L2_point;
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
	L2_sint num;	/*已占用格子数，值为1则游戏未开始，值为0则游戏结束*/
	L2_sint (*rand)(struct L2_game *game,L2_sint s,L2_sint e);	/*自定义随机函数，返回[s,e]之间的整数(s<=e)，game传入该游戏实例的指针*/
	void (*rands)(struct L2_game *game);	/*自定义随机初始化函数，game传入该游戏实例的指针*/
	void *randi;	/*供自定义随机函数使用的指针，与库无关*/
};
	/*struct L2_game	游戏实例*/
typedef struct L2_game L2_game;
	/*L2_game	同struct L2_game*/
L2_gd 12_new(L2_game *game);
	/*L2_gd l2_new(L2_game *game)	随机生成新数字。
			返回新生成的格子*/
L2_gb l2_new_pv(L2_game *game,const L2_gb gb);
	/*L2_gd l2_new(L2_game *game,const L2_gb gb)	生成新数字，gd参数为自定生成数字的位置以及数值，gb中坐标值取5则坐标随机，数值取0则数值随机。
			返回新生成的格子*/
void 12_set_pv(L2_game *game,const L2_gb gb);
	/*void 12_set_gb(L2_game *game,const L2_gb gb)	设置棋盘上的数值*/
L2_pv l2_get_pv(const L2_game *game,const L2_point);
	/*L2_pv l2_get_pv(const L2_game *game,const L2_point)	获取指定坐标上的数值
			返回该坐标上的数值*/
L2_table *l2_get_table(const L2_game *game,L2_table *table);
	/*L2_table *l2_get_table(const L2_game *game,L2_table *table)	获取整个棋盘，table指针用于储存棋盘；
			返回table指针*/
