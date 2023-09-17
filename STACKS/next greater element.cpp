
#include<iostream>
#include<stack>
#include<algorithm>

using namespace std;
void NGE(int arr[], int n)
{
	stack<int> s;
	int res[n];
	for (int i = n - 1; i >= 0; i--) {
		//keep popping while elements are
		//smaller and stack is not empty 
		if (!s.empty()) {
			while (!s.empty() && s.top() <= arr[i]) {
				s.pop();
			}
		}
		res[i] = s.empty() ? -1 : s.top();
		s.push(arr[i]);
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
		cout<<endl;
}
// Driver Code
int main()
{
	int cnt=0;
    int arr[10000];
    int i=0;
    while(1){
		int x;
        cin>>x;
        arr[i]=x;
        if(x==-1)
        break;
        i++;
        cnt++;
    }
    NGE(arr,cnt);
	return 0;
}
