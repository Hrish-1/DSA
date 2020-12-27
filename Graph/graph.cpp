#include<bits/stdc++.h>
using namespace std;

int Get_Value(string str, pair <string,int> p[])
{
    for(int i=0;i<3;i++)
    {
        if(str==p[i].first)
        {
            return (p[i].second);
        }
    }
        //cout<<"Please enter valid string"<<endl;
        return -1;
}



int main()
{
	pair <string ,int> Map[3];
	for(int i=0;i<3;i++)
	{
		cin>>Map[i].first;
		cin>>Map[i].second ;
	}
	int arr[3][3];
	for(int i=0;i<3;i++)
	{
		for(int j=i;j<3;j++)
		{
			cin>>arr[i][j];
			arr[j][i] = arr[i][j];
		}
	}
	string str1,str2;
    while(1)
    {
        cout<<"Enter first string"<<endl;
        cin>>str1;
        int sum = 0;
        if(str1=="Add")
        {
            cin>>str1;//mumbai
           int x = Get_Value(str1,Map);
            while(1)
            {
                cin>>str2;//pune
                //cin>>str1;
                if(str2=="End")
                {
                    cout<<"Total Distance = "<<sum<<endl;
                    break;
                }
                //x = Get_Value(str1);
              int  y = Get_Value(str2,Map);
                if(x==-1 || y==-1)
                {
                    cout<<"ENTER INVALID STRING"<<endl;
                    continue;
                }
                sum += arr[x][y];
                x=y;
            }
            continue;
        }

        if(str1=="End")
        {
            break;
        }
        cout<<"Enter second string"<<endl;
        cin>>str2;
        int x = Get_Value(str1,Map);
        int y = Get_Value(str2,Map);
        if(x==-1 || y==-1)
        {
            cout<<"Enter Valid String"<<endl;
            continue;
        }
        cout<<"Distance = "<<arr[x][y]<<endl;
    }
    return 0;
}
