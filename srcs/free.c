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
    FileList *files = auth->users->user->files;
    while (files != NULL)
    {
        remover_ficheiro(files, files->file->id);
        files = files->next;
    } 
    remover_diretorio(auth->users->user->name);
    printf("A sair...\n");
}
