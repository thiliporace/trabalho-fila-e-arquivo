#ifndef __FILA_H__
#define __FILA_H__

const int CAPACIDADE_FILA = 100;

struct Fila
{
	char vetor[CAPACIDADE_FILA];
	int inicio;
	int fim;
	int contador;
};

struct Retorno
{
	int codigo; // -1 = fila vazia, 0 = OK.
	char valor;
};

Fila Create();
bool Enqueue(Fila& fila, char valor);
Retorno Dequeue(Fila& fila);
Retorno Front(const Fila& fila);
bool IsFull(const Fila& fila);
bool IsEmpty(const Fila& fila);

#endif