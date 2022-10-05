//Used to get the bit (1 or 0) at a given position of the given number.
//The concept revolves around using the left shift operator to shift the binary form of 1 (0001) by the given position so that 1 is present at the required position. For ex: If I want to get the bit of a particular number at the 2nd position, I will leftshift 10 by 2 so that it becomes 0100. 
//Now if we perform an and operation on 0100 and the required number, we will get the bit. If it's 1, then the bit of the position (2nd position) is 1 as 1&1 = 1 whereas if it's 0, then the bit is 0 as 1&0=0.


#include <iostream>
using namespace std;


int getbit(int n, int pos)
{
    int temp=1<<pos;            //creating a temporary variable to which we have used the left shift operator
    return((temp&n)!=0);        //this returns (temp&n) !=0. We did this as temp&n will return the decimal value instead of the required bit. that's why we are basically checking it with 0. If it was 0; 0!=0 will give false or 0 which is the required bit while if the bit was 1; 1!=0 will give true or 1 which is the required bit.
}

int main()
{
    int n,pos;
    cin>>n>>pos;

    cout<<getbit(n,pos)<<endl;

    return 0;
    
}