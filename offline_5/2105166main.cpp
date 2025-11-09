#include "2105166pq.hpp"
#include <fstream>

int main() {
    std::ifstream infile("in.txt");
    std::ofstream outfile("out.txt");

    if (!infile) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }
    if (!outfile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }
    priorityqueue<int> pq;

    int choice;
    while (infile >> choice) {
        switch (choice) {
            case 1: {
                int x;
                infile >> x;
                pq.insert(x);
                break;
            }
            case 2: {
               int maxElement;
                if (pq.findmax(maxElement, outfile)) {
                    outfile <<"Max: "<< maxElement << std::endl;
                }
                break;
            }
            case 3: {
                int maxElement;
                if (pq.ExtractMax(maxElement, outfile)) {
                    outfile <<"Max: "<< maxElement <<" has been extracted."<<std::endl;

                }
                break;
            }
            case 4: {
                int i, newKey;
                infile >> i >> newKey;
                if(pq.increasekey(i, newKey, outfile)){
                outfile<<"Key increased!"<<std::endl;
                }
                break;
            }
            case 5: {
                int i, newKey;
                infile >> i >> newKey;
                if(pq.decreasekey(i, newKey, outfile)){
                outfile<<"Key decreased!"<<std::endl;
                }
                break;
            }
            case 6: {
                outfile <<"No of elements: "<<pq.size()<< std::endl;
                pq.Print(outfile);
                outfile << std::endl;
                break;
            }
            case 7: {
                pq.Sort(outfile);
                //pq.Print(outfile);
                outfile << std::endl;
                break;
            }
            default:
                std::cerr << "Invalid choice: " << choice << std::endl;
        }
    }

    infile.close();
    outfile.close();

    return 0;
}