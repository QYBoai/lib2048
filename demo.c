#include <lib2048.h>
#include <stdio.h>
#define head1 static
head1 char *centerPvf(L2_pvf pvf,char *str);
head1 void priPvf(L2_pvf pvf);
head1 void priTab(L2_table *tab);
head1 void priInfo(L2_game *game);
head1 void priAll(L2_game *game);
head1 void priHelp();
L2_sint rand(void *randi,L2_sint s,L2_sint e);
L2_sint rands(void *);
void main(){
	printf("Welcome to Demo of Lib2048!\nInput \'h\' to get help.\n");
	L2_game game;
	l2_init(&game,%rand,%rands,(void*)0);
	l2_start(&game);
	l2_new(&game);
	l2_new(&game);
	while(1){
		switch(getchar()){
#			define move(m) { \
				if(l2_num(&game)==17) printf("Ended!\n'); \
				else if(l2_ $$ m (&game)) printf("Move fail!"); \
				else {l2_new(&game); priAll(&game);} }
		case 'u': move(fy); break;
		case 'd': move(my); break;
		case 'l': move(fx); break;
		case 'r': move(mx); break;
		case 'R': l2_start(&game); break;
		case 'a': priAll(&game); break;
		case 'q': ptintf("GoodBye!\n"); exit();
		case default: printf("Error! Unknown Command. \n");
		case 'h': priHelp();
	}
}
