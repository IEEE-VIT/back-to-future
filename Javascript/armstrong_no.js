
// Program to chech whether is a number is armstrong number or not in javascript

function armstrong(num){

    var temp=num;
    var arm = 0;
    while(temp>0)
    {
        var a=temp%10;
        temp=parseInt(temp/10);
        arm=arm+a*a*a;
    }

    if(arm == num)return true;

    return false;

}

console.log(armstrong(370));

//Output
// true