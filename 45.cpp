#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#define max 10

using namespace std;
//the header file

class medicineType
{
public:

    void take_order();//to  take_order
    void delete_order(); //to delete the order
    void order_list(); //to display the order_list
    //void daily_summary(); //to display daily_summary
    void exit();  //function to exit system
    medicineType();//constuctor

};

medicineType::medicineType ()
{

}

void print_reciept(struct node *temp2);
void store_order(struct node *temp3);


struct node //constract node
{
    int reciept_number;
    string customerName;
    string date;
    int quantity[10];
    int x;
    double price[10];
    string medicine_name[10];
    double total_price;

}*q, *temp;				

int main()	// Main function
{

    medicineType medicine;
    int menu;
    do
    {
        /// system("cls");
        cout<<"\t\t\t    Pharmacy Management System \n";
        cout<<"\t\t==================================================\n\n";
        cout<<"\t\t--------------------------------------------------\n";
        cout<<"\t\t||\t1. Take new Medicine order \t\t ||\n";
        cout<<"\t\t||\t2. Delete Any Medicine order\t\t ||\n";
        cout<<"\t\t||\t3. Print the Reciept and Total Payment \t ||\n";
        cout<<"\t\t||\t4. Exit\t\t\t\t\t ||\n";
        cout<<"\t\t--------------------------------------------------\n";
        cout<<"Enter choice: ";

        cin>>menu;

        switch (menu)
        {
            case 1:  //done
            {
                medicine.take_order();	//function add
                break;
                system("PAUSE");
            }	//end case 1


            case 2:  //done
            {
                medicine.delete_order();	//function delete
                break;
                system("PAUSE");
            }	//end case 2

            case 3:    //done
            {
                medicine.order_list();	//function order
                break;
            }	//end case 4
            case 4:   //done
            {
                medicine.exit();	//function exit
                cout<<"thank you"<<endl;
                return 0;
                break;
            }	//end case 6


            default:
            {
                cout<<"You enter invalid input\nre-enter the input\n"<<endl;
                break;
            }//end defeault
        }//end Switch
    }while(menu!=6);//end do
}//end  main function


void medicineType::take_order()		//function to take_order
{
    int i;
    double total_price = 0;
    int choice, quantity, price, None;
    char check1;

    cout << "\nAdd Order Details\n";
    cout << "_____________ \n\n";

    node *temp;
    temp = new node;

    temp = new node;
    cout << "Type Order no: ";
    cin >> temp->reciept_number;
    cout << "Enter Customer Name: ";
    cin >> temp->customerName;
    cout << "Enter Date : ";
    cin >> temp->date;
    cout << "How many Medicine would you like to order:" << endl;
    cout << "( Maximum is 10 order for each transaction ) \n";
    cout << "  ";
    cin >> temp->x;
    if (temp->x > 10) {
        cout << "The Medicine you order is exceed the maximum amount of order !";
    }
    else {
        for (i = 0; i < temp->x; i++) {
            //void read_order();


            fstream fin;

            // Open an existing file
            fin.open("medicine_detail.csv", ios::in);

            // Get the roll number
            // of which the data is required
            string medicine_name1, med_name1;
            int count = 0, price, total_price, quantity;
            cout << "Enter the medicine name in Capital letters:  ";
            cin >> medicine_name1;

            // Read the Data from the file
            // as String Vector
            vector<string> row;
            string line, word, temp1;

            while (fin >> temp1) {

                row.clear();

                // read an entire row and
                // store it in a string variable 'line'
                getline(fin, line);

                // used for breaking words
                stringstream s(line);

                // read every column data of a row and
                // store it in a string variable, 'word'
                while (getline(s, word, ',')) {

                    // add all the column data
                    // of a row to a vector
                    row.push_back(word);
                }
                med_name1 = row[0];

                if (medicine_name1 == med_name1) {
                    // store medicine name
                    temp->medicine_name[i] = medicine_name1;
                    // Print the found data
                    count = 1;
                    cout << "Quantity : ";
                    cin >> quantity;
                    cout << "\n";
                    temp->quantity[i] = quantity;
                    cout << row[1] << "*" << quantity;
                    price = stoi(row[1]);
                    temp->price[i] = price * quantity;
                    total_price = total_price + price * quantity;
                    //to reduce the quantity use function void unit(row[0]);
                    break;
                }
                temp->total_price = total_price;
            }
            if (count == 0)
                cout << "Record not found\n";

        }
        
        temp->total_price = total_price;

        cout << "===========================================================================" << endl;
        cout << "Order Taken Successfully" << endl;

        store_order(temp);

        cout << "If you want to print receipt\n" <<
             "Type 'Y' for Yes and 'N' for No:  ";
        cin >> check1;
        if (check1 == 'Y') {
            print_reciept(temp);//Check how to pass pointer in function
        }
        else if (check1 == 'N') {
            cout << "  Thanks for placing order \n";
        }
        else{
            cout << "You entered wrong key So now to print reciept go to main menu to print order";
        }
    }//End function take_order
}


    void medicineType::order_list() {

        // File pointer
        fstream fin;

        // Open an existing file
        fin.open("order_detail.csv", ios::in);

        // Get the name of medicine
        // of which the data is required
        int order_no, order_no1, count = 0, i, x;
        string name, name1;

        cout << "Fill ALL Enteries In CAPITAL letters";

        cout << "Enter the order no. :  ";
        cin >> order_no;
        cout << "\nEnter the name : ";
        cin >> name;


        vector<string> row;
        string line, word, temp1;

        while (fin >> temp1) {

            row.clear();

            // read an entire row and
            // store it in a string variable 'line'
            getline(fin, line);

            // used for breaking words
            stringstream s(line);

            // read every column data of a row and
            // store it in a string variable, 'word'
            while (getline(s, word, ',')) {

                // add all the column data
                // of a row to a vector
                row.push_back(word);
            }

            order_no1 = stoi(row[0]);
            name1 = row[1];
            x = stoi(row[3]);

            // Compare the datas
            if (order_no1 == order_no && name1 == name) {

                // Print the found data
                count = 1;
                cout << "Order no. :  " << row[0];
                cout << "\tName: " << row[1];
                cout << "\tDate : " << row[2] << "\n";
                cout << "------------------------------------------------------------------------" << "\n";

                for (i = 0; i < x; i++) {
                    cout << row[4 * i + 4] << "\t" << row[4 * i + 5] << "t" << row[4 * i + 6]
                         << "\n"; //row[4i+6] is total price*quantity
                }
                cout << "Total price : " << row[4 * i + 7];
                break;
            }
        }
        if (count == 0)
            cout << "Record not found\n";
        system("PAUSE");
    }


    void medicineType::delete_order()    //function to delete_order
    {
        // Open FIle pointers
        fstream fin, fout;

        // Open the existing file
        fin.open("order_detail.csv", ios::in);

        // Create a new file to store the non-deleted data
        fout.open("order_detail_new.csv", ios::out);

        int order_no, order_no1, marks, count = 0, i;
        string name, name1;
        string line, word;
        vector<string> row;

        // Get the roll number
        // to decide the data to be deleted
        cout << "Enter the Order no. "
             << "you want to deleted from record :  ";
        cin >> order_no;

        // Check if this record exists
        // If exists, leave it and
        // add all other data to the new file
        while (!fin.eof()) {

            row.clear();
            getline(fin, line);
            stringstream s(line);

            while (getline(s, word, ',')) {
                row.push_back(word);
            }

            int row_size = row.size();
            order_no1 = stoi(row[0]);

            // writing all records,
            // except the record to be deleted,
            // into the new file 'order_detail_new.csv'
            // using fout pointer
            if (order_no != order_no1) {
                if (!fin.eof()) {
                    for (i = 0; i < row_size - 1; i++) {
                        fout << row[i] << ", ";
                    }
                    fout << row[row_size - 1] << "\n";
                }
            } else {
                count = 1;
            }
            if (fin.eof())
                break;
        }
        if (count == 1)
            cout << "Record deleted\n";
        else
            cout << "Record not found\n";

        // Close the pointers
        fin.close();
        fout.close();

        // removing the existing file
        remove("order_detail.csv");

        // renaming the new file with the existing file name
        rename("order_detail_new.csv", "order_detail.csv");
        system("PAUSE");
    }

    void print_reciept(node *temp2) {
        int i;
        cout << "Order no.: " << temp->reciept_number
             << "\tName: " << temp->customerName
             << "\tDate: " << temp->date << "\n";
        for (i = 0; i == temp->x; i++) {
            cout << i + 1 << ")\t" << temp->medicine_name[i]
                 << "\t" << temp->quantity
                 << "\t" << temp->price << " Rs\n";
        }
        cout << "----------------------------------------------\n"
             << "----------------------------------------------\n"
             << "Total money pay: " << temp->total_price;
    }


    
    void store_order(struct node *temp2) {
        // file pointer
        fstream fout;

        // opens an existing csv file or creates a new file.
        fout.open("order_detail.csv", ios::out | ios::app);

        int i;
        string name;

        // Insert the data to file
        fout << temp->reciept_number << ", "
             << temp->customerName << ", "
        << temp->date << ",";
        for (i = 0; i < temp->x; i++) {
            fout << temp->medicine_name[i] << ","
                 << temp->price[i] << ","
                 << temp->quantity << ",";
        }
        fout << temp->total_price
             << "\n";
    }


    void medicineType::exit() {
        cout << "\nYou choose to exit.\n" << endl;
    }







