/**
* Copyright (C) 2008 Happy Fish / YuQing
*
* FastDFS may be copied only under the terms of the GNU General
* Public License V3, which may be found in the FastDFS source kit.
* Please visit the FastDFS Home Page http://www.csource.org/ for more detail.
**/

//fdht_client.h

#ifndef _FDHT_CLIENT_H
#define _FDHT_CLIENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fdht_define.h"
#include "fdht_types.h"
#include "fdht_proto.h"

#ifdef __cplusplus
extern "C" {
#endif

extern GroupArray g_group_array;

int fdht_client_init(const char *filename);
void fdht_client_destroy();

#define fdht_get(pKeyInfo, ppValue, value_len) \
	fdht_get_ex(pKeyInfo, FDHT_EXPIRES_NONE, ppValue, value_len)

int fdht_get_ex(FDHTKeyInfo *pKeyInfo, const time_t expires, \
		char **ppValue, int *value_len);

int fdht_set(FDHTKeyInfo *pKeyInfo, const time_t expires, \
		const char *pValue, const int value_len);

int fdht_inc(FDHTKeyInfo *pKeyInfo, const time_t expires, const int increase, \
		char *pValue, int *value_len);

int fdht_delete(FDHTKeyInfo *pKeyInfo);

#ifdef __cplusplus
}
#endif

#endif

