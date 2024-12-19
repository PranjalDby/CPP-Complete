#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main(){
	
	const char *filename = "sample1.txt";
	struct stat st;
	
	stat(filename,&st);
	printf("file name = %s" ,filename);
	printf("file size = %lld",st.st_size);

}
