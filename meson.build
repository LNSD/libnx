project('nx', 'c',
        version : '4.9.0',
        meson_version : '>= 1.4.0',
        default_options : [
            'warning_level=1', # -Wall
            'werror=true', # -Werror
            'cpp_std=gnu++11', # -std=gnu++11
        ])

#---------------------------------------------------------------------------------
# Dependencies
#---------------------------------------------------------------------------------
deps = []

# nx-svc
if get_option('use_nx_svc').enabled()
    nx_svc_proj = subproject('nx-svc')

    deps += nx_svc_proj.get_variable('nx_svc_dep')
endif

#---------------------------------------------------------------------------------
# Static library
#---------------------------------------------------------------------------------
# The project source code is in the nx subdir
subdir('nx')

# Compiler options
arch_opts = ['-march=armv8-a+crc+crypto', '-mtune=cortex-a57', '-mtp=soft', '-fPIC', '-ftls-model=local-exec']
c_opts = ['-g', '-ffunction-sections', '-fdata-sections'] + arch_opts
c_opts += ['-D__SWITCH__', '-DLIBNX_NO_DEPRECATION']
cpp_opts = ['-fno-rtti', '-fno-exceptions']

nx_lib = static_library('nx',
                        [c_src, s_src, data_gen_src],
                        include_directories : internal_inc,
                        dependencies : deps,
                        c_args : c_opts,
                        cpp_args : cpp_opts)

#---------------------------------------------------------------------------------
# Dependency declaration
#---------------------------------------------------------------------------------
nx_dep_deps = []
nx_dep_link_args = []

# Provide the SVC override define and propagate nx-svc dependency
if get_option('use_nx_svc').enabled()
    nx_dep_deps += deps
    
    # Add linker wrap flags for all SVC functions
    svc_functions = [
        'svcSetHeapSize', 'svcSetMemoryPermission', 'svcSetMemoryAttribute',
        'svcMapMemory', 'svcUnmapMemory', 'svcQueryMemory', 'svcExitProcess',
        'svcCreateThread', 'svcStartThread', 'svcExitThread', 'svcSleepThread',
        'svcGetThreadPriority', 'svcSetThreadPriority', 'svcGetThreadCoreMask',
        'svcSetThreadCoreMask', 'svcGetCurrentProcessorNumber', 'svcSignalEvent',
        'svcClearEvent', 'svcMapSharedMemory', 'svcUnmapSharedMemory',
        'svcCreateTransferMemory', 'svcCloseHandle', 'svcResetSignal',
        'svcWaitSynchronization', 'svcCancelSynchronization', 'svcArbitrateLock',
        'svcArbitrateUnlock', 'svcWaitProcessWideKeyAtomic', 'svcSignalProcessWideKey',
        'svcWaitForAddress', 'svcSignalToAddress', 'svcCreateEvent',
        'svcMapTransferMemory', 'svcUnmapTransferMemory', 'svcCreateSharedMemory',
        'svcCreateInterruptEvent', 'svcQueryPhysicalAddress', 'svcQueryMemoryMapping',
        'svcLegacyQueryIoMapping', 'svcCreateDeviceAddressSpace', 'svcAttachDeviceAddressSpace',
        'svcDetachDeviceAddressSpace', 'svcMapDeviceAddressSpaceByForce',
        'svcMapDeviceAddressSpaceAligned', 'svcMapDeviceAddressSpace', 'svcUnmapDeviceAddressSpace',
        'svcDebugActiveProcess', 'svcBreakDebugProcess', 'svcTerminateDebugProcess',
        'svcGetDebugEvent', 'svcContinueDebugEvent', 'svcLegacyContinueDebugEvent',
        'svcGetDebugThreadContext', 'svcSetDebugThreadContext', 'svcQueryDebugProcessMemory',
        'svcReadDebugProcessMemory', 'svcWriteDebugProcessMemory', 'svcSetHardwareBreakPoint',
        'svcGetDebugThreadParam', 'svcGetProcessList', 'svcGetThreadList',
        'svcGetDebugFutureThreadInfo', 'svcGetLastThreadInfo', 'svcGetResourceLimitLimitValue',
        'svcGetResourceLimitCurrentValue', 'svcGetResourceLimitPeakValue', 'svcCreateResourceLimit',
        'svcSetResourceLimitLimitValue', 'svcCreateCodeMemory', 'svcControlCodeMemory',
        'svcSleepSystem', 'svcReadWriteRegister', 'svcSetThreadActivity',
        'svcGetThreadContext3', 'svcSetProcessActivity', 'svcGetProcessId',
        'svcGetThreadId', 'svcBreak', 'svcOutputDebugString', 'svcReturnFromException',
        'svcGetInfo', 'svcGetSystemInfo', 'svcCreateSession', 'svcAcceptSession',
        'svcReplyAndReceiveLight', 'svcReplyAndReceive', 'svcReplyAndReceiveWithUserBuffer',
        'svcCreatePort', 'svcManageNamedPort', 'svcConnectToPort', 'svcSetProcessMemoryPermission',
        'svcMapProcessMemory', 'svcUnmapProcessMemory', 'svcQueryProcessMemory',
        'svcMapProcessCodeMemory', 'svcUnmapProcessCodeMemory', 'svcCreateProcess',
        'svcStartProcess', 'svcTerminateProcess', 'svcGetProcessInfo', 'svcCreateIoPool',
        'svcCreateIoRegion', 'svcMapIoRegion', 'svcUnmapIoRegion', 'svcConnectToNamedPort',
        'svcSendSyncRequestLight', 'svcSendSyncRequest', 'svcSendSyncRequestWithUserBuffer',
        'svcSendAsyncRequestWithUserBuffer', 'svcGetSystemTick', 'svcSynchronizePreemptionState',
        'svcCallSecureMonitor', 'svcDumpInfo', 'svcKernelDebug', 'svcChangeKernelTraceState'
    ]
    
    foreach func : svc_functions
        nx_dep_link_args += ['-Wl,--wrap,' + func]
    endforeach
endif

nx_dep = declare_dependency(
    link_with : nx_lib, 
    include_directories : nx_dep_inc,
    dependencies : nx_dep_deps,
    link_args : nx_dep_link_args,
)
