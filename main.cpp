#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>

double traslodilatazione_da_ab_a_cd(double n, double a, double b, double c, double d){
	
	double raggio_ab = std::abs(b-a)/2;
	double raggio_cd = std::abs(d-c)/2;
	
	double centro_ab = a + raggio_ab;
	double centro_cd = c + raggio_cd;
	
	n = n-centro_ab;
	n = n/raggio_ab;
	n = n*raggio_cd;
	n = n+centro_cd;
	
	return n;
}

int main()
{

	std::string namein = "data.txt";
	std::string nameout = "result.txt";
	
	std:: ifstream filein(namein);
	std:: ofstream fileout(nameout);
	if (filein.fail())
	{
		std::cerr << "non si apre data.txt" << std::endl;
		return 1;
	}
	
	std::string linea;
	std::getline(filein, linea);
	
	double a = 1;
	double b = 5;	
	double c = -1;
	double d = 2;
	
	int contatore = 1;
	double somma = 0;
	while (std::getline(filein,linea)){
		std::stringstream ss;
		ss << linea;
		double numero;
		if (ss>>numero){
			numero = traslodilatazione_da_ab_a_cd(numero,a,b,c,d);
			contatore++;
			somma += numero;
			double media = somma/contatore;
			fileout << media;
			fileout << std::endl;			
		}
		else{
			std::cout << "errore di formattazione di data.txt" << std::endl;
		}		
	}
	filein.close();
	fileout.close();
    return 0;
}
