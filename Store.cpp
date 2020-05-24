#include "Store.hpp"

using namespace std;

Store::Store() {
	productNumber = 1;
	loggedInMember = 1;
	numberOfMembers = 1;
	admin = new Admin;
	loggedInAdmin = 1;
	indexOfLoggesInBuyer = -1;
	indexOfLoggedInSeller = -1;
	numberOfOffers = 1;
	cartId = 1;
}

vector<string> wordsOfCommand(string str) 
{ 
    vector<string> strings; 
    string word;  
    stringstream iss(str);  
    while (iss >> word) {    
        strings.push_back(word);
    }
    return strings;
}

bool isItLoginCommand(string inputCommand) {
    size_t firstSpace = inputCommand.find(" ");
    if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
        return false;
    }
    size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
    if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != LOGIN){
        return false;
    }
    size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
    if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
    	throw BadRequestException();
        return false;
    }
    vector<string> strings = wordsOfCommand(inputCommand);
    if(strings[3] != EMAIL) {
    	throw BadRequestException();
        return false;
    }
    if(strings[5] != PASSWORD) {
    	throw BadRequestException();
        return false;
    }
    if(strings.size() != 7) {
    	throw BadRequestException();
        return false;
    }
    return true;
}

bool isItLogoutCommand(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}
	if(inputCommand.substr(firstSpace+1) != LOGOUT) {
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[1] != LOGOUT) {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 2) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItSignupCommand(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != SIGNUP){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != EMAIL) {
		throw BadRequestException();
		return false;
	}
	if(strings[5] != USERNAME) {
		throw BadRequestException();
		return false;
	}
	if(strings[7] != PASSWORD) {
		throw BadRequestException();
		return false;
	}
	if(strings[9] != TYPE && strings.size() == 11) {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 9 && strings.size() != 11) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItImportCommand(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != IMPORT){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != TYPE) {
		throw BadRequestException();
		return false;
	}
	if(strings[5] != FILEPATH) {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 7) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItViewSellersOffer(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != OFFERS){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	return true;	
}

bool isItViewStoreProducts(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	if(inputCommand.substr(firstSpace+1) != GET_PRODUCTS){
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings.size() != 2) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItOfferCommand(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != GIVE_OFFER){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != PRODUCT_ID) {
		throw BadRequestException();
		return false;
	}
	if(strings[5] != OFFERUNITPRICE) {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 9) {
		throw BadRequestException();
		return false;
	}
	return true;	
}

bool isItViewOwnOffer(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	if(inputCommand.substr(firstSpace+1) != GET_MY_OFFER){
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings.size() != 2) {
		throw BadRequestException();
		return false;
	}
	if(strings[1] != GET_MY_OFFER) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItChangeOffer(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != CHANGE_OFFER){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != OFFER_ID) {
		throw BadRequestException();
		return false;
	}
	if(strings[5] != OFFERUNITPRICE) {
		throw BadRequestException();
		return false;
	}
	if(strings[7] != AMOUNT) {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 9) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItViewAccount(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != WALLET){
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[2] != QUESTION_MARK) {
		throw BadRequestException();
		return false;
	}
	if(strings[3] != "count") {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 5) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItDicount(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != DISCOUNT){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != OFFER_ID) {
		throw BadRequestException();
		return false;
	}
	if(strings[5] != "discountPercent") {
		throw BadRequestException();
		return false;
	}
	if(strings[7] != "discountNumber") {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 9) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItViewOffersOnProduct(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != OFFERS_ON_PRODUCT){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != PRODUCT_ID) {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 5) {
		throw BadRequestException();
		return false;
	}
	return true;	
}

bool isItViewFeatures(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != DETAIL){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != PRODUCT_ID) {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 5) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItViewComment(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != COMMENTS){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != PRODUCT_ID) {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 5) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItAddCart(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != ADD_TO_CART){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != OFFER_ID) {
		throw BadRequestException();
		return false;
	}
	if(strings[5] != "amount") {
		throw BadRequestException();
		return false;
	}
	if(strings[7] != "discountCode" && strings.size() == 9) {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 7 && strings.size() != 9) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItViewCart(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	if(inputCommand.substr(firstSpace+1) != CART){
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings.size() != 2) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItBuyCommand(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}
	if(inputCommand.substr(firstSpace+1) != SUBMIT_CART){
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings.size() != 2) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItViewBuyHistory(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != ORDERS){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != "count") {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 5) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItCompareCommand(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != COMPARE){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != "productId1") {
		throw BadRequestException();
		return false;
	}
	if(strings[5] != "productId2") {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 7) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isItAddComment(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != COMMENT){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != "productId") {  
		throw BadRequestException();
		return false;
	}
	if(strings[5] != "comment") {
		throw BadRequestException();
		return false;
	}
	return true;	
}

bool isItChargeAccount(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != CHARGE_WALLET){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != "amount") {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 5) {
		throw BadRequestException();
		return false;
	}
	return true;	
}

bool isItViewOffersByAdminCommand(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
	if(secondSpace == string::npos || inputCommand.substr(firstSpace+1, secondSpace - firstSpace -1) != OFFERS){
		return false;
	}
	size_t thirdSpace = inputCommand.find(" ", secondSpace + 1);
	if(thirdSpace == string::npos || inputCommand.substr(secondSpace+1, 1) != QUESTION_MARK){
		throw BadRequestException();
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings[3] != "order") {
		throw BadRequestException();
		return false;
	}
	if(strings[5] != "field") {
		throw BadRequestException();
		return false;
	}
	if(strings.size() != 7) {
		throw BadRequestException();
		return false;
	}
	return true;	
}

bool isItGetOfferBuyerBySeller(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	if(inputCommand.substr(firstSpace+1) != "offerBuyers"){
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings.size() != 2) {
		throw BadRequestException();
		return false;
	}
	return true;	
}

bool isItGetAllOffersByBuyer(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET) {
		return false;
	}
	if(inputCommand.substr(firstSpace+1) != "offers"){
		return false;
	}
	vector<string> strings = wordsOfCommand(inputCommand);
	if(strings.size() != 2) {
		throw BadRequestException();
		return false;
	}
	return true;
}

bool isGetOrPostInCommand(string inputCommand) {
	size_t firstSpace = inputCommand.find(" ");
	if(firstSpace == string::npos || inputCommand.substr(0, firstSpace) != GET && inputCommand.substr(0, firstSpace) != POST) {
		return false;
	}	
	return true;
}

CommandTypes isStartingOrEndingCommand(string inputCommand) {
	if(isItLoginCommand(inputCommand))
		return LoginCommand;
	else if(isItLogoutCommand(inputCommand))
		return LogoutCommand;
	else if(isItSignupCommand(inputCommand)) 
		return SignupCommand;
	else
		return NotACommand;
}

CommandTypes isAdminCommandType(string inputCommand) {
	if(isItImportCommand(inputCommand))
		return ImportCommand;
	else if(isItViewOffersByAdminCommand(inputCommand))
		return ViewAllOffersByAdmin;
	else
		return NotACommand;
}

CommandTypes isSellerCommandType(string inputCommand) {
	if(isItViewStoreProducts(inputCommand))
		return ViewStoreProductsCommand;
	else if(isItOfferCommand(inputCommand))
		return OfferCommand;
	else if(isItViewOwnOffer(inputCommand)) 
		return ViewOwnOfferCommand;
	else if(isItChangeOffer(inputCommand)) 
		return ChangeOfferCommand;
	else if(isItViewAccount(inputCommand)) 
		return ViewAccountCommand;
	else if(isItDicount(inputCommand))
		return DiscountCommand;
	else
		return NotACommand;
}

CommandTypes isItBuyerCommandType(string inputCommand) {
	if(isItViewOffersOnProduct(inputCommand))
		return ViewOffersOnProductCommand;
	else if(isItViewFeatures(inputCommand))
		return ViewFeaturesCommand;
	else if(isItViewComment(inputCommand))
		return ViewCommentsCommand;
	else if(isItAddCart(inputCommand))
		return AddCartCommand;
	else if(isItViewCart(inputCommand))
		return ViewCartCommand;
	else if(isItBuyCommand(inputCommand))
		return BuyCommand;
	else if(isItViewBuyHistory(inputCommand))
		return ViewBuyHistory;
	else if(isItAddComment(inputCommand))
		return AddCommentCommand;
	else if(isItCompareCommand(inputCommand))
		return CompareCommand;
	else if(isItChargeAccount(inputCommand))
		return chargeAccountCommand;
	else if(isItGetOfferBuyerBySeller(inputCommand))
		return GetOfferBuyersCommand;
	else if(isItGetAllOffersByBuyer(inputCommand))
		return GetAllOffersByBuyer;
	else
		return NotACommand;
}

CommandTypes findCommandType(string inputCommand) {
	
	CommandTypes commandsSet1 = isStartingOrEndingCommand(inputCommand);
	CommandTypes commandsSet2 = isAdminCommandType(inputCommand);
	CommandTypes commandsSet3 = isSellerCommandType(inputCommand);
	CommandTypes commandsSet4 = isItBuyerCommandType(inputCommand);
	if(commandsSet1 != NotACommand)
		return commandsSet1;
	else if(commandsSet2 != NotACommand)
		return commandsSet2;
	else if(commandsSet3 != NotACommand)
		return commandsSet3;
	else if(commandsSet4 != NotACommand)
		return commandsSet4;
	else if(!isGetOrPostInCommand(inputCommand)) {
		throw BadRequestException();
	}
	else {
		throw NotFoundException();
	}
}

string findEmail(string inputCommand) {
	size_t questionMark = inputCommand.find("?");
    if(inputCommand.substr(questionMark + 2, 5) != "email"){
        throw BadRequestException();
        return EMPTY_STRING;
    }
    size_t firstSpaceEmail = inputCommand.find(" ", questionMark + 7);
    size_t secondSpaceEmail = inputCommand.find(" ", firstSpaceEmail + 1);
    return inputCommand.substr(firstSpaceEmail + 1, secondSpaceEmail - firstSpaceEmail -1);
}

string findUserName(string inputCommand) {
	size_t usenameSpace = inputCommand.find("username");
    if(inputCommand.substr(usenameSpace, 8) != "username"){
        throw BadRequestException();
        return EMPTY_STRING;
    }
    size_t firstSpaceUsername = inputCommand.find(" ", usenameSpace + 8);
    size_t secondSpaceUsename = inputCommand.find(" ", firstSpaceUsername + 1);
    return inputCommand.substr(firstSpaceUsername + 1, secondSpaceUsename - firstSpaceUsername -1);
}

string findPassword(string inputCommand) {
    size_t passwordSpace = inputCommand.find("password");
    if(inputCommand.substr(passwordSpace, 8) != "password"){
        throw BadRequestException();
        return EMPTY_STRING;
    }
    size_t firstSpacePassword = inputCommand.find(" ", passwordSpace + 8);
    size_t secondSpacePassword = inputCommand.find(" ", firstSpacePassword + 1);
    return inputCommand.substr(firstSpacePassword + 1, secondSpacePassword - firstSpacePassword -1);
}

Role findType(string inputCommand) {
    size_t passwordSpace = inputCommand.find("password");
    size_t firstSpacePassword = inputCommand.find(" ", passwordSpace + 8);
    size_t secondSpacePassword = inputCommand.find(" ", firstSpacePassword + 1);
    string pass = inputCommand.substr(firstSpacePassword + 1, secondSpacePassword - firstSpacePassword -1);
    if(secondSpacePassword == string::npos)
        return BuyerRole; 
    else {
        size_t typeSpace = inputCommand.find("type");
        size_t firstSpaceType = inputCommand.find(" ", typeSpace + 4);
        size_t secondSpaceType = inputCommand.find(" ", firstSpaceType + 1);
        if (inputCommand.substr(firstSpaceType + 1, secondSpaceType - firstSpaceType -1) == "Buyer")
        	return BuyerRole;
        else
        	return SellerRole;
    }
}

int findIndexInVectorOfStrings(vector<string> stringVector, string stringToFind) {
	for(int i = 0; i < stringVector.size(); i++) {
		if(stringVector[i] == stringToFind)
			return i;
	}
	return -1;
}

void Store::signup(string inputCommand) {
	if(indexOfLoggesInBuyer != -1 || indexOfLoggedInSeller != -1 || loggedInAdmin != 0 || loggedInMember != 0) {
		throw PermissionDeniedException();
		return;
	}
	string username = findUserName(inputCommand);
	string password = findPassword(inputCommand);
	string email = findEmail(inputCommand);
	if(findIndexInVectorOfStrings(buyerEmails, email) != -1 || findIndexInVectorOfStrings(buyerUsernames, username) != -1 
			|| findIndexInVectorOfStrings(sellerEmails, email) != -1 || findIndexInVectorOfStrings(sellerUsernames, username) != -1) {
		throw BadRequestException();
		return;
	}
	Role role = findType(inputCommand);
	if (role == BuyerRole) {
		Buyer* newBuyer = new Buyer(username, password, email, numberOfMembers);
		numberOfMembers = numberOfMembers + 1;
		buyers.push_back(newBuyer);
		buyerEmails.push_back(email);
		buyerUsernames.push_back(username);
		loggedInMember = 1;
		indexOfLoggesInBuyer = buyers.size() - 1;
		indexOfLoggedInSeller = -1;
	}
	else {
		Seller* newSeller = new Seller(username, password, email, numberOfMembers);
		numberOfMembers = numberOfMembers + 1;
		sellers.push_back(newSeller);
		sellerEmails.push_back(email);
		sellerUsernames.push_back(username);
		loggedInMember = 1;
		indexOfLoggesInBuyer = -1;
		indexOfLoggedInSeller = sellers.size() - 1;
	}
	cout<< OK<< endl;
}

void Store::login(string inputCommand) {
	if(indexOfLoggesInBuyer != -1 || indexOfLoggedInSeller != -1 || loggedInAdmin != 0 || loggedInMember != 0) {
		throw BadRequestException();
		return;
	}
	string email = findEmail(inputCommand);
	string password = findPassword(inputCommand);
	int indexInSellers = findIndexInVectorOfStrings(sellerEmails, email);
	int indexInBuyers = findIndexInVectorOfStrings(buyerEmails, email);
	if(email == ADMIN_EMAIL && password != ADMIN_PASSWORD)
		throw BadRequestException();
	if(email == ADMIN_EMAIL && password == ADMIN_PASSWORD) {
		loggedInMember = 1;
		loggedInAdmin = 1;
		indexOfLoggedInSeller = -1;
		indexOfLoggesInBuyer = -1;
		cout<< OK<< endl;
		return;
	}
	else if(indexInSellers == -1 && indexInBuyers == -1) {
		throw BadRequestException();
		return;
	}
	else if(indexInBuyers != -1) {
		if(buyers[indexInBuyers]->checkPassword(password)) {
			loggedInMember = 1;
			indexOfLoggedInSeller = -1;
			indexOfLoggesInBuyer = indexInBuyers;
		}
	}
	else if(indexInSellers != -1) {
		if(sellers[indexInSellers]->checkPassword(password))
			loggedInMember = 1;
			indexOfLoggedInSeller = indexInSellers;
			indexOfLoggesInBuyer = -1;
	}
	cout<< OK<< endl;
}

string findTypeOfProduct(string inputCommand) {
    size_t typeSpace = inputCommand.find("type");
    if(inputCommand.substr(typeSpace, 4) != "type"){
        throw BadRequestException();
    	return EMPTY_STRING;
    }
    size_t firstSpaceUsername = inputCommand.find(" ", typeSpace + 4);
    size_t secondSpaceUsename = inputCommand.find(" ", firstSpaceUsername + 1);
    return inputCommand.substr(firstSpaceUsername + 1, secondSpaceUsename - firstSpaceUsername -1);
}

string findFilePath(string inputCommand) {
    size_t fileSpace = inputCommand.find("filePath");
    if(inputCommand.substr(fileSpace, 8) != "filePath" || inputCommand.substr(fileSpace, 9) != "filePath "){
        throw BadRequestException();
    	return EMPTY_STRING;
    }
    size_t firstSpaceFile = inputCommand.find(" ", fileSpace + 4);
    size_t secondSpaceFile = inputCommand.find(" ", firstSpaceFile + 1);
    return inputCommand.substr(firstSpaceFile + 1, secondSpaceFile - firstSpaceFile -1);
}

void Store::import(string inputCommand) {
	if(!loggedInAdmin)
		throw PermissionDeniedException();
	string filePath = findFilePath(inputCommand);
	string type = findTypeOfProduct(inputCommand);
	if(type == "mobile") {
		admin->importMobiles(filePath);
	}
	if(type == "car")
		admin->importCars(filePath);
	if(type == "tv")
		admin->importTvs(filePath);
	productNumber = admin->getNumberOfProducts();
	allGoods = admin->getAllGoods();
	cout<< OK<< endl;

}

int findProductId(string inputCommand) {
    size_t productSpace = inputCommand.find("productId");
    if(inputCommand.substr(productSpace, 9) != "productId"){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpaceProduct = inputCommand.find(" ", productSpace + 9);
    size_t secondSpaceProduct = inputCommand.find(" ", firstSpaceProduct + 1);
    return stoi(inputCommand.substr(firstSpaceProduct + 1, secondSpaceProduct - firstSpaceProduct -1));	
}

float findPrice(string inputCommand) {
    size_t priceSpace = inputCommand.find("offerUnitPrice");
    if(inputCommand.substr(priceSpace, 14) != "offerUnitPrice"){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpacePrice = inputCommand.find(" ", priceSpace + 14);
    size_t secondSpacePrice = inputCommand.find(" ", firstSpacePrice + 1);
    return atof(inputCommand.substr(firstSpacePrice + 1, secondSpacePrice - firstSpacePrice -1).c_str());
}

int findAmount(string inputCommand) {
    size_t productSpace = inputCommand.find("offerAmount");
    if(inputCommand.substr(productSpace, 11) != "offerAmount"){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpaceProduct = inputCommand.find(" ", productSpace + 11);
    size_t secondSpaceProduct = inputCommand.find(" ", firstSpaceProduct + 1);
    return stoi(inputCommand.substr(firstSpaceProduct + 1, secondSpaceProduct - firstSpaceProduct -1));
}

int findOfferId(string inputCommand) {
	string offerString = "offerId";
    size_t productSpace = inputCommand.find("offerId");
    if(inputCommand.substr(productSpace, offerString.size()) != "offerId"){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpaceProduct = inputCommand.find(" ", productSpace + offerString.size());
    size_t secondSpaceProduct = inputCommand.find(" ", firstSpaceProduct + 1);
    return stoi(inputCommand.substr(firstSpaceProduct + 1, secondSpaceProduct - firstSpaceProduct -1));	
}

int findCount(string inputCommand) {
	string count = "count";
    size_t countSpace = inputCommand.find("count");
    if(inputCommand.substr(countSpace, count.size()) != "count"){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpaceCount = inputCommand.find(" ", countSpace + count.size());
    size_t secondSpaceCount = inputCommand.find(" ", firstSpaceCount + 1);
    return stoi(inputCommand.substr(firstSpaceCount + 1, secondSpaceCount - firstSpaceCount -1));
}

void Store::offer(string inputCommand) {
	int productId = findProductId(inputCommand);
	int amount = findAmount(inputCommand);
	float price = findPrice(inputCommand);
	if( amount < 0) {
		throw BadRequestException();
		return;
	}
	if(price < 0) {
		throw BadRequestException();
		return;
	}
	int indexOfProduct = sellers[indexOfLoggedInSeller]->findIndexOfProductInAdminGoods(allGoods, productId);
	sellers[indexOfLoggedInSeller]->giveOffer(allGoods, productId, allGoods[indexOfProduct]->getName(), amount, price, numberOfOffers);
	numberOfOffers = numberOfOffers + 1;
	cout<< OK<< endl;
}

void Store::changingOffer(string inputCommand) {
	int offerId = findOfferId(inputCommand);
	float price = findPrice(inputCommand);
	int amount = findAmount(inputCommand);
	sellers[indexOfLoggedInSeller]->changeOffer(offerId, price, amount);
	cout<< OK<< endl;
}

void Store::viewAccount(string inputCommand) {
	int count = findCount(inputCommand);
	if(indexOfLoggedInSeller != -1)
		sellers[indexOfLoggedInSeller]->getAccount(count);
	if(indexOfLoggesInBuyer != -1)
		buyers[indexOfLoggesInBuyer]->getAccount(count);
}

int findDiscountPercent(string inputCommand) {
	string percent = "discountPercent";
    size_t percentSpace = inputCommand.find("discountPercent");
    if(inputCommand.substr(percentSpace, percent.size()) != "discountPercent"){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpacePercent = inputCommand.find(" ", percentSpace + percent.size());
    size_t secondSpacePercent = inputCommand.find(" ", firstSpacePercent + 1);
    return stoi(inputCommand.substr(firstSpacePercent + 1, secondSpacePercent - firstSpacePercent -1));	
}

int findDiscountNumber(string inputCommand) {
	string number = "discountNumber";
    size_t numberSpace = inputCommand.find("discountNumber");
    if(inputCommand.substr(numberSpace, number.size()) != "discountNumber"){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpaceNumber = inputCommand.find(" ", numberSpace + number.size());
    size_t secondSpaceNumber = inputCommand.find(" ", firstSpaceNumber + 1);
    return stoi(inputCommand.substr(firstSpaceNumber + 1, secondSpaceNumber - firstSpaceNumber -1));
}

void Store::discount(string inputCommand) {
	int percentage = findDiscountPercent(inputCommand);
	int discountNumber = findDiscountNumber(inputCommand);
	int offerId = findOfferId(inputCommand);
	sellers[indexOfLoggedInSeller]->generateDiscountCode(offerId, discountNumber, percentage);
}

void Store::viewOffersOnProduct(string inputCommand) {
	int productId = findProductId(inputCommand);
	buyers[indexOfLoggesInBuyer]->seeOffersForProduct(productId, allGoods);
}

void Store::viewFeatures(string inputCommand) {
	int productId = findProductId(inputCommand);
	buyers[indexOfLoggesInBuyer]->seeFeaturesOfProduct(productId, allGoods);
}	

void Store::viewComment(string inputCommand) {
	int productId = findProductId(inputCommand);
	buyers[indexOfLoggesInBuyer]->seeComments(productId, allGoods);
}

string findDiscountCode (string inputCommand) {
	string s1 = "amount";
	string s2 = "discountCode";
    size_t amountSpace = inputCommand.find(s1);
    size_t firstSpaceAmount = inputCommand.find(" ", amountSpace + s1.size());
    size_t secondSpaceAmount = inputCommand.find(" ", firstSpaceAmount + 1);
    if(secondSpaceAmount == string::npos)
        return "Not Found"; 
    else {
        size_t discountSpace = inputCommand.find(s2);
        size_t firstSpaceDiscount = inputCommand.find(" ", discountSpace + s2.size());
        size_t secondSpaceDiscount = inputCommand.find(" ", firstSpaceDiscount + 1);
        return inputCommand.substr(firstSpaceDiscount + 1, secondSpaceDiscount - firstSpaceDiscount -1);
    }
}

vector<Offer*> Store::getAllOffersFromSellers() {
	vector<Offer*> allOffers;
	for(int i = 0; i < sellers.size(); i++) {
		vector<Offer*> offer = sellers[i]->getOffers();
		for(int j = 0; j < offer.size(); j++) 
			allOffers.push_back(offer[j]);
	}
	return allOffers;
}

int findAmountOfOrder(string inputCommand) {
	string s = "amount";
    size_t productSpace = inputCommand.find(s);
    if(inputCommand.substr(productSpace, s.size()) != s){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpaceProduct = inputCommand.find(" ", productSpace + s.size());
    size_t secondSpaceProduct = inputCommand.find(" ", firstSpaceProduct + 1);
    return stoi(inputCommand.substr(firstSpaceProduct + 1, secondSpaceProduct - firstSpaceProduct -1));
}

void Store::addCart(string inputCommand) {
	string discountCode = findDiscountCode(inputCommand);
	int offerId = findOfferId(inputCommand);
	int amount = findAmountOfOrder(inputCommand);
	vector<Offer*> allOffers = getAllOffersFromSellers();
	buyers[indexOfLoggesInBuyer]->addToCart(offerId, amount, allOffers, discountCode, cartId);
	cartId = cartId + 1;
	cout<< OK<< endl;
}

void Store::viewOrder(string inputCommand) {
	int count = findCount(inputCommand);
	buyers[indexOfLoggesInBuyer]->viewOrders(count);
}
 
string findComment(string inputCommand) {
    string comment = "comment";
    size_t firstCommentSpace = inputCommand.find(comment);
    size_t SpaceComment= inputCommand.find(comment, firstCommentSpace + comment.size());
    return inputCommand.substr(SpaceComment + comment.size() + 1);
}

void Store::addComment(string inputCommand) {
	int productId = findProductId(inputCommand);
	string comment = findComment(inputCommand);
	buyers[indexOfLoggesInBuyer]->addComment(productId, comment, allGoods);
	cout<< OK<< endl;
}

int findProductId1(string inputCommand) {
	string s = "productId1";
    size_t productSpace = inputCommand.find(s);
    if(inputCommand.substr(productSpace, s.size()) != s){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpaceProduct = inputCommand.find(" ", productSpace + s.size());
    size_t secondSpaceProduct = inputCommand.find(" ", firstSpaceProduct + 1);
    return stoi(inputCommand.substr(firstSpaceProduct + 1, secondSpaceProduct - firstSpaceProduct -1));		
}

int findProductId2(string inputCommand) {
	string s = "productId2";
    size_t productSpace = inputCommand.find(s);
    if(inputCommand.substr(productSpace, s.size()) != s){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpaceProduct = inputCommand.find(" ", productSpace + s.size());
    size_t secondSpaceProduct = inputCommand.find(" ", firstSpaceProduct + 1);
    return stoi(inputCommand.substr(firstSpaceProduct + 1, secondSpaceProduct - firstSpaceProduct -1));		
}

void Store::compare(string inputCommand) {
	int productId1 = findProductId1(inputCommand);
	int productId2 = findProductId2(inputCommand);
	buyers[indexOfLoggesInBuyer]->compare(productId1, productId2, allGoods);
}

float findHowMuchToCharge(string inputCommand) {
	string s = "amount";
    size_t amountSpace = inputCommand.find(s);
    if(inputCommand.substr(amountSpace, s.size()) != s){
        throw BadRequestException();
    	return -1;
    }
    size_t firstSpace = inputCommand.find(" ", amountSpace + s.size());
    size_t secondSpace = inputCommand.find(" ", firstSpace + 1);
    return atof(inputCommand.substr(firstSpace + 1, secondSpace - firstSpace -1).c_str());
}

void Store::chargeAccount(string inputCommand) {
	float amountOfMoney = findHowMuchToCharge(inputCommand);
	buyers[indexOfLoggesInBuyer]->chargeAccount(amountOfMoney);
	cout<< OK<< endl;
}

string findOrder(string inputCommand) {
	string s = "order";
    size_t productSpace = inputCommand.find(s);
    if(inputCommand.substr(productSpace, s.size()) != s){
        throw BadRequestException();
    	return "Not Found";
    }
    size_t firstSpaceProduct = inputCommand.find(" ", productSpace + s.size());
    size_t secondSpaceProduct = inputCommand.find(" ", firstSpaceProduct + 1);
    return inputCommand.substr(firstSpaceProduct + 1, secondSpaceProduct - firstSpaceProduct -1);	
}

string findField(string inputCommand) {
	string s = "field";
    size_t productSpace = inputCommand.find(s);
    if(inputCommand.substr(productSpace, s.size()) != s){
        throw BadRequestException();
    	return "Not Found";
    }
    size_t firstSpaceProduct = inputCommand.find(" ", productSpace + s.size());
    size_t secondSpaceProduct = inputCommand.find(" ", firstSpaceProduct + 1);
    return inputCommand.substr(firstSpaceProduct + 1, secondSpaceProduct - firstSpaceProduct -1);	
}

void Store::viewOffersByAdmin(string inputCommand) {
	string field = findField(inputCommand);
	string order = findOrder(inputCommand);
	cout<< OFFERS_CONTENT<< endl;
	admin->printOffersOfSellers(order, field, getAllOffersFromSellers());
}

void Store::logout() {
	if(loggedInAdmin == 0 && loggedInMember == 0 && indexOfLoggesInBuyer == -1 && indexOfLoggedInSeller == -1) {
 		throw PermissionDeniedException();
 		return;
	}
	loggedInMember = 0;
	loggedInAdmin = 0;
	indexOfLoggedInSeller = -1;
	indexOfLoggesInBuyer = -1;
	cout<< OK<< endl;
}

void Store::getOfferBuyers() {
	if(loggedInAdmin != 0 || indexOfLoggesInBuyer != -1 || indexOfLoggedInSeller == -1) {
		throw BadRequestException();
		return;
	}
	sellers[indexOfLoggedInSeller]->printOffersBuyers();
}

void Store::getAllOffersByBuyer() {
	if(loggedInAdmin != 0 || indexOfLoggesInBuyer == -1 || indexOfLoggedInSeller != -1) {
		throw BadRequestException();
		return;
	}
	vector<Offer*> offers = getAllOffersFromSellers();	
	buyers[indexOfLoggesInBuyer]->printAllOffers(offers, allGoods);
}

bool Store::isItSellerCommands(CommandTypes typeOfCommand) {
	if(typeOfCommand == OfferCommand || typeOfCommand == ViewOwnOfferCommand)
		return true;
	if(typeOfCommand == ChangeOfferCommand  || typeOfCommand == DiscountCommand || typeOfCommand == GetOfferBuyersCommand)
		return true;
	else
		return false;
}

bool Store::isItBuyerCommands(CommandTypes typeOfCommand) {
	if(typeOfCommand == ViewOffersOnProductCommand || typeOfCommand == ViewFeaturesCommand || typeOfCommand == ViewCommentsCommand)
		return true;
	if(typeOfCommand == AddCartCommand || typeOfCommand == ViewCartCommand || typeOfCommand == BuyCommand)
		return true;
	if(typeOfCommand == ViewBuyHistory || typeOfCommand == AddCommentCommand || typeOfCommand == CompareCommand)
		return true;
	if(typeOfCommand == chargeAccountCommand || typeOfCommand == GetAllOffersByBuyer)
		return true;
	else 
		return false;
}

bool Store::isItAdminCommands(CommandTypes typeOfCommand) {
	if(typeOfCommand == ImportCommand || typeOfCommand == ViewAllOffersByAdmin)
		return true;
	else
		return false;
}

void Store::sellerCommands(CommandTypes typeOfCommand, string inputCommand) {
	if(indexOfLoggedInSeller == -1 && isItSellerCommands(typeOfCommand)) 
		throw PermissionDeniedException();

	if(typeOfCommand == OfferCommand) {
		offer(inputCommand);
	}
	if(typeOfCommand == ViewOwnOfferCommand ) {
		sellers[indexOfLoggedInSeller]->printOffers();

	}
	if(typeOfCommand == ChangeOfferCommand) {
		changingOffer(inputCommand);
	}

	if(typeOfCommand == DiscountCommand ) {
		discount(inputCommand);
	}
	if(typeOfCommand == GetOfferBuyersCommand) {
		getOfferBuyers();
	}
}

void Store::adminCommands(CommandTypes typeOfCommand, string inputCommand) {
	if(loggedInAdmin == 0 && isItAdminCommands(typeOfCommand))
		throw PermissionDeniedException();
	if(typeOfCommand == ImportCommand )
		import(inputCommand);
	if(typeOfCommand == ViewAllOffersByAdmin )
		viewOffersByAdmin(inputCommand);
}

void Store::buyerCommands(CommandTypes typeOfCommand, string inputCommand) {
	if(indexOfLoggesInBuyer == -1 && isItBuyerCommands(typeOfCommand))
		throw PermissionDeniedException();

	if(typeOfCommand == ViewOffersOnProductCommand) 
		viewOffersOnProduct(inputCommand);
	if(typeOfCommand == ViewFeaturesCommand) 
		viewFeatures(inputCommand);
	if(typeOfCommand == ViewCommentsCommand)
		viewComment(inputCommand);
	if(typeOfCommand == AddCartCommand )
		addCart(inputCommand);
	if(typeOfCommand == ViewCartCommand )
		buyers[indexOfLoggesInBuyer]->viewCart();
	if(typeOfCommand == BuyCommand )
		buyers[indexOfLoggesInBuyer]->giveOrder(getAllOffersFromSellers());
	if(typeOfCommand == ViewBuyHistory )
		viewOrder(inputCommand);
	if(typeOfCommand == AddCommentCommand)
		addComment(inputCommand);
	if(typeOfCommand == CompareCommand)
		compare(inputCommand);
	if(typeOfCommand == chargeAccountCommand)
		chargeAccount(inputCommand);
	if(typeOfCommand == GetAllOffersByBuyer) 
		getAllOffersByBuyer();
}

void Store::openStore(string inputCommand) {
	try{
		CommandTypes typeOfCommand = findCommandType(inputCommand);
		if(typeOfCommand == SignupCommand)
			signup(inputCommand);
		if(typeOfCommand == LogoutCommand)
			logout();
		if(typeOfCommand == LoginCommand)
			login(inputCommand);
		if(typeOfCommand == ViewStoreProductsCommand && loggedInAdmin == 1)
			throw PermissionDeniedException();
		if(typeOfCommand == ViewAccountCommand && loggedInAdmin == 1)
			throw PermissionDeniedException();
		if(typeOfCommand == ViewStoreProductsCommand) {
		if(indexOfLoggedInSeller != -1)
			sellers[indexOfLoggedInSeller]->printAllGoods(allGoods);
		else if(indexOfLoggesInBuyer != -1)
			buyers[indexOfLoggesInBuyer]->printAllGoods(allGoods);
		}
		if(typeOfCommand == ViewAccountCommand)
			viewAccount(inputCommand);
		buyerCommands(typeOfCommand, inputCommand);
		sellerCommands(typeOfCommand, inputCommand);
		adminCommands(typeOfCommand, inputCommand);
	} catch(exception& newException) {
		cout<< newException.what()<< endl;		
	}
}