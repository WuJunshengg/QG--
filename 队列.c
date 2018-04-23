#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"
/**
 *  @name        : void InitAQueue(AQueue *Q)
 *	@description : ��ʼ������
 *	@param		 : ����ָ��Q
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
 *	@description : ��ʼ������
 *	@param		 : ����ָ��Q
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
 *	@description : ���ٶ���
 *	@param		 : ����ָ��Q
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
 *	@description : ���ٶ���
 *	@param		 : ����ָ��Q
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
 *	@description : �������Ƿ�����
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
    return (Q->rear + 1) % MAXQUEUE == Q->front ? 1 : 0;
}
/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *	@description : �������Ƿ�Ϊ��
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
    return Q->front == Q->rear ? TRUE : FLASE;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *	@description : �������Ƿ�Ϊ��
 *	@param		 : ����ָ��Q
 *	@return		 : ��-TRUE; δ��-FLASE
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
 *	@description : �鿴��ͷԪ��
 *	@param		 : ����ָ��Q�����Ԫ��e
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ��
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
 *	@description : �鿴��ͷԪ��
 *	@param		 : ����ָ��Q�����Ԫ��e
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ��
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
 *	@description : ȷ�����г���
 *	@param		 : ����ָ��Q
 *	@return		 : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)
{
    return (Q->rear-Q->front+MAXQUEUE)%MAXQUEUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *	@description : ȷ�����г���
 *	@param		 : ����ָ��Q
 *	@return		 : ���г���count
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{

}

/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *	@description : ��Ӳ���
 *	@param		 : ����ָ��Q,�������ָ��data
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ����˻�Ϊ��
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
 *	@description : ��Ӳ���
 *	@param		 : ����ָ��Q,�������ָ��data
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
 *  @notice      : �����Ƿ�Ϊ��
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
 *	@description : ���Ӳ���
 *	@param		 : ����ָ��Q
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
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
 *	@description : ���Ӳ���
 *	@param		 : ����ָ��Q
 *	@return		 : �ɹ�-TRUE; ʧ��-FLASE
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
 *	@description : ��ն���
 *	@param		 : ����ָ��Q
 *	@return		 : None
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
    Q->front = Q->rear = 0;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *	@description : ��ն���
 *	@param		 : ����ָ��Q
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
 *	@description : ������������
 *	@param		 : ����ָ��Q����������ָ��foo
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
 *	@description : ������������
 *	@param		 : ����ָ��Q����������ָ��foo
 *	@return		 : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
    Node *p = Q->front->next;
    printf("˳�����\n");
    while(p)
    {
        printf("%d", p->data);
        p = p->next;
    }
    printf("\n");
}

/**
 *  @name        : void APrint(void *q)
 *	@description : ��������
 *	@param		 : ָ��q
 *	@return		 : None
 *  @notice      : None
 */
 void APrint(void *q)
 {
     int choice, c = 0, flag = 1;
     void *p = q;
     printf("���������Ԫ�ص�����\n");
     while(flag)
     {
         printf("\t1.�ַ���\n\t2.����\n\t3.������");
         scanf("%d", &c);
         switch(c)
        {
            case 1:printf("%c", *(char*)p); //�ַ���
                   flag=0;break;
            case 2:printf("%d", *(int*)p); //����
                   flag=0;break;
            case 3:printf("%f", *(float*)p); //������
                   flag=0;break;
            default:printf("�������\n");
        }
     }


 }

/**
 *  @name        : void LPrint(void *q)
 *	@description : ��������
 *	@param		 : ָ��q
 *	@return		 : None
 *  @notice      : None
 */
 void LPrint(void *q)
 {
    int choice, c = 0, flag = 1;
     void *p = q;
     printf("���������Ԫ�ص�����\n");
     while(flag)
     {
         printf("\t1.�ַ���\n\t2.����\n\t3.������");
         scanf("%d", &c);
         switch(c)
        {
            case 1:printf("%c", *(char*)p); //�ַ���
                   flag=0;break;
            case 2:printf("%d", *(int*)p); //����
                   flag=0;break;
            case 3:printf("%f", *(float*)p); //������
                   flag=0;break;
            default:printf("�������\n");
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
        printf("\t1.��ʼ������\n");
        printf("\t2.���ٶ���\n");
        printf("\t3.�������Ƿ�����\n");
        printf("\t4.�������Ƿ�Ϊ��\n");
        printf("\t5.�鿴��ͷԪ��\n");
        printf("\t6.ȷ�����г���\n");
        printf("\t7.��Ӳ���\n");
        printf("\t8.���Ӳ���\n");
        printf("\t9.��ն���\n");
        printf("\t10.������������\n");
        printf("\t11.������һ��\n");
        printf("\t������һ������\n");
        printf("\t");
        scanf("%d",&c);
        system("cls");
    switch(c)
    {
        case 1: InitAQueue(&AQ);
                printf("��ʼ���ɹ�\n");
                break;
        case 2: DestoryAQueue(&AQ);
                printf("���ٳɹ�\n");
                break;
        case 3: if(IsFullAQueue(&AQ))printf("��������\n");
                else printf("����δ��\n");
                break;
        case 4: if(IsEmptyAQueue(&AQ))printf("����Ϊ��\n");
                else printf("���в�Ϊ��\n");
                break;
        case 5: if(GetHeadAQueue(&AQ,head))
                {
                    APrint(head);
                }
                else printf("��ȡʧ��\n");
                break;
        case 6: printf("���г���Ϊ:%d",LengthAQueue(&AQ));
                break;
        case 7: printf("\t���������Ԫ�ص�����\n");
                printf("\t1.�ַ���\n\t2.����\n\t3.������\n\t");
                scanf("%d", &num);
                printf("����������:\n");
                switch(num)
                {
                    case 1:scanf("%c",&ch); //�ַ���
                           if(EnAQueue(&AQ,&ch))
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                           break;
                    case 2:scanf("%d",&intt); //����
                            if(EnAQueue(&AQ,&intt))
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                           break;
                    case 3:scanf("%f",&fl); //������
                           if(EnAQueue(&AQ,&fl))
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                           break;
                    default:printf("�������\n");
                }
                EnAQueue(&AQ, &input);
                break;
        case 8: if(DeAQueue(&AQ))
                    printf("���ӳɹ�\n");
                else
                    printf("����ʧ��\n");
                break;
        case 9: ClearAQueue(&AQ);
                break;
        case 10: if(TraverseAQueue(&AQ,APrint))
                 printf("�����ɹ�\n");
                 else
                 printf("����ʧ��\n");
                 break;
        case 11: break;
        default: printf("��������ֲ���ȷ\n");
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
        printf("\t1.��ʼ������\n");
        printf("\t2.���ٶ���\n");
        printf("\t3.�������Ƿ�Ϊ��\n");
        printf("\t4.�鿴��ͷԪ��\n");
        printf("\t5.ȷ�����г���\n");
        printf("\t6.��Ӳ���\n");
        printf("\t7.���Ӳ���\n");
        printf("\t8.��ն���\n");
        printf("\t9.������������\n");
        printf("\t11.������һ��\n");
        printf("\t������һ������\n");
        printf("\t");
        scanf("%d",&c);
        system("cls");
    switch(c)
    {
        case 1: InitLQueue(&LQ);
                printf("��ʼ���ɹ�\n");
                break;
        case 2: DestoryLQueue(&LQ);
                printf("���ٳɹ�\n");
                break;
        case 3: if(IsEmptyLQueue(&LQ))printf("����Ϊ��\n");
                else printf("���в�Ϊ��\n");
                break;
        case 4: if(GetHeadLQueue(&LQ,head))
                {
                    LPrint(head);
                }
                else printf("��ȡʧ��\n");
                break;
        case 5: printf("���г���Ϊ:%d",LengthLQueue(&LQ));
                break;
        case 6: printf("\t���������Ԫ�ص�����\n");
                printf("\t1.�ַ���\n\t2.����\n\t3.������\n\t");
                scanf("%d", &num);
                printf("����������:\n");
                switch(num)
                {
                    case 1:scanf("%c",&ch); //�ַ���
                           if(EnLQueue(&LQ,&ch))
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                           break;
                    case 2:scanf("%d",&intt); //����
                            if(EnLQueue(&LQ,&intt))
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                           break;
                    case 3:scanf("%f",&fl); //������
                           if(EnLQueue(&LQ,&fl))
                                printf("��ӳɹ�\n");
                            else
                                printf("���ʧ��\n");
                           break;
                    default:printf("�������\n");
                }
                EnLQueue(&LQ, &input);
                break;
        case 7: if(DeLQueue(&LQ))
                    printf("���ӳɹ�\n");
                else
                    printf("����ʧ��\n");
                break;
        case 8: ClearLQueue(&LQ);
                break;
        case 9:if(TraverseLQueue(&LQ,LPrint))
                printf("�����ɹ�\n");
                else    printf("����ʧ��\n");
        case 10: break;
        default: printf("��������ֲ���ȷ\n");
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
        printf("\t1.ѭ������\n");
        printf("\t2.��ʽ����\n");
        printf("\t3.�˳�\n");
        printf("\t������һ������\n");
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
        default: printf("��������ֲ���ȷ\n");
                 break;
    }
    }while(a != 3);
    return 0;
}
