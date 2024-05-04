#include <iostream>

using namespace std;

void askRange(int &rangeMin, int &rangeMax, int MIN, int MAX);
void goldbachEuler(int rangeMin, int rangeMax);
bool isPrime(int number);

int main()
{
    const int MIN = 2, MAX = 1000001;
    int rangeMin, rangeMax;
    char continueChoice = 's'; 

    cout << "Welcome! This program performs the Goldbach-Euler algorithm.\n";
    while (continueChoice == 's' || continueChoice == 'S') {
        askRange(rangeMin, rangeMax, MIN, MAX);
        goldbachEuler(rangeMin, rangeMax);
        cout << "Do you want to enter a new range (y/n)? ";
        cin >> continueChoice;
    }

    return 0;
}

/**
 * Asks the user to input two integers and verifies that they are within the range
 * [Min, max] and that rangeMin is less than or equal to rangeMax.
 * 
 * @param rangeMin : the minimum value of the range of even numbers to consider
 * @param rangeMax : the maximum value of the range of even numbers to consider
 * @param Min : the minimum value accepted for rangeMin and rangeMax
 * @param max : the maximum value accepted for rangeMin and rangeMax
 * 
 */
void askRange(int &rangeMin, int &rangeMax, int MIN, int MAX) {
    do {
        cout << "\nEnter the minimum and maximum range of values to print: ";
        cin >> rangeMin >> rangeMax;
    } while (rangeMin < MIN || rangeMax > MAX || rangeMin > rangeMax);
}

/**
 * Goldbach-Euler: Finds the pair of prime numbers
 * that sum up to an even number within the range [rangeMin, rangeMax].
 * Then prints the found pairs in the following format:
 * "i = firstPrime + secondPrime".
 * 
 * @param rangeMin : the minimum of the range of even numbers to consider
 * @param rangeMax : the maximum of the range of even numbers to consider
 * 
 */
void goldbachEuler(int rangeMin, int rangeMax) {
    for (int i = rangeMin; i <= rangeMax; i += 2) {
        int firstPrime, secondPrime;
        if (i % 2 == 0 || ++i % 2 == 0) {
            firstPrime = secondPrime = i / 2;
            while ((!isPrime(firstPrime) || !isPrime(secondPrime)) || firstPrime + secondPrime != i) {
                firstPrime--;
                secondPrime++;
            }
        }
        cout << i << " = " << firstPrime << " + " << secondPrime << endl;
    }
}

/*
 * Checks if an integer is prime.
 * 
 * @param number: the number to check.
 * @return true if the number is prime, false otherwise.
 * 
 */
bool isPrime(int number) {
    bool prime = true;

    if (number == 2 || number == 3) 
        prime = true;
    else {
        for (int divisor = 2; (divisor * divisor) <= number; divisor++) {
        if (number % divisor == 0) 
            prime = false;
        }
    }
    return prime;
}
