#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct Person{
    int idx;
    int t;
    int time;
};

struct Person queue[5000];
int head = 0, tail = 0;
int waitTime[5000] = {0};
int type[200][500];

int main(){
    int T;
    scanf("%d", &T);
    int arriveCount[200];
    for(int i = 0; i < T; i++) scanf("%d", &arriveCount[i]);
    for(int i = 0; i < T; i++){
        for(int j = 0; j < arriveCount[i]; j++){
            scanf("%d", &type[i][j]);
        }
    }

    int window[5];
    memset(window, -1, sizeof(window));
    int windowLeft[5];
    memset(windowLeft, 0, sizeof(windowLeft));
    int used[5] = {0, 0, 0, 0, 0};
    int personWindow = 3;
    int sum = 0;
    int next = 0;
    int peopleIdx = 1;
    int allArrived = 0;
    int cycle = 0;

    while(1){
        int hasNew = 0;
        if(next < T){
            for(int j = 0; j < arriveCount[next]; j++){
                struct Person p;
                p.idx = peopleIdx;
                peopleIdx++;
                p.t = cycle;
                p.time = type[next][j];
                queue[tail] = p;
                tail++;
                hasNew = 1;
            }
            next++;
            if(next >= T) allArrived = 1;
        }
        if(hasNew){
            int waiting = tail - head;
            while(1){
                if(waiting / personWindow < 7) break;
                int added = 0;
                for(int i = 3; i < 5 && !added; i++){
                    if(window[i] == -1 && !used[i]){
                        used[i] = 1;
                        personWindow++;
                        added = 1;
                    }
                }
                if(!added) break;
            }
        }
        for(int i = 0; i < 5; i++){
            if(window[i] != -1){
                windowLeft[i]--;
                if(windowLeft[i] == 0){
                    window[i] = -1;
                }
            }
        }
        {
            int waiting = tail - head;
            while(personWindow > 3){
                if(waiting / personWindow < 7){
                    int removed = 0;
                    for(int i = 4; i >= 3; i--){
                        if(used[i] && window[i] == -1){
                            used[i] = 0;
                            personWindow--;
                            removed = 1;
                            break;
                        }
                    }
                    if(!removed) break;
                }
                else break;
            }
        }
        for(int i = 0; i < 5; i++){
            if(i < 3 || used[i]){
                if(window[i] == -1 && head < tail){
                    struct Person p = queue[head];
                    head++;
                    window[i] = p.idx;
                    windowLeft[i] = p.time;
                    waitTime[p.idx] = cycle - p.t;
                    sum = p.idx;
                }
            }
        }
        if(allArrived && head == tail){
            int allIdle = 1;
            for(int i = 0; i < 5; i++)
                if(window[i] != -1) allIdle = 0;
            if(allIdle) break;
        }
        cycle++;
    }
    for(int i = 1; i <= sum; i++){
        printf("%d : %d\n", i, waitTime[i]);
    }
    return 0;
}
