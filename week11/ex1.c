#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
	int fd = open("ex1.txt", O_RDWR);
	struct stat *s = malloc(sizeof(void*));
	fstat(fd, s);
	char *mem = mmap(NULL, s->st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	memcpy(mem, "This is a nice day ", strlen("This is a nice day "));
	munmap(mem, s->st_size);
    close(fd);
	return 0;
}
