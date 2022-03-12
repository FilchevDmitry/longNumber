#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    cout << "Long real number" <<endl;
    cout <<"Input number : ";
    string number;
    int sign=0;
    int letter=0;
		int num=0;
    cin>>number;
    if (number[0]=='-'|| number[0]=='.'|| number[0]>='0' && number[0]<='9')
    {
        for (int i = 0; i < number.length(); ++i)
        {
            if(number[i]=='.')
                sign++;
            else if(number[i]<'0' || number[i]>'9')
                letter++;
						else if(number[i]>='0'&& number[i]<='9')
							num++;
        }
        if(sign>1 && letter>0 || sign>1 && letter==0 || sign==0 && letter>0&& num==0|| num==0)
        cout<<"NO"<<endl;
        else
        cout<<"YES"<<endl;
    }
    else
        cout<<"No"<<endl;

    return 0;
}

