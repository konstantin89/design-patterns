# design-patterns

## Creational Patterns

### Singleton Pattern
Ensures a class has only one instance and provides a global point of access to that instance.

### Factory Method Pattern
Defines an interface for creating an object but allows subclasses to alter the type of objects that will be created.

### Abstract Factory Pattern
Provides an interface for creating families of related or dependent objects without specifying their concrete classes.

### Builder Pattern
Separates the construction of a complex object from its representation, allowing the same construction process to create various representations.

### Prototype Pattern
Creates new objects by copying an existing object, known as the prototype.


## Structural Patterns

### Adapter Pattern
Allows the interface of an existing class to be used as another interface.

### Decorator Pattern
Attaches additional responsibilities to an object dynamically.

### Bridge Pattern
Separates an objects abstraction from its implementation, allowing them to vary independently.

### Composite Pattern
Composes objects into tree structures to represent part-whole hierarchies.

### Proxy Pattern
Provides a surrogate or placeholder for another object to control access to it.


## Behavioral Patterns

### Observer Pattern
Defines a one-to-many dependency between objects so that when one object changes state, all its dependents are notified and updated automatically.

### Strategy Pattern
Defines a family of algorithms, encapsulates each one, and makes them interchangeable.

### Command Pattern
Encapsulates a request as an object, thereby allowing for parameterization of clients with queues, requests, and operations.

### State Pattern
Allows an object to alter its behavior when its internal state changes.

### Chain of Responsibility Pattern
Passes a request along a chain of handlers. Upon receiving a request, each handler decides either to process it or to pass it to the next handler in the chain.

### Visitor Pattern
Represents an operation to be performed on the elements of an object structure. It lets you define a new operation without changing the classes of the elements on which it operates.

## Concurrency Patterns

### Mutex Pattern
Provides a way to synchronize access to resources that are shared among multiple threads.

### Semaphore Pattern
Controls access to a limited number of resources among multiple threads.

### Producer-Consumer Pattern
Deals with the efficient and safe sharing of data between producer and consumer threads.

### Reader-Writer Pattern
Manages access to a resource that can be read by multiple threads simultaneously but written by only one thread at a time.


## Architectural Patterns

### MVC (Model-View-Controller) Pattern
Separates an application into three interconnected components: Model, View, and Controller.

### MVVM (Model-View-ViewModel) Pattern
Similar to MVC, but with a focus on data binding and separation of concerns.

### Repository Pattern
Provides an abstraction layer for data access, hiding the underlying data store and providing a consistent API for accessing data.