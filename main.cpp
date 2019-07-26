/*
Recursion
(c) 2016
Author: David Erbelding
Written under the supervision of David I. Schwartz, Ph.D., and
supported by a professional development seed grant from the B. Thomas
Golisano College of Computing & Information Sciences
(https://www.rit.edu/gccis) at the Rochester Institute of Technology.
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



// Include iostream for output during the program.
#include <iostream>
// Use std to avoid writing std:: everywhere.
using namespace std;

// Recursion is not a feature specific to C++, instead it is a process used by programmers in all languages.
// Recursion is the process by which a function executes itself.

// The most common example of this is the Fibonacci Sequence
// In the fibonacci sequence, each number is calculated by adding the previous two numbers together.
// The series starts with 1, 1, and continues with 2, 3, 5, 8, 13, 21 . . .
// We can use recursion to create a function that gives us the nth number in the sequence.

// Firstly, we'll use an unsigned integer, since the sequence doesn't use numbers lower than 0.
unsigned int fibonacciRecursive(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        // The first and second values are always 1.
        return 1;
    }
    else
    {
        // Any value after that will be equal to the previous two numbers added together.
        return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
    }
}

// Similar to the recursive function, this one keeps track of previous values so that we don't need to recalculate them.
// This is the way we would calculat the sequence on paper anyway right?
unsigned int fibonacciWithLoop(unsigned int n)
{
    if (n == 0 || n == 1)
    {
        // The first and second values are always 1.
        return 1;
    }
    else
    {
        // Start with these base cases.
        unsigned int nMinus2 = 1;
        unsigned int nMinus1 = 1;

        // start with 2, and loop until we reach n
        for (unsigned int i = 2; i <= n; i++)
        {   
            // calculate the number at i:
            int newNumber = nMinus1 + nMinus2;

            // Save the previous two numbers for the next calculation.
            nMinus2 = nMinus1;
            nMinus1 = newNumber;
        }
        // If we reach the end of the loop, nMinus1 holds the value we want.
        return nMinus1;
    }
}


// Say we want to raise an integer to an integer power:
// This example uses recursion to avoid calculating the same value multiple times.
unsigned int raiseToPower(unsigned int base, unsigned int exponent)
{
    if (exponent == 0)
    {
        // n^0 = 1
        return 1;
    }
    else if (exponent == 1)
    {
        // n^1 = 1
        return base;
    }
    else
    {
        // get the number raised to a lower power, and use that to calculate this one.
        unsigned int result = raiseToPower(base, exponent / 2);

        // n^2 * n^2 = n^4
        result *= result;

        // What if exponent was odd though?
        if (exponent % 2 == 1)  // % 2 is mod 2, gets the remainder of division by 2.
        {
            // If the exponent was odd, multiply in the base one extra time.
            result *= base;
        }

        // This should be our answer:
        return result;
    }
}



// Start of main function
int main() 
{
    cout << "Test of fibonacci sequence: " << endl;
    // Loop and print the first 10 numbers
    for (unsigned int i = 0; i < 10; i++)
    {
        cout << i << ": " << fibonacciRecursive(i) << endl;
    }

    // If you try printing out a really large number, it takes a long time to compute:
    cout << "\npress enter to start calculating fibonacci(40):";
    cin.get();
    cout << 40 << ": " << fibonacciRecursive(40) << endl;

    // This is because each number has to calculate the previous 2 numbers, and add them together.
    // e.g.
    // passing in 4 does this:
    // 4 calls 3:
    //   3 calls 2:
    //     2 calls 1:
    //       1 returns 1
    //     2 calls 0:
    //       0 returns 1
    //     2 returns 1+1=2
    //   3 calls 1:
    //     1 returns 1
    //   3 returns 2+1=3
    // 4 calls 2:
    //   2 calls 1:
    //     1 returns 1
    //   2 calls 0:
    //     0 returns 1
    //   2 returns 1+1=2
    // 4 returns 3+2=5
    
    // You can imagine how crazy this gets for numbers larger than 4.


    // Fortunately there's a way around this. We can use a loop instead:
    cout << "\npress enter to start calculate with a loop instead of recursion:";
    cin.get();
    cout << 40 << ": " << fibonacciWithLoop(40) << endl;


    // Recursion is more useful when you can't use tricks like with the fibonacci numbers.
    cout << "press enter to start calculate powers of 2: ";
    cin.get();
    for (unsigned int i = 0; i < 32; i++)
    {
        cout << "2^" << i << " = " << raiseToPower(2, i) << endl;
    }


    cout << "End of program." << endl;
    cin.get();
    return 0;   // End Program.
}