#include<bits/stdc++.h>
#include<iostream>
using namespace std;
map<string,vector<string>> rules;
  void addToChart(string a,vector<pair<pair<string,string>,int>>& chart,map<string,vector<string>>& rules,int chartNo)
  {
      for(auto i:rules)
      {
          if(i.first == a)
          {
              for(auto l:i.second)
              {
                  chart.push_back({{a,"."+l},chartNo});
                  addToChart(l,chart,rules,chartNo);
              }
          }
      }
  }
  void lookFor(char toLookFor,vector<vector<pair<pair<string,string>,int>>> charts,int i)
  {
      for(auto& l:charts[i])
      {
          int indexOfDot=-1;
          for(int k=0;k<l.first.second.size();k++)
          {
              if(l.first.second[k]==toLookFor)
              {
                  if(l.first.second[k-1]=='.')
                  {
                      indexOfDot=k-1;
                  }
              }
          }
          if(indexOfDot!=-1)
          {
              string temp=l.first.second;
              string newString="";
              for(int k=0;k<temp.size();k++)
              {
                  if(k==indexOfDot)
                  {

                  }
                  else if(k==indexOfDot+1)
                  {
                      newString+=temp[k];
                      newString+='.';
                  }
                  else
                  newString+=temp[k];
              }
              l.first.second=newString;
          }
              if(l.first.second[l.first.second.size()-1]=='.')
              {
                  cout<<l.first.second<<endl;
                  lookFor(l.first.first[0],charts,l.second);
              }
              else
              {
                  int indexOfDot2=-1;
                  for(int q=0;q<l.first.second.size();q++)
                  {
                      if(l.first.second[q]=='.')
                      {
                          indexOfDot2=q+1;
                          break;
                      }
                  }
                  if(indexOfDot2!=-1)
                  {
                      cout<<"------"<<l.first.second<<endl;
                      string temp="";
                      temp+=l.first.second[indexOfDot2+1];
                      addToChart(temp,charts[i+1],rules,i+1);
                  }
              }

      }
      return;
  }
  void printCharts(vector<vector<pair<pair<string,string>,int>>> charts)
  {
      int k=0;
      for(auto& i:charts)
      {
          cout<<"CHART "<<k<<endl;
          k++;
          for(auto& p:i)
          {
              cout<<p.first.first<<"  ->  "<<p.first.second<<"         "<<p.second<<endl;
          }
      }
  }
  void parse(string st,map<string,vector<string>>& rules)
  {
      vector<vector<pair<pair<string,string>,int>>> charts;
      vector<pair<pair<string,string>,int>> temp;
      temp.push_back({{"P",".S"},0});
      addToChart("S",temp,rules,0);
      charts.push_back(temp);
      for(int k=0;k<st.size()-1;k++)
      {
          vector<pair<pair<string,string>,int>> temp;
          charts.push_back(temp);
      }
      for(int i=0;i<st.size();i++)
      {
          char toLookFor=st[i];
          cout<<"    "<<toLookFor<<endl;
          printCharts(charts);
          lookFor(toLookFor,charts,i);
          
      }
  }
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum)
  {
      int h=0;
      int* o=&h;
      *o=12;
      cout<<h<<endl;
      string st = "2+3*4";
      vector<string> temp1;
      temp1.push_back("S+M");
      temp1.push_back("M");
      rules["S"]=temp1;
      vector<string> temp2;
      temp2.push_back("M*T");
      temp2.push_back("T");
      rules["M"]=temp2;
      vector<string> temp3;
      temp3.push_back("1");
      temp3.push_back("2");
      temp3.push_back("3");
      temp3.push_back("4");
      rules["T"]=temp3;

      parse(st,rules);
      

      vector<vector<int>> ret;
      return ret;
  }
