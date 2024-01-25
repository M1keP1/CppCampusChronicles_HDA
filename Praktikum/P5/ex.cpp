#include<iostream>
#include<string>
using namespace std;




class fruit{
    public:

    string color{};
    int num{};

};


int sum(int k) {
  if (k > 0) {
    return k + sum(k - 1);
  } else {
    return 0;
  }
}

int main() {
  
  fruit mango;
  fruit:mango.color="yellow";
  mango.num=15;
  std::cout<< mango.num << mango.color <<endl;
  return 0;
}

int exe(){
    int x{10};
    return x;
}

void print(int y){
     
     std::cout << y << std::endl;
}
void print(string s){
     std::cout << s << std::endl;
     
}

string inp(){
    string sentence{};
    getline(cin, sentence);
    return sentence; 

}

/*
int main(){
    print(exe());
    print(inp());
    return 0;

}
*/