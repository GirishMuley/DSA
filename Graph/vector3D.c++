#include<bits/stdc++.h>
using namespace std;

int main(){
vector < vector < vector<int> > > tube;

for(int i=0;i<1;i++)
{
   for(int j=0;j<6;j++)
   {
     for(int k=0;k<3;k++)
     {
     int value;
     tube.push_back( vector< vector<int> >() );
     tube[k].push_back (vector<int> ());
     tube[i][j].push_back(value);
     }
   }
}

for (int i = 0; i < tube.size(); i++) {
		for (int j = 0; j < tube[i].size(); j++) {
			for (int k = 0; k < tube[i][j].size(); k++) {
				cout << tube[i][j][k] << " ";
			}
			cout << endl;
		}
	}

    return 0;
}