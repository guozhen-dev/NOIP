#include <bits/stdc++.h>
using namespace std ;
string input;
char output[109030];
int p1 , p2 , p3;
int loc;
bool is_al(char a ) {
 if (a>='a' and a <= 'z') return 1 ;
 else return 0 ;
}
bool is_num(char a ){
 if (a>='0' and a<='9') return 1;
 else return 0 ;
}
void write_in(char a){
	output[loc]=a;
	loc++;
}
void printout(){
	for ( int i = 0 ; i < loc ; i++){
		cout << output[i];
	}
}
int main () {
 cin >> p1 >> p2 >> p3;
 cin >> input;
 loc = 0 ;
 for(register int i = 0 ; i < input.length() ; i++){
  if (input[i]=='-' and i == 0 ){
  	write_in('-');
  }
  else if (input[i]!='-'){
   write_in(input[i]);
  }
  else if ( input[i] == '-' ) {
   if(input[i-1]>=input[i+1] || is_al(input[i-1])^is_al(input[i+1])){
    write_in('-');
   }
   else if (is_al(input[i-1]) and is_al(input[i+1]) and input[i-1]+1==input[i+1]){
   }
   else if (is_num(input[i-1]) and is_num(input[i+1]) and input[i-1]+1==input[i+1]){
   }
   else if (input[i-1]<input[i+1] and p3 == 1){
    for (register char j = input[i-1]+1 ; j < input[i+1] ; j++){
      char ans = j ;
      if ( p1 == 2 ){  
        ans+='A'-'a';
      }
      if( p1 == 3){
        ans = '*';
      }
      for(int p = 0; p < p2;p++){
      write_in(ans);
      }
    }
   }

   else if (input[i-1]<input[i+1] and p3 == 2){
    for(register char j = input[i+1]-1 ; j > input[i-1] ; j--){
     char ans = j ;
     if ( p1 == 2 ){          
        ans+='A'-'a';
     }
     if( p1 == 3){
        ans = '*';
     }
     for(int p = 0; p < p2;p++){
        write_in(ans);
     }
    }
  }
 }
}
  printout() ;
  return 0 ;
}
