// /* 定时器中断 */
// #include "STC89C5xRC.H"
// typedef unsigned int u16;
// static u16 Time_Counter = 0;
// #define FOSC 11059200                   // 晶振频率
// #define NT   12                         // 单片机的工作周期为12T
// #define T1MS (65536 - FOSC / 12 / 1000) // 十六位二进制的最大数为 65536 减去该值所走完的时间就是 1ms
// void init_Interrupt()
// {
//     /* 中断器总开关 */
//     EA = 1;
//     /* 定时器TR0开关  (在大表中)*/
//     ET0 = 1;

//     /* 打开定时器

//    TMOD的前四位控制定时中断器 T1后四个控制定时中断器T0
//    后四位数值即代表
//    GATE (第 3 位)
//    C/T (第 2 位)
//    M1 (第 1 位)
//    M0 (第 0 位)

//     */

//     TMOD = TMOD & 11110000;
//     TMOD = TMOD | 11110001;
//     /* 设置初始值，芯片手册这么写 */
//     TL0 = T1MS;
//     TH0 = T1MS >> 8;

//     /* 定时器0的开关 */
//     TR0 = 1;
// }
// void main()
// {

//     init_Interrupt();
//     while (1);
// }

// void Interrupt_doing1() interrupt 1 // 中断码芯片手册可查
// {
//     Time_Counter++;
//     TL0 = T1MS;
//     TH0 = T1MS >> 8;
//     if (Time_Counter == 500) // 500毫秒进行跳转一次
//     {

//         P01 = ~P01;
//         // 每次运行进行初始化
//         Time_Counter = 0;
//     }
// }
