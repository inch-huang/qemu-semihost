#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATA_BUF_SIZ 200

int main(void)
{
	FILE *fd;
	unsigned char Data_Buf[DATA_BUF_SIZ];
	char str_write[30] = "Here is HW2_b for Lab20.\r\n";

	//Get current folder path 
	system("pwd -P>dir");
	//Write into specific file
	fd = fopen("dir", "w");
	if(fd==NULL){
		printf("Wrong file name or path\r\n");	
		return 0;	
	}
	printf("The string is going to write into file is :\r\n%s",str_write);
	fprintf(fd,"%s",&str_write);
	fclose(fd);
	//Read out the file to verify
	fd = fopen("dir", "r");
	if(fd==NULL){
		printf("Wrong file name or path\r\n");	
		return 0;	
	}	
	fread(Data_Buf,sizeof(Data_Buf),1,fd);
	printf("The string read from file is :\r\n%s",Data_Buf);	
	fclose(fd);
	return 0 ;
}
