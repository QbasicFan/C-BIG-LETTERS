//display big letters 
#include <iostream>
#include <string>

using namespace std;

//encoding of characters 
enum letters{
space=10,
A=4536650,
B=12925230,
C=13124108,
D=12921164,
E=32010782,
F=32010768,
G=15224366,
H=19495506,
I=4329604,
J=2165324,
K=9777481,
L=8659215,
M=18732593,
N=18667121,
O=6595878,
P=14989576,
Q=15259246,
R=14989609,
S=7608366,
T=32641156,
U=9741606,
V=18157568,
W=18405034,
X=18157905,
Y=18157700,
Z=32575775
};

/////////////////////////
//debug/////////////////
//Compress//////////////
//getTheNumb will convert a string into a number and populate { enum letters }...
/////////////////////////
int getTheNumb (string str){
int key=0,bin=16777216;//maximum value for the binary convertion
for (int i=0;i<str.length();i++){
if (str.at(i)=='*')//
key+=bin;
bin/=2;
}
return key;
}

////////////////////////////////////////////////////////
//Decompress /////////////////////////////
//builder takes key number return a matrix of booleans
/////////////////////////////////////////////////////////
bool ** show(int key){
int bin=16777216;
//making a 2d array [5*5]
bool **a = new bool * [5];//columns
for (int i=0;i<5;i++)
a[i] =  new bool [5];//rows
//rebuilding the 5*5 block
for (int i=0;i<5;i++)
for (int ii=0;ii<5;ii++){
if (key < bin)
a[i][ii]=0;
else{
a[i][ii]=1;
key-=bin;
}
bin/=2;
}
return a;
}

////////////////////////////////////////
//Building /////////////////////
//read input string and print the big text HORIZONTALY
///////////////////////////////////////
string toBig(string str , char ch ){
int lgh =str.length();
letters Char=A;//enum

//tempo matrix [5][5]
bool ** tmpArray= new bool *[5];
for (int i=0;i<5;i++)
tmpArray [i]= new bool [5]; 

//total array [5][5*string_size] , to display the string 
bool ** array= new bool *[5];
for (int i=0;i<5;i++)
array [i]= new bool [5*lgh]; 

//parsing the string
for (int i=0;i<lgh;i++){

if (str.at(i)=='A' || str.at(i)=='a')
Char=A;
else if (str.at(i)=='B' || str.at(i)=='b')
Char=B;
else if (str.at(i)=='C' || str.at(i)=='c')
Char=C;
else if (str.at(i)=='D' || str.at(i)=='d')
Char=D;
else if (str.at(i)=='E' || str.at(i)=='e')
Char=E;
else if (str.at(i)=='F' || str.at(i)=='f')
Char=F;
else if (str.at(i)=='G' || str.at(i)=='g')
Char=G;
else if (str.at(i)=='H' || str.at(i)=='h')
Char=H;
else if (str.at(i)=='I' || str.at(i)=='i')
Char=I;
else if (str.at(i)=='J' || str.at(i)=='j')
Char=J;
else if (str.at(i)=='K' || str.at(i)=='k')
Char=K;
else if (str.at(i)=='L' || str.at(i)=='l')
Char=L;
else if (str.at(i)=='M' || str.at(i)=='m')
Char=M;
else if (str.at(i)=='N' || str.at(i)=='n')
Char=N;
else if (str.at(i)=='O' || str.at(i)=='o')
Char=O;
else if (str.at(i)=='P' || str.at(i)=='p')
Char=P;
else if (str.at(i)=='Q' || str.at(i)=='q')
Char=Q;
else if (str.at(i)=='R' || str.at(i)=='r')
Char=R;
else if (str.at(i)=='S' || str.at(i)=='s')
Char=S;
else if (str.at(i)=='T' || str.at(i)=='t')
Char=T;
else if (str.at(i)=='U' || str.at(i)=='u')
Char=U;
else if (str.at(i)=='V' || str.at(i)=='v')
Char=V;
else if (str.at(i)=='W' || str.at(i)=='w')
Char=W;
else if (str.at(i)=='X' || str.at(i)=='x')
Char=X;
else if (str.at(i)=='Y' || str.at(i)=='y')
Char=Y;
else if (str.at(i)=='Z' || str.at(i)=='z')
Char=Z;

tmpArray=show(Char);//storing new block in the tempo array
//add it to the big array 
for (int i1=0;i1<5;i1++)
for (int i2=0;i2<5;i2++)
array[i1][i2+5*i]=tmpArray[i1][i2];
}

string out;//out return value
//converting
for (int i=0;i<5;i++){
for (int ii=0;ii<5*lgh;ii++)
if (array[i][ii])
out +=ch;
else
out +=" ";
out +="\n";
}

delete array , tmpArray ; //

return out;
}

/////////////////////////////////
//Line separator
/////////////////////////////////////////////
void wrapper(string str){
int lgh = str.length();
for (int i=0;i<lgh;i++)
cout <<"*";
cout <<endl;
}

////////////////////////////////
//print in color with separators
////////////////////////////////////////
void print(string str , int col=37 , bool wr=false){
if (wr)
wrapper(str);
int i=col+30;
cout << "\033[0;" << i << "m"<<str<<"\033[0m" ;
if (wr)
wrapper(str);
}

//////////////////////////////
//main
/////////////////////////////
int main (){

//make new char here
//k,l,m,n , ... ,0,1,2,...,other chars
/*
cout <<" *   "<<endl;
cout <<" *   "<<endl;
cout <<" *   "<<endl;
cout <<" *   "<<endl;
cout <<" ****"<<endl;
int val=getTheNumb(" *    *    *    *    ****");//key value 
cout <<val<<endl;
*/



string str;
cout << "\nEnter your name : ";
cin >> str;
cout <<endl;

//print (string , int color [1-6] (default construc ) , boolean separator (default constructor false))
print(toBig(str,'+'),6);//big letters , blue , separators

return 0;
}
