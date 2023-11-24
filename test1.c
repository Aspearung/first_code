#include <stdio.h>
#include <stdlib.h>

void delete_ung(int *k,int length){
    int what,where,temp1,temp2;
    int count = 0;

    for(int i=0; i<length; i++){
        printf("%d ",k[i]);
    }

    printf("\n� ���� �����ұ��? : ");
    scanf("%d",&what);

    for(int i=0; i<length-1; i++){
        if( k[i] == what){
            count = count + 1;
        }
    }
    if(count == 0){
        printf("�Է��Ͻ� %d�� �迭�� �����ϴ�.\n",what);
        return 0;
    }
    for(int i=0; i<length-1; i++){
        if( k[i] == what){
            printf("%d��°�� �ִ� %d�� �����մϴ�!\n",i+1,what);
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

    printf("\n�迭�� ������ ������ �����ϴ�.\n");
    for(int i=0; i<length; i++){
        printf("%d ",k[i]);
    }

    return 0;

}

void insert_ung(int *k,int length){
    int where,what;
    int temp1,temp2;

    printf("\n�迭�� ������ ������ �����ϴ�.\n");
    for(int i=0; i<length; i++){
        printf("%d ",k[i]);
    }
    printf("\n������ ���ڸ� �Է����ּ���.\n");
    printf("���� : ");
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

    printf("\n�迭�� ������ ������ �����ϴ�.\n");
    for(int i=0; i<length; i++){
        printf("%d ",k[i]);
    }
    return 0;

}

void print_ung(int *k,int length){
    printf("\n�迭�� ������ ������ �����ϴ�.\n");
    for(int i=0; i<length; i++){
        printf("%d ",k[i]);
    }
}

int main(void){
    int k[10] = {1,3,5,7,9,11};
    int user;
    int length = sizeof(k)/sizeof(int);

    while(1){
        printf("\n1.���� 2.���� 3.��� : ");
        scanf("%d",&user);
        switch(user){
            case 1:{
                printf("�Է��Ͻ� ���� ã�� �װ��� ���� �����մϴ�.\n");
                delete_ung(k,length);
                break;
            }

            case 2:{
                printf("�Է��Ͻ� ���� ���ϴ� ��ġ�� ���� �� �о���մϴ�.\n");
                insert_ung(k,length);
                break;
            }

            case 3:{
                printf("���� �迭�� ����մϴ�.\n");
                print_ung(k,length);
                break;
            }

            default :{
                printf("�߸��� �Է����� �����մϴ�!\n");
                break;
            }

        }
    }

}
