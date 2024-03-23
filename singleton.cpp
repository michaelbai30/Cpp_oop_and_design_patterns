#include <iostream>
using namespace std;

// Singleton 
// Purpose: To ensure a class has only one instance at a time. May also provide a global access point to this instance. We can access this object anywhere in the program and protect it from being overwritten
// useful to CONTROL ACCESS TO SOME SHARED RESOURCE (for example: a db or a file)
// Instead of creating a new, fresh object upon object instantiation, get the one already created

// How To Create
// MAKE DEFAULT CONSTRUCTOR PRIVATE, to prevent other objects from using the new operator with the Singleton class
// Create a static creation method that acts as a constructor. This method calls the private constructor to creat an object and saves it in a static field such that all following calls to this method return the cached object

// Components
// The Singleton class declares the static method getInstance() that returns the same instance of its own class. The constructor should be hidden from client code, and we must be forced to call getInstance

class Singleton{
    private:
        // private static instance of the same class
        static Singleton *instance;
        
        // Private constructor to prevent instantiation
        Singleton(){
            cout << "Singleton instance created" << endl;
        }
    public:
        
        // delete both copy constructor and assignment operator to prevent copying
        Singleton(const Singleton&) = delete;
        Singleton& operator=(const Singleton&) = delete;
        
        // Public getInstance()
        static Singleton *getInstance(){
            if (instance == nullptr){
                instance = new Singleton();
            }
            return instance;
        }
        
        void doSomething(){
            cout <<"Doing something with the singleton instance" << endl;
        }
        
        static void destroyInstance(){
            delete instance;
            instance = nullptr;
        }
};

// Init the static member globally
Singleton *Singleton::instance = nullptr;

int main() {
    
    // get singleton instance and use it
    Singleton *singletonInstance = Singleton::getInstance();
    singletonInstance->doSomething();
    
    Singleton::destroyInstance();
 
    return 0;
}
