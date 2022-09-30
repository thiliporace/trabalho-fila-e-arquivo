#include "fila.h"

Fila Create()
{
	Fila f;
	f.inicio = f.fim = f.contador = 0;
	for (int i = 0; i < CAPACIDADE_FILA; ++i)
		f.vetor[i] = '\0';
	
	return f;
}

bool Enqueue(Fila& fila, char valor)
{
	if (IsFull(fila))
		return false;
	
	fila.vetor[fila.fim] = valor;
	fila.fim = (fila.fim + 1) % CAPACIDADE_FILA;
	++fila.contador;
	return true;
}

Retorno Dequeue(Fila& fila)
{
	Retorno ret = { -1, '\0' };
	
	if (IsEmpty(fila))
		return ret;

	ret.codigo = 0;
	ret.valor = fila.vetor[fila.inicio];
	
	fila.vetor[fila.inicio] = '\0';
	fila.inicio = (fila.inicio + 1) % CAPACIDADE_FILA;
	--fila.contador;
	
	return ret;
}

Retorno Front(const Fila& fila)
{
	Retorno ret = { -1, '\0' };
	
	if (!IsEmpty(fila))
	{
		ret.codigo = 0;
		ret.valor = fila.vetor[fila.inicio];
	}
	
	return ret;
}

int Count(const Fila& fila){
  return fila.contador;
}

Fila Clear(Fila& fila){
  if (IsEmpty(fila)){
    return fila;
  }
  for (int i = 0;i < CAPACIDADE_FILA;i++){
    Dequeue(fila);
  }
  return fila;
}

bool IsFull(const Fila& fila)
{
	return fila.contador == CAPACIDADE_FILA;
}

bool IsEmpty(const Fila& fila)
{
	return fila.contador == 0;
}

