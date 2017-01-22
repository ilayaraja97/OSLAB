#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argv,char *argc[])
{
    char buffer[1024];
    FILE *fin;
    //version 1
    if(argv!=3)
    {
        if(argv!=1)
        {
            printf("invlaid arguments\n");
        }
        fin=popen("cat /proc/cpuinfo |grep \"model name\"","r");
        fscanf(fin,"model name	: %[^\n]s",buffer);
        printf("Processor type : %s\n",buffer);
        pclose(fin);

        fin=popen("cat /proc/version","r");
        fscanf(fin,"Linux version %s(",buffer);
        printf("Kernel version : %s\n",buffer);
        pclose(fin);

        fin=popen("cat /proc/meminfo","r");
        fscanf(fin,"MemTotal:       %[^\n]s",buffer);
        printf("The amount of memory configured into this computer : %s\n",buffer);
        pclose(fin);

        fin=popen("cat /proc/uptime","r");
        fscanf(fin,"%s",buffer);
        printf("Amount of time since the system was last booted : %s s\n",buffer);
        pclose(fin);
    }

    //version 2
    else
    {
        int t=0,r=atoi(argc[1]),w=atoi(argc[2]);
        if(r==0||w==0)
        {
            printf("arguments can't be zero\n");
            return 1;
        }
        //cpu % vars
        int user,kernel,idle,cpuu=0,cpuk=0,cpui=0,cpu=0;
        float cpuTimeUser=0,cpuTimeKernel=0,cpuTimeIdle=0,cpuTime=0;
        //free mem vars
        long long int totMem,freeMem;
        float sumTotMem=0,sumFreeMem=0;

        long long int sectRead,sectWrit,initsr=0,initsw=0;
        float sumr=0,sumw=0;

        long long int ctxt,sumCtxt=0,initCtxt=0;

        long long int pros,sumPros=0,initPros=0;

        while(1)
        {
            if(t%r==0)
            {
                //read
                fin=popen("cat /proc/stat","r");
                fscanf(fin,"cpu %d %*d %d %d",&user,&kernel,&idle);
                pclose(fin);
                cpuTimeUser+=user-cpuu;
                cpuTimeKernel+=kernel-cpuk;
                cpuTimeIdle+=idle-cpui;
                cpuTime+=user+kernel+idle-cpu;

                fin=popen("cat /proc/meminfo","r");
                fscanf(fin,"MemTotal: %lld kB",&totMem);
                fscanf(fin,"%*s %lld kB",&freeMem);
                pclose(fin);
                sumTotMem+=totMem;
                sumFreeMem+=freeMem;

                fin=popen("cat /proc/diskstats | grep sda","r");
                //fscanf(fin,"%[^\n]s",buffer);
                fscanf(fin,"%*lld %*lld sda %lld %*lld %*lld %*lld %lld %*lld %*lld %*lld",&sectRead,&sectWrit);
                pclose(fin);
                sumr+=sectRead-initsr;
                sumw+=sectWrit-initsw;

                fin=popen("cat /proc/stat | grep ctxt","r");
                fscanf(fin,"%*s %lld",&ctxt);
                pclose(fin);
                sumCtxt+=ctxt-initCtxt;

                fin=popen("cat /proc/stat | grep processes","r");
                fscanf(fin,"%*s %lld",&pros);
                pclose(fin);
                sumPros+=pros-initPros;
            }
            if(t%w==0||t<=r)
            {
                //write
                system("clear");
                printf("User mode : %.2f %% System mode : %.2f%% Idle mode : %.2f%%\n",cpuTimeUser/cpuTime*100,cpuTimeKernel/cpuTime*100,cpuTimeIdle/cpuTime*100);
                cpuTime=cpuTimeIdle=cpuTimeKernel=cpuTimeUser=0;
                cpuu=user;
                cpuk=kernel;
                cpui=idle;
                cpu=cpuu+cpuk+cpui;

                printf("Free Memory : %lld kB %.2f %%\n",freeMem,sumFreeMem/sumTotMem*100);
                sumFreeMem=sumTotMem=0;

                printf("Rate of read : %.0f blocks/s Rate of write : %.0f blocks/s\n",sumr/(float)(r/(float)w),(float)(sumw)/(r/(float)w));
                initsr=sectRead;
                initsw=sectWrit;
                sumr=sumw=0;

                printf("Number of context switches : %.0f\n",(float)sumCtxt/(r/(float)w));
                sumCtxt=0;
                initCtxt=ctxt;

                printf("Number of new processes : %.0f\n",(float)sumPros/(r/(float)w));
                sumPros=0;
                initPros=pros;

                if(t<=r)
                {
                    system("clear");
                }
            }
            t++;
            sleep(1);
        }
    }
    return 0;
}
