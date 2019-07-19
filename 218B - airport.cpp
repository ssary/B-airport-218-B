// Accepted 92ms 0 kb                          2019/7/20
#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=0,meow=0,m=0,s=0,maxx=0,minn=0,c=0,tempn=0;
    cin >> n >> m;
    meow = n;
    vector<int> seat;
    vector<int> temp;
    for(int i=0;i<m;i++){
        cin >> s;
        seat.push_back(s);
        temp.push_back(s);
    }
    sort(seat.begin(),seat.end(),greater<int>());

/*    for(int i=0;i<meow;i++){
        if(seat.size() == i ){
            meow-=i;
            i=0;
            c++;
            }
        maxx += seat[i] - c;
    }*/
    tempn= n;
    bool chek = false;
    for(int i=0;i<n;i++){
        if(chek){
            i--;
            n--;}
        chek = false;

        if(seat.size() == i ){
            n-=i;
            i=0;}

        if(seat[i] <= seat[i-1] && seat[i-1] > 0 && i>0){
            maxx += seat[i-1] ;
            chek = true;
            seat[i-1] --;
            if(seat[i-1] == 0){
                seat.erase(seat.begin()+i-1);
                chek = true;}

            else if(seat[i] == 0){
                seat.erase(seat.begin()+i);
                chek = true;}

            sort(seat.begin(),seat.end(),greater<int>());
            }


        else{
            maxx += seat[i];
            chek = true;
            seat[i] -- ;
            if(seat[i] == 0){
                seat.erase(seat.begin()+i);
                chek = true;}


            sort(seat.begin(),seat.end(),greater<int>());

        }}

    sort(temp.begin(),temp.end());
    chek = false;
    for(int i=0;i<tempn;i++){
        if(chek){
            i--;
            tempn--;}

        chek = false;

        if(temp.size() == i ){
            tempn-=i;
            i=0;}

        if(temp[i] >= temp[i-1] && temp[i-1] > 0 && i>0){
            minn += temp[i-1] ;
            temp[i-1] --;
            chek = true;
            if(temp[i-1] == 0){
                temp.erase(temp.begin()+i-1);
                chek = true;}

            else if(temp[i] == 0){
                temp.erase(temp.begin()+i);
                chek = true;}

            }


        else{
            minn += temp[i];
            temp[i] -- ;
            if(temp[i] == 0){
                temp.erase(temp.begin()+i);
                chek = true;}

        }
    }

    cout << maxx << " " << minn <<endl;
    return 0;
}
