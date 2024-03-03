#include<bits/stdc++.h>
using namespace std;

int main()
{
    auto start = std::chrono::system_clock::now();
    string inputFilePath;
    cin>>inputFilePath; // Enter full path of file which contains input. e.g  /Users/prate/OneDrive/Documents/Input_02.txt

    ifstream inputFile(inputFilePath);
    string word;
    vector<string> words;
    unordered_set<string> unSet;
    if(inputFile.is_open()) 
    {
        while(getline(inputFile,word))
        {
            words.push_back(word);
            unSet.insert(word);
        }
        inputFile.close();
    }
    else 
    {
        cout<<"Failed to open given file. Please enter correct file path."<< endl;
    }

    string longCompWord,secLongCompWord;
    int longCompWordLen=0,secLongCompWordLen=0;
    for(auto &word: words)
    {
        int n=word.size();
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            bool ans=false;
            for(int j=i;j<n;j++)
            {
                dp[i]|=((i!=0 || j!=n-1) && unSet.find(word.substr(i,j-i+1))!=unSet.end() && dp[j+1]);
            }
        }
        if(dp[0])
        {
            if(n>=longCompWordLen)
            {
                secLongCompWordLen=longCompWordLen;
                secLongCompWord=longCompWord;
                longCompWordLen=n;
                longCompWord=word;
            }
            else if(n>secLongCompWordLen)
            {
                secLongCompWordLen=n;
                secLongCompWord=word;
            }
        }
    }

    string outputFilePath;
    cin>>outputFilePath;  // Enter full path of file which will contain output. e.g  /Users/prate/OneDrive/Documents/Output_02.txt
    ofstream outputFile(outputFilePath);
    outputFile<<"Longest Compound Word :- "<<longCompWord<<endl;
    outputFile<<"Second Longest Compound Word :- "<<secLongCompWord<<endl;
    auto end=std::chrono::system_clock::now();
    outputFile<<"Time taken to process given file :- "<<std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()<<" milli seconds"<<endl;
}