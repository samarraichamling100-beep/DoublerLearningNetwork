#include <iostream>
#include <random>
int getNumber()
{
    int number;
    std::cout << "Enter the number to Guess from range(0,1000)" << std::endl;
    std::cin >> number;
    //If number is less than zero
    if(number < 0)
    {
        std::cout << "Please enter a number higher than 0 and less or equal to 1000" << std::endl;
        getNumber();
    }
    //if the number range is higher than zero
    else if(number > 1000)
    {
        std::cout << "Please enter a number lower or equal to 1000 and greater or equal to 0" << std::endl;
        getNumber();
    }
    return number;
}
void CheckAndGetNewDistributer(int guess,int Number,std::uniform_int_distribution<int> & Distributer,int &min,int &max)
{
    //Removed min max defination here to make the min max actually work
    if (Number > guess)
    {
        //Setting the minumin to guess + 1 since the guess is smaller than Number 
        min = guess + 1;
    }
    else if (Number < guess)
    {
        //Setting the max to guess - 1 since the guess is larger than Number 
        max = guess - 1;
    }
    std::cout << "Min : " << min << std::endl;
    std::cout << "Max : " << max << std::endl;

    std::uniform_int_distribution<int> NewDistributer(min, max);

    Distributer = NewDistributer;
}

int TheGuess(std::uniform_int_distribution<int> Distributer,std::mt19937 &gen,int & attempts)
{
    int Guess = Distributer(gen);
    attempts ++;
    std::cout << "the guess was " << Guess << std::endl;

    return Guess;
}
int main ()
{
    //sets up the random number gen
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> Distributer(0,1000);
    int min = 0;
    int max = 1000;

    int attempts = 0;
    //Gets the Number to guess
    int TheMainNumber = getNumber();
    //generates a guess from the range
    int guess = TheGuess(Distributer,gen,attempts);

    while(TheMainNumber != guess)
    {
        CheckAndGetNewDistributer(guess,TheMainNumber,Distributer,min,max);
        guess = TheGuess(Distributer,gen,attempts);
    }

    std::cout << "it took " << attempts << " attempts to find the number" << std::endl;
    return 0;
}