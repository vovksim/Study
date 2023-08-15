#include <map>
#include <tuple>
#include <vector>
#include <iostream>
#include <string> 

using namespace std;
//-------------------------------------------------------------------------------------------------

enum class Lang
{
	DE, FR, IT
};

ostream& operator<<(ostream& out, Lang names) {
    
    switch (names) {
    case Lang::DE : {
        return out << "DE";
        }
    case Lang::FR: {
        return out << "FR";
    }
    case Lang::IT: {
        return out << "IT";
    }
    }
    return out;
}

//-------------------------------------------------------------------------------------------------

struct Region
{
	std::string std_name;
	std::string parent_std_name;
	std::map<Lang, std::string> names;
	int64_t population;
    
};

ostream& operator<<(ostream& out, map<Lang, string> names) {
    for (map<Lang, string>::iterator a = names.begin(); a != names.end(); ++a) {
        out << (*a).first << "  |  " << (*a).second << "\n";
    }
    return out;
}

ostream& operator << (ostream& out, const Region& temp) {
    out << temp.std_name << "\n" << temp.parent_std_name << "\n" << temp.population << "\n" << temp.names;
    return out;
}
//-------------------------------------------------------------------------------------------------
bool operator<(const Region& lhs, const Region& rhs)
{
	return std::tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
		std::tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}
//-------------------------------------------------------------------------------------------------
int FindMaxRepetitionCount(const vector<Region>& regions)
{
	int result = 0;
    map<Region, int> repetition_count;
    for (const Region& region : regions)
    {   
        repetition_count[region];
        cout << region << endl;
    }
    cout << " \n Ending map size : " << repetition_count.size() << endl;
    return 0;
}


int main()
{
    std::cout << FindMaxRepetitionCount({
     {
         "Moscow",
         "Russia",
         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
         89
     }, {
         "Russia",
         "Eurasia",
         {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
         89
     }, {
         "Moscow",
         "Russia",
         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
         89
     }, {
         "Moscow",
         "Russia",
         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
         89
     }, {
         "Russia",
         "Eurasia",
         {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
         89
     },
        }) << std::endl;

    std::cout << FindMaxRepetitionCount({
        {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Russia",
            "Eurasia",
            {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Toulouse",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            89
        }, {
            "Moscow",
            "Russia",
            {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
            31
        },
        }) << std::endl;

    return 0;
}