#include<bits/stdc++.h>
#include <time.h>
#include <cstdlib>
#include<ctime>
#include <unistd.h>

#define timeoutSec 1

using namespace std;
class Clock {
    private:
        unsigned long begTime;
    public:
        void start() {
            begTime = clock();
        }
        unsigned long elapsedTime() {
            return ((unsigned long) clock() - begTime) / CLOCKS_PER_SEC;
        }
};

int main()
{
    int n;
    cout << "Enter no. of frames to send:  ";
    cin >> n;
    vector<int> frames(n);
    for(int i = 0; i < n; i++)frames[i] = i+1;

    srand(time(NULL));
    
    Clock t;
    cout<<"Frames to be transmitted:  ";
    for(int i=0; i<frames.size(); i++)cout<<frames[i]<<" ";
    cout<<endl;
    cout << "Timeout set to: " << timeoutSec << endl;
    int count = 0;
    
    cout<<endl<<"\tSender\t\t\t\tReceiver"<<endl;
    cout << "=================================================================" << endl << endl;
    
    do
    {
        bool timeout = false;

        cout<<"Sending Frame:  "<<frames[count];
        cout<<"\t\t";
        

        //Server side sends code and it takes some time to reach to receiver side
        t.start();
        //Stimulating time gap for transmition
        int to = rand()%30000 + 15000;
        for(int i=0; i<30000; i++)for(int j=0; j<to; j++){}

        //Receiver side recieving code
        if(t.elapsedTime() <= timeoutSec)
        {
            cout<<"Received Frame: " << frames[count] << "    (time elapsed: " << t.elapsedTime() << ")";
            cout<<endl;
        }
        else
        {
            cout<<"Timeout: server side unable to send code in time."<<endl;
            timeout = true;
        }

        //Receiver side sending acknowledgement
        if(!timeout)
        {
            //Stimulating time taken to send back acknoledgment
            int to = rand()%30000 + 15000;
            for(int i=0; i<30000; i++) for(int j=0; j<to; j++){}
            
            if(t.elapsedTime() <= timeoutSec){
                cout << "Acknowledgement received for Frame: " << frames[count] << "    (time elapsed: " << t.elapsedTime() << ")" << endl;
                count++;
            }
            else{
                cout<<"Timeout: receiver side unable to send acknowledgement in time."<<endl;
                timeout = true;
            }
        }
    cout << "-----------------------------------------------------------------" << endl << endl;
    }while(count < frames.size());
    
    return 0;
}