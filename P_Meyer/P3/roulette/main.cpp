

#include "func.cpp"


int main()
{
    std::cout << "------The bluetooth device has been connected!-------" << endl;

    vector<player> players;
    char choice{};
    do{
        string playername;
        cout<< "Enter playername"<<endl;
        cin >> playername;
        // need a verification here to check existing users

        players.push_back(playername);

        std::cout << "Do you want to add another user? (y/n): ";
        std::cin >> choice;
    }while(choice=='y'||choice=='Y');

    cout <<"All players added to game sucessfully"<<endl;

    cout <<"Let the game begin"<<endl;

    for (size_t i = 0; i < players.size(); ++i)
    {

        std::cout << "It's " << players[i].get_name() << "'s turn." << std::endl;

        cout <<"Heyy "<<players[i].get_name() <<endl;
        cout<<"You currrently have "<<players[i].get_price_money()<<" in your account " <<endl;
        cout <<"Enter your bet to start playing" <<endl;
        int guess{};
        while(true)
        {
            cin >> guess;
            if(guess>0 && guess<37){
                break;
            }
            else
            {
                cout <<"Enter a valid guess"<<endl;
            }
        }
        cout<<"How much do u want to bet"<<endl;
        int amount{};
        cin >> amount;
        cout<<"Enter play type"<<endl;
        char mode{};
        cin>>mode;
        cout<<"-----------------------------------";

        play(guess,mode,amount,players[i]);
    }


    return 0;
}
