#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class User {
protected:
    string username;
    string password;

public:
    User() { }

    virtual void signup(string u, string p) {
        username = u;
        password = p;
    }

    virtual bool login(string u, string p) {
        if (username == u && password == p) {
            cout << "you have logged in" << endl;
            return true;
        } else {
            cout << "login fail " << endl;
            return false;
        }
    }
};

class admin : public User {
public:
    admin() {
    }

    admin(string u, string p) {
        username = u;
        password = p;
    }
};

class waiter : public User {
public:
    waiter() {
    }

    waiter(string u, string p) {
        username = u;
        password = p;
    }
};

class customer {
public:
    void display() {
        cout << "What would you like to order?" << endl;
    }
};

class MenuItem {
public:
    string name;
    float price;
    MenuItem(string n, float p) { 
	name = n; price = p; }
};

class Menu {
public:
    vector<MenuItem> items;
    void addItem(string name, float price) {
        if (name.empty()) {
            cout << " Item name cannot be empty" << endl;
            return;
        }
        if (price <= 0) {
            cout << " Price must be a positive number" << endl;
            return;
        }
        items.push_back(MenuItem(name, price));

    }
    void removeItem(int index) {
        if (index >= 0 && index < items.size()) {
            cout << "Item removed " << items[index].name << endl;
            items.erase(items.begin() + index);
        } else {
            cout << "Invalid item number" << endl;
        }
    }
    void displayMenu() {
        cout << "---------- MENU ----------" << endl;
        if (items.empty()) {
            cout << "No items available" << endl;
        } else {
            for (int i = 0; i < items.size(); i++) {
                cout << "|" << i + 1 << ". " << items[i].name << " - Rs." << items[i].price << "|" << endl;
            }
        }
        cout << "--------------------------" << endl;
    }
};

class Table {
public:
    int tableNumber;
    int capacity;
    Table(int number, int cap) { 
	tableNumber = number; capacity = cap; 
	}
};

class TableManager {
    vector<Table> tables;
public:
    void addTable(int number, int capacity) {
        tables.push_back(Table(number, capacity));
        cout << "Table added " << endl;
    }
    void displayTables() {
        cout << "----------|Table|----------" << endl;
        if (tables.empty()) {
            cout << "No tables available" << endl;
        } else {
            for (int i = 0; i < tables.size(); i++) {
                cout << "|" << "Table no " << tables[i].tableNumber << " and Capacity: " << tables[i].capacity << "|" << endl;
            }
        }
        cout << "--------------------------" << endl;
    }
};

class Order {
public:
    string itemName;
    int quantity;
    Order(string item, int qty) { 
	itemName = item; quantity = qty; }
};

class OrderManager {
    vector<Order> orders;
public:
    void placeOrder(string item, int quantity) {
        orders.push_back(Order(item, quantity));
        cout << "Order placed" << endl;
    }
    void displayOrders() {
        cout << "--- Orders ---" << endl;
        if (orders.empty()) {
            cout << "No orders found" << endl;
        } else {
            for (int i = 0; i < orders.size(); i++) {
                cout << i + 1 << ". " << orders[i].itemName << " x" << orders[i].quantity << endl;
            }
        }
        cout << "--------------" << endl;
    }
};

class Reservation {
private:
    struct ReservedTable {
        int tableNumber;
        string customerName;
    };
    vector<ReservedTable> reservations;
public:
    void makeReservation(int tableNumber, string customerName) {
    while (true) {
        bool reserved = false;
        for (int i = 0; i < reservations.size(); i++) {
            if (reservations[i].tableNumber == tableNumber) {
                cout << "Table " << tableNumber << " is already reserved"<<endl;
				cout<< "Please enter a different table number "<<endl;
                cin >> tableNumber;
                cout<<"enter name"<<endl;
                cin>>customerName;
                reserved = true;
                break;
            }
        }
        if (!reserved) break;
    }
        reservations.push_back({tableNumber, customerName});
    }
    void displayReservations() {
        cout << endl << "---------- Reservations----------" << endl;
        if (reservations.empty()) {
            cout << "No reservations available" << endl;
        } else {
            for (int i = 0; i < reservations.size(); i++) {
                cout << "Table no " << reservations[i].tableNumber
                     << " reserved for " << reservations[i].customerName << endl;
            }
        }
        cout << "---------------------" << endl;
    }
};

class PaymentSystem {
private:
    struct Payment {
        float amount;
        string method;
    };
    vector<Payment> payments;
public:
    void makePayment(float amount, const string& method) {
        payments.push_back({amount, method});
        cout << "Payment of Rs. " << amount << " made via " << method << endl;
    }
    void displayAllPayments() {
        cout << endl << "---------- Payment History ----------" << endl;
        if (payments.empty()) {
      cout << "No payments made yet.";
        } else {
            for (int i = 0; i < payments.size(); i++) {
                cout << i + 1 << ". Rs. " << payments[i].amount
                     << " via " << payments[i].method << endl;
            }
        }
        cout << "------------------------" << endl;
    }
    float getTotalRevenue() {
        float total = 0;
        for (int i = 0; i < payments.size(); i++) {
            total += payments[i].amount;
        }
        return total;
    }
};

class Feedback {
private:
    struct Entry {
        string customerName;
        string message;
    };
    vector<Entry> feedbacks;
public:
    void submitFeedback(const string& name, const string& msg) {
        feedbacks.push_back({name, msg});
        cout << "Thank you for your feedback" << endl;
    }
    void displayFeedbacks() {
        cout << endl << "---------- Customer Feedbacks -------------" << endl;
        if (feedbacks.empty()) {
            cout << "No feedback submitted yet.";
        } else {
            for (int i = 0; i < feedbacks.size(); i++) {
                cout << i + 1 << ". " << feedbacks[i].customerName << " says: "
                     << feedbacks[i].message << endl;
            }
        }
        cout << "---------------------------" << endl;
    }
};

int main() {
    string uName, uPass;
    admin a;
    waiter w;
    customer c;
    Menu m;
    TableManager t;
    OrderManager o;
    Feedback f;
    Reservation r;
    PaymentSystem p;
    m.addItem("Burger", 223);
m.addItem("Fries", 2232);
m.addItem("Pizza", 683);
r.makeReservation(1, "Ali");
r.makeReservation(2, "Sara");
r.makeReservation(3, "Ahmed");
    int n;
    while (true) {
        cout << "*******************|WELCOME TO RH RESTRUNENT|********************" << endl;
        cout << endl;
        cout << " customer login enter 1" << endl;
        cout << " admin login enter 2" << endl;
        cout << " waiter login enter 3" << endl;
        cout << " Exit enter 4" << endl;
        cin >> n;

        if (n == 4) {
            cout << "COME AGAIN " << endl;
            break;
        }

        if (n == 1) {
            c.display();
            m.displayMenu();

            char giveFeedback;
            cout << "Do you want to give feedback? (y/n): ";
            cin >> giveFeedback;

            if (giveFeedback == 'y' || giveFeedback == 'Y') {
                string fName, fMsg;
                cin.ignore();
                cout << "Enter your name ";
                getline(cin, fName);
                cout << "Enter your feedback: ";
                getline(cin, fMsg);
                f.submitFeedback(fName, fMsg);

                ofstream fout("feedback.txt", ios::app);
                fout << fName << " : " << fMsg << endl;
                fout.close();

                f.displayFeedbacks();
            } else {
                cout << "Thank you for visiting!" << endl;
            }

        } else if (n == 2) {
            cout << "Enter username for sign up" << endl;
            cin >> uName;
            cout << "Enter password for sign up" << endl;
            cin >> uPass;
            a.signup(uName, uPass);
            string lUser, lPass;
            cout << "Enter username to login: ";
            cin >> lUser;
            cout << "Enter password to login: ";
            cin >> lPass;
            if (!a.login(lUser, lPass)) {
                continue;
            }
            cout << "You are signed up and logged in as Admin" << endl;

            int ch;
            do {
                cout << "1 Add Menu Item" << endl;
                cout << "2 Remove Menu Item" << endl;
                cout << "3 View Menu" << endl;
                cout << "4 Add Table" << endl;
                cout << "5 View Tables" << endl;
                cout << "6 Make Reservation" << endl;
                cout << "7 View Reservations" << endl;
                cout << "8 Place Order" << endl;
                cout << "9 View Orders" << endl;
                cout << "10 Make Payment" << endl;
                cout << "11 View Payments" << endl;
                cout << "12 Exit" << endl;
                cin >> ch;

                if (ch == 1) {
                    cin.ignore();
                    string itemName;
                    float itemPrice;
                    cout << "Enter item name: ";
                    getline(cin, itemName);
                    cout << "Enter item price: ";
                    cin >> itemPrice;
                    m.addItem(itemName, itemPrice);

                    ofstream fout("menu.txt", ios::app);
                    fout << itemName << "," << itemPrice << endl;
                    fout.close();

                } else if (ch == 2) {
                    m.displayMenu();
                    int idx;
                    cout << "Enter item number to remove: ";
                    cin >> idx;
                    m.removeItem(idx - 1);

                } else if (ch == 3) {
                    m.displayMenu();

                } else if (ch == 4) {
                    int tNo, tCap;
                    cout << "Enter table number: ";
                    cin >> tNo;
                    cout << "Enter capacity: ";
                    cin >> tCap;
                    t.addTable(tNo, tCap);

                    ofstream fout("tables.txt", ios::app);
                    fout << "Table " << tNo << ", Capacity: " << tCap << endl;
                    fout.close();

                } else if (ch == 5) {
                    t.displayTables();

                } else if (ch == 6) {
                    int resNo;
                    string custName;
                    cout << "Enter table number ";
                    cin >> resNo;
                    cout << "Enter customer name ";
                    cin >> custName;
                    r.makeReservation(resNo, custName);

                    ofstream fout("reservations.txt", ios::app);
                    fout << "Table " << resNo << " reserved for " << custName << endl;
                    fout.close();

                } else if (ch == 7) {
                    r.displayReservations();

                } else if (ch == 8) {
                    string oItem;
                    int oQty;
                    m.displayMenu();
                    cin.ignore();
                    bool valid = false;
                    do {
                        cout << "Enter item name: ";
                        getline(cin, oItem);
                        valid = false;
                        for (int i = 0; i < m.items.size(); i++) {
                            if (m.items[i].name == oItem) {
                                valid = true;
                                break;
                            }
                        }
                        if (!valid) {
                            cout << "Invalid item name. Please enter a valid one from the menu" << endl;
                            m.displayMenu();
                        }
                    } while (!valid);

                    cout << "Enter quantity: ";
                    cin >> oQty;
                    o.placeOrder(oItem, oQty);

                    ofstream fout("orders.txt", ios::app);
                    fout << oItem << " x" << oQty << endl;
                    fout.close();

                } else if (ch == 9) {
                    o.displayOrders();

                } else if (ch == 10) {
                    float payAmt;
                    string payMethod;
                    cout << "Enter amount: ";
                    cin >> payAmt;
                    cout << "Enter payment method: ";
                    cin >> payMethod;
                    p.makePayment(payAmt, payMethod);

                    ofstream fout("payments.txt", ios::app);
                    fout << "Rs. " << payAmt << " via " << payMethod << endl;
                    fout.close();

                } else if (ch == 11) {
                    p.displayAllPayments();
                    cout << "Total Revenue: Rs. " << p.getTotalRevenue() << endl;
                } else {
                    cout << "invaild option" << endl;
                }

            } while (ch != 12);

        } else if (n == 3) {
            cout << "Enter username for sign up" << endl;
            cin >> uName;
            cout << "Enter password for sign up" << endl;
            cin >> uPass;
            w.signup(uName, uPass);
            string lUser, lPass;
            cout << "Enter username to login: ";
            cin >> lUser;
            cout << "Enter password to login: ";
            cin >> lPass;
            if (!w.login(lUser, lPass)) {
                continue;
            }
            cout << "You are signed up and logged in as Waiter" << endl;

            int ch;
            do {
                cout << "1. View Menu" << endl;
                cout << "2. View Tables" << endl;
                cout << "3. View Reservations" << endl;
                cout << "4. View Orders" << endl;
                cout << "5. Exit" << endl;
                cin >> ch;

                if (ch == 1) {
                    m.displayMenu();
                } else if (ch == 2) {
                    t.displayTables();
                } else if (ch == 3) {
                    r.displayReservations();
                } else if (ch == 4) {
                    o.displayOrders();
                } else {
                    cout << "Invalid Entry" << endl;
                }

            } while (ch != 5);

        } else {
            cout << "invaild entary" << endl;
        }
    }

    return 0;
}
