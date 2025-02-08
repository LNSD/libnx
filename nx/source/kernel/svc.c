#include "types.h"
#include <nx_svc.h>

///@name Memory management
///@{

Result svcSetHeapSize(void** out_addr, u64 size) {
  return __nx_svc_set_heap_size(out_addr, size);
}

Result svcSetMemoryPermission(void* addr, u64 size, u32 perm) {
  return __nx_svc_set_memory_permission(addr, size, perm);
}

Result svcSetMemoryAttribute(void* addr, u64 size, u32 val0, u32 val1) {
  return __nx_svc_set_memory_attribute(addr, size, val0, val1);
}

Result svcMapMemory(void* dst_addr, void* src_addr, u64 size) {
  return __nx_svc_map_memory(dst_addr, src_addr, size);
}

Result svcUnmapMemory(void* dst_addr, void* src_addr, u64 size) {
  return __nx_svc_unmap_memory(dst_addr, src_addr, size);
}

Result svcQueryMemory(MemoryInfo* meminfo_ptr, u32 *pageinfo, u64 addr) {
    return __nx_svc_query_memory(meminfo_ptr, pageinfo, addr);
}

///@}

///@name Process and thread management
///@{

void NX_NORETURN svcExitProcess(void) {
  __nx_svc_exit_process();
}

Result svcCreateThread(Handle* out, void* entry, void* arg, void* stack_top, int prio, int cpuid) {
  return __nx_svc_create_thread(out, entry, arg, stack_top, prio, cpuid);
}

Result svcStartThread(Handle handle) {
  return __nx_svc_start_thread(handle);
}

void NX_NORETURN svcExitThread(void) {
  __nx_svc_exit_thread();
}

void svcSleepThread(s64 nano) {
  __nx_svc_sleep_thread(nano);
}

Result svcGetThreadPriority(s32* priority, Handle handle) {
  return __nx_svc_get_thread_priority(priority, handle);
}

Result svcSetThreadPriority(Handle handle, u32 priority) {
  return __nx_svc_set_thread_priority(handle, priority);
}

Result svcGetThreadCoreMask(s32* preferred_core, u64* affinity_mask, Handle handle) {
  return __nx_svc_get_thread_core_mask(preferred_core, affinity_mask, handle);
}

Result svcSetThreadCoreMask(Handle handle, s32 preferred_core, u32 affinity_mask) {
  return __nx_svc_set_thread_core_mask(handle, preferred_core, affinity_mask);
}

u32 svcGetCurrentProcessorNumber(void) {
  return __nx_svc_get_current_processor_number();
}

///@}

///@name Synchronization
///@{

Result svcSignalEvent(Handle handle) {
  return __nx_svc_signal_event(handle);
}

Result svcClearEvent(Handle handle) {
  return __nx_svc_clear_event(handle);
}

///@}

///@name Inter-process memory sharing
///@{

Result svcMapSharedMemory(Handle handle, void* addr, size_t size, u32 perm) {
  return __nx_svc_map_shared_memory(handle, addr, size, perm);
}

Result svcUnmapSharedMemory(Handle handle, void* addr, size_t size) {
  return __nx_svc_unmap_shared_memory(handle, addr, size);
}

Result svcCreateTransferMemory(Handle* out, void* addr, size_t size, u32 perm) {
  return __nx_svc_create_transfer_memory(out, addr, size, perm);
}

///@}

///@name Miscellaneous
///@{

Result svcCloseHandle(Handle handle) {
  return __nx_svc_close_handle(handle);
}

///@}

///@name Synchronization
///@{

Result svcResetSignal(Handle handle) {
  return __nx_svc_reset_signal(handle);
}

///@}

///@name Synchronization
///@{

Result svcWaitSynchronization(s32* index, const Handle* handles, s32 handleCount, u64 timeout) {
  return __nx_svc_wait_synchronization(index, handles, handleCount, timeout);
}

Result svcCancelSynchronization(Handle thread) {
  return __nx_svc_cancel_synchronization(thread);
}

Result svcArbitrateLock(u32 wait_tag, u32* tag_location, u32 self_tag) {
  return __nx_svc_arbitrate_lock(wait_tag, tag_location, self_tag);
}

Result svcArbitrateUnlock(u32* tag_location) {
  return __nx_svc_arbitrate_unlock(tag_location);
}

Result svcWaitProcessWideKeyAtomic(u32* key, u32* tag_location, u32 self_tag, u64 timeout) {
  return __nx_svc_wait_process_wide_key_atomic(key, tag_location, self_tag, timeout);
}

void svcSignalProcessWideKey(u32* key, s32 num) {
  __nx_svc_signal_process_wide_key(key, num);
}

///@}

///@name Miscellaneous
///@{

u64 svcGetSystemTick(void) {
  return __nx_svc_get_system_tick();
}

///@}

///@name Inter-process communication (IPC)
///@{

Result svcConnectToNamedPort(Handle* session, const char* name) {
  return __nx_svc_connect_to_named_port(session, name);
}

Result svcSendSyncRequestLight(Handle session) {
  return __nx_svc_send_sync_request_light(session);
}

Result svcSendSyncRequest(Handle session) {
  return __nx_svc_send_sync_request(session);
}

Result svcSendSyncRequestWithUserBuffer(void* usrBuffer, u64 size, Handle session) {
  return __nx_svc_send_sync_request_with_user_buffer(usrBuffer, size, session);
}

Result svcSendAsyncRequestWithUserBuffer(Handle* handle, void* usrBuffer, u64 size, Handle session) {
  return __nx_svc_send_async_request_with_user_buffer(handle, usrBuffer, size, session);
}

///@}

///@name Process and thread management
///@{

Result svcGetProcessId(u64 *processID, Handle handle) {
  return __nx_svc_get_process_id(processID, handle);
}

Result svcGetThreadId(u64 *threadID, Handle handle) {
  return __nx_svc_get_thread_id(threadID, handle);
}

///@}

///@name Miscellaneous
///@{

Result svcBreak(u32 breakReason, uintptr_t address, uintptr_t size) {
  return __nx_svc_break(breakReason, address, size);
}

///@}

///@name Debugging
///@{

Result svcOutputDebugString(const char *str, u64 size) {
  return __nx_svc_output_debug_string(str, size);
}

///@}

///@name Miscellaneous
///@{

void NX_NORETURN svcReturnFromException(Result res) {
  __nx_svc_return_from_exception(res);
}

Result svcGetInfo(u64* out, u32 id0, Handle handle, u64 id1) {
  return __nx_svc_get_info(out, id0, handle, id1);
}

///@}

///@name Cache Management
///@{

void svcFlushEntireDataCache(void) {
  __nx_svc_flush_entire_data_cache();
}

Result svcFlushDataCache(void *address, size_t size) {
  return __nx_svc_flush_data_cache(address, size);
}

///@}

///@name Memory management
///@{

Result svcMapPhysicalMemory(void *address, u64 size) {
  return __nx_svc_map_physical_memory(address, size);
}

Result svcUnmapPhysicalMemory(void *address, u64 size) {
  return __nx_svc_unmap_physical_memory(address, size);
}

///@}

///@name Process and thread management
///@{

Result svcGetDebugFutureThreadInfo(LastThreadContext *_out_context, u64 *out_thread_id, Handle debug, s64 ns) {
    return __nx_svc_get_debug_future_thread_info(_out_context, out_thread_id, debug, ns);
}

Result svcGetLastThreadInfo(LastThreadContext *_out_context, u64 *out_tls_address, u32 *out_flags) {
    return __nx_svc_get_last_thread_info(_out_context, out_tls_address, out_flags);
}

///@}

///@name Resource Limit Management
///@{

Result svcGetResourceLimitLimitValue(s64 *out, Handle reslimit_h, LimitableResource which) {
    return __nx_svc_get_resource_limit_limit_value(out, reslimit_h, which);
}

Result svcGetResourceLimitCurrentValue(s64 *out, Handle reslimit_h, LimitableResource which) {
    return __nx_svc_get_resource_limit_current_value(out, reslimit_h, which);
}

///@}

///@name Process and thread management
///@{

Result svcSetThreadActivity(Handle thread, ThreadActivity paused) {
    return __nx_svc_set_thread_activity(thread, paused);
}

Result svcGetThreadContext3(ThreadContext* ctx, Handle thread) {
    return __nx_svc_get_thread_context3(ctx, thread);
}

///@}

///@name Synchronization
///@{

Result svcWaitForAddress(void *address, u32 arb_type, s64 value, s64 timeout) {
  return __nx_svc_wait_for_address(address, arb_type, value, timeout);
}

Result svcSignalToAddress(void *address, u32 signal_type, s32 value, s32 count) {
  return __nx_svc_signal_to_address(address, signal_type, value, count);
}

///@}

///@name Miscellaneous
///@{

void svcSynchronizePreemptionState(void) {
  __nx_svc_synchronize_preemption_state();
}

///@}

///@name Resource Limit Management
///@{

Result svcGetResourceLimitPeakValue(s64 *out, Handle reslimit_h, LimitableResource which) {
    return __nx_svc_get_resource_limit_peak_value(out, reslimit_h, which);
}

///@}

///@name Memory Management
///@{

Result svcCreateIoPool(Handle *out_handle, u32 pool_type) {
  return __nx_svc_create_io_pool(out_handle, pool_type);
}

Result svcCreateIoRegion(Handle *out_handle, Handle io_pool_h, u64 physical_address, u64 size, u32 memory_mapping, u32 perm) {
  return __nx_svc_create_io_region(out_handle, io_pool_h, physical_address, size, memory_mapping, perm);
}

///@}

///@name Debugging
///@{
void svcDumpInfo(u32 dump_info_type, u64 arg0) {
  __nx_svc_dump_info(dump_info_type, arg0);
}

void svcKernelDebug(u32 kern_debug_type, u64 arg0, u64 arg1, u64 arg2) {
  __nx_svc_kernel_debug(kern_debug_type, arg0, arg1, arg2);
}

void svcChangeKernelTraceState(u32 kern_trace_state) {
  __nx_svc_change_kernel_trace_state(kern_trace_state);
}

///@}
                                                                                                                                                                                                                      \
///@name Inter-process communication (IPC)
///@{

Result svcCreateSession(Handle *server_handle, Handle *client_handle, u32 unk0, u64 unk1) {
  return __nx_svc_create_session(server_handle, client_handle, unk0, unk1);
}

Result svcAcceptSession(Handle *session_handle, Handle port_handle) {
  return __nx_svc_accept_session(session_handle, port_handle);
}

Result svcReplyAndReceiveLight(Handle handle) {
  return __nx_svc_reply_and_receive_light(handle);
}

Result svcReplyAndReceive(s32* index, const Handle* handles, s32 handleCount, Handle replyTarget, u64 timeout) {
  return __nx_svc_reply_and_receive(index, handles, handleCount, replyTarget, timeout);
}

Result svcReplyAndReceiveWithUserBuffer(s32* index, void* usrBuffer, u64 size, const Handle* handles, s32 handleCount, Handle replyTarget, u64 timeout) {
  return __nx_svc_reply_and_receive_with_user_buffer(index, usrBuffer, size, handles, handleCount, replyTarget, timeout);
}

///@}

///@name Synchronization
///@{

Result svcCreateEvent(Handle* server_handle, Handle* client_handle) {
  return __nx_svc_create_event(server_handle, client_handle);
}

///@}

///@name Memory management
///@{

Result svcMapIoRegion(Handle io_region_h, void *address, u64 size, u32 perm) {
  return __nx_svc_map_io_region(io_region_h, address, size, perm);
}

Result svcUnmapIoRegion(Handle io_region_h, void *address, u64 size) {
  return __nx_svc_unmap_io_region(io_region_h, address, size);
}

Result svcMapPhysicalMemoryUnsafe(void *address, u64 size) {
  return __nx_svc_map_physical_memory_unsafe(address, size);
}

Result svcUnmapPhysicalMemoryUnsafe(void *address, u64 size) {
  return __nx_svc_unmap_physical_memory_unsafe(address, size);
}

Result svcSetUnsafeLimit(u64 size) {
  return __nx_svc_set_unsafe_limit(size);
}

///@}

///@name Code memory / Just-in-time (JIT) compilation support
///@{

Result svcCreateCodeMemory(Handle* code_handle, void* src_addr, u64 size) {
  return __nx_svc_create_code_memory(code_handle, src_addr, size);
}

Result svcControlCodeMemory(Handle code_handle, CodeMapOperation op, void* dst_addr, u64 size, u64 perm) {
  return __nx_svc_control_code_memory(code_handle, op, dst_addr, size, perm);
}

///@}

///@name Power Management
///@{

void svcSleepSystem(void) {
  __nx_svc_sleep_system();
}

///@}

///@name Device memory-mapped I/O (MMIO)
///@{

Result svcReadWriteRegister(u32* outVal, u64 regAddr, u32 rwMask, u32 inVal) {
  return __nx_svc_read_write_register(outVal, regAddr, rwMask, inVal);
}

///@}

///@name Process and thread management
///@{

Result svcSetProcessActivity(Handle process, ProcessActivity paused) {
    return __nx_svc_set_process_activity(process, paused);
}

///@}

///@name Inter-process memory sharing
///@{

Result svcCreateSharedMemory(Handle* out, size_t size, u32 local_perm, u32 other_perm) {
  return __nx_svc_create_shared_memory(out, size, local_perm, other_perm);
}

Result svcMapTransferMemory(Handle tmem_handle, void* addr, size_t size, u32 perm) {
  return __nx_svc_map_transfer_memory(tmem_handle, addr, size, perm);
}

Result svcUnmapTransferMemory(Handle tmem_handle, void* addr, size_t size) {
  return __nx_svc_unmap_transfer_memory(tmem_handle, addr, size);
}

///@}

///@name Device memory-mapped I/O (MMIO)
///@{

Result svcCreateInterruptEvent(Handle* handle, u64 irqNum, u32 flag) {
  return __nx_svc_create_interrupt_event(handle, irqNum, flag);
}

Result svcQueryPhysicalAddress(PhysicalMemoryInfo *out, u64 virtaddr) {
    return __nx_svc_query_physical_address(out, virtaddr);
}

Result svcQueryMemoryMapping(u64* virtaddr, u64* out_size, u64 physaddr, u64 size) {
  return __nx_svc_query_memory_mapping(virtaddr, out_size, physaddr, size);
}

Result svcLegacyQueryIoMapping(u64* virtaddr, u64 physaddr, u64 size) {
  return __nx_svc_legacy_query_io_mapping(virtaddr, physaddr, size);
}

///@}

///@name I/O memory management unit (IOMMU)
///@{

Result svcCreateDeviceAddressSpace(Handle *handle, u64 dev_addr, u64 dev_size) {
  return __nx_svc_create_device_address_space(handle, dev_addr, dev_size);
}

Result svcAttachDeviceAddressSpace(u64 device, Handle handle) {
  return __nx_svc_attach_device_address_space(device, handle);
}

Result svcDetachDeviceAddressSpace(u64 device, Handle handle) {
  return __nx_svc_detach_device_address_space(device, handle);
}

Result svcMapDeviceAddressSpaceByForce(Handle handle, Handle proc_handle, u64 map_addr, u64 dev_size, u64 dev_addr, u32 option) {
  return __nx_svc_map_device_address_space_by_force(handle, proc_handle, map_addr, dev_size, dev_addr, option);
}

Result svcMapDeviceAddressSpaceAligned(Handle handle, Handle proc_handle, u64 map_addr, u64 dev_size, u64 dev_addr, u32 option) {
  return __nx_svc_map_device_address_space_aligned(handle, proc_handle, map_addr, dev_size, dev_addr, option);
}

Result svcMapDeviceAddressSpace(u64 *out_mapped_size, Handle handle, Handle proc_handle, u64 map_addr, u64 dev_size, u64 dev_addr, u32 perm) {
  return __nx_svc_map_device_address_space(out_mapped_size, handle, proc_handle, map_addr, dev_size, dev_addr, perm);
}

Result svcUnmapDeviceAddressSpace(Handle handle, Handle proc_handle, u64 map_addr, u64 map_size, u64 dev_addr) {
  return __nx_svc_unmap_device_address_space(handle, proc_handle, map_addr, map_size, dev_addr);
}

///@}

///@name Cache Management
///@{

Result svcInvalidateProcessDataCache(Handle process, uintptr_t address, size_t size) {
    return __nx_svc_invalidate_process_data_cache(process, address, size);
}

Result svcStoreProcessDataCache(Handle process, uintptr_t address, size_t size) {
    return __nx_svc_store_process_data_cache(process, address, size);
}

Result svcFlushProcessDataCache(Handle process, uintptr_t address, size_t size) {
    return __nx_svc_flush_process_data_cache(process, address, size);
}

///@}

///@name Debugging
///@{

Result svcDebugActiveProcess(Handle* debug, u64 processID) {
  return __nx_svc_debug_active_process(debug, processID);
}

Result svcBreakDebugProcess(Handle debug) {
  return __nx_svc_break_debug_process(debug);
}

Result svcTerminateDebugProcess(Handle debug) {
  return __nx_svc_terminate_debug_process(debug);
}

Result svcGetDebugEvent(void* event_out, Handle debug) {
  return __nx_svc_get_debug_event(event_out, debug);
}

Result svcContinueDebugEvent(Handle debug, u32 flags, u64* tid_list, u32 num_tids) {
  return __nx_svc_continue_debug_event(debug, flags, tid_list, num_tids);
}

Result svcLegacyContinueDebugEvent(Handle debug, u32 flags, u64 threadID) {
  return __nx_svc_legacy_continue_debug_event(debug, flags, threadID);
}

///@}

///@name Process and thread management
///@{

Result svcGetProcessList(s32 *num_out, u64 *pids_out, u32 max_pids) {
    return __nx_svc_get_process_list(num_out, pids_out, max_pids);
}

Result svcGetThreadList(s32 *num_out, u64 *tids_out, u32 max_tids, Handle debug) {
    return __nx_svc_get_thread_list(num_out, tids_out, max_tids, debug);
}

///@}

///@name Debugging
///@{

Result svcGetDebugThreadContext(ThreadContext* ctx, Handle debug, u64 threadID, u32 flags) {
    return __nx_svc_get_debug_thread_context(ctx, debug, threadID, flags);
}

Result svcSetDebugThreadContext(Handle debug, u64 threadID, const ThreadContext* ctx, u32 flags) {
    return __nx_svc_set_debug_thread_context(debug, threadID, ctx, flags);
}

Result svcQueryDebugProcessMemory(MemoryInfo* meminfo_ptr, u32* pageinfo, Handle debug, u64 addr) {
    return __nx_svc_query_debug_process_memory(meminfo_ptr, pageinfo, debug, addr);
}

Result svcReadDebugProcessMemory(void* buffer, Handle debug, u64 addr, u64 size) {
    return __nx_svc_read_debug_process_memory(buffer, debug, addr, size);
}

Result svcWriteDebugProcessMemory(Handle debug, const void* buffer, u64 addr, u64 size) {
    return __nx_svc_write_debug_process_memory(debug, buffer, addr, size);
}

Result svcSetHardwareBreakPoint(u32 which, u64 flags, u64 value) {
    return __nx_svc_set_hardware_break_point(which, flags, value);
}

Result svcGetDebugThreadParam(u64* out_64, u32* out_32, Handle debug, u64 threadID, DebugThreadParam param) {
    return __nx_svc_get_debug_thread_param(out_64, out_32, debug, threadID, param);
}

///@}

///@name Miscellaneous
///@{

Result svcGetSystemInfo(u64* out, u64 id0, Handle handle, u64 id1) {
    return __nx_svc_get_system_info(out, id0, handle, id1);
}

///@}

///@name Inter-process communication (IPC)
///@{

Result svcCreatePort(Handle* portServer, Handle *portClient, s32 max_sessions, bool is_light, const char* name) {
    return __nx_svc_create_port(portServer, portClient, max_sessions, is_light, name);
}

Result svcManageNamedPort(Handle* portServer, const char* name, s32 maxSessions) {
    return __nx_svc_manage_named_port(portServer, name, maxSessions);
}

Result svcConnectToPort(Handle* session, Handle port) {
    return __nx_svc_connect_to_port(session, port);
}

///@}

///@name Memory management
///@{

Result svcSetProcessMemoryPermission(Handle proc, u64 addr, u64 size, u32 perm) {
    return __nx_svc_set_process_memory_permission(proc, addr, size, perm);
}

Result svcMapProcessMemory(void* dst, Handle proc, u64 src, u64 size) {
    return __nx_svc_map_process_memory(dst, proc, src, size);
}

Result svcUnmapProcessMemory(void* dst, Handle proc, u64 src, u64 size) {
    return __nx_svc_unmap_process_memory(dst, proc, src, size);
}

Result svcQueryProcessMemory(MemoryInfo* meminfo_ptr, u32 *pageinfo, Handle proc, u64 addr) {
    return __nx_svc_query_process_memory(meminfo_ptr, pageinfo, proc, addr);
}

Result svcMapProcessCodeMemory(Handle proc, u64 dst, u64 src, u64 size) {
    return __nx_svc_map_process_code_memory(proc, dst, src, size);
}

Result svcUnmapProcessCodeMemory(Handle proc, u64 dst, u64 src, u64 size) {
    return __nx_svc_unmap_process_code_memory(proc, dst, src, size);
}

///@}

///@name Process and thread management
///@{

Result svcCreateProcess(Handle* out, const void* proc_info, const u32* caps, u64 cap_num) {
    return __nx_svc_create_process(out, proc_info, caps, cap_num);
}

Result svcStartProcess(Handle proc, s32 main_prio, s32 default_cpu, u32 stack_size) {
    return __nx_svc_start_process(proc, main_prio, default_cpu, stack_size);
}

Result svcTerminateProcess(Handle proc) {
    return __nx_svc_terminate_process(proc);
}

Result svcGetProcessInfo(s64 *out, Handle proc, ProcessInfoType which) {
    return __nx_svc_get_process_info(out, proc, which);
}

///@}

///@name Resource Limit Management
///@{

Result svcCreateResourceLimit(Handle* out) {
    return __nx_svc_create_resource_limit(out);
}

Result svcSetResourceLimitLimitValue(Handle reslimit, LimitableResource which, u64 value) {
    return __nx_svc_set_resource_limit_limit_value(reslimit, which, value);
}

///@}

///@name Secure Monitor
///@{

void svcCallSecureMonitor(SecmonArgs* regs) {
    __nx_svc_call_secure_monitor(regs);
}

///@}

///@name Memory management
///@{

Result svcMapInsecurePhysicalMemory(void *address, u64 size) {
    return __nx_svc_map_insecure_physical_memory(address, size);
}

Result svcUnmapInsecurePhysicalMemory(void *address, u64 size) {
    return __nx_svc_unmap_insecure_physical_memory(address, size);
}

///@}
