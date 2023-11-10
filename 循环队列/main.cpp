#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

typedef int DataType;       //Ԫ����������

const int MAXN = 100001; //�����������

//ѭ���������Ͷ���
typedef struct
{
    DataType data[MAXN];
    int head;       //����ָ��
    int tail;       //��βָ��
    int MaxSize;    //�����������
} SqQueue;

//��ʼ��һ���յ�ѭ�����У���1�����ö��������������2�����ö��ס���βָ��
void InitQueue(SqQueue *&q, int capacity)
{
    //���������д����
    /**********************Begin**********************/
    q=(SqQueue*)malloc(sizeof(SqQueue));
    q->head=0;
    q->tail=0;
    q->MaxSize=capacity;
    /***********************End***********************/
}

//�ж����Ƿ�Ϊ��
int QueueEmpty(SqQueue* q)
{
    //���������д����
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

//�ж����Ƿ���
int QueueFull(SqQueue* q)
{
    //���������д����
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

//����в���
void Push(SqQueue* &q, DataType e)
{
    //���������д����
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


//ɾ������Ԫ�أ�����Ԫ�ش������e
void Pop(SqQueue*& q, DataType& e)
{
    //���������д����
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

//ȡ����Ԫ�أ��������e
void GetHead(SqQueue*& q, DataType&e)
{
    //���������д����
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
//������
int main()
{
    int n, q;
    scanf("%d %d", &n, &q); //�������������ѯ�ʴ���

    SqQueue* Q,*origin;             //����ѭ������Q
    //ѭ�����У�����������n��Ԫ�أ�ѭ����������Ϊn+1
    InitQueue(Q, n + 1);


    //���������д����
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

