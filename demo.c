#define L2_INLINE
#include <lib2048.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define head1 static
/*head1 char *centerPvf(const L2_pvf pvf,char *str);*/
head1 void priPvf(const L2_pvf pvf);
head1 void priTab(L2_tab *tab);
head1 void priInfo(L2_game *game);
head1 void priAll(L2_game *game);
head1 void priHelp(){
	printf("***help\n");
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
	for(L2_sint y=0;y<=3;y++){
		for(L2_sint x=0;x<=3;x++)
			priPvf(l2_pv2pvf((*tab)[x][y]));
	printf("\n");
	}
}
head1 void priPvf(const L2_pvf pvf){
	if(pvf!=1) printf("%" L2_PVF_PRIu,pvf);
	else printf("0");
	printf(" ");
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
			case 'u': move(l2_fy); break;
			case 'd': move(l2_my); break;
			case 'l': move(l2_fx); break;
			case 'r': move(l2_mx); break;
			case 'R': goto start;
			case 'a': priAll(&game); break;
			case 'q': printf("GoodBye!\n"); return 0;
			case 'h': priHelp(); break;
			default: printf("Error! Unknown Command. \n");priHelp();
		}
	}
}
