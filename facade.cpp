#include <iostream>
using namespace std;

// Facade
// The purpose of a facade is to simplify an interface to a library, framework, etc..
// A class that provides a simple interface to a complex subsystem ... includes features clients really care about

// Components of a Facade
// Facade: A class that provides simplified access to a particular part(s) of a subsystem
// Additional Facade: Can be created to prevent polluting a single facade with unrelated features that make it more complex
// Complex Subsystem: The things you are trying to abstract
// Client: Calls the facade instead of the subsystem objects directly

class CPU {
    public:
        void freeze() { cout << "CPU freeze\n"; }
        void jump(long position) { cout << "CPU jump to " << position << "\n"; }
        void execute() { cout << "CPU execute\n"; }
};

class Memory {
    public:
        void load(long position, const string& data) { 
            cout << "Memory load: " << data << " at position " << position << "\n"; 
        }
};

class HardDrive {
    public:
        string read(long lba, int size) { 
            return "Data read from sector " + to_string(lba) + " with size " + to_string(size); 
        }
};

// The Facade
class ComputerFacade {
    CPU cpu;
    Memory memory;
    HardDrive hardDrive;

    public:
        void start() {
            cpu.freeze();
            memory.load(0, hardDrive.read(1024, 2048));
            cpu.jump(1024);
            cpu.execute();
        }

        void shutDown() {
            cout << "Computer is shutting down.\n";
        }
};

int main() {
    // Client need only call this simple interface
    ComputerFacade computer;
    computer.start();
    computer.shutDown();
  
    return 0;
}
