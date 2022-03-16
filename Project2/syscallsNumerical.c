//STUDENT ID: 0710012
#include <stdio.h>
#include <unistd.h>
#include <sys/syscall.h>
int main()
{
	int studentId = 710012;
	int r_1=2, r_2=30, a_1=10, a_2=35, m_1=11, m_2=35;
	//scanf("%d %d %d %d %d %d", &r_1,&r_2,&a_1,&a_2,&m_1,&m_2);
	printf("helloworld : %ld\n", syscall(548));
	printf("echo : %ld\n", syscall(549, studentId));
	printf("returnIndividualValues : %ld\n", syscall(550, studentId, r_1, r_2));
	printf("addition : %ld\n", syscall(551, studentId, a_1, a_2));
	printf("multiplication : %ld\n", syscall(552, studentId, m_1, m_2));
	printf("dataTypes : %ld\n", syscall(553, studentId));
	//perror("");
	return 0;
}
