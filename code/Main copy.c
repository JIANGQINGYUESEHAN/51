#include "STC89C5xRC.H"
void Delay100us(int a);
/*
void main()
{
//  片选信号 用来选择当前要操作的哪一个数码管。
P13=0;
P14=0;
P14=1;
// 段选信号 用来控制被选中的数码管上哪些段被点亮。
//P0 在这里代表了数码管的控制引脚，总集成控制数码管的段位。
P0=0;
P01=1;
P02=2;
while(1){}
}
*/


typedef unsigned int u16;
typedef unsigned char u8;

static u8 s_digit_codes[10] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F  // 9
};
void Static_Digital_Tube(u16 a,u8 b);
// int main(){
// Static_Digital_Tube(7,s_digit_codes[3]);
// while (1)
// {
  
// }
// }
/**
 * @brief 内部方法，让数码管某一位显示特定数字
 * 
 * @param a 片选, 从左到右[0-7]
 * @param b  显示想要的数字编码
 */

void Static_Digital_Tube(u16 a,u8 b){
//先片选
//先与或将 P13，P14，P15，都变成0;
P1=P1&0xC7;
//将值迁移三位
a<<=a;
//或进行赋值
P1=a|P1;

/* 进行段选 */
P0=b;

}

void Delay100us(int a) //@11.0592MHz
{

    while (a < 0)
    {

        unsigned char data i, j;

        i = 2;
        j = 15;
        do
        {
            while (--j);
        } while (--i);
        a--;
    }
}