#include<iostream>
#include<time.h>
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define RTT 5
#define TIMEOUT 7
#define TOT_FRAMES 7
enum {NO,YES} ACK;
using namespace std;
int main()
{
int wait_time,i=1;
ACK=YES;
for(;i<=TOT_FRAMES;)
{
if(ACK==YES&&i!=1)
{
cout<<"\n sender:ack for frame"<<i-1<<"received\n";
}
cout<<"\n sender:frame"<<i<<"sent,waiting for ack";
ACK=NO;
wait_time=rand()%4+1;
if(wait_time==TIMEOUT)
{
cout<<"\n sender:ack not received for frame"<<i<<"TIMEOUT resending frame";
}
else
{
Sleep(RTT/2);
cout<<"\n Reciever:frame"<<i<<"recieved,ack sent\n";
cout<<"\n---------\n";
ACK=YES;
Sleep(RTT/2);
i++;
}
}
return 0;
}