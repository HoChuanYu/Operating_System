//STUDENT ID: 0710012

#include <linux/syscalls.h>
#include <linux/kernel.h>

/* Insert your code in this file. You must create 4 system calls:
*   1. syscalltest_returnIndividualValues:
*       - Input: integers studentId, a and b.
*       - Output: 0;
*       - Action: Display in kernel ring buffer the message "[studentId] syscalltest_returnIndividualValues : a, b
*       - Example: if studentId = 12345, a=2 and b=30, then the message "[12345] syscalltest_returnIndividualValues : 2, 30" is display in kernel ring buffer.
            
*   2. syscalltest_addition:
*       - Input: integers studentId, a and b.
*       - Output: a+b;
*       - Action: Display in kernel ring buffer the message "[studentId] syscalltest_addition : a, b, a+b
*       - Example: if studentId = 12345, a=10 and b=35, then the message "[12345] syscalltest_addition : 10, 35, 45" is display in kernel ring buffer.
            
*   3. syscalltest_multiplication:
*       - Input: integers studentId, a and b.
*       - Output: a*b;
*       - Action: Display in kernel ring buffer the message "[studentId] syscalltest_multiplication : a, b, a*b
*       - Example: if studentId = 12345, a=11 and b=35, then the message "[12345] syscalltest_multiplication : 11, 35, 385" is display in kernel ring buffer.
* 
*   4. syscalltest_dataTypes:
*       - Input: integer studentId.
*       - Output: 0;
*       - Action: Display the size in bits of the following datatypes: 
            a. unsigned int
            b. signed int
            c. unsigned long
            d. signed long
            e. unsigned long long
            f. signed long long
            g. double
            h. char
*       - Example: if studentId = 12345, then the message "[12345] Size of unsigned int : 4 bytes" is display in kernel ring buffer. (Do this for all the datatypes)
*       - NOTE: You cannot hard-type "4 bytes" or "8 bytes". You need to find out how to measure the size of the datatypes.
*/

//INSERT YOUR CODE BELOW
SYSCALL_DEFINE0(syscalltest_helloworld)
{
	printk("Hello world from a system call! OS_Project02!\n");
	return 0;
}

SYSCALL_DEFINE1(syscalltest_echo, int, studentId)
{
	printk("My student id is : [%d]\n", studentId);
	return 0;
}
SYSCALL_DEFINE3(syscalltest_returnIndividualValues, int, studentId, int, r_1, int, r_2)
{
	printk("[%d] syscalltest_returnIndividualValues : %d, %d\n", studentId, r_1, r_2);
	return 0;
}
SYSCALL_DEFINE3(syscalltest_addition, int, studentId, int, a_1, int, a_2)
{
	int a = a_1+a_2;
	printk("[%d] syscalltest_addition : %d, %d, %d\n", studentId, a_1, a_2, a);
	return a;
}
SYSCALL_DEFINE3(syscalltest_multiplication, int, studentId, int, m_1, int, m_2)
{
	int m = m_1*m_2;
	printk("[%d] syscalltest_multiplication : %d, %d, %d\n", studentId, m_1, m_2, m);
	return m;
}
SYSCALL_DEFINE1(syscalltest_dataTypes, int, studentId )
{
	printk("[%d] Size of unsigned int : %d bytes.\n[%d] Size of signed int : %d bytes.\n[%d] Size of unsigned long : %d bytes.\n[%d] Size of signed long : %d bytes.\n[%d] Size of unsigned long long : %d bytes.\n[%d] Size of signed long long : %d bytes.\n[%d] Size of double : %d bytes.\n[%d] Size of char : %d bytes.\n", studentId,sizeof(unsigned int),studentId,sizeof(int),studentId,sizeof(unsigned long int),studentId,sizeof(long int),studentId,sizeof(unsigned long long int),studentId,sizeof(long long int),studentId,sizeof(double),studentId,sizeof(char));
	return 0;
}
