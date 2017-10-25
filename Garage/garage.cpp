#include "Garage.h"
#include <iostream>
using namespace std;



//Garage::Garage(){
//	ArrayStack<Car> laneOne(10);
//	ArrayStack<Car>laneTwo(10);
//	ArrayStack<Car>street(10);
//
//}


//check lane one to see if it is empty

bool Garage::checkLaneOne() {
	if (laneOne.isEmpty()) {
		return true;
	}
	else {
		return false;
	}
}


// Check Lane Two see if it is empty


bool Garage::checkLaneTwo() {
	if (laneTwo.isEmpty()) {
		return true;
	 }

	else {
		return false;
	}
}


////push car into lane one  if the there's a room

void Garage::toLaneOne( Car& newCar) {
	if (!laneOne.isEmpty()) {
		laneOne.push(newCar);
	}
	else{
		cout << "Lane is full" << endl;
		}

}




//push car into lane two  if the there's a room

void Garage::toLaneTwo( Car& newCar) {

	if (!laneTwo.isEmpty()) {
		laneTwo.push(newCar);
	}
	else {
		cout << "Lane Two is full" << endl;
	}
}



void Garage:: toStreet(Car& newCar) {
	 if(laneOne.isFull()) {

		 street.push(newCar);
  }
	 else if (laneTwo.isFull()) {
		 street.push(newCar);
	 }

	 else {
		 street.pop();
	 }
}


void Garage::arrival(Car& newEntry) {

	if (laneOne.isFull() == false) {
		laneOne.push(newEntry);
		cout << newEntry.getPlate() << " has been pushed into lane one" << endl;

  }
	else if (laneTwo.isFull() == false) {
		laneTwo.push(newEntry);
		cout << newEntry.getPlate() << " has been pushed into lane two" << endl;
	}

	else {
		cout << "Both lanes are full" << endl;
	}
}


void Garage:: departure( Car& departure) {
	Car temp;
	int counterOne = 0,
		counterTwo = 0,
		counterThree = 0;

	if (laneOne.search(departure) == true) {
		while (laneOne.isEmpty() == false)
		{
			temp = laneOne.peek();
			laneOne.pop();
			if (temp.getPlate() == departure.getPlate())
			{
				cout << departure.getPlate() << " has been departed from lane 1" << endl;
				break;
			}
			else if (laneTwo.isFull() == false)
			{
				laneTwo.push(temp);
				counterTwo++;
				cout << temp.getPlate() << "  has been moved from lane 1 to lane 2 " << endl;
			}
			else if (laneTwo.isFull() == true) {
				street.push(temp);
				counterThree++;		
				
			}

		}
		while (counterThree != 0)
		{
			temp = street.peek();
			street.pop();
			cout << temp.getPlate() << " has been moved from street back to lane 1" << endl;
			laneOne.push(temp);
			counterThree--;
		}
		while (counterTwo != 0)
		{
			temp = laneTwo.peek();
			laneTwo.pop();
			cout << temp.getPlate() << " has been moved from lane 2 back to lane 1" << endl;
			laneOne.push(temp);
			counterTwo--;
		}
 }

	else {

		 // lane two

		if (laneTwo.search(temp) == true) {

			while (laneTwo.isEmpty() == false)
			{
				temp = laneTwo.peek();
				laneTwo.pop();

				if (temp.getPlate() == departure.getPlate()) {
					cout << departure.getPlate() << " has been departed from lane 2" << endl;
					break;
				}

				else if (laneOne.isFull() == false) {
					laneOne.push(temp);
					counterTwo++;
					cout << temp.getPlate() << " has been moved from lane 2 to lane 1" << endl;
					
				}
				else if (laneOne.isFull() == true) {
					street.push(temp);
					counterThree++;

				}
			}
		}
	}

}

//free the memory
Garage::~Garage()
{
}
