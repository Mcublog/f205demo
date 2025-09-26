/**
 * @file rndis_debug.c
 * @brief RNDIS (Remote Network Driver Interface Specification)
 *
 * @section License
 *
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright (C) 2010-2024 Oryx Embedded SARL. All rights reserved.
 *
 * This file is part of CycloneTCP Open.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * @author Oryx Embedded SARL (www.oryx-embedded.com)
 * @version 2.4.4
 **/


#include <inttypes.h>

#include "rndis_debug.h"
//>>---------------------- Log control
#define LOG_MODULE_NAME rndisd
#define LOG_MODULE_LEVEL (3)
#include "log_libs.h"
//<<----------------------
#define arraysize(a) (sizeof(a) / sizeof(*(a)))

//General objects (required)
#define OID_GEN_SUPPORTED_LIST             0x00010101
#define OID_GEN_HARDWARE_STATUS            0x00010102
#define OID_GEN_MEDIA_SUPPORTED            0x00010103
#define OID_GEN_MEDIA_IN_USE               0x00010104
#define OID_GEN_MAXIMUM_LOOKAHEAD          0x00010105
#define OID_GEN_MAXIMUM_FRAME_SIZE         0x00010106
#define OID_GEN_LINK_SPEED                 0x00010107
#define OID_GEN_TRANSMIT_BUFFER_SPACE      0x00010108
#define OID_GEN_RECEIVE_BUFFER_SPACE       0x00010109
#define OID_GEN_TRANSMIT_BLOCK_SIZE        0x0001010A
#define OID_GEN_RECEIVE_BLOCK_SIZE         0x0001010B
#define OID_GEN_VENDOR_ID                  0x0001010C
#define OID_GEN_VENDOR_DESCRIPTION         0x0001010D
#define OID_GEN_CURRENT_PACKET_FILTER      0x0001010E
#define OID_GEN_CURRENT_LOOKAHEAD          0x0001010F
#define OID_GEN_DRIVER_VERSION             0x00010110
#define OID_GEN_MAXIMUM_TOTAL_SIZE         0x00010111
#define OID_GEN_PROTOCOL_OPTIONS           0x00010112
#define OID_GEN_MAC_OPTIONS                0x00010113
#define OID_GEN_MEDIA_CONNECT_STATUS       0x00010114
#define OID_GEN_MAXIMUM_SEND_PACKETS       0x00010115
#define OID_GEN_VENDOR_DRIVER_VERSION      0x00010116
#define OID_GEN_SUPPORTED_GUIDS            0x00010117
#define OID_GEN_NETWORK_LAYER_ADDRESSES    0x00010118
#define OID_GEN_TRANSPORT_HEADER_OFFSET    0x00010119
#define OID_GEN_MACHINE_NAME               0x0001021A
#define OID_GEN_RNDIS_CONFIG_PARAMETER     0x0001021B
#define OID_GEN_VLAN_ID                    0x0001021C

//General objects (optional)
#define OID_GEN_MEDIA_CAPABILITIES         0x00010201
#define OID_GEN_PHYSICAL_MEDIUM            0x00010202

//Statistics objects (required)
#define OID_GEN_XMIT_OK                    0x00020101
#define OID_GEN_RCV_OK                     0x00020102
#define OID_GEN_XMIT_ERROR                 0x00020103
#define OID_GEN_RCV_ERROR                  0x00020104
#define OID_GEN_RCV_NO_BUFFER              0x00020105


// #define OID_GEN_SUPPORTED_LIST                      0x00010101UL
// #define OID_GEN_HARDWARE_STATUS                     0x00010102UL
// #define OID_GEN_MEDIA_SUPPORTED                     0x00010103UL
// #define OID_GEN_MEDIA_IN_USE                        0x00010104UL
// #define OID_GEN_MAXIMUM_FRAME_SIZE                  0x00010106UL
// #define OID_GEN_MAXIMUM_TOTAL_SIZE                  0x00010111UL
// #define OID_GEN_LINK_SPEED                          0x00010107UL
// #define OID_GEN_TRANSMIT_BLOCK_SIZE                 0x0001010AUL
// #define OID_GEN_RECEIVE_BLOCK_SIZE                  0x0001010BUL
// #define OID_GEN_VENDOR_ID                           0x0001010CUL
// #define OID_GEN_VENDOR_DESCRIPTION                  0x0001010DUL
// #define OID_GEN_CURRENT_PACKET_FILTER               0x0001010EUL
// #define OID_GEN_MEDIA_CONNECT_STATUS                0x00010114UL
// #define OID_GEN_MAXIMUM_SEND_PACKETS                0x00010115UL
// #define OID_GEN_PHYSICAL_MEDIUM                     0x00010202UL
// #define OID_GEN_XMIT_OK                             0x00020101UL
// #define OID_GEN_RCV_OK                              0x00020102UL
// #define OID_GEN_XMIT_ERROR                          0x00020103UL
// #define OID_GEN_RCV_ERROR                           0x00020104UL
// #define OID_GEN_RCV_NO_BUFFER                       0x00020105UL
#define OID_GEN_CDC_RNDIS_CONFIG_PARAMETER          0x0001021BUL
#define OID_802_3_PERMANENT_ADDRESS                 0x01010101UL
#define OID_802_3_CURRENT_ADDRESS                   0x01010102UL
#define OID_802_3_MULTICAST_LIST                    0x01010103UL
#define OID_802_3_MAXIMUM_LIST_SIZE                 0x01010104UL
#define OID_802_3_RCV_ERROR_ALIGNMENT               0x01020101UL
#define OID_802_3_XMIT_ONE_COLLISION                0x01020102UL
#define OID_802_3_XMIT_MORE_COLLISIONS              0x01020103UL

//RNDIS messages
const RndisValueName rndisMsgLabel[] =
{
   {0x00000001, "REMOTE_NDIS_PACKET_MSG"},
   {0x00000002, "REMOTE_NDIS_INITIALIZE_MSG"},
   {0x80000002, "REMOTE_NDIS_INITIALIZE_CMPLT"},
   {0x00000003, "REMOTE_NDIS_HALT_MSG"},
   {0x00000004, "REMOTE_NDIS_QUERY_MSG"},
   {0x80000004, "REMOTE_NDIS_QUERY_CMPLT"},
   {0x00000005, "REMOTE_NDIS_SET_MSG"},
   {0x80000005, "REMOTE_NDIS_SET_CMPLT"},
   {0x00000006, "REMOTE_NDIS_RESET_MSG"},
   {0x80000006, "REMOTE_NDIS_RESET_CMPLT"},
   {0x00000007, "REMOTE_NDIS_INDICATE_STATUS_MSG"},
   {0x00000008, "REMOTE_NDIS_KEEPALIVE_CMPLT"},
   {0x80000008, "REMOTE_NDIS_KEEPALIVE_CMPLT"}
};

//Status codes
const RndisValueName rndisStatusLabel[] =
{
   {0x00000000, "RNDIS_STATUS_SUCCESS"},
   {0xC0000001, "RNDIS_STATUS_FAILURE"},
   {0xC0010015, "RNDIS_STATUS_INVALID_DATA"},
   {0xC00000BB, "RNDIS_STATUS_NOT_SUPPORTED"},
   {0x4001000B, "RNDIS_STATUS_MEDIA_CONNECT"},
   {0x4001000C, "RNDIS_STATUS_MEDIA_DISCONNECT"}
};

//Object identifiers
const RndisValueName rndisOidLabel[] =
{
   //General objects
   {0x00010101, "OID_GEN_SUPPORTED_LIST"},
   {0x00010102, "OID_GEN_HARDWARE_STATUS"},
   {0x00010103, "OID_GEN_MEDIA_SUPPORTED"},
   {0x00010104, "OID_GEN_MEDIA_IN_USE"},
   {0x00010105, "OID_GEN_MAXIMUM_LOOKAHEAD"},
   {0x00010106, "OID_GEN_MAXIMUM_FRAME_SIZE"},
   {0x00010107, "OID_GEN_LINK_SPEED"},
   {0x00010108, "OID_GEN_TRANSMIT_BUFFER_SPACE"},
   {0x00010109, "OID_GEN_RECEIVE_BUFFER_SPACE"},
   {0x0001010A, "OID_GEN_TRANSMIT_BLOCK_SIZE"},
   {0x0001010B, "OID_GEN_RECEIVE_BLOCK_SIZE"},
   {0x0001010C, "OID_GEN_VENDOR_ID"},
   {0x0001010D, "OID_GEN_VENDOR_DESCRIPTION"},
   {0x0001010E, "OID_GEN_CURRENT_PACKET_FILTER"},
   {0x0001010F, "OID_GEN_CURRENT_LOOKAHEAD"},
   {0x00010110, "OID_GEN_DRIVER_VERSION"},
   {0x00010111, "OID_GEN_MAXIMUM_TOTAL_SIZE"},
   {0x00010112, "OID_GEN_PROTOCOL_OPTIONS"},
   {0x00010113, "OID_GEN_MAC_OPTIONS"},
   {0x00010114, "OID_GEN_MEDIA_CONNECT_STATUS"},
   {0x00010115, "OID_GEN_MAXIMUM_SEND_PACKETS"},
   {0x00010116, "OID_GEN_VENDOR_DRIVER_VERSION"},
   {0x00010117, "OID_GEN_SUPPORTED_GUIDS"},
   {0x00010118, "OID_GEN_NETWORK_LAYER_ADDRESSES"},
   {0x00010119, "OID_GEN_TRANSPORT_HEADER_OFFSET"},
   {0x0001021A, "OID_GEN_MACHINE_NAME"},
   {0x0001021B, "OID_GEN_RNDIS_CONFIG_PARAMETER"},
   {0x0001021C, "OID_GEN_VLAN_ID"},
   //Ethernet objects
   {0x01010101, "OID_802_3_PERMANENT_ADDRESS"},
   {0x01010102, "OID_802_3_CURRENT_ADDRESS"},
   {0x01010103, "OID_802_3_MULTICAST_LIST"},
   {0x01010104, "OID_802_3_MAXIMUM_LIST_SIZE"},
   {0x01010105, "OID_802_3_MAC_OPTIONS"},
};


/**
 * @brief Dump RNDIS message for debugging purpose
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpMsg(const RndisMsg *message, size_t length)
{
//Check current trace level

   error_t error;
   const char_t *label;

   //Check the length of the message
   if(length < sizeof(RndisMsg))
      return ERROR_INVALID_LENGTH;

   //Retrieve the name of the RNDIS message
   label = rndisFindName(message->messageType,
      rndisMsgLabel, arraysize(rndisMsgLabel));

   //Dump RNDIS message
   LOG_RAW_INFO("  MessageType = 0x%08" PRIX32 " (%s)\r\n", message->messageType, label);
   LOG_RAW_INFO("  MessageLength = %" PRIu32 "\r\n", message->messageLength);

   //Check message type
   switch(message->messageType)
   {
   //RNDIS Packet message?
   case RNDIS_PACKET_MSG:
      error = rndisDumpPacketMsg((RndisPacketMsg *) message, length);
      break;
   //RNDIS Initialize message?
   case RNDIS_INITIALIZE_MSG:
      error = rndisDumpInitializeMsg((RndisInitializeMsg *) message, length);
      break;
   //RNDIS Halt message?
   case RNDIS_HALT_MSG:
      error = rndisDumpHaltMsg((RndisHaltMsg *) message, length);
      break;
   //RNDIS Query message?
   case RNDIS_QUERY_MSG:
      error = rndisDumpQueryMsg((RndisQueryMsg *) message, length);
      break;
   //RNDIS Set message?
   case RNDIS_SET_MSG:
      error = rndisDumpSetMsg((RndisSetMsg *) message, length);
      break;
   //RNDIS Reset message?
   case RNDIS_RESET_MSG:
      error = rndisDumpResetMsg((RndisResetMsg *) message, length);
      break;
   //RNDIS Indicate Status message?
   case RNDIS_INDICATE_STATUS_MSG:
      error = rndisDumpIndicateStatusMsg((RndisIndicateStatusMsg *) message, length);
      break;
   //RNDIS Keep-Alive message?
   case RNDIS_KEEPALIVE_MSG:
      error = rndisDumpKeepAliveMsg((RndisKeepAliveMsg *) message, length);
      break;
   //RNDIS Initialize Cmplt message?
   case RNDIS_INITIALIZE_CMPLT:
      error = rndisDumpInitializeCmplt((RndisInitializeCmplt *) message, length);
      break;
   //RNDIS Query Cmplt message?
   case RNDIS_QUERY_CMPLT:
      error = rndisDumpQueryCmplt((RndisQueryCmplt *) message, length);
      break;
   //RNDIS Set Cmplt message?
   case RNDIS_SET_CMPLT:
      error = rndisDumpSetCmplt((RndisSetCmplt *) message, length);
      break;
   //RNDIS Reset Cmplt message?
   case RNDIS_RESET_CMPLT:
      error = rndisDumpResetCmplt((RndisResetCmplt *) message, length);
      break;
   //RNDIS Keep-Alive Cmplt message?
   case RNDIS_KEEPALIVE_CMPLT:
      error = rndisDumpKeepAliveCmplt((RndisKeepAliveCmplt *) message, length);
      break;
   //Unknown message type?
   default:
      error = ERROR_INVALID_TYPE;
      break;
   }

   //Return status code
   return error;

}


/**
 * @brief Dump REMOTE_NDIS_PACKET_MSG message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpPacketMsg(const RndisPacketMsg *message, size_t length)
{
   //Check the length of the message
   if(length < sizeof(RndisPacketMsg))
      return ERROR_INVALID_LENGTH;

   //Dump RNDIS message
   LOG_RAW_INFO("  DataOffset = 0x%08" PRIX32 "\r\n", message->dataOffset);
   LOG_RAW_INFO("  DataLength = %" PRIu32 "\r\n", message->dataLength);
   LOG_RAW_INFO("  OOBDataOffset = %" PRIu32 "\r\n", message->oobDataOffset);
   LOG_RAW_INFO("  OOBDataLength = %" PRIu32 "\r\n", message->oobDataLength);
   LOG_RAW_INFO("  NumOOBDataElements = %" PRIu32 "\r\n", message->numOobDataElements);
   LOG_RAW_INFO("  PerPacketInfoOffset = 0x%08" PRIX32 "\r\n", message->perPacketInfoOffset);
   LOG_RAW_INFO("  PerPacketInfoLength = %" PRIu32 "\r\n", message->perPacketInfoLength);
   LOG_RAW_INFO("  VcHandle = 0x%08" PRIX32 "\r\n", message->vcHandle);
   LOG_RAW_INFO("  Reserved = 0x%08" PRIX32 "\r\n", message->reserved);

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_INITIALIZE_MSG message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpInitializeMsg(const RndisInitializeMsg *message, size_t length)
{
   //Check the length of the message
   if(length < sizeof(RndisInitializeMsg))
      return ERROR_INVALID_LENGTH;

   //Dump RNDIS message
   LOG_RAW_INFO("  RequestID = 0x%08" PRIX32 "\r\n", message->requestId);
   LOG_RAW_INFO("  MajorVersion = %" PRIu32 "\r\n", message->majorVersion);
   LOG_RAW_INFO("  MinorVersion = %" PRIu32 "\r\n", message->minorVersion);
   LOG_RAW_INFO("  MaxTransferSize = %" PRIu32 "\r\n", message->maxTransferSize);

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_HALT_MSG message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpHaltMsg(const RndisHaltMsg *message, size_t length)
{
   //Check the length of the message
   if(length < sizeof(RndisHaltMsg))
      return ERROR_INVALID_LENGTH;

   //Dump RNDIS message
   LOG_RAW_INFO("  RequestID = 0x%08" PRIX32 "\r\n", message->requestId);

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_QUERY_MSG message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpQueryMsg(const RndisQueryMsg *message, size_t length)
{
//Check current trace level

   const char_t *label;

   //Check the length of the message
   if(length < sizeof(RndisQueryMsg))
      return ERROR_INVALID_LENGTH;

   //Retrieve the corresponding OID
   label = rndisFindName(message->oid,
      rndisOidLabel, arraysize(rndisOidLabel));

   //Dump RNDIS message
   LOG_RAW_INFO("  RequestID = 0x%08" PRIX32 "\r\n", message->requestId);
   LOG_RAW_INFO("  OID = 0x%08" PRIX32 " (%s)\r\n", message->oid, label);
   LOG_RAW_INFO("  InformationBufferLength = %" PRIu32 "\r\n", message->infoBufferLength);
   LOG_RAW_INFO("  InformationBufferOffset = %" PRIu32 "\r\n", message->infoBufferOffset);
   LOG_RAW_INFO("  Reserved = %" PRIu32 "\r\n", message->reserved);

   //Retrieve the length of the OID input buffer
   length -= sizeof(RndisQueryMsg);

   //Any data to dump?
   if(length > 0)
   {
      //Dump the content of the OID input buffer
      LOG_RAW_INFO("  OIDInputBuffer (%" PRIuSIZE " bytes)\r\n", length);
      LOG_RAW_INFO_ARRAY("    ", message->oidInputBuffer, length);
   }

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_SET_MSG message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpSetMsg(const RndisSetMsg *message, size_t length)
{
//Check current trace level

   const char_t *label;

   //Check the length of the message
   if(length < sizeof(RndisSetMsg))
      return ERROR_INVALID_LENGTH;

   //Retrieve the corresponding OID
   label = rndisFindName(message->oid,
      rndisOidLabel, arraysize(rndisOidLabel));

   //Dump RNDIS message
   LOG_RAW_INFO("  RequestID = 0x%08" PRIX32 "\r\n", message->requestId);
   LOG_RAW_INFO("  OID = 0x%08" PRIX32 " (%s)\r\n", message->oid, label);
   LOG_RAW_INFO("  InformationBufferLength = %" PRIu32 "\r\n", message->infoBufferLength);
   LOG_RAW_INFO("  InformationBufferOffset = %" PRIu32 "\r\n", message->infoBufferOffset);
   LOG_RAW_INFO("  Reserved = %" PRIu32 "\r\n", message->reserved);

   //Retrieve the length of the OID input buffer
   length -= sizeof(RndisSetMsg);

   //Any data to dump?
   if(length > 0)
   {
      //Dump the content of the OID input buffer
      LOG_RAW_INFO("  OIDInputBuffer (%" PRIuSIZE " bytes)\r\n", length);
      LOG_RAW_INFO_ARRAY("    ", message->oidInputBuffer, length);
   }


   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_RESET_MSG message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpResetMsg(const RndisResetMsg *message, size_t length)
{
   //Check the length of the message
   if(length < sizeof(RndisResetMsg))
      return ERROR_INVALID_LENGTH;

   //Dump RNDIS message
   LOG_RAW_INFO("  Reserved = 0x%08" PRIX32 "\r\n", message->reserved);

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_INDICATE_STATUS_MSG message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpIndicateStatusMsg(const RndisIndicateStatusMsg *message, size_t length)
{
//Check current trace level

   size_t n;
   const char_t *label;

   //Check the length of the message
   if(length < sizeof(RndisIndicateStatusMsg))
      return ERROR_INVALID_LENGTH;

   //Retrieve the corresponding status string
   label = rndisFindName(message->status,
      rndisStatusLabel, arraysize(rndisStatusLabel));

   //Dump RNDIS message
   LOG_RAW_INFO("  Status = 0x%08" PRIX32 " (%s)\r\n", message->status, label);
   LOG_RAW_INFO("  StatusBufferLength = %" PRIu32 "\r\n", message->statusBufferLength);
   LOG_RAW_INFO("  StatusBufferOffset = %" PRIu32 "\r\n", message->statusBufferOffset);

   //Calculate the length of the diagnostic information buffer
   n = length - message->statusBufferLength;

   //Any data to dump?
   if(n > 0)
   {
      //Dump the content of the diagnostic information buffer
      LOG_RAW_INFO("  DiagnosticInfoBuffer (%" PRIuSIZE " bytes)\r\n", n);
      //LOG_RAW_INFO_ARRAY("    ", message->diagnosticInfoBuffer, n);
   }

   //Calculate the length of the status buffer
   n = message->statusBufferLength;

   //Any data to dump?
   if(n > 0)
   {
      //Dump the content of the status buffer
      LOG_RAW_INFO("  DiagnosticInfoBuffer (%" PRIuSIZE " bytes)\r\n", n);
      //LOG_RAW_INFO_ARRAY("    ", message->diagnosticInfoBuffer, n);
   }


   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_KEEPALIVE_MSG message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpKeepAliveMsg(const RndisKeepAliveMsg *message, size_t length)
{
   //Check the length of the message
   if(length < sizeof(RndisKeepAliveMsg))
      return ERROR_INVALID_LENGTH;

   //Dump RNDIS message
   LOG_RAW_INFO("  RequestID = 0x%08" PRIX32 "\r\n", message->requestId);

   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_INITIALIZE_CMPLT message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpInitializeCmplt(const RndisInitializeCmplt *message, size_t length)
{
//Check current trace level

   const char_t *label;

   //Check the length of the message
   if(length < sizeof(RndisInitializeCmplt))
      return ERROR_INVALID_LENGTH;

   //Retrieve the corresponding status string
   label = rndisFindName(message->status,
      rndisStatusLabel, arraysize(rndisStatusLabel));

   //Dump RNDIS message
   LOG_RAW_INFO("  RequestID = 0x%08" PRIX32 "\r\n", message->requestId);
   LOG_RAW_INFO("  Status = 0x%08" PRIX32 " (%s)\r\n", message->status, label);
   LOG_RAW_INFO("  MajorVersion = %" PRIu32 "\r\n", message->majorVersion);
   LOG_RAW_INFO("  MinorVersion = %" PRIu32 "\r\n", message->minorVersion);
   LOG_RAW_INFO("  DeviceFlags = 0x%08" PRIX32 "\r\n", message->deviceFlags);
   LOG_RAW_INFO("  Medium = 0x%08" PRIX32 "\r\n", message->medium);
   LOG_RAW_INFO("  MaxPacketsPerTransfer = %" PRIu32 "\r\n", message->maxPacketsPerTransfer);
   LOG_RAW_INFO("  MaxTransferSize = %" PRIu32 "\r\n", message->maxTransferSize);
   LOG_RAW_INFO("  PacketAlignmentFactor = %" PRIu32 "\r\n", message->packetAlignmentFactor);
   LOG_RAW_INFO("  AFListOffset = %" PRIu32 "\r\n", message->afListOffset);
   LOG_RAW_INFO("  AFListSize = %" PRIu32 "\r\n", message->afListSize);


   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_QUERY_CMPLT message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpQueryCmplt(const RndisQueryCmplt *message, size_t length)
{
//Check current trace level

   const char_t *label;

   //Check the length of the message
   if(length < sizeof(RndisQueryCmplt))
      return ERROR_INVALID_LENGTH;

   //Retrieve the corresponding status string
   label = rndisFindName(message->status,
      rndisStatusLabel, arraysize(rndisStatusLabel));

   //Dump RNDIS message
   LOG_RAW_INFO("  RequestID = 0x%08" PRIX32 "\r\n", message->requestId);
   LOG_RAW_INFO("  Status = 0x%08" PRIX32 " (%s)\r\n", message->status, label);
   LOG_RAW_INFO("  InformationBufferLength = %" PRIu32 "\r\n", message->infoBufferLength);
   LOG_RAW_INFO("  InformationBufferOffset = %" PRIu32 "\r\n", message->infoBufferOffset);

   //Retrieve the length of the OID input buffer
   length -= sizeof(RndisQueryCmplt);

   //Any data to dump?
   if(length > 0)
   {
      //Dump the content of the OID input buffer
      LOG_RAW_INFO("  OIDInputBuffer (%" PRIuSIZE " bytes)\r\n", length);
      LOG_RAW_INFO_ARRAY("    ", message->oidInputBuffer, length);
   }


   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_SET_CMPLT message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpSetCmplt(const RndisSetCmplt *message, size_t length)
{
//Check current trace level

   const char_t *label;

   //Check the length of the message
   if(length < sizeof(RndisSetCmplt))
      return ERROR_INVALID_LENGTH;

   //Retrieve the corresponding status string
   label = rndisFindName(message->status,
      rndisStatusLabel, arraysize(rndisStatusLabel));

   //Dump RNDIS message
   LOG_RAW_INFO("  RequestID = 0x%08" PRIX32 "\r\n", message->requestId);
   LOG_RAW_INFO("  Status = 0x%08" PRIX32 " (%s)\r\n", message->status, label);


   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_RESET_CMPLT message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpResetCmplt(const RndisResetCmplt *message, size_t length)
{
//Check current trace level

   const char_t *label;

   //Check the length of the message
   if(length < sizeof(RndisResetCmplt))
      return ERROR_INVALID_LENGTH;

   //Retrieve the corresponding status string
   label = rndisFindName(message->status,
      rndisStatusLabel, arraysize(rndisStatusLabel));

   //Dump RNDIS message
   LOG_RAW_INFO("  Status = 0x%08" PRIX32 " (%s)\r\n", message->status, label);
   LOG_RAW_INFO("  AddressingReset = 0x%08" PRIX32 "\r\n", message->addressingReset);


   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Dump REMOTE_NDIS_KEEPALIVE_CMPLT message
 * @param[in] message Pointer to the RNDIS message
 * @param[in] length Length of the message, in bytes
 * @return Error code
 **/

error_t rndisDumpKeepAliveCmplt(const RndisKeepAliveCmplt *message, size_t length)
{
//Check current trace level

   const char_t *label;

   //Check the length of the message
   if(length < sizeof(RndisKeepAliveCmplt))
      return ERROR_INVALID_LENGTH;

   //Retrieve the corresponding status string
   label = rndisFindName(message->status,
      rndisStatusLabel, arraysize(rndisStatusLabel));

   //Dump RNDIS message
   LOG_RAW_INFO("  RequestID = 0x%08" PRIX32 "\r\n", message->requestId);
   LOG_RAW_INFO("  Status = 0x%08" PRIX32 " (%s)\r\n", message->status, label);


   //Successful processing
   return NO_ERROR;
}


/**
 * @brief Helper function
 * @param[in] value 32-bit value
 * @param[in] table Look-up table
 * @param[in] size Number of entries in the look-up table
 * @return Pointer to the matching name, if any
 **/

const char_t *rndisFindName(uint32_t value, const RndisValueName *table, size_t size)
{
   //Local variables
   size_t i;

   //Default name
   static const char_t defaultName[] = "Unknown";

   //Loop through the look-up table
   for(i = 0; i < size; i++)
   {
      //Compare values
      if(table[i].value == value)
      {
         //Return a pointer to the corresponding name
         return table[i].name;
      }
   }

   //No matching entry...
   return defaultName;
}
