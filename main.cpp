#include <iostream>

using namespace std;


int main()
{
    string sum,word,temp;
    signed long long t=0,sx=0,sy=0,ex=0,ey=0,total=0,x=0,orig=0;
    cin >> t >> sx >> sy>>ex>>ey;
    cin >> word;

    if(ex>sx){
        temp += "E";
        for(int i=0;i<ex-sx;i++)
            sum += "E";

    }
    else if(ex<sx){
        temp += "W";
        for(int i=0;i<sx-ex;i++)
            sum += "W";
    }

    if(ey>sy){
        temp += "N" ;
        for(int i=0;i<ey-sy;i++)
            sum += "N";
    }
    else if(ey<sy){
        temp += "S" ;
        for(int i=0;i<sy-ey;i++)
            sum += "S" ;
    }

    orig = sum.size();

    for(int i=0;i<word.size();i++){ ///1
        for(int m=0;m<sum.size();m++){     ///  word :SESNW  sum : NE
            if(word[i] != temp[0] && word[i] != temp[1]){
                break;}
            cout << sum[m] << "  " << word[i] <<endl;

            if(sum[m] == word[i]){
                total = i+1;
                x ++;
                sum.erase(sum.begin()+m);
                break;
            }
        }
        if(x==orig)
            break;
    }

    if(x == orig)
        cout << total <<endl;

    else
        cout << "-1" << endl;
    return 0;
}
