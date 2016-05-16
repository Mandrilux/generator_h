/*
** read.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:19:53 2016
** Last update Mon May 16 14:49:59 2016 
*/

#include "gen.h"

int     read_file(char *file)
{
  int   fd;
  char	*str;
  char	*tmp;
  char	*file_ok;

  if ((file_ok =  get_name_file(file)) == NULL)
    return (-1);
  printf("%s\n\n", file_ok);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  while ((str = get_next_line(fd)) != NULL)
    {
      tmp = rostring(str);
      free(str);
      if (check_is_proto(tmp) != -1)
	{
	  tmp = format_str(tmp);
	  printf("%s\n", tmp);
	}
    }
  printf("\n");
  return (1);
}

int	read_h(char *file)
{
  int	fd;
  char	*str, *tmp;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  while ((str = get_next_line(fd)) != NULL)
    {
      tmp = rostring(str);
      if (check_is_proto(tmp) == -1)
	{
	  printf("on garde\n");
	}
    }
  printf("\n");
  return (1);

}
