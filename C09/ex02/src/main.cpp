#include "PmergeMe.hpp"
#include <iostream>

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

char **createFakeArgv(const std::vector<std::string> &args) {
    char **argv = new char*[args.size() + 1];
    for (size_t i = 0; i < args.size(); ++i) {
        argv[i] = const_cast<char*>(args[i].c_str());
    }
    argv[args.size()] = NULL;
    return argv;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }

    PmergeMe sorter;
    std::string mode = argv[1];
    if (mode == "random") {
        if (argc != 3) {
            std::cerr << "Usage for random: ./PmergeMe random <size>" << std::endl;
            return 1;
        }

        int size = std::atoi(argv[2]);
        if (size <= 0) {
            std::cerr << "Error: Size must be positive." << std::endl;
            return 1;
        }

        // Generate random numbers
        std::vector<std::string> argsStore;
        argsStore.push_back(argv[0]); // Program name

        std::srand(std::time(NULL));
        std::cout << "Generating " << size << " random numbers..." << std::endl;

        for (int i = 0; i < size; ++i) {
            std::stringstream ss;
            ss << (std::rand() % 100000 + 1); // Random num between 1 and 100000
            argsStore.push_back(ss.str());
        }

        // Create fake argv to pass to PmergeMe
        char **fakeArgv = createFakeArgv(argsStore);

        // Run the sorter with generated args
        sorter.sortAndMeasure(size + 1, fakeArgv);

        delete[] fakeArgv; // Cleanup (container only, strings are in argsStore)
    } else {
		try {
			sorter.sortAndMeasure(argc, argv);
		} catch (const std::exception &e) {
			std::cerr << "Error" << std::endl;
			return 1;
		}
	} 
    return 0;
}
