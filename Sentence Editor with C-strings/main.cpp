#include <iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;
void recursionfunction(int,int,char[]);
char*encrypt(char[],int,int);
char*decrypt(char[],int,int);
string capitalize(char[],int);
int countwords(char[],int);
void slicer(char[],int);
float average(char[],int);
void concatenate(char[],int,char[],int);
int substring(char[],int,char[],int);
void frequency(char[],int);
int main()
{
    int sizeofarray,choice;
    cout<<"enter the size of the sentence "<<endl;
    cin>>sizeofarray;
    sizeofarray+=1;
    cout<<"enter your one line sentence"<<endl;
    char*myarray;
    myarray=new char[sizeofarray];
    cin.ignore();
    cin.getline(myarray,sizeofarray);
    cout<<"choose one of the following "<<endl;
    cout<<"1-Encrypt "<<endl;
    cout<<"2-Decrypt "<<endl;
    cout<<"3-Capitalize "<<endl;
    cout<<"4-Count the words"<<endl;
    cout<<"5-Sentence slicer "<<endl;
    cout<<"6-Average length of words "<<endl;
    cout<<"7-Concatenate a new string "<<endl;
    cout<<"8-Search for a substring"<<endl;
    cout<<"9-Frequency of a certain word"<<endl;
    cout<<"10-EXIT"<<endl;
    cin>>choice;
    recursionfunction(choice,sizeofarray,myarray);
    return 0;
}
void recursionfunction(int choice,int sizeofarray,char*myarray){
if(choice==10)
    return;
else{
switch(choice){
case 1:
    cout<<"enter the encryption key "<<endl;
    int k;
    cin>>k;
    cout<<encrypt(myarray,sizeofarray,k)<<endl;
    break;
case 9:
    frequency(myarray,sizeofarray);
    break;
case 2:
    cout<<"enter the decryption key "<<endl;
    int k2;
    cin>>k2;
    cout<<decrypt(myarray,sizeofarray,k2)<<endl;
    break;
case 3:
    cout<<capitalize(myarray,sizeofarray)<<endl;
    break;
case 4:
    cout<<countwords(myarray,sizeofarray)<<endl;
    break;
case 5:
    slicer(myarray,sizeofarray);
    break;
case 6:
    cout<<average(myarray,sizeofarray)<<endl;
    break;
case 7:
    int sizeofnewstring;
    cout<<"enter the size of the new string "<<endl;
    cin>>sizeofnewstring;
    sizeofnewstring+=1;
    char*newstring;
    newstring=new char[sizeofnewstring];
    cout<<"enter the string you want to concatenate "<<endl;
    cin.ignore();
    cin.getline(newstring,sizeofnewstring);
    concatenate(myarray,sizeofarray,newstring,sizeofnewstring);
    break;
case 8:
    cout<<"enter the size of the substring "<<endl;
    int sizeofnewstring2;
    cin>>sizeofnewstring2;
    sizeofnewstring2+=1;
    char *newstring2=new char[sizeofnewstring2];
    cout<<"enter the substring you are looking for "<<endl;
    cin.ignore();
    cin>>newstring2;
    cout<<substring(myarray,sizeofarray,newstring2,sizeofnewstring2)<<endl;
   break;
}
}
    int sizeofarray1,choice1;
    cout<<"enter the size of the sentence "<<endl;
    cin>>sizeofarray1;
    sizeofarray1+=1;
    cout<<"enter your one line sentence"<<endl;
    char*myarray1;
    myarray1=new char[sizeofarray1];
    cin.ignore();
    cin.getline(myarray1,sizeofarray1);
    cout<<"choose one of the following "<<endl;
    cout<<"1-Encrypt "<<endl;
    cout<<"2-Decrypt "<<endl;
    cout<<"3-Capitalize "<<endl;
    cout<<"4-Count the words"<<endl;
    cout<<"5-Sentence slicer "<<endl;
    cout<<"6-Average length of words "<<endl;
    cout<<"7-Concatenate a new string "<<endl;
    cout<<"8-Search for a substring"<<endl;
    cout<<"9-Frequency of a certain word"<<endl;
    cout<<"10-EXIT"<<endl;
    cin>>choice1;
    recursionfunction(choice1,sizeofarray1,myarray1);
}
char*encrypt(char*myarray,int sizeofarray,int k){
if(k>=0 &&k<=100){
for(int i=0;i<sizeofarray-1;i++)
        myarray[i]=myarray[i]+k;
char*pointer;
pointer=new char[sizeofarray];
pointer=myarray;
return pointer;
}
else
   return"NULL";
}
char*decrypt(char*myarray,int sizeofarray,int k2){
if(k2>=0 &&k2<=100){
for(int i=0;i<sizeofarray-1;i++)
        myarray[i]=myarray[i]-k2;
char*pointer;
pointer=new char[sizeofarray];
pointer=myarray;
return pointer;
}
else
   return "NULL";
}
string capitalize(char*myarray,int sizeofarray){
for(int i=0;i<sizeofarray-1;i++){
    if(isalpha(myarray[i]))
        myarray[i]=toupper(myarray[i]);
}
return myarray;
}
int countwords(char*myarray,int sizeofarray){
int sum=0;
for(int i=0;i<sizeofarray-1;i++){
    if(isalpha(myarray[i]))
               continue;
else
    if(isalpha(myarray[i-1]))
    sum=sum+1;
}
if(isalpha(myarray[sizeofarray-2]))
    return sum+1;
else
    return sum;
}
void slicer(char*myarray,int sizeofarray){
int sum=0;
for(int i=0;i<sizeofarray-1;i++){
    if(isalpha(myarray[i]))
               continue;
else
    if(isalpha(myarray[i-1]))
    sum=sum+1;
}
if(isalpha(myarray[sizeofarray-2]))
    sum=sum+1;
sum=sum+1;
string *newarray=new string[sum];
string tempword="";
int z=0;
for(int j=0;j<sizeofarray;j++){
    if(isalpha(myarray[j])){
        tempword+=myarray[j];
        continue;
    }
    newarray[z]=tempword;
    z=z+1;
    tempword="";
}
cout<<"{";
for(int m=0;m<sum;m++){
    cout<<newarray[m];
    if(m!=sum-2 &&m!=sum-1)
        cout<<",";
}
cout<<"}"<<endl;
delete []newarray;
}
float average(char*myarray,int sizeofarray){
float sum=0.0;
for(int i=0;i<sizeofarray-1;i++){
    if(isalpha(myarray[i]))
               continue;
else
    if(isalpha(myarray[i-1]))
    sum=sum+1;
}
if(isalpha(myarray[sizeofarray-2]))
    sum=sum+1;
float temp=0.0;
for(int j=0;j<sizeofarray;j++){
    if(isalpha(myarray[j]))
        temp=temp+1;
}
return temp/sum;
}
void concatenate(char*myarray,int sizeofarray,char*newstring,int sizeofnewstring){
cout<<strcat(myarray,newstring)<<endl;
delete[]newstring;
}
int substring(char*myarray,int sizeofarray,char*newstring2,int sizeofnewstring2){
char*pointer=strstr(myarray,newstring2);
if(pointer){
int x=sizeofarray-1;
int y=strlen(pointer);
int place=x-y;
return place;
}
else
   return -1;
}
void frequency(char*myarray,int sizeofarray){
cout<<"enter the word "<<endl;
cin.ignore();
string word;
cin>>word;
int sum=0;
for(int i=0;i<sizeofarray-1;i++){
    if(isalpha(myarray[i]))
               continue;
else
    if(isalpha(myarray[i-1]))
    sum=sum+1;
}
if(isalpha(myarray[sizeofarray-2]))
    sum=sum+1;
sum=sum+1;
string *newarray=new string[sum];
string tempword="";
int z=0;
for(int j=0;j<sizeofarray;j++){
    if(isalpha(myarray[j])){
        tempword+=myarray[j];
        continue;
    }
    newarray[z]=tempword;
    z=z+1;
    tempword="";
}
int n=0;
int num=0;
int *temparray=new int[n];
string z1=word,z2=word;
if(isupper(z1[0]))
    z1[0]=tolower(z1[0]);
if(islower(z2[0]))
    z2[0]=toupper(z2[0]);
for(int m=0;m<sum;m++){
    if(newarray[m]==word || newarray[m]==z1 || newarray[m]==z2){
      temparray[n]=m;
      n=n+1;
      num=100;
}
}
if(num==100){
cout<<"[";
for(int g=0;g<n;g++){
    cout<<temparray[g]+1;
    if(g!=n-1)
        cout<<",";
}
cout<<"]"<<endl;
}
else
    cout<<"NULL"<<endl;
}
