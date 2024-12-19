#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>


int main(){
	int fd = open("sample1.txt",O_CREAT | O_WRONLY,0777);
	if(fd>0){
	printf("file opened successfully\n");
	char to_write[] = "Hello My name is Pranjal";
	
	write(fd,to_write,sizeof(to_write));
	printf("writting completed\n");
	close(fd);
	
	printf("Opening file for reading\n");
	fd = open("sample1.txt",O_RDONLY);
	char buffer[1000];
	read(fd,buffer,sizeof(buffer));
	
	printf("Data readed from file is %s\n",buffer);
	close(fd);
	
	printf("appending data to file\n");
	char data[1000];
	printf("what data do you want to append: ");
	fgets(data,sizeof(data),stdin);
	fd = open("sample1.txt",O_APPEND | O_CREAT | O_WRONLY);
	write(fd,data,sizeof(data)/sizeof(data[0]));
	close(fd);

	
	printf("copying data of one file to other file:\n");
	int fd2 = open("samplefile2.txt",O_CREAT | O_WRONLY | O_TRUNC,0777);
	fd = open("samplefile1.txt",O_RDONLY);	
	char buffer2[1000];
	ssize_t r;
	while((r=read(fd,buffer2,sizeof(buffer2)))>0){
		printf("%s\n",buffer2);
		write(fd2,buffer2,r);

	}
	close(fd);
	close(fd2);
		
	}

}
