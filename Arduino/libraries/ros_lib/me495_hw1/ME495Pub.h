#ifndef _ROS_me495_hw1_ME495Pub_h
#define _ROS_me495_hw1_ME495Pub_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace me495_hw1
{

  class ME495Pub : public ros::Msg
  {
    public:
      std_msgs::Header header;
      float time;
      float configuration;

    ME495Pub():
      header(),
      time(0),
      configuration(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_time;
      u_time.real = this->time;
      *(outbuffer + offset + 0) = (u_time.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_time.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_time.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_time.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->time);
      union {
        float real;
        uint32_t base;
      } u_configuration;
      u_configuration.real = this->configuration;
      *(outbuffer + offset + 0) = (u_configuration.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_configuration.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_configuration.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_configuration.base >> (8 * 3)) & 0xFF;
      offset += sizeof(this->configuration);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      union {
        float real;
        uint32_t base;
      } u_time;
      u_time.base = 0;
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_time.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->time = u_time.real;
      offset += sizeof(this->time);
      union {
        float real;
        uint32_t base;
      } u_configuration;
      u_configuration.base = 0;
      u_configuration.base |= ((uint32_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_configuration.base |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_configuration.base |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_configuration.base |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->configuration = u_configuration.real;
      offset += sizeof(this->configuration);
     return offset;
    }

    const char * getType(){ return "me495_hw1/ME495Pub"; };
    const char * getMD5(){ return "91983dfb08bae7741ea33f6281cab302"; };

  };

}
#endif