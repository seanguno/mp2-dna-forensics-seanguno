#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "utilities.hpp"

std::vector<std::string> SplitToVect(std::string line);
int LongestConsecutiveSubstring(std::string str_to_find, std::string dna_sequence);
std::vector<int> MaxSubs(std::vector<std::string> strs, std::string dna_sequence);
std::vector<int> PeopleCounts(std::vector<std::vector<std::string>> ppl_vector, std::vector<int> max_subs);
std::string GetMatch(std::vector<std::vector<std::string>> ppl_vector, std::vector<int> matches_vector);

#endif
