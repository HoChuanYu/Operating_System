#include <stdio.h>
#include <string.h>

long addition (int input1, int input2);
long substraction (int input1, int input2);
long multiplication (int input1, int input2);

// StudentID = 12345 // replace with your student ID without leading 0

int main() {
    char operator;
    char *operation;

    int input1=0;
    int input2=0;
    long result = 0;

    while(1)
    {
        input1=0;
        input2=0;
        result = 0;
        
        printf("=======================\n");
        printf("Enter operation [sum - sub - mul - exit]: ");
        scanf("%s",operation);

        if(strcmp(operation,"exit")==0){
            break;
        }

        printf("Enter two operands (space separated): ");
        scanf("%d %d", &input1, &input2);

        if(strcmp(operation,"sum")==0){
            result = addition (input1, input2);
            printf("Operation: [%s] - Operands [%d %d] - Result:[%ld]\n",operation, input1, input2, result);
        }else if(strcmp(operation,"sub")==0){
            result = substraction (input1, input2);
            printf("Operation: [%s] - Operands [%d %d] - Result:[%ld]\n",operation, input1, input2, result);
        }else if(strcmp(operation,"mul")==0){
            result = multiplication (input1, input2);
            printf("Operation: [%s] - Operands [%d %d] - Result:[%ld]\n",operation, input1, input2, result);
        }else{
            printf("Invalid option\n");
        }
    }

    return 0;
}

long addition (int input1, int input2)
{
    long result = 0;

    //INSERT YOUR CODE HERE TO LOAD/UNLOAD AND USE KERNEL MODULE
    // The variable 'result' should get its value from inside the kernel module

    return result;
}

long substraction (int input1, int input2)
{
    long result = 0;

    //INSERT YOUR CODE HERE TO LOAD/UNLOAD AND USE KERNEL MODULE
    // The variable 'result' should get its value from inside the kernel module

    return result;
}

long multiplication (int input1, int input2)
{
    long result = 0;

    //INSERT YOUR CODE HERE TO LOAD/UNLOAD AND USE KERNEL MODULE
    // The variable 'result' should get its value from inside the kernel module

    return result;
}
