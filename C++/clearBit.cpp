//Clearing the bit means to set the value of the bit at a given position to 0.
//The concept revolves around using the left shift operator to shift the binary form of 1 (0001) by the given position so that 1 is present at the required position. For ex: If I want to get the bit of a particular number at the 2nd position, I will leftshift 10 by 2 so that it becomes 0100. Now we will take the complement of it as ~(0100) which will make it (1011).
//Now if we perform an and operation on 1011 and the required number, we will get the bit. If it's 1, then the bit of the position (2nd position) is 1 as 1&0 = 0 whereas if it's 0, then the bit is 0 as 0&0=0.Thus, we have cleared the bit.

#include <iostream>
using namespace std;


int clearbit(int n, int pos)
{
    int mask=~(1<<pos);            //creating the complement of the temporary variable to which we have used the left shift operator
    return(mask & n);              
}

int main()
{
    int n,pos;
    cin>>n>>pos;

    cout<<clearbit(n,pos)<<endl;

    return 0;
    
}