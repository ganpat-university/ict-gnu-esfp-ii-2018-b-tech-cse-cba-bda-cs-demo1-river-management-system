#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstring>

using namespace std;

class RMS                                                                               ///Class RMS declared
{
public:
    class State                                                                         ///Class of State declared
    {
    public:
        string S_Id,S_Name;
        int S_Area,S_Forest_Area,S_Annual_Rainfall,S_Total_Water_Requirement,S_Population;

        void get_data(int i)                                                            ///Getting Data of States
        {
            cout<<"Enter Data of State "<<i+1<<"=====================>"<<endl;
            cout<<"Enter State ID :- ";
            cin>>S_Id;
            cout<<"Enter State Name (Uttar Pradesh = UP):- ";
            cin>>S_Name;
            cout<<"Enter State Area :- ";
            cin>>S_Area;
            cout<<"Enter State Forest Area :- ";
            cin>>S_Forest_Area;
            cout<<"Enter State Annual Rainfall :- ";
            cin>>S_Annual_Rainfall;
            cout<<"Enter State Total Water Requirement :- ";
            cin>>S_Total_Water_Requirement;
            cout<<"Enter State Population :- ";
            cin>>S_Population;
        }

    };
    class River                                                                         ///Class of River Defined
    {
    public:
        string R_Condition,R_Id,R_State,R_Name;
        int R_Water_Intake;
        float R_Length;

        void get_data(int i)                                                            ///Getting Data of Rivers
        {
            cout<<"Enter Data of River "<<i+1<<"=====================>"<<endl;
            cout<<"Enter River-ID :- ";
            cin>>R_Id;
            cout<<"Enter River Name :- ";
            cin>>R_Name;
            cout<<"Enter River State :- ";
            cin>>R_State;
            cout<<"Enter River Condition :- ";
            cin>>R_Condition;
            cout<<"Enter River Length :- ";
            cin>>R_Length;
            cout<<"Enter River Water Intake :- ";
            cin>>R_Water_Intake;
        }
    };
    State state;                                                                            ///Object of State created
    River river;                                                                            ///Object of River created
};

void display_states_rainfall_greaterthan500(RMS rm[])                                       ///task1 function
{
    for(int i=0;i<7;i++)
    {
        for(int k=0;k<7;k++)
        {
            if(rm[i].river.R_Length==10)
            {
                if(rm[i].river.R_State==rm[k].state.S_Name && rm[k].state.S_Annual_Rainfall>500)
                {
                    cout<<rm[i].state.S_Name<<endl;
                }
            }

        }
    }
}

void display_river_water_intake_atleast7000(RMS rm[])                                               ///task2 function
{
    for(int i=0;i<7;i++)
    {
        for(int k=0;k<7;k++)
        {
            if(rm[i].state.S_Forest_Area==500)
                if((rm[i].state.S_Name==rm[k].river.R_State) && (rm[k].river.R_Water_Intake>=7000))
            {
                {
                    cout<<rm[i].state.S_Name<<endl;
                }
            }

        }
    }
}

void display_population_more_then_1000(RMS rm[])                          ///display names of all the rivers and states having population greater than 1000
{
    string exp,arr[7];
    cout<<"|   State   |  River  |"<<endl;
    for(int i=0;i<7;i++)
    {
        exp=rm[i].river.R_State;
        for(int k=0;k<7;k++)
        {
            if(exp==rm[k].state.S_Name)
            {
                if(rm[i].state.S_Population>1000)
                    cout<<"|"<<setw(11)<<exp<<"|"<<setw(9)<<rm[i].river.R_Name<<"|"<<endl;
            }
        }

    }
}

void display_river_length_greater_than_3(RMS rm[])                                     ///display names of all the rivers having length greater than 3 KM
{
    string arr[7],exp;
    int count[7],t=0,a=0,b=1;
    for(int i=0;i<7;i++)
    {
        if(rm[i].river.R_Length>3)
        {
            arr[a]=rm[i].river.R_Name;
            t++;
            a++;
        }
    }
    a=0;
    cout<<t<<endl<<a;
    for(int i=a;i<t-1;i++)
    {
        for(int j=b;j<t;j++)
        {
            if(arr[i]>arr[j])
            {
                exp=arr[i];
                arr[i]=arr[j];
                arr[j]=exp;
            }
        }
        b++;
    }
    a++;
    for(int i=0;i<t;i++)
    {
        cout<<arr[i]<<endl;
    }
}

void display_water_intake_then_8000(RMS rm[])   ///display names of all the rivers having water intake greater than in Gujarat State 8000
{
    for(int i=0;i<7;i++)
    {
        if(((rm[i].river.R_State=="Gujarat") || (rm[i].river.R_State=="GUJARAT")) && (rm[i].river.R_Water_Intake>8000))
        {
            cout<<rm[i].river.R_Name<<endl;
        }
    }
}

void display_river_length_greater_than_2(RMS rm[])             ///display names of all the rivers having length greater than 2 KM In UP
{
    for(int i=0;i<7;i++)
    {
        if((rm[i].river.R_Water_Intake==500) && ((rm[i].river.R_State=="UP") || (rm[i].river.R_State=="Uttar Pradesh") || (rm[i].river.R_State=="Uttar") || (rm[i].river.R_State=="Pradesh") ) && (rm[i].river.R_Length>2))
        {
            cout<<rm[i].river.R_Name<<endl;
        }
    }
}

int main()
{
    int choice;
    char ch;
    RMS rms[7];                                                                             ///RMS class Object created
    for(int i=0;i<7;i++)
        rms[i].state.get_data(i);
    cout<<endl;
    for(int i=0;i<7;i++)
        rms[i].river.get_data(i);

    ofstream write("database_state.txt",ios::out | ios::binary);               ///ofstream object write opens database_state.txt for writing data of states
    write<<"row-no_S-id__S-Name___S-Area____S-ForestArea_____S-AnnualRainfall______S-TotalWaterRequirement_______S-Population"<<endl;
    for(int i=0;i<7;i++)
        write<<i+1<<"_"<<rms[i].state.S_Id<<"__"<<rms[i].state.S_Name<<"___"<<rms[i].state.S_Area<<"____"<<rms[i].state.S_Forest_Area<<"_____"<<rms[i].state.S_Annual_Rainfall<<"______"<<rms[i].state.S_Total_Water_Requirement<<"_______"<<rms[i].state.S_Population<<endl;
    write.close();
    ofstream write2("database_river.txt",ios::out | ios::binary);               ///ofstream object write opens database_river.txt for writing data of rivers
    write2<<"row-no_R-id__R-Name___R-Length____R-WaterIntake_____R-State______R-condition"<<endl;
    for(int i=0;i<7;i++)
        write2<<i+1<<"_"<<rms[i].river.R_Id<<"__"<<rms[i].river.R_Name<<"___"<<rms[i].river.R_Length<<"____"<<rms[i].river.R_Water_Intake<<"_____"<<rms[i].river.R_State<<"______"<<rms[i].river.R_Condition<<endl;
    write2.close();
again:
    cout<<"\n***MENU***\n";
    cout<<"1. Display names of all the states in which annual rainfall is greater than 500 and having river length as 10km ... "<<endl;
    cout<<"2. Display names of all the states which have river water intake as atleast 7000 and forest area as 500sqft ... "<<endl;
    cout<<"3. Display names of all the states and rivers having population more than 1000...."<<endl;
    cout<<"4. Display names of all the Rivers having length greater than 3KM ...."<<endl;
    cout<<"5. Display names of all the having water intake greater than 8000 belong to Gujarat...."<<endl;
    cout<<"6. Display names of all the Rivers having length greater than 2 KM and water intake as 500 belong to Uttar Pradesh...."<<endl<<endl;
again_choice:
    cout<<"Enter your choice : ";
    cin>>choice;
    if(choice>6 || choice<1)
        goto again_choice;
    switch(choice)
    {
        case 1 :display_states_rainfall_greaterthan500(rms);
                break;
        case 2 :display_river_water_intake_atleast7000(rms);
                break;
        case 3 :display_population_more_then_1000(rms);
                break;
        case 4 :display_river_length_greater_than_3(rms);
                break;
        case 5 :display_water_intake_then_8000(rms);
            break;
        case 6 :display_river_length_greater_than_2(rms);
            break;
    }
    cout<<"Want to check something else?(y/n) ";
    cin>>ch;
    if(ch=='y')
    {
        goto again;
    }
    return 0;
}
