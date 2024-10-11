/* 一百倒计时 */

// #include "STC89C5xRC.H"

// typedef unsigned int u16;
// typedef unsigned char u8;

// void Static_Digital_Tube1(u16 a, u8 b);
// void Delay100us(unsigned int a);
// void Digital_Number(int digtail);
// void Digital_Show_Refresh();

// static u8 s_digit_codes[10] = {
//     0x3F, // 0
//     0x06, // 1
//     0x5B, // 2
//     0x4F, // 3
//     0x66, // 4
//     0x6D, // 5
//     0x7D, // 6
//     0x07, // 7
//     0x7F, // 8
//     0x6F  // 9
// };

// static u8 Digital_Number_Buffer[8];

// // 多位数码管
// void main()
// {
//     char i = 100;
//     u8 n   = 20;
//     while (1)
//     {
//         n--;
//         if (n == 0)
//         {
//             n = 20; 
//             if (i > 0)
//             {
//                 i--;
//             }

//             Digital_Number(i);
//             if (i == 0)
//             {
//                 i = 100;
//             }
//         }
//         Digital_Show_Refresh();
//     }
// }

// /**
//  * @brief 刷新代码表
//  */
// void Digital_Show_Refresh()
// {
//     u16 i;
//     for (i = 0; i < 8; i++)
//     {
//         Static_Digital_Tube1(i, Digital_Number_Buffer[i]); // 显示当前数字
//         Delay100us(1);                                     // 增加延迟以便人眼可见
//     }
// }

// void Digital_Number(int digtail)
// {
//     u8 i;

//     // 将显存清零
//     for (i = 0; i < 8; i++)
//     {
//         Digital_Number_Buffer[i] = 0; // 清空缓冲区
//     }
//     i = 0; // 从数组的起始位置（最左侧）开始赋值

//     // 赋值显存
//     while (digtail > 0 && i < 8)
//     {
//         Digital_Number_Buffer[i] = s_digit_codes[digtail % 10]; // 取个位数字，并从左侧开始填充
//         digtail /= 10;                                          // 去掉最低位
//         i++;                                                    // 移动到下一个显示位置
//     }
// }

// /**
//  * @brief 控制数码管显示多少
//  *
//  * @param a 范围为0~7,表示第几个显示
//  * @param b 范围为0~7,表示显示几
//  */
// void Static_Digital_Tube1(u16 a, u8 b)
// {
//     // 清空P2的2-4位，保持其他位不变
//     P2 = P2 & 11110001; // 0xC7 -> 11000111，清空P2.2 ~ P2.4

//     // 将a左移3位，确保它对准P2.2~P2.4的位置
//     a <<= 2;

//     // 片选操作：将选择的数码管赋值到P2
//     P2 = P2 | a;

//     // 段选操作：将段码赋值到P0
//     P0 = b;
// }

// /**
//  * @brief 延迟函数
//  *
//  * @param a  延迟多少毫秒
//  */
// void Delay100us(unsigned int a)
// { // @11.0592MHz
//     unsigned char i, j;

//     while (a)
//     {
//         i = 2;
//         j = 15; // 在这里声明 j
//         do {
//             while (--j);
//         } while (--i);
//         a--;
//     }
// }
