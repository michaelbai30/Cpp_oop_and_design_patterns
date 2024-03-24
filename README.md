Notes for object oriented programming and design patterns in C++

Factory:
The purpose of the Factory design pattern is to define an interface for creating an object but allow subclasses to determine which class to instantiate, providing flexibility. To implement it, define a creator class with a factory method that returns an instance of a product class. Subclasses of the creator then override this factory method to create and return instances of different product classes, enabling the instantiation process to be dynamic and flexible based on the context or parameters provided.

Facade:
The purpose of the Facade design pattern is to provide a simplified interface to a complex subsystem, making the subsystem easier to use and understand for the client. To implement a Facade, create a class that aggregates the complex interactions within the subsystem and provides straightforward methods for clients to use. This Facade class sends client requests to the appropriate components of the subsystem without exposing the underlying complexity to the client.

Proxy:
The purpose of the Proxy design pattern is to provide a substitute or placeholder for another object, allowing you to control access to it, manage its lifecycle, or add additional functionalities without changing the object itself. To implement a Proxy, create a proxy class that has the same interface as the original service object it is intended to represent. This proxy class holds a reference to the service object and delegates client requests to the service object, potentially adding additional processing before or after forwarding the request.

Singleton:
The purpose of the Singleton design pattern is to ensure that a class has only one instance and provides a global point of access to that instance, promoting controlled access and resource management. To implement it, make the class constructor private to prevent external instantiation, and introduce a static method that returns the unique instance of the class, creating this instance if it does not yet exist. Often, the copy constructor and assignment operator are explicitly prevented from being used (either made private or deleted) to ensure the class cannot be copied or assigned, maintaining a single instance throughout the application's lifecycle.

Composite:
The purpose of the Composite design pattern is to enable individual objects and compositions of objects to be treated uniformly by representing them in a tree structure. To implement it, define a component interface that both the leaf "node" and composite "nodes" classes will implement, ensuring that operations can be applied to both individual elements as well as their compositions. 
