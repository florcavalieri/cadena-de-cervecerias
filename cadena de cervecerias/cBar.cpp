#include "cBar.h"
#include "cListaT.h"
#include "cMesas.h"
#include "cCadena.h"

cBar::cBar() : cTipoLocal() //RVISAR
{
	//ListaMesas = new cListaT<class cMesas>();
	DineroGanadoB = 0;
	PintasRubia = 0;
	PintasRoja = 0;
	PintasNegra = 0;
}

cBar::cBar(cEncargado* encargado, cListaT<cEmpleado>* listaEmpleados, string num, int rubia, int roja, int negra, string nombre = "", string ubicacion = "") : cTipoLocal(/*listaEncargados, listaMeseros, listaVendedores, */num, rubia, roja, negra, nombre, ubicacion)
{
	DineroGanadoB = 0;
	*estado = limpio;
	//ListaMesas = new cListaT<class cMesas>();
}



cBar::~cBar()
{
}




//void cBar::DineroGanado()
//{
//
//}


void cBar::LimpiezaMesas()
{
	cMesas* mesas;
	if (estado[mesas->getEstado()] == estado[sucio])
		mesas->setEstado(limpio);
}


void cBar::PagarEmpleados(/*cListaT<cEmpleado> * empleado, int dias*/)
{
	/*float totalen = 0, totalme = 0, totalven = 0;

	for (int i = 0; i < ListaEmpleados->getCA(); i++)
	{
		cEncargado *en = dynamic_cast<cEncargado*>(ListaEmpleados[i]);
		cMesero *me = dynamic_cast<cMesero*>(ListaEmpleados[i]);
		cVendedor *ven = dynamic_cast<cVendedor*>(ListaEmpleados[i]);

		if (en != NULL)
		{
			for (int i = 0; i < 7; i++)
			{
				if (i <= 3 && semana[i] == semana[dias])
					totalen = ((SueldoXHoraE*LaJ)*acumulador) + en->getSueldoE();

				if (i > 3 && i <= 5 && semana[i] == semana[dias])
					totalen = ((SueldoXHoraE*VaS)*acumulador) + en->getSueldoE();

				if (i = 6 && semana[i] == semana[dias])
					totalen = ((SueldoXHoraE*D)*acumulador) + en->getSueldoE();
			}

			en->setSalarioE(totalen);
		}

		if (ven != NULL)
		{
			totalven = ((SueldoXHoraV*HorarioTrabajoV)*acumulador) + me->getSueldoM();
			ven->setSalarioV(totalven);
		}
	}*/

	cTipoLocal::PagarEmpleados();

	float totalme = 0;

	for (int i = 0; i < ListaEmpleados->getCA(); i++)
	{
		cMesero* me = dynamic_cast<cMesero*>(ListaEmpleados[i]);

		if (me != NULL)
		{
			totalme = ((SueldoXHoraM * HorarioTrabajoM) * acumMesero) + me->getSueldoM();
			me->setSalarioM(totalme);
		}
	}

}

void cBar::SimularClientes()
{
	cTipoLocal::SimularClientes();
}

void cBar::SolicitarCerveza(int tipocerveza, int cantidad)
{
	switch (tipocerveza)
	{
	case 1:
	{
		PintasRubia = PintasRubia - cantidad;
		if ((PintasRubia / 3) % 2 == 0)
			BRubia--;
		break;
	}
	case 2:
	{
		PintasRoja = PintasRoja - cantidad;
		if ((PintasRoja / 3) % 2 == 0)
			BRoja--;
		break;
	}
	case 3:
	{
		PintasNegra = PintasNegra - cantidad;
		if ((PintasNegra / 3) % 2 == 0)
			BNegra--;
		break;
	}
	}
}

bool cBar::VerificarBarriles(int tipocerveza, int cantidad)
{
	int auxR, auxRO, auxN, resultado;
	switch (tipocerveza)
	{
	case 1:
	{
		auxR = (PintasRubia - cantidad) / 3;

		if (auxR % 2 == 0)
			BRubia--;
		if (BRubia > MINBARRILES)
			return true;
		break;
	}
	case 2:
	{
		auxRO = (PintasRoja - cantidad) / 3;

		if (auxRO % 2 == 0)
			BRoja--;
		if (BRoja > MINBARRILES)
			return true;
		break;
	}
	case 3:
	{
		auxN = (PintasNegra - cantidad) / 3;

		if (auxN % 2 == 0)
			BNegra--;
		if (BNegra > MINBARRILES)
			return true;
		break;
	}
	}
}


ostream& operator << (ostream& out, cBar* bar)
{
	out << bar->getNombre() << endl;
	out << bar->getUbicacion() << endl;
	out << bar->getNumero() << endl;
	return out;
}
