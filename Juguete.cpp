#include <string>

using namespace std;

class Juguete {
	private:
		string codigo;
		string nombre;
		string marca;
		string categoria;
		float precio;
		int stock;
		int apartado;

	public:
		Juguete(string codigo = "", string nombre = "", string marca = "", string categoria = "", float precio = 0.0f, int stock = 0, int apartado = 0)
			: codigo(codigo), nombre(nombre), marca(marca), categoria(categoria), precio(precio), stock(stock), apartado(apartado) {}

		string getCodigo() const {return codigo; }
		void setCodigo(string &cod) {codigo = cod; }

		string getNombre() const { return nombre; }
		void setNombre(string &n) { nombre = n; }

		string getMarca() const { return marca;  }
		void setMarca(string &m) { marca = m; }

		string getCategoria() const { return categoria; }
		void setCategoria(string &c) { categoria = c; }

		float getPrecio() const { return precio; }
		void setPrecio(float &p) { precio = p; }

		int getStock() const { return stock; }
		void setStock(int &s) { stock = s; }

		int getApartado() const { return apartado; }
		void setApartado(int &a) { apartado = a; }
};
