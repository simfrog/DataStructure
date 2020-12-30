#pragma once
#include "CustomerQueue.h"
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

static mt19937 gen = mt19937((unsigned int)time(NULL)); /* 난수 */
static uniform_real_distribution<> dist(0,1);

class BankSimulator
{
private:
    int nSimulation;     /* 입력: 전체 시뮬레이션 횟수 */
    double probArrival;  /* 입력: 단위시간에 도착하는 평균 고객 수 */
    int tMaxService;     /* 입력: 한 고객에 대한 최대 서비스 시간 */
    int totalWaitTime;   /* 결과: 고객들이 기다린 전체시간 */
    int nCustomers;      /* 결과: 전체 고객 수 */
    int nServedCustomers;/* 결과: 서비스 받은 고객 수 */
    CustomerQueue que;   /* 고객 대기 큐 */

    /* 난수 생성하여 고객 도착 여부와 서비스 시간 자동 생성 코드 */
    bool IsNewCustomer() { return dist(gen) < probArrival; }
    int RandServiceTime() { return (int)(tMaxService*dist(gen))+1; }

    /* 새로 도착한 고객을 큐에 삽입 */
    void InsertCustomer(int arrivalTime) {
        Customer a(++nCustomers, arrivalTime, RandServiceTime());
        cout << "고객 " << a.id << "방문 (서비스 시간: " << a.tService << "분)\n";
        que.enqueue(a);
    }

public:
    /* 생성자 */
    BankSimulator():nCustomers(0),totalWaitTime(0),nServedCustomers(0){}
    
    /* 시뮬레이션 파라미터 입력 */
    void readSimulationParameters() {
        cout << "시뮬레이션 할 최대 시간 (예:10) = ";
        cin >> nSimulation;
        cout << "단위시간에 도착하는 고객 수 (예:0.5) = ";
        cin >> probArrival;
        cout << "한 고객에 대한 최대 서비스 시간 (예:5) = ";
        cin >> tMaxService;
        cout << "---------------------------------------\n";
    }

    void run() {
        int clock = 0;          /* 현재 시각 */
        int serviceTime = -1;   /* 처리에 걸리는 잔여 시간 */
        while(clock < nSimulation) {
            clock++;
            cout << "현재시각: " << clock << "\n";

            /* 새로운 고객이 도착했으면 큐에 삽입 */
            if(IsNewCustomer()) { InsertCustomer(clock); }
            /* 현재 고객 서비스 중 */
            if(serviceTime > 0) { serviceTime--; }
            else {
                if(que.isEmpty()) { continue; }     /* 기다리는 고객 없음 */
                Customer a = que.dequeue();         /* 새로 서비스 할 고객 */
                nServedCustomers++;                 /* 서비스한 고객 수 */
                totalWaitTime += clock-a.tArrival;  /* 총 대기시간 */
                cout << "고객 " << a.id << " 서비스 시작 (대기시간: " << clock-a.tArrival << "분)\n";
                serviceTime = a.tService-1;
            }
        }
    }

    void printStat() {
        cout << "---------------------------------------\n";
        cout << "서비스 받은 고객 수 = " << nServedCustomers << "명\n";
        cout << "전체 대기 시간 = " << totalWaitTime << "분\n";
        cout << "서비스 고객 평균 대기시간 = " << (double)totalWaitTime/nServedCustomers << "분\n";
        cout << "현재 대기 고객 수 = " << nCustomers-nServedCustomers << "명\n";
    }
};