#ifndef __GOODS_HPP__
#define __GOODS_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <algorithm>
#include <stdlib.h>
#include <bits/stdc++.h> 
#include <stdio.h>
#include "Exceptions.hpp"
#include "Members.hpp"
#include "Struct.hpp"

using namespace std;

class BadRequestException;
class NotFoundException;
class PermissionDeniedException;
class Seller;
class Buyer;
typedef struct discount{
	string discountCode;
	int discountPercent;
} Discount;

typedef struct comment{
	string comment;
	string commenter;
} Comment;

typedef struct order{
	int productId;
	int offerId;
	int amount;
	float price;
	int cartId;
	Seller* seller;
	string productName;
} Order;

typedef struct offer{
	int amount;
	float price;
	float soldPrice;
	int offerId;
	int productId;
	string productName;
	vector<Discount> discountCodes;
	Seller* seller;
	string buyerName;
	int idOfBuyer;
} Offer;


class Goods {
public:
	Goods(string _name, int _productId);
	void setOffer(Offer* newOffer);
	void printNameAndProductId();
	int getProductId();
	string getName() { return name;}
	vector<Offer*> getAllOffers();
	virtual void printInformation();
	void printComments();
	void addComment(Comment newComment) { comments.push_back(newComment);}
protected:
	string name;
	vector<Comment> comments;
	int productId;
	vector<Offer*> offers;	
};

class Mobile: public Goods {
public:
	Mobile(string _name, int _productId, int _weight, int _frequency, int builtInMemory, int RAM, int displaySize, int cameraResolution, string operatingSystem);
	void printInformation();
	void compareMobileProducts(Mobile* mobile2);
private:
	int weight;
	int frequency;
	int builtInMemory;
	int RAM;
	int displaySize;
	int cameraResolution;
	string operatingSystem;
};

class TV: public Goods {
public:
	TV(string _name, int _productId, int _screenSize, string _screenType, string _resolution, bool _3D, bool _HDR);
	void printInformation();
	void compareTVProducts(TV* tv2);
private:
	int screenSize;
	string screenType;
	string resolution;
	bool threeD;
	bool HDR;
};

class Car: public Goods {
public:
	Car(string _name, int _productId, int _weight, int _numberOfSeats, int _numberOfCylinders, int _engineCapacity, bool _reverseParkingSensor); 
	void printInformation();
	void compareCarProducts(Car* car2);
private:
	int weight;
	int numberOfSeats;
	int numberOfCylinders;
	int engineCapacity;
	bool reverseParkingSensor;
};

#endif