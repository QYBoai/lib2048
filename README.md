# lib2048
##关于“2048”
略
##类型  
```c
typedef uint_least8_t L2_pv;
	/*L2_pv	格子中的数字(指数，如：格子中的数字为16，该值为4)*/
```
```c
typedef uint_least32_t L2_sv;
	/*L2_sv	分数*/
```
```c
typedef uint_least8_t L2_xy;
	/*L2_xy	坐标的数值*/
```
```c
struct L2_point{
	L2_xy x=0;	/*横坐标*/
	L2_xy y=0;	/*纵坐标*/
};
	/*struct L2_point	格坐标*/
```
```c
struct L2_gb{
	L2_point point;	/*格坐标*/
	L2_pv val=0;	/*格子中的数字(指数)*/
};
	/*struct L2_gb	一个格子完整的信息*/
```
```c
typedef L2_sv L2_table[4][4];
