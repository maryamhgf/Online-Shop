#include "Members.hpp"

using namespace std;

Member::Member(string _username, string _password, string _email, int _id, Role _type) {
	username = _username;
	password = _password;
	email = _email;
	type = _type;
	account.push_back(0);
	id = _id;
}

void Member::printAllGoods(vector<Goods*> allGoods) {
	cout<< ALL_GOODS_CONTENT<< endl;
	for(int i = 0; i < allGoods.size(); i++)
		cout<< allGoods[i]->getProductId()<< COULMN_DELIMITER<< allGoods[i]->getName()<< endl;
}


void Member::getAccount(int count) {
	if(count > account.size()) 
		count = account.size();
	cout<< CREDIT_CONTENT<< endl;
	int numberOfCredit = account.size() - 1 - count;
	for(int i = account.size() - 1; i > numberOfCredit; i--) {
		cout<< account[i]<< endl;
	}
}

bool Member::checkPassword(string passwordToCheck) {
	if(passwordToCheck == password)
		return true;
	throw BadRequestException();
	return false;
}


Admin::Admin(): Member("admin", "admin", "admin@admin.com", 0, AdminRole) {
	numberOfProducts = 0;
}


void printOfferInformationForAdmin(Offer* offer) {
	cout<< offer->productId<< COULMN_DELIMITER<<offer->offerId<< COULMN_DELIMITER<<offer->price<< COULMN_DELIMITER<<offer->amount<< endl;
}

void decreaseAmount(Offer* offer,int soldAmount) {
	if(soldAmount > offer->amount)
		throw BadRequestException();
	offer->amount = offer->amount - soldAmount;
}
void printOfferInforamtion(Offer* offer) {
	cout<< offer->offerId<< COULMN_DELIMITER<< offer->price<< COULMN_DELIMITER<< offer->amount;
}
int indexOfDiscount(Offer* offer,string discountCode) {
	for(int i = 0; i < offer->discountCodes.size(); i++) {
		if( discountCode == offer->discountCodes[i].discountCode) 
			return i;
	}
	throw BadRequestException();
	return -1;
}

float priceAfterDiscountCode(Offer* offer,string discountCode, float oldPrice) {
	int index = indexOfDiscount(offer,discountCode);
	float newPrice = oldPrice * (1 - offer->discountCodes[index].discountPercent);
	return newPrice;
}

void eraseDiscountCode(Offer* offer,string discountCodeToErase) {
	int indexOfCode = -1;;
	for(int i = 0; i < offer->discountCodes.size(); i++) {
		if(offer->discountCodes[i].discountCode == discountCodeToErase)
			indexOfCode = i;
	}
	if(indexOfCode == -1){
		throw BadRequestException();
		return;
	} 
	offer->discountCodes.erase(offer->discountCodes.begin() + indexOfCode, offer->discountCodes.begin() + indexOfCode + 1);
}


bool compareInOrderOfferIdDescend(Offer* offer1, Offer* offer2) {
	if(offer1->offerId > offer2->offerId)
		return true;
	return false;
}

bool compareInOrderOfferIdAscend(Offer* offer1, Offer* offer2) {
	if(offer1->offerId < offer2->offerId)
		return true;
	return false;
}

bool compareInOrderPriceDescend(Offer* offer1, Offer* offer2) {
	if(offer1->price > offer2->price)
		return true;
	return false;
}

bool compareInOrderPriceAscend(Offer* offer1, Offer* offer2) {
	if(offer1->price < offer2->price)
		return true;
	return false;
}

void swap(Offer* a, Offer* b)
{
    Offer* temp = a;
    a = b;
    b = temp;
}

int maxIndexInOrderOfOfferId(vector<Offer*> offers, int i)
{
    if (i == offers.size() - 1)
        return i;

    int maxIndxRest = maxIndexInOrderOfOfferId(offers, i + 1);
    if (offers[i]->offerId > offers[maxIndxRest]->offerId)
        return i;
    else
        return maxIndxRest;
}

void SortDescentOfferId(vector<Offer*>& offers, int i)
{
    if (i == offers.size())
        return;
    int j = maxIndexInOrderOfOfferId(offers, i);
    swap(offers[i], offers[j]);
    SortDescentOfferId(offers, i + 1);    
}

int minIndexInOrderOfOfferId(vector<Offer*> offers, int i)
{
    if (i == offers.size() - 1)
        return i;

    int minIndxRest = minIndexInOrderOfOfferId(offers, i + 1);
    if (offers[i]->offerId < offers[minIndxRest]->offerId)
        return i;
    else
        return minIndxRest;
}

void SortAscentOfferId(vector<Offer*>& offers, int i)
{
    if (i == offers.size())
        return;
    int j = minIndexInOrderOfOfferId(offers, i);
    swap(offers[i], offers[j]);
    SortAscentOfferId(offers, i + 1);    
}

int minIndexInOrderOfPrice(vector<Offer*> offers, int i)
{
    if (i == offers.size() - 1)
        return i;

    int minIndxRest = minIndexInOrderOfPrice(offers, i + 1);
    if (offers[i]->price < offers[minIndxRest]->price)
        return i;
    else
        return minIndxRest;
}

void SortAscentOfferPrice(vector<Offer*>& offers, int i)
{
    if (i == offers.size())
        return;
    int j = minIndexInOrderOfPrice(offers, i);
    swap(offers[i], offers[j]);
    SortAscentOfferPrice(offers, i + 1);    
}

void printAscendOrderOfferIdField(vector<Offer*> offers) {
	vector<Offer*> copyOfOffers = offers;
	sort(copyOfOffers.begin(), copyOfOffers.end(), compareInOrderOfferIdAscend);
	for(int i = 0; i < copyOfOffers.size(); i++) 
		printOfferInformationForAdmin(copyOfOffers[i]);
}

void printAscendOrderOfferPriceField(vector<Offer*> offers) {
	vector<Offer*> copyOfOffers = offers;
	sort(copyOfOffers.begin(), copyOfOffers.end(), compareInOrderPriceAscend);
	for(int i = 0; i < copyOfOffers.size(); i++) 
		printOfferInformationForAdmin(copyOfOffers[i]);	
}

void printDescendOrderOfferIdField(vector<Offer*> offers) {
	vector<Offer*> copyOfOffers = offers;
	sort(copyOfOffers.begin(), copyOfOffers.end(), compareInOrderOfferIdDescend);
	for(int i = 0; i < copyOfOffers.size(); i++) 
		printOfferInformationForAdmin(copyOfOffers[i]);
}

void printDescendOrderOfferPriceField(vector<Offer*> offers) {
	vector<Offer*> copyOfOffers = offers;
	sort(copyOfOffers.begin(), copyOfOffers.end(), compareInOrderPriceDescend);
	for(int i = 0; i < copyOfOffers.size(); i++) 
		printOfferInformationForAdmin(copyOfOffers[i]);	
}

void Admin::printOffersOfSellers(string order, string field, vector<Offer*> offers) {
	if(order == ASCEND && field == OFFER_ID){
		printAscendOrderOfferIdField(offers);
	}
	else if(order == ASCEND && field == OFFER_PRICE) {
		printAscendOrderOfferPriceField(offers);
	}
	else if(order == DESCEND && field == OFFER_ID) {
		printDescendOrderOfferIdField(offers);
	}
	else if(order == DESCEND && field == OFFER_PRICE) {
		printDescendOrderOfferPriceField(offers);
	}
}

vector<Goods*> Admin::findOfferedGoods() {
	vector<Goods*> offeredGoods;
	for(int i = 0; i < allGoods.size(); i++) {
		if(allGoods[i]->getAllOffers().size() != 0 ) 
			offeredGoods.push_back(allGoods[i]);
	}
	return offeredGoods;
}

void Admin::printAllGoods() {
	cout<< ALL_GOODS_CONTENT<< endl;
	for(int i = 0; i < allGoods.size(); i++) 
		cout<< allGoods[i]->getProductId()<< allGoods[i]->getName()<< endl;
}

void Admin::importTvs(string tvFilename) {
	fstream inputFile;
	inputFile.open(tvFilename, ios::in);
	if(!inputFile.is_open()){
		throw NotFoundException();
		return;
	}
	string temp, word;
	getline(inputFile, temp);
	while(getline(inputFile, temp)){
		stringstream s(temp);
		vector<string> infOfOneTv;
		while(getline(s, word, CSV_FILE_DELIMITER)) {
			infOfOneTv.push_back(word);
		}
		numberOfProducts++;
		addNewTv(infOfOneTv, numberOfProducts);
	}
}

void Admin::importCars(string carFilename) {
	fstream inputFile;
	inputFile.open(carFilename, ios::in);
	if(!inputFile.is_open()){
		throw NotFoundException();
		return;
	}
	string temp, word;
	getline(inputFile, temp);
	while(getline(inputFile, temp)){
		stringstream s(temp);
		vector<string> infOfOneCar;
		while(getline(s, word, CSV_FILE_DELIMITER)) {
			infOfOneCar.push_back(word);
		}
		numberOfProducts++;
		addNewCar(infOfOneCar, numberOfProducts);
	}
}

void Admin::addNewMobile(vector<string> infOfNewMobile, int productId) {
	string name = infOfNewMobile[0];
	int weight = stoi(infOfNewMobile[1]);
	int frequency = stoi(infOfNewMobile[2]);
	int builtInMemory = stoi(infOfNewMobile[3]);
	int RAM = stoi(infOfNewMobile[4]);
	int displaySize = stoi(infOfNewMobile[5]);
	int cameraResolution = stoi(infOfNewMobile[6]);
	string operatingSystem = infOfNewMobile[7];
	Mobile* newMobile = new Mobile(name, productId, weight, frequency, builtInMemory, RAM, displaySize, cameraResolution, operatingSystem);
	mobiles.push_back(newMobile);
	allGoods.push_back(newMobile);
}

void Admin::importMobiles(string mobileFilename) {
	fstream inputFile;
	inputFile.open(mobileFilename, ios::in);
	if(!inputFile.is_open()){
		throw NotFoundException();
		return;
	}
	string temp, word;
	getline(inputFile, temp);
	while(getline(inputFile, temp)){
		stringstream s(temp);
		vector<string> infOfOneMobile;
		while(getline(s, word, CSV_FILE_DELIMITER)) {
			if(word[word.size()-1] == '\r') {
				word = word.substr(0, word.size() - 1);
			}
			infOfOneMobile.push_back(word);
		}
		numberOfProducts = numberOfProducts + 1;
		addNewMobile(infOfOneMobile, numberOfProducts);
	}
}

void Admin::addNewTv(vector<string> infOfNewTv, int productId) {
	string name = infOfNewTv[0];
	int screenSize = stoi(infOfNewTv[1]);
	string screenType = infOfNewTv[2];
	string reselution = infOfNewTv[3];
	bool threeD = stoi(infOfNewTv[4]);
	bool HDR = stoi(infOfNewTv[5]);
	TV* newTv = new TV(name, productId, screenSize, screenType, reselution, threeD, HDR);
	tvs.push_back(newTv);
	allGoods.push_back(newTv);
}

void Admin::addNewCar(vector<string> infOfNewCar, int productId) {
	string name = infOfNewCar[0];
	int weight = stoi(infOfNewCar[1]);
	int numberOfSeats = stoi(infOfNewCar[2]);
	int numberOfCylinders = stoi(infOfNewCar[3]);
	int engineCapacity = stoi(infOfNewCar[4]);
	bool reverseParkingSensor = stoi(infOfNewCar[5]);
	Car* newCar = new Car(name, productId, weight, numberOfSeats, numberOfCylinders, engineCapacity, reverseParkingSensor);
	cars.push_back(newCar);
	allGoods.push_back(newCar);
}



Seller::Seller(string _usename, string _password, string _email, int _id): Member(_usename, _password, _email, _id, SellerRole) { 

}

void Seller::printInforamtionOfOfferBasedOnBuyer(string buyerName) {
	for(int i = 0; i < givenOffers.size(); i++) {
		if(buyerName == givenOffers[i]->buyerName) {
			cout<< givenOffers[i]->productId<< COULMN_DELIMITER<< givenOffers[i]->offerId<< COULMN_DELIMITER;
			cout<< givenOffers[i]->idOfBuyer<< COULMN_DELIMITER<< givenOffers[i]->soldPrice<<endl; 
		}
	}
}

void Seller::printOffersBuyers() {
	cout<< OFFER_BUYER_CONTENT<< endl;
	for(int i = buyers.size() - 1; i >= 0; i--) {
		printInforamtionOfOfferBasedOnBuyer(buyers[i]);
	}
}




void Seller::updateBuyers(string buyer) {
	buyers.push_back(buyer);
}

void Seller::updateSellerAccount(float cash, int amount) {
	float lastAccountCash = account.back();
	account.push_back(lastAccountCash + cash * amount);
}

int Seller::findIndexOfProductInAdminGoods(vector<Goods*> allGoods, int productId) {
	for(int i = 0; i < allGoods.size(); i++ ) {
		if(allGoods[i]->getProductId() == productId){
			return i;
		}
	}
	throw BadRequestException();
	return -1;
}

void Seller::checkExistedOffer(int productId) {
	for(int i = 0; i < givenOffers.size(); i++) {
		if(givenOffers[i]->productId == productId) {
			throw BadRequestException();
		}
	}
} 

int Seller::findIndexOfOfferBaseOnOfferId(int offerId) {
	for(int i = 0; i < givenOffers.size(); i++) {
		if(givenOffers[i]->offerId == offerId) 
			return i;
	}
	throw BadRequestException();
	return -1;	
}

void Seller::giveOffer(vector<Goods*> allGoods, int productId, string productName, int amount, float price, int offerId) {
	try{
		int indexOfProductInGoods = findIndexOfProductInAdminGoods(allGoods, productId);
		checkExistedOffer(productId);
		Offer* newOffer = new Offer;
		newOffer->amount = amount;
		newOffer->price = price;
		newOffer->offerId = offerId;
		newOffer->productId = productId;
		newOffer->productName = productName;
		newOffer->seller = this;
		allGoods[indexOfProductInGoods]->setOffer(newOffer);
		givenOffers.push_back(newOffer);
		goodsForSell.push_back(allGoods[indexOfProductInGoods]);
	} catch(exception& newException) {
		throw BadRequestException();
	}
}
void Seller::printOffers() {
	cout<< OFFERS_CONTENT<< endl;
	for(int i = 0; i < givenOffers.size() ; i++) 
		cout<< givenOffers[i]->productId << COULMN_DELIMITER<< givenOffers[i]->offerId<< COULMN_DELIMITER<< givenOffers[i]->price<< COULMN_DELIMITER<< givenOffers[i]->amount<< endl;
}


void updateOffer(Offer* offer,float newOfferPrice, int newOfferAmount) {
	offer->amount = newOfferAmount;
	offer->price = newOfferPrice;
}


void Seller::changeOffer(int offerId, float offerPrice, int offerAmount) {
	int indexOfOffer = findIndexOfOfferBaseOnOfferId(offerId);
	updateOffer(givenOffers[indexOfOffer] ,offerPrice, offerAmount);
}

void Seller::generateDiscountCode(int offerId, int Number, int percentage) {
	try{
		int indexOfOffer = findIndexOfOfferBaseOnOfferId(offerId);
		srand(time(0));
		for(int i = 0; i < Number; i++) {
			string code = to_string(rand());
			cout<< code<< endl;
			Discount newDiscount = {code, percentage};
			givenOffers[indexOfOffer]->discountCodes.push_back(newDiscount);
		}
	} catch(exception& newException) {
		cout<< newException.what()<< endl;
	}
}

Buyer::Buyer(string _usename, string _password, string _email, int _id):Member(_usename, _password, _email, _id, BuyerRole) {

}


int findProductIndex(int productId, vector<Goods*> allGoods) {
	for(int i = 0; i < allGoods.size(); i++) {
		if (allGoods[i]->getProductId() == productId)
			return i;
	}
	throw BadRequestException();
	return -1;
}

void Buyer::printAllOffers(vector<Offer*> offers, vector<Goods*> allGoods) {
	vector<Offer*> copyOfOffers = offers;
	sort(copyOfOffers.begin(), copyOfOffers.end(), compareInOrderOfferIdAscend);
	cout<< PRODUCT_CONTENT<< endl;
	for(int i = 0; i < copyOfOffers.size(); i++) {
		int indexOfProduct = findProductIndex(copyOfOffers[i]->productId, allGoods);
		allGoods[indexOfProduct]->printNameAndProductId();
		cout<< COULMN_DELIMITER;
		printOfferInforamtion(copyOfOffers[i]);
		cout<< endl;
	}


}

void Buyer::seeOffersForProduct(int productId, vector<Goods*> allGoods) {
	try{
		int indexOfProduct = findProductIndex(productId, allGoods);
		int numberOfOffers = allGoods[indexOfProduct]->getAllOffers().size();
		vector<Offer*> offersOfProduct = allGoods[indexOfProduct]->getAllOffers();
		cout<< PRODUCT_CONTENT<< endl;
		for(int i = 0; i < numberOfOffers; i++) {
			allGoods[indexOfProduct]->printNameAndProductId();
			cout<< COULMN_DELIMITER;
			printOfferInforamtion(offersOfProduct[i]);
			cout<<endl;
		} 
	} catch(exception& newException) {
		cout<< newException.what()<< endl;
	}
}

int findOfferIndex(int offerId, vector<Offer*> offers) {
	for(int i = 0; i < offers.size(); i++) {
		if(offers[i]->offerId == offerId)
			return i;
	}
	throw BadRequestException();
	return -1;
}

void Buyer::seeFeaturesOfProduct(int productId, vector<Goods*> allGoods) {
	int indexOfProduct = findProductIndex(productId, allGoods);
	allGoods[indexOfProduct]->printInformation();
}

void Buyer::seeComments(int productId, vector<Goods*> allGoods) {
	try{
		int indexOfProduct = findProductIndex(productId, allGoods);
		cout<< allGoods[indexOfProduct]->getName()<<endl;
		allGoods[indexOfProduct]->printComments();
	} catch( exception& newException) {
		cout<< newException.what()<< endl;
	}
}

void Buyer::addToCart(int offerId, int amount, vector<Offer*> offers, string discountCode, int cartId) {
	try{
		int indexOfOffer = findOfferIndex(offerId, offers);
		decreaseAmount(offers[indexOfOffer],amount);
		float soldPrice;
		if(discountCode != "Not Found" && indexOfDiscount(offers[indexOfOffer], discountCode) !=-1 ) { 
			soldPrice = priceAfterDiscountCode(offers[indexOfOffer],discountCode, offers[indexOfOffer]->price);
			eraseDiscountCode(offers[indexOfOffer],discountCode);
		}
		else
			soldPrice = offers[indexOfOffer]->price;
		Order newOrder = {offers[indexOfOffer]->productId, offerId, amount, soldPrice, cartId, offers[indexOfOffer]->seller, offers[indexOfOffer]->productName}; 
		cart.push_back(newOrder);
	} catch(exception& newException) {
		throw BadRequestException();
	}
}

void Buyer::viewCart() {
	cout<< CART_CONTENT<< endl;
	for(int i = cart.size() - 1; i >= 0; i--) {
		cout<< cart[i].productId<< COULMN_DELIMITER<< cart[i].productName<< COULMN_DELIMITER<< cart[i].offerId<< COULMN_DELIMITER;
		cout<< cart[i].seller->giveId()<< COULMN_DELIMITER<< cart[i].price<< COULMN_DELIMITER<< cart[i].amount<< endl;
	}
	if(cart.size() == 0)
		cout<<"Empty"<< endl;
}

void Buyer::copyCartToBoughtCart() {
	for(int i = 0; i < cart.size(); i++)
		boughtCart.push_back(cart[i]);
}

void Buyer::updateSoldPrice(vector<Offer*> offers, int offerId, float soldPrice) {
	int indexOfOffer = findOfferIndex(offerId, offers);
	offers[indexOfOffer]->soldPrice = soldPrice;
}

void Buyer::updateBuyerNameAndId(vector<Offer*> offers, int offerId) {
	int indexOfOffer = findOfferIndex(offerId, offers);
	offers[indexOfOffer]->buyerName = username;
	offers[indexOfOffer]->idOfBuyer = id;
}

void Buyer::giveOrder(vector<Offer*> offers) {
	try{
		float cash = account[account.size() - 1];
		float moneyToPay = 0;
		for(int i = 0; i < cart.size(); i++) 
			moneyToPay = moneyToPay + (cart[i].price * cart[i].amount);
		if(moneyToPay > cash) {
			throw BadRequestException();
		}
		else {
			account.push_back(cash - moneyToPay);
			copyCartToBoughtCart();
			for(int i = 0; i < cart.size(); i++) {
				cart[i].seller->updateSellerAccount(cart[i].price, cart[i].amount);
				cart[i].seller->updateBuyers(username);
				updateSoldPrice(offers, cart[i].offerId, cart[i].price);
				updateBuyerNameAndId(offers, cart[i].offerId);
			}
			cart.clear();
	}
	cout<< "OK"<< endl;
	} catch(exception& newException) {
		cout<< newException.what()<< endl;
	} 
}

void Buyer::viewOrders(int count) {
	cout<< ORDER_CONTENT<< endl;
	int lastIndex = boughtCart.size() - 1;
	if(count > boughtCart.size()) 
		count = boughtCart.size();
	if(count != 0) {
		cout<< boughtCart[lastIndex].productId<< COULMN_DELIMITER<< boughtCart[lastIndex].productName<< COULMN_DELIMITER;
		cout<< boughtCart[lastIndex].offerId<< COULMN_DELIMITER<< boughtCart[lastIndex].seller->giveId()<< COULMN_DELIMITER<< boughtCart[lastIndex].price;
		cout<< COULMN_DELIMITER<<boughtCart[lastIndex].amount<< endl; 
		int numberOfShouldBePrintedElements = boughtCart.size() - 1 - count;
		for(int i =boughtCart.size()-2; i > numberOfShouldBePrintedElements; i--) {
			if(boughtCart[i].cartId != boughtCart[i+1].cartId) 
				cout<< "****"<<endl;
			cout<< boughtCart[i].productId<< COULMN_DELIMITER<< boughtCart[i].productName<< COULMN_DELIMITER<< boughtCart[i].offerId;
			cout<< COULMN_DELIMITER<< boughtCart[i].seller->giveId()<< COULMN_DELIMITER<< boughtCart[i].price<< COULMN_DELIMITER<< boughtCart[i].amount<<endl;	
		}
	}
}

void Buyer::chargeAccount(float amount) {
	if(amount <= 0){
		throw BadRequestException();
		return;
	}
	float moneyInaccount = account.back();
	account.push_back(moneyInaccount + amount);
}

void Buyer::addComment(int productId, string newComment, vector<Goods*> allGoods) {
	try{
		int index = findProductIndex(productId, allGoods);
		for(int i = 0; i< allGoods.size(); i++) {
			if(allGoods[i]->getProductId() == productId){
				Comment comment = {newComment, username};
				allGoods[i]->addComment(comment);
				return;
			}
		}
	} catch( exception& newException) {
		throw NotFoundException();
	}
}

bool checkIfTheSameKind(Goods* product1, Goods* product2) {
	if(Mobile* mobile1 = dynamic_cast<Mobile*> (product1)) {
		if(Mobile* mobile2 = dynamic_cast<Mobile*> (product2))
			return 1;
	}
	if(TV* tv1 = dynamic_cast<TV*> (product1)) {
		if(TV* tv2 = dynamic_cast<TV*> (product2))
			return 1;
	}
	if(Car* car1 = dynamic_cast<Car*> (product1)) {
		if(Car* car2 = dynamic_cast<Car*> (product2))
			return 1;
	}
	throw BadRequestException();
	return 0;	
}

int findProductIndexToCompare(int productId, vector<Goods*> allGoods) {
	for(int i = 0; i < allGoods.size(); i++) {
		if (allGoods[i]->getProductId() == productId)
			return i;
	}
	throw NotFoundException();
	return -1;
}

void Buyer::compare(int productId1, int productId2, vector<Goods*> allGoods) {
	int index1 = findProductIndexToCompare(productId1, allGoods);
	int index2 = findProductIndexToCompare(productId2, allGoods);
	if(checkIfTheSameKind(allGoods[index1], allGoods[index2])) {
		if(Mobile* mobile1 = dynamic_cast<Mobile*> (allGoods[index1])) {
			Mobile* mobile2 = dynamic_cast<Mobile*> (allGoods[index2]);
			mobile1->compareMobileProducts(mobile2);
		}
		if(TV* tv1 = dynamic_cast<TV*> (allGoods[index1])) {
			TV* tv2 = dynamic_cast<TV*> (allGoods[index2]);
			tv1->compareTVProducts(tv2);
		}
		if(Car* car1 = dynamic_cast<Car*> (allGoods[index1])) {
			Car* car2 = dynamic_cast<Car*> (allGoods[index2]);
			car1->compareCarProducts(car2);
		}
	}
	else
		throw BadRequestException();
}