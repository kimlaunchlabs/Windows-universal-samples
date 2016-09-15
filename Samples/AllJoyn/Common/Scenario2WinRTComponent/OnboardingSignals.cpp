//*********************************************************
//
// Copyright (c) Microsoft. All rights reserved.
// This code is licensed under the MIT License (MIT).
// THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
// IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
// PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.
//
//*********************************************************
//-----------------------------------------------------------------------------
// <auto-generated>
//   This code was generated by a tool.
//
//   Changes to this file may cause incorrect behavior and will be lost if
//   the code is regenerated.
//
//   For more information, see: http://go.microsoft.com/fwlink/?LinkID=623246
// </auto-generated>
//-----------------------------------------------------------------------------
#include "pch.h"

using namespace Microsoft::WRL;
using namespace Platform;
using namespace Windows::Devices::AllJoyn;
using namespace Windows::Foundation;
using namespace org::alljoyn::Onboarding;

void OnboardingSignals::Initialize(_In_ ISignalEmitter^ emitter)
{
    m_emitter = emitter;
    alljoyn_busattachment nativeBusAttachment = AllJoynHelpers::GetInternalBusAttachment(m_emitter->BusObject->BusAttachment);
    auto interfaceDefinition = alljoyn_busattachment_getinterface(nativeBusAttachment, "org.alljoyn.Onboarding");
    alljoyn_interfacedescription_getmember(interfaceDefinition, "ConnectionResult", &m_memberConnectionResult);
}

void OnboardingSignals::ConnectionResult(_In_ Onboarding^ interfaceMemberArg)
{
    if (nullptr == AllJoynHelpers::GetInternalBusObject(m_emitter->BusObject))
    {
        return;
    }

    size_t argCount = 1;
    alljoyn_msgarg arguments = alljoyn_msgarg_array_create(argCount);
    (void)TypeConversionHelpers::SetAllJoynMessageArg(alljoyn_msgarg_array_element(arguments, 0), "(ns)", interfaceMemberArg);
    
    alljoyn_busobject_signal(
        AllJoynHelpers::GetInternalBusObject(m_emitter->BusObject), 
        NULL,  // Generated code only supports broadcast signals.
        m_emitter->Session->Id,
        m_memberConnectionResult,
        arguments,
        argCount, 
        0, // A signal with a TTL of 0 will be sent to every member of the session, regardless of how long it takes to deliver the message
        ALLJOYN_MESSAGE_FLAG_GLOBAL_BROADCAST, // Broadcast to everyone in the session.
        NULL); // The generated code does not need the generated signal message

    alljoyn_msgarg_destroy(arguments);
}

void OnboardingSignals::CallConnectionResultReceived(_In_ OnboardingSignals^ sender, _In_ OnboardingConnectionResultReceivedEventArgs^ args)
{
    ConnectionResultReceived(sender, args);
}

