/*

  This file is provided under a dual BSD/GPLv2 license.  When using or
  redistributing this file, you may do so under either license.

  GPL LICENSE SUMMARY

  Copyright(c) 1999 - 2015 Intel Corporation. All rights reserved.

  This program is free software; you can redistribute it and/or modify
  it under the terms of version 2 of the GNU General Public License as
  published by the Free Software Foundation.

  This program is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St - Fifth Floor, Boston, MA 02110-1301 USA.
  The full GNU General Public License is included in this distribution
  in the file called LICENSE.GPL.

  Contact Information:
  e1000-devel Mailing List <e1000-devel@lists.sourceforge.net>
  Intel Corporation, 5200 N.E. Elam Young Parkway, Hillsboro, OR 97124-6497

  BSD LICENSE

  Copyright(c) 1999 - 2015 Intel Corporation. All rights reserved.
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in
      the documentation and/or other materials provided with the
      distribution.
    * Neither the name of Intel Corporation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

/*
 *
 * Module Name:
 *   linuxpci_i.h
 *
 *  Abstract:
 *   This file contains Linux specific prototypes & variable types
 *
 */


#include "hwbus_t.h"

#ifndef _LINUX_PCIINTERFACE_H_
#define _LINUX_PCIINTERFACE_H_ 

#define MAX_SEGMENTS 0xFF
#define MAX_BUSES 256
#define MAX_DEVICES 32
#define MAX_FUNCTIONS 8
#define NAL_NO_PCI_BUS 0
#define NAL_NO_DEVICE 2

UINT16
_NalReadPciDeviceCount(VOID);

NAL_STATUS
_NalReadPciDevice(
    OUT NAL_DEVICE_LOCATION* PciLocations,
    IN OUT UINT16* Count
    );

NAL_STATUS
_NalReadPciDeviceScanPci(
    OUT NAL_DEVICE_LOCATION* PciLocations,
    IN OUT UINT16* Count
    );

NAL_STATUS
_NalFillPciConfigSpec(
    IN NAL_DEVICE_LOCATION PciLocation,
    OUT PCI_DEVICE* Device,
    IN UINT32 DwordCount
    );

NAL_STATUS
_NalOSReadPciConfig32(
    IN NAL_DEVICE_LOCATION PciLocation,
    IN UINT32 DwordNumber,
    OUT UINT32* Value
    );

NAL_STATUS
_NalOSWritePciConfig32(
    IN NAL_DEVICE_LOCATION PciLocation,
    IN UINT32 DwordNumber,
    IN UINT32 Data
    );

NAL_STATUS
_NalOSWritePciConfigVariable(
    IN NAL_DEVICE_LOCATION PciLocation,
    IN UINT32 DwordNumber,
    IN UINT8 ByteMask,
    IN UINT32 Data
    );

NAL_STATUS
_NalEnablePciDevice(
    IN NAL_DEVICE_LOCATION DeviceLocation
    );

NAL_STATUS
_NalOSReadPciExConfig32(
    IN NAL_DEVICE_LOCATION PciLocation,
    IN UINT32 DwordNumber,
    OUT UINT32* Value
    );

NAL_STATUS
_NalOSWritePciExConfig32(
    IN NAL_DEVICE_LOCATION PciLocation,
    IN UINT32 DwordNumber,
    IN UINT32 Data
    );

NAL_STATUS
_NalOsWritePciExConfigSpace(
    IN NAL_DEVICE_LOCATION DeviceLocation,
    IN UINT32 ByteOffset,
    IN UINT32 NoOfBytes,
    IN UINT8* Data
    );

NAL_STATUS
_NalOsReadPciExConfigSpace(
    IN NAL_DEVICE_LOCATION DeviceLocation,
    IN UINT32 ByteIndex,
    IN UINT32 NoOfBytes,
    OUT UINT8* Value
    );

NAL_STATUS
_NalOsWritePciExByte(
    IN NAL_DEVICE_LOCATION DeviceLocation,
    IN UINT32 ByteOffset,
    IN UINT8 Data
    );

NAL_STATUS
_NalOsReadPciExByte(
    IN NAL_DEVICE_LOCATION DeviceLocation,
    IN UINT32 ByteIndex,
    OUT UINT8* Value
    );

NAL_STATUS
_NalReadPciDeviceSysfs(
        OUT NAL_DEVICE_LOCATION* PciLocations,
        IN OUT UINT16* Count
        );

NAL_STATUS
_NalOSReadPciConfig32Sysfs(
    IN NAL_DEVICE_LOCATION PciLocation,
    IN UINT32 DwordNumber,
    OUT UINT32* Value
    );

NAL_STATUS
_NalOSReadPciConfigSpaceSysfs(
    IN NAL_DEVICE_LOCATION PciLocation,
    IN UINT32 DwordCount,
    OUT UINT32* Value
    );

NAL_STATUS
_NalOsPciDeviceEnableSysfs(
        IN NAL_DEVICE_LOCATION PciLocation
        );

NAL_STATUS
_NalOsPciDeviceDisableSysfs(
        IN NAL_DEVICE_LOCATION PciLocation
        );

#endif
