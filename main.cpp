#include "Store.hpp"

int main() {
	Store store;
	string input;
	int i = 1;
	while(getline(cin, input)) {
		store.openStore(input);
	}
}