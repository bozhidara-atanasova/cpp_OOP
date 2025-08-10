#include <iostream>
#include <limits>

class Counter
{
private:
    std::size_t count;
    std::size_t capacity;

public:
    Counter(std::size_t cap) : count(0), capacity(cap) {}

    std::size_t getVisitorsCount() const {
        return count;
    }

    // Increase: returns true on success, false if it would exceed capacity
    bool increaseVisitorsCount(std::size_t amount = 1) {
        if (amount == 0) return true;
        if (capacity != 0) {
            if (count + amount > capacity) return false;
        }
        count += amount;
        return true;
    }

    // Decrease: returns true on success, false if it would go below zero
    bool decreaseVisitorsCount(std::size_t amount = 1) {
        if (amount == 0) return true;
        if (amount > count) return false;
        count -= amount;
        return true;
    }

    std::size_t getCapacity() const { return capacity; }
    void setCapacity(std::size_t cap) { capacity = cap; }
};

int main()
{
    std::cout << "=== Club P — Visitor Counter ===\n";
    std::cout << "Enter capacity (0 for no limit): ";

    std::size_t cap = 0;
    if (!(std::cin >> cap)) {
        std::cerr << "Invalid number. Exiting.\n";
        return 1;
    }

    Counter counter(cap);

    std::cout << "\nCommands:\n"
        << "  + N  -> N people enter (e.g., + 3)\n"
        << "  - N  -> N people leave (e.g., - 2)\n"
        << "  p    -> print current count\n"
        << "  q    -> quit\n\n";

    while (true) {
        std::cout << "[Count: " << counter.getVisitorsCount();
        if (counter.getCapacity() != 0) std::cout << "/" << counter.getCapacity();
        std::cout << "] > ";

        char cmd;
        if (!(std::cin >> cmd)) {
            std::cerr << "Read error. Exiting.\n";
            break;
        }

        if (cmd == 'q' || cmd == 'Q') {
            std::cout << "Goodbye!\n";
            break;
        }
        else if (cmd == 'p' || cmd == 'P') {
            std::cout << "Current visitors: " << counter.getVisitorsCount() << "\n";
        }
        else if (cmd == '+') {
            std::size_t n;
            if (std::cin >> n) {
                if (counter.increaseVisitorsCount(n)) {
                    std::cout << n << " entered. Total: " << counter.getVisitorsCount() << "\n";
                }
                else {
                    std::cout << "Denied: exceeds capacity";
                    if (counter.getCapacity() != 0) std::cout << " (" << counter.getCapacity() << ")";
                    std::cout << ". Total: " << counter.getVisitorsCount() << "\n";
                }
            }
            else {
                std::cout << "Invalid number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else if (cmd == '-') {
            std::size_t n;
            if (std::cin >> n) {
                if (counter.decreaseVisitorsCount(n)) {
                    std::cout << n << " left. Total: " << counter.getVisitorsCount() << "\n";
                }
                else {
                    std::cout << "Denied: cannot go below 0. Total: " << counter.getVisitorsCount() << "\n";
                }
            }
            else {
                std::cout << "Invalid number.\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }
        else {
            std::cout << "Unknown command. Use +, -, p, q.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}
