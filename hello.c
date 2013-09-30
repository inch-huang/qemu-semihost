#include <stdio.h>
#include <stdlib.h>

#define FILE_NAME "/etc/hosts"
#define DATA_BUF_SIZ 512

int main(void)
{
	FILE *fd;
	unsigned char Data_Buf[DATA_BUF_SIZ];

	fd = fopen(FILE_NAME, "r");
	if(fd==NULL){
		printf("Wrong file name or path\r\n");	
		return 0;	
	}
	fread(&Data_Buf,sizeof(Data_Buf),1,fd);
	printf("\r\nread from %s:\r\n%s",FILE_NAME, Data_Buf);	
	fclose(fd);
	return 0 ;
}
