#include <iostream>
#include <vector>

std::vector<int> createVector()
{
    std::vector<int> intList;
    std::cout << "How many numbers? ";
    int length;
    std::cin >> length;
    
    std::cout << "Please enter the numbers ";
    for (int i = 0; i < length; i++)
    {
        int num;
        std::cin >> num;
        intList.push_back(num);
    }
    return intList;
}

int findSmallest(std::vector<int> intList)
{
    int smallest = intList.at(0);
    int indexSmallest;
    for (int i = 0; i < intList.size(); i++)
    {
        if (intList.at(i) < smallest)
        {
            smallest = intList.at(i); 
            indexSmallest = i;
        }
        
    }
    return indexSmallest;
}

int findMissing(int indexSmallest, std::vector<int> intList) 
{
    const int smallest = intList.at(indexSmallest);
    int missing;
    bool numAlreadyExists = true;
    int count = 0;
    while (numAlreadyExists)
    {
        count++;
        numAlreadyExists = false;
        for (int i = 0; i < intList.size(); i++)
        {
            if (intList.at(i) == (smallest + count))
            {
                numAlreadyExists = true;
            }
            
        }
    }
    missing = smallest + count;
    return missing;
}

int main()
{
    std::vector<int> intList = createVector();
    int indexOfSmallest = findSmallest(intList);
    int smallestMissing = findMissing(indexOfSmallest, intList);

    std::cout << "The smallest missing number is " << smallestMissing << '\n';


    return 0;
}

