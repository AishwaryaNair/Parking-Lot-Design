#include <iostream>
#include <vector>

using namespace std;

enum ParkingType{
	REGULAR,
	COMPACT,
	HANDICAPPED
};

class ParkingSpace{
private:
	ParkingType typeofparking;
	bool isempty;
	int distance;
public:
	ParkingSpace(){};
	~ParkingSpace(){};
	void settypeofparking(ParkingType input);
	ParkingType gettypeofparking();
	void setempty(bool value);
	bool getempty();
	void setdistance(int value);
	int getdistance();
};

class ParkingLotSign{
private:
	int availableregular;
	int availablecompact;
	int availablehandicapped;
public:
	void setavailableregular(int value);
	void setavailablecompact(int value);
	void setavailablehandicapped(int value);
	int getavailableregular();
	int getavailablecompact();
	int getavailablehandicapped();
	void addtoavailable(ParkingType cartype);
	void subtractfromavailable(ParkingType cartype);
};

class Car{
private:
	ParkingType cartype;
	int parkingslotnumber;
public:
	void setcartypr(ParkingType input);
	ParkingType getcartype();
	void setparkinglotnumber(int value);
	int getparkinglotnumber();
};

class ParkingLot{
private:
	vector<ParkingSpace> parkingspaces;
	ParkingLotSign signboard;
public:
	ParkingLot(){};
	~ParkingLot(){};
	void setparkingspaces(vector<ParkingSpace> input);
	void setsignboard(ParkingLotSign input);
	bool park(Car& car);
	void unpark(Car& car);
};


