#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<string.h>

int main(int argc , char** argv){
	
	char* parametre = argv[1];

	int fd = open(parametre,O_RDONLY);

	if(fd < 0){perror("hata"); return -1;}

	char* katar = malloc(sizeof(char)*1000);

	while(read(fd,katar,1000)){
		printf("%s",katar);
		free(katar);
		katar = malloc(sizeof(char)*1000);
	}

	printf("\n\n------OKUMA TAMAMLANDİ------\n");

	free(katar);

return 0;
}
