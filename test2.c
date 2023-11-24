
#include <stdio.h>
#include <stdlib.h>
#define element int
#define maxsize 4

typedef struct stack{
    element top;
    element bottom;
    element data[maxsize];
}stack;

void stack_first(stack *ung){
    ung->top = 0;
    ung->bottom = 0;
    //ung->data[ung->top] = 0;
}

void push(stack *ung,element value){
    printf("%d�� ���ÿ� �ְڽ��ϴ�.\n",value);
    if(ung->top >= 5){
        printf("�޸� �����÷ο�!\n");
    }
    else{
        ung->data[ung->top] = value;
        ung->top++;
    }
}

void pop(stack *ung){
    if(ung->top < 0){
        printf("�޸� ����÷ο�!\n");
    }
    else{
        ung->data[--ung->top];
    }
}

void print_stack(stack *ung){
    for(int i = ung->top-1; i>=ung->bottom ; i--){
        printf("%d<-",ung->data[i]);
    }
}

int main(void){
    int user,value;
    stack ung;

    stack_first(&ung);

    while(1){
        printf("\n1.���� 2.����  3.��� : ");
        scanf("%d",&user);
        switch(user){
            case 1:{
                printf("�Է��Ͻ� ���� ���ÿ� �ֽ��ϴ�.\n");
                printf("�Է� : ");
                scanf("%d",&value);
                push(&ung,value);
                break;
            }

            case 2:{
                printf("top��ġ�� �ִ� ���� �����մϴ�.\n");
                pop(&ung);
                break;
            }

            case 3:{
                printf("���� ������ ����մϴ�.\n");
                print_stack(&ung);
                break;
            }

            default :{
                printf("�߸��� �Է����� �����մϴ�!\n");
                break;
            }

        }
    }

}
