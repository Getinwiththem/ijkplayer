/*
 * Copyright (c) 2016 Raymond Zheng <raymondzheng1412@gmail.com>
 *
 * This file is part of ijkPlayer.
 *
 * ijkPlayer is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * ijkPlayer is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with ijkPlayer; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */
#include "ijkioprotocol.h"

#include <string.h>

extern IjkURLProtocol ijkio_ffio_protocol;
extern IjkURLProtocol ijkio_androidio_protocol;
extern IjkURLProtocol ijkio_cache_protocol;

int ijkio_alloc_url(IjkURLContext **ph, const char *url) {
    if (!ph) {
        return -1;
    }

    IjkURLContext *h = NULL;
    if (!strncmp(url, "cache:", strlen("cache:"))) {
        h = (IjkURLContext *)calloc(1, sizeof(IjkURLContext));
        h->prot = &ijkio_cache_protocol;
        h->priv_data = calloc(1, ijkio_cache_protocol.priv_data_size);
    } else if (!strncmp(url, "ffio:", strlen("ffio:"))) {
        h = (IjkURLContext *)calloc(1, sizeof(IjkURLContext));
        h->prot = &ijkio_ffio_protocol;
        h->priv_data = calloc(1, ijkio_ffio_protocol.priv_data_size);
    } else if (!strncmp(url, "androidio:", strlen("androidio:"))) {
        h = (IjkURLContext *)calloc(1, sizeof(IjkURLContext));
        h->prot = &ijkio_androidio_protocol;
        h->priv_data = calloc(1, ijkio_androidio_protocol.priv_data_size);
    } else {
        return -1;
    }

    *ph = h;

    return 0;
}