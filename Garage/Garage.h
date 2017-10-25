#pragma once
#include"Car.h"
#include"ArrayStack.h"
#include<string>


class Garage
{

private:
	ArrayStack<Car> laneOne;
	ArrayStack<Car> laneTwo;
	ArrayStack<Car> street;


public:
	/*Garage();*/
	bool checkLaneOne();
	bool  checkLaneTwo();
	void toLaneOne( Car& newCar);
	void toLaneTwo( Car& newCar);
	void toStreet( Car& newCar);
	void arrival( Car& arrival);
	void departure( Car& departure);
	~Garage();
};

#include"Garage.cpp"





