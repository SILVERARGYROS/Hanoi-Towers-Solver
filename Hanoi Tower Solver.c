#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* array;
    int top;
}stack;

stack* towerInit(int max);
void push(stack* tower, int value);
int pop(stack* tower);
void move(stack* tower1, stack* tower2);
int top(stack* tower);
int Hanoi(int n, stack* t1, stack* t2, stack* t3);

int main (void)
{
    //clears terminal
    system("clear"); 

    
    //get towers height
    int height;
    printf("Please enter tower's height: ");
    scanf("%d", &height);

    //initialize towers (stacks)
    stack* t1 = towerInit(height);
    stack* t2 = towerInit(height);
    stack* t3 = towerInit(height);

    //solve towers
    // Hanoi(height, t1, t2, t3);

    printf("all good so far\n");
    return 0;
}

stack* towerInit(int max)
{
    stack* tower;
    tower = (stack*) malloc(sizeof(stack));
    tower->array = (int*) malloc (sizeof(int) * (max-1));
    tower->top = 0;
    
    return tower;
}

void push(stack* tower, int value)
{
    tower->top++;
    tower->array[tower->top] = value;
}

int pop(stack* tower)
{
    int value = tower->array[tower->top];
    tower->top--;
    return value;
}

void move(stack* tower1, stack* tower2)
{
    push(tower1, pop(tower2));
}

int top(stack* tower)
{
    return tower->array[tower->top];
}

int Hanoi(int n, stack* t1, stack* t2, stack* t3)
{
    
}