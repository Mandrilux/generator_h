/*
** str.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 13:11:00 2016
** Last update Tue May 17 10:47:44 2016 
*/

#include "gen.h"

char	*format_str(char *str)
{
  char	*tmp;
  char	**cut;
  int	i = -1, len_tmp = 0, nb_elm, len;

  len  = strlen(str);
  if ((tmp = malloc(sizeof(char) * (len + 4))) == NULL)
    return (NULL);
  memset(tmp, '\0', len + 4);
  if ((cut = strtowordtab(str, '(')) == NULL)
    return (NULL);
  if ((cut = strtowordtab(cut[0], ' ')) == NULL)
    return (NULL);
  nb_elm = count_tab(cut);
  while (++i < nb_elm)
    {
      if (i + 1 != nb_elm)
	  len_tmp += strlen(cut[i]) + 1;
    }
  len_tmp -= 1;
  strncat(tmp, str, len_tmp);
  strcat(tmp, "\t\t");
  strcat(tmp, &(str[len_tmp]));
  strcat(tmp, ";");
  free(str);
  return (tmp);
}

char	*get_name_file(char *name)
{
  char	*tmp;
  int	len;

  len = strlen(name);
  if ((tmp = malloc(sizeof(char) * (len + 10))) == NULL)
    return (NULL);
  memset(tmp, '\0', len + 10);
  strcat(tmp, "\t\t");
  strcat(tmp, "/* ");
  strcat(tmp, name);
  strcat(tmp, " */");
  return (tmp);
}

int     alloc(t_core *core, char *name)
{
  int   i;
  char  **tmp;

  i = -1;
  if (core->re_write == NULL)
    {
      if ((core->re_write = malloc(sizeof(char *) * 2)) == NULL)
	return (-1);
      core->re_write[0] = strdup(name);
      core->re_write[1] = NULL;
    }
  else
    {
      if ((tmp = malloc(sizeof(char *) *
			(count_tab(core->re_write) + 2))) == NULL)
	return (-1);
      while (core->re_write[++i] != NULL)
	tmp[i] = core->re_write[i];
      tmp[i] = strdup(name);
      tmp[i + 1] = NULL;
      core->re_write = tmp;
    }
  return (1);
}

char	*add_include(char *str)
{
  char	*tmp;

  if (strstr(str, "include") != NULL)
    return (str);
  if ((tmp = malloc(sizeof(char) * (strlen(str) + strlen("include/") + 1))) == NULL)
    return (NULL);
  memset(tmp, '\0', strlen(str) + strlen("include/") + 1);
  strcat(tmp, "include/");
  strcat(tmp, str);
  return (tmp);
}
