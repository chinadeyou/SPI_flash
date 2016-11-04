#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#include "ftd2xx.h"

FT_STATUS ftStatus;
DWORD numDevs;
FT_DEVICE_LIST_INFO_NODE *devInfo;
int i;
int main()
{
	printf("hello wrld!\n");
	
	// create the device information list
	ftStatus = FT_CreateDeviceInfoList(&numDevs);

	if (ftStatus == FT_OK) {
	printf("Number of devices is %d\n",numDevs);
	}
	else {
		// FT_CreateDeviceInfoList failed
		printf("error ftstatus  = %d\n",ftStatus);
	}

	if (numDevs > 0) 
	{
		// allocate storage for list based on numDevs
		devInfo =(FT_DEVICE_LIST_INFO_NODE*)malloc(sizeof(FT_DEVICE_LIST_INFO_NODE)*numDevs);
		// get the device information list
		ftStatus = FT_GetDeviceInfoList(devInfo,&numDevs);
		if (ftStatus == FT_OK)
		{
			for ( i = 0; i < numDevs; i++)
			{
				printf("Dev %d:\n",i);
				printf(" Flags=0x%x\n",devInfo[i].Flags);
				printf(" Type=0x%x\n",devInfo[i].Type);
				printf(" ID=0x%x\n",devInfo[i].ID);
				printf(" LocId=0x%x\n",devInfo[i].LocId);
				printf(" SerialNumber=%s\n",devInfo[i].SerialNumber);
				printf(" Description=%s\n",devInfo[i].Description);
				printf(" ftHandle=0x%x\n",devInfo[i].ftHandle);
			}
		}
	}



}