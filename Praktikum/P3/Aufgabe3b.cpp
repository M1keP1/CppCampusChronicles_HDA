#include <iostream>
#include <vector>
#include <string>

class Name_values
{ 
  public:
  Name_values();
  Name_values(const std::string&day ,const std::vector<int> &x);
  void add_values(const int&);
double durchschnitt();
 void print_all()const;
 std::string get_name()const;
private:
std::string name;
std::vector<int> values;
};  

std::string Name_values::get_name() const
{
   return name;
}
 void Name_values::add_values(const int& sf)
{
    values.push_back(sf);
}
Name_values::Name_values() {}

Name_values::Name_values(const std::string& day, const std::vector<int>&x):name{day},values{x}
{

}
 double Name_values::durchschnitt()
{   
  
double durchschnitt{0.0};
int sum=0;
    for(int i=0;i<values.size();i++)
   { 
    sum +=values.at(i);
    }
    durchschnitt=sum/values.size();
   
    return durchschnitt;
}
void Name_values::print_all() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Values: ";
    for (const auto& value : values)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
    //std::cout<<name.durch
}



int main()
{
  std::string inputday; 
  
int inputNumber{0};
  std::vector<Name_values> week;
   std::vector<int> inputvalues;

  
std::cout<<"gib wochentag :";
   while ((std::cin>>inputday)&&(inputday != "q"))
    {     
          
         std::cout<<"gib werte dafür";
             
              
          

          
          bool dayExists = false;
        for (auto& element : week)
        {
            if (element.get_name() == inputday)
            {
                dayExists = true;
                element.add_values(inputNumber);
                break;
            }
            
        }
        while (std::cin>>inputNumber)
          {
             inputvalues.push_back(inputNumber);
             if (std::cin.peek() == '\n')
                break;

          }
   if (!dayExists)
   {
    
      
         if (inputday == "monday" || inputday == "mo")
        {
            Name_values monday( inputday, inputvalues);
            week.push_back(monday);
            
        }
        else if (inputday == "tuesday" || inputday == "tu")
             {Name_values tuesday(inputday, inputvalues);
             week.push_back(tuesday);}
         
        else if (inputday == "wednesday" || inputday == "we")
           
           {
            Name_values wednesday(inputday, inputvalues);
             week.push_back(wednesday);
             }
        else if (inputday == "thursday" || inputday == "th")
            {Name_values thursday(inputday, inputvalues);
             week.push_back(thursday);}
        else if (inputday == "friday" || inputday == "fr")
            {Name_values friday(inputday, inputvalues);
             week.push_back(friday);}
        else if (inputday == "saturday" || inputday == "sa")
            {
            Name_values saturday(inputday, inputvalues);
            week.push_back(saturday);
            }
        else if (inputday == "sunday" || inputday == "su")
            
            {
              Name_values sunday(inputday, inputvalues);
             week.push_back(sunday);
            }
             
             bool dayExists = false;
            }

         std::cout<<"gib wochentag :";
    }    double t{0.0};
       //std::string y{};
     // for(int i=0;i<week.size();i++)
      /*{  
        t = (week.at(i)).durchschnitt();
        y=  (week.at(i)).get_name();
      }
     //std::cout<<"durchschnitt von "<<y<<" ist "<<t<<std::endl;*/
     for (const auto& element : week)
    {
        element.print_all();
    }
