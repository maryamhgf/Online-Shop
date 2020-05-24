#ifndef __EXCEPTIONS_HPP__
#define __EXCEPTIONS_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <exception>
#include <algorithm>
#include <stdlib.h>
#include <bits/stdc++.h> 
#include <stdio.h>


enum Role { AdminRole, SellerRole, BuyerRole};

using namespace std;
class BadRequestException: public exception {
  virtual const char* what() const throw();
};

class NotFoundException: public exception {
  virtual const char* what() const throw();
};

class PermissionDeniedException: public exception {
  virtual const char* what() const throw();
};

#endif