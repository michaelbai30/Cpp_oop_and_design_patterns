#include <iostream>
#include <vector>
using namespace std;

// Composite
// Compose objects into tree structures and then work with these structures as if they were either individual objects or compositions of objects.
// "Treat individual objects and composition of objects uniformly"
// Similar operations but differ in complexity

// Problem: 
// Used for an app to deal with a hierarchy of objects where both individual objects and compositions need to be treated in the same way. 
// For instance: File system. Directories can contain files and other directories as well. Whether it's a single file or a directory, we must be able to perform operations like calculating the size, listing name, etc...
// Without Composite pattern, we might need to check the type of each object before performing operations.

// Structure
// 1) The Component interface describes operations that are common to both simple and complex elements of the tree
// 2) The leaf is a basic element of a tree that has no sub-elements
// 3) The Container (the Composite) is an element that has sub-elements: leaves or other containers. A container doesn't know the concrete classes of its children. It works with all sub-elements only via the component interface.
// 4) The Client works with all elements through the component interface. As a result, the client can work in the same way with both simple or complex elements of the tree.

// Component Interface
// Common operations to both files and directories (show)
class FileSystemComponent{
    public:
        virtual void show() const = 0;
        virtual ~FileSystemComponent() {};
};

// Leaf "Node"
class File : public FileSystemComponent{
    string name;
    public:
        File(const string &name) : name(name){}
        void show() const override{
            cout << "File: " << name << endl;
        }
};

// Composite "Node"
// Directory HAS files OR other directories (file system components)
class Directory : public FileSystemComponent {
    
    std::string name;
    std::vector<FileSystemComponent*> children;
    public:
        Directory(const std::string& name) : name(name) {}

        void add(FileSystemComponent* component) {
            children.push_back(component);
        }
        
        // Display both directory name and children names
        void show() const override {
            std::cout << "Directory: " << name << std::endl;
            for (const auto& child : children) {
                child->show();
            }
        }

        ~Directory() {
            for (auto& child : children) {
                delete child;
            }
        }
};


int main() {
    Directory* root = new Directory("root");
    File* file1 = new File("file1.txt");
    File* file2 = new File("file2.txt");

    Directory* dir1 = new Directory("dir1");
    File* file3 = new File("file3.txt");

    root->add(file1);
    root->add(file2);
    root->add(dir1);
    dir1->add(file3);
    
     // Notice, the client need not distinguish between files and directories when calling show
     // Because both file and directory implement file system component, clients can interact with both files and directories uniformly using show.
    root->show();
    file2->show();
    dir1->show();
    delete root;

    return 0;
}
