#include <string>
#include <iostream>
#include <iomanip>
#include <cassert>

//Trevor Withers
//Specification file for the Subscription class and Magazine struct

using namespace std;

// This struct holds the magazine information
struct Magazine
{
	string name;
	string isbn;
	char delivery;
	Magazine* link;
};

// This class holds the subscription information
class Subscription
{
public:
	Subscription(string /*distributorName*/);
	~Subscription();
	void showMagazine(ostream& /*out*/) const;
	void addMagazine(string /*name*/, string /*isbn*/, char /*delivery*/);
	void removeMagazine(string /*isbn*/);
	int getNoMagazines() const { return numMagazines; }
	string getDistributorName() const { return distributorName; }
private:
	string distributorName;
	int numMagazines;
	Magazine* firstPtr;
};