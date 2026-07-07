# include "free.h"

void free_arvore(No *raiz)
{
    if (!raiz)
        return;
    free_arvore(raiz->esq);
    free_arvore(raiz->dir);
    free(raiz);
}

void free_everything(Auth *auth)
{
    if (!auth)
        return;
    if (auth->users && auth->users->user && auth->users->user->files)
    {
        FileList *files = auth->users->user->files;
        while (files != NULL)
        {
            remover_ficheiro(files, files->file->id);
            files = files->next;
        }
    }
    if (auth->users && auth->users->user && auth->users->user->name && opendir(auth->users->user->name))
        remover_diretorio(auth->users->user->name);
    printf("A sair...\n");
}
