#include <stdio.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define init_module(module_image, len, param_values) syscall(__NR_init_module, module_image, len, param_values)
#define finit_module(fd, param_values, flags) syscall(__NR_finit_module, fd, param_values, flags)
#define delete_module(name, flags) syscall(__NR_delete_module, name, flags)

long addition (int input1, int input2);
long substraction (int input1, int input2);
long multiplication (int input1, int input2);
char* itoa(int, char* , int);

// StudentID = 710012 // replace with your student ID without leading 0

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

    const char *moduleName = "calculatorModule.ko";
	const char *moduleNameNoExtension = "calculatorModule";
	char n1[100];
	char n2[100];
	//itoa(input1,n1,10);
	//itoa(input2,n2,10);
	sprintf(n1, "%d", input1);
	sprintf(n2, "%d", input2);
	char first[100]="firstParam=";
	strcat(first,n1);
	strcat(first, " secondParam=");
	strcat(first, n2);
	strcat(first, " operationParam=\"sum\"");
	const char *paramsNew = first;
	int fd, use_finit;
	size_t image_size;
	struct stat st;
	void *image;
//Section - Module loading - BEGIN
	fd = open(moduleName, O_RDONLY);
	fstat(fd, &st);
	image_size = st.st_size;
	image = malloc(image_size);
	read(fd, image, image_size);
	if (result=init_module(image, image_size, paramsNew) != 0) {
		perror("init_module");
		return EXIT_FAILURE;
	}
//Section - Module loading - END

	
	FILE *fp = fopen("/sys/module/calculatorModule/parameters/resultParam","r");
	fscanf(fp,"%ld",&result);
	fclose(fp);
	
//Section - Module unloading - BEGIN	
	if (delete_module(moduleNameNoExtension, O_NONBLOCK) != 0) {
		perror("delete_module");
		return EXIT_FAILURE;
	}
	close(fd);
	free(image);
//Section - Module unloading - END
	
    return result;
}

long substraction (int input1, int input2)
{
	long result=0;

	const char *moduleName = "calculatorModule.ko";
	const char *moduleNameNoExtension = "calculatorModule";
        char n1[100];
        char n2[100];
        //itoa(input1,n1,10);
        //itoa(input2,n2,10);
        sprintf(n1, "%d", input1);
        sprintf(n2, "%d", input2);
        char first[100]="firstParam=";
        strcat(first,n1);
        strcat(first, " secondParam=");
        strcat(first, n2);
        strcat(first, " operationParam=\"sub\"");
        const char *paramsNew = first;
        int fd, use_finit;
        size_t image_size;
        struct stat st;
        void *image;
//Section - Module loading - BEGIN
        fd = open(moduleName, O_RDONLY);
        fstat(fd, &st);
        image_size = st.st_size;
        image = malloc(image_size);
        read(fd, image, image_size);
        if (result=init_module(image, image_size, paramsNew) != 0) {
                perror("init_module");
                return EXIT_FAILURE;
        }
//Section - Module loading - END


        FILE *fp = fopen("/sys/module/calculatorModule/parameters/resultParam","r");
        fscanf(fp,"%ld",&result);
        fclose(fp);

//Section - Module unloading - BEGIN	
	if (delete_module(moduleNameNoExtension, O_NONBLOCK) != 0) {
		perror("delete_module");
		return EXIT_FAILURE;
	}
	close(fd);
	free(image);
//Section - Module unloading - END
	
    return result;
}

long multiplication (int input1, int input2)
{
    long result = 0;

	const char *moduleName = "calculatorModule.ko";
    	const char *moduleNameNoExtension = "calculatorModule";
        char n1[100];
        char n2[100];
        //itoa(input1,n1,10);
        //itoa(input2,n2,10);
        sprintf(n1, "%d", input1);
        sprintf(n2, "%d", input2);
        char first[100]="firstParam=";
        strcat(first,n1);
        strcat(first, " secondParam=");
        strcat(first, n2);
        strcat(first, " operationParam=\"mul\"");
        const char *paramsNew = first;
        int fd, use_finit;
        size_t image_size;
        struct stat st;
        void *image;
//Section - Module loading - BEGIN
        fd = open(moduleName, O_RDONLY);
        fstat(fd, &st);
        image_size = st.st_size;
        image = malloc(image_size);
        read(fd, image, image_size);
        if (result=init_module(image, image_size, paramsNew) != 0) {
                perror("init_module");
                return EXIT_FAILURE;
        }
//Section - Module loading - END


        FILE *fp = fopen("/sys/module/calculatorModule/parameters/resultParam","r");
        fscanf(fp,"%ld",&result);
        fclose(fp);

//Section - Module loading - END

//Section - Module unloading - BEGIN
	if (delete_module(moduleNameNoExtension, O_NONBLOCK) != 0) {
		perror("delete_module");
		return EXIT_FAILURE;
	}
	close(fd);
	free(image);
	
    return result;
}
