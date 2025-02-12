#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> final;
bool valid(vector<int> &v, int n)
{
   for(int i=0; i<n*n; i++)
    {
        if(v[i]==0)
        continue;  
        int redica=i/n, kolona=i%n;

        for(int j=i+1; j<n*n; j++)
         {
            if(v[j]==0)
            {
                continue;
            }
            int redica_j=j/n, kolona_j=j%n;

            if(redica==redica_j)
            {
                return false;
            }
        
            if(kolona==kolona_j)
            {
                return false;
            }
        
            if(abs(redica-redica_j)==abs(kolona-kolona_j))
            {
                return false;
            }
            
            if(redica+kolona==redica_j+kolona_j)
            {
                return false;
            }
        }
    }
    return true;
}

void generate(vector<int> &v, int n, int i, vector<int> &queens)
{
    if(i==n)
    {
        if(valid(v,n))
        final.push_back(v);
        return;
    }
   
    int queen=queens[i];
    for(int j=0; j<n*n; j++)
    {
        if(v[j]==0)
        {
            v[j]=queen;   
            generate(v,n,i+1,queens);   
            v[j]=0;
        } 
    }
}


int main()
{
    int n=0;
    cin>>n;
    vector <int> queens(n);
    int j=1;
    for(int i=0; i<n; i++)
    queens[i]=j++;
    vector<int> v(n*n,0);
    generate(v,n,0,queens);
   
    for(auto v:final)
    {
        for(int i=0; i<n*n; i++)
        {
            cout<<v[i]<< ' ';
            if(i%n==n-1)
            cout<< '\n';
        }
       
        cout<<'\n';
    }
   
    cout<<final.size()<< '\n';
   
   
   

    return 0;
}