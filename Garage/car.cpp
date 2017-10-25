#include "Car.h"
#include<string>

//get the car plate

void Car::setPlate(string newPlate) {

	plate = newPlate;
}


// count the number of times the car was moved
void Car::setTurn(){
	counter++;
}

void Car::setCarStatus( char newStatus) {
	carStatus = newStatus;
}


// compare license plate

bool Car:: operator== (Car& compareLicense) {

	return  (plate == compareLicense.getPlate());
}

bool Car::operator!= (Car& compareLicense) {

	return (plate != compareLicense.getPlate());
	
	
}

Car:: ~Car() {

}



