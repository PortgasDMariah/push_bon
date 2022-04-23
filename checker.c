#include "struct.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <fcntl.h>


int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
void    apply_mouv(t_data *tmp, t_data *tmp2, char *str)
{
    if(str[1] == 'a')
    {
        if (str[0] == 'r')
            ft_rotate(tmp, 1);
        else if (str[0] == 's')
            ft_swap(tmp);
        else if (str[0] == 'p')
            pa(tmp, tmp2);
    }
    else if(str[1] == 'b')
    {
         if (str[0] == 'r')
            ft_rotate(tmp2, 2);
        else if (str[0] == 's')
            ft_swap(tmp2);
        else if (str[0] == 'p')
            pb(tmp, tmp2, 1);
    }
    else if(str[0] == 'r' && str[1] == 'r')
    {
        if(str[2] == 'a')
            ft_rrotate(tmp, 1);
        else if (str[2] == 'b')
            ft_rrotate(tmp2, 2);
        else if(str[2] == 'r')
            rrr(tmp, tmp2);
        else  if(str[2] == '\n')
            doublerotate(tmp, tmp2);
    }
    //ss et voir si sb fonctionne
}


void    good_print(char *str, t_data *list, t_data *listb)
{
    if(!ft_strcmp(str,"ra\n") && !ft_strcmp(str,"rb\n") && !ft_strcmp(str,"rra\n") && !ft_strcmp(str,"rrb\n") 
    && !ft_strcmp(str,"sa\n") && !ft_strcmp(str,"sb\n") && !ft_strcmp(str,"pa\n") && !ft_strcmp(str,"pb\n") 
    && !ft_strcmp(str,"rrr\n") && !ft_strcmp(str,"rr\n") && !ft_strcmp(str,"ss\n"))
        printf("k.o \n");
    else
        apply_mouv(list, listb, str);
   // quit_well(list, 3); // il faut quitter avec erreur
}

void    printnode(t_node *start)
{
        t_node *temp;

        temp = start;
        while(temp)
        {
                printf("%ld \n", (long int)temp->data);
                temp = temp->next;
        }
}
void    org(char **av, int ac, t_data *list)
{
   if (ac <= 2)
		one_arg(list, av[1]);
	while (av[list->i] && ((ft_parsing(av[list->i], list) == 0)
			|| ft_parsing((av[list->i]), list)))
	{
		list->val = ft_parsing(av[list->i], list);
		list->j = (list->i) + 1;
		while (av[list->j])
		{
			if (list->val == ft_parsing((av[(list->j)++]), list))
				quit_well(list, 1);
		}
		create_stack_a(list, av[list->i], list->i);
		(list->i)++;
	}
    printf("magic ca \n");
     printnode(list->head);
    //exit(0);
}


int main(int ac, char **av)
{
    t_data stack_a;
    t_data stack_b;

    init(&stack_a, &stack_b);

   // (void)ac;
   // (void)av;
  ///  int fd;

   // fd = open("text", O_RDONLY);
 //   printf("%d \n", fd);
    char *line = "bonjour";

    org(av, ac, &stack_a);
    while(line != NULL)
    {
        line = get_next_line(0);
        if(line ==  NULL)
            break;
       // printf(" check = %s", line);
        good_print(line, &stack_a, &stack_b);
    }
   // printnode(stack_a.head);
    sorted_or_not(&stack_a);
    
    return(0);
}