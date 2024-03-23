#include <iostream>
using namespace std;

// Proxy
// Goal: To provide a substitute or placeholder for another object
// The proxy controls access to the original object, allowing you to perform something either before or after the request reaches the original object

// Create a new proxy class w/ same interface as original service object, then pass the proxy object to all of the original object's clients. Upon receiving a client request, the proxy creates a real service object and delegates all the work to it. Can serve requests without the real DB even knowing.

// Real world example:
// A credit card is a proxy for a bank account
// A bank account is a proxy for cash
// Both credit cards and cash implement "payment"
// Credit card eliminates need to carry cash around
// Bank account makes keeping track of payments easy

// Components
// 1) Service Interface:Declares the interface of the service. The proxy follows this interface
// 2) Service: A class that does something useful.
// 3) Proxy: A class that has a reference field that points to a service object. After the proxy finishes processing, it PASSES THE REQUEST TO THE SERVER OBJECT
// 4) The client should work with both services and proxies via the same interface. That way, you can pass the proxy into any code that expects a service object.


// Service Interface
// Both the real service (Bank Account) and proxy (Credit Card) will implement this
class Payment{
    public:
        virtual void makePayment(double amount) = 0;
        virtual ~Payment() {};
};

// Service
class BankAccount : public Payment{
    public:
        void makePayment(double amount) override{
            cout << "Payment of $" << amount << " made from bank account" << endl;
        };
};

// Proxy
// Credit Card is a proxy for Bank Account
// Can also implement additional behaviors such as checking for fraud
class CreditCard : public Payment{
    BankAccount bankAccount;
    bool checkFraud(double amount){
        return amount > 20000; // if payment exceeds $20000 consider fraud
    }
    public:
        void makePayment(double amount) override{
            if (checkFraud(amount)){
                cout << "Payment declined: Possible fraud" << endl;
            }
            else{
                cout << "Payment approved by credit card" << endl;
                // proxy uses bank account's makePayment, but conceals it as its makePayment
                bankAccount.makePayment(amount);
            }
        };
};

int main(){
    BankAccount bankAccount;
    bankAccount.makePayment(1000);
    
    cout << "------------" << endl;
    
    CreditCard creditCard;
    creditCard.makePayment(1000);
    creditCard.makePayment(30000);
    
    return;
};
