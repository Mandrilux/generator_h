/*
** read.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:19:53 2016
** Last update Mon May 16 12:54:00 2016 
*/

#include "gen.h"

int     read_file(char *file)
{
  int   fd;
  char	*str;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  while ((str = get_next_line(fd)) != NULL)
    {
      if (check_is_proto(str) != -1)
	printf("%s\n", str);
    }
  return (1);
}
