#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
/*
 * #include <net/if.h>
 * #include <sys/ioctl.h>
 * #include <sys/socket.h>
 * #include <linux/can.h>
 * #include <linux/can/raw.h>
 */

int main()
{

	//int can_socket;
	//struct sockaddr_can can_addr;
	//struct ifreq ifr;
	int can_socket=1;
	//can_socket = socket(PF_CAN, SOCK_RAW, CAN_RAW);


	if(can_socket == -1)
	{
		perror("creating CAN socket");
		return 1;
	}

	uint32_t can_id =0x123;
	uint8_t data[] = {0x00, 0x06, 0x07, 0x08};
	size_t data_length = sizeof(data);
	int can_dlc = 0;

	can_dlc = data_length;

	printf("CAN frme sent: ID=0x%03X, DLC=%d, data= ", can_id, can_dlc);
	for(size_t i = 0; i < can_dlc; i++ )
	{
		printf("%02X ",data[i]);
	}

	return 0;
}
