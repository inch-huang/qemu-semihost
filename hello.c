#include <stdio.h>
#include <stdlib.h>

#define RW_FILE_NAME "/home/inch-huang/hw2_b.txt"
#define DATA_BUF_SIZ 200

int main(void)
{
	FILE *fd;
	unsigned char Data_Buf[DATA_BUF_SIZ];
	char str_write[30] = "Here is HW2_b for Lab20.\r\n";
	//Write into specific file
	fd = fopen(RW_FILE_NAME, "w");
	if(fd==NULL){
		printf("Wrong file name or path\r\n");	
		return 0;	
	}
	printf("The string is going to write into %s is :\r\n%s",RW_FILE_NAME,str_write);
	fprintf(fd,"%s",&str_write);
	fclose(fd);
	//Read out the file to verify
	fd = fopen(RW_FILE_NAME, "r");
	if(fd==NULL){
		printf("Wrong file name or path\r\n");	
		return 0;	
	}	
	fread(Data_Buf,sizeof(Data_Buf),1,fd);
	printf("The string read from %s is :\r\n%s",RW_FILE_NAME,Data_Buf);	
	fclose(fd);
	return 0 ;
}
