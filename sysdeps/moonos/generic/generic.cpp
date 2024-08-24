#include <mlibc/all-sysdeps.hpp>
// #include <mlibc/debug.hpp>

namespace mlibc {
void syscall(uint64_t selector, uint64_t arg0, uint64_t arg1, uint64_t arg2,
             uint64_t arg3, uint64_t arg4, uint64_t arg5) {
  //   asm("mov %rcx, %r10\n\t"
  //       "syscall\n\t"
  //       "ret");
}
void sys_libc_log(const char *message) {
  syscall(1, 1, (uint64_t)message, 50, 0, 0, 0);
}

void sys_libc_panic() {
  sys_libc_log("\e[31mmlibc: panic!\e[0m");
  //   mlibc::infoLogger() << "\e[31mmlibc: panic!" << frg::endlog;
  //   asm volatile("syscall" : : "a"(12), "D"(1) : "rcx", "r11", "rdx");
}

int sys_tcb_set(void *pointer) { return -1; }

int sys_anon_allocate(size_t size, void **pointer) { return -1; }

int sys_anon_free(void *pointer, size_t size) { return -1; }

int sys_open(const char *path, int flags, mode_t mode, int *fd) { return -1; }

int sys_close(int fd) { return -1; }

int sys_read(int fd, void *buf, size_t count, ssize_t *bytes_read) {
  return -1;
}

#ifndef MLIBC_BUILDING_RTLD
int sys_write(int fd, const void *buf, size_t count, ssize_t *bytes_written) {
  return -1;
}
#endif

int sys_seek(int fd, off_t offset, int whence, off_t *new_offset) { return -1; }

int sys_vm_map(void *hint, size_t size, int prot, int flags, int fd,
               off_t offset, void **window) {
  return -1;
}

int sys_vm_unmap(void *pointer, size_t size) {
  return sys_anon_free(pointer, size);
}

int sys_futex_wait(int *pointer, int expected, const struct timespec *time) {
  return -1;
}

int sys_futex_wake(int *pointer) { return -1; }
int sys_clock_get(int clock, time_t *secs, long *nanos) { return -1; }
void sys_exit(int status) { return; }

} // namespace mlibc
