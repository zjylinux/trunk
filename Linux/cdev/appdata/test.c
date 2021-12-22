#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define N 128

char buf[N] = {0};
int main (int argc, const char *argv[])
{
	int fd;
	fd = open("/dev/hello",O_RDWR);
	if (fd < 0)
	{
		perror("open error");
		return -1;
	}
	read(fd,buf,sizeof(buf));
	write(fd,buf,sizeof(buf));
	close(fd);
	
}
