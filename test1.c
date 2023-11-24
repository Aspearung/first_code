#include <stdio.h>
#include <stdlib.h>

void delete_ung(int *k,int length){
    int what,where,temp1,temp2;
    int count = 0;

    for(int i=0; i<length; i++){
        printf("%d ",k[i]);
    }

    printf("\n어떤 수를 삭제할까요? : ");
    scanf("%d",&what);

    for(int i=0; i<length-1; i++){
        if( k[i] == what){
            count = count + 1;
        }
    }
    if(count == 0){
        printf("입력하신 %d는 배열에 없습니다.\n",what);
        return 0;
    }
    for(int i=0; i<length-1; i++){
        if( k[i] == what){
            printf("%d번째에 있는 %d를 삭제합니다!\n",i+1,what);
            where = i;
            break;
        }
    }
    for(int i=0; i,i<length-where; i++){
        if(where+i+1 == length){
            break;
        }
        *(k+where+i) = *(k+where+i+1);
    }

    printf("\n배열의 구성은 다음과 같습니다.\n");
    for(int i=0; i<length; i++){
        printf("%d ",k[i]);
    }

    return 0;

}

void insert_ung(int *k,int length){
    int where,what;
    int temp1,temp2;

    printf("\n배열의 구성은 다음과 같습니다.\n");
    for(int i=0; i<length; i++){
        printf("%d ",k[i]);
    }
    printf("\n삽입할 숫자를 입력해주세요.\n");
    printf("숫자 : ");
    scanf("%d",&what);

    for(int i=0; i<length-1; i++){
        if( k[i] >= what || k[i] == 0){
            where = i+1;
            break;
        }
    }

    temp1 = *(k + where-1);
    *(k+where-1) = what;

    for(int i=0; i<length-where;i++){
        temp2 = *(k+where+i);
        *(k+where+i) = temp1;
        temp1 = temp2;
    }

    printf("\n배열의 구성은 다음과 같습니다.\n");
    for(int i=0; i<length; i++){
        printf("%d ",k[i]);
    }
    return 0;

}

void print_ung(int *k,int length){
    printf("\n배열의 구성은 다음과 같습니다.\n");
    for(int i=0; i<length; i++){
        printf("%d ",k[i]);
    }
}

int main(void){
    int k[10] = {1,3,5,7,9,11};
    int user;
    int length = sizeof(k)/sizeof(int);

    while(1){
        printf("\n1.삭제 2.삽입 3.출력 : ");
        scanf("%d",&user);
        switch(user){
            case 1:{
                printf("입력하신 수를 찾고 그것을 당기며 삭제합니다.\n");
                delete_ung(k,length);
                break;
            }

            case 2:{
                printf("입력하신 수를 원하는 위치에 삽입 후 밀어내기합니다.\n");
                insert_ung(k,length);
                break;
            }

            case 3:{
                printf("현재 배열을 출력합니다.\n");
                print_ung(k,length);
                break;
            }

            default :{
                printf("잘못된 입력으로 종료합니다!\n");
                break;
            }

        }
    }

}
