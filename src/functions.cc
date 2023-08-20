#include "functions.hpp"

std::vector<std::string> SplitToVect(std::string line) {
    std::string to_add;
    std::vector<std::string> to_return;
    for (unsigned int i = 0; i < line.length(); ++i) {
        switch (line.at(i))
        {
        case ',' :
            to_return.push_back(to_add);
            to_add = "";
            break;
        
        default:
            to_add += line.at(i);
            break;
        }
    }
    to_return.push_back(to_add);
    return to_return;
}

int LongestConsecutiveSubstring(std::string str_to_find, std::string dna_sequence) {
    int count = 0;
    int max = 0;
    for (unsigned int i = 0; i < dna_sequence.length() - str_to_find.length() + 1; ++i) {
        std::string test = dna_sequence.substr(i, str_to_find.length());
        if (dna_sequence.substr(i, str_to_find.length()) == str_to_find) {
            count++;
            if (i + str_to_find.length() < dna_sequence.length() - str_to_find.length() + 1) {
                i += str_to_find.length() - 1;
            } 
        } else {
            count = 0;
        }
        if (count > max) {
            max = count;
        }
    }
    return max;
}

std::vector<int> MaxSubs(std::vector<std::string> strs, std::string dna_sequence) {
   std::vector<int> to_return;
   for (unsigned long idx = 1; idx < strs.size(); ++idx) {
    to_return.push_back(LongestConsecutiveSubstring(strs.at(idx), dna_sequence));
   }
   return to_return;
}

std::vector<int> PeopleCounts(std::vector<std::vector<std::string>> ppl_vector, std::vector<int> max_subs) {
    std::vector<int> to_return;
    for (unsigned long i = 0; i < ppl_vector.size(); ++i) {
        unsigned int count = 0;
        for (unsigned long j = 0; j < max_subs.size(); ++j) {
            if (max_subs.at(j) == std::stoi(ppl_vector.at(i).at(j + 1))) {
                count++;
            }
        }
        to_return.push_back(count);
    }
    return to_return;
}

std::string GetMatch(std::vector<std::vector<std::string>> ppl_vector, std::vector<int> matches_vector) {
    int max_idx = -1;
    for (size_t i = 0; i < matches_vector.size(); ++i) {
        if (matches_vector.at(i) == 3 && max_idx != -1) {
            return "No match";
        }
        if (matches_vector.at(i) == 3) {
            max_idx = i;
        }
    }
    if (max_idx == -1) {
        return "No match";
    }
    return ppl_vector.at(max_idx).at(0);
}


//std::vector<std::vector<unsigned int>> PeopleToVectors(std::ifstream text_file) {
//
//}
