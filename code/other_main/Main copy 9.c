// /* 中断
// 总共有八个中断
// 四个 外部中断





//  */
// #include "STC89C5xRC.H"
// /* 中断初始化 */
// void init_Interrupt()
// {
//     /* 打开总中断开关 */
//     EA = 1;
//     /* 打开哪个外部中断 */
//     EX0 = 1;
//     // 配置外部中断为下降沿触发(中断触发方式)
//     IT0 = 1;
// }
// void main()
// {
//     init_Interrupt();//调用中断器
//     P0 = 0;
//     while (1)
//     {
//     }
// }
// /* 中断 要做的函数 */
// void Interrupt_doing() interrupt 0
// {

//     P0 = ~P0;
// }
