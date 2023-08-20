#include <iostream>
#include <fstream>

#include "functions.hpp"
#include "utilities.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " [input_file] [dna_sequence]"
             << std::endl;
    return 1;
  }

std::ifstream input(argv[1]);
std::string test;
std::getline(input, test);
std::vector<std::string> strs = SplitToVect(test);
std::string dna_sequence = argv[2];
std::vector<int> max_substrings = MaxSubs(strs, dna_sequence);
std::vector<std::vector<std::string>> people_vectors;
for(std::string line; std::getline(input, line); line = "") {
  people_vectors.push_back(SplitToVect(line));
}
std::vector<int> ppl_counts = PeopleCounts(people_vectors, max_substrings);
std::string match = GetMatch(people_vectors, ppl_counts);
std::cout << match << std::endl;
return 0;
}
