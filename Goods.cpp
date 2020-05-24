#include "Goods.hpp"

using namespace std;


Goods::Goods(string _name, int _productId) {
	name = _name;
	productId = _productId;
}

void Goods::setOffer(Offer* newOffer) {
	offers.push_back(newOffer);
}

void Goods::printNameAndProductId() {
	cout<< productId<< COULMN_DELIMITER<< name;
}

vector<Offer*> Goods::getAllOffers() {
	return offers;
}

int Goods::getProductId() {
	return productId;
}

void Goods::printInformation() {
	cout<< "NOTHING TO PRINT";
}

void Goods::printComments() {
	for(int i = comments.size() - 1; i >= 0; i--)
		cout<< comments[i].commenter<< COULMN_DELIMITER<< comments[i].comment<<endl;
}


Mobile::Mobile(string _name, int _productId, int _weight, int _frequency, int _builtInMemory, 
		int _RAM, int _displaySize, int _cameraResolution, string _operationgSystem): Goods(_name, _productId) {
	weight = _weight;
	frequency = _frequency;
	builtInMemory = _builtInMemory;
	RAM = _RAM;
	displaySize = _displaySize;
	cameraResolution = _cameraResolution;
	operatingSystem = _operationgSystem;
}

void Mobile::compareMobileProducts(Mobile* mobile2) {
	cout<< name<< COULMN_DELIMITER<< mobile2->name<< endl;
	cout<< "weight: "<< weight<< COULMN_DELIMITER<< mobile2->weight<< endl;
	cout<< "CPU Frequency: "<< frequency<< COULMN_DELIMITER<< mobile2->frequency<< endl;
	cout<< "Built-in Memory: "<< builtInMemory<< COULMN_DELIMITER << mobile2->builtInMemory<< endl;
	cout<< "RAM: "<< RAM<< COULMN_DELIMITER<< mobile2->RAM<< endl;
	cout<< "Display Size: "<< displaySize<< COULMN_DELIMITER<< mobile2->displaySize<< endl;
	cout<< "Camera Resolution: "<< cameraResolution<< COULMN_DELIMITER<< mobile2->cameraResolution<< endl;
	cout<< "Operationg System: "<< operatingSystem<< COULMN_DELIMITER<< mobile2->operatingSystem<< endl;
}

void Mobile::printInformation() {
	cout<< name<< endl;
	cout<< "Weight: "<< weight<<endl;
	cout<< "CPU Frequency: "<< frequency<<endl;
	cout<< "Built-in Memory: "<< builtInMemory<<endl;
	cout<< "RAM: "<< RAM<<endl;
	cout<< "Display Size: "<< displaySize<< endl;
	cout<< "Camera Resolution: "<< cameraResolution<< endl;
	cout<< "Operationg System: "<< operatingSystem<<endl;
}


TV::TV(string _name, int _productId, int _screenSize, string _screenType, string _resolution, bool _3D, bool _HDR): Goods(_name, _productId) {
	screenSize = _screenSize;
	screenType = _screenType;
	resolution = _resolution;
	threeD = _3D;
	HDR = _HDR;
}

void TV::printInformation() {
	cout<< name<< endl;;
	cout<< "Screen Size: "<< screenSize<<endl;
	cout<< "Screen Type: "<< screenType<<endl;
	cout<< "Resolution: "<< resolution<<endl;
	cout<< "3D: "<< threeD<<endl;
	cout<< "HDR: "<< HDR<<endl;
}

void TV::compareTVProducts(TV* tv2) {
	cout<< name<< COULMN_DELIMITER<< tv2->name<< endl;
	cout<< "Screen Size: "<< screenSize<< COULMN_DELIMITER<< tv2->screenSize<< endl;
	cout<< "Screen Type: "<< screenType<< COULMN_DELIMITER<< tv2->screenType<< endl;
	cout<< "Resolution: "<< resolution<< COULMN_DELIMITER<< tv2->resolution<< endl;
	cout<< "3D: "<< threeD<< COULMN_DELIMITER<< tv2->threeD<< endl;
	cout<< "HDR: "<< HDR<< COULMN_DELIMITER<< tv2->HDR<< endl;
}

Car::Car(string _name, int _productId, int _weight, int _numberOfSeats, int _numberOfCylinders,
	 int _engineCapacity, bool _reverseParkingSensor): Goods(_name, _productId) {
	weight = _weight;
	numberOfSeats = _numberOfSeats;
	numberOfCylinders = _numberOfCylinders;
	engineCapacity = _engineCapacity;
	reverseParkingSensor = _reverseParkingSensor;
}

void Car::printInformation() {
	cout<< name<< endl;;
	cout<< "Weight: "<< weight<<endl;
	cout<< "Num. of Seats: "<< numberOfSeats<< endl;
	cout<< "Num. of Cylinders: "<< numberOfCylinders<<endl;
	cout<< "Engine Capacity: "<< engineCapacity<<endl;
	cout<< "Reverse Parking Sensor: "<< reverseParkingSensor<<endl;
}

void Car::compareCarProducts(Car* car2) {
	cout<< name<< car2->name<< endl;
	cout<< "Num. of Seats: "<< numberOfSeats<< COULMN_DELIMITER<< car2->numberOfSeats<< endl;
	cout<< "Num. of Cylinders: "<< numberOfCylinders<< COULMN_DELIMITER<< car2->numberOfCylinders<< endl;
	cout<< "Engine Capacity: "<< engineCapacity<< COULMN_DELIMITER<< car2->engineCapacity<< endl;
	cout<< "Reverse Parking Sensor: "<< reverseParkingSensor<< COULMN_DELIMITER<< car2->reverseParkingSensor<< endl; 
}