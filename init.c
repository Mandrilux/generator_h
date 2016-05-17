/*
1;2802;0c** init.c for h in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 11:03:55 2016
** Last update Tue May 17 18:08:49 2016 
*/

#include "gen.h"

t_core		*init_core(char *name, char *h)
{
  t_core	*tmp;

  if ((tmp = malloc(sizeof(t_core) * 1)) == NULL)
    return (NULL);
  tmp->name_h = h;
  tmp->name_prog = name;
  tmp->re_write = NULL;
  tmp->header = NULL;
  return (tmp);
}

int             add_last(t_header **header, int fd)
{
  t_header     *tmp;
  t_header     *new_maillon;
  char		*line_read;

  tmp = NULL;
  if ((new_maillon = malloc(sizeof(t_header))) == NULL)
    return (-1);
  new_maillon->line = NULL;
  while ((line_read = get_next_line(fd)) != NULL)
    {
      printf("%s\n",line_read);
      line_read = rostring(line_read);
      new_maillon->line = alloc(new_maillon->line, line_read);
      free(line_read);
    }
  close(fd);
  if (*header == NULL)
    *header = new_maillon;
  else
    {
      tmp = *header;
      while (tmp->nxt != NULL)
	tmp = tmp->nxt;
      tmp->nxt = new_maillon;
    }
  return (1);
}
