#include "Exceptions.hpp"

using namespace std;

const char* BadRequestException::what() const throw() {
    return "Bad Request" ;
}

const char* NotFoundException::what() const throw() {
    return "Not Found" ;
}

const char* PermissionDeniedException::what() const throw() {
    return "Permission Denied" ;
}