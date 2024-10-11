// /* 按下按钮控制LED灯 */

// #include "STC89C5xRC.H"

// #define SW1 P30
// #define SW2 P31
// #define SW3 P32
// #define SW4 P33

// void Delay100us(int a);
// bit Press1();
// bit Press2();
// bit Press3();
// bit Press4();
// void main()
// {
//     if (Press1())
//     {
//         P20 = ~P20;
//     }
//     if (Press2())
//     {
//         P21 = ~P21;
//     }
//     if (Press3())
//     {
//         P22 = ~P22;
//     }
//     if (Press4())
//     {
//         P23 = ~P23;
//     }
// }
// /**
//  *  按键 按下去是 1 抬起是0
//  * @brief  延时消抖
//  *
//  * @param P30  传过哪个按钮
//  * @return bit  返回真假
//  */
// bit Press4()
// {
//     // 如果按键没有按下则返回0
//     if (SW4 == 1)
//     {
//         return 0;
//     }
//     /* 延迟一会， */
//     Delay100us(10);
//     // 等待按键按起
//     while (1)
//     {
//         if (SW4 == 1)
//         {
//             Delay100us(10);
//             if (SW4 == 1)
//             {
//                 Delay100us(10);
//                 return 1;
//             }
//         }
//     }
// }
// bit Press1()
// {
//     // 如果按键没有按下则返回0
//     if (SW1 == 1)
//     {
//         return 0;
//     }
//     /* 延迟一会， */
//     Delay100us(10);
//     // 等待按键按起
//     while (1)
//     {
//         if (SW1 == 1)
//         {
//             Delay100us(10);
//             if (SW1 == 1)
//             {
//                 Delay100us(10);
//                 return 1;
//             }
//         }
//     }
// }
// bit Press2()
// {
//     // 如果按键没有按下则返回0
//     if (SW2 == 1)
//     {
//         return 0;
//     }
//     /* 延迟一会， */
//     Delay100us(10);
//     // 等待按键按起
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

// bit Press3()
// {
//     // 如果按键没有按下则返回0
//     if (SW3 == 1)
//     {
//         return 0;
//     }
//     /* 延迟一会， */
//     Delay100us(10);
//     // 等待按键按起
//     while (1)
//     {
//         if (SW3 == 1)
//         {
//             Delay100us(10);
//             if (SW3 == 1)
//             {
//                 Delay100us(10);
//                 return 1;
//             }
//         }
//     }
// }
// void Delay100us(int a) //@11.0592MHz
// {

//     while (a < 0)
//     {

//         unsigned char data i, j;

//         i = 2;
//         j = 15;
//         do
//         {
//             while (--j);
//         } while (--i);
//         a--;
//     }
// }