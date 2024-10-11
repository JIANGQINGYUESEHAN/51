// /* 独立安按键加数 */

// #include "STC89C5xRC.H"
// #include "STDIO.H"
// #define SW1 P30
// #define SW2 P31
// #define SW3 P32
// #define SW4 P33
// typedef unsigned int u16;
// typedef unsigned char u8;
// void Static_Digital_Tube(u16 a, u8 b);
// void Digital_Show_Refresh();
// void Delay100us(int a);
// bit Press2();

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

// void Digtial_Buffer_Show(digtail);
// static u8 Number_Buffer[8];
// void Number_Dispaly(char *str);

// void main()
// {
//     u16 i, count[4], str[9];
//     for (i = 0; i < 4; i++)
//     {
//         count[i] = 0;
//     }
//     while (1)
//     {
//         if (Press2())
//         {
//             count[2]++;
//             sprintf(str, "%02d%02d%02d%02d", (int)count[0], (int)count[1], (int)count[2], (int)count[3]);
//             Number_Dispaly(str);
//         }
        
//     }
// }
// /* 数字管进行拼串 */
// void Number_Dispaly(char *str)
// {
//     u16 i;
//     for (i = 0; i < 8; i++)
//     {
//         if (str[i] <= '9' || str[i] >= '0')
//         {
//             Number_Buffer[i] = s_digit_codes[str[i] - '0'];
//         }
//         Digital_Show_Refresh();
//     }
// }

// /* 电子管显示数字处理 */
// void Digtial_Buffer_Show(digtail)
// {
//     // 先全部清 0;
//     u16 i;
//     for (i = 0; i < 8; i++)
//     {
//         Number_Buffer[i] = 0;
//     }
//     // 判断大小如果小与0直接return
//     if (digtail < 0)
//     {
//         return;
//     }
//     // 进行分解
//     i = 0; // 从数组的起始位置（最左侧）开始赋值
//     while (digtail > 0 && i < 8)
//     {
//         Number_Buffer[i] = s_digit_codes[digtail % 10];
//         // 排除个位
//         digtail = digtail / 10;
//         i++; // 移动到下一个显示位置
//     }
// }

// /* 电子管刷新 */
// void Digital_Show_Refresh()
// {
//     u16 i;
//     for (i = 0; i < 8; i++)
//     {
//         Static_Digital_Tube(i, Number_Buffer[i]);
//         Delay100us(1);
//     }
// }
// /* 电子管驱动 */
// void Static_Digital_Tube(u16 a, u8 b)
// {
//     P2 = 1;
//     // 先与操作，将P2.2, P2.3, P2.4都置为0
//     P2 = P2 & 0xC7;
//     // 11000111, 清除P2的2到4位

//     // 将a左移两位，确保它对准P2.2~P2.4的位置
//     a <<= 2;

//     // 将a的值与P2的值进行或运算，赋值给P2
//     P2 = P2 | a;

//     /* 进行段选 */
//     P0 = b;
// }

// // 按键驱动
// bit Press2()
// {
//     // 首次按下判断是否按下 （按下是1，松开是0）
//     if (SW2 == 1)
//     {
//         return 0;
//     }
//     // 延迟消抖
//     Delay100us(10);

//     while (1)
//     {
//         if (SW2 == 1)
//         {
//             Delay100us(10);
//             if (SW2 == 1)
//             {
//                 Delay100us(10);
//                 return 1;
//             }
//         }
//     }
// }

// void Delay100us(int a)
// {
//     while (a > 0)
//     {
//         unsigned char i, j;

//         i = 2;
//         j = 15;
//         do
//         {
//             while (--j);
//         } while (--i);
//         a--;
//     }
// }