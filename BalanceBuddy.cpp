#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
// 6-8 is a parallel array
const int MaxExp = 100; //Maximum amount of expenses const since it should not be changed.
string category[MaxExp]; // category(food, transport, medicine.)
float Amount[MaxExp]; // Amount spent on category depending what the user inputs.
int NumOfExp = 0; // This is a counter for the number of expenses;

float CheckingAcc = 0.0;  // The money available for spending 
float SavingsAcc = 0.0;   // The money that remains saved 


void OutputMenu();
void InsertExp(); // Add expenses.
void ViewExp(); // View expenses.
void DeleteExp(); // Delete expenses.
void HighestExp(); // Outputs Highest expense.
void ExpSummary(); // Expeneses summary.
void SearchExpByCategory(); // Search for the expense by category depnding on what the user inputs as category.
void ResetExps(); // Resets all expenses 
void SetAccs(); // Allows the user to set the balance of the checking and savings accs.
void TransFunds(); // Allows the user to transfer funds between accs.
void ViewAccBal(); // Allows the user to see funds available in both checking and saving.
void AccBalEdit();// this prototype function is a solution to an issue were we couldnt edit balance.


int main()
{
    while(true)// is an infinite loop to repeatedly display the menu until they choose to exit
    {
        OutputMenu();
        int option;
        cout<<"Dear User Please Enter An Option From The Menu Above!"<<endl;
        cin>>option;
        
        switch (option)
        {
            case 1: SetAccs();
            break;
            
            case 2: ViewAccBal();
            break;
            
            case 3: AccBalEdit();
            break;
            
            case 4: InsertExp();
            break;
            
            case 5: ViewExp();
            break;
            
            case 6: DeleteExp();
            break;
            
            case 7: TransFunds();
            break;
            
            case 8: HighestExp();
            break;
            
            case 9: ExpSummary();
            break;
            
            case 10: SearchExpByCategory();
            break;
            
            case 11: ResetExps();
            break;
            
            case 12: cout<< "Concluding Program!"<<endl;
            
            return 0;
            
            default : cout<<"Invalid Option, Please choose from(1 --> 12)"<<endl; // FIX: 12 not 11
        }
    }
}

void OutputMenu() //Outputing the menu to make sure its visable for the user.
{ 
    
    cout <<"\n---- Welcome To The Expenses Calculator! ----\n";
    cout << "1.  Assign Account Balances. 💳" << endl;
    cout << "2.  View Account Balances. 💰" << endl; 
    cout << "3.  Edit Account Balances. ✏️"<<endl;
    cout << "4.  Add An Expense. ➕." << endl;
    cout << "5.  View Expenses. 👀" << endl;
    cout << "6.  Delete An Expense. 🚮" << endl;
    cout << "7.  Transfer money Between Accounts. 🔁" << endl;
    cout << "8.  View The Highest Expense. 🔝" << endl;
    cout << "9.  View An Expense Summary. 📝" << endl;
    cout << "10. Search For An Expense By Category. 🔍" <<endl;
    cout << "11. Reset All Available Expenses. ♻️" << endl; 
    cout << "12. Exit The Program. 👋" << endl; 
}
    


void SetAccs()
{
    cout<<"Dear User Please Input Amount For Your Checking Account: ";
    cin>>CheckingAcc;
    
    cout<<"Dear User Please Input Amount For Your Savings Account: ";
    cin>>SavingsAcc;
    cout<<"Amounts successfully Added!"<<endl;
}



void ViewAccBal()
{
    cout<<"\n---- Account Balances : ----\n";
    cout<<"The Checkings Account: "<<fixed<<setprecision(2)<<CheckingAcc<<endl;
    cout<<"The Savings Account: "<<fixed<<setprecision(2)<<SavingsAcc<<endl;
    
    
}



void TransFunds()
{
    int Direction;
    float TransAmount;
    cout<<"\n---- Transfer Direction ----\n"<<endl;
    cout<<"Dear User Please Select The Transfer Direction: "<<endl;
    cout<<"1. Transfer From Checking To Savings. "<<endl;
    cout<<"2. Transfer From Savings To Checking. "<<endl;
    cin>>Direction;
    
    if (Direction == 1)
    {
        float TransAmount;
        cout<<"Please Enter The Amount To Transfer From Cheking To Savings: "<<endl;
        cin>>TransAmount;
    
        if(TransAmount > CheckingAcc)
        {
            cout<<"Dear User You Have Insufficient Funds In Checking Account To Transer! "<<endl;
            return;
        }
        CheckingAcc -= TransAmount;
        SavingsAcc  += TransAmount;
    
        cout<<"Dear User You Have Transfered "<<fixed<<setprecision(2)<< TransAmount << "To Your Savings Account! "<<endl;
    }
    else if (Direction == 2)
    {
        float TransAmount;
        cout<<"Please Enter The Amount To Transfer From Savings To Checking: "<<endl;
        cin>>TransAmount;
    
        if(TransAmount > SavingsAcc)
        {
            cout<<"Dear User You Have Insufficient Funds In Savings Account To Transer! "<<endl;
            return;
        }


        SavingsAcc  -= TransAmount;
        CheckingAcc += TransAmount;
    
        cout<<"Dear User You Have Transfered "<<fixed<<setprecision(2)<< TransAmount << "To Your Checking Account! "<<endl;
    }
    else
    {
        cout<<"Dear User You Have Entered A Wrong Option Please Input 1 For Checking Account Or 2 For Savings Account!"<<endl;
    }
}


void AccBalEdit ()
{
    int num;
    cout<<"\n---- Balance Editing ----\n"<<endl;
    cout<<"Dear User Which Acount Would You Like To Edit? "<<endl;
    cout<<"1. Checking Account "<<endl;
    cout<<"2. Savings Account "<<endl;
    cout<<"Dear User Please Enter (1 or 2): "<<endl;
    cin>>num;
    
    if(num == 1)
    {
        cout<<"Dear User Please Enter The New Balance For The Checking Account: ";
        cin>>CheckingAcc;
        cout<<"Your Checking Account Balance Has Been successfuly Changed to: "<< fixed << setprecision(2)<< CheckingAcc   <<endl;
    }
    else if (num == 2 )
    {
        cout<<"Dear User Please Enter The New Balance For The Savings Account: ";
        cin>>SavingsAcc;
        cout<<"Your Savings Account Balance Has Been successfuly Changed to: "<< fixed << setprecision(2)<< SavingsAcc    <<endl;
    }
    else 
    {
        cout<<"Dear User You Have Entered A Wrong Option Please Input 1 For Checking Account Or 2 For Savings Account! "<<endl;
    }
}



void InsertExp()
{
    if (NumOfExp >= MaxExp) 
    {
        cout << "Exceeded Expense Entries. Limit reached!" << endl;
        return;
    }

    cout << "Please Enter A Category (Food, Medicine ...etc): " << endl;
    cin >> category[NumOfExp];
    cout << "Please Enter Expense Amount: " << endl;
    cin >> Amount[NumOfExp];

    // Check if the entered expense is positive
    if (Amount[NumOfExp] <= 0)
    {
        cout << "Error: The expense amount must be positive!" << endl;
        return;
    }

    int Acc;
    cout << "Dear User, Which Account Would You Like To Deduct From? " << endl;
    cout << "1. Checking Account. " << endl;
    cout << "2. Savings Account. " << endl;
    cin >> Acc;
    
    if (Acc == 1)
    {
        if (Amount[NumOfExp] > CheckingAcc)
        {
            cout << "Dear User, You Have Insufficient Funds In Your Checking Account! " << endl;
            return;
        }
        CheckingAcc -= Amount[NumOfExp]; // Deduct from checking account.
    }
    else if (Acc == 2)
    {
        if (Amount[NumOfExp] > SavingsAcc)
        {
            cout << "Dear User, You Have Insufficient Funds In Your Savings Account! " << endl;
            return;
        }
        SavingsAcc -= Amount[NumOfExp]; // Deduct from savings account.
    }
    else 
    {
        cout << "Dear User, You Have Entered A Wrong Option. Please Input 1 For Checking Account Or 2 For Savings Account! " << endl;
        return;
    }

    NumOfExp++; 
    cout << "Expense Added!" << endl;
}

void ViewExp()
{
    if (NumOfExp == 0)
    {
        cout<<"No Expenses Avaliable!"<<endl;
        return;
    }
    cout<<"---- All Expenses ----"<<endl;
    for (int z = 0; z < NumOfExp; z++)
    {
        cout<<"Category: "<<category[z]<<", Amount: "<<fixed<<setprecision(2)<<Amount[z]<<endl;//set precision available in chapter 5 it  an inbuilt method that is used to manipulate floating point values.
    }
}



void DeleteExp()
{
    if (NumOfExp == 0)
    {
        cout<<"No Expenses Available To Delete!"<<endl;
        return;
    }
    float ExpAmountElim;
    string temp;
    string CategoryElim;//Category deleted or eliminated.
    cout<<"Please Enter Category You Wish To Delete!"<<endl;
    getline(cin, temp);
    getline(cin, CategoryElim);
    cout<<"Please Enter The Expense Amount You Wish To Delete!"<<endl;
    cin>>ExpAmountElim;
    int ind = -1;
    for (int n = 0; n < NumOfExp ; ++n)
    {
      if (category[n] == CategoryElim && Amount[n] == ExpAmountElim)
      {
        ind = n;
        break;
      }
    }
    if (ind != -1)
    {
        CheckingAcc += Amount[ind]; 
        for(int n = ind; n <NumOfExp - 1; ++n)
        {
            category[n] = category[n + 1];
            Amount[n] = Amount [n + 1];
        }
        NumOfExp--;
        cout<<"Expense Has Been Deleted! "<<endl;
    }
    else
    {
        cout<<"No Expenses Available To Delete! "<<endl;
    }
    
}



void HighestExp()
{
  if (NumOfExp == 0 )
  {
    cout<<"No Expenses Available To Display!"<<endl;
    return;
  }
  
  int Highestind = 0;
  for(int n = 1; n < NumOfExp; ++n)
  {
    if (Amount[n] > Amount[Highestind])
    {
      Highestind = n;
    }
  }
  cout<<"\n---- Highest Expense ↑ ----\n";
  cout<<"Category: "<<category[Highestind]<<endl;
  cout<<"Amount: "<<fixed<<setprecision(2)<< Amount[Highestind]<<endl;
}



void ExpSummary()
{
  if ( NumOfExp == 0)
  {
    cout<<"No Expenses Available To Show A Summary!"<<endl;
    return;
  }
  
  float total = 0;
  for( int n = 0; n < NumOfExp; n++)
  {
    total += Amount[n];
  }
  cout<<"\n---- Total Expenses Summary ----\n"<<endl;
  cout<<"The Total Expenses Are: "<< fixed << setprecision(2) << total <<endl;
}



void SearchExpByCategory()
{
  if ( NumOfExp ==0 )
  {
    cout<<"No Expense Available To Search!"<<endl;
    return;
  }
  string temp;
  string CategorySearch;
  cout<<"Please Enter Category To Search For: "<<endl;
  getline (cin, temp);
  getline(cin, CategorySearch);
  
  bool Found = false;
  for (int n = 0; n < NumOfExp; ++n)
  {
    if(category[n] == CategorySearch)
    {
      cout<<"Category: "<<category[n]<<endl;
      cout<<"Amount: "<<fixed<<setprecision(2)<<Amount[n]<<endl;
      Found = true;
      
    }
  }
  if (!Found)
  {
    cout<<"No Expenses Were Found For The Give Category"<<endl;
  }
}



void ResetExps()
{
    if(NumOfExp == 0)
    {
        cout<<"No Expenses Available To Reset! "<<endl;
    }
    for (int n = 0; n < NumOfExp; n++)
    {
       category[n] = " ";
       Amount[n] = 0.0;
    }
    NumOfExp = 0;
    cout<<"All Expenses successfully Deleted! "<<endl;
}
