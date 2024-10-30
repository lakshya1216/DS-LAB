#include<stdio.h>
#define MAX 5

void insert(int q[],int *rear,int *front , int value){
    if(*front == *rear +1 || *rear==MAX-1){
        printf("Queue Overflow\n");
    }
    else{
        *rear = (*rear+1)%MAX;
        q[*rear]=value;
    }
}
int delete(int q[],int *front,int *rear){
    if(*front ==-1){
        printf("Queue Underflow\n");
        return 0;
    }
    else{
        int temp = q[*front];
        *front = (*front+1)%MAX;
        return temp;
    }
}
int display(int q[],int *front, int *rear){
    if(*front == -1){
        printf("Queue is empty\n");
    }
    for(int i=*front;i<=*rear;i++){
        printf("%d \n",q[i]);
    }
}
int main(){
    int q[MAX],front=-1,rear=-1,item,choice,del_item;
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while(1){
        
        printf("Enter Your choice\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d",&item);
            insert(q,&rear,&front,item);
            break;
            case 2:
            del_item=delete(q,&front,&rear);
            if(del_item!=-1){
                printf("Deleted item is %d\n",del_item);
                break;
            }
            
            case 3:
            display(q,&front,&rear);
            break;
            case 4:
            printf("Exit\n");
            return 0;
            break;
            default:
            printf("Invalid choice\n");
            break;
        }
    }
}