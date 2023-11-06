#include<stdio.h>
#include<stdlib.h>

int arr[20];
int n,val,i,pos;

void create();
void display();
void insert();
void delete();



int  main()
{
    int choice;
    while (1)
    {
        printf("\n\n---MENU---\n");
        printf("1.CREATE\n");
        printf("2.DISPLAY\n");
        printf("3.INSERT\n");
        printf("4.DELETE\n");
        printf("5.EXIT\n");
        printf("");
        printf("\nENTER YOUR CHOICE:\t");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: create();
            break;
            case 2: display();
            break;
            case 3: insert();
            break;
            case 4: delete();
            break;
            case 5: exit(0);
            default:
            printf("\nINVALID CHOICE\n");
            break;
        }
    }
    return 0;    
}

void create()
{
    printf("\nEnter the size of the array elements:\t");
    scanf("%d",&n);
    printf("Enter the elements for the array :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }   
}

void insert(){
    printf("Enter the location where to enter the element:");
    scanf("%d",&pos);
    if (pos>=n){
        printf("Insertion not possible\n");
    }
    else{
        printf("Enter the element:");
        scanf("%d",&val);
        for (int i=n-1;i>=pos;i--){
            arr[i+1]=arr[i];
        }
        arr[pos]=val;
        n+=1;
    }
}

void display()
{
    if(n==0){
        printf("Array is empty");
    }
    else{
        for (int i=0;i<n;i++){
            printf("%d\n",arr[i]);
        }
    }
}

void delete(){
    if(n==0){
        printf("Array is empty");
        exit(0);
    }
    printf("Enter the location where to delete the element:");
    scanf("%d",&pos);
    if (pos>=n){
        printf("Deletion not possible");
    }
    else{
        for (int i=pos;i<n;i++){
            arr[i]=arr[i+1];
        }
        n-=1;
    }

}