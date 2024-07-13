#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
using namespace std;
string letter[26][7];
string word;
vector<string>words;
int main(){
	freopen("input.txt","r",stdin);
    for(int i=0;i<26;i++){
        for(int j=0;j<7;j++){
            cin>>letter[i][j];
            getchar();
        }
    }
    getline(cin,word);
    while(!word.empty()){
        if(word[0]>'Z'||word[0]<'A'){
            word.erase(0,1);
        }else{
            int i=0;
            while(word[i]<='Z'&&word[i]>='A'){
                i++;
            }
            words.push_back(word.substr(0,i));
            word.erase(0,i);
        }
    }
    for(int i=0;i<words.size();i++){
        for(int j=0;j<7;j++){
            for(int k=0;k<words[i].size();k++){
                if(k==words[i].size()-1)cout<<letter[words[i][k]-'A'][j];
                else cout<<letter[words[i][k]-'A'][j]<<' ';
            }
            cout<<endl;
        }
        if(i!=words.size()-1)cout<<endl;
    }
    return 0;
}
