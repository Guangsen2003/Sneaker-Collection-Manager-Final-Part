// Sneaker Collection Manager
// Name: Guangsen Xu
// Final Project

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;




enum SneakerBrand
{
    Nike,
    Adidas,
    Jordan,
    NewBalance,
    Puma
};

enum SneakerCondition
{
    New,
    Excellent,
    Good,
    Fair,
    Poor
};




struct Sneaker
{
    string model;
    SneakerBrand brand;
    double size;
    SneakerCondition condition;
    double purchasePrice;
    double estimatedValue;
};


const int MAX_SNEAKERS = 20;




string getBrandName(SneakerBrand brand)
{
    if (brand == Nike)
    {
        return "Nike";
    }
    else if (brand == Adidas)
    {
        return "Adidas";
    }
    else if (brand == Jordan)
    {
        return "Jordan";
    }
    else if (brand == NewBalance)
    {
        return "New Balance";
    }
    else
    {
        return "Puma";
    }
}




string getConditionName(SneakerCondition condition)
{
    if (condition == New)
    {
        return "New";
    }
    else if (condition == Excellent)
    {
        return "Excellent";
    }
    else if (condition == Good)
    {
        return "Good";
    }
    else if (condition == Fair)
    {
        return "Fair";
    }
    else
    {
        return "Poor";
    }
}




void displayMenu()
{
    cout << "========================================" << endl;
    cout << "        SNEAKER COLLECTION MANAGER" << endl;
    cout << "========================================" << endl;
    cout << "1. Add Sneaker" << endl;
    cout << "2. Display Collection" << endl;
    cout << "3. Search Collection" << endl;
    cout << "4. Sort Collection" << endl;
    cout << "5. Collection Summary" << endl;
    cout << "6. Exit" << endl;
    cout << "----------------------------------------" << endl;
    cout << "Enter selection: ";
}



void addSneaker(Sneaker Collection[], int& sneakerCount)
{
    int brandChoice;
    int conditionChoice;

    if (sneakerCount >= MAX_SNEAKERS)
    {
        cout << "Collection is full." << endl;
        return;
    }

    cout << "\nEnter information for sneaker #"
         << sneakerCount + 1 << endl;

    cout << "Enter model name: ";
    cin.ignore();
    getline(cin, Collection[sneakerCount].model);


  
    cout << "Select a brand:" << endl;
    cout << "1. Nike" << endl;
    cout << "2. Adidas" << endl;
    cout << "3. Jordan" << endl;
    cout << "4. New Balance" << endl;
    cout << "5. Puma" << endl;
    cout << "Enter selection: ";
    cin >> brandChoice;

    if (brandChoice == 1)
    {
        Collection[sneakerCount].brand = Nike;
    }
    else if (brandChoice == 2)
    {
        Collection[sneakerCount].brand = Adidas;
    }
    else if (brandChoice == 3)
    {
        Collection[sneakerCount].brand = Jordan;
    }
    else if (brandChoice == 4)
    {
        Collection[sneakerCount].brand = NewBalance;
    }
    else if (brandChoice == 5)
    {
        Collection[sneakerCount].brand = Puma;
    }
    else
    {
        cout << "Invalid brand choice." << endl;
        return;
    }


 
    cout << "Enter shoe size: ";
    cin >> Collection[sneakerCount].size;



    cout << "Select a condition:" << endl;
    cout << "1. New" << endl;
    cout << "2. Excellent" << endl;
    cout << "3. Good" << endl;
    cout << "4. Fair" << endl;
    cout << "5. Poor" << endl;
    cout << "Enter selection: ";
    cin >> conditionChoice;

    if (conditionChoice == 1)
    {
        Collection[sneakerCount].condition = New;
    }
    else if (conditionChoice == 2)
    {
        Collection[sneakerCount].condition = Excellent;
    }
    else if (conditionChoice == 3)
    {
        Collection[sneakerCount].condition = Good;
    }
    else if (conditionChoice == 4)
    {
        Collection[sneakerCount].condition = Fair;
    }
    else if (conditionChoice == 5)
    {
        Collection[sneakerCount].condition = Poor;
    }
    else
    {
        cout << "Invalid condition choice." << endl;
        return;
    }


 
    cout << "Enter purchase price: $";
    cin >> Collection[sneakerCount].purchasePrice;



    cout << "Enter estimated value: $";
    cin >> Collection[sneakerCount].estimatedValue;


    sneakerCount++;

    cout << "Sneaker added successfully!" << endl;
}



void displayCollection(const Sneaker Collection[], int sneakerCount)
{
    if (sneakerCount == 0)
    {
        cout << "Collection is empty." << endl;
        return;
    }

    cout << "\n===== SNEAKER COLLECTION =====" << endl;

    for (int i = 0; i < sneakerCount; i++)
    {
        cout << "\nSneaker #" << i + 1 << endl;

        cout << "Model: "
             << Collection[i].model << endl;

        cout << "Brand: "
             << getBrandName(Collection[i].brand) << endl;

        cout << "Size: "
             << Collection[i].size << endl;

        cout << "Condition: "
             << getConditionName(Collection[i].condition) << endl;

        cout << "Purchase Price: $"
             << fixed << setprecision(2)
             << Collection[i].purchasePrice << endl;

        cout << "Estimated Value: $"
             << Collection[i].estimatedValue << endl;
    }
}



void searchByBrand(const Sneaker Collection[], int sneakerCount)
{
    int brandChoice;
    SneakerBrand searchBrand;
    bool found = false;

    if (sneakerCount == 0)
    {
        cout << "Collection is empty." << endl;
        return;
    }

    cout << "\nSelect a brand to search:" << endl;
    cout << "1. Nike" << endl;
    cout << "2. Adidas" << endl;
    cout << "3. Jordan" << endl;
    cout << "4. New Balance" << endl;
    cout << "5. Puma" << endl;
    cout << "Enter selection: ";
    cin >> brandChoice;

    if (brandChoice == 1)
    {
        searchBrand = Nike;
    }
    else if (brandChoice == 2)
    {
        searchBrand = Adidas;
    }
    else if (brandChoice == 3)
    {
        searchBrand = Jordan;
    }
    else if (brandChoice == 4)
    {
        searchBrand = NewBalance;
    }
    else if (brandChoice == 5)
    {
        searchBrand = Puma;
    }
    else
    {
        cout << "Invalid brand choice." << endl;
        return;
    }


    for (int i = 0; i < sneakerCount; i++)
    {
        if (Collection[i].brand == searchBrand)
        {
            cout << "\nModel: "
                 << Collection[i].model << endl;

            cout << "Brand: "
                 << getBrandName(Collection[i].brand) << endl;

            cout << "Size: "
                 << Collection[i].size << endl;

            cout << "Condition: "
                 << getConditionName(Collection[i].condition) << endl;

            cout << "Purchase Price: $"
                 << fixed << setprecision(2)
                 << Collection[i].purchasePrice << endl;

            cout << "Estimated Value: $"
                 << Collection[i].estimatedValue << endl;

            found = true;
        }
    }


    if (found == false)
    {
        cout << "No sneakers found for that brand." << endl;
    }
}


// ==================== SEARCH BY MODEL ====================

void searchByModel(const Sneaker Collection[], int sneakerCount)
{
    string searchModel;
    bool found = false;

    if (sneakerCount == 0)
    {
        cout << "Collection is empty." << endl;
        return;
    }

    cout << "Enter model name to search: ";
    cin.ignore();
    getline(cin, searchModel);


    for (int i = 0; i < sneakerCount; i++)
    {
        if (Collection[i].model == searchModel)
        {
            cout << "\nModel: "
                 << Collection[i].model << endl;

            cout << "Brand: "
                 << getBrandName(Collection[i].brand) << endl;

            cout << "Size: "
                 << Collection[i].size << endl;

            cout << "Condition: "
                 << getConditionName(Collection[i].condition) << endl;

            cout << "Purchase Price: $"
                 << fixed << setprecision(2)
                 << Collection[i].purchasePrice << endl;

            cout << "Estimated Value: $"
                 << Collection[i].estimatedValue << endl;

            found = true;
        }
    }


    if (found == false)
    {
        cout << "No sneakers found with that model." << endl;
    }
}




void searchCollection(const Sneaker Collection[], int sneakerCount)
{
    int searchChoice;

    do
    {
        cout << "\n===== SEARCH COLLECTION =====" << endl;
        cout << "1. Search by Brand" << endl;
        cout << "2. Search by Model" << endl;
        cout << "3. Return to Main Menu" << endl;
        cout << "Enter selection: ";
        cin >> searchChoice;


        switch (searchChoice)
        {
            case 1:
                searchByBrand(Collection, sneakerCount);
                break;

            case 2:
                searchByModel(Collection, sneakerCount);
                break;

            case 3:
                cout << "Returning to Main Menu..." << endl;
                break;

            default:
                cout << "Invalid selection." << endl;
        }

    } while (searchChoice != 3);
}




void sortByBrand(Sneaker Collection[], int sneakerCount)
{
    for (int i = 0; i < sneakerCount - 1; i++)
    {
        for (int j = 0; j < sneakerCount - i - 1; j++)
        {
            if (Collection[j].brand > Collection[j + 1].brand)
            {
                Sneaker temp = Collection[j];

                Collection[j] = Collection[j + 1];

                Collection[j + 1] = temp;
            }
        }
    }

    cout << "Collection sorted by brand." << endl;
}



void sortByModel(Sneaker Collection[], int sneakerCount)
{
    for (int i = 0; i < sneakerCount - 1; i++)
    {
        for (int j = 0; j < sneakerCount - i - 1; j++)
        {
            if (Collection[j].model > Collection[j + 1].model)
            {
                Sneaker temp = Collection[j];

                Collection[j] = Collection[j + 1];

                Collection[j + 1] = temp;
            }
        }
    }

    cout << "Collection sorted by model." << endl;
}




void sortByValue(Sneaker Collection[], int sneakerCount)
{
    for (int i = 0; i < sneakerCount - 1; i++)
    {
        for (int j = 0; j < sneakerCount - i - 1; j++)
        {
            if (Collection[j].estimatedValue >
                Collection[j + 1].estimatedValue)
            {
                Sneaker temp = Collection[j];

                Collection[j] = Collection[j + 1];

                Collection[j + 1] = temp;
            }
        }
    }

    cout << "Collection sorted by estimated value." << endl;
}




void sortCollection(Sneaker Collection[], int sneakerCount)
{
    int sortChoice;

    do
    {
        cout << "\n===== SORT COLLECTION =====" << endl;
        cout << "1. Sort by Brand" << endl;
        cout << "2. Sort by Model" << endl;
        cout << "3. Sort by Estimated Value" << endl;
        cout << "4. Return to Main Menu" << endl;
        cout << "Enter selection: ";
        cin >> sortChoice;


        switch (sortChoice)
        {
            case 1:
                sortByBrand(Collection, sneakerCount);
                break;

            case 2:
                sortByModel(Collection, sneakerCount);
                break;

            case 3:
                sortByValue(Collection, sneakerCount);
                break;

            case 4:
                cout << "Returning to Main Menu..." << endl;
                break;

            default:
                cout << "Invalid selection." << endl;
        }

    } while (sortChoice != 4);
}




void displaySummary(const Sneaker Collection[], int sneakerCount)
{
    double totalPurchase = 0;
    double totalEstimated = 0;

    if (sneakerCount == 0)
    {
        cout << "Collection is empty." << endl;
        return;
    }


    for (int i = 0; i < sneakerCount; i++)
    {
        totalPurchase += Collection[i].purchasePrice;

        totalEstimated += Collection[i].estimatedValue;
    }


    double gainLoss = totalEstimated - totalPurchase;


    cout << "\n===== COLLECTION SUMMARY =====" << endl;

    cout << "Number of Sneakers: "
         << sneakerCount << endl;

    cout << fixed << setprecision(2);

    cout << "Total Purchase Cost: $"
         << totalPurchase << endl;

    cout << "Total Estimated Value: $"
         << totalEstimated << endl;

    cout << "Total Gain/Loss: $"
         << gainLoss << endl;


    if (gainLoss > 0)
    {
        cout << "Status: Collection increased in value."
             << endl;
    }
    else if (gainLoss < 0)
    {
        cout << "Status: Collection decreased in value."
             << endl;
    }
    else
    {
        cout << "Status: Collection value stayed the same."
             << endl;
    }
}




int main()
{
    Sneaker Collection[MAX_SNEAKERS];

    int sneakerCount = 0;
    int choice;


    do
    {
        displayMenu();

        cin >> choice;


        switch (choice)
        {
            case 1:
                addSneaker(Collection, sneakerCount);
                break;


            case 2:
                displayCollection(Collection, sneakerCount);
                break;


            case 3:
                searchCollection(Collection, sneakerCount);
                break;


            case 4:
                sortCollection(Collection, sneakerCount);
                break;


            case 5:
                displaySummary(Collection, sneakerCount);
                break;


            case 6:
                cout << "Exiting program..." << endl;
                break;


            default:
                cout << "Invalid selection." << endl;
        }


        cout << endl;

    } while (choice != 6);


    return 0;
}
