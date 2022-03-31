#!/bin/sh

mkdir /server/tmp                         && \
cd /server/tmp                            && \
curl -sS https://down.serverrent.hu/metin2_server.tar.gz > metin2_server.tar.gz && \
unzip metin2_server.tar.gz                                  && \
rm metin2_server.tar.gz
mv svfiles ..