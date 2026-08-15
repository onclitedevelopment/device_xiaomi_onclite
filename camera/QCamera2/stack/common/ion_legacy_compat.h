/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Pre-4.12 ION ABI, from the kernel's unexported ion_legacy.h.
 * Do not include <linux/ion.h>: its ion_allocation_data is the new ABI.
 */

#ifndef __ION_LEGACY_COMPAT_H__
#define __ION_LEGACY_COMPAT_H__

#include <stddef.h>
#include <linux/types.h>
#include <linux/ioctl.h>
#include <linux/msm_ion.h>

#ifndef ION_IOC_MAGIC
#define ION_IOC_MAGIC		'I'
#endif

/* 4.9 had both; 4.19 dropped the alias and keeps CACHED in <linux/ion.h>. */
#ifndef ION_FLAG_CACHED
#define ION_FLAG_CACHED		1
#endif

#ifndef ION_IOMMU_HEAP_ID
#define ION_IOMMU_HEAP_ID	ION_SYSTEM_HEAP_ID
#endif

typedef int ion_user_handle_t;

struct ion_allocation_data {
	size_t len;
	size_t align;
	unsigned int heap_id_mask;
	unsigned int flags;
	ion_user_handle_t handle;
};

struct ion_fd_data {
	ion_user_handle_t handle;
	int fd;
};

struct ion_handle_data {
	ion_user_handle_t handle;
};

struct ion_custom_data {
	unsigned int cmd;
	unsigned long arg;
};

struct ion_flush_data {
	ion_user_handle_t handle;
	int fd;
	void *vaddr;
	unsigned int offset;
	unsigned int length;
};

#define ION_IOC_ALLOC		_IOWR(ION_IOC_MAGIC, 0, \
				      struct ion_allocation_data)
#define ION_IOC_FREE		_IOWR(ION_IOC_MAGIC, 1, struct ion_handle_data)
#define ION_IOC_MAP		_IOWR(ION_IOC_MAGIC, 2, struct ion_fd_data)
#define ION_IOC_SHARE		_IOWR(ION_IOC_MAGIC, 4, struct ion_fd_data)
#define ION_IOC_IMPORT		_IOWR(ION_IOC_MAGIC, 5, struct ion_fd_data)
#define ION_IOC_CUSTOM		_IOWR(ION_IOC_MAGIC, 6, struct ion_custom_data)

#define ION_IOC_CLEAN_CACHES		_IOWR(ION_IOC_MSM_MAGIC, 0, \
					      struct ion_flush_data)
#define ION_IOC_INV_CACHES		_IOWR(ION_IOC_MSM_MAGIC, 1, \
					      struct ion_flush_data)
#define ION_IOC_CLEAN_INV_CACHES	_IOWR(ION_IOC_MSM_MAGIC, 2, \
					      struct ion_flush_data)

#endif /* __ION_LEGACY_COMPAT_H__ */
