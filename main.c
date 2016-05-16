/*
1;2802;0c1;2802;0c** main.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Mon May 16 10:48:51 2016
** Last update Mon May 16 11:18:43 2016 
*/

#include "gen.h"

int		main(int ac, char **av)
{
  DIR		*rep;
  t_core	*core;
  (void) ac;
  if ((core = init_core(av[0])) == NULL)
    return (printf("RAM was attacked !\n"));
  if (directory_open(core, &rep) == -1)
    return (EXIT_FAILURE);
  display_directory(&rep);
  return (1);
}

int		directory_open(t_core *core, DIR **rep)
{
  *rep = opendir(".");
  if (*rep == NULL)
    {
      perror(core->name_prog);
      return (-1);
    }
  else
    return (1);
}

int    display_directory(DIR **rep)
{
  struct dirent *ent;

  if (*rep != NULL)
    {
      while ((ent = readdir(*rep)) != NULL)
	{
	  if (strlen(ent->d_name) > 2)
	    {
	      if (strcmp(&(ent->d_name[strlen(ent->d_name) - 2]), TYPE_F) == 0)
		printf("%s\n", ent->d_name);
	    }
	}
      closedir(*rep);
    }
  return (1);
}
