#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *	@description : 初始化队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    Q->data_size = 0;
}

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *	@description : 初始化队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
    Q->front = (Node*)malloc(sizeof(Node));
    if(Q->front)
    {
        Q->rear = Q->front;
        Q->front->next = NULL;
    }
}
/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *	@description : 销毁队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
    free(Q->data);
    Q->front = 0;
    Q->rear = 0;
    Q->data_size = 0;
}
/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *	@description : 销毁队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
    while(Q->front)
    {
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
        if(!Q->rear)
        free(Q->rear);
    }
    free(Q->front);

}

/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *	@description : 检查队列是否已满
 *	@param		 : 队列指针Q
 *	@return		 : 满-TRUE; 未满-FLASE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    return (Q->rear + 1) % MAXQUEUE == Q->front ? 1 : 0;
}
/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *	@description : 检查队列是否为空
 *	@param		 : 队列指针Q
 *	@return		 : 空-TRUE; 未空-FLASE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    return Q->front == Q->rear ? TRUE : FLASE;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *	@description : 检查队列是否为空
 *	@param		 : 队列指针Q
 *	@return		 : 空-TRUE; 未空-FLASE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
    if(Q->front == Q->rear)
        return TRUE;
    return FLASE;
}

/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *	@description : 查看队头元素
 *	@param		 : 队列指针Q，存放元素e
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e)
{
    if(Q->front == Q->rear) return FLASE;
    else
    {
        e = Q->data[Q->front];
        return TRUE;
    }
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *	@description : 查看队头元素
 *	@param		 : 队列指针Q，存放元素e
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
    if(IsEmptyLQueue(Q))
        return FLASE;
    e = Q->front->data;
    return TRUE;
}

/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *	@description : 确定队列长度
 *	@param		 : 队列指针Q
 *	@return		 : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    return (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *	@description : 确定队列长度
 *	@param		 : 队列指针Q
 *	@return		 : 队列长度count
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{

}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *	@description : 入队操作
 *	@param		 : 队列指针Q,入队数据指针data
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
    if(IsFullAQueue(Q))
    {
        return FLASE;
    }
    Q->data[Q->rear] = data;
    Q->rear = (Q->rear + 1) % MAXQUEUE;
    Q->data_size += sizeof(data);
    return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *	@description : 入队操作
 *	@param		 : 队列指针Q,入队数据指针data
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
    Node *p = (Node*)malloc(sizeof(Node));
    if(!p)
    {
        return FLASE;
    }
    p->data = data;
    p->next = NULL;
    Q->rear->next = p;
    Q->rear = p;
}

/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *	@description : 出队操作
 *	@param		 : 队列指针Q
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
    if(IsEmptyAQueue(Q))
    {
        return FLASE;
    }
    Q->data_size -= sizeof(Q->data[Q->front]);
    Q->data[Q->front] = NULL;
//    printf("%d", Q->data[Q->front]);
    Q->front = (Q->front + 1) % MAXQUEUE;
    return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *	@description : 出队操作
 *	@param		 : 队列指针Q
 *	@return		 : 成功-TRUE; 失败-FLASE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
    Node *p;
    if(Q->rear == Q->front)
    {
        return FLASE;
    }

    p = Q->front->next;
    Q->front->next = p->next;
    if(Q->rear == p)
    {
        Q->rear = Q->front;
    }
    free(p);
    return TRUE;
}

/**
 *  @name        : void ClearAQueue(AQueue *Q)
 *	@description : 清空队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    Q->front = Q->rear = 0;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *	@description : 清空队列
 *	@param		 : 队列指针Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
    Q->front = Q->rear = NULL;
    Q->data_size = 0;
}

/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *	@description : 遍历函数操作
 *	@param		 : 队列指针Q，操作函数指针foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
    int i = Q->front;
    if(IsEmptyAQueue(Q))
    {
        return FLASE;
    }
    while(i != Q->rear)
    {
       foo(Q->data[i]);
       i = (i + 1) % MAXQUEUE;
    }
    return TRUE;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *	@description : 遍历函数操作
 *	@param		 : 队列指针Q，操作函数指针foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    Node *p = Q->front->next;
    printf("顺序输出\n");
    while(p)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 *  @name        : void APrint(void *q)
 *	@description : 操作函数
 *	@param		 : 指针q
 *	@return		 : None
 *  @notice      : None
 */
 void APrint(void *q)
 {
     int choice, c = 0, flag = 1;
     void *p = q;
     printf("请输入队列元素的类型\n");
     while(flag)
     {
         printf("\t1.字符型\n\t2.整形\n\t3.浮点型");
         scanf("%d", &c);
         switch(c)
        {
            case 1:printf("%c", *(char*)p); //字符型
                   flag=0;break;
            case 2:printf("%d", *(int*)p); //整形
                   flag=0;break;
            case 3:printf("%f", *(float*)p); //浮点型
                   flag=0;break;
            default:printf("输入错误\n");
        }
     }


 }

/**
 *  @name        : void LPrint(void *q)
 *	@description : 操作函数
 *	@param		 : 指针q
 *	@return		 : None
 *  @notice      : None
 */
 void LPrint(void *q)
 {
    int choice, c = 0, flag = 1;
     void *p = q;
     printf("请输入队列元素的类型\n");
     while(flag)
     {
         printf("\t1.字符型\n\t2.整形\n\t3.浮点型");
         scanf("%d", &c);
         switch(c)
        {
            case 1:printf("%c", *(char*)p); //字符型
                   flag=0;break;
            case 2:printf("%d", *(int*)p); //整形
                   flag=0;break;
            case 3:printf("%f", *(float*)p); //浮点型
                   flag=0;break;
            default:printf("输入错误\n");
        }
     }
 }
 void aQueue()
 {
     AQueue AQ;
     int c, num, ch, intt, fl, input;
     void *head;
     do
    {
        printf("\n\n");
        printf("\t1.初始化队列\n");
        printf("\t2.销毁队列\n");
        printf("\t3.检查队列是否已满\n");
        printf("\t4.检查队列是否为空\n");
        printf("\t5.查看队头元素\n");
        printf("\t6.确定队列长度\n");
        printf("\t7.入队操作\n");
        printf("\t8.出队操作\n");
        printf("\t9.清空队列\n");
        printf("\t10.遍历函数操作\n");
        printf("\t11.返回上一层\n");
        printf("\t请输入一个数字\n");
        printf("\t");
        scanf("%d",&c);
        system("cls");
    switch(c)
    {
        case 1: InitAQueue(&AQ);
                printf("初始化成功\n");
                break;
        case 2: DestoryAQueue(&AQ);
                printf("销毁成功\n");
                break;
        case 3: if(IsFullAQueue(&AQ))printf("队列已满\n");
                else printf("队列未满\n");
                break;
        case 4: if(IsEmptyAQueue(&AQ))printf("队列为空\n");
                else printf("队列不为空\n");
                break;
        case 5: if(GetHeadAQueue(&AQ,head))
                {
                    APrint(head);
                }
                else printf("获取失败\n");
                break;
        case 6: printf("队列长度为:%d",LengthAQueue(&AQ));
                break;
        case 7: printf("\t请输入入队元素的类型\n");
                printf("\t1.字符型\n\t2.整形\n\t3.浮点型\n\t");
                scanf("%d", &num);
                printf("请输入数据:\n");
                switch(num)
                {
                    case 1:scanf("%c",&ch); //字符型
                           if(EnAQueue(&AQ,&ch))
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                           break;
                    case 2:scanf("%d",&intt); //整形
                            if(EnAQueue(&AQ,&intt))
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                           break;
                    case 3:scanf("%f",&fl); //浮点型
                           if(EnAQueue(&AQ,&fl))
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                           break;
                    default:printf("输入错误\n");
                }
                EnAQueue(&AQ, &input);
                break;
        case 8: if(DeAQueue(&AQ))
                    printf("出队成功\n");
                else
                    printf("出队失败\n");
                break;
        case 9: ClearAQueue(&AQ);
                break;
        case 10: if(TraverseAQueue(&AQ,APrint))
                 printf("遍历成功\n");
                 else
                 printf("遍历失败\n");
                 break;
        case 11: break;
        default: printf("输入的数字不正确\n");
                 break;
    }
    }while(c!=11);
 }
 void lQueue()
 {
     LQueue LQ;
     int c, num, ch, intt, fl, input;
     void *head;
     do
    {
        printf("\n\n");
        printf("\t1.初始化队列\n");
        printf("\t2.销毁队列\n");
        printf("\t3.检查队列是否为空\n");
        printf("\t4.查看队头元素\n");
        printf("\t5.确定队列长度\n");
        printf("\t6.入队操作\n");
        printf("\t7.出队操作\n");
        printf("\t8.清空队列\n");
        printf("\t9.遍历函数操作\n");
        printf("\t11.返回上一层\n");
        printf("\t请输入一个数字\n");
        printf("\t");
        scanf("%d",&c);
        system("cls");
    switch(c)
    {
        case 1: InitLQueue(&LQ);
                printf("初始化成功\n");
                break;
        case 2: DestoryLQueue(&LQ);
                printf("销毁成功\n");
                break;
        case 3: if(IsEmptyLQueue(&LQ))printf("队列为空\n");
                else printf("队列不为空\n");
                break;
        case 4: if(GetHeadLQueue(&LQ,head))
                {
                    LPrint(head);
                }
                else printf("获取失败\n");
                break;
        case 5: printf("队列长度为:%d",LengthLQueue(&LQ));
                break;
        case 6: printf("\t请输入入队元素的类型\n");
                printf("\t1.字符型\n\t2.整形\n\t3.浮点型\n\t");
                scanf("%d", &num);
                printf("请输入数据:\n");
                switch(num)
                {
                    case 1:scanf("%c",&ch); //字符型
                           if(EnLQueue(&LQ,&ch))
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                           break;
                    case 2:scanf("%d",&intt); //整形
                            if(EnLQueue(&LQ,&intt))
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                           break;
                    case 3:scanf("%f",&fl); //浮点型
                           if(EnLQueue(&LQ,&fl))
                                printf("入队成功\n");
                            else
                                printf("入队失败\n");
                           break;
                    default:printf("输入错误\n");
                }
                EnLQueue(&LQ, &input);
                break;
        case 7: if(DeLQueue(&LQ))
                    printf("出队成功\n");
                else
                    printf("出队失败\n");
                break;
        case 8: ClearLQueue(&LQ);
                break;
        case 9:if(TraverseLQueue(&LQ,LPrint))
                printf("遍历成功\n");
                else    printf("遍历失败\n");
        case 10: break;
        default: printf("输入的数字不正确\n");
                 break;
    }
    }while(c!=11);
 }
int main()
{
    int a = 0;

    do
    {
        printf("\n\n");
        printf("\t1.循环队列\n");
        printf("\t2.链式队列\n");
        printf("\t3.退出\n");
        printf("\t请输入一个数字\n");
        printf("\t");
        scanf("%d",&a);
        system("cls");
         switch(a)
    {
        case 1: aQueue();
                break;
        case 2: lQueue();
                break;
        case 3: break;
        default: printf("输入的数字不正确\n");
                 break;
    }
    }while(a != 3);
    return 0;
}
