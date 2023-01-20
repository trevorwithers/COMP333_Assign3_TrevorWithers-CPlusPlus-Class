#include "Subscription.h"
// Trevor Withers
// Implementation file for the Subscription class and Magazine struct

// Constructor
Subscription::Subscription(string distributorName)
{
	// Do you need to use this-> to distinguish between the parameter and variable from the specification file?
	// 
	this->distributorName = distributorName;
	//  initializes the list to be an empty list
	
	numMagazines = 0;
	firstPtr = NULL;
}

// Destructor
Subscription::~Subscription()
{
	Magazine* walker = firstPtr;
	Magazine* stalker = NULL;

	// Delete all the magazines by walking through the list and deleting each one
	while (walker != NULL)
	{
		stalker = walker;
		walker = walker->link;
		delete stalker;
	}
}

// This function displays the magazine list and the number of magazines
void Subscription::showMagazine(ostream& out) const
{
	out << "Distributor Name: " << distributorName << endl;
	out << setw(25) << left << "Magazine Name" << setw(14) << "ISBN" << setw(14) << "Delivery Type" << endl << endl;
	Magazine* walker = firstPtr;
	
	// Display the magazine list by walking through the list untill the end is reached
	while (walker != NULL)
	{
		string deliveryType = (walker->delivery == 'D') ? "Daily" : (walker->delivery == 'W') ? "Weekly" : (walker->delivery == 'M') ? "Monthly" : "Monthly";
		out << setw(25) << left << walker->name << setw(14) << walker->isbn << setw(14) << deliveryType << endl;
		walker = walker->link;
	}
	out <<endl << "# of magazines = " << numMagazines << endl;
}

// This function adds a magazine to the list
void Subscription::addMagazine(string pName, string pIsbn, char pDelivery)
{
	Magazine* builder = new Magazine;
	assert(builder);
	
	// Validate the name
	while (pName == "")
	{
		cout << "Magazine name cannot be blank. Default set to 'Unknown'" << endl;
		pName = "Unknown";
	}
	builder->name = pName;
	
	// Validate the ISBN
	while (pIsbn == "")
	{
		cout << "Magazine ISBN cannot be blank. Default set to 'Unknown'" << endl;
		pIsbn = "Unknown";
	}
	builder->isbn = pIsbn;
	
	// Validate the delivery type
	while (pDelivery != 'D' && pDelivery != 'W' && pDelivery != 'M')
	{
		cout << "Invalid delivery type. Set to Default (M)." << endl;
		pDelivery = 'M';
		
	}
	builder->delivery = toupper(pDelivery);
	builder->link = NULL;
	Magazine* walker = firstPtr;
	Magazine* stalker = NULL;
	
	// Step through the list until the end is reached or the passed name is less than the current name
	while (walker != NULL && walker->name < builder->name)
	{
		stalker = walker;
		walker = walker->link;
	}

	// Walker is null if the end of the list is reached
	if (walker == NULL)
	{
		// If the list is empty, set the first pointer to the new node
		if (stalker == NULL)
		{
			firstPtr = builder;
		}
		// Otherwise, set the link of the last node to the new node
		else
		{
			stalker->link = builder;
		}
		numMagazines++;
		cout << "Magazine added." << endl;
	}
	// If the passed name is equal to the current name, display an error message
	else if (walker->name == builder->name)
	{
		cout << "This magazine is already in the list." << endl;
		delete builder;
	}
	// If the passed name is less than the current name, insert the new node before the current node
	else
	{
		// If stalker is null, the new node is the first node
		if (stalker == NULL)
		{
			firstPtr = builder;
		}
		// Otherwise, set the link of the previous node to the new node
		else
		{
			stalker->link = builder;
		}
		
		// Set the link of the new node to the current node
		builder->link = walker;
		numMagazines++;
		cout << "Magazine added." << endl;
	}
}

// This function removes a magazine from the list
void Subscription::removeMagazine(string isbn)
{
	Magazine* walker = firstPtr;
	Magazine* stalker = NULL;

	// Step through the list until the end is reached or the passed ISBN is found
	while (walker != NULL && walker->isbn != isbn)
	{
		stalker = walker;
		walker = walker->link;
	}
	
	// If the end of the list is reached, display an error message
	if (walker == NULL)
	{
		cout << "The magazine with ISBN " << isbn << " was not found." << endl;
	}
	// Otherwise, remove the node
	else
	{
		// If stalker is null, the node to be removed is the first node
		if (stalker == NULL)
		{
			firstPtr = walker->link;
		}
		// Otherwise, set the link of the previous node to the link of the current node
		else
		{
			stalker->link = walker->link;
		}
		delete walker;
		numMagazines--;
		cout << "Magazine removed." << endl;
	}
}