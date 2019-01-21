---
layout: post
title: "PAT-A 1016"
description: "code solutions"
categories: [PAT-A]
tags: [C++]
redirect_from:
  - /2019/01/21/
---
PAT-A 1016

1016 Phone Bills （25 分）

A long-distance telephone company charges its customers by the following rules:

Making a long-distance call costs a certain amount per minute, depending on the time of day when the call is made. When a customer starts connecting a long-distance call, the time will be recorded, and so will be the time when the customer hangs up the phone. Every calendar month, a bill is sent to the customer for each minute called (at a rate determined by the time of day). Your job is to prepare the bills for each month, given a set of phone call records.

## Input Specification:

Each input file contains one test case. Each case has two parts: the rate structure, and the phone call records.

The rate structure consists of a line with 24 non-negative integers denoting the toll (cents/minute) from 00:00 - 01:00, the toll from 01:00 - 02:00, and so on for each hour in the day.

The next line contains a positive number N (≤1000), followed by N lines of records. Each phone call record consists of the name of the customer (string of up to 20 characters without space), the time and date (mm:dd:hh:mm), and the word on-line or off-line.

For each test case, all dates will be within a single month. Each on-line record is paired with the chronologically next record for the same customer provided it is an off-line record. Any on-line records that are not paired with an off-line record are ignored, as are off-line records not paired with an on-line record. It is guaranteed that at least one call is well paired in the input. You may assume that no two records for the same customer have the same time. Times are recorded using a 24-hour clock.
    
## Output Specification:

For each test case, you must print a phone bill for each customer.

Bills must be printed in alphabetical order of customers' names. For each customer, first print in a line the name of the customer and the month of the bill in the format shown by the sample. Then for each time period of a call, print in one line the beginning and ending time and date (dd:hh:mm), the lasting time (in minute) and the charge of the call. The calls must be listed in chronological order. Finally, print the total charge for the month in the format shown by the sample.

## Sample Input:

    10 10 10 10 10 10 20 20 20 15 15 15 15 15 15 15 20 30 20 15 15 10 10 10
    10
    CYLL 01:01:06:01 on-line
    CYLL 01:28:16:05 off-line
    CYJJ 01:01:07:00 off-line
    CYLL 01:01:08:03 off-line
    CYJJ 01:01:05:59 on-line
    aaa 01:01:01:03 on-line
    aaa 01:02:00:01 on-line
    CYLL 01:28:15:41 on-line
    aaa 01:05:02:24 on-line
    aaa 01:04:23:59 off-line
    
## Sample Output:
    
	CYJJ 01
	01:05:59 01:07:00 61 $12.10
	Total amount: $12.10
	CYLL 01
	01:06:01 01:08:03 122 $24.40
	28:15:41 28:16:05 24 $3.85
	Total amount: $28.25
	aaa 01
	02:00:01 04:23:59 4318 $638.80
	Total amount: $638.80
    
## my own thoughts

This problem is quite a complex problem which mainly requires us to sort and process output format. However,It's quite wired that no matter how modified, I still got 0 point which means all passpoints failed. But when I change the compiler to clang++ instead of g++,  I got full grades (- -). Thus I'm quite confused. I will continue to find the reason and I'll put my latest discovery into chapter **reflcetion**.
Here are my codes:
  
    {% highlight ruby %}
    #include <iostream>
    #include <cstdio>
    #include <vector>
    #include <string>
    #include <algorithm>
    using namespace std;

    typedef struct
    {
        int month,day,hour,minute;
        bool ison;
    }info;
    typedef struct
    {
        vector<info> data;
        string name;
    }user;

    int cmp1(user a,user b)
    {
        return a.name<b.name;
    }

    int cmp2(info a,info b)
    {
        int tmpa,tmpb;
        tmpa=a.minute+a.hour*100+a.day*10000+a.month*1000000;
        tmpb=b.minute+b.hour*100+b.day*10000+b.month*1000000;
        return tmpa<tmpb;
    }

    int main()
    {
        float price[24];
        int n;
        int namenum=1;
        float total;
        vector<user> p;

        for(int i=0;i<24;++i)
        {
            cin>>price[i];
            price[i]/=100;
        }
        cin>>n;
        for(int i=0;i<n;++i)
        {
            int j;
            user tmp1;
            info tmp2;
            string tmp3;
            cin>>tmp1.name;
            scanf("%d:%d:%d:%d",&tmp2.month,&tmp2.day,&tmp2.hour,&tmp2.minute);
            cin>>tmp3;
            if(tmp3=="on-line")
                tmp2.ison=true;
            else
                tmp2.ison=false;

            for(j=0;j<p.size();++j)
                if(p[j].name==tmp1.name)
                    break;
            if(j==p.size())
                p.push_back(tmp1);
            p[j].data.push_back(tmp2);
        }
        sort(p.begin(),p.end(),cmp1);
        for(int i=0;i<p.size();++i)
        {
            int flag=0;
            total=0;
            sort(p[i].data.begin(),p[i].data.end(),cmp2);
            int j=0;
            while(p[i].data[j].ison==false)
                j++;
            for(;j<p[i].data.size();++j)
            {
                float once=0;
                info start,end;
                if(p[i].data[j].ison)
                    start=p[i].data[j];
                else if(p[i].data[j-1].ison)
                {
                    if(flag==0)
                    {
                        cout<<p[i].name;
                        printf(" %02d\n",p[i].data[0].month);
                        flag=1;
                    }
                    end=p[i].data[j];
                    printf("%02d:%02d:%02d %02d:%02d:%02d ",start.day,start.hour,start.minute,end.day,end.hour,end.minute);
                    int time=end.minute+end.hour*60+end.day*24*60-(start.minute+start.hour*60+start.day*24*60);
                    cout<<time<<' ';
                    if(end.day-start.day>1)
                    {
                        for(int k=0;k<24;++k)
                            once+=price[k]*60*(end.day-start.day-1);
                    }
                    if(end.day-start.day>=1)
                    {
                        for(int k=0;k<end.hour;++k)
                            once+=price[k]*60;
                        for(int k=start.hour+1;k<24;++k)
                            once+=price[k]*60;
                        once+=price[end.hour]*end.minute;
                        once+=price[start.hour]*(60-start.minute);
                    }
                    else
                    {
                        if(end.hour-start.hour>1)
                        {
                            for(int k=start.hour+1;k<end.hour;k++)
                                once+=price[k]*60;
                        }
                        if(end.hour-start.hour>=1)
                        {
                            once+=price[end.hour]*end.minute;
                            once+=price[start.hour]*(60-start.minute);
                        }
                        else
                            once+=price[start.hour]*(end.minute-start.minute);
                    }
                    printf("$%.2f\n",once);
                    total+=once;
                }
            }
            if(total!=0)
                printf("Total amount: $%.2f\n",total);
        }
    }
	{% endhighlight %}
	
---	
## reflection

Still confused

---
  If you find there are faults in the source codes, any method connecting with me is welcomed.
