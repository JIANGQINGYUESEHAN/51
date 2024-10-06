#include "STC89C5xRC.H"
typedef unsigned int u16;
typedef unsigned char u8;
void Static_Digital_Tube1(u16 a, u8 b);
void Delay100us(unsigned int a);
void Digital_Number(int digtail);
void Digital_Show_Refresh();
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
static u8 Digital_Number_Buffer[8];
// 多为数码管
void main() {
 Digital_Number(654321);
    while (1) {
       Digital_Show_Refresh();
    }
}
/**
 * @brief 刷新代码表
 * 
 */
void Digital_Show_Refresh(){
u16 i;
 for (i = 0; i < 8; i++) {
            Static_Digital_Tube1(i,Digital_Number_Buffer[i]); // 使用 s_digit_codes[i]，避免越界
            Delay100us(1);
        }

}

/**
 * @brief 将每个位置要显示的数字扒到数组中存取来
 * 
 * @param digtail 要显示的数
 */
void Digital_Number(int digtail) {
    u16 i = 0;
    
    // 依次分解数字，存入显示缓冲区
    while (digtail > 0 && i < 8) {
        Digital_Number_Buffer[i] = digtail % 10;  // 取当前数字的个位
        digtail /= 10;  // 去掉最低位
        i++;
    }
    
    // 对于小于8位的数字，未使用的位置将保持显示0
    for (; i < 8; i++) {
        Digital_Number_Buffer[i] = 0;
    }
}


/**
 * @brief 控制数码管显示多少
 *
 * @param a 范围为0~7,表示第几个显示
 * @param b 范围为0~7,表示显示几
 */
void Static_Digital_Tube1(u16 a, u8 b)
{
    /* 每次片选都置空 */
    P1 = 0;
    /* 片选 */
    P1 = P1 & 0xC7;
    a <<= 3;
    P1 = P1 | a;
    /* D段选 */
    P0 = b;
}
/**
 * @brief 延迟函数
 *
 * @param a  延迟多少毫秒
 */
void Delay100us(unsigned int a) //@11.0592MHz
{

    unsigned char data i, j;

    while (a)
    {
        i = 2;
        j = 15;
        do
        {
            while (--j);
        } while (--i);
        a--;
    }
}
