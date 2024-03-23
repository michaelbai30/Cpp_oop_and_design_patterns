#include <iostream>
using namespace std;

// Factory Method: 
// provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that can be created

// Instead of directly calling the constructor, call a factory method. The returned object is called a "product"

// Now we can override the factory method in a subclass and change the class of products being created by the method.

// Components

// Product: Declares the interface
// Concrete products: Implementations of the product interface
// Creator class: Declares the factory method 
// Concrete creators: Overrides the base factory method so it returns a different type of product.


// Abstract Product
class Logger{
    public: 
        virtual ~Logger() {};
        virtual void log(const string &message) = 0;
        
    
};

// Concrete Product A
// file logger isa public logger
class FileLogger : public Logger{
    public:
        void log(const string &message) override{
            cout << "File log:" << message << endl;
        }
};

// Concrete Product B
class ConsoleLogger : public Logger{
    public:
        void log(const string &message) override{
            cout << "Console log:" << message << endl;
        }
};

// Creator (Factory)
class LoggerFactory{
    public:
        
        // createLogger = factory method
        virtual Logger *createLogger(const string &type){
            if (type == "file"){
                return new FileLogger();
            }
            else if (type == "console"){
                return new ConsoleLogger();
            }
            else {
                throw std::invalid_argument("Unknown logger type");
            }
        }
};

int main() {
    LoggerFactory loggerFactory;
    Logger *fileLogger = loggerFactory.createLogger("file");
    
    Logger *consoleLogger = loggerFactory.createLogger("console");
    
    fileLogger->log(" Hello from file");
    consoleLogger->log(" Hello from console");
    
    delete fileLogger;
    delete consoleLogger;
    

    return 0;
}
