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
        if(temp==0)
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
int compareRight(string num1,string num2){
    int maxlength=0;
    char temp='0';
    (num1.length()>=num2.length())? maxlength=num1.length() : maxlength=num2.length();
    for (int i = 0; i < maxlength; ++i) {
        if(maxlength==num1.length()) {
            if (num1[i] > num2[i])
            return true;
            if(num1[i] < num2[i])
                return -1;
        }
        if(maxlength==num2.length()){
            if(i>=num1.length())
                if( num2[i]>temp )
                    return -1;
            if (num1[i] > num2[i])
                    return true;
        }
    }
    return false;
}
int compareLeft(string num1,string num2){
    int maxlength=0;
    char temp='0';
    int numOne=0;
    int numTwo=0;
    for (int i = 0; i < num1.length(); ++i) {
        numOne = numOne*10 + (num1[i] - '0');
    }
    for (int i = 0; i < num2.length(); ++i) {
        numTwo = numTwo*10 + (num2[i] - '0');
    }
    if (numOne>numTwo)
        return true;
    else if(numOne<numTwo)
        return -1;
    else
        return false;
}
int main()
{
    cout <<"Input number1 : \n";
    string num1,num2;
    cin>>num1;
    cout <<"Input number2 : \n";
    cin>>num2;
    if(checking(num1)&& checking(num2))
    {

        if(compareLeft(numLeft(num1), numLeft(num2))==1)
            cout<<"More"<<endl;
        if(compareLeft(numLeft(num1), numLeft(num2))==-1 && compareRight(numRight(num1), numRight(num2))==-1)
            cout<<"Less"<<endl;
        if(compareLeft(numLeft(num1), numLeft(num2))==0 && compareRight(numRight(num1), numRight(num2))==0)
            cout<<"Equal"<<endl;

    }
    else
        cout<<"Incorrect number!!!!\n";
    return 0;
}

