#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    string s,t;
	    cin>>s>>t;
	    int size = t.size();
	    map<char,int> secondstring;
	    map<char,int> orignal_counter;
	    int start=0;
	    int ans_start=INT_MAX;
	    int ans_end=INT_MAX;
	    int counting = 0;
	    int diff = INT_MAX;
	    int i=0;
	    for(int i=0;i<size;i++){
	        secondstring[t[i]]++;
	    }
	    for(i=0;i<s.size();i++){
	            orignal_counter[s[i]]++;
	            if(orignal_counter[s[i]]==secondstring[s[i]])
	                counting += orignal_counter[s[i]];
                if(counting == size){
	            // window moving
	            while(start<i){
	                if(secondstring[s[start]]==0){
	                    start++;
	                }
	                else if(secondstring[s[start]]<orignal_counter[s[start]]){
	                    orignal_counter[s[start]]--;
	                    start++;
	                }
	                else{
	                    break;
	                }
	            }
	            //cout<<start<<" "<<i<<endl;
	            if(diff>(i-start)){
	                diff=i-start;
	                ans_start = start;
	                ans_end = i;
	            }
	 
	            
	        }
	    }
	    
	    if(diff!=INT_MAX){
	        for(int i=ans_start;i<=ans_end;i++){
	            cout<<s[i];
	        }
	        cout<<endl;
	    }
	    else
	        cout<<"-1"<<endl;
	    
	}
	return 0;
}
