#include<iostream>
#include<fstream>
#include"ArrayStack.h"
#include "ArrayStack.h"
#include"Garage.h"
#include"StackInterface.h"
using namespace std;


int main() {

	Car tempCar;
	Garage garageCar;
	string carPlate;
	int counter = 0;
	char A_D;

	ifstream myfile;
	myfile.open("Cars.txt");
	if (!myfile) {
		cout << "File not found" << endl;
	}
	while (!myfile.eof()) {

		myfile >> A_D >> carPlate;
		tempCar.setPlate(carPlate);
		if (A_D == 'A') {
			garageCar.arrival(tempCar);
		}

		else
		{
			garageCar.departure(tempCar);
		}	
	 }

	myfile.close();

	system("pause");
	return 0;
}
