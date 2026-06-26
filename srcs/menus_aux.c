#include "menus_aux.h"

void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

int get_int(const char *prompt, int *value)
{
    int r;

    while (1)
    {
        printf("%s", prompt);
        r = scanf("%d", value);
        if (r == EOF)
        {
            printf("\nA sair...\n");
            return EOF;
        }
        if (r == 1)
        {
            clear_input_buffer();
            return 1;
        }
        printf("Entrada inválida. Tente novamente.\n");
        clear_input_buffer();
    }
}

int get_line(const char *prompt, char *buf, int size)
{
    while (1)
    {
        printf("%s", prompt);
        if (fgets(buf, size, stdin) == NULL)
        {
            printf("\nA sair...\n");
            return EOF;
        }
        buf[strcspn(buf, "\r\n")] = '\0';
        if (buf[0] != '\0')
            return 1;
        printf("Entrada inválida. Tente novamente.\n");
    }
}

void separator(void)
{
    printf("  ------------------------------------------------\n");
}

void header(const char *title)
{
    printf("\n  ================================================\n");
    printf("  %s\n", title);
    printf("  ================================================\n\n");
}

void pause_enter(void)
{
    int c;
    printf("\n  Prima ENTER para continuar...");
    fflush(stdout);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void clear_screen(void)
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
