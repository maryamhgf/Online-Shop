# Online-Shop-Domain-
Implementation domain of mobile, car, and TV online shop in C++.

***You can see all commands in the in.txt file and all outputs in out.txt file***

There are three main role in this shop: admin, sellers, and buyers. Admin can put cars, mobiles, TVs available in the shop. Sellers can offer amount and prices on available products or give discount codes to buyers. Buyers can see all products and offered prices, then buy them. Also, they should charge their accounts.

1. Products: There are three types: mobiles, cars, and TVs. All information about them are in .csv files.

2. Admin: admin dousn't need to sign up. To login, the username is "admin" and the password is "admin@admin.com".
 
  Commands:
  
  2.1. POST importProducts ? type<mobile|tv|car>filePath<filePath> -> output: OK|Not Found
  
  2.2. GET offers ? order <ASCEND/DESCEND> field <offerId/offerPrice> -> output: productId | offerId | offerUnitPrice | 
  offerAmount
  
  Admin can see all offers on a product on ascend or descend offerId or offerPrice order.
  
3. Seller: new sellers sould signup first then sign in.

  commands:
  
  3.1. POST signup ? email <email> username <username> password <password> type <seller> 
  
   -> output: OK | Basd Request
  
  3.2. POST login ? email <email> password <password> -> output: OK | Bad Request
  
  3.3. POST logout -> output: OK | Permission Denied
  
  3.4. GET getProducts -> output: productId | productName
      
  Seller can see all available products in shop to offer price and amount.
  
  3.5. POST offer ? productId <productId> offerUnitPrice <offerUnitPrice> offerAmount <offerAmount> 
  
  3.6. GET myOffers -> output: productId | offerUnitPrice | offerAmount
      
  Seller can see all her/his offers.
        
  3.7. POST changeOffer ? offerId <offerId> offerUnitPrice <offerUnitPrice> offerAmount <offerAmount>
      
  Seller can change the offer.
  
  3.8. GET wallet ? count <count> -> output: credit
  
  Seller can see all changes in the wallet.
      
  3.9. POST generateDiscountCode ? offerId <offerId> dicountPercent <discountPercent> discountNumber                                      
                                                    discountNumber -> output: dicountCodes

4. Buyer: new buyers sould signup first then login.

  Commands:
  
  4.1. POST signup ? email <email> username <username> password <password> type <Buyer> 
      
   -> output: OK | Basd Request
      
   or: POST signup ? email <email> username <username> password <password>
  
  4.2. POST login ? email <email> password <password> -> output: OK | Bad Request
  
  4.3. GET getProducts -> output: productId | productName
  
  4.4. GET offersOnProduct ? productId <productId> -> output: productId | productName | offerId | offerUnitPrice | 
  offerAmount
  
  4.5. GET productDetail ? productId <productId> -> output: <productName> 
                                                            <feature> : <value>
              
  4.6. GET comments ? productId <productId? -> output: <productName> 
  username | comment
                                                         
  4.7. POST addToCart ? offerId> amount <amount> [discountCode <discountCode>] -> output: OK | Bad Request
  
  
 4.8. GET cart -> output: productId | productName | offerId | sellerId | totalPriceConsideringDiscount | amount
 
 Buyer can see all products that want to buy.
      
 4.9. POST submitCart -> output: OK | Bad Request
 
 If Buyer had enough money, then by this command can buy the products in cart.
      
 4.10. GET orders ? count <count> -> output: productId | productName | offerId | sellerId | soldPrice | amount
  
 Buyer can see latest #count orders.
       
 4.11. GET wallet ? count <count> -> output: credit
  
  
 4.12. POST chargeWallet ? amount <amount> -> output: OK | Bad Request
  
  
 4.13. GET compare ? productId1 <product Id1> productId2 <productId2> -> output: productName1 | productName2
                                                                        featureName : product1Value | product2Value
                                                                      
                        

I handeled all errors and bad requests by exception handling.
  
  
  
  
