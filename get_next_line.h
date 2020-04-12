#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

typedef struct	list_link {
	void 	*str;
	struct 	list_link* next;
}				t_list_link;

typedef struct list_head
{
	unsigned int 	count = 0;
	t_list_link 	*next;
}				t_list_head;
