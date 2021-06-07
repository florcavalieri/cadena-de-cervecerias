#pragma once 
#include "cBar.h"

typedef enum Estado { limpio, sucio, ocupado };

//template<typename cCliente>
//class cListaT;

class cMesas : public cBar
{

public:

	cMesas();
	virtual ~cMesas();

	//SETS 
	void setEstado(Estado estado) { this->estado = estado; }

	//GETS 
	int getEstado() { return estado; }

private:

	Estado estado;
	static int NumeroMesa;

};

