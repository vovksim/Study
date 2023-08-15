#include <iostream>
#include <map>
#include <string>

using namespace std;
template<typename keyType, typename valueType>
valueType& GetRefStrict(map<keyType, valueType>& const map, keyType key) {
	if (map.find(key) == map.end()) {
		throw std::exception("runmtime error");
	}
	return map[key];
}


int main() {
	map<int, string> map = { {0, "value"} };
	try {
		string& item = GetRefStrict(map, 0);
		item = "newvalue";
		cout << map[0] << endl;
	}
	catch (exception& a) {
		cout << a.what() << endl;
	}
	return 0;
}
