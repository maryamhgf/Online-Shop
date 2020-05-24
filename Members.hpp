#ifndef __MEMBERS_HPP__
#define __MEMBERS_HPP__

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
#include "Struct.hpp"
#include "Goods.hpp"

using namespace std;

class Goods;
class TV;
class Mobile;
class Car;
class BadRequestException;
class NotFoundException;
class PermissionDeniedException;
class Seller;
class Buyer;
struct comment;
struct offer;
struct order;
struct discount;
typedef struct comment Comment;
typedef struct order Order;
typedef struct offer Offer;
typedef struct discount Discount;

class Member {
public:
	Member(string _username, string _password, string _email, int _id, Role _type);
	int giveId() { return id;}
	bool checkPassword(string passwordToCheck);
	void getAccount(int count);
	void printAllGoods(vector<Goods*> allGoods);
protected:
	string username;
	string password;
	string email;
	int id;
	Role type;
	vector<float> account;
};

class Admin: public Member {
public:
	Admin();
	void importTvs(string tvFilename);
	void importCars(string carFilename);
	void importMobiles(string mobileFilename);
	void addNewTv(vector<string> infOfNewTv, int productId);
	void addNewMobile(vector<string> inOfNewMobile, int productId);
	void addNewCar(vector<string> inOfNewCar, int productId);
	void printAllOffers(string order, string field);
	void printAllGoods();
	void printOffersOfSellers(string order, string field, vector<Offer*> offers);
	int getNumberOfProducts() {return numberOfProducts;}
	vector<Goods*> getAllGoods() {return allGoods;}
	vector<Goods*> findOfferedGoods();
private:
	vector<Seller> allSellers;
	vector<Buyer> allBuyers;
	vector<Mobile*> mobiles;
	vector<TV*> tvs;
	vector<Car*> cars;
	vector<Goods*>allGoods;
	int numberOfProducts;
};


class Seller: public Member {
public:
	Seller(string _usename, string _password, string _email, int _id);
	int findIndexOfProductInAdminGoods(vector<Goods*> allGoods, int productId);
	void checkExistedOffer(int productId);
	void giveOffer(vector<Goods*> allGoods, int productId, string productName, int amount, float price, int offerId);
	void printOffers();
	void changeOffer(int offerId, float offerPrice, int offerAmount);
	int findIndexOfOfferBaseOnOfferId(int offerId);
	void generateDiscountCode(int offerId, int Number, int percentage);
	void updateSellerAccount(float cash, int amount);
	vector<Offer*> getOffers() {return givenOffers;}
	int getId() {return id;}
	string getName() {return username;}
	void updateBuyers(string buyer);
	void printInforamtionOfOfferBasedOnBuyer(string buyerName); 
	void printOffersBuyers();
private:
	vector<string> buyers;
	vector<Goods*> goodsForSell; 
	vector<Offer*> givenOffers;
};


class Buyer: public Member {
public:
	Buyer(string _usename, string _password, string _email, int _id);
	void seeOffersForProduct(int productId, vector<Goods*> allGoods);
	void seeFeaturesOfProduct(int productId, vector<Goods*> allGoods); 
	void seeComments(int productId, vector<Goods*> allGoods);
	void addToCart(int offerId, int amount, vector<Offer*> offers, string discountCode, int cartId);
	void viewCart();
	void giveOrder(vector<Offer*> offers);
	void viewOrders(int count);
	void chargeAccount(float amount);
	void addComment(int productId, string newComment, vector<Goods*> allGoods);
	void compare(int productId1, int productId2, vector<Goods*> allGoods);
	void copyCartToBoughtCart();
	void updateSoldPrice(vector<Offer*> offers, int offerId, float soldPrice);
	void updateBuyerNameAndId(vector<Offer*> offers, int offerId);
	void printAllOffers(vector<Offer*> offers, vector<Goods*> allGoods);
private:
	vector<Order> cart;
	vector<Order> boughtCart;
};


#endif