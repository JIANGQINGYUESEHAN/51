/* 独立安按键加数 */

#include "STC89C5xRC.H"

#define SW1 P30
#define SW2 P31
#define SW3 P32
#define SW4 P33
typedef unsigned int u16;
typedef unsigned char u8;

void Static_Digital_Tube1(u16 a, u8 b);

void Digital_Show_Refresh();
void Delay100us(int a);
bit Press2();

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

static u8 Number = 1;
static u8 Number_Buffer[8];
void main()
{
    if (Press2())
    {
    }
}

void Digital_Number(int digtail)
{
    Number++;
    // 然后将该数转换为十六进制数
   
    while (Number != 0)
    {
        int temp = Number % 16; // 取余数

        // 将余数转换为对应的十六进制字符
        if (temp < 10)
        {
            hexNum[i] = temp + 48; // 0-9的ASCII值
        }
        else
        {
            hexNum[i] = temp + 55; // A-F的ASCII值 (A是65，所以55加上10开始是A)
        }

        Number = Number / 16; // 除以16
        i++;                  // 继续向前存储位
    }
    // 这样 Number_Buffer都是二进制数, // 然后将该数进行显示
}
void Digital_Show_Refresh()
{
}

void Static_Digital_Tube1(u16 a, u8 b)
{
    P2 = 1;
    // 先与操作，将P2.2, P2.3, P2.4都置为0
    P2 = P2 & 0xC7;
    // 11000111, 清除P2的2到4位

    // 将a左移两位，确保它对准P2.2~P2.4的位置
    a <<= 2;

    // 将a的值与P2的值进行或运算，赋值给P2
    P2 = P2 | a;

    /* 进行段选 */
    P0 = b;
}

/**
 *  按键 按下去是 1 抬起是0
 * @brief  延时消抖
 *
 * @param P30  传过哪个按钮
 * @return bit  返回真假
 */

bit Press2()
{
    // 如果按键没有按下则返回0
    if (SW2 == 1)
    {
        return 0;
    }
    /* 延迟一会， */
    Delay100us(10);
    // 等待按键按起
    while (1)
    {
        if (SW2 == 1)
        {
            Delay100us(10);
            if (SW2 == 1)
            {
                Delay100us(10);
                return 1;
            }
        }
    }
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