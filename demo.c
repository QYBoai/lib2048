#define L2_INLINE
//#include <conio.h>
#include <lib2048.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#define head1 static
/*head1 char *centerPvf(const L2_pvf pvf,char *str);*/
head1 int getch(void);
head1 char *color[]={
"\033[8m", /*0 0*/
"\033[1;40;31m", /*1 2*/
"\033[1;40;32m", /*2 4*/
"\033[1;40;33m", /*3 8*/
"\033[1;40;34m", /*4 16*/
"\033[1;40;35m", /*5 32*/
"\033[1;40;36m", /*6 64*/
"\033[1;40;37m", /*7 128*/
"\033[1;41;32m", /*8 256*/
"\033[1;41;33m", /*9 512*/
"\033[1;41;34m", /*10 1024*/
"\033[1;41;35m", /*11 2048*/
"\033[1;41;36m", /*12 4096*/
"\033[1;41;37m", /*13 8192*/
"\033[1;42;33m", /*14 16384*/
"\033[1;42;34m", /*15 32768*/
"\033[1;42;35m", /*16 65536*/
"\033[1;42;36m", /*17 131072*/
"\033[1;42;37m", /*18 262144*/
"\033[1;43;34m"  /*19 524288*/
};
int getch(void)
{
        int c=0;
        struct termios org_opts, new_opts;
        int res=0;
        //保留终端原来设置
        res=tcgetattr(STDIN_FILENO, &org_opts);
        assert(res==0);
        //从新设置终端参数
        memcpy(&new_opts, &org_opts, sizeof(new_opts));
        new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | /* ECHOPRT | ECHOKE |*/  ICRNL);
        tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
        c=getchar();
        //恢复中断设置
        res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);assert(res==0);
        return c;
}
head1 void priPv(const L2_pv pv);
head1 void priTab(L2_tab *tab);
head1 void priInfo(L2_game *game);
head1 void priAll(L2_game *game);
head1 void priHelp(){
	printf("\033[1mw,s,a,d\033[0m to move Up,Down,Left,Right.\n\033[1mq\033[0m to Quit.\n");
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
	printf(color[pv]);
	if(pv!=0) printf("%" L2_PVF_PRIu ,l2_pv2pvf(pv));
	else printf("0");
	printf("	\033[0m");
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
		printf("\n\033[8m");
		char key;
		s:
		key=getch();
		if(key==EOF || key=='\n') goto s;
		printf("\033[2J\033[0m\n");
		switch(key){
			#define move(m) { \
				if(l2_num(&game)==17) printf("Ended!\n"); \
				else if(! m (&game)) printf("Move fail!\n"); \
				else l2_new(&game); priAll(&game);}
			case 'w': move(l2_fy); break;
			case 's': move(l2_my); break;
			case 'a': move(l2_fx); break;
			case 'd': move(l2_mx); break;
			case 'R': goto start;
			case 'i': priAll(&game); break;
			case 'q': printf("GoodBye!\n"); return 0;
			case 'h': priHelp(); priAll(&game); break;
			default: printf("Error! Unknown Command. \n"); priHelp(); priAll(&game);
		}
	}
}
