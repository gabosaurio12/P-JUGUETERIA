// Bibliotecas basicas
#include <iostream>
#include <string>

// Funcionamiento
#include <fstream>
#include <vector>
#include <ncurses.h>
#include <stdlib.h>

#include "Juguete.cpp"

using namespace std;

void cargarArchivo(string nombre, vector<Juguete> &lista) {
	nombre += ".csv";
	ifstream archivo(nombre);
	if (archivo.is_open()) {
		string linea;
		while (getline(archivo, linea)) {
			vector<string> tokens;
			size_t inicio = 0;
			size_t fin = linea.find(",");
			
			while (fin != string::npos) {
				tokens.push_back(linea.substr(inicio, fin - inicio));
				inicio = fin + 1;
				fin = linea.find(",", inicio);
			}
			tokens.push_back(linea.substr(inicio));

			if (tokens.size() >= 7) {
				Juguete actual(tokens[0], tokens[1], tokens[2], tokens[3], stof(tokens[4]), stoi(tokens[5]), stoi(tokens[6]));
				lista.push_back(actual);
			}
		}
	} else {
		mvprintw(15,37, "Error al abrir el archivo");
	}

	archivo.close();
}

void guardarArchivo(string nombre, vector<Juguete> lista) {
	nombre += ".csv";
	ofstream archivo(nombre);
	if (archivo.is_open()) {
		for (int i = 0; i < lista.size(); i++) {
			Juguete actual = lista[i];
			archivo << actual.getCodigo() << "," << actual.getNombre() << "," << actual.getMarca() << ","
				<< actual.getCategoria() << "," << actual.getPrecio() << "," << actual.getStock() << ","
				<< actual.getApartado() << "\n";
		}
		archivo.close();
	}
}

void buscar() {}

void venta() {}

void registrarVenta() {}

void inventario(string nombreArchivo) {
	vector<Juguete> listaInv;
	cargarArchivo(nombreArchivo, listaInv);

	int x = 2;
	int y = 2;
	for (int i = 0; i < listaInv.size(); i++) {
		Juguete actual = listaInv[i];
		int x2 = x;

		mvprintw(y, x2,"%-15s", actual.getNombre().c_str());
		mvprintw(y, x2 += 15,"%-15s", actual.getMarca().c_str());
		mvprintw(y, x2 += 15,"%-15s", actual.getCategoria().c_str());
		mvprintw(y, x2 += 10,"%-10.2f", actual.getPrecio());
		mvprintw(y, x2 += 10,"%-10d", actual.getStock());
		mvprintw(y, x2 += 5,"%-5d\n", actual.getApartado());
		y++;
	}
	refresh();
}

void alta(string nombreArchivo) {
	clear();

	mvprintw(5,5, "Codigo: ");
	char cod[15];
	getstr(cod);

	mvprintw(6,5, "Nombre: ");
	char nom[20];
	getstr(nom);

	mvprintw(7,5, "Marca: ");
	char mar[20];
	getstr(mar);

	mvprintw(8,5, "Categoria: ");
	char cat[20];
	getstr(cat);

	mvprintw(9,5, "Precio: ");
    char prec[6];
	getstr(prec);
	string precStr(prec);

	mvprintw(10,5, "Stock: ");
	char stock2[3];
	getstr(stock2);
	string stockStr(stock2);

    mvprintw(11,5, "Apartado: ");
    char apar[3];
	getstr(apar);
	string aparStr(apar);

	float precio = stof(precStr);
    int stock = stoi(stockStr);
    int apartado = stoi(aparStr);

    Juguete nuevo(cod, nom, mar, cat, precio, stock, apartado);

    vector<Juguete> lista;
    cargarArchivo(nombreArchivo, lista);
    lista.push_back(nuevo);
    guardarArchivo(nombreArchivo, lista);

	refresh();
}

int main() {
	initscr();

	alta("inventario");
	alta("inventario");

	inventario("inventario");

	getch();

	endwin();
	return 0;
}
