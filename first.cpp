#include<bits/stdc++.h>
using namespace std;
string st,input;
int len,i;
bool flag=false;
void check()
{
    int index;
    if(st.find("2E2")<=st.length())
    {
        index=st.find("2E2");
        st=st.substr(0,index)+"E"+st.substr(index+3);

        cout<<st<<"\t"<<input<<"\t"<<"rule E->2E2\n";
    }
    else if(st.find("3E3")<=st.length())
    {
        index=st.find("3E3");
        st=st.substr(0,index)+"E"+st.substr(index+3);

        cout<<st<<"\t"<<input<<"\t"<<"rule E->3E3\n";
    }
    else if(st=="$4")
    {
        st="$E";

        cout<<st<<"\t"<<input<<"\t"<<"rule E->4\n";
    }
    else if( st.size()>1 && st.find("4")<=input.length()) 
    {
        for(int k=0;k<st.length();k++)
        {
            if(st[k]=='4')
            {
                st[k]='E';
            }
        }
        cout<<st<<"\t"<<input<<"\t"<<"rule E->4\n";
    }
    else if( input.size()!=1 && (input[0]=='+' || input[0]=='*' || input[0]=='4' || input[0]=='E'  || input[0]=='2' || input[0]=='3') )
    {

      if(input[0]=='+' )
      {
         st=st+"+";
         input=input.substr(1);
         cout<<st<<"\t"<<input<<"\t"<<"shift ->symbol(+)\n";

      }
      else if (input[0]=='*')
      {
          st=st+"*";
         input=input.substr(1);
         cout<<st<<"\t"<<input<<"\t"<<"shift ->symbol(*)\n";
      }
      else if(input[0]=='4') 
      {
           st=st+"4";
         input=input.substr(1);
         cout<<st<<"\t"<<input<<"\t"<<"shift ->terminal\n";

      }
       else if(input[0]=='2') 
      {
           st=st+"2";
         input=input.substr(1);
         cout<<st<<"\t"<<input<<"\t"<<"shift ->terminal\n";

      }
       else if(input[0]=='3') 
      {
           st=st+"3";
         input=input.substr(1);
         cout<<st<<"\t"<<input<<"\t"<<"shift ->terminal\n";

      }
      else if(input[0]=='E')
      {
          st=st+"E";
          input=input.substr(1);
           cout<<st<<"\t"<<input<<"\t"<<"shift ->non-terminal\n";
      }
    }
    else 
    {
     flag=true;
    }
}
int main()
{
cout<<"grammer are \n E->2E2 \t E->3E3  \t E->4 \n";

cout<<"enter input to check\n";
cin>>input;
input=input+"$";
cout<<"stack\tinput\taction\n";
st="$";
//len=input.size();
while(!flag)
{
    check();
}

return 0;




}