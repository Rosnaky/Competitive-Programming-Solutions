#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n; cin>>n;
	int order[n];
	vector<pair<int, int>> east, north;
	map<int, int> ans;

	for(int i = 0; i < n; i++) {
		string dir;
		int x, y;
		cin>>dir>>x>>y;

		order[i] = x;
		ans[x] = -1;

		if(dir=="E") {
			east.push_back(make_pair(x,y));
		}
		else{
			north.push_back(make_pair(x,y));
		}
	}

	sort(north.begin(), north.end());
	sort(east.begin(), east.end(), [](const pair<int,int> &left, const pair<int,int> &right) {
		return left.second < right.second;
	});

	for(auto i : east) {
		for(auto j : north) {
			if(ans[j.first]!=-1) {
				continue;
			}
			if (i.first<j.first && i.second>j.second) {
				int d1 = j.first-i.first;
				int d2 = i.second-j.second;
				if(d1>d2) {
					ans[i.first]=d1;
					break;
				}
				else if(d1<d2) {
					ans[j.first]=d2;
				}
			}
		}
	}

	for(int i : order) {
		if(ans[i]==-1) {
			cout<<"Infinity"<<endl;
		}
		else{cout<<ans[i]<<endl;}
	}

    

}