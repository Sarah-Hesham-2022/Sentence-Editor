#include <iostream>
#include<string>
#include<cstring>
using namespace std;
void general(string,int,int);
string encrypt(string,int);
string decrypt(string,int);
string capitalize(string,int);
int countwords(string,int);
void slicer(string,int);
float averagelength(string,int);
string concatenate(string);
void substring(string,int);
void frequency(string,int);
int main()
{
    string y;
    cout<<"enter your sentence"<<endl;
    cout<<endl;
    getline(cin,y);
    int length;
    cout<<"enter the length of the sentence  "<<endl;
    cin>>length;
    cout<<"choose one of the following"<<endl;
    cout<<endl;
    cout<<"1-Encrypt the string by a certain k"<<endl;
    cout<<"2-Decrypt the string by provided k"<<endl;
    cout<<"3-Capitalize"<<endl;
    cout<<"4-Count the words"<<endl;
    cout<<"5-Sentence slicer"<<endl;
    cout<<"6-Average length of the words of the string"<<endl;
    cout<<"7-Concatenate a new string to the current string"<<endl;
    cout<<"8-Search for a substring"<<endl;
    cout<<"9-Frequency of a certain word"<<endl;
    cout<<"10-Exit"<<endl;
    cout<<endl;
    int x;
    cin>>x;
    general(y,length,x);
    return 0;
}
void general(string y,int length,int x){
    if (x==10)
        return;
    else{
        switch(x){
    case 1:
       cout<<encrypt(y,length)<<endl;
        break;
    case 2:
        cout<<decrypt(y,length)<<endl;
        break;
    case 3:
        cout<<capitalize(y,length)<<endl;
        break;
    case 4:
        cout<<countwords(y,length)<<endl;
        break;
    case 5:
        slicer(y,length);
        break;
    case 6:
       cout<<averagelength(y,length)<<endl;
        break;
    case 7:
        cout<<concatenate(y)<<endl;
        break;
    case 8:
        substring(y,length);
        break;
    case 9:
        frequency(y,length);
        break;
    default :
        cout<<"error due to incorrect input,try again"<<endl;
        break;
        }
    }
    string d;
    cout<<"enter your sentence  "<<endl;
    cout<<endl;
    cin.ignore();
    getline(cin,d);
    int l;
    cout<<"enter the length of the sentence"<<endl;
    cin>>l;
    cout<<"choose one of the following"<<endl;
    cout<<endl;
    cout<<"1-Encrypt the string by a certain k"<<endl;
    cout<<"2-Decrypt the string by provided k"<<endl;
    cout<<"3-Capitalize"<<endl;
    cout<<"4-Count the words"<<endl;
    cout<<"5-Sentence slicer"<<endl;
    cout<<"6-Average length of the words of the string"<<endl;
    cout<<"7-Concatenate a new string to the current string"<<endl;
    cout<<"8-Search for a substring"<<endl;
    cout<<"9-Frequency of a certain word"<<endl;
    cout<<"10-Exit"<<endl;
    cout<<endl;
    int z;
    cin>>z;
    general(d,l,z);

}
string encrypt(string y,int length){
cout<<"enter the key"<<endl;
int k;
cin>>k;
if(k<=100 && k>=1){
for(int i=0;i<length;i++){
        y[i]=y[i]+k;
}
string*pointer=new string;
*pointer=y;
return *pointer;
}
else{
    return "NULL";
}
}
string decrypt(string y,int length){
cout<<"enter the key"<<endl;
int k;
cin>>k;
if(k<=100 && k>=1){
for(int i=0;i<length;i++){
        y[i]=y[i]-k;
}
string *pointer=new string;
*pointer=y;
return *pointer;
}
else{
    return "NULL";
}
}
string capitalize(string y,int length){
for(int i=0;i<length;i++){
    if(isalpha(y[i]))
     y[i]=toupper(y[i]);
}
return y;
}
int countwords(string y,int length){
int x=0;
for(int i=0;i<length;i++){
    if(!isalnum(y[i]) && (y[i-1]!=' ' && y[i-1]!='.' && y[i-1]!='?' )){
        x=x+1;
        continue;
    }
}
cout<<"the number of words is "<<endl;
return x;
}
void slicer(string y,int length){
int x=0;
for(int i=0;i<length;i++){
    if(!isalnum(y[i]) && (y[i-1]!=' ' && y[i-1]!='.' && y[i-1]!='?' )){
        x=x+1;
        continue;
    }
}
string *myarray;
myarray=new string[x];
string word="";
int z=0;
for(int i=0;i<length;i++){
    if(isalnum(y[i])){
       word=word+y[i];
       continue;
        }
        myarray[z]=word;
        z=z+1;
        word="";
    }
    for(int j=0;j<x;j++){
       if(j==0)
            cout<<'{';
       cout<<'"'<<myarray[j]<<'"';
       if(j!=x-1)
        cout<<',';
        if(j==x-1)
            cout<<'}'<<endl;
    }
delete [] myarray;
}
float averagelength(string y,int length){
int x=0;
float z=0.0;
for(int i=0;i<length;i++){
    if(!isalnum(y[i]) && (y[i-1]!=' ' && y[i-1]!='.' && y[i-1]!='?' )){
        x=x+1;
        continue;
    }
}
for(int j=0;j<length;j++){
    if(isalnum(y[j]))
        z=z+1.0;
}
cout<<x<<endl<<z<<endl;
cout<<"the average is: "<<endl;
float a=z/x;
return a;
}
string concatenate(string y){
cout<<"enter the new string : "<<endl;
string a,z;
cin.ignore();
getline(cin,a);
z=y+a;
return z;
}
void substring(string  y,int length){
string z;
cout<<"enter the substring"<<endl;
cin>>z;
int a=z.size();
int b=0;
string z1=z;
string z2=z;
if(isupper(z1[0]))
    z1[0]=tolower(z1[0]);
if(islower(z2[0]))
        z2[0]=toupper(z2[0]);
for(int i=0;i<length;i++){
    if ((y.substr(i,a))==z || y.substr(i,a)==z1 || y.substr(i,a)==z2){
        cout<<i<<endl;
        b=100;
        break;
    }
    if(b==0 && i==length-1)
        cout<<"-1"<<endl;
}
}
void frequency(string y,int length){
string q;
cout<<"enter the word "<<endl;
cin>>q;
int a=q.size();
string z1=q;
string z2=q;
if(isupper(z1[0]))
    z1[0]=tolower(z1[0]);
if(islower(z2[0]))
     z2[0]=toupper(z2[0]);
int p=0;
for(int i=0;i<length;i++){
    if(!isalnum(y[i]) && (y[i-1]!=' ' && y[i-1]!='.' && y[i-1]!='?' )){
        p=p+1;
        continue;
    }
}
string *myarray;
myarray=new string[p];
string word="";
int z=0;
for(int i=0;i<length;i++){
    if(isalnum(y[i])){
       word=word+y[i];
       continue;
        }
        myarray[z]=word;
        z=z+1;
        word="";
    }
    int n=0;
   for(int e=0;e<z;e++){
    if(myarray[e]==q || myarray[e]==z1 || myarray[e]==z2)
        n=n+1;
   }
   int *newarray=new int[n];
   int m=0;
   for(int u=0;u<z;u++){
    if(myarray[u]==q || myarray[u]==z1 || myarray[u]==z2){
        newarray[m]=u;
        m=m+1;
    }
   }
   for(int t=0;t<m;t++){
        if(t==0)
         cout<<'[';
    cout<<(newarray[t]+1);
   if(t!=m-1)
        cout<<',';
    if(t==m-1)
        cout<<']'<<endl;
}
}










