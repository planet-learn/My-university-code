#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

typedef int DataType;       //元素数据类型

const int MAXN = 100001; //队列最大容量

//循环队列类型定义
typedef struct
{
    DataType data[MAXN];
    int head;       //队首指针
    int tail;       //队尾指针
    int MaxSize;    //队列最大容量
} SqQueue;

//初始化一个空的循环队列：（1）设置队列最大容量，（2）设置队首、队尾指针
void InitQueue(SqQueue *&q, int capacity)
{
    //请在下面编写代码
    /**********************Begin**********************/
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->head=0;
    q->tail=0;
    q->MaxSize=capacity;
    /***********************End***********************/
}

//判队列是否为空
int QueueEmpty(SqQueue* q)
{
    //请在下面编写代码
    /**********************Begin**********************/
    if(q->head==q->tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    /***********************End***********************/
}

//判队列是否满
int QueueFull(SqQueue* q)
{
    //请在下面编写代码
    /**********************Begin***********

    ***********/
    if(((q->tail+1)%(q->MaxSize)==q->head))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    // return (((q->tail+1)%q->MaxSize)==q->head);
    /***********************End***********************/
}

//入队列操作
void Push(SqQueue* &q, DataType e)
{
    //请在下面编写代码
    /**********************Begin**********************/
    /*if((q->tail+1)%MAXN==q->head)
    {
        // return false;
        cout<<"full";
    }*/
    /*if(QueueFull(q))
    {
        cout<<"full";
    }*/
    //q->tail++;
    // q->tail=((q->tail+1)%q->MaxSize);
    //int f=q->MaxSize;
    //q->data[q->tail]=e;
    // if(QueueFull(q)==0)
    //{
    (q->tail)= ((q->tail)+1)%(q->MaxSize);
    int f=(q->tail);
    q->data[f]=e;
    //}
    //else
    //{

    //  printf("full\n");
    //}

    //q->data[f]=e;


}


// return true;

/***********************End***********************/


//删除队首元素：队首元素存入变量e
void Pop(SqQueue*& q, DataType& e)
{
    //请在下面编写代码
    /**********************Begin**********************/
    //if(q->tail==q->head)
    // {
    // return false;
    //}
    // else
    //{
    q->head=(q->head+1)%q->MaxSize;
    e=q->data[q->head];
    //}
    /***********************End***********************/
}

//取队首元素，存入变量e
void GetHead(SqQueue*& q, DataType&e)
{
    //请在下面编写代码
    /**********************Begin**********************/
    if(QueueEmpty(q))
    {
        //return;
        printf("empty\n");
    }
    else
    {
        e=q->data[(q->head+1)%q->MaxSize];
    }

    /***********************End***********************/
}
//主函数
int main()
{
    int n, q;
    scanf("%d %d", &n, &q); //输入队列容量、询问次数

    SqQueue* Q,*origin;             //声明循环队列Q
    //循环队列，里面最多放置n个元素，循环队列容量为n+1
    InitQueue(Q, n + 1);


    //请在下面编写代码
    /**********************Begin**********************/
    while((q--))
    {
        origin=Q;
        char s[4];
        scanf("%s",s);
        Q=origin;
        if(s[1]=='o')
        {
            if(!QueueEmpty(Q))
            {
                int e;
                GetHead(Q,e);
                cout<<e<<endl;
                Pop(Q,e);
            }
            else
            {
                cout<<"empty"<<endl;
            }
        }
        else if(s[1]=='r')
        {
            if(!QueueEmpty(Q))
            {
                int e;
                GetHead(Q,e);
                cout<<e<<endl;
            }
            else
            {
                cout<<"empty"<<endl;
            }
        }
        else if(s[1]=='u')
        {
            int e=0;
            scanf("%d",&e);
            if(QueueFull(Q))
            {

                cout<<"full"<<endl;
            }
            else
            {
                Push(Q,e);
            }
        }
        else
        {

        }
    }
    /***********************End***********************/
    return 0;
}

