#include <stdio.h>

int main()
{
    /*int a,n,i;
    double item=0;
    int sum=0;
    scanf("%d %d",&a,&n);
    for(i=1; i<=n; i++)
    {
        item=item*10+a;
        sum+=item;
    }

    printf("s = %d\n",sum);*/
    int *p[3],a[3][3],b[3],(*f)[3];int *s=NULL;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            a[i][j]=j;

        }
         b[i]=i;
    }
    f=a;//相当与数组指针接收到了数组的第一个值的首地址也就是数组的首地址
    for(int i=0;i<3;i++)
    {
        *(p+i)=a[i];
        //printf("%d\n",p[i][i]);
        *(p+i)=b[i];
        //printf("%d\n",p[i]);
        printf("%d, %d, %d, %d\n",((*f)[i]),a[i][i],sizeof(*f),sizeof(**f));//这是数组指针的作用
      /*
数组指针：数组指针可以说成是”数组的指针”，首先这个变量是一个指针。

其次，”数组”修饰这个指针，意思是说这个指针存放着一个数组的首地址，或者说这个指针指向一个数组的首地址。

根据上面的解释，可以了解到指针数组和数组指针的区别，因为二者根本就是种类型的变量。*/
    }
    printf("%d",sizeof(s));
    //总结：行指针的概念要清楚，就是可以把一个数组的首地址赋值给一个指针，然后第一次解引用可以得到一个数组的
    return 0;
}
