class cCliente
{

public:
	cCliente();
	cCliente(float billetera, bool sentado, int pinta, float mediaPinta);
	cCliente(const cCliente& c);
	virtual ~cCliente();

	void PedirCerveza();

private:
	float billetera;
	bool sentado;
	int pinta;
	float mediaPinta;
};

