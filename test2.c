
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
    printf("%d를 스택에 넣겠습니다.\n",value);
    if(ung->top >= 5){
        printf("메모리 오버플로우!\n");
    }
    else{
        ung->data[ung->top] = value;
        ung->top++;
    }
}

void pop(stack *ung){
    if(ung->top < 0){
        printf("메모리 언더플로우!\n");
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
        printf("\n1.삽입 2.삭제  3.출력 : ");
        scanf("%d",&user);
        switch(user){
            case 1:{
                printf("입력하신 수를 스택에 넣습니다.\n");
                printf("입력 : ");
                scanf("%d",&value);
                push(&ung,value);
                break;
            }

            case 2:{
                printf("top위치에 있는 값을 삭제합니다.\n");
                pop(&ung);
                break;
            }

            case 3:{
                printf("현재 스택을 출력합니다.\n");
                print_stack(&ung);
                break;
            }

            default :{
                printf("잘못된 입력으로 종료합니다!\n");
                break;
            }

        }
    }

}
