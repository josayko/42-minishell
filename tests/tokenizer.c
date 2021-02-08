# include "../includes/msh.h"
#include <ctype.h>
#include <stdio.h>

enum e_type {
	END,
	BUILTIN,
	EXEC,
	ARG,
	VAR,
	QUOTE,
	DBL_QUOTE,
	SEMICOLON,
	PIPE,
	L_CHEVRON,
	R_CHEVRON,
	DBL_CHEVRON,
	BACKSLASH,
};

typedef struct s_ast {
	enum e_type	type;
	char	*value;
	struct s_ast	*parent;
	struct s_ast	*left;
	struct s_ast	*right;
}				t_ast;

// static void error()
// {
	// ft_putstr_fd("Error parsing input\n", 2);
// }

// 0123456789
// ls -l srcs

char * get_next_token(char *input, int *pos)
{
	int start;
	char *token;

	token = NULL;
	while (input[*pos] && isblank(input[*pos]))
		(*pos)++;
	start = *pos;
	if (input[*pos] == ';' || input[*pos] == '|')
	{
		token = ft_calloc(2, sizeof(char));
		token[0] = input[*pos];
		(*pos)++;
		return token;
	}
	while (input[*pos] || isblank(input[*pos]))
	{
		if (isblank(input[*pos]) || input[*pos] == ';' || input[*pos] == '|')
		{
			token = ft_substr(input, start, *pos - start);
			return token;
		}
		(*pos)++;
	}
	token = ft_substr(input, start, *pos);
	return token;
}

void ast_add(t_ast **node, char *token)
{
	t_ast *new;
	t_ast *ptr;

	ptr = *node; // reference to the begining of the tree
	if (!ptr->left && !ptr->right && !ptr->parent)
	{
		new = ft_calloc(1, sizeof(t_ast));
		new->type = ARG;
		new->value = token;
		new->left = NULL;
		new->right = NULL;
		new->parent = ft_calloc(1, sizeof(t_ast));
		*node = new;
	}
	else 
	{
		return ;
	}
	return ;
}

int main(void)
{
	t_ast *node;
	int pos = 0;
	int i = 0;
	char *input = "pwd;ls -l libft;ls$HOME| grep main.c";
	char *tokens[MAXLIST];

	ft_bzero(tokens, MAXLIST);
	if (input)
	{
		node = ft_calloc(1, sizeof(t_ast));
		node->left = NULL;
		node->right = NULL;
		node->parent = NULL;
		while (input[pos])
		{
			tokens[i] = get_next_token(input, &pos);
			printf("%s\n", tokens[i]);
			ast_add(&node, tokens[i]);
			i++;
		}
	}
	else {
		printf("Usage: ./a.out <args>\n");
	}
	return (0);
}