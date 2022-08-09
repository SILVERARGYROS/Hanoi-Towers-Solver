#include <stdio.h>
#include <stdlib.h>

typedef struct STACK{
    int number;
    struct STACK* next;
}stack;

stack* towerInit(int max, stack** tower);
void push(stack* head, int value);
int pop(stack* head);
int top(stack* head); //unused
void moveLayer(stack** tower1, stack** tower2);
void Hanoi(int n, stack** from, stack** to, stack** spare);

int main (void)
{
    int i;

    //clears terminal
    system("clear"); 

    
    //get towers height
    int height;
    printf("Please enter tower's height: ");
    scanf("%d", &height);


    //initialize towers (stacks)
    stack* tower1;
    stack* tower2;
    stack* tower3;
    tower1 = towerInit(height, &tower1);
    


    //debugging/testing
    /* for(i = 0; i < t2->top; i++)
    {
        printf("debug t2 [%d] == %d\n", i, t2->array[i]);
    } */


    //solve towers
    Hanoi(height, &tower1, &tower2, &tower3);

    printf("all good so far\n");
    return 0;
}

stack* towerInit(int max, stack** tower)
{
    int i;
    
    stack* temp = *tower;
    temp = (stack*) malloc(sizeof(stack));
    temp->number = 1;
    for(i = 2; i <= max; i++)
    {
        temp->next = (stack*) malloc(sizeof(stack));
        temp = temp->next;
        temp->number = i;
    }
    
    return *tower;
}

void push(stack* head, int value)
{
    stack* temp = (stack*) malloc(sizeof(stack));
    temp->number = value;
    temp->next = head;
    head = temp;
}

int pop(stack* head)
{
    int value;
    stack* temp = head;
    head = head->next;

    value = temp->number;
    free(temp);
    return value;
}

int top(stack* head)
{
    return head->number;
}

void moveLayer(stack** tower1, stack** tower2)
{
    push(tower1, pop(tower2));
}

void Hanoi(int n, stack** from, stack** to, stack** spare)
{
    if (n == 0) 
    {
        return; 
    } 
    Hanoi(n-1, from, spare, to); 
    // cout << "Move disk " << n << " from rod " << from_rod <<
    //                             " to rod " << to_rod << endl; 
    // printf("moving disk %d from ")
    moveLayer(from, to);
    Hanoi(n-1, spare, to, from); 
}