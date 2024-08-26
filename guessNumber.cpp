// We are playing the Guess Game. The game is as follows:
// I pick a number from 1 to n. You have to guess which number I picked.
// Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.
// You call a pre-defined API int guess(int num), which returns three possible results:
// -1: Your guess is higher than the number I picked (i.e. num > pick).
// 1: Your guess is lower than the number I picked (i.e. num < pick).
// 0: your guess is equal to the number I picked (i.e. num == pick).
// Return the number that I picked.

#include <iostream>
using namespace std;


// Mock of the guess API (to be provided)
int guess(int num) 
{
    int pick = 6; // Assume the number picked is 6 for this example
    if (num > pick) return -1;
    if (num < pick) return 1;
    return 0;
}

int guessNumber(int n) 
{
    long long low=1, high=n,mid;
    while(low<=high) {
        mid=(low+high)/2;
        if(guess(mid)==0) return mid;
        if(guess(mid)<0) high=mid-1;
        else low=mid+1;
    }
    return -1;
}

int main() 
{
    int n = 10; // Example range
    int result = guessNumber(n);
    cout << "The picked number is " << result << endl;
    return 0;
}