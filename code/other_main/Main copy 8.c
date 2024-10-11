// #include "STC89C5xRC.H"
// #include "STDIO.H"

// typedef unsigned int u16;
// typedef unsigned char u8;

// void Static_Digital_Tube(u8 a, u8 b);
// void Digital_Show_Refresh();
// void Delay100us(int a);
// #define KEYIN P1
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

// static u8 Number_Buffer[8];
// u8 Int_MatrixKeyboard_CheckKey();
// void Digtial_Buffer_Show(u16 num);

// // void main()
// // {

// //     u8 key_pressed;
// //     Digtial_Buffer_Show(0);
// //     while (1)
// //     {
// //         key_pressed = Int_MatrixKeyboard_CheckKey();
// //         if (key_pressed)
// //         {
// //             Digtial_Buffer_Show(key_pressed);
// //         }
// //         Digital_Show_Refresh(); // 反复刷新显示
// //     }
// // }
// void main() {
//     u8 key_pressed;

//     while (1) {
//         key_pressed = Int_MatrixKeyboard_CheckKey();
//         if (key_pressed) {
//             // 如果按键被按下，切换 P20 的状态
//             P20 = ~P20; // 反转 P20 的状态
//         }
//         // 适当的延迟可以避免过快循环
//         Delay100us(100);
//     }
// }




// // 按键矩阵驱动
// u8 Int_MatrixKeyboard_CheckKey() {
//     static u8 key_value = 0;

//     // 将P20置低以检测按键
//     KEYIN = 11111110; // 0xFE
//     Delay100us(10);   // 消抖

//     if (KEYIN != 11111110) { // 检测是否有按键按下
//         Delay100us(10); // 消抖
//         if (KEYIN != 11111110) {
//             // 检测行
//             KEYIN = 11111110; // 重新设置以检测列
//             switch (KEYIN) {
//                 case 11111010: key_value = 1; break; // 1
//                 case 11110110: key_value = 2; break; // 2
//                 case 11101110: key_value = 3; break; // 3
//                 case 11111100: key_value = 4; break; // 4
//             }

//             // 检测列
//             KEYIN = 11111100; // 切换到下一个状态
//             switch (KEYIN) {
//                 case 01111110: key_value = key_value; break; // 第1列
//                 case 10111110: key_value = key_value + 4; break; // 第2列
//                 case 11011110: key_value = key_value + 8; break; // 第3列
//                 case 11101110: key_value = key_value + 12; break; // 第4列
//             }

//             // 等待按键抬起
//             while (KEYIN != 11111110);
//         }
//     } else {
//         key_value = 0; // 没有按键被按下
//     }

//     return key_value; // 返回按键值
// }


// /* 电子管显示数字处理 */
// void Digtial_Buffer_Show(u16 num)
// {
//     u8 i;
//     // 将显存清零
//     for (i = 0; i < 8; i++)
//     {
//         Number_Buffer[i] = 0;
//     }

//     if (num == 0)
//     {
//         Number_Buffer[0] = s_digit_codes[0];
//         return;
//     }

//     // 赋值显存
//     i = 0;
//     while (num > 0 && i < 8)
//     {
//         Number_Buffer[8 - i] = s_digit_codes[num % 10]; // 从右到左填充
//         i++;
//         num /= 10;
//     }
// }

// /* 电子管刷新 */
// void Digital_Show_Refresh()
// {
//     u16 i;
//     for (i = 0; i < 8; i++)
//     {
//         Static_Digital_Tube(i, Number_Buffer[8 - i]);
//         Delay100us(1);
//     }
// }

// /* 电子管驱动 */
// void Static_Digital_Tube(u8 a, u8 b)
// {
//     // 关掉所有数码管（将 P2.2 到 P2.4 全部置高）
//     P2 = 00000000;
//     P2 = P2 & 000011100; // 000011100
//     a <<= 2;
//     // 设置段选数据到 P0
//     P2 = P2 | a;

//     /* 设置段选数据到 P0 */
//     P0 = b; // 输出段选数据（要点亮的段）
// }

// void Delay100us(int a)
// {
//     while (a > 0)
//     {
//         unsigned char i, j;
//         i = 2;  // 控制外层循环
//         j = 15; // 控制内层循环
//         do {
//             while (--j);
//         } while (--i);
//         a--;
//     }
// }
