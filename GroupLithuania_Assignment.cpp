#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//Osama Part//
struct Booking
{
    int id;
	string name;
	string date;
	string time;
	Booking *next;

	void input()
	{
		cout << "\nEnter Booking Name: ";
		cin.ignore();
		getline(cin, name);
		cout << "Enter Booking Date(DD-MM-YY): ";
		cin >> date;
		cout << "Enter Booking Time (HH:MM): ";
		cin >> time;
	}

	void output()
	{
	    cout << "\nBooking ID: " << id;
		cout << "\nBooking Name: " << name;
		cout << "\nBooking Date: " << date;
		cout << "\nBooking Time: " << time;
	}
};

///// Queue Class ///// Osama Part
template <typename T>
class Queue
{
	Booking *front, *rear;
	int SIZE;

public:
	Queue()
	{
	    front = NULL;
		rear = NULL;
		SIZE = 0;
	}

	void enqueue(Booking obj)
	{
		Booking *temp;
		temp = new Booking;
		temp->id = obj.id;
		temp->name = obj.name;
		temp->date = obj.date;
		temp->time = obj.time;
		if (front == NULL)
        {
            front = rear = temp;
        }
		else
		{
			rear->next = temp;
			rear = temp;
		}
		SIZE++;
	}

	Booking dequeue()
	{
		if(!isEmpty())
        {
            Booking *temp = front;
            front = front->next;
            SIZE--;
            Booking toReturn = *temp;
            delete temp;
            return toReturn;
        }
	}

	float remove(int id){
        if(isEmpty()){
            return false;
        }
        else if(id == front->id){
            Booking *temp = front;
            front = front->next;
            SIZE--;
            delete temp;
            return true;
        }
        else{
            Booking *prev = front;
            Booking *temp = front->next;
            while(temp)
            {
                if(temp->id == id)
                {
                    SIZE--;
                    prev->next = temp->next;
                    return true;
                }
                prev = temp;
                temp = temp->next;
            }
            return false;
        }
	}

	float isEmpty()
	{
		return front == NULL;
	}

	Booking peek() const
	{
		Booking obj;
		obj.name = rear->next->name;
		obj.id = rear->next->id;
		obj.date = rear->next->date;
		obj.time = rear->next->time;
		return obj;
	}

	int length() const
	{
		return SIZE;
	}

	void makeEmpty()
	{
		while (front != NULL)
		{
			dequeue();
		}
	}

    void printQueue()
    {
        if(isEmpty()){
            cout<<" > No Bookings in the Queue ...";
        }
        else{
            cout<<" > Total Bookings: " <<SIZE <<endl;
            Booking *temp = front;
            while(temp)
            {
                temp->output();
                cout<<"\n-------------------";
                temp = temp->next;
            }
        }
    }

    Booking* search(int id){
        Booking booking;
        if(isEmpty()){
            return NULL;
        }
        else{
            Booking *temp = front;
            while(temp)
            {
                if(temp->id == id)
                {
                    return temp;
                }
                temp = temp->next;
            }
            return NULL;
        }
    }

    Booking* edit(int id){
        Booking booking;
        if(isEmpty()){
            return NULL;
        }
        else{
            Booking *temp = front;
            while(temp)
            {
                if(temp->id == id)
                {
                    cout<<"\n > Booking Found. Enter New Details ...";
                    cout<<"\n\nEnter New Date: ";
                    cin>>temp->date;
                    cout<<"Enter New Time: ";
                    cin>>temp->time;
                    return temp;
                }
                temp = temp->next;
            }
            return NULL;
        }
    }

	~Queue()
	{
		makeEmpty();
	}


};
