#include <iostream>
using namespace std;

// Decorator / Wrapper

// The Decorator design pattern enables you to attach new behaviors to existing objects by placing these objects inside special wrapper objects that contain the behaviors

// Instead of extending a class repeatedly to alter an object's behavior (or implement more features) through inheritance, we use composition.

// Ex of inefficiency with inheritance
// We have a notification app and we wish to extend its usage to SNS, email, and Facebook
// We need to manually implement these through inheritance AS WELL AS its combinations (SNS and email, email and Facebook, etc...)

// Problems with Inheritance
// 1) Inheritance is static: We cannot alter the behavior of an existing object at runtime. We must replace it entirely.
// 2) Subclasses can only have one parent class. Sometimes, we need to "inherit" from more than one parent class.

// Composition: One object HAS another object
// Wrapper: An object that can be linked with some target object

// Structure
// 1) Component Interface: Declares the common interface for both wrappers and wrapped objects
// 2) Concrete Component: A class of objects being wrapped. Basic behaviors that can be altered by decorators
// 3) Base Decorators: A class that has a field for referencing a wrapped object. The field's type should be declared as the compoennt interface so it can contain both concrete components and decorators
// 4) Concrete Decorators: Define extra behaviors through overriding methods of the base decorator.
// 5) Client: Can wrap components in multiple layers of decorators

// Component Interface
class Notification{
    public:
        virtual string getMessage() const = 0;
        virtual ~Notification(){};
};

// Concrete Component 
class BasicNotification : public Notification{
    string message;
    public:
        BasicNotification(const string &msg){
            message = msg;
        }
        string getMessage() const override{
            return message;
        }
};

// Base Decorator
class NotificationDecorator : public Notification{
    protected:
        Notification *wrappee; //the notification being wrapped IS a Notification
    public:
        NotificationDecorator(Notification *notification){
            wrappee = notification;
        }
        string getMessage() const override{
            return wrappee->getMessage(); // we operate on the wrappee
        }
        virtual ~NotificationDecorator(){
            delete wrappee;
        }
};

// Concrete Decorators. To perform a specific new action.
class PrefixDecorator : public NotificationDecorator {
    string prefix;
    
    public:
         PrefixDecorator(Notification* notification, const string& pref) : NotificationDecorator(notification) {
        this->prefix = pref;
    }

        string getMessage() const override {
            return prefix + NotificationDecorator::getMessage();
        }
};

class UppercaseDecorator : public NotificationDecorator {
    public:
        UppercaseDecorator(Notification* notification) : NotificationDecorator(notification) {}

        string getMessage() const override {
            string originalMessage = NotificationDecorator::getMessage();
            string uppercaseMessage;
            for (auto &c : originalMessage) {
                uppercaseMessage += toupper(c);
            }
            return uppercaseMessage;
        }
};

int main() {
   
    Notification* notification = new BasicNotification("Hello, World!");
    notification = new PrefixDecorator(notification, "Prefix: ");
    notification = new UppercaseDecorator(notification);

    cout << notification->getMessage() << endl;

    delete notification; 
    
    return 0;
}
