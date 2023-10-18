#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "lista_ligada.h"

struct item
{
    unsigned int valor;
    char *chave;
};

struct no
{
    Item dados;
    No *proximo;
};

No *criar_lista_ligada()
{
    return NULL;
}

void destruir_lista_ligada(No *ptr_no)
{

    No *ptr_no_aux;
    while (ptr_no != NULL)
    {
        ptr_no_aux = ptr_no;
        ptr_no = ptr_no->proximo;
        free(ptr_no_aux);
    }
}

char *strdup(const char *src)
{
    size_t length = strlen(src) + 1;
    char *dst = malloc(length);
    if (dst != NULL)
    {
        memcpy(dst, src, length);
    }
    return dst;
}

// adiciona no na cabeça da lista
No *adicionar_lista_ligada(No *ptr_ptr_no, char *chave, int valor)
{

    No *novo_no = (No *)malloc(sizeof(No));
    novo_no->dados.chave = strdup(chave);
    novo_no->dados.valor = valor;
    novo_no->proximo = ptr_ptr_no;
    return novo_no;
}

// remove da cabeça da lista
No *remover_lista_ligada(No *ptr_ptr_no, char *chave)
{
    No *ptr_no_anterior = NULL;
    No *ptr_no_atual = ptr_ptr_no;

    while (ptr_no_atual != NULL)
    {
        if (strcmp(ptr_no_atual->dados.chave, chave) == 0)
        {
            if (ptr_no_anterior != NULL)
            {
                ptr_no_anterior->proximo = ptr_no_atual->proximo;
            }
            else
            {
                ptr_ptr_no = ptr_no_atual->proximo;
            }
            free(ptr_no_atual->dados.chave);
            free(ptr_no_atual);
            break;
        }
        ptr_no_anterior = ptr_no_atual;
        ptr_no_atual = ptr_no_atual->proximo;
    }

    return ptr_ptr_no;
}

int buscar_valor_lista_ligada(No *ptr_no, char *chave)
{
    while (ptr_no != NULL)
    {
        if (strcmp(ptr_no->dados.chave, chave) == 0)
        {
            return ptr_no->dados.valor;
        }
        ptr_no = ptr_no->proximo;
    }
    return -1; // Retorna -1 se a chave não for encontrada
}

void imprimir_lista_ligada(No *ptr_no)
{

    while (ptr_no != NULL)
    {
        printf("(%s, %d) ", ptr_no->dados.chave, ptr_no->dados.valor);
        if (ptr_no->proximo != NULL)
            printf("-> ");
        ptr_no = ptr_no->proximo;
    }
}