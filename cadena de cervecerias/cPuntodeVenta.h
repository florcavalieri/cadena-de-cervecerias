#include "cTipoLocal.h"

class cPuntodeVenta : public cTipoLocal
{

public:
	cPuntodeVenta();
	//cPuntodeVenta(cListaT<cEncargado>*listaEncargados, cListaT<cMesero>*listaMeseros, cListaT<cVendedor>*listaVendedores, string num, string nombre, string ubicacion, int barriles = MAXBARRILES);
	cPuntodeVenta(cEncargado* encargado, cListaT<cEmpleado>* ListaVendedores, string num, int rubia, int roja, int negra, string nombre = "", string ubicacion = "");
	cPuntodeVenta(const cPuntodeVenta& pdv);
	virtual ~cPuntodeVenta();


	void SimularClientes() { cTipoLocal::SimularClientes(); }
	void PagarEmpleados(/*cListaT<cEmpleado> *empleado, int acumulador, int dias*/) { cTipoLocal::PagarEmpleados(); } //CORREGIR
	void EntradaEmpleados(cListaT<cEmpleado>* empleado) { cTipoLocal::EntradaEmpleados(); } //REVISAR
	//void SalidaEmpleados(cEmpleado * empleado) { cTipoLocal::SalidaEmpleados(empleado); } //REVISAR
	void SolicitarCerveza(int tipocerveza, int cantidad) { cTipoLocal::SolicitarCerveza(tipocerveza, cantidad); }
	bool VerificarBarriles(int tipocerveza, int cantidad) { cTipoLocal::VerificarBarriles(tipocerveza, cantidad); }
	string getNombre() { return cTipoLocal::nombre; }
	string getUbicacion() { return cTipoLocal::ubicacion; }
	string getNumero() { return cTipoLocal::numero; }


private:

	float DineroGanadoP;

};

ostream& operator << (ostream& out, cPuntodeVenta& pdv);

