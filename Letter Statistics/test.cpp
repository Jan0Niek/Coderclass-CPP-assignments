#include <iostream>
#include <fstream>
#include <vector>




std::vector<int> processInputToAlphabet(std::istream& input)
{
    std::vector<int> alphabet(26);
    char letter;

    while (!input.eof())
    {
        input >> letter;
        letter = tolower(letter);
        alphabet.at(letter-97)++;
    }

    alphabet.at(letter-97)--;

    return alphabet;
}

std::vector<std::vector<int>> getVowelsAndConsonants(std::vector<int> alphabet)
{
    std::vector<int> vowels;
    std::vector<int> consonants;

    for (int i = 0; i < 26; i++)
    {
        //seperate vowels at these indices
        if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20)
        {
            vowels.push_back(alphabet.at(i));
        } else {
            consonants.push_back(alphabet.at(i));
        }
    }

    return std::vector<std::vector<int>> {vowels, consonants};

}

int main(){

    std::vector<int> alf = processInputToAlphabet(std::cin);
    
    for (int i = 0; i < 2; i++)
    {
        std::vector<int> list = getVowelsAndConsonants(alf).at(i);
        for (int j = 0; j < list.size(); j++)
        {
            std::cout << list.at(j) << std::endl;
        }
        
    }
    
    
    

    return 0;
}