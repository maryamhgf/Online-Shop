#ifndef __STORE_HPP__
#define __STORE_HPP__

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
#include "Members.hpp"

using namespace std;

class Goods;
class Mobile;
class TV;
class Car;
class Member;
class Admin;
class Buyer;
class Seller;
class BadRequestException;
class NotFoundException;
class PermissionDeniedException;
struct comment;
struct offer;
struct order;
struct discount;
typedef struct comment Comment;
typedef struct order Order;
typedef struct offer Offer;
typedef struct discount Discount;
enum CommandTypes {LoginCommand, LogoutCommand, SignupCommand, ImportCommand, ViewSellersOffersCommand, ViewStoreProductsCommand, OfferCommand,
	 ViewOwnOfferCommand, ChangeOfferCommand, ViewAccountCommand, DiscountCommand, ViewOffersOnProductCommand, ViewFeaturesCommand, ViewCommentsCommand, 
	 AddCartCommand, ViewCartCommand, BuyCommand, ViewBuyHistory, AddCommentCommand, CompareCommand, chargeAccountCommand, ViewAllOffersByAdmin,
	 GetOfferBuyersCommand, GetAllOffersByBuyer, NotACommand};

class Store {
public:
	Store();
	void openStore(string inputCommend);
	void signup(string inputCommand);
	void login(string inputCommand);
	void import(string inputCommand);
	void offer(string inputCommand);
	void changingOffer(string inputCommand);
	void viewAccount(string inputCommand);
	void discount(string inputCommand);
	void viewOffersOnProduct(string inputCommand);
	void viewFeatures(string inputCommand);
	void viewComment(string inputCommand);
	vector<Offer*> getAllOffersFromSellers();
	void addCart(string inputCommand);
	void viewOrder(string inputCommand);
	void addComment(string inputCommand);
	void compare(string input);
	void chargeAccount(string inputCommand);
	void viewOffersByAdmin(string inputCommand);
	void logout();
	void getOfferBuyers();
	void getAllOffersByBuyer();
	bool isItAdminCommands(CommandTypes typeOfCommand);
	bool isItBuyerCommands(CommandTypes typeOfCommand);
	bool isItSellerCommands(CommandTypes typeOfCommand);
	void sellerCommands(CommandTypes typeOfCommand, string inputCommand);
	void adminCommands(CommandTypes typeOfCommand, string inputCommand);
	void buyerCommands(CommandTypes typeOfCommand, string inputCommand);
private:
	vector<Goods*> allGoods;
	vector<Seller*> sellers;
	vector<Buyer*> buyers;
	vector<string> buyerEmails;
	vector<string> sellerEmails;
	vector<string> buyerUsernames;
	vector<string> sellerUsernames;
	Admin* admin;
	int numberOfOffers;
	int numberOfMembers;
	int productNumber;
	int cartId;
	bool loggedInMember;
	bool loggedInAdmin;
	int indexOfLoggedInSeller;
	int indexOfLoggesInBuyer;
};


#endif