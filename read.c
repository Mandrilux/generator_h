/*
1;2802;0c1;2802;0c1;2802;0c1;2802;0c1;2802;0c1;2802;0c1;2802;0c** read.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:19:53 2016
** Last update Tue May 17 18:33:14 2016 
*/

#include "gen.h"

int     read_file(t_core *core, char *file)
{
  int   fd, fdh;
  char	*str;
  char	*tmp;
  char	*file_ok;

  if ((file_ok =  get_name_file(file)) == NULL)
    return (-1);
  if ((fdh = open(core->name_h, O_APPEND | O_WRONLY)) == -1)
    {
      perror(core->name_prog);
      exit (0);
    }
  write(fdh, file_ok, strlen(file_ok));
  write(fdh, "\n\n", strlen("\n\n"));
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  while ((str = get_next_line(fd)) != NULL)
    {
      tmp = rostring(str);
      free(str);
      if (check_is_proto(tmp) != -1)
	{
	  tmp = format_str(tmp);
	  if (is_exist_already(core, rostring(tmp)) != 1)
	    {
	      printf("%s\n", tmp);
	      write(fdh, tmp, strlen(tmp));
	      write(fdh, "\n", strlen("\n"));
	    }
	}
    }
  write(fdh, "\n", strlen("\n"));
  return (1);
}

int	read_h(t_core *core, char *file)
{
  int	fd;
  char	*str, *tmp;
  if ((fd = open(file, O_CREAT | O_RDONLY, 0777)) == -1)
    {
      perror(core->name_prog);
      return (-1);
    }
  while ((str = get_next_line(fd)) != NULL)
    {
      tmp = rostring(str);
      if (check_parenthesis(tmp) == 0)
	{
	  if (strstr(tmp, ".c */") == NULL)
	      core->re_write = alloc(core->re_write, tmp);
	}
      else if (strstr(tmp, "typedef") != NULL)
	core->re_write = alloc(core->re_write, tmp);
    }
  core->nb_write = last_line_ok(core->re_write);
  return (1);
}

void    display_tableau(char **tab)
{
  int   i;

  i = -1;
  if (tab != NULL)
    {
      while (tab[++i] != NULL)
	printf("%s\n", tab[i]);
    }
}
