//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

 // } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    int search(int arr[],int l,int h,int key)
    {
        if(l<=h)
        {
            int mid=(l+h)/2;
            if(arr[mid]==key)
                return mid;
            else
                if(arr[mid]>key)
                    return search(arr, l , mid-1 , key);
            return search(arr, mid+1 , h ,key);
        }
        return -1;
    }

    bool findTriplets(int arr[], int n)
    { 
        //Your code here
        sort(arr,arr+n);
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int k = search(arr,j+1,n-1,-arr[i]-arr[j]);
                if(k!=-1)
                {
                    // cout<< arr[i] << " " << arr[j] << " " << arr[k] <<endl;
                    return true;
                }
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}  // } Driver Code Ends