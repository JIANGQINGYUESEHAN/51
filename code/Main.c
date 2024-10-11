#include "STC89C5xRC.H"
#include "STDIO.H"

typedef unsigned int u16;
typedef unsigned char u8;

typedef void (*Callback_Function)(void);

#define Callback_Function_Max_Count 4
#define FOSC 11059200                   // 晶振频率
#define NT   12                         // 单片机的工作周期为12T
#define T1MS (65536 - FOSC / 12 / 1000) // 十六位二进制的最大数为 65536 减去该值所走完的时间就是 1ms

Callback_Function Callback_Function_Array[Callback_Function_Max_Count];
static u16 Time_Counter = 0;

void init_Interrupt()
{
      u8 i ;
    EA  = 1;
    ET0 = 1;

    TCON = TCON & 11110000;
    TCON = TCON | 11110001;

    TL0 = T1MS;
    TH0 = T1MS >> 8;

    /* 定时器0的开关 */
    TR0 = 1;
    // 函数初始化;

    for (i = 0; i < Callback_Function_Max_Count; i++)
    {
        Callback_Function_Array[i] = NULL;
    }
}

// 初始化回调函数
bit Callback_Function_Initialization(Callback_Function callback)
{
      u8 i ;
    for (i = 0; i < Callback_Function_Max_Count; i++)
    {
        if (Callback_Function_Array[i] == NULL)
        {
            Callback_Function_Array[i] = callback;
            return 1; // 成功注册
        }
    }
    return 0; // 注册失败，数组已满
}
// 逆初始化

bit Dri_Timer0_DeregisterCallback(Callback_Function callback)
{
     u8 i ;
    for (i = 0; i < Callback_Function_Max_Count; i++)
    {
        if (Callback_Function_Array[i] == callback)
        {
            Callback_Function_Array[i] = NULL;
            return 1;
        }
    }
    return 0;
}
void main()
{

    
}

void Interrupt_doing1() interrupt 1 // 中断码芯片手册可查
{
     u8 i ;
    Time_Counter++;
    TL0 = T1MS;
    TH0 = T1MS >> 8;
    // 调用回调函数
  
    for (i = 0; i < Callback_Function_Max_Count; i++)
    {
        if (Callback_Function_Array[i] != NULL)
        {
            Callback_Function_Array[i]();
        }
    }
}
