#include <iostream>
#include <fstream>
#include <vector>

std::vector<int> processInputToAlphabet(std::istream& input)
{
    std::vector<int> alphabet(26);
    char letter = 'a';

    while (!input.eof())
    {
        input >> letter;
        letter = tolower(letter);
        if ((letter-0) >= 97 && (letter-0) <= 122) alphabet.at(letter-97)++;
    }
    if ((letter-0) >= 97 && (letter-0) <= 122) alphabet.at(letter-97)--;
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

int findMostCommonsIndex(std::vector<int> list)
{
    int highest = 0;
    int index = 0;
    for (int i = 0; i < list.size(); i++)
    {
        if (list.at(i) > highest)
        {
            highest = list.at(i);
            index = i;
        }
    }
    return index;
}

std::vector<int> getAlphabet(int argc, char* argv[])
{
    if (argc == 1)
    {
        return processInputToAlphabet(std::cin);
    } 
    else if (argc == 2)
    {
        std::ifstream fileIn;
        fileIn.open(argv[1]);

        if (!fileIn.is_open())
        {
            std::cout << "cannot open input file " << argv[1] << std::endl;
            return std::vector<int>(1);
        }
        return processInputToAlphabet(fileIn);
        fileIn.close();

    } else {
        std::cout << "cannot handle parameter list" << std::endl;
        return std::vector<int>(1);
    }
}

int main(int argc, char* argv[])
{
    std::vector<char> CONSONANTS {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    std::vector<char> VOWELS {'a', 'e', 'i', 'o', 'u'};
    
    std::vector<int> alphabet = getAlphabet(argc, argv);
    if (alphabet.size() != 26) return 1;

    std::vector<std::vector<int>> vowelsAndConsonants = getVowelsAndConsonants(alphabet);
    std::vector<int> vowels = vowelsAndConsonants.at(0);
    std::vector<int> consonants = vowelsAndConsonants.at(1);

    char mostCommonVowel = VOWELS.at(findMostCommonsIndex(vowels));
    int vowelFrequency = vowels.at(findMostCommonsIndex(vowels));

    char mostCommonConsonant = CONSONANTS.at(findMostCommonsIndex(consonants));
    int consonantFrequency = consonants.at(findMostCommonsIndex(consonants));

    int mostCommonLetterIndex = findMostCommonsIndex(alphabet);
    int letterFrequency = alphabet.at(mostCommonLetterIndex);
    char mostCommonLetter = 97 + mostCommonLetterIndex;
    
    std::cout << "Most frequent vowel: " << mostCommonVowel << " (" << vowelFrequency << " times)" << std::endl;
    std::cout << "Most frequent consonant: " << mostCommonConsonant << " (" << consonantFrequency << " times)" << std::endl;
    std::cout << "Most frequent letter, overall: " << mostCommonLetter << " (" << letterFrequency << " times)" << std::endl;
    
    return 0;
}