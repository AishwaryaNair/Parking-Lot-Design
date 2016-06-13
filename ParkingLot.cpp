#include "ParkingLot.h"

bool ParkingLot::park(Car& car){
	if (car.getcartype() == REGULAR){
		if (signboard.getavailableregular() != 0){
			for (int i = 0; i < 1; i++){
				if (parkingspaces[i].getempty() == true){
					car.setparkinglotnumber(i);
					parkingspaces[i].setempty(false);
					signboard.subtractfromavailable(REGULAR);
					return true;
				}
			}
		}
	}
	else if (car.getcartype() == COMPACT){
		if (signboard.getavailablecompact() != 0){
			for (int i = 1; i < 2; i++){
				if (parkingspaces[i].getempty() == true){
					car.setparkinglotnumber(i);
					parkingspaces[i].setempty(false);
					signboard.subtractfromavailable(COMPACT);
					return true;
				}
			}
		}
	}
	else if (car.getcartype() == HANDICAPPED){
		if (signboard.getavailablehandicapped() != 0){
			for (int i = 2; i < 3; i++){
				if (parkingspaces[i].getempty() == true){
					car.setparkinglotnumber(i);
					parkingspaces[i].setempty(false);
					signboard.subtractfromavailable(HANDICAPPED);
					return true;
				}
			}
		}
	}
	return false;
}

void ParkingLot::unpark(Car& car){
	if (car.getcartype() == REGULAR){
		parkingspaces[car.getparkinglotnumber()].setempty(true);
		signboard.addtoavailable(REGULAR);
	}
	else if (car.getcartype() == COMPACT){
		parkingspaces[car.getparkinglotnumber()].setempty(true);
		signboard.addtoavailable(COMPACT);
	}
	else if (car.getcartype() == HANDICAPPED){
		parkingspaces[car.getparkinglotnumber()].setempty(true);
		signboard.addtoavailable(HANDICAPPED);
	}
}

void ParkingLot::setparkingspaces(vector<ParkingSpace> input){
	parkingspaces = input;
}
void ParkingLot::setsignboard(ParkingLotSign input){
	signboard = input;
}

void ParkingSpace::settypeofparking(ParkingType input){
	typeofparking = input;
}

ParkingType ParkingSpace::gettypeofparking(){
	return typeofparking;
}

void ParkingSpace::setempty(bool value){
	isempty = value;
}

bool ParkingSpace::getempty(){
	return isempty;
}

void ParkingSpace::setdistance(int value){
	distance = value;
}

int ParkingSpace::getdistance(){
	return distance;
}

void ParkingLotSign::setavailableregular(int value){
	availableregular = value;
}

void ParkingLotSign::setavailablecompact(int value){
	availablecompact = value;
}

void ParkingLotSign::setavailablehandicapped(int value){
	availablehandicapped = value;
}

int ParkingLotSign::getavailableregular(){
	return availableregular;
}

int ParkingLotSign::getavailablecompact(){
	return availablecompact;
}

int ParkingLotSign::getavailablehandicapped(){
	return availablehandicapped;
}

void ParkingLotSign::addtoavailable(ParkingType cartype){
	if (cartype == REGULAR){
		availableregular += 1;
	}
	else if (cartype == COMPACT){
		availablecompact += 1;
	}
	else if (cartype == HANDICAPPED){
		availablehandicapped += 1;
	}
}

void ParkingLotSign::subtractfromavailable(ParkingType cartype){
	if (cartype == REGULAR){
		availableregular -= 1;
	}
	else if (cartype == COMPACT){
		availablecompact -= 1;
	}
	else if (cartype == HANDICAPPED){
		availablehandicapped -= 1;
	}
}

void Car::setcartypr(ParkingType input){
	cartype = input;
}

ParkingType Car::getcartype(){
	return cartype;
}

void Car::setparkinglotnumber(int value){
	parkingslotnumber = value;
}

int Car::getparkinglotnumber(){
	return parkingslotnumber;
}

int main(){
	ParkingLotSign parkinglotsign;
	parkinglotsign.setavailablecompact(1);
	parkinglotsign.setavailableregular(1);
	parkinglotsign.setavailablehandicapped(1);
	ParkingType pt;
	vector<ParkingSpace> parkingspace;
	ParkingSpace p1;
	p1.setempty(true);
	pt = REGULAR;
	p1.settypeofparking(pt);
	parkingspace.push_back(p1);
	pt = COMPACT;
	p1.settypeofparking(pt);
	parkingspace.push_back(p1);
	pt = HANDICAPPED;
	p1.settypeofparking(pt);
	parkingspace.push_back(p1);
	ParkingLot parkinglot;
	parkinglot.setparkingspaces(parkingspace);
	parkinglot.setsignboard(parkinglotsign);
	Car car1;
	car1.setcartypr(REGULAR);
	if (parkinglot.park(car1) == true){
		cout << "Car parked\n";
	}
	else{
		cout << "No place to park\n";
	}
	Car car2;
	car2.setcartypr(REGULAR);
	if (parkinglot.park(car2) == true){
		cout << "Car parked\n";
	}
	else{
		cout << "No place to park\n";
	}
	Car car3;
	car3.setcartypr(HANDICAPPED);
	if (parkinglot.park(car3) == true){
		cout << "Car parked\n";
	}
	else{
		cout << "No place to park\n";
	}
	parkinglot.unpark(car1);
	if (parkinglot.park(car2) == true){
		cout << "Car parked\n";
	}
	else{
		cout << "No place to park\n";
	}
	system("pause");
	return 0;
}


