#include <stdio.h>
#include <stdlib.h>

//定义student，用来存储学生信息
struct student
{
    char id[11];//10位id
    char name[13];//不超过4个汉字
    char sex;//f或m
    int age;//年龄
    float score[3];//语文、数学、英语三科成绩
};

//设置student的函数
void setStudent(struct student *s)
{
    printf("请输入学生id:");
    scanf("%s", s->id );
    printf("请输入学生姓名:");
    scanf("%s", s->name );
    printf("请输入学生性别(f&m):");
    scanf("%c", &(s->sex) );
    printf("请输入学生年龄");
    scanf("%d", &(s->age) );
    printf("请输入语文成绩:");
    scanf("%f", &(s->score[0]) );
    printf("请输入数学成绩:");
    scanf("%f", &(s->score[1]) );
    printf("请输入英语成绩:");
    scanf("%f", &(s->score[2]) );
}
//输出student的函数
void putStudent(const struct student *s)
{
    printf("学号:%s",s->id);
    printf("姓名:%s",s->name);
    printf("性别:%c",s->sex);
    printf("年龄:%d",s->age);
    printf("语文:%f",s->score[0]);
    printf("数学:%f",s->score[1]);
    printf("英语:%f",s->score[2]);
    printf("\n");
}
//1.定义节点类型
struct node
{
    struct student data; 
    struct node *next;
};
void setNode(struct node *p,int n)
{
    setStudent(&(p->data) );
}

void putNode(struct node *p)
{
    putStudent( &(p->data) );
}

struct node *head = NULL; //一个空链表

//插入函数
struct node *insert_head(struct node *head, int temp)
{
    struct node *p_new = NULL;
    //1.申请空间
    p_new = (struct node *)malloc(sizeof(struct node));
    //2.填充数据
    setNode(p_new->data,temp);
    //3.插入链表
    p_new->next = head;
    head = p_new;

    return head;
}
struct node *insert_tail(struct node *head, int temp)
{
    struct node *p_new = NULL;
    struct node *p_set = NULL;
    //1.申请空间
    p_new = (struct node *)malloc(sizeof(struct node));
    //2.填充数据
    setNode(p_new->data,temp);

    //3.插入链表
    p_set = head;
    while (p_set != NULL && p_set->next != NULL)
    {
        p_set = p_set->next;
    }
    if (p_set == NULL)
    {
        head = p_new;
    }
    else
    {
        p_set->next = p_new;
    }
    p_new->next = NULL;

    return head;
}

struct node *insert_sort(struct node *head, int temp)
{
    struct node *p_new = (struct node *)malloc(sizeof(struct node));
    struct node *p1;

    setNode(p_new->data,temp);
    p_new->next = NULL;

    if (head == NULL)
    {
        head = p_new;
        return head;
    }

    p1 = head;
    if (p1->data > p_new->data)
    {
        p_new->next = p1;
        head = p_new;
        return head;
    }
    while ((p1->next != NULL) && (p1->next->data < p_new->data))
    {
        p1 = p1->next;
    }
    p_new->next = p1->next;
    p1->next = p_new;
    return head;
}

struct node *insert_sort2(struct node *head, int temp)
{
    struct node *p_new = (struct node *)malloc(sizeof(struct node));
    struct node *p1, *p2;

    setNode(p_new->data,temp);
    p_new->next = NULL;

    p2 = p1 = head;
    while ((p1 != NULL) && (p1->data < p_new->data))
    {
        p2 = p1;
        p1 = p1->next;
    }
    //p2==p1==head 情况1
    if (p2 == p1)
    {
        head = p_new;
    }
    else
    {
        p2->next = p_new;
    }
    p_new->next = p1;

    return head;
}

struct node *delete_node(struct node *head, int temp)
{
    struct node *p1, *p2;
    p2 = p1 = head;
    while (p1 != NULL && (p1->data != temp))
    {
        p2 = p1;
        p1 = p1->next;
    }
    if (p1 == NULL)
    {
        printf("没找到需要删除的节点\n");
        return head;
    }
    else
    {
        if (p1 == p2)
        {
            head = p1->next;
        }
        else
        {
            p2->next = p1->next;
        }
        free(p1);
    }
    return head;
}
void print_link(const struct node *head)
{
    while (head != NULL)
    {
        putNode(head->data);
        head = head->next;
    }
}
int main()
{
    int sel;
    int temp;
    int flag=1;
    struct node *head = NULL;
    while (flag)
    {
        printf("学生管理系统:\n请输入你的选择:\n");
        printf("1.插入;2.删除;3.显示;4.退出\n");
        scanf("%d", &sel);
        switch (sel)
        {
        case 1:
            printf("请输入插入的数据:");
            scanf("%d", &temp);
            head = insert_sort2(head, temp);
            break;
        case 2:
            printf("请输入要删除的数据:");
            scanf("%d", &temp);
            head = delete_node(head, temp);
            break;
        case 3:
            print_link(head);
            break;
        case 4:
            flag=0;
            break;
        }
    }
    printf("程序退出!\n");
    return 0;
}