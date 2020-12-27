#include<bits/stdc++.h>
using namespace std;
int **arr;
list<int> *adj;
int V;
int E;

void add_edge(int i,int j)
{
    cout<<"In Addedge"<<endl;
    adj[i].push_back(j);
}

void push_edge()
{
        adj = new list<int>[E];

    for(int i=0;i<V;++i)
    {
        for(int j=0;j<E;j++)
        {
            if(arr[i][j]!=0)
            {
                cout<<"i= "<<i<<" "<<"j= "<<j<<endl;
                add_edge(i,j);

            }
        }
    }
}

/*void prinadj()
{
    cout<<"In Printing adj"<<endl;
    list<int>::iterator i;


        for (auto it = adj[*i].begin(); it != adj[*i].end(); ++it)
            cout << ' ' << *it;

}*/

int Getindex(string str,string s[])
{
    for(int i=0;i<V;i++)
    {
        if(str==s[i])
        {
            //cout<<"Equal"<<endl;
            return i;
        }
    }
}
int Get_Value(string str,string p[])
{
    for(int i=0;i<V;i++)
    {
        if(str==p[i])
        {
            return (i);
        }
    }
        //cout<<"Please enter valid string"<<endl;
        return -1;
}




void BFS(string str[],string s1)
{
    int visit[V];
    for(int i=0;i<V;i++)
    {
        visit[i]=0;
    }
    list< string > Queue;

    int j = Getindex(s1,str);
    visit[j]=1;
    Queue.push_back(s1);
    //string s1;
    list<int>::iterator i;
    //push_edge();
    while(!Queue.empty())
    {
        s1 = Queue.front();
        j = Getindex(s1,str);
        //cout<<"j= "<<j<<endl;
        cout<<s1<<" ";
        Queue.pop_front();

        for(  i = adj[j].begin();i!=adj[j].end();i++)
        {
            if(!visit[*i])
            {
                visit[*i] = 1;
                Queue.push_back(str[*i]);
                //cout<<str[*i]<<endl;
            }
        }
    }

}




int main()
{
    cout<<"Enter no of Vertices:"<<endl;
    int vertexes;
    cin>>vertexes;
    cout<<"Enter no of Edges:"<<endl;
    int edges;
    cin>>edges;
    V = vertexes;
    E = edges;
    arr = new int*[V];

    string Map[vertexes];
	for(int i=0;i<vertexes;i++)
	{
	    arr[i] = new int [E];
		cin>>Map[i];
		//Map[i].second = i;
	}

	for(int i=0;i<=vertexes;i++)
	{
		for(int j=i;j<edges;j++)
		{
			cin>>arr[i][j];//    add edge( i , j )        addedge (0,0)
			arr[j][i] = arr[i][j];
		}
	}
	push_edge();
	cout<<endl;
	//prinadj();
	while(1)
    {
        cout<<"Enter Root String: "<<endl;
        string str;
        cin>>str;
        if(str=="end")
        {
            break;
        }
        int x = Get_Value(str,Map);
        if(x!=-1)
        {
                BFS(Map,str);
                cout<<endl;
        }
        else
            cout<<"Enter valid string"<<endl;
    }


	/*string str1,str2;
    while(1)
    {
        cin>>str1;
        if(str1=="End")
        {
            break;
        }
        cin>>str2;
        int x = Get_Value(str1,Map);
        int y = Get_Value(str2,Map);
        if(x==-1 || y==-1)
        {
            cout<<"Enter Valid String"<<endl;
            continue;
        }
        cout<<"Distance = "<<arr[x][y]<<endl;


    }*/
}
