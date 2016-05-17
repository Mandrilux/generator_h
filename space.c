/*
1;2802;0c** space.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 10:53:42 2016
** Last update Tue May 17 19:50:08 2016 
*/

#include "gen.h"

char    *init_str_2(char *str)
{
  char  *str_2;

  if ((str_2 = malloc(sizeof(char) * (strlen(str) + 1))) == NULL)
    return (NULL);
  memset(str_2, 0, strlen(str) + 1);
  return (str_2);
}

char    *rostring(char *str)
{
  int   i;
  int   j;
  char  *str_2;

  str_2 = init_str_2(str);
  i = 0;
  j = 0;
  while ((str[i] == ' ' || str[i] == '\t') && str[i++] != '\0');
  while (str[i] != '\0')
    {
      if ((str[i] == '\t' || str[i] == ' ')
          && (str[i + 1] != '\t' && str[i + 1] != ' ')
	  && str[i + 1] != '\0')
	str_2[j++] = ' ';
      else if (str[i] != ' ' && str[i] != '\t')
	str_2[j++] = str[i];
      i++;
    }
  str_2[j] = '\0';
  return (str_2);
}

int	delete_line_empty(t_core *core)
{
  char	*file, *line_read;
  char	**contenue;
  int	i = -1, fd, len_tab;

  contenue = NULL;
  file = add_include(core->name_h);
  if ((fd = open(file, O_RDONLY)) == -1)
    return (-1);
  while ((line_read = get_next_line(fd)) != NULL)
    {
      line_read = rostring(line_read);
      contenue = alloc(contenue, line_read);
      free(line_read);
    }
  len_tab = count_tab(contenue);
  while (contenue[++i] != NULL)
    {
      if (strlen(contenue[i]) > 3 && strncmp(contenue[i], "/* ", 3) == 0)
	{
	  if (i + 2 <= len_tab)
	    {
	      if (is_empty_elm2(contenue[i + 1]) == 1 && is_empty_elm2(contenue[i + 2]) == 1)
		printf("%s [ligne %d]\n", contenue[i], i);
	    }
	}
    }
  close(fd);
  return (1);
}
