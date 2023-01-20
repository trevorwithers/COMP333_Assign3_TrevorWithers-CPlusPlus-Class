#include "Subscription.h"

// Trevor Withers
// Client code for the Subscription class
int main()
{
	// Create a subscription
	Subscription* subscription = new Subscription("Trevor Withers");
	assert(subscription);
	cout << "Distributor Name: " << subscription->getDistributorName() << endl << "Number of Magazines: " << subscription->getNoMagazines() << endl << endl;
	
	// Add magazines to the subscription
	subscription->addMagazine("The New York Times", "1234567890123", 'D');
	subscription->addMagazine("The Wall Street Journal", "1234567890124", 'W');
	subscription->addMagazine("The Washington Post", "1234567890125", 'M');
	subscription->addMagazine("Life", "1234567890126", 'D');
	subscription->addMagazine("Time", "1234567890127", 'M');
	subscription->addMagazine("Time", "1234567890127", 'W');
	subscription->addMagazine("Sports Illustrated", "1234567890128", 'M');
	subscription->addMagazine("The New Yorker", "1234567890129", 'D');
	subscription->addMagazine("The Atlantic", "1234567890130", 'D');
	subscription->addMagazine("The Economist", "1234567890131", 'W');

	// Display the subscription
	subscription->showMagazine(cout);

	// Remove magazines from the subscription
	subscription->removeMagazine("1234567890126");
	subscription->removeMagazine("1234567890131");
	subscription->removeMagazine("1234567890127");

	// Display the subscription
	subscription->showMagazine(cout);

	// Delete the subscription
	delete subscription;
	
	system("pause");
	
}
/*
	Distributor Name: Trevor Withers
	Number of Magazines: 0

	Magazine added.
	Magazine added.
	Magazine added.
	Magazine added.
	Magazine added.
	This magazine is already in the list.
	Magazine added.
	Magazine added.
	Magazine added.
	Magazine added.
	Distributor Name: Trevor Withers
	Magazine Name            ISBN          Delivery Type

	Life                     1234567890126 Daily
	Sports Illustrated       1234567890128 Monthly
	The Atlantic             1234567890130 Daily
	The Economist            1234567890131 Weekly
	The New York Times       1234567890123 Daily
	The New Yorker           1234567890129 Daily
	The Wall Street Journal  1234567890124 Weekly
	The Washington Post      1234567890125 Monthly
	Time                     1234567890127 Monthly

	# of magazines = 9
	Magazine removed.
	Magazine removed.
	Magazine removed.
	Distributor Name: Trevor Withers
	Magazine Name            ISBN          Delivery Type

	Sports Illustrated       1234567890128 Monthly
	The Atlantic             1234567890130 Daily
	The New York Times       1234567890123 Daily
	The New Yorker           1234567890129 Daily
	The Wall Street Journal  1234567890124 Weekly
	The Washington Post      1234567890125 Monthly

	# of magazines = 6
	Press any key to continue . . .

	C:\Users\withe\OneDrive - St. Lawrence College\Documents\School\St. Lawrence\Year 2\Semester 1\Comp 333\COMP333_Assign3_TrevorWithers\x64\Debug\COMP333_Assign3_TrevorWithers.exe (process 26120) exited with code 0.
	To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
	Press any key to close this window . . .
*/