#ifndef __STRUCTS_HPP__
#define __STRUCTS_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <algorithm>
#include <stdlib.h>
#include <bits/stdc++.h> 
#include <stdio.h>
#include "Members.hpp"

using namespace std;

class Member;
class Seller;
class Buyer;
class Admin;

#define EMPTY_STRING ""
#define CSV_FILE_DELIMITER ','
#define COULMN_DELIMITER " | "
#define CONTENT "productId | offerId | offerUnitPrice | offerAmount"
#define ALL_GOODS_CONTENT "productId | productName"
#define OFFERS_CONTENT "productId | offerId | offerUnitPrice | offerAmount"
#define CREDIT_CONTENT "credit"
#define PRODUCT_CONTENT "productId | productName | offerId | offerUnitPrice | offerAmount"
#define CART_CONTENT "productId | productName | offerId | sellerId | totalPriceConsideringDiscount | amount"
#define ORDER_CONTENT "productId | productName | offerId | sellerId | soldPrice | amount"
#define POST "POST"
#define GET "GET"
#define LOGIN "login"
#define LOGOUT "logout"
#define SIGNUP "signup"
#define QUESTION_MARK "?"
#define IMPORT "importProducts"
#define OFFERS "offers"
#define GET_PRODUCTS "getProducts"
#define GIVE_OFFER "offer"
#define GET_MY_OFFER  "myOffers"
#define CHANGE_OFFER "changeOffer"
#define WALLET "wallet"
#define DISCOUNT "generateDiscountCode"
#define OFFERS_ON_PRODUCT "offersOnProduct"
#define DETAIL "productDetail"
#define COMMENTS "comments"
#define ADD_TO_CART "addToCart"
#define CART "cart"
#define SUBMIT_CART "submitCart"
#define ORDERS "orders"
#define COMPARE "compare"
#define COMMENT "comment"
#define ADMIN_EMAIL "admin@gmail.com"
#define ADMIN_PASSWORD "admin"
#define CHARGE_WALLET "chargeWallet"
#define DESCEND "DESCEND"
#define ASCEND "ASCEND"
#define OFFER_PRICE "offerPrice"
#define OFFER_ID "offerId"
#define OFFERS "offers"
#define OK "OK"
#define EMAIL "email"
#define PASSWORD "password"
#define USERNAME "username"
#define TYPE "type"
#define FILEPATH "filePath"
#define PRODUCT_ID "productId"
#define OFFERUNITPRICE "offerUnitPrice"
#define AMOUNT "offerAmount"
#define OFFER_BUYER_CONTENT "productId | offerId | buyerId | soldPrice | amount"

struct discount;
struct comment;
struct order;
struct offer;
typedef struct discount Discount;
typedef struct comment Comment;
typedef struct order Order;
typedef struct offer Offer;


#endif