#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>

struct node{
    int cf,px,py,pz;
    int flag;
    struct node * link;
};

typedef struct node NODE;

NODE * getnode(){
    NODE * x;
    x = (NODE*)malloc(sizeof(NODE));
    if(x==NULL){
        printf("\nInsufficient memory");
        exit(0);
    }
    return x;
}

void display(NODE *head){
    NODE *temp;
    if(head->link==NULL){
        printf("\nPolynomial does not exist");
        return;
    }
    temp = head->link;
    printf("\n");
    while(temp!=head){
        printf("%d x^%d y^%d z^%d",temp->cf,temp->px,temp->py,temp->pz);
        if(temp->link!=head){
            printf(" + ");
        }
        temp = temp->link;
    }
    printf("\n");
}

NODE * insert_rear(int cf,int x,int y,int z,NODE * head){
    NODE * temp,*cur;
    temp = getnode();
    temp->cf = cf;
    temp->px = x;
    temp->py = y;
    temp->pz = z;
    cur = head->link;
    while(cur->link!=head){
        cur = cur->link;
    }
    cur->link = temp;
    temp->link = head;
    return head;
}

NODE * read_poly(NODE * head){
    int px,py,pz,cf,ch;
    printf("\nEnter coeff: ");
    scanf("%d",&cf);
    printf("\nEnter x, y, z powers(0-indiacate NO term): ");
    scanf("%d%d%d", &px, &py, &pz);
    head=insert_rear(cf,px,py,pz,head);
    printf("\nIf you wish to continue press 1 otherwise 0: ");
    scanf("%d", &ch);
    while(ch != 0)
    {
        printf("\nEnter coeff: ");
        scanf("%d",&cf);
        printf("\nEnter x, y, z powers(0-indiacate NO term): ");
        scanf("%d%d%d", &px, &py, &pz);
        head=insert_rear(cf,px,py,pz,head);
        printf("\nIf you wish to continue press 1 otherwise 0: ");
        scanf("%d", &ch);
    }
    return head;
}

void evaluate(NODE * head){
    NODE * p;
    p = head->link;
    float x,y,z,result = 0;
    printf("\nEnter x,y,z terms to evaluate : ");
    scanf("%f %f %f",&x,&y,&z);
    while(p!=head){
        result = result + (p->cf)*pow(x,p->px)*pow(y,p->py)*pow(z,p->pz);
        p = p->link;
    }
    printf("\nThe result of the polynomial is %f\n",result);
}

NODE * add(NODE * h1,NODE * h2,NODE * h3){
    NODE * p1,*p2;
    p1 = h1->link;
    while(p1!=h1){
        p2=h2->link;
        while(p2!=h2){
            if(p1->px==p2->px&&p1->py==p2->py&&p1->pz==p2->pz){
                h3=insert_rear(p1->cf+p2->cf,p1->px,p1->py,p1->pz,h3);
                p2->flag=1;
                break;
            }
            p2=p2->link;
        }
        if(p2==h2)
            h3=insert_rear(p1->cf,p1->px,p1->py,p1->pz,h3);
        p1=p1->link;
    }
    p2=h2->link;
    while(p2!=h2){
        if(p2->flag!=1)
            h3=insert_rear(p2->cf,p2->px,p2->py,p2->pz,h3);
        p2=p2->link;
    }
    return h3;
}

void main()
{
    NODE *h1,*h2,*h3;
    int ch;
    h1=getnode();
    h2=getnode();
    h3=getnode();
    h1->link=h1;
    h2->link=h2;
    h3->link=h3;
    while(1){
        printf("\n\n1.Evaluate polynomial\n2.Add two polynomials\n3.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter polynomial to evaluate:\n");
                h1=read_poly(h1);
                display(h1);
                evaluate(h1);
                break;
            case 2:
                printf("\nEnter the first polynomial:");
                h1=read_poly(h1);
                printf("\nEnter the second polynomial:");
                h2=read_poly(h2);
                h3=add(h1,h2,h3);
                printf("\nFirst polynomial is: ");
                display(h1);
                printf("\nSecond polynomial is: ");
                display(h2);
                printf("\nThe sum of 2 polynomials is: ");
                display(h3);
                break;
            case 3:
                exit(0); 
                break;
            default:
                printf("\nInvalid entry");
                break;
        }
    }
}