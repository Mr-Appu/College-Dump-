// https://www.onlinegdb.com/HRzWh4tTq

#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter n : ");
    int n; scanf("%d",&n);
    
    int id[n],a[n],b[n],p[n];
    int vis[n];
    
    int start[n],end[n];
    int b_temp[n];
    int tot_time = 0;
    
    printf("A B P\n");
    for(int i=0;i<n;i++)
    {
        id[i] = i+1;
        scanf("%d %d %d",&a[i],&b[i],&p[i]);
        
        vis[i] = 0;
        b_temp[i] = b[i];
        
        start[i] = -1;
        end[i] = -1;
        
        tot_time += b[i];
    }
    
    int t = 0;
    
    while(t != tot_time)
    {
        int priority = 1000000;
        int j = -1;
        
        for(int i=0;i<n;i++)
        {
            if(a[i] <= t && priority > p[i] && !vis[i])
            {
                priority = p[i];
                j = i;
            }
        }
        
        int id = j;
        int tt = b[j];
        
        while(1)
        {
            int next = 1000000;
            
            for(int i=0;i<n;i++)
            {
                if(a[i] < (t+tt)  && !vis[i] && next > a[i]  &&  priority > p[i])
                {
                    next = a[i];
                    id = i;
                }
            }
            
            if(start[j] == -1) start[j] = t;
            
            if(id == j) break;
            
            
            int temp = a[id] - t;
            b[j] = b[j] - temp;
            t += temp;
            tt = b[id];
            priority = p[id];
            j = id;
        }
        
        vis[id] = 1;
        t += b[id];
        end[id] = t;
    }
    
    printf("PID Start End\n");
    for(int i=0;i<n;i++)
    {
        printf("%3d %5d %3d\n",i+1,start[i],end[i]);
    }
    
    return 0;
}
