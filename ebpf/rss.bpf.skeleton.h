/* SPDX-License-Identifier: (LGPL-2.1 OR BSD-2-Clause) */

/* THIS FILE IS AUTOGENERATED! */
#ifndef __RSS_BPF_SKEL_H__
#define __RSS_BPF_SKEL_H__

#include <stdlib.h>
#include <bpf/libbpf.h>

struct rss_bpf {
	struct bpf_object_skeleton *skeleton;
	struct bpf_object *obj;
	struct {
		struct bpf_map *tap_rss_map_configurations;
		struct bpf_map *tap_rss_map_indirection_table;
		struct bpf_map *tap_rss_map_toeplitz_key;
	} maps;
	struct {
		struct bpf_program *tun_rss_steering_prog;
	} progs;
	struct {
		struct bpf_link *tun_rss_steering_prog;
	} links;
};

static void
rss_bpf__destroy(struct rss_bpf *obj)
{
	if (!obj)
		return;
	if (obj->skeleton)
		bpf_object__destroy_skeleton(obj->skeleton);
	free(obj);
}

static inline int
rss_bpf__create_skeleton(struct rss_bpf *obj);

static inline struct rss_bpf *
rss_bpf__open_opts(const struct bpf_object_open_opts *opts)
{
	struct rss_bpf *obj;

	obj = (struct rss_bpf *)calloc(1, sizeof(*obj));
	if (!obj)
		return NULL;
	if (rss_bpf__create_skeleton(obj))
		goto err;
	if (bpf_object__open_skeleton(obj->skeleton, opts))
		goto err;

	return obj;
err:
	rss_bpf__destroy(obj);
	return NULL;
}

static inline struct rss_bpf *
rss_bpf__open(void)
{
	return rss_bpf__open_opts(NULL);
}

static inline int
rss_bpf__load(struct rss_bpf *obj)
{
	return bpf_object__load_skeleton(obj->skeleton);
}

static inline struct rss_bpf *
rss_bpf__open_and_load(void)
{
	struct rss_bpf *obj;

	obj = rss_bpf__open();
	if (!obj)
		return NULL;
	if (rss_bpf__load(obj)) {
		rss_bpf__destroy(obj);
		return NULL;
	}
	return obj;
}

static inline int
rss_bpf__attach(struct rss_bpf *obj)
{
	return bpf_object__attach_skeleton(obj->skeleton);
}

static inline void
rss_bpf__detach(struct rss_bpf *obj)
{
	return bpf_object__detach_skeleton(obj->skeleton);
}

static inline int
rss_bpf__create_skeleton(struct rss_bpf *obj)
{
	struct bpf_object_skeleton *s;

	s = (struct bpf_object_skeleton *)calloc(1, sizeof(*s));
	if (!s)
		return -1;
	obj->skeleton = s;

	s->sz = sizeof(*s);
	s->name = "rss_bpf";
	s->obj = &obj->obj;

	/* maps */
	s->map_cnt = 3;
	s->map_skel_sz = sizeof(*s->maps);
	s->maps = (struct bpf_map_skeleton *)calloc(s->map_cnt, s->map_skel_sz);
	if (!s->maps)
		goto err;

	s->maps[0].name = "tap_rss_map_configurations";
	s->maps[0].map = &obj->maps.tap_rss_map_configurations;

	s->maps[1].name = "tap_rss_map_indirection_table";
	s->maps[1].map = &obj->maps.tap_rss_map_indirection_table;

	s->maps[2].name = "tap_rss_map_toeplitz_key";
	s->maps[2].map = &obj->maps.tap_rss_map_toeplitz_key;

	/* programs */
	s->prog_cnt = 1;
	s->prog_skel_sz = sizeof(*s->progs);
	s->progs = (struct bpf_prog_skeleton *)calloc(s->prog_cnt, s->prog_skel_sz);
	if (!s->progs)
		goto err;

	s->progs[0].name = "tun_rss_steering_prog";
	s->progs[0].prog = &obj->progs.tun_rss_steering_prog;
	s->progs[0].link = &obj->links.tun_rss_steering_prog;

	s->data_sz = 7088;
	s->data = (void *)"\
\x7f\x45\x4c\x46\x02\x01\x01\0\0\0\0\0\0\0\0\0\x01\0\xf7\0\x01\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\x30\x19\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\0\x40\0\x0a\0\
\x01\0\x7b\x1a\x38\xff\0\0\0\0\xb7\x01\0\0\0\0\0\0\x63\x1a\x4c\xff\0\0\0\0\xbf\
\xa6\0\0\0\0\0\0\x07\x06\0\0\x4c\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\xbf\x62\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x07\0\0\0\0\0\0\x18\x01\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\xbf\x62\0\0\0\0\0\0\x85\0\0\0\x01\0\0\0\xbf\x08\0\0\0\0\0\
\0\x18\0\0\0\xff\xff\xff\xff\0\0\0\0\0\0\0\0\x15\x07\x0f\x02\0\0\0\0\xbf\x89\0\
\0\0\0\0\0\x15\x09\x0d\x02\0\0\0\0\x71\x71\0\0\0\0\0\0\x55\x01\x01\0\0\0\0\0\
\x05\0\x09\x02\0\0\0\0\xb7\x01\0\0\0\0\0\0\x63\x1a\xc0\xff\0\0\0\0\x7b\x1a\xb8\
\xff\0\0\0\0\x7b\x1a\xb0\xff\0\0\0\0\x7b\x1a\xa8\xff\0\0\0\0\x7b\x1a\xa0\xff\0\
\0\0\0\x63\x1a\x98\xff\0\0\0\0\x7b\x1a\x90\xff\0\0\0\0\x7b\x1a\x88\xff\0\0\0\0\
\x7b\x1a\x80\xff\0\0\0\0\x7b\x1a\x78\xff\0\0\0\0\x7b\x1a\x70\xff\0\0\0\0\x7b\
\x1a\x68\xff\0\0\0\0\x7b\x1a\x60\xff\0\0\0\0\x7b\x1a\x58\xff\0\0\0\0\x7b\x1a\
\x50\xff\0\0\0\0\x79\xa6\x38\xff\0\0\0\0\x15\x06\x85\0\0\0\0\0\x6b\x1a\xd0\xff\
\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xd0\xff\xff\xff\xbf\x61\0\0\0\0\0\0\
\xb7\x02\0\0\x0c\0\0\0\xb7\x04\0\0\x02\0\0\0\xb7\x05\0\0\0\0\0\0\x85\0\0\0\x44\
\0\0\0\xb7\x02\0\0\x10\0\0\0\x69\xa1\xd0\xff\0\0\0\0\xbf\x13\0\0\0\0\0\0\xdc\
\x03\0\0\x10\0\0\0\x15\x03\x02\0\0\x81\0\0\x55\x03\x08\0\xa8\x88\0\0\xb7\x02\0\
\0\x14\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xd0\xff\xff\xff\xbf\x61\0\0\0\0\0\
\0\xb7\x04\0\0\x02\0\0\0\xb7\x05\0\0\0\0\0\0\x85\0\0\0\x44\0\0\0\x69\xa1\xd0\
\xff\0\0\0\0\xdc\x01\0\0\x10\0\0\0\x15\x01\x26\0\xdd\x86\0\0\x55\x01\x6c\0\0\
\x08\0\0\xb7\x01\0\0\x01\0\0\0\x73\x1a\x50\xff\0\0\0\0\xb7\x01\0\0\0\0\0\0\x63\
\x1a\xe0\xff\0\0\0\0\x7b\x1a\xd8\xff\0\0\0\0\x7b\x1a\xd0\xff\0\0\0\0\xbf\xa3\0\
\0\0\0\0\0\x07\x03\0\0\xd0\xff\xff\xff\xbf\x61\0\0\0\0\0\0\xb7\x02\0\0\0\0\0\0\
\xb7\x04\0\0\x14\0\0\0\xb7\x05\0\0\x01\0\0\0\x85\0\0\0\x44\0\0\0\x61\xa1\xdc\
\xff\0\0\0\0\x63\x1a\x5c\xff\0\0\0\0\x61\xa1\xe0\xff\0\0\0\0\x63\x1a\x60\xff\0\
\0\0\0\x71\xa6\xd9\xff\0\0\0\0\x71\xa1\xd0\xff\0\0\0\0\x67\x01\0\0\x02\0\0\0\
\x57\x01\0\0\x3c\0\0\0\x7b\x1a\x40\xff\0\0\0\0\x57\x06\0\0\xff\0\0\0\x15\x06\
\x45\0\x11\0\0\0\x79\xa1\x38\xff\0\0\0\0\x55\x06\x52\0\x06\0\0\0\xb7\x02\0\0\
\x01\0\0\0\x73\x2a\x53\xff\0\0\0\0\xb7\x02\0\0\0\0\0\0\x63\x2a\xe0\xff\0\0\0\0\
\x7b\x2a\xd8\xff\0\0\0\0\x7b\x2a\xd0\xff\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\
\0\xd0\xff\xff\xff\x79\xa2\x40\xff\0\0\0\0\xb7\x04\0\0\x14\0\0\0\x05\0\x41\0\0\
\0\0\0\x7b\x7a\x10\xff\0\0\0\0\xb7\x07\0\0\x01\0\0\0\x73\x7a\x51\xff\0\0\0\0\
\xb7\x01\0\0\0\0\0\0\x7b\x1a\xf0\xff\0\0\0\0\x7b\x1a\xe8\xff\0\0\0\0\x7b\x1a\
\xe0\xff\0\0\0\0\x7b\x1a\xd8\xff\0\0\0\0\x7b\x1a\xd0\xff\0\0\0\0\xbf\xa3\0\0\0\
\0\0\0\x07\x03\0\0\xd0\xff\xff\xff\xb7\x01\0\0\x28\0\0\0\x7b\x1a\x40\xff\0\0\0\
\0\xbf\x61\0\0\0\0\0\0\xb7\x02\0\0\0\0\0\0\xb7\x04\0\0\x28\0\0\0\xb7\x05\0\0\
\x01\0\0\0\x85\0\0\0\x44\0\0\0\x79\xa1\xd8\xff\0\0\0\0\x63\x1a\x5c\xff\0\0\0\0\
\x77\x01\0\0\x20\0\0\0\x63\x1a\x60\xff\0\0\0\0\x79\xa1\xe0\xff\0\0\0\0\x63\x1a\
\x64\xff\0\0\0\0\x77\x01\0\0\x20\0\0\0\x63\x1a\x68\xff\0\0\0\0\x79\xa1\xe8\xff\
\0\0\0\0\x63\x1a\x6c\xff\0\0\0\0\x77\x01\0\0\x20\0\0\0\x63\x1a\x70\xff\0\0\0\0\
\x79\xa1\xf0\xff\0\0\0\0\x63\x1a\x74\xff\0\0\0\0\x77\x01\0\0\x20\0\0\0\x63\x1a\
\x78\xff\0\0\0\0\x71\xa6\xd6\xff\0\0\0\0\x25\x06\xb1\0\x3c\0\0\0\x6f\x67\0\0\0\
\0\0\0\x18\x01\0\0\x01\0\0\0\0\0\0\0\0\x18\0\x1c\x5f\x17\0\0\0\0\0\0\x55\x07\
\x01\0\0\0\0\0\x05\0\xab\0\0\0\0\0\xb7\x01\0\0\0\0\0\0\x6b\x1a\xfe\xff\0\0\0\0\
\xb7\x01\0\0\x28\0\0\0\x7b\x1a\x40\xff\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\
\x8c\xff\xff\xff\x7b\x1a\x20\xff\0\0\0\0\xbf\xa1\0\0\0\0\0\0\x07\x01\0\0\x54\
\xff\xff\xff\x7b\x1a\x18\xff\0\0\0\0\xb7\x07\0\0\0\0\0\0\x7b\x8a\x30\xff\0\0\0\
\0\x7b\x9a\x28\xff\0\0\0\0\x05\0\xdf\0\0\0\0\0\xb7\x01\0\0\x01\0\0\0\x73\x1a\
\x52\xff\0\0\0\0\xb7\x01\0\0\0\0\0\0\x7b\x1a\xd0\xff\0\0\0\0\xbf\xa3\0\0\0\0\0\
\0\x07\x03\0\0\xd0\xff\xff\xff\x79\xa1\x38\xff\0\0\0\0\x79\xa2\x40\xff\0\0\0\0\
\xb7\x04\0\0\x08\0\0\0\xb7\x05\0\0\x01\0\0\0\x85\0\0\0\x44\0\0\0\x69\xa1\xd0\
\xff\0\0\0\0\x6b\x1a\x56\xff\0\0\0\0\x69\xa1\xd2\xff\0\0\0\0\x6b\x1a\x58\xff\0\
\0\0\0\x71\xa1\x50\xff\0\0\0\0\x15\x01\x0f\0\0\0\0\0\x61\x71\x04\0\0\0\0\0\x71\
\xa2\x53\xff\0\0\0\0\x15\x02\x41\0\0\0\0\0\xbf\x12\0\0\0\0\0\0\x57\x02\0\0\x02\
\0\0\0\x15\x02\x3e\0\0\0\0\0\x61\xa1\x5c\xff\0\0\0\0\x63\x1a\xa0\xff\0\0\0\0\
\x61\xa1\x60\xff\0\0\0\0\x63\x1a\xa4\xff\0\0\0\0\x69\xa1\x56\xff\0\0\0\0\x6b\
\x1a\xa8\xff\0\0\0\0\x69\xa1\x58\xff\0\0\0\0\x6b\x1a\xaa\xff\0\0\0\0\x05\0\xf4\
\0\0\0\0\0\x71\xa1\x51\xff\0\0\0\0\x15\x01\x5f\x01\0\0\0\0\x61\x71\x04\0\0\0\0\
\0\x71\xa2\x53\xff\0\0\0\0\x15\x02\x3d\0\0\0\0\0\xbf\x12\0\0\0\0\0\0\x57\x02\0\
\0\x10\0\0\0\x15\x02\x3a\0\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\x5c\xff\xff\
\xff\x71\xa4\x54\xff\0\0\0\0\xbf\x23\0\0\0\0\0\0\x15\x04\x02\0\0\0\0\0\xbf\xa3\
\0\0\0\0\0\0\x07\x03\0\0\x7c\xff\xff\xff\x67\x01\0\0\x38\0\0\0\xc7\x01\0\0\x38\
\0\0\0\x65\x01\x01\0\xff\xff\xff\xff\xbf\x32\0\0\0\0\0\0\xbf\xa3\0\0\0\0\0\0\
\x07\x03\0\0\x6c\xff\xff\xff\x71\xa5\x55\xff\0\0\0\0\xbf\x34\0\0\0\0\0\0\x15\
\x05\x02\0\0\0\0\0\xbf\xa4\0\0\0\0\0\0\x07\x04\0\0\x8c\xff\xff\xff\x65\x01\x01\
\0\xff\xff\xff\xff\xbf\x43\0\0\0\0\0\0\x61\x21\x04\0\0\0\0\0\x67\x01\0\0\x20\0\
\0\0\x61\x24\0\0\0\0\0\0\x4f\x41\0\0\0\0\0\0\x7b\x1a\xa0\xff\0\0\0\0\x61\x21\
\x08\0\0\0\0\0\x61\x22\x0c\0\0\0\0\0\x67\x02\0\0\x20\0\0\0\x4f\x12\0\0\0\0\0\0\
\x7b\x2a\xa8\xff\0\0\0\0\x61\x31\0\0\0\0\0\0\x61\x32\x04\0\0\0\0\0\x61\x34\x08\
\0\0\0\0\0\x61\x33\x0c\0\0\0\0\0\x69\xa5\x58\xff\0\0\0\0\x6b\x5a\xc2\xff\0\0\0\
\0\x69\xa5\x56\xff\0\0\0\0\x6b\x5a\xc0\xff\0\0\0\0\x67\x03\0\0\x20\0\0\0\x4f\
\x43\0\0\0\0\0\0\x7b\x3a\xb8\xff\0\0\0\0\x67\x02\0\0\x20\0\0\0\x4f\x12\0\0\0\0\
\0\0\x7b\x2a\xb0\xff\0\0\0\0\x05\0\xbf\0\0\0\0\0\x71\xa2\x52\xff\0\0\0\0\x15\
\x02\x04\0\0\0\0\0\xbf\x12\0\0\0\0\0\0\x57\x02\0\0\x04\0\0\0\x15\x02\x01\0\0\0\
\0\0\x05\0\xbc\xff\0\0\0\0\x57\x01\0\0\x01\0\0\0\x15\x01\x24\x01\0\0\0\0\x61\
\xa1\x5c\xff\0\0\0\0\x63\x1a\xa0\xff\0\0\0\0\x61\xa1\x60\xff\0\0\0\0\x63\x1a\
\xa4\xff\0\0\0\0\x05\0\xb2\0\0\0\0\0\x71\xa2\x52\xff\0\0\0\0\x15\x02\x16\0\0\0\
\0\0\xbf\x12\0\0\0\0\0\0\x57\x02\0\0\x20\0\0\0\x15\x02\x13\0\0\0\0\0\xbf\xa2\0\
\0\0\0\0\0\x07\x02\0\0\x5c\xff\xff\xff\x71\xa4\x54\xff\0\0\0\0\xbf\x23\0\0\0\0\
\0\0\x15\x04\x02\0\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\x7c\xff\xff\xff\x57\
\x01\0\0\0\x01\0\0\x15\x01\x01\0\0\0\0\0\xbf\x32\0\0\0\0\0\0\xbf\xa3\0\0\0\0\0\
\0\x07\x03\0\0\x6c\xff\xff\xff\x71\xa5\x55\xff\0\0\0\0\xbf\x34\0\0\0\0\0\0\x15\
\x05\x02\0\0\0\0\0\xbf\xa4\0\0\0\0\0\0\x07\x04\0\0\x8c\xff\xff\xff\x15\x01\xc3\
\xff\0\0\0\0\x05\0\xc1\xff\0\0\0\0\xbf\x12\0\0\0\0\0\0\x57\x02\0\0\x08\0\0\0\
\x15\x02\x04\x01\0\0\0\0\xbf\xa2\0\0\0\0\0\0\x07\x02\0\0\x5c\xff\xff\xff\x71\
\xa4\x54\xff\0\0\0\0\xbf\x23\0\0\0\0\0\0\x15\x04\x02\0\0\0\0\0\xbf\xa3\0\0\0\0\
\0\0\x07\x03\0\0\x7c\xff\xff\xff\x57\x01\0\0\x40\0\0\0\x15\x01\x01\0\0\0\0\0\
\xbf\x32\0\0\0\0\0\0\x61\x23\x04\0\0\0\0\0\x67\x03\0\0\x20\0\0\0\x61\x24\0\0\0\
\0\0\0\x4f\x43\0\0\0\0\0\0\x7b\x3a\xa0\xff\0\0\0\0\x61\x23\x08\0\0\0\0\0\x61\
\x22\x0c\0\0\0\0\0\x67\x02\0\0\x20\0\0\0\x4f\x32\0\0\0\0\0\0\x7b\x2a\xa8\xff\0\
\0\0\0\x15\x01\x78\0\0\0\0\0\x71\xa1\x55\xff\0\0\0\0\x15\x01\x76\0\0\0\0\0\x61\
\xa1\x98\xff\0\0\0\0\x67\x01\0\0\x20\0\0\0\x61\xa2\x94\xff\0\0\0\0\x4f\x21\0\0\
\0\0\0\0\x7b\x1a\xb8\xff\0\0\0\0\x61\xa1\x90\xff\0\0\0\0\x67\x01\0\0\x20\0\0\0\
\x61\xa2\x8c\xff\0\0\0\0\x05\0\x75\0\0\0\0\0\x15\x06\x54\xff\x87\0\0\0\x05\0\
\x3e\0\0\0\0\0\x0f\x96\0\0\0\0\0\0\xbf\x62\0\0\0\0\0\0\x07\x02\0\0\x01\0\0\0\
\x71\xa3\xff\xff\0\0\0\0\x67\x03\0\0\x03\0\0\0\x3d\x32\x22\0\0\0\0\0\x55\x01\
\x0c\0\xc9\0\0\0\x79\xa1\x40\xff\0\0\0\0\x0f\x16\0\0\0\0\0\0\x07\x06\0\0\x02\0\
\0\0\x79\xa1\x38\xff\0\0\0\0\xbf\x62\0\0\0\0\0\0\x79\xa3\x18\xff\0\0\0\0\xb7\
\x04\0\0\x01\0\0\0\xb7\x05\0\0\x01\0\0\0\x85\0\0\0\x44\0\0\0\xb7\x01\0\0\x01\0\
\0\0\x73\x1a\x54\xff\0\0\0\0\x05\0\x15\0\0\0\0\0\x07\x08\0\0\xff\xff\xff\xff\
\xbf\x81\0\0\0\0\0\0\x67\x01\0\0\x20\0\0\0\x77\x01\0\0\x20\0\0\0\xbf\x69\0\0\0\
\0\0\0\x15\x01\x0f\0\0\0\0\0\xbf\x92\0\0\0\0\0\0\x79\xa1\x40\xff\0\0\0\0\x0f\
\x12\0\0\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xf8\xff\xff\xff\xb7\x06\0\0\
\x01\0\0\0\x79\xa1\x38\xff\0\0\0\0\xb7\x04\0\0\x02\0\0\0\xb7\x05\0\0\x01\0\0\0\
\x85\0\0\0\x44\0\0\0\x71\xa1\xf8\xff\0\0\0\0\x15\x01\xdb\xff\0\0\0\0\x71\xa6\
\xf9\xff\0\0\0\0\x07\x06\0\0\x02\0\0\0\x05\0\xd8\xff\0\0\0\0\x79\xa8\x30\xff\0\
\0\0\0\x79\xa9\x28\xff\0\0\0\0\x71\xa1\xff\xff\0\0\0\0\x67\x01\0\0\x03\0\0\0\
\x79\xa2\x40\xff\0\0\0\0\x0f\x12\0\0\0\0\0\0\x07\x02\0\0\x08\0\0\0\x7b\x2a\x40\
\xff\0\0\0\0\x71\xa6\xfe\xff\0\0\0\0\x25\x06\x37\0\x3c\0\0\0\xb7\x01\0\0\x01\0\
\0\0\x6f\x61\0\0\0\0\0\0\x18\x02\0\0\x01\0\0\0\0\0\0\0\0\x18\0\x1c\x5f\x21\0\0\
\0\0\0\0\x55\x01\x01\0\0\0\0\0\x05\0\x30\0\0\0\0\0\x07\x07\0\0\x01\0\0\0\xbf\
\x71\0\0\0\0\0\0\x67\x01\0\0\x20\0\0\0\x77\x01\0\0\x20\0\0\0\x55\x01\x02\0\x0b\
\0\0\0\x79\xa7\x10\xff\0\0\0\0\x05\0\xda\xfe\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\
\x03\0\0\xfe\xff\xff\xff\x79\xa1\x38\xff\0\0\0\0\x79\xa2\x40\xff\0\0\0\0\xb7\
\x04\0\0\x02\0\0\0\xb7\x05\0\0\x01\0\0\0\x85\0\0\0\x44\0\0\0\xbf\x61\0\0\0\0\0\
\0\x15\x01\x1b\0\x3c\0\0\0\x55\x01\xe0\xff\x2b\0\0\0\xb7\x01\0\0\0\0\0\0\x63\
\x1a\xf8\xff\0\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xf8\xff\xff\xff\x79\xa6\
\x38\xff\0\0\0\0\xbf\x61\0\0\0\0\0\0\x79\xa2\x40\xff\0\0\0\0\xb7\x04\0\0\x04\0\
\0\0\xb7\x05\0\0\x01\0\0\0\x85\0\0\0\x44\0\0\0\x71\xa1\xfa\xff\0\0\0\0\x55\x01\
\xd4\xff\x02\0\0\0\x71\xa1\xf9\xff\0\0\0\0\x55\x01\xd2\xff\x02\0\0\0\x71\xa1\
\xfb\xff\0\0\0\0\x55\x01\xd0\xff\x01\0\0\0\x79\xa2\x40\xff\0\0\0\0\x07\x02\0\0\
\x08\0\0\0\xbf\x61\0\0\0\0\0\0\x79\xa3\x20\xff\0\0\0\0\xb7\x04\0\0\x10\0\0\0\
\xb7\x05\0\0\x01\0\0\0\x85\0\0\0\x44\0\0\0\xb7\x01\0\0\x01\0\0\0\x73\x1a\x55\
\xff\0\0\0\0\x05\0\xc6\xff\0\0\0\0\xb7\x01\0\0\0\0\0\0\x6b\x1a\xf8\xff\0\0\0\0\
\xb7\x09\0\0\x02\0\0\0\xb7\x08\0\0\x1e\0\0\0\x05\0\xb0\xff\0\0\0\0\x15\x06\xcf\
\xff\x87\0\0\0\x05\0\xd3\xff\0\0\0\0\x61\xa1\x78\xff\0\0\0\0\x67\x01\0\0\x20\0\
\0\0\x61\xa2\x74\xff\0\0\0\0\x4f\x21\0\0\0\0\0\0\x7b\x1a\xb8\xff\0\0\0\0\x61\
\xa1\x70\xff\0\0\0\0\x67\x01\0\0\x20\0\0\0\x61\xa2\x6c\xff\0\0\0\0\x4f\x21\0\0\
\0\0\0\0\x7b\x1a\xb0\xff\0\0\0\0\xb7\x01\0\0\0\0\0\0\x07\x08\0\0\x04\0\0\0\x61\
\x92\0\0\0\0\0\0\xb7\x05\0\0\0\0\0\0\x05\0\x4e\0\0\0\0\0\xaf\x53\0\0\0\0\0\0\
\xbf\x85\0\0\0\0\0\0\x0f\x15\0\0\0\0\0\0\x71\x55\0\0\0\0\0\0\x67\x02\0\0\x01\0\
\0\0\xbf\x50\0\0\0\0\0\0\x77\0\0\0\x07\0\0\0\x4f\x02\0\0\0\0\0\0\xbf\x40\0\0\0\
\0\0\0\x67\0\0\0\x39\0\0\0\xc7\0\0\0\x3f\0\0\0\x5f\x20\0\0\0\0\0\0\xaf\x03\0\0\
\0\0\0\0\xbf\x50\0\0\0\0\0\0\x77\0\0\0\x06\0\0\0\x57\0\0\0\x01\0\0\0\x67\x02\0\
\0\x01\0\0\0\x4f\x02\0\0\0\0\0\0\xbf\x40\0\0\0\0\0\0\x67\0\0\0\x3a\0\0\0\xc7\0\
\0\0\x3f\0\0\0\x5f\x20\0\0\0\0\0\0\xaf\x03\0\0\0\0\0\0\x67\x02\0\0\x01\0\0\0\
\xbf\x50\0\0\0\0\0\0\x77\0\0\0\x05\0\0\0\x57\0\0\0\x01\0\0\0\x4f\x02\0\0\0\0\0\
\0\xbf\x40\0\0\0\0\0\0\x67\0\0\0\x3b\0\0\0\xc7\0\0\0\x3f\0\0\0\x5f\x20\0\0\0\0\
\0\0\xaf\x03\0\0\0\0\0\0\x67\x02\0\0\x01\0\0\0\xbf\x50\0\0\0\0\0\0\x77\0\0\0\
\x04\0\0\0\x57\0\0\0\x01\0\0\0\x4f\x02\0\0\0\0\0\0\xbf\x40\0\0\0\0\0\0\x67\0\0\
\0\x3c\0\0\0\xc7\0\0\0\x3f\0\0\0\x5f\x20\0\0\0\0\0\0\xaf\x03\0\0\0\0\0\0\xbf\
\x50\0\0\0\0\0\0\x77\0\0\0\x03\0\0\0\x57\0\0\0\x01\0\0\0\x67\x02\0\0\x01\0\0\0\
\x4f\x02\0\0\0\0\0\0\xbf\x40\0\0\0\0\0\0\x67\0\0\0\x3d\0\0\0\xc7\0\0\0\x3f\0\0\
\0\x5f\x20\0\0\0\0\0\0\xaf\x03\0\0\0\0\0\0\xbf\x50\0\0\0\0\0\0\x77\0\0\0\x02\0\
\0\0\x57\0\0\0\x01\0\0\0\x67\x02\0\0\x01\0\0\0\x4f\x02\0\0\0\0\0\0\xbf\x40\0\0\
\0\0\0\0\x67\0\0\0\x3e\0\0\0\xc7\0\0\0\x3f\0\0\0\x5f\x20\0\0\0\0\0\0\xaf\x03\0\
\0\0\0\0\0\xbf\x50\0\0\0\0\0\0\x77\0\0\0\x01\0\0\0\x57\0\0\0\x01\0\0\0\x67\x02\
\0\0\x01\0\0\0\x4f\x02\0\0\0\0\0\0\x57\x04\0\0\x01\0\0\0\x87\x04\0\0\0\0\0\0\
\x5f\x24\0\0\0\0\0\0\xaf\x43\0\0\0\0\0\0\x57\x05\0\0\x01\0\0\0\x67\x02\0\0\x01\
\0\0\0\x4f\x52\0\0\0\0\0\0\x07\x01\0\0\x01\0\0\0\xbf\x35\0\0\0\0\0\0\x15\x01\
\x0b\0\x24\0\0\0\xbf\xa3\0\0\0\0\0\0\x07\x03\0\0\xa0\xff\xff\xff\x0f\x13\0\0\0\
\0\0\0\x71\x34\0\0\0\0\0\0\xbf\x40\0\0\0\0\0\0\x67\0\0\0\x38\0\0\0\xc7\0\0\0\
\x38\0\0\0\xb7\x03\0\0\0\0\0\0\x65\0\xa9\xff\xff\xff\xff\xff\xbf\x23\0\0\0\0\0\
\0\x05\0\xa7\xff\0\0\0\0\xbf\x31\0\0\0\0\0\0\x67\x01\0\0\x20\0\0\0\x77\x01\0\0\
\x20\0\0\0\x15\x01\x0b\0\0\0\0\0\x69\x72\x08\0\0\0\0\0\x3f\x21\0\0\0\0\0\0\x2f\
\x21\0\0\0\0\0\0\x1f\x13\0\0\0\0\0\0\x63\x3a\x50\xff\0\0\0\0\xbf\xa2\0\0\0\0\0\
\0\x07\x02\0\0\x50\xff\xff\xff\x18\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x85\0\0\0\
\x01\0\0\0\x55\0\x02\0\0\0\0\0\x69\x70\x0a\0\0\0\0\0\x95\0\0\0\0\0\0\0\x69\0\0\
\0\0\0\0\0\x05\0\xfd\xff\0\0\0\0\x02\0\0\0\x04\0\0\0\x0c\0\0\0\x01\0\0\0\0\0\0\
\0\x02\0\0\0\x04\0\0\0\x28\0\0\0\x01\0\0\0\0\0\0\0\x02\0\0\0\x04\0\0\0\x02\0\0\
\0\x80\0\0\0\0\0\0\0\x47\x50\x4c\x20\x76\x32\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x01\
\x7a\x52\0\x08\x7c\x0b\x01\x0c\0\0\0\x18\0\0\0\x18\0\0\0\0\0\0\0\0\0\0\0\x20\
\x11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xa0\0\
\0\0\x04\0\xf1\xff\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd7\x01\0\0\0\0\x03\0\x38\
\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xbf\x01\0\0\0\0\x03\0\xe0\x09\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x68\x01\0\0\0\0\x03\0\x88\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x48\x01\
\0\0\0\0\x03\0\xf0\x0b\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xcf\x01\0\0\0\0\x03\0\x10\
\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xb7\x01\0\0\0\0\x03\0\x88\x0a\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x9f\x01\0\0\0\0\x03\0\xb8\x0a\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\x01\
\0\0\0\0\x03\0\xf0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf1\0\0\0\0\0\x03\0\x30\x0b\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x17\x02\0\0\0\0\x03\0\x40\x0b\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\xf7\x01\0\0\0\0\x03\0\x38\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xaf\x01\0\0\
\0\0\x03\0\xb8\x0b\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x97\x01\0\0\0\0\x03\0\xe0\x0b\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x01\0\0\0\0\x03\0\xc0\x02\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x10\x01\0\0\0\0\x03\0\xf8\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe9\0\0\0\0\0\
\x03\0\x40\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x70\x01\0\0\0\0\x03\0\xb8\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x0f\x02\0\0\0\0\x03\0\x70\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\xa7\x01\0\0\0\0\x03\0\xb0\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x8f\x01\0\0\0\0\x03\
\0\xa0\x07\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x28\x01\0\0\0\0\x03\0\xd0\x07\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\xe1\0\0\0\0\0\x03\0\xf8\x05\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x87\
\x01\0\0\0\0\x03\0\x70\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x38\x01\0\0\0\0\x03\0\
\x90\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\x01\0\0\0\0\x03\0\xc8\x06\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xd9\0\0\0\0\0\x03\0\xd0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x07\
\x02\0\0\0\0\x03\0\xd8\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xef\x01\0\0\0\0\x03\0\
\x08\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x58\x01\0\0\0\0\x03\0\x68\x08\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\x20\x01\0\0\0\0\x03\0\x80\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd1\
\0\0\0\0\0\x03\0\xb8\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xe7\x01\0\0\0\0\x03\0\xc8\
\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x7f\x01\0\0\0\0\x03\0\x18\x09\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x30\x01\0\0\0\0\x03\0\x30\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc9\0\0\
\0\0\0\x03\0\x48\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xf9\0\0\0\0\0\x03\0\xc0\x01\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\xff\x01\0\0\0\0\x03\0\x88\x0d\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\xdf\x01\0\0\0\0\x03\0\x98\x0d\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc7\x01\0\0\0\
\0\x03\0\x30\x10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x77\x01\0\0\0\0\x03\0\xc0\x0d\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\x50\x01\0\0\0\0\x03\0\x88\x10\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\x18\x01\0\0\0\0\x03\0\0\x11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\0\0\0\0\x03\
\0\x08\x11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xc1\0\0\0\0\0\x03\0\x10\x11\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xba\0\0\0\0\0\x03\0\xf8\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x03\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6b\0\0\0\x11\0\x06\0\0\0\0\0\0\
\0\0\0\x07\0\0\0\0\0\0\0\x25\0\0\0\x11\0\x05\0\0\0\0\0\0\0\0\0\x14\0\0\0\0\0\0\
\0\x82\0\0\0\x11\0\x05\0\x28\0\0\0\0\0\0\0\x14\0\0\0\0\0\0\0\x01\0\0\0\x11\0\
\x05\0\x14\0\0\0\0\0\0\0\x14\0\0\0\0\0\0\0\x40\0\0\0\x12\0\x03\0\0\0\0\0\0\0\0\
\0\x20\x11\0\0\0\0\0\0\x28\0\0\0\0\0\0\0\x01\0\0\0\x31\0\0\0\x50\0\0\0\0\0\0\0\
\x01\0\0\0\x33\0\0\0\xe0\x10\0\0\0\0\0\0\x01\0\0\0\x32\0\0\0\x1c\0\0\0\0\0\0\0\
\x01\0\0\0\x2f\0\0\0\0\x74\x61\x70\x5f\x72\x73\x73\x5f\x6d\x61\x70\x5f\x74\x6f\
\x65\x70\x6c\x69\x74\x7a\x5f\x6b\x65\x79\0\x2e\x74\x65\x78\x74\0\x6d\x61\x70\
\x73\0\x74\x61\x70\x5f\x72\x73\x73\x5f\x6d\x61\x70\x5f\x63\x6f\x6e\x66\x69\x67\
\x75\x72\x61\x74\x69\x6f\x6e\x73\0\x74\x75\x6e\x5f\x72\x73\x73\x5f\x73\x74\x65\
\x65\x72\x69\x6e\x67\x5f\x70\x72\x6f\x67\0\x2e\x72\x65\x6c\x74\x75\x6e\x5f\x72\
\x73\x73\x5f\x73\x74\x65\x65\x72\x69\x6e\x67\0\x5f\x6c\x69\x63\x65\x6e\x73\x65\
\0\x2e\x72\x65\x6c\x2e\x65\x68\x5f\x66\x72\x61\x6d\x65\0\x74\x61\x70\x5f\x72\
\x73\x73\x5f\x6d\x61\x70\x5f\x69\x6e\x64\x69\x72\x65\x63\x74\x69\x6f\x6e\x5f\
\x74\x61\x62\x6c\x65\0\x72\x73\x73\x2e\x62\x70\x66\x2e\x63\0\x2e\x73\x74\x72\
\x74\x61\x62\0\x2e\x73\x79\x6d\x74\x61\x62\0\x4c\x42\x42\x30\x5f\x39\0\x4c\x42\
\x42\x30\x5f\x38\x39\0\x4c\x42\x42\x30\x5f\x37\x39\0\x4c\x42\x42\x30\x5f\x36\
\x39\0\x4c\x42\x42\x30\x5f\x35\x39\0\x4c\x42\x42\x30\x5f\x34\x39\0\x4c\x42\x42\
\x30\x5f\x33\x39\0\x4c\x42\x42\x30\x5f\x32\x39\0\x4c\x42\x42\x30\x5f\x38\0\x4c\
\x42\x42\x30\x5f\x38\x38\0\x4c\x42\x42\x30\x5f\x35\x38\0\x4c\x42\x42\x30\x5f\
\x33\x38\0\x4c\x42\x42\x30\x5f\x38\x37\0\x4c\x42\x42\x30\x5f\x36\x37\0\x4c\x42\
\x42\x30\x5f\x34\x37\0\x4c\x42\x42\x30\x5f\x37\x36\0\x4c\x42\x42\x30\x5f\x35\
\x36\0\x4c\x42\x42\x30\x5f\x32\x36\0\x4c\x42\x42\x30\x5f\x31\x36\0\x4c\x42\x42\
\x30\x5f\x38\x35\0\x4c\x42\x42\x30\x5f\x36\x35\0\x4c\x42\x42\x30\x5f\x33\x35\0\
\x4c\x42\x42\x30\x5f\x31\x35\0\x4c\x42\x42\x30\x5f\x34\0\x4c\x42\x42\x30\x5f\
\x38\x34\0\x4c\x42\x42\x30\x5f\x37\x34\0\x4c\x42\x42\x30\x5f\x35\x34\0\x4c\x42\
\x42\x30\x5f\x34\x34\0\x4c\x42\x42\x30\x5f\x33\x34\0\x4c\x42\x42\x30\x5f\x32\
\x34\0\x4c\x42\x42\x30\x5f\x34\x33\0\x4c\x42\x42\x30\x5f\x33\x33\0\x4c\x42\x42\
\x30\x5f\x32\x33\0\x4c\x42\x42\x30\x5f\x31\x33\0\x4c\x42\x42\x30\x5f\x38\x32\0\
\x4c\x42\x42\x30\x5f\x32\x32\0\x4c\x42\x42\x30\x5f\x31\x32\0\x4c\x42\x42\x30\
\x5f\x38\x31\0\x4c\x42\x42\x30\x5f\x37\x31\0\x4c\x42\x42\x30\x5f\x36\x31\0\x4c\
\x42\x42\x30\x5f\x33\x31\0\x4c\x42\x42\x30\x5f\x38\x30\0\x4c\x42\x42\x30\x5f\
\x36\x30\0\x4c\x42\x42\x30\x5f\x34\x30\0\x4c\x42\x42\x30\x5f\x33\x30\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xaa\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\x10\x17\0\0\0\0\0\0\x1f\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x01\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x1a\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x40\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\
\0\0\0\0\0\0\x5a\0\0\0\x01\0\0\0\x06\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x40\0\0\0\0\
\0\0\0\x20\x11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\x56\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd0\x16\0\0\0\0\0\0\x30\0\
\0\0\0\0\0\0\x09\0\0\0\x03\0\0\0\x08\0\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x20\0\0\0\
\x01\0\0\0\x03\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x60\x11\0\0\0\0\0\0\x3c\0\0\0\0\0\
\0\0\0\0\0\0\0\0\0\0\x04\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x6c\0\0\0\x01\0\0\0\x03\
\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x9c\x11\0\0\0\0\0\0\x07\0\0\0\0\0\0\0\0\0\0\0\0\
\0\0\0\x01\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x78\0\0\0\x01\0\0\0\x02\0\0\0\0\0\0\0\
\0\0\0\0\0\0\0\0\xa8\x11\0\0\0\0\0\0\x30\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x08\0\0\
\0\0\0\0\0\0\0\0\0\0\0\0\0\x74\0\0\0\x09\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\
\0\x17\0\0\0\0\0\0\x10\0\0\0\0\0\0\0\x09\0\0\0\x07\0\0\0\x08\0\0\0\0\0\0\0\x10\
\0\0\0\0\0\0\0\xb2\0\0\0\x02\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\xd8\x11\0\0\
\0\0\0\0\xf8\x04\0\0\0\0\0\0\x01\0\0\0\x30\0\0\0\x08\0\0\0\0\0\0\0\x18\0\0\0\0\
\0\0\0";

	return 0;
err:
	bpf_object__destroy_skeleton(s);
	return -1;
}

#endif /* __RSS_BPF_SKEL_H__ */
