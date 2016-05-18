/*
** read.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Tue May 17 19:01:11 2016
** Last update Wed May 18 11:03:34 2016 
*/

#include "gen.h"

int     read_file(t_core *core, char *file)
{
  int   fd, fdh;
  char	*str;
  char	*tmp;
  char	*file_ok;
  char	**data = NULL;
  int	i = -1;

  if ((file_ok =  get_name_file(file)) == NULL)
    return (-1);
  if ((fdh = open(core->name_h, O_APPEND | O_WRONLY)) == -1)
    {
      perror(core->name_prog);
      exit (0);
    }
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
	      data = alloc(data, tmp);
	    }
	}
    }
  if (data != NULL)
    {
      write(fdh, file_ok, strlen(file_ok));
      write(fdh, "\n\n", strlen("\n\n"));
      while (data[++i] != NULL)
	{
	  write(fdh, data[i], strlen(data[i]));
	  write(fdh, "\n", strlen("\n"));
	}
      write(fdh, "\n", strlen("\n"));
      free_tab(data);
    }
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
	    core->re_write = alloc(core->re_write, str);
	}
      else if (strstr(tmp, "typedef") != NULL)
	core->re_write = alloc(core->re_write, str);
      else if (strstr(tmp, "strdup(") != NULL)
	core->re_write = alloc(core->re_write, str);
    }
  core->nb_write = last_line_ok(core->re_write);
  return (1);
}
