#include <iostream>

using namespace std;
bool checking (string number)
{
    int sign=0;
    int letter=0;
    int num=0;
    int minus=0;
    if (number[0]=='-'|| number[0]=='.'|| number[0]>='0' && number[0]<='9')
    {
        for (int i = 0; i < number.length(); ++i)
        {
            if(number[i]=='.')
                sign++;
            else if (number[i]=='-')
                minus++;
            else if(number[i]<'0'|| number[i]>'9')
                letter++;
            else if(number[i]>='0'&& number[i]<='9')
                num++;
        }
        if(sign>1||letter>0||minus>1||num==0)
            return false;
        else
            return true;
    }
    else
        return false;
}
string numLeft (string number){
    int temp=0;
    string num;
    for (int i = 0; i <number.length() ; ++i) {
        if(number[i]=='.')
            temp++;
        else if(temp==0)
            num+=number[i];
    }
    if(number[0]=='.')
        num='0';
    return num;
}
string numRight (string number){
    int temp=0;
    string num;
    for (int i = 0; i <number.length() ; ++i) {
        if(number[i]=='.')
            temp++;
        else if(temp>0)
            num+=number[i];
    }
    if(number[number.length()-1]=='.'|| temp==0)
        num='0';
    return num;
}
int main()
{
    cout << "Long number" <<endl;
    cout <<"Input number1 : \n";
    string num1,num2;
    cin>>num1;
    cout <<"Input number2 : \n";
    cin>>num2;
    if(checking(num1)&& checking(num2))
    {
        if(numLeft(num1)==numLeft(num2)&&(numRight(num1) == numRight(num2)))
            cout<<"Equal"<<endl;
        else if(numLeft(num1)<=numLeft(num2)&&(numRight(num1)<numRight(num2)))
            cout<<"Less"<<endl;
        else if(numLeft(num1)>=numLeft(num2)&&(numRight(num1)>numRight(num2)))
            cout<<"More"<<endl;
    }
    else
        cout<<"Incorrect number!!!!\n";
    return 0;
}

