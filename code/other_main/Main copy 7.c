// /* 独立安按键加数 */

// #include "STC89C5xRC.H"
// #include "STDIO.H"

// typedef unsigned int u16;
// typedef unsigned char u8;
// void Static_Digital_Tube(u8 a, u8 b);
// void Digital_Show_Refresh();
// void Delay100us(int a);

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
// #define KEYIN P1 // 假设行和列都连接到 P1 端口

// void Digtial_Buffer_Show(digtail);
// static u8 Number_Buffer[8];
// // u8 Int_MatrixKeyboard_CheckKey();
// // void main()
// // {
// //     u8 key;
// //     key = Int_MatrixKeyboard_CheckKey();
    
// //     Digtial_Buffer_Show(0);
// //     while (1)
// //     {

// //         if (key)
// //         {
// //             Digtial_Buffer_Show(key);
// //         }
// //         Digital_Show_Refresh();
// //     }
// // }

// void main() {
//    Digtial_Buffer_Show(793451);  // 修改为显示794468
//     while (1) {
//         Digital_Show_Refresh(); // 反复刷新显示
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
//     if (digtail == 0)
//     {
//         Number_Buffer[7] = s_digit_codes[0];
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
// void Static_Digital_Tube(u8 a, u8 b)
// {
//   // 关掉所有数码管（将 P2.2 到 P2.4 全部置高）
//     P2 |= 0x1C; // 0b00011100

//     // 选择当前数码管
//     P2 &= ~(0x04 << a); // 清除选择位（P2.2-P2.4）

//     // 设置段选数据到 P0
  

//     /* 设置段选数据到 P0 */
//     P0 = b;   // 输出段选数据（要点亮的段）
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