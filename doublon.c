/*
** doublon.c for  in /home/baptiste/project/generator_h
**
** Made by
** Login   <baptiste@epitech.net>
**
** Started on  Tue May 17 15:06:18 2016
** Last update Tue May 17 17:24:31 2016 
*/

#include "gen.h"

int	init_all_h(t_core *core)
{
  DIR	*rep;

  if (open_include(core, &rep) == -1)
    return (EXIT_FAILURE);
  return (check_all_h(core, &rep));
}

int            open_include(t_core *core, DIR **rep)
{
  *rep = opendir("include");
  if (*rep == NULL)
    {
      perror(core->name_prog);
      return (-1);
    }
  else
    return (1);
}

int    check_all_h(t_core *core, DIR **rep)
{
  int	flag = 0;
  struct dirent *ent;
  char	*name;

  if (*rep != NULL)
    {
      while ((ent = readdir(*rep)) != NULL)
	{
	  if (strlen(ent->d_name) > 2)
	    {
	      if (strcmp(&(ent->d_name[strlen(ent->d_name) - 2]), TYPE_H) == 0)
		{
		  name = add_include(ent->d_name);
		  if (strcmp(name, core->name_h) != 0)
		    {
		      read_to_h(core, name);
		      printf("on open le .h %s\n", name);
		    }
		}
	    }
	}
      closedir(*rep);
    }
  return (flag);
}

int	read_to_h(t_core *core, char *name)
{
  int	fd;

  if ((fd = open(name, O_RDONLY)) == -1)
    {
      perror(name);
      exit (0);
    }
  add_last(&(core->header),  fd);
  /* while ((line_read = get_next_line(fd)) != NULL) */
  /*   { */
  /*     line_read = rostring(line_read); */

  /*     free(line_read); */
  /*   } */
  /* close(fd); */
  return (0);
}
