#include "../includes/minishell.h"

int main(void)
{
    char *input;

    while (1)
    {
        input = readline("minishell> ");
        if (!input) // Handle EOF (Ctrl+D)
            break;

        // Add input to history if it's not empty
        // if (*input)
        //     add_history(input);

        // Check for blank input
        if (is_blank_line(input))
        {
            free(input);
            continue;
        }

        // Validate syntax
        if (!unclosed_quotes(input))
        {
            free(input);
            continue; // Prompt again if validation fails
        }

        // Pass validated input to ft_split
        // char **tokens = ft_split(input, ' '); // Example: split by spaces
        // if (tokens)
        // {
        //     // Process tokens (e.g., execute commands)
        //     for (int i = 0; tokens[i]; i++)
        //         free(tokens[i]);
        //     free(tokens);
        // }

        if (!pipe_syntax(input) || !file_syntax(input))
            return (false);
        free(input); // Free input after processing
    }

    return 0;
}
