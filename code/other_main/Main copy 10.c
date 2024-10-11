// /*  触发四个外部中断*/
// #include "STC89C5xRC.H"
// /* 中断初始化 */
// sbit EX2 = XICON ^ 2;
// sbit EX3 = XICON ^ 6;
// sbit IT2 = XICON ^ 4;
// sbit IT3 = XICON ^ 0;
// void init_Interrupt()
// {
//     /* 打开总中断开关 */
//     EA = 1;
//     /* 打开哪个外部中断 */
//     EX0 = 1;
//     EX2 = 1;
//     EX1 = 1;
//     EX3 = 1;
//     /* 配置外部中断为下降沿触发(中断触发方式) */
//     IT0 = 1;
//     IT1 = 1;
//     IT2 = 1;
//     IT3 = 1;
// }
// void main()
// {
//     init_Interrupt(); // 调用中断器
//     P0 = 0;
//     while (1)
//     {
//     }
// }
// /* 因为尚硅谷的中断器与按键绑定在一起，所以按下四个独立按键那么中断触发 */
// /* 中断 要做的函数 */
// void Interrupt_doing1() interrupt 0
// {

//     P01 = ~P01;
// }
// void Interrupt_doing2() interrupt 2
// {

//     P02 = ~P02;
// }void Interrupt_doing3() interrupt 6
// {

//     P03 = ~P03;
// }
// void Interrupt_doing4() interrupt 7
// {

//     P04 = ~P04;
// }
