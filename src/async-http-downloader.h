/*
 * Copyright 2008 Evenflow, Inc.
 *
 * async-http-downloader.h
 * Header file for async-http-downloader.c
 *
 * This file is part of nautilus-dropbox.
 *
 * nautilus-dropbox is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * nautilus-dropbox is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with nautilus-dropbox.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ASYNC_HTTP_DOWNLOADER_H
#define ASYNC_HTTP_DOWNLOADER_H

#include <glib.h>

G_BEGIN_DECLS

typedef void (*HttpResponseHandler)(gint response_code,
                                    GList *headers,
                                    GIOChannel *data_channel,
                                    gpointer ud);

gboolean
make_async_http_get_request(const char *host, gint port,
			    const char *path, gboolean is_ssl,
                            GList *request_headers,
                            HttpResponseHandler cb, gpointer ud);

G_END_DECLS

#endif
