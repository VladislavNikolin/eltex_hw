//Прямой и обратный вывод из файла
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <malloc.h>
#include <errno.h>
#include <stdlib.h>

void printFile(int fd)
{
  int size;
  int error;
  char *buff;

  size = lseek(fd, 0, SEEK_END);
  if (size < 0)
  {
    perror("Size error");
    exit(EXIT_FAILURE);
  }

  error = lseek(fd, 0, SEEK_SET);
  if (error < 0)
  {
    perror("Set error");
    exit(EXIT_FAILURE);
  }

  buff = malloc(sizeof(*buff) * size);
  error = read(fd, buff, size);
  if (error < 0)
  {
    perror("Read error");
    exit(EXIT_FAILURE);
  }

  printf("%s\n", buff);

  free(buff);
}

void backPrint(int fd)
{
  char symbol;
  int error;
  int position = lseek(fd, 0, SEEK_END);

  for (int i = position - 1; i >= 0; i--)
  {
    error = lseek(fd, i, SEEK_SET);
    if (error < 0)
    {
      perror("Set error");
      exit(EXIT_FAILURE);
    }

    error = read(fd, &symbol, 1);
    if (error < 0)
    {
      perror("Read error");
      exit(EXIT_FAILURE);
    }

    printf("%c", symbol);
  }
  printf("\n");
}

int main(int argc, char **argv)
{
  char *fileName = "test.txt";
  char *message = "Hello world!!!";

  int error;
  int fd;

  fd = open(fileName, O_CREAT | O_RDWR, S_IREAD | S_IWRITE);
  if (fd < 0)
  {
    perror("File error");
    exit(EXIT_FAILURE);
  }

  error = write(fd, message, strlen(message) + 1);
  if (error < 0)
  {
    perror("Write error");
    exit(EXIT_FAILURE);
  }

  printFile(fd);
  backPrint(fd);

  close(fd);
}