#define L2_INLINE
#include <lib2048.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define head1 static
/*head1 char *centerPvf(const L2_pvf pvf,char *str);*/
head1 void priPv(const L2_pv pv);
head1 void priTab(L2_tab *tab);
head1 void priInfo(L2_game *game);
head1 void priAll(L2_game *game);
head1 void priHelp(){
	printf("w,s,a,d to move Up,Down,Left,Right.\nq to Quit.");
}
static L2_sint randa(void *randi,L2_sint s,L2_sint e);
static void rands(void *);
static void rands(void *a){
	srand((unsigned)time(NULL));
}
static L2_sint randa(void *randi,L2_sint s,L2_sint e){
	return (rand())%(e-s+1)+s;
}
//head1 void priTab()
head1 void priAll(L2_game *game){
	printf("Table:\n");
	priTab(&(game->table));
	printf("Info:\n");
	priInfo(game);
}
head1 void priInfo(L2_game *game){
	printf("Score:");
	printf("%" L2_SV_PRIu,l2_get_soc(game));
	printf( " Block Num:");
	printf("%" L2_SINT_PRIu,l2_num(game));
	printf("\n");
}
head1 void priTab(L2_tab *tab){
#define max(a,b) ((a)>(b)?(a):(b))
//	int ml[4]={};
	for(L2_sint y=0;y<=3;y++){
		for(L2_sint x=0;x<=3;x++)
			priPv((*tab)[x][y]);
	printf("\n");
	}
}
head1 void priPv(const L2_pv pv){
	if(pv!=0) printf("\033[1;31m%" L2_PVF_PRIu "\033[0m",l2_pv2pvf(pv));
	else printf("0");
	printf("	");
}
int main(){
	printf("Welcome to Demo of Lib2048!\nInput \'h\' to get help.\n");
	L2_game game;
	l2_init(&game,randa,rands,(void*)0);
	start:
	l2_start(&game);
	l2_new(&game);
	l2_new(&game);
	priAll(&game);
	while(1){
		printf("\n>");
		char key;
		s:
		key=getchar();
		if(key==EOF || key=='\n') goto s;
		switch(key){
			#define move(m) { \
				if(l2_num(&game)==17) printf("Ended!\n"); \
				else if(! m (&game)) printf("Move fail!"); \
				else {l2_new(&game); priAll(&game);} }
			case 'w': move(l2_fy); break;
			case 's': move(l2_my); break;
			case 'a': move(l2_fx); break;
			case 'd': move(l2_mx); break;
			case 'R': goto start;
			case 'i': priAll(&game); break;
			case 'q': printf("GoodBye!\n"); return 0;
			case 'h': priHelp(); break;
			default: printf("Error! Unknown Command. \n");priHelp();
		}
	}
}
