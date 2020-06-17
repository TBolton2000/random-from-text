#include<fstream>
#include<iostream>
#include<vector>
#include<chrono>
#include"MapTree.h"

double create_random_file(std::string inFileName, std::string outFileName, int window_size){
    std::ifstream inFile(inFileName);
    std::ofstream outFile(outFileName);

    if (!inFile) {
        std::cerr << "File, " << inFileName << ", could not be opened for reading." << std::endl;
        exit(1);
    }

    if (!outFile) {
        std::cerr << "File, " << outFileName << ", could not be opened for writing." << std::endl;
        exit(1);
    }

    int window = window_size;
    //std::cout << "Enter the window size: ";
    //std::cin >> window;

    std::vector<char> queue;
    std::vector<char> out_queue;
    for(int i = 0; i < window; i++) {
        queue.push_back(inFile.get());
        out_queue.push_back(queue.at(i));
        outFile << queue.at(i);
    }
    
    MapTree map;

    int count = 0;
    while (inFile.good()) {
        std::string key = "";
        char nextChar = inFile.get();
        try{
            if (nextChar == '\n')
                continue;
            for (size_t i = 0; i < queue.size(); i++)
                key += queue.at(i);
            queue.push_back(nextChar);
            if(map.isIn(key))
                map.find(key).occurs(nextChar);
            else{
                map.put(key,CharDistribution());
                map.find(key).occurs(nextChar);
            }
        }
        catch(std::exception &e) {
            //std::cout << "Error: !!!!!!!!!!!" << e.what() << " at " << count << std::endl;
        }
        //std::cout << "Key: \"" << key << "\" Value: \"" << queue.at(queue.size()-1) << "\"" << " Iteration: " << count << std::endl;
        queue.erase(queue.begin());

        count++;
    }

    inFile.close();

    int out_size = 10000000;
    //std::cout << "Enter the number of characters randomly generated: ";
    //std::cin >> out_size;
    auto start = std::chrono::high_resolution_clock::now();
    int num_of_spaces = 0;
    for (size_t i = 0 ; i < out_size - window; i++) {
        std::string key = "";
        for (size_t i = 0; i < out_queue.size(); i++){
            key += out_queue.at(i);
        }
        char newChar = map.find(key).getRandomChar();
        if (newChar == ' ')
            num_of_spaces++;
        outFile << newChar; 
        out_queue.push_back(newChar);
        out_queue.erase(out_queue.begin());
        if(num_of_spaces == 9){
            outFile << "\n";
            num_of_spaces = 0;  
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();

    //std::cout << "Time taken by the BST implementation for window size = " << window << ", and output size = " << out_size << ", is " << time_taken << std::endl;

    return time_taken;
    //return 0;
}
