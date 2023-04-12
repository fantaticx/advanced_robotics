/*
 * rosserial SyncGen
 */
#include "mbed.h"
#include <ros.h>
#include <std_msgs/String.h>
#include <rosserial_mbed/SyncGen.h>

ros::NodeHandle  nh;
using rosserial_mbed::SyncGen;

#if defined(TARGET_LPC1768)
const int CH_LEN = 6;
PwmOut channels[CH_LEN] = {p26, p25, p24, p23, p22, p21};
#else
#error "You need to specify the pins for the adcs"
#endif


int t_ms = 0;

// void channelCB(const std_msgs::Int32& freq){
        
//     // calculated the periods
//     t_ms = (int)(1000.0f/((float)freq.data));
    
//     for(int i=0; i<CH_LEN; i++)
//     {
//         if(freq.data != 0)
//         {
//             channels[i].period_ms(t_ms);
//         }    
//     }    
// }

void setGetFreq(const SyncGen::Request & req, SyncGen::Response & res) {
    // ignore if zero
    if(req.frequency != 0)
    {
        // calculated the periods
        t_ms = (int)(1000.0f/((float)req.frequency));
        
        for(int i=0; i<CH_LEN; i++)
        {
            
                channels[i].period_ms(t_ms);
        }    
    }
    res.frequency = (int)(1000.0f/((float)t_ms));
}


ros::ServiceServer<SyncGen::Request, SyncGen::Response> server("set_frequency",&setGetFreq);



int main(void) {
    nh.initNode();
    nh.advertiseService(server);
    
    // init channels with 20Hz and 200us Dut y-Cycle
    t_ms = 50;
    for(int i=0; i<CH_LEN; i++)
    {
        channels[i].period_ms(t_ms);
        channels[i].pulsewidth_us(200);
    }  


    while (1) {
        nh.spinOnce();
        wait_ms(10);
    }
}

