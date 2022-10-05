//Setting the bit means to set the value of the bit at a given position to 1.
//The concept revolves around using the left shift operator to shift the binary form of 1 (0001) by the given position so that 1 is present at the required position. For ex: If I want to get the bit of a particular number at the 2nd position, I will leftshift 10 by 2 so that it becomes 0100. 
//Now if we perform an or operation on 0100 and the required number, we will get the bit. If it's 1, then the bit of the position (2nd position) is 1 as 1or1 = 1 whereas if it's 0, then the bit is 0 as 1or0=1.Thus, we have set the bit.

#include <iostream>
using namespace std;


int setbit(int n, int pos)
{
    int temp=1<<pos;            //creating a temporary variable to which we have used the left shift operator
    return(temp|n);       
}

int main()
{
    int n,pos;
    cin>>n>>pos;

    cout<<setbit(n,pos)<<endl;

    return 0;
    
}